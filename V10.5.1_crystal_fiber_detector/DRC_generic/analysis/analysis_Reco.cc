#include "RootInterface.h"
#include "RecoInterface.h"
#include "DRsimInterface.h"
#include "functions.h"

#include "TROOT.h"
#include "TStyle.h"
#include "TH1.h"
#include "TH2.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TPaveStats.h"
#include "TString.h"
#include "TLorentzVector.h"
#include "TGraph.h"

#include <iostream>
#include <string>
#include <tuple>

int main(int argc, char* argv[]) {

  TString filename =argv[1];
  float n_of_b = std::stof(argv[2]);
  float low = std::stof(argv[3]);
  float high = std::stof(argv[4]);
  TH1F *tT_S_N_str[2][20][10]; 
  TH1F *Fiber_mip_deposit_x_[20]; 
  TH1F *Fiber_mip_deposit_z_[20]; 

  gStyle->SetOptFit(1);
  TFile *root_file = new TFile(filename+".root","recreate");

  TH1F* tot_MC_Edep = new TH1F("tot_MC_Edep","Total MC Energy deposit;MeV;Evt",n_of_b,low,high);
  tot_MC_Edep->Sumw2(); tot_MC_Edep->SetLineColor(kRed); tot_MC_Edep->SetLineWidth(2);
  TH1F* MC_Edep_crystal = new TH1F("MC_Edep_crystal","Total MC crystal Energy deposit;MeV;Evt",n_of_b,low,high);
  MC_Edep_crystal->Sumw2(); MC_Edep_crystal->SetLineColor(kRed); MC_Edep_crystal->SetLineWidth(2);
  TH1F* MC_Edep_fiber = new TH1F("MC_Edep_fiber","Total MC fiber Energy deposit;MeV;Evt",n_of_b,low,high);
  MC_Edep_fiber->Sumw2(); MC_Edep_fiber->SetLineColor(kRed); MC_Edep_fiber->SetLineWidth(2);
  TH1F* MC_Edep_x_fiber = new TH1F("MC_Edep_x_fiber","MC x fiber Energy deposit;MeV;Evt",n_of_b,low,high);
  MC_Edep_x_fiber->Sumw2(); MC_Edep_x_fiber->SetLineColor(kRed); MC_Edep_x_fiber->SetLineWidth(2);
  TH1F* MC_Edep_z_fiber = new TH1F("MC_Edep_z_fiber","MC z fiber Energy deposit;MeV;Evt",n_of_b,low,high);
  MC_Edep_z_fiber->Sumw2(); MC_Edep_z_fiber->SetLineColor(kRed); MC_Edep_z_fiber->SetLineWidth(2);

  TH1F* MC_crystal_hit_rm_nondata = new TH1F("MC_crystal_hit_rm_nondata","MC_crystal_hit_rm_nondata;MeV;Evt",n_of_b,low,high);
  MC_crystal_hit_rm_nondata->Sumw2(); MC_crystal_hit_rm_nondata->SetLineColor(kRed); MC_crystal_hit_rm_nondata->SetLineWidth(2);
  TH1F* MC_crystal_hit_rm_leakage_nondata = new TH1F("MC_crystal_hit_rm_leakage_nondata","MC_crystal_hit_rm_leakage_nondata;MeV;Evt",n_of_b,low,high);
  MC_crystal_hit_rm_leakage_nondata->Sumw2(); MC_crystal_hit_rm_leakage_nondata->SetLineColor(kRed); MC_crystal_hit_rm_leakage_nondata->SetLineWidth(2);
  TH1F* MC_crystal_hit_rm_leakage_nondata_cladding = new TH1F("MC_crystal_hit_rm_leakage_nondata_cladding","MC_crystal_hit_rm_leakage_nondata_cladding;MeV;Evt",n_of_b,low,high);
  MC_crystal_hit_rm_leakage_nondata_cladding->Sumw2(); MC_crystal_hit_rm_leakage_nondata_cladding->SetLineColor(kRed); MC_crystal_hit_rm_leakage_nondata_cladding->SetLineWidth(2);
  
  TH1I* MC_crystal_hit_low = new TH1I("MC_crystal_hit_low._energy","MC_crystal_hit_low;MeV;evt",80,488,496);
  MC_crystal_hit_low->Sumw2(); MC_crystal_hit_low->SetLineColor(kRed); MC_crystal_hit_low->SetLineWidth(2);

  TH1I* MC_crystal_hit_rm_leakage_nondata_cladding_low = new TH1I("MC_crystal_hit_rm_leakage_nondata_cladding_low._energy","MC_crystal_hit_rm_leakage_nondata_cladding_low;MeV;evt",80,488,496);
  MC_crystal_hit_rm_leakage_nondata_cladding_low->Sumw2(); MC_crystal_hit_rm_leakage_nondata_cladding_low->SetLineColor(kRed); MC_crystal_hit_rm_leakage_nondata_cladding_low->SetLineWidth(2);

  TH1F* tHit_C = new TH1F("Hit_C","# of p.e. of Cerenkov ch.;# of p.e.;Evt",50,0,50.);
  tHit_C->Sumw2(); tHit_C->SetLineColor(kBlue); tHit_C->SetLineWidth(2);
  TH1F* tHit_S = new TH1F("Hit_S","# of p.e. of Scintillation ch.;# of p.e.;Evt",50,0,50);
  tHit_S->Sumw2(); tHit_S->SetLineColor(kRed); tHit_S->SetLineWidth(2);

  TH1F* tT_S = new TH1F("time_S","Scint time;ns;p.e.",2400,0.,240.);
  tT_S->Sumw2(); tT_S->SetLineColor(kRed); tT_S->SetLineWidth(2);
  TH1F* tWav_S = new TH1F("wavlen_S","Scint wavelength;nm;p.e.",120,300.,900.);
  tWav_S->Sumw2(); tWav_S->SetLineColor(kRed); tWav_S->SetLineWidth(2);
  TH1F* tWav_C = new TH1F("wavlen_C","Cerenkov wavelength;nm;p.e.",120,300.,900.);
  tWav_C->Sumw2(); tWav_C->SetLineColor(kBlue); tWav_C->SetLineWidth(2);
  TH1F* tNhit_S = new TH1F("nHits_S","Number of Scint p.e./SiPM;p.e.;n",200,0.,200.);
  tNhit_S->Sumw2(); tNhit_S->SetLineColor(kRed); tNhit_S->SetLineWidth(2);
  TH1F* tNhit_C = new TH1F("nHits_C","Number of Cerenkov p.e./SiPM;p.e.;n",50,0.,50.);
  tNhit_C->Sumw2(); tNhit_C->SetLineColor(kBlue); tNhit_C->SetLineWidth(2);

  TH1F* MC_vx = new TH1F("MC_position_x","MC position;vx(mm)",20,-10.,10.);
  MC_vx->Sumw2(); MC_vx->SetLineColor(kRed); MC_vx->SetLineWidth(2);
  TH1F* MC_vz = new TH1F("MC_position_z","MC position;vz(mm)",20,-10.,10.);
  MC_vz->Sumw2(); MC_vz->SetLineColor(kRed); MC_vz->SetLineWidth(2);

  TH1F* hot_fiber_x_all = new TH1F("hot_fiber_x_all_sipm_number","x axis hot fiber;x_sipm_number;Evt",20,0.,20.);
  hot_fiber_x_all->Sumw2(); hot_fiber_x_all->SetLineColor(kBlack); hot_fiber_x_all->SetLineWidth(2);  
  TH1F* hot_fiber_z_all = new TH1F("hot_fiber_z_all_sipm_number","z axis hot fiber;z_sipm_number;Evt",20,0.,20.);
  hot_fiber_z_all->Sumw2(); hot_fiber_z_all->SetLineColor(kBlack); hot_fiber_z_all->SetLineWidth(2);
  
  TH1F* rm_cladding_hot_fiber_x = new TH1F("rm_cladding_hot_fiber_x_sipm_number","x axis hot fiber;x_sipm_number;Evt",20,0.,20.);
  rm_cladding_hot_fiber_x->Sumw2(); rm_cladding_hot_fiber_x->SetLineColor(kBlack); rm_cladding_hot_fiber_x->SetLineWidth(2);  
  TH1F* rm_cladding_hot_fiber_z = new TH1F("rm_cladding_hot_fiber_z_sipm_number","z axis hot fiber;z_sipm_number;Evt",20,0.,20.);
  rm_cladding_hot_fiber_z->Sumw2(); rm_cladding_hot_fiber_z->SetLineColor(kBlack); rm_cladding_hot_fiber_z->SetLineWidth(2);


  TH1F* hot_fiber_x = new TH1F("rm_cladding_leakage_x_hot_fiber_sipm_number","x axis hot fiber;x_sipm_number;Evt",20,0.,20.);
  hot_fiber_x->Sumw2(); hot_fiber_x->SetLineColor(kBlack); hot_fiber_x->SetLineWidth(2);  
  TH1F* hot_fiber_z = new TH1F("rm_cladding_leakage_z_hot_fiber_sipm_number","z axis hot fiber;z_sipm_number;Evt",20,0.,20.);
  hot_fiber_z->Sumw2(); hot_fiber_z->SetLineColor(kBlack); hot_fiber_z->SetLineWidth(2);
  // TH1F *hot_fiber_x_position = (TH1F*)hot_fiber_x->Clone("x_hot_fiber_position");
  TH1F *hot_fiber_x_position = new TH1F("x_hot_fiber_position", "x axis hot fiber position;vx(mm);Evt", hot_fiber_x->GetNbinsX(), -10, 10);
  TH1F *hot_fiber_z_position = new TH1F("z_hot_fiber_position", "z axis hot fiber position;vz(mm);Evt", hot_fiber_z->GetNbinsX(), -10, 10);
  
  TH1F *Subtraction_histo_MC_Reco_x = new TH1F("Subtraction_histo_MC_Reco_x", "histo MC - Reco position;x(mm);Evt", 20,-10.,10.);
  Subtraction_histo_MC_Reco_x->Sumw2(); Subtraction_histo_MC_Reco_x->SetLineColor(kBlack); Subtraction_histo_MC_Reco_x->SetLineWidth(2);
  TH1F *Subtraction_histo_MC_Reco_z = new TH1F("Subtraction_histo_MC_Reco_z", "MC - Reco position;z(mm);Evt", 20,-10.,10.);
  Subtraction_histo_MC_Reco_z->Sumw2(); Subtraction_histo_MC_Reco_z->SetLineColor(kBlack); Subtraction_histo_MC_Reco_z->SetLineWidth(2);

  TH1F* Subtraction_ebye_value_MC_Reco_x = new TH1F("Subtraction_ebye_value_MC_Reco_x","ebye_value MC - Reco position;x(mm);Evt",200, 0., 25.);
  Subtraction_ebye_value_MC_Reco_x->Sumw2(); Subtraction_ebye_value_MC_Reco_x->SetLineColor(kBlack); Subtraction_ebye_value_MC_Reco_x->SetLineWidth(2);  
  TH1F* Subtraction_ebye_value_MC_Reco_z = new TH1F("Subtraction_ebye_value_MC_Reco_z","ebye_value MC - Reco position;z(mm);Evt",200, 0., 25.);
  Subtraction_ebye_value_MC_Reco_z->Sumw2(); Subtraction_ebye_value_MC_Reco_z->SetLineColor(kBlack); Subtraction_ebye_value_MC_Reco_z->SetLineWidth(2);

  TH1I* x_fiber_position_is_null_hit = new TH1I("x_fiber_position_is_null_energy._total","MeV(E)/evt(total);MeV;evt",n_of_b,low,high);x_fiber_position_is_null_hit->Sumw2(); x_fiber_position_is_null_hit->SetLineColor(kBlack); x_fiber_position_is_null_hit->SetLineWidth(2);
  TH1I* z_fiber_position_is_null_hit = new TH1I("z_fiber_position_is_null_energy._total","MeV(E)/evt(total);MeV;evt",n_of_b,low,high);z_fiber_position_is_null_hit->Sumw2(); z_fiber_position_is_null_hit->SetLineColor(kBlack); z_fiber_position_is_null_hit->SetLineWidth(2);
  
  for (int i = 0; i < 20; i++){
    TString Fiber_mip_energy_deposit_x;
    TString Fiber_mip_energy_deposit_z;
    TString str1 = std::to_string(i);
    Fiber_mip_energy_deposit_x = "Fiber_mip_energy_deposit_x" + str1;
    Fiber_mip_energy_deposit_z = "Fiber_mip_energy_deposit_z" + str1;

    Fiber_mip_deposit_x_[i] = new TH1F(Fiber_mip_energy_deposit_x.Data(), "Fiber_mip_energy_deposit_x;MeV;evt",n_of_b,low,high);
    Fiber_mip_deposit_x_[i]->Sumw2();
    Fiber_mip_deposit_x_[i]->SetLineColor(kBlack);
    Fiber_mip_deposit_x_[i]->SetLineWidth(2);

    Fiber_mip_deposit_z_[i] = new TH1F(Fiber_mip_energy_deposit_z.Data(), "Fiber_mip_energy_deposit_z;MeV;evt",n_of_b,low,high);
    Fiber_mip_deposit_z_[i]->Sumw2();
    Fiber_mip_deposit_z_[i]->SetLineColor(kBlack);
    Fiber_mip_deposit_z_[i]->SetLineWidth(2);
  }
  // for (int i = 0; i <= 1; i++){
  //   for(int j = 0; j <= 19; j++){
  //     for(int eventN = 0; eventN<=9; eventN++){
  //       TString tT_S_N;
  //       TString str1 = std::to_string(i);
  //       TString str2 = std::to_string(j);
  //       TString str3 = std::to_string(eventN*10+1); // 1 11 21 31 41 51 ... 91 번째 이벤트라는 제목 의미
  //       tT_S_N = "tT_S_fiberN_" + str1 + "_" + str2 + "_evtN_" + str3;
  //       tT_S_N_str[i][j][eventN] = new TH1F(tT_S_N.Data(), "Sint time;ns;p.e.", 2400, 0., 240.);
  //       tT_S_N_str[i][j][eventN]->Sumw2();
  //       tT_S_N_str[i][j][eventN]->SetLineColor(kBlue);
  //       tT_S_N_str[i][j][eventN]->SetLineWidth(2);
  //     }
  //   }
  // }
  // TH1F* test = new TH1F("test","Scint time;ns;p.e.",600,10.,70.);
  // test->Sumw2(); tT_S->SetLineColor(kRed); tT_S->SetLineWidth(2);

  TH1I* crystal_hit_total = new TH1I("crystal_total._energy","MeV(E)/evt(total);MeV;evt",n_of_b,low,high);crystal_hit_total->Sumw2(); crystal_hit_total->SetLineColor(kBlack); crystal_hit_total->SetLineWidth(2);
  TH1I* crystal_hit_rm_cladding = new TH1I("crystal_hit_rm_cladding._energy","MeV(E)/evt(total);MeV;evt",n_of_b,low,high);crystal_hit_rm_cladding->Sumw2(); crystal_hit_rm_cladding->SetLineColor(kBlack); crystal_hit_rm_cladding->SetLineWidth(2);
  TH1I* crystal_hit_rm_leakage_cladding = new TH1I("crystal_hit_rm_leakage_cladding._energy","MeV(E)/evt(total);MeV;evt",n_of_b,low,high);crystal_hit_rm_leakage_cladding->Sumw2(); crystal_hit_rm_leakage_cladding->SetLineColor(kBlack); crystal_hit_rm_leakage_cladding->SetLineWidth(2);
  
  // 50MeV low energy side tail investigation
  TH1I* crystal_hit_total_low = new TH1I("crystal__total_low_shape._energy","MeV(E)/evt(total);MeV;evt",80,482,490);crystal_hit_total_low->Sumw2(); crystal_hit_total_low->SetLineColor(kBlack); crystal_hit_total_low->SetLineWidth(2);
  TH1I* crystal_hit_rm_cladding_low = new TH1I("crystal_hit_rm_cladding_low_shape._energy","MeV(E)/evt(total);MeV;evt",80,482,490);crystal_hit_rm_cladding_low->Sumw2(); crystal_hit_rm_cladding_low->SetLineColor(kBlack); crystal_hit_rm_cladding_low->SetLineWidth(2);
  TH1I* crystal_hit_rm_leakage_cladding_low = new TH1I("crystal_hit_rm_leakage_cladding_low_shape._energy","MeV(E)/evt(total);MeV;evt",80,482,490);crystal_hit_rm_leakage_cladding_low->Sumw2(); crystal_hit_rm_leakage_cladding_low->SetLineColor(kBlack); crystal_hit_rm_leakage_cladding_low->SetLineWidth(2);
  
  // TH1I* x_fiber_hit = new TH1I("fiber_x_energy._total","MeV(E)/evt(total);MeV;evt",n_of_b,low,high);x_fiber_hit->Sumw2(); x_fiber_hit->SetLineColor(kBlack); x_fiber_hit->SetLineWidth(2);
  // TH1I* y_fiber_hit = new TH1I("fiber_y_energy._total","MeV(E)/evt(total);MeV;evt",n_of_b,low,high);y_fiber_hit->Sumw2(); y_fiber_hit->SetLineColor(kBlack); y_fiber_hit->SetLineWidth(2);
  // TH1I* tot_fiber_hit = new TH1I("fiber_total_energy._total","MeV(E)/evt(total);MeV;evt",n_of_b,low,high);tot_fiber_hit->Sumw2(); tot_fiber_hit->SetLineColor(kBlack); tot_fiber_hit->SetLineWidth(2);
  
  // RootInterface<DRsimInterface::DRsimEventData>* drInterface = new RootInterface<DRsimInterface::DRsimEventData>(std::string(filename), false);
  // drInterface->GetChain("DRsim");

  RootInterface<DRsimInterface::DRsimEventData>* drInterface = new RootInterface<DRsimInterface::DRsimEventData>(std::string("../DRsim/"+filename), false);
  drInterface->GetChain("DRsim");
  
  unsigned int entries = drInterface->entries();
  std::cout << drInterface->entries() << std::endl;


  while (drInterface->numEvt() < entries) {
    if (drInterface->numEvt() % 100 == 0) printf("Analyzing %dth event ...\n", drInterface->numEvt());

    DRsimInterface::DRsimEventData drEvt;
    drInterface->read(drEvt);

    float tot_MC_Edep_cal = 0.;
    float MC_Edep_fiber_cal_tot = 0.;
    float MC_Edep_x_fiber_cal = 0.;
    float MC_Edep_z_fiber_cal = 0.;
    float MC_Edep_crystal_cal = 0.;
    float MC_vx_cal = 0.;
    float MC_vz_cal = 0.;
    float cladding_cal = 0.;
    float Step_vx =0.;
    float Step_vy =0.;
    float Step_vz =0.;
    float Step_Edep = 0.;
    float MC_crystal_hit_rm_nondata_cal = 0.;
    float MC_crystal_hit_rm_leakage_nondata_cal = 0.;
    float MC_crystal_hit_rm_leakage_nondata_cladding_cal = 0.;
    bool skipInnerLoops = false;
    float n_crystal_hit_data = 0.;
    float n_x_fiber_hit_data = 0.;
    float n_z_fiber_hit_data = 0.;
    float n_tot_fiber_hit_data = 0.;
    float ebye_x_fiber_poton = 0.;
    float ebye_z_fiber_poton = 0.;
    float x_fiber_hit_data[21] = {0};  // 20개의 데이터를 저장할 수 있는 배열 생성 // 모든 값 0으로 초기화
    float x_fiber_maxCount = -1;       // 최대 count 값을 저장할 변수. 초기값은 -1로 설정
    float x_fiber_maxSiPMnum = -1;     // 최대 count 값을 가진 SiPMnum 값을 저장할 변수
    float z_fiber_hit_data[21] = {0};  
    float z_fiber_maxCount = -1;       
    float z_fiber_maxSiPMnum = -1;
    float Sipm_position_x = 0.;
    float Sipm_position_z = 0.;
    float Subtraction_e_by_e_x = 0.;
    float Subtraction_e_by_e_z = 0.;
    float init_MC_Edep_fiber_cal = 0.;
    float sum_1 = 0.;
    float sum_2 = 0.;
    bool MC_Edep_fiber_bool = false;

    for (auto edepItr = drEvt.Edeps.begin(); edepItr != drEvt.Edeps.end(); ++edepItr) {
      auto edep = *edepItr;
      tot_MC_Edep_cal += edep.Edep;
    }
    for (auto stepsItr = drEvt.steps.begin(); stepsItr != drEvt.steps.end(); ++stepsItr) {
      auto step = *stepsItr;
      Step_vx = step.vx;
      Step_vy = step.vy;
      Step_vz = step.vz;
      
      // printf("%d\n", Step_vy);
      
      // 입자 위치시작
      // /DRsim/generator/x0 0 mm
      // /DRsim/generator/y0 -10 cm
      // /DRsim/generator/z0 0 mm

      // z fiber 20개 각각 position
      // x = 0, y = -0.5 z = -9.5~ 9.5
      // x fiber 20개 각각 position
      // x = -9.5~ 9.5, y = +0.5 z = 0

      if(Step_vy<= 1){
        MC_Edep_fiber_cal_tot += step.Edep;
        if(step.Edep != 0){
          MC_Edep_fiber_bool = true;
        }
      }
      else{
        MC_Edep_crystal_cal += step.Edep;
      }

      if( -1.0<= Step_vy && Step_vy<= 0.0){
        MC_Edep_z_fiber_cal += step.Edep;
      }
      if( 0.0<= Step_vy && Step_vy<= 1.0){
        MC_Edep_x_fiber_cal += step.Edep;
      }

      if (MC_Edep_fiber_bool){
        if (1<= Step_vy){
          MC_crystal_hit_rm_nondata_cal += step.Edep;
          if (-5.0<= Step_vz && Step_vz<= 5.0){
            if(-5.0<= Step_vx && Step_vx<= 5.0){
              MC_crystal_hit_rm_leakage_nondata_cal += step.Edep;
            }
          }
        }
      }
      sum_1 += 1;
      // 처음 클레딩 위치는 아래와 같다. (fiber 중심 -9.5)
      // 클레딩 사이즈 0.50*mm, 코어 사이즈 0.485*mm 
      // 즉 -10 ~ -9.985 , -9.015 ~ -9 mm

      // 마찮가지로 두번째는
      // -9 ~ -8.985 , -8.015 ~ -8 mm


      // fiber 영역이 아닌 빔포지션 영역만 보므로 -5 ~ 5 mm 영역 까지로 수정
      if(-1.0<= Step_vy && Step_vy<= 0.0){
        for (int i = 0; i < 10; i++) {
          float cladding_cal_min_L = -5.0 + i*1;
          float cladding_cal_max_L = -4.985 + i*1;

          float cladding_cal_min_R = -4.015 + i*1;
          float cladding_cal_max_R = -4.0 + i*1;
          if(cladding_cal_min_L <= Step_vz && Step_vz<= cladding_cal_max_L || cladding_cal_min_R <= Step_vz && Step_vz<= cladding_cal_max_R){
            skipInnerLoops = true;
            // printf("%f\n", Step_vz);
            break;
          }
        }
      }
      // if (skipInnerLoops) {
      //   skipInnerLoops = false;
      //   // printf("%s\n", "건너뛰기");
      //   continue;  // j의 현재 for문을 종료
      // } // contunue를해도 for문이 다음 event의 step을 보는 것이기에 영향 x
      if(0<= Step_vy && Step_vy<= 1.0){
        for (int i = 0; i < 10; i++) {
          float cladding_cal_min_L = -5.0 + i*1;
          float cladding_cal_max_L = -4.985 + i*1;

          float cladding_cal_min_R = -4.015 + i*1;
          float cladding_cal_max_R = -4.0 + i*1;
          if(cladding_cal_min_L <= Step_vx && Step_vx<= cladding_cal_max_L || cladding_cal_min_R <= Step_vx && Step_vx<= cladding_cal_max_R){
            skipInnerLoops = true;
            break;
          }
        }
      }
      // if (skipInnerLoops) {
      //   skipInnerLoops = false;
      //   // printf("%s\n", "건너뛰기");
      //   continue;  // j의 for문을 종료
      //   // contunue를해도 for문이 다음 event의 step을 보는 것이기에 영향 x
      // }
      sum_2 += 1;
      if (MC_Edep_fiber_bool){
        if(!skipInnerLoops){
          if (-5.0<= Step_vz && Step_vz<= 5.0){
            if (-5.0<= Step_vx && Step_vx<= 5.0){
              if(1< Step_vy){
                MC_crystal_hit_rm_leakage_nondata_cladding_cal += step.Edep;
              }
            }
          }
        }
      }
    }
    // printf("%s\t%d\n","sum_1", sum_1);
    // if (sum_2 != 0){
    //     printf("%s\t%d\n","sum_2", sum_2);
    // }

    for (auto GenPtcsItr = drEvt.GenPtcs.begin(); GenPtcsItr != drEvt.GenPtcs.end(); ++GenPtcsItr) {
      auto Genvx = *GenPtcsItr;
      MC_vx_cal += Genvx.vx;
      MC_vz_cal += Genvx.vz;
    }

    tot_MC_Edep->Fill(tot_MC_Edep_cal);
    MC_Edep_fiber->Fill(MC_Edep_fiber_cal_tot);
    MC_Edep_x_fiber->Fill(MC_Edep_x_fiber_cal);
    MC_Edep_z_fiber->Fill(MC_Edep_z_fiber_cal);
    MC_Edep_crystal->Fill(MC_Edep_crystal_cal);
    if(MC_Edep_crystal_cal >= 488.0 && MC_Edep_crystal_cal <= 496.0){
      MC_crystal_hit_low->Fill(MC_Edep_crystal_cal);
    }
    if(MC_crystal_hit_rm_nondata_cal != 0){
      MC_crystal_hit_rm_nondata->Fill(MC_crystal_hit_rm_nondata_cal);
    }
    if(MC_crystal_hit_rm_leakage_nondata_cal != 0){
      MC_crystal_hit_rm_leakage_nondata->Fill(MC_crystal_hit_rm_leakage_nondata_cal);
    }
    if(MC_crystal_hit_rm_leakage_nondata_cladding_cal != 0){
      MC_crystal_hit_rm_leakage_nondata_cladding->Fill(MC_crystal_hit_rm_leakage_nondata_cladding_cal);
    }
    if(MC_crystal_hit_rm_leakage_nondata_cladding_cal >= 488.0 && MC_crystal_hit_rm_leakage_nondata_cladding_cal <= 496.0){
      MC_crystal_hit_rm_leakage_nondata_cladding_low->Fill(MC_crystal_hit_rm_leakage_nondata_cladding_cal);
    }
    // float Pleak = 0.;
    // float Eleak_nu = 0.;
    // for (auto leak : drEvt.leaks) {
    //   TLorentzVector leak4vec;
    //   leak4vec.SetPxPyPzE(leak.px,leak.py,leak.pz,leak.E);
    //   if ( std::abs(leak.pdgId)==12 || std::abs(leak.pdgId)==14 || std::abs(leak.pdgId)==16 ) {
    //     Eleak_nu += leak4vec.P();
    //   } else {
    //     Pleak += leak4vec.P();
    //   }
    // }
    // tP_leak->Fill(Pleak);
    // tP_leak_nu->Fill(Eleak_nu);

    int nHitC = 0; int nHitS = 0;
    for (auto tower = drEvt.towers.begin(); tower != drEvt.towers.end(); ++tower) {
      int moduleNum = tower->ModuleNum;
      for (auto sipm = tower->SiPMs.begin(); sipm != tower->SiPMs.end(); ++sipm) {
        int plateNum = sipm->x;
        int fiberNum = sipm->y;        
        // printf("%d\t%d\n",plateNum, fiberNum);
        int SiPMnum = sipm->SiPMnum;
        typedef std::tuple<float,float,float> threeVector;
        // if ( RecoInterface::IsCerenkov(sipm->x,sipm->y) ) {
        //   tNhit_C->Fill(sipm->count);
        //   for (const auto timepair : sipm->timeStruct) {
        //     tT_C->Fill(timepair.first.first+0.05,timepair.second);
        //     nHitC += timepair.second;
        //     // if (timepair.first.first < 35) {
        //     //   nHitC += timepair.second;
        //     //   // t2DhitC->Fill(60*(moduleNum%7)+fiberNum, 60*(moduleNum/7)+plateNum, timepair.second);
        //     // }
        //   }
        //   for (const auto wavpair : sipm->wavlenSpectrum) {
        //     tWav_C->Fill(wavpair.first.first,wavpair.second);
        //   }
        // } else {
        tNhit_S->Fill(sipm->count);
        nHitS += sipm->count; // s fiber tot optical photon hit
        // t2DhitS->Fill(60*(moduleNum%7)+fiberNum, 60*(moduleNum/7)+plateNum, sipm->count);
        for (const auto timepair : sipm->timeStruct) {
          if (sipm->Crystal == 0 ){
            // event by event optical photon by time (ns) of s fiber by s fiber number
            // if(drInterface->numEvt() < 100){
            //   if(drInterface->numEvt() % 10 == 0){
            //     tT_S_N_str[moduleNum][SiPMnum][drInterface->numEvt() % 10]->Fill(timepair.first.first+0.05,timepair.second);//기준 weght
            //   }
            // }
            // s fiber optical photon by time (ns) // reference Sipmhit code
            tT_S->Fill(timepair.first.first+0.05,timepair.second);
            // if(moduleNum==0 && SiPMnum ==1){
            //   test->Fill(timepair.first.first+0.05,timepair.second);
            // }

          }
        }
        for (const auto wavpair : sipm->wavlenSpectrum) {
          tWav_S->Fill(wavpair.first.first,wavpair.second);
        }
        // if(sipm.crystal == 1){
        //   for (auto sipm:tower.SiPMs){
        //     tsipmXY->Fill(sipm.x,sipm.y,sipm.count);
        //     tNhit->Fill(sipm.count);
        //     int hit = sipm.count;
        //     nhit+=hit;
        //     fired_sipm+=1;
        //     for (const auto timepair:sipm.timeStruct){
        //       tT->Fill(timepair.first.first+0.005,timepair.second);
        //       turnontime->Fill(timepair.first.first+0.005,timepair.second);
        //       if(cbdInterface->numEvt()==982)risetimesipm->Fill(timepair.first.first+0.005,timepair.second);
        //     }
        //     for (const auto wavpair: sipm.wavlenSpectrum){
        //       tWav->Fill(wavpair.first.first,wavpair.second);
        //     }
        //     if(cbdInterface->numEvt()==982){
        //       int risetimesipmbin=risetimesipm->FindFirstBinAbove(0.5);
        //       if(Edep!=0) tXYriseTime->Fill(sipm.x,sipm.y,risetimesipm->GetBinCenter(risetimesipmbin));
        //       risetimesipm->Reset();
        //     }
        //   }
        // }
        if(sipm->Crystal == 1){
          int crystal_hit_data = sipm->count;
          n_crystal_hit_data+= crystal_hit_data;
        }

        // 아래쪽은 fiber 에너지 리컨하려면 cal const를 알아야되는데 모르니까.. 제외하고 일단 MC energy deposit을 확인하자.
        if(sipm->Crystal == 0){
          int tot_fiber_hit_data = sipm->count;
          n_tot_fiber_hit_data+= tot_fiber_hit_data;

          if(moduleNum == 1){
            for (int i = 0; i < 20; i++) {
                  if (SiPMnum == i) {
                        x_fiber_hit_data[i] += sipm->count;
                  }                  
            }
            // int x_fiber_hit_data = sipm->count;
            // n_x_fiber_hit_data+= x_fiber_hit_data;
          }
          if(moduleNum == 0){
            for (int i = 0; i < 20; i++) {
                  if (SiPMnum == i) {
                        z_fiber_hit_data[i] += sipm->count;
                  }
            }
            // int y_fiber_hit_data = sipm->count;
            // n_y_fiber_hit_data+= y_fiber_hit_data;
          }
        }
      }
    }
    float Nomal = 1.0;
    float BGO_calib_const = 0.00326752;
    float CsI_calib_const = 0.016591478696742;
    float LYSO_calib_const = 0.000518808777429;
    float Mu_MiP_min_energy_x_fiber_calibration_const = 0.01165862;
    float Mu_MiP_min_energy_z_fiber_calibration_const = 0.01136646;

    float x_fiber_calibration_const = Mu_MiP_min_energy_x_fiber_calibration_const;
    float z_fiber_calibration_const = Mu_MiP_min_energy_z_fiber_calibration_const;
    float calibration_const = BGO_calib_const;

    for (int i = 0; i < 20; i++) {
      ebye_x_fiber_poton = x_fiber_hit_data[i];
      ebye_z_fiber_poton = z_fiber_hit_data[i];

      Fiber_mip_deposit_x_[i]->Fill((ebye_x_fiber_poton)*x_fiber_calibration_const);
      Fiber_mip_deposit_z_[i]->Fill((ebye_z_fiber_poton)*z_fiber_calibration_const);

      if (ebye_x_fiber_poton > x_fiber_maxCount) {
            x_fiber_maxCount = ebye_x_fiber_poton;
            x_fiber_maxSiPMnum = i;
      }
      if (ebye_z_fiber_poton > z_fiber_maxCount) {            
            z_fiber_maxCount = ebye_z_fiber_poton;
            z_fiber_maxSiPMnum = i;
      }
    }
    // if x_fiber_maxCount 이 0일 때 energy가 얼마나 deposit 되는지 확인용 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    // fiber에 광자 안남긴 데이터 제거
    if (x_fiber_maxCount == 0){
      x_fiber_position_is_null_hit->Fill((n_crystal_hit_data)*calibration_const);
    }
    if (z_fiber_maxCount == 0){
      z_fiber_position_is_null_hit->Fill((n_crystal_hit_data)*calibration_const);
    }
    // if x_fiber_maxCount 이 0일 때 energy가 얼마나 deposit 되는지 확인용 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
   
    // hot fiber all
    hot_fiber_x_all->Fill(x_fiber_maxSiPMnum);
    hot_fiber_z_all->Fill(z_fiber_maxSiPMnum);

    // hot fiber with cladding data removed
    if (x_fiber_maxCount != 0){
      rm_cladding_hot_fiber_x->Fill(x_fiber_maxSiPMnum);
    }
    if (z_fiber_maxCount != 0){
      rm_cladding_hot_fiber_z->Fill(z_fiber_maxSiPMnum);
    }

    // hot fiber with remove cladding data and leakage data
    if (x_fiber_maxCount != 0 && x_fiber_maxSiPMnum != 0 && x_fiber_maxSiPMnum != 1 && x_fiber_maxSiPMnum != 2 && x_fiber_maxSiPMnum != 3 && x_fiber_maxSiPMnum != 4 && x_fiber_maxSiPMnum != 15 && x_fiber_maxSiPMnum != 16 && x_fiber_maxSiPMnum != 17 && x_fiber_maxSiPMnum != 18 && x_fiber_maxSiPMnum != 19 && x_fiber_maxSiPMnum != 20 ){
      // printf("%d\n", MC_vx_cal);
      Sipm_position_x = x_fiber_maxSiPMnum - 9.5;
      Subtraction_e_by_e_x = fabs(MC_vx_cal - Sipm_position_x);
      hot_fiber_x->Fill(x_fiber_maxSiPMnum);
      MC_vx->Fill(MC_vx_cal);
      Subtraction_ebye_value_MC_Reco_x->Fill(Subtraction_e_by_e_x);
    }
    if (z_fiber_maxCount != 0 && z_fiber_maxSiPMnum != 0 && z_fiber_maxSiPMnum != 1 && z_fiber_maxSiPMnum != 2 && z_fiber_maxSiPMnum != 3 && z_fiber_maxSiPMnum != 4 && z_fiber_maxSiPMnum != 15 && z_fiber_maxSiPMnum != 16 && z_fiber_maxSiPMnum != 17 && z_fiber_maxSiPMnum != 18 && z_fiber_maxSiPMnum != 19 && z_fiber_maxSiPMnum != 20){
      Sipm_position_z = z_fiber_maxSiPMnum - 9.5;
      Subtraction_e_by_e_z = fabs(MC_vz_cal - Sipm_position_z);
      hot_fiber_z->Fill(z_fiber_maxSiPMnum);
      MC_vz->Fill(MC_vz_cal);
      Subtraction_ebye_value_MC_Reco_z->Fill(Subtraction_e_by_e_z);
    }

    // hot_fiber_x->Fill(x_fiber_maxSiPMnum);
    // hot_fiber_z->Fill(z_fiber_maxSiPMnum);



    // fiber에 beam position이 안찍혔을 때 e deposit이 어떻게 되고 있는지 확인용
    tHit_C->Fill(nHitC);
    tHit_S->Fill(nHitS);

    

    // CsI calib const 0.016591478696742
    // LYSO calib const 0.000518808777429
//     crystal_hit->Fill((n_crystal_hit_data)*0.016591478696742);
    
//     x_fiber_hit->Fill((n_x_fiber_hit_data));
//     y_fiber_hit->Fill((n_y_fiber_hit_data));
//     tot_fiber_hit->Fill((n_tot_fiber_hit_data));

    crystal_hit_total->Fill((n_crystal_hit_data)*calibration_const);
    // 50 MeV low energy shape investigation
    if((n_crystal_hit_data)*calibration_const >= 482.0 && (n_crystal_hit_data)*calibration_const <= 490.0){
      crystal_hit_total_low->Fill((n_crystal_hit_data)*calibration_const);
    }
    // remove cladding data 
    if (z_fiber_maxCount != 0 && x_fiber_maxCount != 0){
      crystal_hit_rm_cladding->Fill((n_crystal_hit_data)*calibration_const);
      // 50 MeV low energy shape investigation
      if((n_crystal_hit_data)*calibration_const >= 482.0 && (n_crystal_hit_data)*calibration_const <= 490.0){
        crystal_hit_rm_cladding_low->Fill((n_crystal_hit_data)*calibration_const);
      }
    }
    // remove cladding data and leakage data
    if (z_fiber_maxCount != 0 && z_fiber_maxSiPMnum != 0 && z_fiber_maxSiPMnum != 1 && z_fiber_maxSiPMnum != 2 && z_fiber_maxSiPMnum != 3 && z_fiber_maxSiPMnum != 4 && z_fiber_maxSiPMnum != 15 && z_fiber_maxSiPMnum != 16 && z_fiber_maxSiPMnum != 17 && z_fiber_maxSiPMnum != 18 && z_fiber_maxSiPMnum != 19 && z_fiber_maxSiPMnum != 20 && x_fiber_maxCount != 0 && x_fiber_maxSiPMnum != 0 && x_fiber_maxSiPMnum != 1 && x_fiber_maxSiPMnum != 2 && x_fiber_maxSiPMnum != 3 && x_fiber_maxSiPMnum != 4 && x_fiber_maxSiPMnum != 15 && x_fiber_maxSiPMnum != 16 && x_fiber_maxSiPMnum != 17 && x_fiber_maxSiPMnum != 18 && x_fiber_maxSiPMnum != 19 && x_fiber_maxSiPMnum != 20 ){
      crystal_hit_rm_leakage_cladding->Fill((n_crystal_hit_data)*calibration_const);
      // 50 MeV low energy shape investigation
      if((n_crystal_hit_data)*calibration_const >= 482.0 && (n_crystal_hit_data)*calibration_const <= 490.0){
        crystal_hit_rm_leakage_cladding_low->Fill((n_crystal_hit_data)*calibration_const);
      }
    }
  } // event loop
  // drInterface->close();
  // tHit_S->Write();

  for (int i = 1; i <= hot_fiber_x->GetNbinsX(); i++) {
    Double_t old_center = hot_fiber_x->GetBinCenter(i);
    Double_t old_content = hot_fiber_x->GetBinContent(i);
    
    Int_t new_bin = hot_fiber_x_position->FindBin(old_center - 10);
    hot_fiber_x_position->AddBinContent(new_bin, old_content);
  }
  for (int i = 1; i <= hot_fiber_z->GetNbinsX(); i++) {
    Double_t old_center = hot_fiber_z->GetBinCenter(i);
    Double_t old_content = hot_fiber_z->GetBinContent(i);
    
    Int_t new_bin = hot_fiber_z_position->FindBin(old_center - 10);
    hot_fiber_z_position->AddBinContent(new_bin, old_content);
  }
  
  int x_nBins = hot_fiber_x->GetNbinsX();
  int z_nBins = hot_fiber_z->GetNbinsX();
  for (int bin = 1; bin <= x_nBins; bin++) {
      double x_value_MC = MC_vx->GetBinContent(bin);
      double x_value_Reco = hot_fiber_x->GetBinContent(bin);
      Subtraction_histo_MC_Reco_x->AddBinContent(bin, x_value_MC - x_value_Reco);
  }
  for (int bin = 1; bin <= z_nBins; bin++) {
      double z_value_MC = MC_vz->GetBinContent(bin);
      double z_value_Reco = hot_fiber_z->GetBinContent(bin);
      Subtraction_histo_MC_Reco_z->AddBinContent(bin, z_value_MC - z_value_Reco);
  }

  tot_MC_Edep->Write();
  MC_Edep_fiber->Write();
  MC_Edep_x_fiber->Write();
  MC_Edep_z_fiber->Write();
  MC_Edep_crystal->Write();
  MC_vx->Write();
  MC_vz->Write();
  MC_crystal_hit_rm_nondata->Write();
  MC_crystal_hit_rm_leakage_nondata->Write();
  MC_crystal_hit_rm_leakage_nondata_cladding->Write();
  // MC_crystal_hit_low->Write();
  // MC_crystal_hit_rm_leakage_nondata_cladding_low->Write();
//   x_fiber_hit->Write();
//   y_fiber_hit->Write();
//   tot_fiber_hit->Write();
  hot_fiber_x_all->Write();
  hot_fiber_z_all->Write();
  rm_cladding_hot_fiber_x->Write();
  rm_cladding_hot_fiber_z->Write();
  hot_fiber_x->Write();
  hot_fiber_z->Write();
  hot_fiber_x_position->Write();
  hot_fiber_z_position->Write();
  crystal_hit_total->Write();
  crystal_hit_rm_leakage_cladding->Write();
  crystal_hit_rm_cladding->Write();
  Subtraction_histo_MC_Reco_x->Write();
  Subtraction_histo_MC_Reco_z->Write();
  Subtraction_ebye_value_MC_Reco_x->Write();
  Subtraction_ebye_value_MC_Reco_z->Write();
  x_fiber_position_is_null_hit->Write();
  z_fiber_position_is_null_hit->Write();
  tT_S->Write();
  // crystal_hit_total_low->Write();
  // crystal_hit_rm_cladding_low->Write();
  // crystal_hit_rm_leakage_cladding_low->Write();
  for (int i = 0; i <= 19; i++){
    Fiber_mip_deposit_x_[i]->Write();
    Fiber_mip_deposit_z_[i]->Write();
  }
  // for (int i = 0; i <= 1; i++){
  //   for(int j = 0; j <= 19; j++){
  //     for(int eventN = 0; eventN<=9; eventN++){
  //       tT_S_N_str[i][j][eventN]->Write();
  //     }
  //   }
  // }
  
  root_file->Close();
}

