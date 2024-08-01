#include "RootInterface.h"
#include "DRsimInterface.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TH1.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TPaveStats.h"
#include "TString.h"
#include "TLorentzVector.h"
#include "TH2.h"
#include "TH2Poly.h"
#include "TH3.h"
#include "TMath.h"
#include "TGraph.h"
#include "TLegend.h"
#include "TMultiGraph.h"

#include <iostream>
#include <string>
#include <cmath>

int main(int argc, char* argv[]){

      // total entri = 15,000
      // E Units = MeV
      float True_c50 = 600.00;
      float True_c100 = 1200.00;
      float True_c200 = 2400.00;
      float True_c300 = 3600.00;
      float True_c400 = 4800.00;

      float LYSO_c50_Mean = 493.8; 
      float LYSO_c100_Mean = 1132; 
      float LYSO_c200_Mean = 2349; 
      float LYSO_c300_Mean = 3581; 
      float LYSO_c400_Mean = 4848; 

      float CsI_c50_Mean = 513; 
      float CsI_c100_Mean = 1133;  
      float CsI_c200_Mean = 2342; 
      float CsI_c300_Mean = 3663;
      float CsI_c400_Mean = 5138;

      float BGO_c50_Mean = 497.5; 
      float BGO_c100_Mean = 1134; 
      float BGO_c200_Mean = 2353; 
      float BGO_c300_Mean = 3593; 
      float BGO_c400_Mean = 4858; 

      // Draw할 캔버스 생성(빈 그림판 생성)
      auto c = new TCanvas("c","c",600,500);

      // axis grid 생성
      gPad->SetGrid(1,1); // x축, y축 (0 = grid 사용 x, 1 = grid 사용)

      TGraph *CsI_E_linearity = new TGraph();
      CsI_E_linearity -> SetPoint(CsI_E_linearity->GetN(), True_c50, CsI_c50_Mean/True_c50);
      CsI_E_linearity -> SetPoint(CsI_E_linearity->GetN(), True_c100, CsI_c100_Mean/True_c100);
      CsI_E_linearity -> SetPoint(CsI_E_linearity->GetN(), True_c200, CsI_c200_Mean/True_c200);
      CsI_E_linearity -> SetPoint(CsI_E_linearity->GetN(), True_c300, CsI_c300_Mean/True_c300);
      CsI_E_linearity -> SetPoint(CsI_E_linearity->GetN(), True_c400, CsI_c400_Mean/True_c400);

      TGraph *BGO_E_linearity = new TGraph();
      BGO_E_linearity -> SetPoint(BGO_E_linearity->GetN(), True_c50, BGO_c50_Mean/True_c50);
      BGO_E_linearity -> SetPoint(BGO_E_linearity->GetN(), True_c100, BGO_c100_Mean/True_c100);
      BGO_E_linearity -> SetPoint(BGO_E_linearity->GetN(), True_c200, BGO_c200_Mean/True_c200);
      BGO_E_linearity -> SetPoint(BGO_E_linearity->GetN(), True_c300, BGO_c300_Mean/True_c300);
      BGO_E_linearity -> SetPoint(BGO_E_linearity->GetN(), True_c400, BGO_c400_Mean/True_c400);

      TGraph *LYSO_E_linearity = new TGraph();
      LYSO_E_linearity -> SetPoint(LYSO_E_linearity->GetN(), True_c50, LYSO_c50_Mean/True_c50);
      LYSO_E_linearity -> SetPoint(LYSO_E_linearity->GetN(), True_c100, LYSO_c100_Mean/True_c100);
      LYSO_E_linearity -> SetPoint(LYSO_E_linearity->GetN(), True_c200, LYSO_c200_Mean/True_c200);
      LYSO_E_linearity -> SetPoint(LYSO_E_linearity->GetN(), True_c300, LYSO_c300_Mean/True_c300);
      LYSO_E_linearity -> SetPoint(LYSO_E_linearity->GetN(), True_c400, LYSO_c400_Mean/True_c400);

      // axis point 모양, 색깔, 크기 변경
      CsI_E_linearity -> SetMarkerStyle(21);
      CsI_E_linearity -> SetMarkerColor(kGreen);
      CsI_E_linearity -> SetMarkerSize(0.7);

      BGO_E_linearity -> SetMarkerStyle(21);
      BGO_E_linearity -> SetMarkerColor(kBlue);
      BGO_E_linearity -> SetMarkerSize(0.7);

      LYSO_E_linearity -> SetMarkerStyle(21);
      LYSO_E_linearity -> SetMarkerColor(kRed);
      LYSO_E_linearity -> SetMarkerSize(0.7);

      // 범위 조정
      // TAxis *axisy = E_linearity->GetYaxis();
      // TAxis *axisx = E_linearity->GetXaxis();
      // axisy->SetRangeUser(0.9, 1.1);
      // axisx->SetRangeUser(0.0, 1.5);
      // 범위조정 안되서 그래프 끝단에 점 추가
      TGraph* aFrame = new TGraph();
      aFrame->SetPoint(0, 0.0, 0.7);
      aFrame->SetPoint(1, 0.0, 1.15);
      aFrame->SetPoint(2, 5200.0, 0.7);
      aFrame->SetPoint(3, 5200.0, 1.15);
      aFrame->SetLineWidth(0);
      aFrame->SetMarkerSize(0.01);
      aFrame->SetMarkerColor(1);
      aFrame->SetMarkerStyle(20);

      TMultiGraph *E_linearity = new TMultiGraph();
      E_linearity->Add(aFrame, "p");
      E_linearity->Add(CsI_E_linearity, "p");
      E_linearity->Add(LYSO_E_linearity, "p");
      E_linearity->Add(BGO_E_linearity, "p");
      E_linearity -> SetTitle("Carbon energy linearity");
      E_linearity -> GetXaxis() -> SetTitle("E truth (MeV/u)");
      E_linearity -> GetYaxis() -> SetTitle("E mean/E truth");
      E_linearity->Draw();

      // explan box 추가
      auto legend = new TLegend(0.1,0.7,0.48,0.9); // x1, y1, x2, y2 위치지정
      // legend->SetHeader("Gamma energy linearity","C"); // option "C" allows to center the header
      legend->AddEntry(CsI_E_linearity,"CsI Energy linearity","p");// p 옵션을 추가해주면 선은 그리지 않고 pointer만 그리게 되어있다., l 옵션은 라인, lep는 뭐지
      legend->AddEntry(BGO_E_linearity,"BGO Energy linearity","p");
      legend->AddEntry(LYSO_E_linearity,"LYSO Energy linearity","p");
      legend->Draw("SAME"); // 그림옵션 동일하게

      //Draw 없이 루트파일 자체저장
      TString input_str = argv[1];
      TString filename = "/u/user/parkh/Geant4_10.5.1/after_eo_crystal/DRC_generic/build/analysis/"+input_str;
      TFile *root_file = new TFile(filename+".root","recreate");
      //E_linearity->Write("Energy linearity");
      c->Write();
      root_file->Close();
}