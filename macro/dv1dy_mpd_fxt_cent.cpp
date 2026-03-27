//
// Created by mikhail on 8/1/21.
//
void dv1dy_mpd_fxt_cent(){
  std::pair<float, float> proton_pt_cut = { 0.7, 1.3 };
  auto file = TFile::Open("/run/media/peter/ssd4tb/Work/Dataset/QnToolsMPD/files-prod40/calc_urqmd_xew_2.5agev_prod40.root");
  auto file_out = TFile::Open( "/run/media/peter/ssd4tb/Work/Dataset/QnToolsMPD/files-prod40/dv1dycent_urqmd_xew_2.5agev_prod40.root", "recreate" );

  auto v1_f1 = Correlation<1>( file, "/proton/"s, std::vector{"v1.F1_RESCALED(F3_RESCALED,Tp_RESCALED)"s}, std::array<std::string, 1>{ "y1y1cent"s });
  auto v1_f2 = Correlation<1>( file, "/proton/"s, std::vector{"v1.F2_RESCALED.Tp_RESCALED(F1_RESCALED,F3_RESCALED)"s}, std::array<std::string, 1>{ "y1y1cent"s });
  auto v1_f3 = Correlation<1>( file, "/proton/"s, std::vector{"v1.F3_RESCALED(F1_RESCALED,Tp_RESCALED)"s}, std::array<std::string, 1>{ "y1y1cent"s });
  auto v1_proton = v1_f1; //Qn::Merge(v1_f2, v1_f3);
  v1_proton.Rebin( std::vector{ Qn::AxisD{"tr_pT", 1, proton_pt_cut.first, proton_pt_cut.second }, Qn::AxisD{"cent", {10, 20, 30, 40, 50, 60}}, Qn::AxisD{"tr_y", 6, -1.1, 0.1 } } );
  v1_proton.Project( std::vector{ "tr_y"s, "cent"s } );

  auto fitter = Fitter( v1_proton, "tr_y"s, "cent"s );
  auto fit_functions = std::vector< TF1* >{ new TF1( "f1", "pol1", -0.3, 0.1 ) };
  // fit_functions[0]->FixParameter( 2, 0.0 );
  fitter.Fit( fit_functions, 2 );

  fitter.DumpGraphs( "dv1dy_slices.root" );

  file_out->cd();
  auto i=size_t{0};
  for( const auto& c : fitter.GetFitResults() ){
    auto name = std::string{ "fit_par" }.append( std::to_string(i) );
    c.Write( name.c_str() );
    ++i;
  }
  file_out->Close();
  file->Close();
}