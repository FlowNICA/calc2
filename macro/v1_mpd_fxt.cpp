//
// Created by mikhail on 8/1/21.
//
void v1_mpd_fxt() {
  auto file = TFile::Open(
      "/run/media/peter/ExtSsd/Work/Dataset/QnToolsMPD/files-prod36-new/"
      "corr_urqmd_xexe_2.5agev_prod36_highharmonics.root");
  auto file_out = TFile::Open(
      "/run/media/peter/ExtSsd/Work/Dataset/QnToolsMPD/files-prod36-new/"
      "calc_urqmd_xexe_2.5agev_prod36_highharmonics.root",
      "recreate");
  std::vector<std::string> ep_vectors{"F1_RESCALED", "F2_RESCALED",
                                      "F3_RESCALED"};
  std::vector<std::string> res_vectors{
      "F1_RESCALED", "F2_RESCALED",   "F3_RESCALED",
      "Tp_RESCALED", "Tneg_RESCALED",
  };
  std::vector<std::string> sts_vectors{
      "Tp_RESCALED",
      "Tneg_RESCALED",
  };
  std::array<std::string, 4> q1q1_components{"x1x1cent", "y1y1cent", "x1y1cent",
                                             "y1x1cent"};
  std::array<std::string, 4> q1q1_comps_res{"x1x1cent", "y1y1cent", "y1y1cent",
                                            "x1x1cent"};
  std::array<std::string, 4> q2q2_components{"x2x2cent", "y2y2cent", "x2y2cent",
                                             "y2x2cent"};
  std::array<std::string, 4> q2q2_comps_res{"x2x2cent", "y2y2cent", "y2y2cent",
                                            "x2x2cent"};
  std::array<std::string, 4> q3q3_components{"x3x3cent", "y3y3cent", "x3y3cent",
                                             "y3x3cent"};
  std::array<std::string, 4> q3q3_comps_res{"x3x3cent", "y3y3cent", "y3y3cent",
                                            "x3x3cent"};
  std::array<std::string, 4> q4q4_components{"x4x4cent", "y4y4cent", "x4y4cent",
                                             "y4x4cent"};
  std::array<std::string, 4> q4q4_comps_res{"x4x4cent", "y4y4cent", "y4y4cent",
                                            "x4x4cent"};

  file_out->cd();
  file_out->mkdir("resolutions");
  file_out->mkdir("proton");
  file_out->mkdir("pi_pos");
  file_out->mkdir("pi_neg");
  //  *******************************************
  //  Calculating v1 for sim-tru particles
  //  *******************************************
  //
  {
    auto proton1_psi1 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"tru_proton_PLAIN"s, "psi_rp_PLAIN"s},
        q1q1_components);
    auto pi_pos1_psi1 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"tru_pi_pos_PLAIN"s, "psi_rp_PLAIN"s},
        q1q1_components);
    auto pi_neg1_psi1 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"tru_pi_neg_PLAIN"s, "psi_rp_PLAIN"s},
        q1q1_components);

    auto proton2_psi2 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"tru_proton_PLAIN"s, "psi_rp_PLAIN"s},
        q2q2_components);
    auto pi_pos2_psi2 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"tru_pi_pos_PLAIN"s, "psi_rp_PLAIN"s},
        q2q2_components);
    auto pi_neg2_psi2 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"tru_pi_neg_PLAIN"s, "psi_rp_PLAIN"s},
        q2q2_components);

    // auto proton3_psi3 = FunctionsNE::CreateCorrelation( file, "/",
    // std::array{"tru_proton_PLAIN"s, "psi_rp_PLAIN"s}, q3q3_components); auto
    // pi_pos3_psi3 = FunctionsNE::CreateCorrelation( file, "/",
    // std::array{"tru_pi_pos_PLAIN"s, "psi_rp_PLAIN"s}, q3q3_components); auto
    // pi_neg3_psi3 = FunctionsNE::CreateCorrelation( file, "/",
    // std::array{"tru_pi_neg_PLAIN"s, "psi_rp_PLAIN"s}, q3q3_components);
    //
    // auto proton4_psi4 = FunctionsNE::CreateCorrelation( file, "/",
    // std::array{"tru_proton_PLAIN"s, "psi_rp_PLAIN"s}, q4q4_components); auto
    // pi_pos4_psi4 = FunctionsNE::CreateCorrelation( file, "/",
    // std::array{"tru_pi_pos_PLAIN"s, "psi_rp_PLAIN"s}, q4q4_components); auto
    // pi_neg4_psi4 = FunctionsNE::CreateCorrelation( file, "/",
    // std::array{"tru_pi_neg_PLAIN"s, "psi_rp_PLAIN"s}, q4q4_components);

    proton1_psi1.value() = proton1_psi1.value() * 2.0;
    pi_pos1_psi1.value() = pi_pos1_psi1.value() * 2.0;
    pi_neg1_psi1.value() = pi_neg1_psi1.value() * 2.0;

    // proton2_psi2.value() = proton2_psi2.value()*2.0;
    // pi_pos2_psi2.value() = pi_pos2_psi2.value()*2.0;
    // pi_neg2_psi2.value() = pi_neg2_psi2.value()*2.0;
    //
    // proton3_psi3.value() = proton3_psi3.value()*2.0;
    // pi_pos3_psi3.value() = pi_pos3_psi3.value()*2.0;
    // pi_neg3_psi3.value() = pi_neg3_psi3.value()*2.0;
    //
    // proton4_psi4.value() = proton4_psi4.value()*2.0;
    // pi_pos4_psi4.value() = pi_pos4_psi4.value()*2.0;
    // pi_neg4_psi4.value() = pi_neg4_psi4.value()*2.0;

    file_out->cd("proton");
    proton1_psi1.value().Save("v1.tru_proton_PLAIN.psi_rp_PLAIN");
    // proton2_psi2.value().Save("v2.tru_proton_PLAIN.psi_rp_PLAIN");
    // proton3_psi3.value().Save("v3.tru_proton_PLAIN.psi_rp_PLAIN");
    // proton4_psi4.value().Save("v4.tru_proton_PLAIN.psi_rp_PLAIN");
    file_out->cd("pi_pos");
    pi_pos1_psi1.value().Save("v1.tru_pi_pos_PLAIN.psi_rp_PLAIN");
    // pi_pos2_psi2.value().Save("v2.tru_pi_pos_PLAIN.psi_rp_PLAIN");
    // pi_pos3_psi3.value().Save("v3.tru_pi_pos_PLAIN.psi_rp_PLAIN");
    // pi_pos4_psi4.value().Save("v4.tru_pi_pos_PLAIN.psi_rp_PLAIN");
    file_out->cd("pi_neg");
    pi_neg1_psi1.value().Save("v1.tru_pi_neg_PLAIN.psi_rp_PLAIN");
    // pi_neg2_psi2.value().Save("v2.tru_pi_neg_PLAIN.psi_rp_PLAIN");
    // pi_neg3_psi3.value().Save("v3.tru_pi_neg_PLAIN.psi_rp_PLAIN");
    // pi_neg4_psi4.value().Save("v4.tru_pi_neg_PLAIN.psi_rp_PLAIN");
  }

  //  *******************************************
  //  Calculating v1 for rec particles wrt RP
  //  *******************************************
  //
  {
    auto proton1_psi1 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"proton_RESCALED"s, "psi_rp_PLAIN"s},
        q1q1_components);
    auto pi_pos1_psi1 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"pi_pos_RESCALED"s, "psi_rp_PLAIN"s},
        q1q1_components);
    auto pi_neg1_psi1 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"pi_neg_RESCALED"s, "psi_rp_PLAIN"s},
        q1q1_components);

    auto proton2_psi2 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"proton_RESCALED"s, "psi_rp_PLAIN"s},
        q2q2_components);
    auto pi_pos2_psi2 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"pi_pos_RESCALED"s, "psi_rp_PLAIN"s},
        q2q2_components);
    auto pi_neg2_psi2 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"pi_neg_RESCALED"s, "psi_rp_PLAIN"s},
        q2q2_components);

    auto proton3_psi3 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"proton_RESCALED"s, "psi_rp_PLAIN"s},
        q3q3_components);
    auto pi_pos3_psi3 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"pi_pos_RESCALED"s, "psi_rp_PLAIN"s},
        q3q3_components);
    auto pi_neg3_psi3 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"pi_neg_RESCALED"s, "psi_rp_PLAIN"s},
        q3q3_components);

    auto proton4_psi4 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"proton_RESCALED"s, "psi_rp_PLAIN"s},
        q4q4_components);
    auto pi_pos4_psi4 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"pi_pos_RESCALED"s, "psi_rp_PLAIN"s},
        q4q4_components);
    auto pi_neg4_psi4 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"pi_neg_RESCALED"s, "psi_rp_PLAIN"s},
        q4q4_components);

    proton1_psi1.value() = proton1_psi1.value() * 2.0;
    pi_pos1_psi1.value() = pi_pos1_psi1.value() * 2.0;
    pi_neg1_psi1.value() = pi_neg1_psi1.value() * 2.0;

    proton2_psi2.value() = proton2_psi2.value() * 2.0;
    pi_pos2_psi2.value() = pi_pos2_psi2.value() * 2.0;
    pi_neg2_psi2.value() = pi_neg2_psi2.value() * 2.0;

    proton3_psi3.value() = proton3_psi3.value() * 2.0;
    pi_pos3_psi3.value() = pi_pos3_psi3.value() * 2.0;
    pi_neg3_psi3.value() = pi_neg3_psi3.value() * 2.0;

    proton4_psi4.value() = proton4_psi4.value() * 2.0;
    pi_pos4_psi4.value() = pi_pos4_psi4.value() * 2.0;
    pi_neg4_psi4.value() = pi_neg4_psi4.value() * 2.0;

    file_out->cd("proton");
    proton1_psi1.value().Save("v1.proton_RESCALED.psi_rp_PLAIN");
    proton2_psi2.value().Save("v2.proton_RESCALED.psi_rp_PLAIN");
    proton3_psi3.value().Save("v3.proton_RESCALED.psi_rp_PLAIN");
    proton4_psi4.value().Save("v4.proton_RESCALED.psi_rp_PLAIN");
    file_out->cd("pi_pos");
    pi_pos1_psi1.value().Save("v1.pi_pos_RESCALED.psi_rp_PLAIN");
    pi_pos2_psi2.value().Save("v2.pi_pos_RESCALED.psi_rp_PLAIN");
    pi_pos3_psi3.value().Save("v3.pi_pos_RESCALED.psi_rp_PLAIN");
    pi_pos4_psi4.value().Save("v4.pi_pos_RESCALED.psi_rp_PLAIN");
    file_out->cd("pi_neg");
    pi_neg1_psi1.value().Save("v1.pi_neg_RESCALED.psi_rp_PLAIN");
    pi_neg2_psi2.value().Save("v2.pi_neg_RESCALED.psi_rp_PLAIN");
    pi_neg3_psi3.value().Save("v3.pi_neg_RESCALED.psi_rp_PLAIN");
    pi_neg4_psi4.value().Save("v4.pi_neg_RESCALED.psi_rp_PLAIN");
  }

  //  *******************************************
  //  Calculation of v1 with regular 3-Sub
  //  *******************************************
  //
  for (auto qa : ep_vectors) {
    auto proton_qa = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"proton_RESCALED"s, qa}, q1q1_components);
    auto pi_pos_qa = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"pi_pos_RESCALED"s, qa}, q1q1_components);
    auto pi_neg_qa = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"pi_neg_RESCALED"s, qa}, q1q1_components);

    auto res_v = FunctionsNE::VectorResolutions3S(file, "/", qa, res_vectors,
                                                  q1q1_comps_res);

    for (auto R1 : res_v) {
      auto v1_proton = std::make_optional(proton_qa.value() * 2 / R1);
      auto v1_pi_pos = std::make_optional(pi_pos_qa.value() * 2 / R1);
      auto v1_pi_neg = std::make_optional(pi_neg_qa.value() * 2 / R1);

      file_out->cd("resolutions");
      R1.Save("R1." + R1.Title());

      file_out->cd("proton");
      v1_proton.value().Save("v1." + R1.Title());
      file_out->cd("pi_pos");
      v1_pi_pos.value().Save("v1." + R1.Title());
      file_out->cd("pi_neg");
      v1_pi_neg.value().Save("v1." + R1.Title());
    }
  }

  //  *******************************************
  //  Calculation of flow for F2 with 4-sub method
  //  *******************************************
  //
  {
    auto res_v = FunctionsNE::VectorResolutions4S(
        file, "/", "F2_RESCALED", sts_vectors, ep_vectors, q1q1_comps_res);

    std::string qa = "F2_RESCALED";
    auto proton_qa = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"proton_RESCALED"s, qa}, q1q1_components);
    auto pi_pos_qa = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"pi_pos_RESCALED"s, qa}, q1q1_components);
    auto pi_neg_qa = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"pi_neg_RESCALED"s, qa}, q1q1_components);

    for (auto R1 : res_v) {
      auto v1_proton = std::make_optional(proton_qa.value() * 2 / R1);
      auto v1_pi_pos = std::make_optional(pi_pos_qa.value() * 2 / R1);
      auto v1_pi_neg = std::make_optional(pi_neg_qa.value() * 2 / R1);

      file_out->cd("resolutions");
      R1.Save("R1." + R1.Title());

      file_out->cd("proton");
      v1_proton.value().Save("v1." + R1.Title());
      file_out->cd("pi_pos");
      v1_pi_pos.value().Save("v1." + R1.Title());
      file_out->cd("pi_neg");
      v1_pi_neg.value().Save("v1." + R1.Title());
    }
  }

  //  *******************************************
  //  Calculating v2 with MH method
  //  *******************************************
  {
    auto proton_qa_qb = std::make_optional(Correlation<4>(
        file, "/", {"proton_RESCALED"s, "F1_RESCALED"s, "F3_RESCALED"s},
        {
            "x2x1x1cent",
            "x2y1y1cent",
            "y2y1x1cent",
            "y2x1y1cent",
        }));
    auto proton_2qa = std::make_optional(Correlation<4>(
        file, "/", {"proton_RESCALED"s, "F1_RESCALED"s, "F1_RESCALED"s},
        {
            "x2x1x1cent",
            "x2y1y1cent",
            "y2y1x1cent",
            "y2x1y1cent",
        }));
    auto proton_2qb = std::make_optional(Correlation<4>(
        file, "/", {"proton_RESCALED"s, "F2_RESCALED"s, "F2_RESCALED"s},
        {
            "x2x1x1cent",
            "x2y1y1cent",
            "y2y1x1cent",
            "y2x1y1cent",
        }));
    auto proton_2qc = std::make_optional(Correlation<4>(
        file, "/", {"proton_RESCALED"s, "F3_RESCALED"s, "F3_RESCALED"s},
        {
            "x2x1x1cent",
            "x2y1y1cent",
            "y2y1x1cent",
            "y2x1y1cent",
        }));
    auto pi_pos_qa_qb = std::make_optional(Correlation<4>(
        file, "/", {"pi_pos_RESCALED"s, "F1_RESCALED"s, "F3_RESCALED"s},
        {
            "x2x1x1cent",
            "x2y1y1cent",
            "y2y1x1cent",
            "y2x1y1cent",
        }));
    auto pi_pos_2qa = std::make_optional(Correlation<4>(
        file, "/", {"pi_pos_RESCALED"s, "F1_RESCALED"s, "F1_RESCALED"s},
        {
            "x2x1x1cent",
            "x2y1y1cent",
            "y2y1x1cent",
            "y2x1y1cent",
        }));
    auto pi_pos_2qb = std::make_optional(Correlation<4>(
        file, "/", {"pi_pos_RESCALED"s, "F2_RESCALED"s, "F2_RESCALED"s},
        {
            "x2x1x1cent",
            "x2y1y1cent",
            "y2y1x1cent",
            "y2x1y1cent",
        }));
    auto pi_pos_2qc = std::make_optional(Correlation<4>(
        file, "/", {"pi_pos_RESCALED"s, "F3_RESCALED"s, "F3_RESCALED"s},
        {
            "x2x1x1cent",
            "x2y1y1cent",
            "y2y1x1cent",
            "y2x1y1cent",
        }));
    auto pi_neg_qa_qb = std::make_optional(Correlation<4>(
        file, "/", {"pi_neg_RESCALED"s, "F1_RESCALED"s, "F3_RESCALED"s},
        {
            "x2x1x1cent",
            "x2y1y1cent",
            "y2y1x1cent",
            "y2x1y1cent",
        }));
    auto pi_neg_2qa = std::make_optional(Correlation<4>(
        file, "/", {"pi_neg_RESCALED"s, "F1_RESCALED"s, "F1_RESCALED"s},
        {
            "x2x1x1cent",
            "x2y1y1cent",
            "y2y1x1cent",
            "y2x1y1cent",
        }));
    auto pi_neg_2qb = std::make_optional(Correlation<4>(
        file, "/", {"pi_neg_RESCALED"s, "F2_RESCALED"s, "F2_RESCALED"s},
        {
            "x2x1x1cent",
            "x2y1y1cent",
            "y2y1x1cent",
            "y2x1y1cent",
        }));
    auto pi_neg_2qc = std::make_optional(Correlation<4>(
        file, "/", {"pi_neg_RESCALED"s, "F3_RESCALED"s, "F3_RESCALED"s},
        {
            "x2x1x1cent",
            "x2y1y1cent",
            "y2y1x1cent",
            "y2x1y1cent",
        }));

    proton_qa_qb.value() = proton_qa_qb.value() * 4;
    proton_2qa.value() = proton_2qa.value() * 4;
    proton_2qb.value() = proton_2qb.value() * 4;
    proton_2qc.value() = proton_2qc.value() * 4;
    pi_pos_qa_qb.value() = pi_pos_qa_qb.value() * 4;
    pi_pos_2qa.value() = pi_pos_2qa.value() * 4;
    pi_pos_2qb.value() = pi_pos_2qb.value() * 4;
    pi_pos_2qc.value() = pi_pos_2qc.value() * 4;
    pi_neg_qa_qb.value() = pi_neg_qa_qb.value() * 4;
    pi_neg_2qa.value() = pi_neg_2qa.value() * 4;
    pi_neg_2qb.value() = pi_neg_2qb.value() * 4;
    pi_neg_2qc.value() = pi_neg_2qc.value() * 4;
    auto qa_qb_1 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F1_RESCALED"s, "F3_RESCALED"s},
        std::array<std::string, 4>{
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
        });
    auto qa_qd_1 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F1_RESCALED"s, "Tp_RESCALED"s},
        std::array<std::string, 4>{
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
        });
    auto qb_qd_1 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F3_RESCALED"s, "Tp_RESCALED"s},
        std::array<std::string, 4>{
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
        });
    auto qc_qd_1 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F2_RESCALED"s, "Tp_RESCALED"s},
        std::array<std::string, 4>{
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
        });
    auto qa_qb_2 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F1_RESCALED"s, "F3_RESCALED"s},
        std::array<std::string, 4>{
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
        });
    auto qa_qd_2 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F1_RESCALED"s, "Tp_RESCALED"s},
        std::array<std::string, 4>{
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
        });
    auto qb_qd_2 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F3_RESCALED"s, "Tp_RESCALED"s},
        std::array<std::string, 4>{
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
        });
    auto qc_qd_2 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F2_RESCALED"s, "Tp_RESCALED"s},
        std::array<std::string, 4>{
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
        });
    auto res_qa_1 = std::make_optional(FunctionsNE::Resolution3S(
        qa_qb_1.value(), qa_qd_1.value(), qb_qd_1.value()));
    auto res_qb_1 = std::make_optional(FunctionsNE::Resolution3S(
        qa_qb_1.value(), qb_qd_1.value(), qa_qd_1.value()));
    auto res_qd_1 = std::make_optional(FunctionsNE::Resolution3S(
        qa_qd_1.value(), qb_qd_1.value(), qa_qb_1.value()));
    auto res_qc_1 = std::make_optional(qc_qd_1.value() / res_qd_1.value());
    auto res_qa_2 = std::make_optional(FunctionsNE::Resolution3S(
        qa_qb_2.value(), qa_qd_2.value(), qb_qd_2.value()));
    auto res_qb_2 = std::make_optional(FunctionsNE::Resolution3S(
        qa_qb_2.value(), qb_qd_2.value(), qa_qd_2.value()));
    auto res_qd_2 = std::make_optional(FunctionsNE::Resolution3S(
        qa_qd_2.value(), qb_qd_2.value(), qa_qb_2.value()));
    auto res_qc_2 = std::make_optional(qc_qd_2.value() / res_qd_2.value());
    auto proton_v2_qa_qb = std::make_optional(
        proton_qa_qb.value() / (res_qa_1.value() * res_qb_2.value() * 2.0));
    auto proton_v2_2qa = std::make_optional(
        proton_2qa.value() / (res_qa_1.value() * res_qa_2.value() * 2.0));
    auto proton_v2_2qb = std::make_optional(
        proton_2qb.value() / (res_qb_1.value() * res_qb_2.value() * 2.0));
    auto proton_v2_2qc = std::make_optional(
        proton_2qc.value() / (res_qc_1.value() * res_qc_2.value() * 2.0));
    auto pi_pos_v2_qa_qb = std::make_optional(
        pi_pos_qa_qb.value() / (res_qa_1.value() * res_qb_2.value() * 2.0));
    auto pi_pos_v2_2qa = std::make_optional(
        pi_pos_2qa.value() / (res_qa_1.value() * res_qa_2.value() * 2.0));
    auto pi_pos_v2_2qb = std::make_optional(
        pi_pos_2qb.value() / (res_qb_1.value() * res_qb_2.value() * 2.0));
    auto pi_pos_v2_2qc = std::make_optional(
        pi_pos_2qc.value() / (res_qc_1.value() * res_qc_2.value() * 2.0));
    auto pi_neg_v2_qa_qb = std::make_optional(
        pi_neg_qa_qb.value() / (res_qa_1.value() * res_qb_1.value() * 2.0));
    auto pi_neg_v2_2qa = std::make_optional(
        pi_neg_2qa.value() / (res_qa_1.value() * res_qa_2.value() * 2.0));
    auto pi_neg_v2_2qb = std::make_optional(
        pi_neg_2qb.value() / (res_qb_1.value() * res_qb_2.value() * 2.0));
    auto pi_neg_v2_2qc = std::make_optional(
        pi_neg_2qc.value() / (res_qc_1.value() * res_qc_2.value() * 2.0));
    file_out->cd("proton");
    proton_v2_qa_qb.value().Save("v2.F1_RESCALED.F3_RESCALED");
    proton_v2_2qa.value().Save("v2.F1_RESCALED.F1_RESCALED");
    proton_v2_2qc.value().Save("v2.F2_RESCALED.F2_RESCALED");
    proton_v2_2qb.value().Save("v2.F3_RESCALED.F3_RESCALED");
    file_out->cd("pi_pos");
    pi_pos_v2_qa_qb.value().Save("v2.F1_RESCALED.F3_RESCALED");
    pi_pos_v2_2qa.value().Save("v2.F1_RESCALED.F1_RESCALED");
    pi_pos_v2_2qc.value().Save("v2.F2_RESCALED.F2_RESCALED");
    pi_pos_v2_2qb.value().Save("v2.F3_RESCALED.F3_RESCALED");
    file_out->cd("pi_neg");
    pi_neg_v2_qa_qb.value().Save("v2.F1_RESCALED.F3_RESCALED");
    pi_neg_v2_2qa.value().Save("v2.F1_RESCALED.F1_RESCALED");
    pi_neg_v2_2qc.value().Save("v2.F2_RESCALED.F2_RESCALED");
    pi_neg_v2_2qb.value().Save("v2.F3_RESCALED.F3_RESCALED");
  }

  //  *******************************************
  //  Calculating v3 with 4P method
  //  *******************************************
  {
    auto proton_3qa = std::make_optional(Correlation<8>(
        file, "/",
        {"proton_RESCALED"s, "F1_RESCALED"s, "F1_RESCALED"s, "F1_RESCALED"s},
        {
            "x3x1x1x1cent",
            "x3x1y1y1cent",
            "x3y1x1y1cent",
            "x3y1y1x1cent",
            "y3x1x1y1cent",
            "y3x1y1x1cent",
            "y3y1x1x1cent",
            "y3y1y1y1cent",
        }));
    auto proton_3qb = std::make_optional(Correlation<8>(
        file, "/",
        {"proton_RESCALED"s, "F3_RESCALED"s, "F3_RESCALED"s, "F3_RESCALED"s},
        {
            "x3x1x1x1cent",
            "x3x1y1y1cent",
            "x3y1x1y1cent",
            "x3y1y1x1cent",
            "y3x1x1y1cent",
            "y3x1y1x1cent",
            "y3y1x1x1cent",
            "y3y1y1y1cent",
        }));
    auto proton_3qc = std::make_optional(Correlation<8>(
        file, "/",
        {"proton_RESCALED"s, "F2_RESCALED"s, "F2_RESCALED"s, "F2_RESCALED"s},
        {
            "x3x1x1x1cent",
            "x3x1y1y1cent",
            "x3y1x1y1cent",
            "x3y1y1x1cent",
            "y3x1x1y1cent",
            "y3x1y1x1cent",
            "y3y1x1x1cent",
            "y3y1y1y1cent",
        }));
    auto pi_pos_3qa = std::make_optional(Correlation<8>(
        file, "/",
        {"pi_pos_RESCALED"s, "F1_RESCALED"s, "F1_RESCALED"s, "F1_RESCALED"s},
        {
            "x3x1x1x1cent",
            "x3x1y1y1cent",
            "x3y1x1y1cent",
            "x3y1y1x1cent",
            "y3x1x1y1cent",
            "y3x1y1x1cent",
            "y3y1x1x1cent",
            "y3y1y1y1cent",
        }));
    auto pi_pos_3qb = std::make_optional(Correlation<8>(
        file, "/",
        {"pi_pos_RESCALED"s, "F3_RESCALED"s, "F3_RESCALED"s, "F3_RESCALED"s},
        {
            "x3x1x1x1cent",
            "x3x1y1y1cent",
            "x3y1x1y1cent",
            "x3y1y1x1cent",
            "y3x1x1y1cent",
            "y3x1y1x1cent",
            "y3y1x1x1cent",
            "y3y1y1y1cent",
        }));
    auto pi_pos_3qc = std::make_optional(Correlation<8>(
        file, "/",
        {"pi_pos_RESCALED"s, "F2_RESCALED"s, "F2_RESCALED"s, "F2_RESCALED"s},
        {
            "x3x1x1x1cent",
            "x3x1y1y1cent",
            "x3y1x1y1cent",
            "x3y1y1x1cent",
            "y3x1x1y1cent",
            "y3x1y1x1cent",
            "y3y1x1x1cent",
            "y3y1y1y1cent",
        }));
    auto pi_neg_3qa = std::make_optional(Correlation<8>(
        file, "/",
        {"pi_neg_RESCALED"s, "F1_RESCALED"s, "F1_RESCALED"s, "F1_RESCALED"s},
        {
            "x3x1x1x1cent",
            "x3x1y1y1cent",
            "x3y1x1y1cent",
            "x3y1y1x1cent",
            "y3x1x1y1cent",
            "y3x1y1x1cent",
            "y3y1x1x1cent",
            "y3y1y1y1cent",
        }));
    auto pi_neg_3qb = std::make_optional(Correlation<8>(
        file, "/",
        {"pi_neg_RESCALED"s, "F3_RESCALED"s, "F3_RESCALED"s, "F3_RESCALED"s},
        {
            "x3x1x1x1cent",
            "x3x1y1y1cent",
            "x3y1x1y1cent",
            "x3y1y1x1cent",
            "y3x1x1y1cent",
            "y3x1y1x1cent",
            "y3y1x1x1cent",
            "y3y1y1y1cent",
        }));
    auto pi_neg_3qc = std::make_optional(Correlation<8>(
        file, "/",
        {"pi_neg_RESCALED"s, "F2_RESCALED"s, "F2_RESCALED"s, "F2_RESCALED"s},
        {
            "x3x1x1x1cent",
            "x3x1y1y1cent",
            "x3y1x1y1cent",
            "x3y1y1x1cent",
            "y3x1x1y1cent",
            "y3x1y1x1cent",
            "y3y1x1x1cent",
            "y3y1y1y1cent",
        }));

    proton_3qa.value() = proton_3qa.value() * 8;
    proton_3qb.value() = proton_3qb.value() * 8;
    proton_3qc.value() = proton_3qc.value() * 8;
    pi_pos_3qa.value() = pi_pos_3qa.value() * 8;
    pi_pos_3qb.value() = pi_pos_3qb.value() * 8;
    pi_pos_3qc.value() = pi_pos_3qc.value() * 8;
    pi_neg_3qa.value() = pi_neg_3qa.value() * 8;
    pi_neg_3qb.value() = pi_neg_3qb.value() * 8;
    pi_neg_3qc.value() = pi_neg_3qc.value() * 8;

    auto qa_qb_1 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F1_RESCALED"s, "F3_RESCALED"s},
        std::array<std::string, 8>{
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
        });
    auto qa_qd_1 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F1_RESCALED"s, "Tp_RESCALED"s},
        std::array<std::string, 8>{
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
        });
    auto qb_qd_1 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F3_RESCALED"s, "Tp_RESCALED"s},
        std::array<std::string, 8>{
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
        });
    auto qc_qd_1 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F2_RESCALED"s, "Tp_RESCALED"s},
        std::array<std::string, 8>{
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
        });
    auto qa_qb_2 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F1_RESCALED"s, "F3_RESCALED"s},
        std::array<std::string, 8>{
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
        });
    auto qa_qd_2 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F1_RESCALED"s, "Tp_RESCALED"s},
        std::array<std::string, 8>{
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
        });
    auto qb_qd_2 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F3_RESCALED"s, "Tp_RESCALED"s},
        std::array<std::string, 8>{
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
        });
    auto qc_qd_2 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F2_RESCALED"s, "Tp_RESCALED"s},
        std::array<std::string, 8>{
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
        });
    auto qa_qb_3 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F1_RESCALED"s, "F3_RESCALED"s},
        std::array<std::string, 8>{
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
        });
    auto qa_qd_3 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F1_RESCALED"s, "Tp_RESCALED"s},
        std::array<std::string, 8>{
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
        });
    auto qb_qd_3 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F3_RESCALED"s, "Tp_RESCALED"s},
        std::array<std::string, 8>{
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
        });
    auto qc_qd_3 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F2_RESCALED"s, "Tp_RESCALED"s},
        std::array<std::string, 8>{
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
        });
    auto res_qa_1 = std::make_optional(FunctionsNE::Resolution3S(
        qa_qb_1.value(), qa_qd_1.value(), qb_qd_1.value()));
    auto res_qb_1 = std::make_optional(FunctionsNE::Resolution3S(
        qa_qb_1.value(), qb_qd_1.value(), qa_qd_1.value()));
    auto res_qd_1 = std::make_optional(FunctionsNE::Resolution3S(
        qa_qd_1.value(), qb_qd_1.value(), qa_qb_1.value()));
    auto res_qc_1 = std::make_optional(qc_qd_1.value() / res_qd_1.value());
    auto res_qa_2 = std::make_optional(FunctionsNE::Resolution3S(
        qa_qb_2.value(), qa_qd_2.value(), qb_qd_2.value()));
    auto res_qb_2 = std::make_optional(FunctionsNE::Resolution3S(
        qa_qb_2.value(), qb_qd_2.value(), qa_qd_2.value()));
    auto res_qd_2 = std::make_optional(FunctionsNE::Resolution3S(
        qa_qd_2.value(), qb_qd_2.value(), qa_qb_2.value()));
    auto res_qc_2 = std::make_optional(qc_qd_2.value() / res_qd_2.value());
    auto res_qa_3 = std::make_optional(FunctionsNE::Resolution3S(
        qa_qb_3.value(), qa_qd_3.value(), qb_qd_3.value()));
    auto res_qb_3 = std::make_optional(FunctionsNE::Resolution3S(
        qa_qb_3.value(), qb_qd_3.value(), qa_qd_3.value()));
    auto res_qd_3 = std::make_optional(FunctionsNE::Resolution3S(
        qa_qd_3.value(), qb_qd_3.value(), qa_qb_3.value()));
    auto res_qc_3 = std::make_optional(qc_qd_3.value() / res_qd_3.value());
    auto proton_v3_3qa = std::make_optional(
        proton_3qa.value() / (res_qa_1.value() * res_qa_2.value() *
                              res_qa_3.value() * 2.0 * sqrt(2.0)));
    auto proton_v3_3qb = std::make_optional(
        proton_3qb.value() / (res_qb_1.value() * res_qb_2.value() *
                              res_qb_3.value() * 2.0 * sqrt(2.0)));
    auto proton_v3_3qc = std::make_optional(
        proton_3qc.value() / (res_qc_1.value() * res_qc_2.value() *
                              res_qc_3.value() * 2.0 * sqrt(2.0)));
    auto pi_pos_v3_3qa = std::make_optional(
        pi_pos_3qa.value() / (res_qa_1.value() * res_qa_2.value() *
                              res_qa_3.value() * 2.0 * sqrt(2.0)));
    auto pi_pos_v3_3qb = std::make_optional(
        pi_pos_3qb.value() / (res_qb_1.value() * res_qb_2.value() *
                              res_qb_3.value() * 2.0 * sqrt(2.0)));
    auto pi_pos_v3_3qc = std::make_optional(
        pi_pos_3qc.value() / (res_qc_1.value() * res_qc_2.value() *
                              res_qc_3.value() * 2.0 * sqrt(2.0)));
    auto pi_neg_v3_3qa = std::make_optional(
        pi_neg_3qa.value() / (res_qa_1.value() * res_qa_2.value() *
                              res_qa_3.value() * 2.0 * sqrt(2.0)));
    auto pi_neg_v3_3qb = std::make_optional(
        pi_neg_3qb.value() / (res_qb_1.value() * res_qb_2.value() *
                              res_qb_3.value() * 2.0 * sqrt(2.0)));
    auto pi_neg_v3_3qc = std::make_optional(
        pi_neg_3qc.value() / (res_qc_1.value() * res_qc_2.value() *
                              res_qc_3.value() * 2.0 * sqrt(2.0)));
    file_out->cd("proton");
    proton_v3_3qa.value().Save("v3.F1_RESCALED.F1_RESCALED.F1_RESCALED");
    proton_v3_3qc.value().Save("v3.F2_RESCALED.F2_RESCALED.F2_RESCALED");
    proton_v3_3qb.value().Save("v3.F3_RESCALED.F3_RESCALED.F3_RESCALED");
    file_out->cd("pi_pos");
    pi_pos_v3_3qa.value().Save("v3.F1_RESCALED.F1_RESCALED.F1_RESCALED");
    pi_pos_v3_3qc.value().Save("v3.F2_RESCALED.F2_RESCALED.F2_RESCALED");
    pi_pos_v3_3qb.value().Save("v3.F3_RESCALED.F3_RESCALED.F3_RESCALED");
    file_out->cd("pi_neg");
    pi_neg_v3_3qa.value().Save("v3.F1_RESCALED.F1_RESCALED.F1_RESCALED");
    pi_neg_v3_3qc.value().Save("v3.F2_RESCALED.F2_RESCALED.F2_RESCALED");
    pi_neg_v3_3qb.value().Save("v3.F3_RESCALED.F3_RESCALED.F3_RESCALED");
  }

  //  *******************************************
  //  Calculating v4 with 5P method
  //  *******************************************
  {
    auto proton_4qa = std::make_optional(
        Correlation<16>(file, "/",
                        {"proton_RESCALED"s, "F1_RESCALED"s, "F1_RESCALED"s,
                         "F1_RESCALED"s, "F1_RESCALED"s},
                        {
                            "x4x1x1x1x1cent",
                            "x4x1x1y1y1cent",
                            "x4x1y1x1y1cent",
                            "x4x1y1y1x1cent",
                            "x4y1x1x1y1cent",
                            "x4y1x1y1x1cent",
                            "x4y1y1x1x1cent",
                            "x4y1y1y1y1cent",
                            "y4x1x1x1y1cent",
                            "y4x1x1y1x1cent",
                            "y4x1y1x1x1cent",
                            "y4x1y1y1y1cent",
                            "y4y1x1x1x1cent",
                            "y4y1x1y1y1cent",
                            "y4y1y1x1y1cent",
                            "y4y1y1y1x1cent",
                        }));
    auto proton_4qb = std::make_optional(
        Correlation<16>(file, "/",
                        {"proton_RESCALED"s, "F3_RESCALED"s, "F3_RESCALED"s,
                         "F3_RESCALED"s, "F3_RESCALED"s},
                        {
                            "x4x1x1x1x1cent",
                            "x4x1x1y1y1cent",
                            "x4x1y1x1y1cent",
                            "x4x1y1y1x1cent",
                            "x4y1x1x1y1cent",
                            "x4y1x1y1x1cent",
                            "x4y1y1x1x1cent",
                            "x4y1y1y1y1cent",
                            "y4x1x1x1y1cent",
                            "y4x1x1y1x1cent",
                            "y4x1y1x1x1cent",
                            "y4x1y1y1y1cent",
                            "y4y1x1x1x1cent",
                            "y4y1x1y1y1cent",
                            "y4y1y1x1y1cent",
                            "y4y1y1y1x1cent",
                        }));
    auto proton_4qc = std::make_optional(
        Correlation<16>(file, "/",
                        {"proton_RESCALED"s, "F2_RESCALED"s, "F2_RESCALED"s,
                         "F2_RESCALED"s, "F2_RESCALED"s},
                        {
                            "x4x1x1x1x1cent",
                            "x4x1x1y1y1cent",
                            "x4x1y1x1y1cent",
                            "x4x1y1y1x1cent",
                            "x4y1x1x1y1cent",
                            "x4y1x1y1x1cent",
                            "x4y1y1x1x1cent",
                            "x4y1y1y1y1cent",
                            "y4x1x1x1y1cent",
                            "y4x1x1y1x1cent",
                            "y4x1y1x1x1cent",
                            "y4x1y1y1y1cent",
                            "y4y1x1x1x1cent",
                            "y4y1x1y1y1cent",
                            "y4y1y1x1y1cent",
                            "y4y1y1y1x1cent",
                        }));
    auto pi_pos_4qa = std::make_optional(
        Correlation<16>(file, "/",
                        {"pi_pos_RESCALED"s, "F1_RESCALED"s, "F1_RESCALED"s,
                         "F1_RESCALED"s, "F1_RESCALED"s},
                        {
                            "x4x1x1x1x1cent",
                            "x4x1x1y1y1cent",
                            "x4x1y1x1y1cent",
                            "x4x1y1y1x1cent",
                            "x4y1x1x1y1cent",
                            "x4y1x1y1x1cent",
                            "x4y1y1x1x1cent",
                            "x4y1y1y1y1cent",
                            "y4x1x1x1y1cent",
                            "y4x1x1y1x1cent",
                            "y4x1y1x1x1cent",
                            "y4x1y1y1y1cent",
                            "y4y1x1x1x1cent",
                            "y4y1x1y1y1cent",
                            "y4y1y1x1y1cent",
                            "y4y1y1y1x1cent",
                        }));
    auto pi_pos_4qb = std::make_optional(
        Correlation<16>(file, "/",
                        {"pi_pos_RESCALED"s, "F3_RESCALED"s, "F3_RESCALED"s,
                         "F3_RESCALED"s, "F3_RESCALED"s},
                        {
                            "x4x1x1x1x1cent",
                            "x4x1x1y1y1cent",
                            "x4x1y1x1y1cent",
                            "x4x1y1y1x1cent",
                            "x4y1x1x1y1cent",
                            "x4y1x1y1x1cent",
                            "x4y1y1x1x1cent",
                            "x4y1y1y1y1cent",
                            "y4x1x1x1y1cent",
                            "y4x1x1y1x1cent",
                            "y4x1y1x1x1cent",
                            "y4x1y1y1y1cent",
                            "y4y1x1x1x1cent",
                            "y4y1x1y1y1cent",
                            "y4y1y1x1y1cent",
                            "y4y1y1y1x1cent",
                        }));
    auto pi_pos_4qc = std::make_optional(
        Correlation<16>(file, "/",
                        {"pi_pos_RESCALED"s, "F2_RESCALED"s, "F2_RESCALED"s,
                         "F2_RESCALED"s, "F2_RESCALED"s},
                        {
                            "x4x1x1x1x1cent",
                            "x4x1x1y1y1cent",
                            "x4x1y1x1y1cent",
                            "x4x1y1y1x1cent",
                            "x4y1x1x1y1cent",
                            "x4y1x1y1x1cent",
                            "x4y1y1x1x1cent",
                            "x4y1y1y1y1cent",
                            "y4x1x1x1y1cent",
                            "y4x1x1y1x1cent",
                            "y4x1y1x1x1cent",
                            "y4x1y1y1y1cent",
                            "y4y1x1x1x1cent",
                            "y4y1x1y1y1cent",
                            "y4y1y1x1y1cent",
                            "y4y1y1y1x1cent",
                        }));
    auto pi_neg_4qa = std::make_optional(
        Correlation<16>(file, "/",
                        {"pi_neg_RESCALED"s, "F1_RESCALED"s, "F1_RESCALED"s,
                         "F1_RESCALED"s, "F1_RESCALED"s},
                        {
                            "x4x1x1x1x1cent",
                            "x4x1x1y1y1cent",
                            "x4x1y1x1y1cent",
                            "x4x1y1y1x1cent",
                            "x4y1x1x1y1cent",
                            "x4y1x1y1x1cent",
                            "x4y1y1x1x1cent",
                            "x4y1y1y1y1cent",
                            "y4x1x1x1y1cent",
                            "y4x1x1y1x1cent",
                            "y4x1y1x1x1cent",
                            "y4x1y1y1y1cent",
                            "y4y1x1x1x1cent",
                            "y4y1x1y1y1cent",
                            "y4y1y1x1y1cent",
                            "y4y1y1y1x1cent",
                        }));
    auto pi_neg_4qb = std::make_optional(
        Correlation<16>(file, "/",
                        {"pi_neg_RESCALED"s, "F3_RESCALED"s, "F3_RESCALED"s,
                         "F3_RESCALED"s, "F3_RESCALED"s},
                        {
                            "x4x1x1x1x1cent",
                            "x4x1x1y1y1cent",
                            "x4x1y1x1y1cent",
                            "x4x1y1y1x1cent",
                            "x4y1x1x1y1cent",
                            "x4y1x1y1x1cent",
                            "x4y1y1x1x1cent",
                            "x4y1y1y1y1cent",
                            "y4x1x1x1y1cent",
                            "y4x1x1y1x1cent",
                            "y4x1y1x1x1cent",
                            "y4x1y1y1y1cent",
                            "y4y1x1x1x1cent",
                            "y4y1x1y1y1cent",
                            "y4y1y1x1y1cent",
                            "y4y1y1y1x1cent",
                        }));
    auto pi_neg_4qc = std::make_optional(
        Correlation<16>(file, "/",
                        {"pi_neg_RESCALED"s, "F2_RESCALED"s, "F2_RESCALED"s,
                         "F2_RESCALED"s, "F2_RESCALED"s},
                        {
                            "x4x1x1x1x1cent",
                            "x4x1x1y1y1cent",
                            "x4x1y1x1y1cent",
                            "x4x1y1y1x1cent",
                            "x4y1x1x1y1cent",
                            "x4y1x1y1x1cent",
                            "x4y1y1x1x1cent",
                            "x4y1y1y1y1cent",
                            "y4x1x1x1y1cent",
                            "y4x1x1y1x1cent",
                            "y4x1y1x1x1cent",
                            "y4x1y1y1y1cent",
                            "y4y1x1x1x1cent",
                            "y4y1x1y1y1cent",
                            "y4y1y1x1y1cent",
                            "y4y1y1y1x1cent",
                        }));

    proton_4qa.value() = proton_4qa.value() * 16;
    proton_4qb.value() = proton_4qb.value() * 16;
    proton_4qc.value() = proton_4qc.value() * 16;
    pi_pos_4qa.value() = pi_pos_4qa.value() * 16;
    pi_pos_4qb.value() = pi_pos_4qb.value() * 16;
    pi_pos_4qc.value() = pi_pos_4qc.value() * 16;
    pi_neg_4qa.value() = pi_neg_4qa.value() * 16;
    pi_neg_4qb.value() = pi_neg_4qb.value() * 16;
    pi_neg_4qc.value() = pi_neg_4qc.value() * 16;

    auto qa_qb_1 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F1_RESCALED"s, "F3_RESCALED"s},
        std::array<std::string, 16>{
            "x1x1cent",
            "x1x1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "y1y1cent",
            "y1y1cent",
        });
    auto qa_qd_1 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F1_RESCALED"s, "Tp_RESCALED"s},
        std::array<std::string, 16>{
            "x1x1cent",
            "x1x1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "y1y1cent",
            "y1y1cent",
        });
    auto qb_qd_1 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F3_RESCALED"s, "Tp_RESCALED"s},
        std::array<std::string, 16>{
            "x1x1cent",
            "x1x1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "y1y1cent",
            "y1y1cent",
        });
    auto qc_qd_1 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F2_RESCALED"s, "Tp_RESCALED"s},
        std::array<std::string, 16>{
            "x1x1cent",
            "x1x1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "y1y1cent",
            "y1y1cent",
        });
    auto qa_qb_2 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F1_RESCALED"s, "F3_RESCALED"s},
        std::array<std::string, 16>{
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
        });
    auto qa_qd_2 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F1_RESCALED"s, "Tp_RESCALED"s},
        std::array<std::string, 16>{
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
        });
    auto qb_qd_2 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F3_RESCALED"s, "Tp_RESCALED"s},
        std::array<std::string, 16>{
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
        });
    auto qc_qd_2 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F2_RESCALED"s, "Tp_RESCALED"s},
        std::array<std::string, 16>{
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
        });
    auto qa_qb_3 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F1_RESCALED"s, "F3_RESCALED"s},
        std::array<std::string, 16>{
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
        });
    auto qa_qd_3 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F1_RESCALED"s, "Tp_RESCALED"s},
        std::array<std::string, 16>{
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
        });
    auto qb_qd_3 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F3_RESCALED"s, "Tp_RESCALED"s},
        std::array<std::string, 16>{
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
        });
    auto qc_qd_3 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F2_RESCALED"s, "Tp_RESCALED"s},
        std::array<std::string, 16>{
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
        });
    auto qa_qb_4 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F1_RESCALED"s, "F3_RESCALED"s},
        std::array<std::string, 16>{
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
        });
    auto qa_qd_4 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F1_RESCALED"s, "Tp_RESCALED"s},
        std::array<std::string, 16>{
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
        });
    auto qb_qd_4 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F3_RESCALED"s, "Tp_RESCALED"s},
        std::array<std::string, 16>{
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
        });
    auto qc_qd_4 = FunctionsNE::CreateCorrelation(
        file, "/", std::array{"F2_RESCALED"s, "Tp_RESCALED"s},
        std::array<std::string, 16>{
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
            "x1x1cent",
            "y1y1cent",
            "x1x1cent",
            "y1y1cent",
            "y1y1cent",
            "x1x1cent",
        });
    auto res_qa_1 = std::make_optional(FunctionsNE::Resolution3S(
        qa_qb_1.value(), qa_qd_1.value(), qb_qd_1.value()));
    auto res_qb_1 = std::make_optional(FunctionsNE::Resolution3S(
        qa_qb_1.value(), qb_qd_1.value(), qa_qd_1.value()));
    auto res_qd_1 = std::make_optional(FunctionsNE::Resolution3S(
        qa_qd_1.value(), qb_qd_1.value(), qa_qb_1.value()));
    auto res_qc_1 = std::make_optional(qc_qd_1.value() / res_qd_1.value());
    auto res_qa_2 = std::make_optional(FunctionsNE::Resolution3S(
        qa_qb_2.value(), qa_qd_2.value(), qb_qd_2.value()));
    auto res_qb_2 = std::make_optional(FunctionsNE::Resolution3S(
        qa_qb_2.value(), qb_qd_2.value(), qa_qd_2.value()));
    auto res_qd_2 = std::make_optional(FunctionsNE::Resolution3S(
        qa_qd_2.value(), qb_qd_2.value(), qa_qb_2.value()));
    auto res_qc_2 = std::make_optional(qc_qd_2.value() / res_qd_2.value());
    auto res_qa_3 = std::make_optional(FunctionsNE::Resolution3S(
        qa_qb_3.value(), qa_qd_3.value(), qb_qd_3.value()));
    auto res_qb_3 = std::make_optional(FunctionsNE::Resolution3S(
        qa_qb_3.value(), qb_qd_3.value(), qa_qd_3.value()));
    auto res_qd_3 = std::make_optional(FunctionsNE::Resolution3S(
        qa_qd_3.value(), qb_qd_3.value(), qa_qb_3.value()));
    auto res_qc_3 = std::make_optional(qc_qd_3.value() / res_qd_3.value());
    auto res_qa_4 = std::make_optional(FunctionsNE::Resolution3S(
        qa_qb_4.value(), qa_qd_4.value(), qb_qd_4.value()));
    auto res_qb_4 = std::make_optional(FunctionsNE::Resolution3S(
        qa_qb_4.value(), qb_qd_4.value(), qa_qd_4.value()));
    auto res_qd_4 = std::make_optional(FunctionsNE::Resolution3S(
        qa_qd_4.value(), qb_qd_4.value(), qa_qb_4.value()));
    auto res_qc_4 = std::make_optional(qc_qd_4.value() / res_qd_4.value());
    auto proton_v4_4qa = std::make_optional(
        proton_4qa.value() / (res_qa_1.value() * res_qa_2.value() *
                              res_qa_3.value() * res_qa_4.value() * 4.0));
    auto proton_v4_4qb = std::make_optional(
        proton_4qb.value() / (res_qb_1.value() * res_qb_2.value() *
                              res_qb_3.value() * res_qb_4.value() * 4.0));
    auto proton_v4_4qc = std::make_optional(
        proton_4qc.value() / (res_qc_1.value() * res_qc_2.value() *
                              res_qc_3.value() * res_qc_4.value() * 4.0));
    auto pi_pos_v4_4qa = std::make_optional(
        pi_pos_4qa.value() / (res_qa_1.value() * res_qa_2.value() *
                              res_qa_3.value() * res_qa_4.value() * 4.0));
    auto pi_pos_v4_4qb = std::make_optional(
        pi_pos_4qb.value() / (res_qb_1.value() * res_qb_2.value() *
                              res_qb_3.value() * res_qb_4.value() * 4.0));
    auto pi_pos_v4_4qc = std::make_optional(
        pi_pos_4qc.value() / (res_qc_1.value() * res_qc_2.value() *
                              res_qc_3.value() * res_qc_4.value() * 4.0));
    auto pi_neg_v4_4qa = std::make_optional(
        pi_neg_4qa.value() / (res_qa_1.value() * res_qa_2.value() *
                              res_qa_3.value() * res_qa_4.value() * 4.0));
    auto pi_neg_v4_4qb = std::make_optional(
        pi_neg_4qb.value() / (res_qb_1.value() * res_qb_2.value() *
                              res_qb_3.value() * res_qb_4.value() * 4.0));
    auto pi_neg_v4_4qc = std::make_optional(
        pi_neg_4qc.value() / (res_qc_1.value() * res_qc_2.value() *
                              res_qc_3.value() * res_qc_4.value() * 4.0));
    file_out->cd("proton");
    proton_v4_4qa.value().Save(
        "v4.F1_RESCALED.F1_RESCALED.F1_RESCALED.F1_RESCALED");
    proton_v4_4qc.value().Save(
        "v4.F2_RESCALED.F2_RESCALED.F2_RESCALED.F2_RESCALED");
    proton_v4_4qb.value().Save(
        "v4.F3_RESCALED.F3_RESCALED.F3_RESCALED.F3_RESCALED");
    file_out->cd("pi_pos");
    pi_pos_v4_4qa.value().Save(
        "v4.F1_RESCALED.F1_RESCALED.F1_RESCALED.F1_RESCALED");
    pi_pos_v4_4qc.value().Save(
        "v4.F2_RESCALED.F2_RESCALED.F2_RESCALED.F2_RESCALED");
    pi_pos_v4_4qb.value().Save(
        "v4.F3_RESCALED.F3_RESCALED.F3_RESCALED.F3_RESCALED");
    file_out->cd("pi_neg");
    pi_neg_v4_4qa.value().Save(
        "v4.F1_RESCALED.F1_RESCALED.F1_RESCALED.F1_RESCALED");
    pi_neg_v4_4qc.value().Save(
        "v4.F2_RESCALED.F2_RESCALED.F2_RESCALED.F2_RESCALED");
    pi_neg_v4_4qb.value().Save(
        "v4.F3_RESCALED.F3_RESCALED.F3_RESCALED.F3_RESCALED");
  }

  file_out->Close();
  file->Close();
}
