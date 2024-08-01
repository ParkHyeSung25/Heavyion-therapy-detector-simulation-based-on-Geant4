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
  // TString filename = argv[1];
  // TString outputname = argv[2];

  gStyle->SetOptFit(1);
  TFile *root_file = new TFile(filename+".root","recreate");

  TH1F* tot_MC_Edep = new TH1F("tot_MC_Edep","Total MC Energy deposit;MeV;Evt",100,low,high);
  tot_MC_Edep->Sumw2(); tot_MC_Edep->SetLineColor(kRed); tot_MC_Edep->SetLineWidth(2);
  TH1F* MC_Edep_crystal = new TH1F("MC_Edep_crystal","Total MC crystal Energy deposit;MeV;Evt",100,low,high);
  MC_Edep_crystal->Sumw2(); MC_Edep_crystal->SetLineColor(kRed); MC_Edep_crystal->SetLineWidth(2);
  TH1F* MC_Edep_fiber = new TH1F("MC_Edep_fiber","Total MC fiber Energy deposit;MeV;Evt",100,low,high);
  MC_Edep_fiber->Sumw2(); MC_Edep_fiber->SetLineColor(kRed); MC_Edep_fiber->SetLineWidth(2);

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
  
  TH1F* hot_fiber_x = new TH1F("x_hot_fiber_number","x axis hot fiber;x_sipm_number;Evt",19,0.,19.);
  hot_fiber_x->Sumw2(); hot_fiber_x->SetLineColor(kRed); hot_fiber_x->SetLineWidth(2);  
  TH1F* hot_fiber_y = new TH1F("y_hot_fiber_number","y axis hot fiber;y_sipm_number;Evt",19,0.,19.);
  hot_fiber_y->Sumw2(); hot_fiber_y->SetLineColor(kRed); hot_fiber_y->SetLineWidth(2);
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

  TH1I* crystal_hit = new TH1I("crystal_energy._total","MeV(E)/evt(total);MeV;evt",n_of_b,low,high);crystal_hit->Sumw2(); crystal_hit->SetLineColor(kBlack); crystal_hit->SetLineWidth(2);
  TH1I* x_fiber_hit = new TH1I("fiber_x_energy._total","MeV(E)/evt(total);MeV;evt",n_of_b,low,high);x_fiber_hit->Sumw2(); x_fiber_hit->SetLineColor(kBlack); x_fiber_hit->SetLineWidth(2);
  TH1I* y_fiber_hit = new TH1I("fiber_y_energy._total","MeV(E)/evt(total);MeV;evt",n_of_b,low,high);y_fiber_hit->Sumw2(); y_fiber_hit->SetLineColor(kBlack); y_fiber_hit->SetLineWidth(2);
  TH1I* tot_fiber_hit = new TH1I("fiber_total_energy._total","MeV(E)/evt(total);MeV;evt",n_of_b,low,high);tot_fiber_hit->Sumw2(); tot_fiber_hit->SetLineColor(kBlack); tot_fiber_hit->SetLineWidth(2);

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
    float MC_Edep_fiber_cal = 0.;
    float MC_Edep_crystal_cal = 0.;
    float n_crystal_hit_data = 0.;
    float n_x_fiber_hit_data = 0.;
    float n_y_fiber_hit_data = 0.;
    float n_tot_fiber_hit_data = 0.;
    float ebye_x_fiber_poton = 0.;
    float ebye_y_fiber_poton = 0.;
    int x_fiber_hit_data[20] = {0};  // 20개의 데이터를 저장할 수 있는 배열 생성 // 모든 값 0으로 초기화
    int x_fiber_maxCount = -1;       // 최대 count 값을 저장할 변수. 초기값은 -1로 설정
    int x_fiber_maxSiPMnum = -1;     // 최대 count 값을 가진 SiPMnum 값을 저장할 변수
    int y_fiber_hit_data[20] = {0};  
    int y_fiber_maxCount = -1;       
    int y_fiber_maxSiPMnum = -1;

    for (auto edepItr = drEvt.Edeps.begin(); edepItr != drEvt.Edeps.end(); ++edepItr) {
      auto edep = *edepItr;
      int MC_moduleNum = edepItr->ModuleNum;
      
      tot_MC_Edep_cal += edep.Edep;
      if(MC_moduleNum == 1){
            MC_Edep_fiber_cal += edep.Edep;
      }
      if(MC_moduleNum == 4 ){
            MC_Edep_crystal_cal += edep.Edep;
      }
    }
    tot_MC_Edep->Fill(tot_MC_Edep_cal);
    MC_Edep_fiber->Fill(MC_Edep_fiber_cal);
    MC_Edep_crystal->Fill(MC_Edep_crystal_cal);


