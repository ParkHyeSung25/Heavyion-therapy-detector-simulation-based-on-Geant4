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

  TH1F* tEdep = new TH1F("totEdep","Total Energy deposit;MeV;Evt",100,low,high);
  tEdep->Sumw2(); tEdep->SetLineColor(kRed); tEdep->SetLineWidth(2);
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
  for (int i = 0; i <= 1; i++){
    for(int j = 0; j <= 19; j++){
      for(int eventN = 0; eventN<=9; eventN++){
        TString tT_S_N;
        TString str1 = std::to_string(i);
        TString str2 = std::to_string(j);
        TString str3 = std::to_string(eventN*10+1); // 1 11 21 31 41 51 ... 91 번째 이벤트라는 제목 의미
        tT_S_N = "tT_S_fiberN_" + str1 + "_" + str2 + "_evtN_" + str3;
        tT_S_N_str[i][j][eventN] = new TH1F(tT_S_N.Data(), "Sint time;ns;p.e.", 2400, 0., 240.);
        tT_S_N_str[i][j][eventN]->Sumw2();
        tT_S_N_str[i][j][eventN]->SetLineColor(kBlue);
        tT_S_N_str[i][j][eventN]->SetLineWidth(2);
      }
    }
  }
  // TH1F* test = new TH1F("test","Scint time;ns;p.e.",600,10.,70.);
  // test->Sumw2(); tT_S->SetLineColor(kRed); tT_S->SetLineWidth(2);

  TH1I* crystal_hit = new TH1I("p.e._total","MeV(E)/evt(total);MeV;evt",n_of_b,low,high);crystal_hit->Sumw2(); crystal_hit->SetLineColor(kBlack); crystal_hit->SetLineWidth(2);
  
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

    float Edep = 0.;
    float n_crystal_hit_data =0.;
    for (auto edepItr = drEvt.Edeps.begin(); edepItr != drEvt.Edeps.end(); ++edepItr) {
      auto edep = *edepItr;
      Edep += edep.Edep;
    }
    tEdep->Fill(Edep);



    if(drInterface->numEvt() < 100){
      if(drInterface->numEvt() % 10 == 0){
        printf("%d\n",drInterface->numEvt());
      }
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
          // tNhit_S->Fill(sipm->count);
          // nHitS += sipm->count; // s fiber tot optical photon hit
        // t2DhitS->Fill(60*(moduleNum%7)+fiberNum, 60*(moduleNum/7)+plateNum, sipm->count);
        for (const auto timepair : sipm->timeStruct) {
          if (sipm->Crystal == 0 ){
            // event by event optical photon by time (ns) of s fiber by s fiber number
            if(drInterface->numEvt() < 100){
              if(drInterface->numEvt() % 10 == 0){
                tT_S_N_str[moduleNum][SiPMnum][drInterface->numEvt() % 10]->Fill(timepair.first.first+0.05,timepair.second);//기준 weght
              }
            }
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
        // fiber by 
        if(sipm->Crystal == 0){
          int tot_fiber_hit_data = sipm->count;
          n_tot_fiber_hit_data+= tot_fiber_hit_data;
          if(fiberNum == 0){
            int x_fiber_hit_data = sipm->count;
            n_x_fiber_hit_data+= x_fiber_hit_data;
          }
          if(fiberNum == 1){
            int y_fiber_hit_data = sipm->count;
            n_y_fiber_hit_data+= y_fiber_hit_data;
          }
        }
      }
    }
    // tHit_C->Fill(nHitC);
    // tHit_S->Fill(nHitS);

    // not_used CsI calibration const = 0.026448262085497
    // not_used LYSO calibration const = 0.000847848360656

    int CsI_calib_const = 0.016591478696742
    int LYSO_calib_const = 0.000518808777429
    
    x_fiber_hit->Fill((n_x_fiber_hit_data)*CsI_calib_const);
    y_fiber_hit->Fill((n_y_fiber_hit_data)*CsI_calib_const);
    tot_fiber_hit->Fill((n_tot_fiber_hit_data)*CsI_calib_const);
    crystal_hit->Fill((n_crystal_hit_data)*CsI_calib_const);

  } // event loop
  // drInterface->close();
  for (int i = 0; i <= 1; i++){
    for(int j = 0; j <= 19; j++){
      for(int eventN = 0; eventN<=9; eventN++){
        tT_S_N_str[i][j][eventN]->Write();
      }
    }
  }
  x_fiber_hit->Write();
  y_fiber_hit->Write();
  tot_fiber_hit->Write();
  crystal_hit->Write();
  tT_S->Write();
  // test->Write();

  root_file->Close();
}

