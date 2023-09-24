//
// Created by Misha on 8/18/2023.
//

#ifndef CALC2_CORRELATION_H
#define CALC2_CORRELATION_H

#include <array>
#include <string>
#include <numeric>

#include <TFile.h>

#include <DataContainer.hpp>
#include <utility>

template <size_t N>
class Correlation {
public:
  Correlation() = delete;
  Correlation( TFile* file,
               const std::string& directory,
               const std::vector<std::string>& vector_names,
               const std::array<std::string, N>& component_names ) :
               vector_names_{ vector_names },
               component_names_{ component_names } {
    if( !file )
      throw std::runtime_error( std::string( "Error: Input file is nullptr" ) );
    int idx{};
    for (const auto &component : component_names) {
      std::string name = directory + "/";
      for( const auto& vec : vector_names ){
        name+=vec+".";
      }
      if( !component.empty() ) name+=component;
      else name.pop_back();
      components_[idx] = ReadFromFile( file, name );
      idx++;
    }
  };
  Correlation( TFile* file,
               const std::string& directory,
               const std::array<std::string, 2>& vector_names,
               const std::array<std::string, N>& component_names ) :
               vector_names_{ vector_names.data(), vector_names.data()+2 },
               component_names_{ component_names } {

    if( !file )
      throw std::runtime_error( std::string( "Error: Input file is nullptr" ) );
    int idx{};
    for (const auto &component : component_names) try {
      std::string name{};
      name.append(directory).append("/").append(vector_names[0]).append(".").append(vector_names[1]);
      if( !component.empty() ) name.append(".").append(component);
      components_[idx] = ReadFromFile( file, name );
      idx++;
    } catch (const std::exception&){
      std::string name{};
      name.append(directory).append("/").append(vector_names[1]).append(".").append(vector_names[0]);
      if( !component.empty() ) name.append(".").append(component);
      components_[idx] = ReadFromFile( file, name );
      idx++;
    }
  };
  Correlation( const Correlation& ) = default;
  Correlation& operator=( const Correlation& ) = default;
  Correlation( Correlation&& )  noexcept = default;
  Correlation& operator=( Correlation&& )  noexcept = default;
  ~Correlation() = default;
  [[nodiscard]] const std::string& Title() const { return title_; }
  void SetTitle( const std::string& title ){ title_ = title; }
  void Rebin( const std::vector<Qn::AxisD>& rebin_axes ){
    std::for_each( components_.begin(), components_.end(), [&rebin_axes]( auto& component ){
      for( const auto& axis : rebin_axes ){
        component = component.Rebin( axis );
      }
    } );
  }
  void Project( const std::vector<std::string>& projection_axes ){
    std::for_each( components_.begin(), components_.end(), [&projection_axes]( auto& component ){
        component = component.Projection( projection_axes );
    } );
  }
  Qn::DataContainerStatCalculate& operator[]( size_t idx ){ return components_.at(idx); }
  [[nodiscard]] constexpr size_t Size() const  { return N; };
  void Save( const std::string& name ) const {
    std::for_each( components_.begin(), components_.end(), [ this, name, idx=0 ]( const auto& component ) mutable {
      component.Write( std::data(name+"."+component_names_.at(idx)) );
      idx++;
    } );
  }

  friend Correlation<N> operator+(const Correlation<N>& lhs, const Correlation<N> & rhs) noexcept {
    auto result = Correlation(lhs);
    for( size_t i=0; i<N; ++i ){
      result.components_[i] = lhs.components_[i] + rhs.components_[i];
    }
    return result;
  }

  friend Correlation<N> operator-(const Correlation<N>& lhs, const Correlation<N> & rhs) noexcept {
    auto result = Correlation(lhs);
    for( size_t i=0; i<N; ++i ){
      result.components_[i] = lhs.components_[i] - rhs.components_[i];
    }
    return result;
  }

  friend Correlation<N> operator*(const Correlation<N>& lhs, const Correlation<N> & rhs) noexcept {
    auto result = Correlation(lhs);
    for( size_t i=0; i<N; ++i ){
      result.components_[i] = lhs.components_[i] * rhs.components_[i];
    }
    return result;
  }

  friend Correlation<N> operator*(const Correlation<N>& lhs, const std::array<double, N> & tensor) noexcept {
    auto result = Correlation(lhs);
    for( size_t i=0; i<N; ++i ){
      result.components_[i] = lhs.components_[i] * tensor.at[i];
    }
    return result;
  }

  friend Correlation<N> operator*(const Correlation<N>& lhs, double scale) noexcept {
    auto result = Correlation(lhs);
    for( size_t i=0; i<N; ++i ){
      result.components_[i] = lhs.components_[i] * scale ;
    }
    return result;
  }

  friend Correlation<N> operator*(double scale, const Correlation<N>& lhs) noexcept {
    return lhs*scale;
  }

  friend Correlation<N> operator/(const Correlation<N>& lhs, const Correlation<N> & rhs) noexcept {
    auto result = Correlation(lhs);
    for( size_t i=0; i<N; ++i ){
      result.components_[i] = lhs.components_[i] / rhs.components_[i];
    }
    return result;
  }

  friend Correlation<N> operator/(const Correlation<N>& lhs, const std::array<double, N> & tensor) noexcept {
    auto result = Correlation(lhs);
    for( size_t i=0; i<N; ++i ){
      result.components_[i] = lhs.components_[i] / tensor[i];
    }
    return result;
  }


  friend Correlation<N> operator/(const Correlation<N>& lhs, double scale) noexcept {
    auto result = Correlation(lhs);
    for( size_t i=0; i<N; ++i ){
      result.components_[i] = lhs.components_[i] / scale;
    }
    return result;
  }

  friend Correlation<N> Sqrt(const Correlation<N>& lhs) noexcept {
    auto result = Correlation(lhs);
    for( size_t i=0; i<N; ++i ){
      result.components_[i] = Sqrt( lhs.components_[i] );
    }
    return result;
  }


private:
  std::string title_;
  std::array<std::string, N> component_names_;
  std::array<Qn::DataContainerStatCalculate, N> components_;
  std::vector<std::string> vector_names_;

  Qn::DataContainerStatCalculate ReadFromFile( TFile* file, const std::string& name ){
    using namespace std::literals::string_literals;
    Qn::DataContainerStatCalculate* container{nullptr};
    file->GetObject(name.c_str(), container);
    if (container) return *container;
    else {
      Qn::DataContainerStatCollect *container_collect{nullptr};
      file->GetObject(name.c_str(), container_collect);
      if (container_collect) return Qn::DataContainerStatCalculate(*container_collect);
    }
    throw std::runtime_error("No obj "s + name + " in a file"s);
  }
};


#endif //CALC2_CORRELATION_H