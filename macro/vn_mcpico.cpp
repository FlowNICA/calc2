//
// Created by mikhail on 8/1/21.
//
void vn_mcpico(){
  auto file = TFile::Open( "~/Documents/Work/Dataset/QnToolsMcPico/files/corr_mcpico_2.87gev_lab.root" );
  std::array<std::string, 2> q1q1_components{"x1x1cent", "y1y1cent"};
  std::array<std::string, 2> q2q2_components{"x2x2cent", "y2y2cent"};

  auto file_out = TFile::Open( "~/Documents/Work/Dataset/QnToolsMcPico/files/calc_mcpico_2.87gev_lab.root", "recreate" );
  file_out->cd();
  file_out->mkdir("proton");
  file_out->mkdir("pionP");
  file_out->mkdir("pionM");
//  *******************************************
//  Calculating v1 for sim-tru particles
//  *******************************************
//
  {
    auto proton1_psi1 = FunctionsNE::CreateCorrelation( file, "/", std::array{"tru_proton_PLAIN"s, "psi_rp_PLAIN"s}, q1q1_components);
    auto pi_pos1_psi1 = FunctionsNE::CreateCorrelation( file, "/", std::array{"tru_pionP_PLAIN"s, "psi_rp_PLAIN"s}, q1q1_components);
    auto pi_neg1_psi1 = FunctionsNE::CreateCorrelation( file, "/", std::array{"tru_pionM_PLAIN"s, "psi_rp_PLAIN"s}, q1q1_components);
    
    auto proton2_psi2 = FunctionsNE::CreateCorrelation( file, "/", std::array{"tru_proton_PLAIN"s, "psi_rp_PLAIN"s}, q2q2_components);
    auto pi_pos2_psi2 = FunctionsNE::CreateCorrelation( file, "/", std::array{"tru_pionP_PLAIN"s, "psi_rp_PLAIN"s}, q2q2_components);
    auto pi_neg2_psi2 = FunctionsNE::CreateCorrelation( file, "/", std::array{"tru_pionM_PLAIN"s, "psi_rp_PLAIN"s}, q2q2_components);

    proton1_psi1.value() = proton1_psi1.value()*2.0;
    pi_pos1_psi1.value() = pi_pos1_psi1.value()*2.0;
    pi_neg1_psi1.value() = pi_neg1_psi1.value()*2.0;

    proton2_psi2.value() = proton2_psi2.value()*2.0;
    pi_pos2_psi2.value() = pi_pos2_psi2.value()*2.0;
    pi_neg2_psi2.value() = pi_neg2_psi2.value()*2.0;

    file_out->cd("proton");
    proton1_psi1.value().Save("v1.tru_proton_PLAIN.psi_rp_PLAIN");
    proton2_psi2.value().Save("v2.tru_proton_PLAIN.psi_rp_PLAIN");
    file_out->cd("pionP");
    pi_pos1_psi1.value().Save("v1.tru_pionP_PLAIN.psi_rp_PLAIN");
    pi_pos2_psi2.value().Save("v2.tru_pionM_PLAIN.psi_rp_PLAIN");
    file_out->cd("pionM");
    pi_neg1_psi1.value().Save("v1.tru_pionP_PLAIN.psi_rp_PLAIN");
    pi_neg2_psi2.value().Save("v2.tru_pionM_PLAIN.psi_rp_PLAIN");
  }
  
  file_out->Close();
  file->Close();
}
