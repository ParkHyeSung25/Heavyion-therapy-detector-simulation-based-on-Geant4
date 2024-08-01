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
#include "TGraphErrors.h"
#include "TLegend.h"

#include <iostream>
#include <string>
#include <cmath>
#include "TMultiGraph.h"

int main(int argc, char* argv[]){
      
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

      float LYSO_c50_Sigma = 1.254; 
      float LYSO_c100_Sigma = 1.213; 
      float LYSO_c200_Sigma = 1.499; 
      float LYSO_c300_Sigma = 1.77; 
      float LYSO_c400_Sigma = 2.033; 

      float LYSO_c50_error_propa = 0.0000202511;
      float LYSO_c100_error_propa = 0.0000088339;
      float LYSO_c200_error_propa = 0.0000055343;
      float LYSO_c300_error_propa = 0.000005585;
      float LYSO_c400_error_propa = 0.0000049505;

      float CsI_c50_Mean = 513; 
      float CsI_c100_Mean = 1133;  
      float CsI_c200_Mean = 2342; 
      float CsI_c300_Mean = 3663;
      float CsI_c400_Mean = 5138;

      float CsI_c50_Sigma = 3.122; 
      float CsI_c100_Sigma = 4.407; 
      float CsI_c200_Sigma = 6.549; 
      float CsI_c300_Sigma = 8.18; 
      float CsI_c400_Sigma = 9.903; 

      float CsI_c50_error_propa = 0.0000467836;
      float CsI_c100_error_propa = 0.0000317741;
      float CsI_c200_error_propa = 0.0000239115; 
      float CsI_c300_error_propa = 0.0000218401;
      float CsI_c400_error_propa = 0.0000186844;

      float BGO_c50_Mean = 497.5; 
      float BGO_c100_Mean = 1134; 
      float BGO_c200_Mean = 2353; 
      float BGO_c300_Mean = 3593; 
      float BGO_c400_Mean = 4858; 

      float BGO_c50_Sigma = 1.671; 
      float BGO_c100_Sigma = 2.135; 
      float BGO_c200_Sigma = 2.927; 
      float BGO_c300_Sigma = 3.646; 
      float BGO_c400_Sigma = 4.257; 

      float BGO_c50_error_propa = 0.0000261307;
      float BGO_c100_error_propa = 0.000015873;
      float BGO_c200_error_propa = 0.0000106247;
      float BGO_c300_error_propa = 0.0000091845;
      float BGO_c400_error_propa = 0.0000088514;

      Double_t x[5] = {1/sqrt(True_c50), 1/sqrt(True_c100), 1/sqrt(True_c200), 1/sqrt(True_c300), 1/sqrt(True_c400)};
      Double_t CsI_y[5] = {CsI_c50_Sigma/CsI_c50_Mean, CsI_c100_Sigma/CsI_c100_Mean, CsI_c200_Sigma/CsI_c200_Mean, CsI_c300_Sigma/CsI_c300_Mean, CsI_c400_Sigma/CsI_c400_Mean};
      Double_t BGO_y[5] = {BGO_c50_Sigma/BGO_c50_Mean, BGO_c100_Sigma/BGO_c100_Mean, BGO_c200_Sigma/BGO_c200_Mean, BGO_c300_Sigma/BGO_c300_Mean, BGO_c400_Sigma/BGO_c400_Mean};
      Double_t LYSO_y[5] = {LYSO_c50_Sigma/LYSO_c50_Mean, LYSO_c100_Sigma/LYSO_c100_Mean,LYSO_c200_Sigma/LYSO_c200_Mean, LYSO_c300_Sigma/LYSO_c300_Mean, LYSO_c400_Sigma/LYSO_c400_Mean};
      Double_t CsI_error_propa[5] = {CsI_c50_error_propa, CsI_c100_error_propa, CsI_c200_error_propa, CsI_c300_error_propa, CsI_c400_error_propa};
      Double_t BGO_error_propa[5] = {BGO_c50_error_propa, BGO_c100_error_propa, BGO_c200_error_propa, BGO_c300_error_propa, BGO_c400_error_propa};
      Double_t LYSO_error_propa[5] = {LYSO_c50_error_propa, LYSO_c100_error_propa, LYSO_c200_error_propa, LYSO_c300_error_propa, LYSO_c400_error_propa};

      Double_t x_fit[4] = {1/sqrt(True_c100), 1/sqrt(True_c200), 1/sqrt(True_c300), 1/sqrt(True_c400)};
      Double_t CsI_y_fit[4] = {CsI_c100_Sigma/CsI_c100_Mean, CsI_c200_Sigma/CsI_c200_Mean, CsI_c300_Sigma/CsI_c300_Mean, CsI_c400_Sigma/CsI_c400_Mean};
      Double_t BGO_y_fit[4] = {BGO_c100_Sigma/BGO_c100_Mean, BGO_c200_Sigma/BGO_c200_Mean, BGO_c300_Sigma/BGO_c300_Mean, BGO_c400_Sigma/BGO_c400_Mean};
      Double_t LYSO_y_fit[4] = {LYSO_c100_Sigma/LYSO_c100_Mean, LYSO_c200_Sigma/LYSO_c200_Mean, LYSO_c300_Sigma/LYSO_c300_Mean, LYSO_c400_Sigma/LYSO_c400_Mean};
      Double_t CsI_error_propa_fit[4] = {CsI_c100_error_propa, CsI_c200_error_propa, CsI_c300_error_propa, CsI_c400_error_propa};
      Double_t BGO_error_propa_fit[4] = {BGO_c100_error_propa, BGO_c200_error_propa, BGO_c300_error_propa, BGO_c400_error_propa};
      Double_t LYSO_error_propa_fit[4] = {LYSO_c100_error_propa, LYSO_c200_error_propa, LYSO_c300_error_propa, LYSO_c400_error_propa};

      // Draw할 캔버스 생성(빈 그림판 생성)
      auto c = new TCanvas("c","c",600,500);

      // axis grid 생성
      gPad->SetGrid(0,1); // x축, y축 (0 = grid 사용 x, 1 = grid 사용)
      //gStyle->SetOptFit(0001);
      TGraphErrors *CsI_E_resolution = new TGraphErrors(5,x,CsI_y,0,CsI_error_propa);
      TGraphErrors *BGO_E_resolution = new TGraphErrors(5,x,BGO_y,0,BGO_error_propa);
      TGraphErrors *LYSO_E_resolution = new TGraphErrors(5,x,LYSO_y,0,LYSO_error_propa); 

      // 50MeV를 제외한 데이터만 포함하는 새로운 TGraphErrors 객체 생성
      TGraphErrors *CsI_E_resolution_fit = new TGraphErrors(4, x_fit, CsI_y_fit, 0, CsI_error_propa_fit);
      TGraphErrors *BGO_E_resolution_fit = new TGraphErrors(4, x_fit, BGO_y_fit, 0, BGO_error_propa_fit);
      TGraphErrors *LYSO_E_resolution_fit = new TGraphErrors(4, x_fit, LYSO_y_fit, 0, LYSO_error_propa_fit);

      CsI_E_resolution->SetMarkerStyle(21);
      CsI_E_resolution->SetMarkerColor(kGreen);
      CsI_E_resolution -> SetMarkerSize(0.7);

      BGO_E_resolution->SetMarkerStyle(21);
      BGO_E_resolution->SetMarkerColor(kBlue);
      BGO_E_resolution -> SetMarkerSize(0.7);

      LYSO_E_resolution->SetMarkerStyle(21);
      LYSO_E_resolution->SetMarkerColor(kRed);
      LYSO_E_resolution -> SetMarkerSize(0.7);


      // linear fitting
      TF1 *linear = new TF1("Linear law","[0]*x + [1]", 0, x_fit[3]*3);
      linear->SetParName(0, "CsI_slope"); // p0 slope : 기울기
      linear->SetParName(1, "CsI_intercept"); // p1 : intercept : y 절편
      double CsI_slope = linear->GetParameter(0); // 기울기
      double CsI_intercept = linear->GetParameter(1); // y 절편
      linear -> SetNpx(700);
      CsI_E_resolution_fit -> Fit(linear, "G");

      TF1 *linear2 = new TF1("Linear law","[0]*x + [1]", 0, x_fit[3]*3);
      linear2->SetParName(0, "BGO_slope"); // p0 slope : 기울기
      linear2->SetParName(1, "BGO_intercept"); // p1 : intercept : y 절편
      double BGO_slope = linear2->GetParameter(0); // 기울기
      double BGO_intercept = linear2->GetParameter(1); // y 절편
      linear2 -> SetNpx(700);
      BGO_E_resolution_fit->Fit(linear2, "R");

      TF1 *linear3 = new TF1("Linear law","[0]*x + [1]", 0, x_fit[3]*3);
      linear3 -> SetNpx(700);
      linear3->SetParName(0, "LYSO_slope"); // p0에 slope : 기울기 추가
      linear3->SetParName(1, "LYSO_intercept"); // p1 : intercept : y 절편 추가
      double LYSO_slope = linear3->GetParameter(0); // 기울기
      double LYSO_intercept = linear3->GetParameter(1); // y 절편
      LYSO_E_resolution_fit -> Fit(linear3, "R");

      // 범위 조정
      // TAxis *axisy = E_resolution->GetYaxis();
      // axisy->SetRangeUser(0.0, 0.2);
      // TAxis *axisx = E_resolution->GetXaxis();
      // axisx->SetRangeUser(0.1, 5);
      TGraph* aFrame = new TGraph();
      aFrame->SetPoint(0, 0.0, 0.03);
      aFrame->SetPoint(1, 0.05, 0.03);
      aFrame->SetPoint(2, 0.0, 0.0);
      aFrame->SetPoint(3, 0.05, 0.0);
      aFrame->SetLineWidth(0);
      aFrame->SetMarkerSize(0.01);
      aFrame->SetMarkerColor(1);
      aFrame->SetMarkerStyle(20);

      // 한 플롯에 그래프 여러개 그리기
      TMultiGraph *E_resolution = new TMultiGraph();
      E_resolution->Add(aFrame, "p");
      E_resolution->Add(CsI_E_resolution, "p");
      E_resolution->Add(BGO_E_resolution, "p");
      E_resolution->Add(LYSO_E_resolution, "p");
      E_resolution -> SetTitle("Carbon energy resolution");
      E_resolution -> GetXaxis() -> SetTitle("1/#sqrt{E}(MeV/u)");
      E_resolution -> GetYaxis() -> SetTitle("#sigma/E");
      E_resolution->Draw();

      linear->Draw("same");
      linear2->Draw("same");
      linear3->Draw("same");

      // linear의 통계 정보 가져오기
      // 위에서 사용했으므로 다시 정의해줘야됌
      double slope1 = linear->GetParameter(0);
      double slope1_error = linear->GetParError(0);
      double intercept1 = linear->GetParameter(1);
      double intercept1_error = linear->GetParError(1);
      double chi2_ndf1 = linear->GetChisquare() / linear->GetNDF();

      double slope2 = linear2->GetParameter(0);
      double slope2_error = linear->GetParError(0);
      double intercept2 = linear2->GetParameter(1);
      double intercept2_error = linear2->GetParError(1);
      double chi2_ndf2 = linear2->GetChisquare() / linear2->GetNDF();

      double slope3 = linear3->GetParameter(0);
      double slope3_error = linear3->GetParError(0);
      double intercept3 = linear3->GetParameter(1);
      double intercept3_error = linear3->GetParError(1);
      double chi2_ndf3 = linear3->GetChisquare() / linear3->GetNDF();

      // TPaveText를 사용하여 통계 박스 만들기
      // TPaveText *pt = new TPaveText(0.6,0.6,0.9,0.9,"brNDC"); // 위치 조정
      // pt->SetFillColor(0);
      // pt->SetTextSize(0.03);
      // pt->AddText(Form("CsI Chi^2/NDF: %.3f", chi2_ndf1));
      // pt->AddText(Form("CsI Slope: %f #pm %f", slope1, slope1_error));
      // pt->AddText(Form("CsI Intercept: %f #pm %f", intercept1, intercept1_error));
      // pt->AddText(Form("BGO Chi^2/NDF: %.3f", chi2_ndf2));
      // pt->AddText(Form("BGO Slope: %f #pm %f", slope2, slope2_error));
      // pt->AddText(Form("BGO Intercept: %f #pm %f", intercept2, intercept2_error));
      // pt->AddText(Form("LYSO Slope: %f #pm %f", slope3, slope3_error));
      // pt->AddText(Form("LYSO Intercept: %f #pm %f", intercept3, intercept3_error));
      // pt->AddText(Form("LYSO Chi^2/NDF: %.3f", chi2_ndf3));
      // pt->Draw("same");
      TPaveText *pt = new TPaveText(0.6,0.6,0.9,0.9,"brNDC"); // 위치 조정
      pt->SetFillColor(0);
      pt->SetTextSize(0.03);

      TText *text1 = pt->AddText(Form("CsI #chi^{2}/NDF: %.3f", chi2_ndf1));
      text1->SetTextColor(kGreen); // 초록색으로 설정
      TText *text2 = pt->AddText(Form("CsI Slope: %f/#sqrt{E} #pm %f", slope1, slope1_error));
      text2->SetTextColor(kGreen); // 파란색으로 설정
      TText *text3 = pt->AddText(Form("CsI Intercept: %f #pm %f", intercept1, intercept1_error));
      text3->SetTextColor(kGreen);
      pt->AddText(""); // 빈줄 추가
      TText *text4 = pt->AddText(Form("BGO #chi^{2}/NDF: %.3f", chi2_ndf2));
      text4->SetTextColor(kBlue); // 파란색으로 설정
      TText *text5 = pt->AddText(Form("BGO Slope: %f/#sqrt{E} #pm %f", slope2, slope2_error));
      text5->SetTextColor(kBlue);
      TText *text6 = pt->AddText(Form("BGO Intercept: %f #pm %f", intercept2, intercept2_error));
      text6->SetTextColor(kBlue); 
      pt->AddText("");
      TText *text7 = pt->AddText(Form("LYSO #chi^{2}/NDF: %.3f", chi2_ndf3));
      text7->SetTextColor(kRed);
      TText *text8 = pt->AddText(Form("LYSO Slope: %f/#sqrt{E} #pm %f", slope3, slope3_error));
      text8->SetTextColor(kRed); // 빨간색으로 설정
      TText *text9 = pt->AddText(Form("LYSO Intercept: %f #pm %f", intercept3, intercept3_error));
      text9->SetTextColor(kRed);
      pt->Draw("same");

      // explan box 추가
      auto legend = new TLegend(0.1,0.7,0.48,0.9); // x1, y1, x2, y2 위치지정
      // legend->SetHeader("Gamma energy linearity","C"); // option "C" allows to center the header
      legend->AddEntry(CsI_E_resolution,"CsI Energy resolution","p"); // p 옵션을 추가해주면 선은 그리지 않고 pointer만 그리게 되어있다., l 옵션은 라인, lep는 뭐지
      legend->AddEntry(BGO_E_resolution,"BGO Energy resolution","p");
      legend->AddEntry(LYSO_E_resolution,"LYSO Energy resolution","p"); 
      legend->Draw("SAME"); // 그림옵션 동일하게

      // 루트로 뽑을 때는 그래프 선 없애려면 포인트에 마우스 우클릭해서 set draw option 들어가서 APE 입력 
      // TCanvas* c = new TCanvas("c", "c", 500, 1000); // canvas title, name, window size x, y
      // c->cd();
      // E_resolution -> Draw("APE");
      // c->SaveAs("test.png");

      TString input_str = argv[1];
      TString filename = "/u/user/parkh/Geant4_10.5.1/after_eo_crystal/DRC_generic/build/analysis/"+input_str;
      TFile *root_file = new TFile(filename+".root","recreate");
      c->Write();
      root_file->Close();

      //E_linearity->Draw("Hist"); c->SaveAs(filename+"_Edep.png");
}