//     if(drInterface->numEvt() < 100){
//       if(drInterface->numEvt() % 10 == 0){
//         printf("%d\n",drInterface->numEvt());
//       }
//     }



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
      //   printf("%d\t%d\n",moduleNum, sipm->SiPMnum);
        int SiPMnum = sipm->SiPMnum;
        typedef std::tuple<float,float,float> threeVector;
        // printf("%d\t%d\n", plateNum,fiberNum);
        // printf("%d\n", plateNum);
        threeVector SiPMpos;
        // if (sipm->Crystal == 0 ){
        //   SiPMpos = sipm->pos; 
        //   std::cout << std::get<0>(SiPMpos) << " "
        //     << std::get<1>(SiPMpos) << " "
        //     << std::get<2>(SiPMpos) << std::endl;
        // }
        // if(SiPMnum>19){
        //   printf("%d\n", SiPMnum);
        // }
        // printf("%d\t%d\n", moduleNum, SiPMnum); // 수평 방향 모듈(0)의 Sipm number 20개, 수직 방향 모듈(1)의 Sipm number 20개 출력


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

          if(moduleNum == 0){
            for (int i = 0; i < 20; i++) {
                  if (SiPMnum == i) {
                        x_fiber_hit_data[i] += sipm->count;
                  }
            }
            // int x_fiber_hit_data = sipm->count;
            // n_x_fiber_hit_data+= x_fiber_hit_data;
          }
          if(moduleNum == 1){
            for (int i = 0; i < 20; i++) {
                  if (SiPMnum == i) {
                        y_fiber_hit_data[i] += sipm->count;
                  }
            }
            // int y_fiber_hit_data = sipm->count;
            // n_y_fiber_hit_data+= y_fiber_hit_data;
          }
        }
      }
    }
    
    for (int i = 0; i < 20; i++) {
      ebye_x_fiber_poton = x_fiber_hit_data[i];
      ebye_y_fiber_poton = y_fiber_hit_data[i];
      if (ebye_x_fiber_poton > x_fiber_maxCount) {            
            x_fiber_maxCount = ebye_x_fiber_poton;
            x_fiber_maxSiPMnum = i;
      }
      if (ebye_y_fiber_poton > y_fiber_maxCount) {            
            y_fiber_maxCount = ebye_y_fiber_poton;
            y_fiber_maxSiPMnum = i;
      }
    }
    hot_fiber_x->Fill(x_fiber_maxSiPMnum);
    hot_fiber_y->Fill(y_fiber_maxSiPMnum);

    tHit_C->Fill(nHitC);
    tHit_S->Fill(nHitS);
    // not_used CsI calibration const = 0.026448262085497
    // not_used LYSO calibration const = 0.000847848360656

    // CsI calib const 0.016591478696742
    // LYSO calib const 0.000518808777429
//     crystal_hit->Fill((n_crystal_hit_data)*0.016591478696742);

    float CsI_calib_const = 0.016591478696742;
    float LYSO_calib_const = 0.000518808777429;
    
//     x_fiber_hit->Fill((n_x_fiber_hit_data));
//     y_fiber_hit->Fill((n_y_fiber_hit_data));
//     tot_fiber_hit->Fill((n_tot_fiber_hit_data));
    crystal_hit->Fill((n_crystal_hit_data)*LYSO_calib_const);
  } // event loop
  // drInterface->close();
  // for (int i = 0; i <= 1; i++){
  //   for(int j = 0; j <= 19; j++){
  //     for(int eventN = 0; eventN<=9; eventN++){
  //       tT_S_N_str[i][j][eventN]->Write();
  //     }
  //   }
  // }
  // tHit_S->Write();
  tot_MC_Edep->Write();
  MC_Edep_fiber->Write();
  MC_Edep_crystal->Write();
//   x_fiber_hit->Write();
//   y_fiber_hit->Write();
//   tot_fiber_hit->Write();
  hot_fiber_x->Write();
  hot_fiber_y->Write();
  crystal_hit->Write();
  tT_S->Write();
  // test->Write();

  root_file->Close();
}

