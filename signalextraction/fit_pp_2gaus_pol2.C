#include <TMath.h>
#include <TF1.h>
#include <TNamed.h>
#include <TNtuple.h>
#include <TTree.h>
#include <TMath.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TLatex.h>
#include <TLorentzVector.h>
#define MAX_XB       20000
//this is for fit the pp 2015 lambdaC
void fit_pp_2gaus_pol2(){
//TFile *f =new TFile("hist_pp_10_20.root");
//TFile *f = new TFile("/home/xiao147/private/newchannel_lambda_CtoproduceDntuple/CMSSW_7_5_8_patch3/src/Bfinder/Bfinder/Dntuple/hist_pp_5_6_TMVA_latest.root");
TFile *f = new TFile("/home/xiao147/private/newchannel_lambda_CtoproduceDntuple/CMSSW_7_5_8_patch3/src/Bfinder/Bfinder/Dntuple/hist_pp_10_20_TMVA_latest_whole.root");
//TFile *f = new TFile("/home/xiao147/private/newchannel_lambda_CtoproduceDntuple/CMSSW_7_5_8_patch3/src/Bfinder/Bfinder/Dntuple/hist_pp_5_6_TMVA.root");

//TFile *f = new TFile("/home/xiao147/private/newchannel_lambda_CtoproduceDntuple/CMSSW_7_5_8_patch3/src/Bfinder/Bfinder/Dntuple/hist_PbPb_10_20_TMVA.root");
TH1F *h1 = (TH1F*) f->Get("h1");
//h1->Rebin(2);
//h1->SetAxisRange(2.2,2.4);
h1->Draw("E");
h1->SetMarkerColor(2);
h1->SetMarkerStyle(20);
h1->SetMarkerSize(1.5);
TCanvas *c1 = new TCanvas("c1","c1");
//gStyle->SetTitleX(0.9);
gStyle->SetOptTitle(0);
gStyle->SetOptStat(0);
gStyle->SetOptFit(0);
gStyle->SetTitleX(0.8f); //title box x position
gStyle->SetTitleY(0.95);
gStyle->SetTitleW(0.2f);  //Title box width as fraction of pad size.
gStyle->SetTitleFontSize(0.06);


h1->SetTitle("5.02TeV PP");
h1->GetXaxis()->CenterTitle();
h1->GetYaxis()->CenterTitle();
h1->GetXaxis()->SetTitleOffset(1.0);
h1->GetYaxis()->SetTitleOffset(1.2);
h1->GetXaxis()->SetLabelOffset(0.007);
h1->GetYaxis()->SetLabelOffset(0.007);
h1->GetXaxis()->SetTitleSize(0.045);
h1->GetYaxis()->SetTitleSize(0.045);
h1->GetXaxis()->SetTitleFont(42);
h1->GetYaxis()->SetTitleFont(42);
h1->GetXaxis()->SetLabelFont(42);
h1->GetYaxis()->SetLabelFont(42);
h1->GetXaxis()->SetLabelSize(0.04);
h1->GetYaxis()->SetLabelSize(0.04);


h1->GetXaxis()->SetTitle("m_{pk#pi} (GeV/c^{2})");
h1->GetYaxis()->SetTitle("Entries");

//The following is the TLatex method which is copied from Jian.
/*TLatex* tex;
tex = new TLatex(0.30,0.73,"P_{T}>10GeV");
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.04);
tex->SetLineWidth(2);
tex->Draw();

tex = new TLatex(0.20,0.83,"|y| < 1.0");
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.04);
tex->SetLineWidth(2);
tex->Draw();
*/
/*
tex = new TLatex(0.20,0.78,"centrality:30%-100%");
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.04);
tex->SetLineWidth(2);
tex->Draw();

TLatex Tl;
Tl.SetNDC();
Tl.SetTextAlign(12);
Tl.SetTextSize(0.05);
Tl.SetTextFont(42);
Tl.DrawLatex(0.18,0.965, "#font[61]{CMS}");
Tl.DrawLatex(0.61,0.965, "#scale[0.8]{PbPb #sqrt{s_{NN}} = 5.02 TeV}");
*/
//after here would do fit.
Double_t c=h1->GetBinWidth(1);
TF1 *f1=new TF1("f1","pol2",2.1,2.45);
TF1 *f2=new TF1("f2","0.007*[0]*([3]*TMath::Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[3])*TMath::Gaus(x,[1],[4])/(sqrt(2*3.14159)*[4]))",2.1,2.45);
TF1 *f3=new TF1("f3","0.007*[0]*([3]*TMath::Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[3])*TMath::Gaus(x,[1],[4])/(sqrt(2*3.14159)*[4]))+pol2(5)",2.1,2.45);
f3->SetParNames("Strength","Mean1","Sigma1","pro1","Sigma2","back1","back2","back3");
Double_t par[8];
//f3->SetParameter(0,2500); //6-8 pp 2 gaus
f3->SetParameter(0,1000);//10-20 pp 2 gaus
//f3->SetParameter(0,1500);//5-6 pp 2 gaus, 8-10 pp 2 gaus
/////this is for pp 10-20 half bin width

f3->SetParameter(1,2.288681);//mean1 10-20 pp 2 gaus 
//f3->SetParameter(2,0.02);//5-6
f3->FixParameter(2,7.300065e-03);//sigma1 10-20 pp 2 gaus
f3->FixParameter(3,8.458758e-01);//pro1 10-20 pp 2 gaus
f3->FixParameter(4,1.797897e-02);//mean2 10-20 pp 2 gaus

/*
//////this is for pp 8-10 half bin width 
f3->SetParameter(1,2.288362); //mean 8-10 pp 2 gaus
f3->FixParameter(2,4.055313e-03); // sigma1 8-10 pp 2 gaus
f3->FixParameter(3,2.683585e-01);// pro1 8-10 pp 2 gaus
f3->FixParameter(4,9.120214e-03);// sigma2 8-10 pp 2 gaus
*/

/*
///////this is for pp 6-8 with half bin width
f3->SetParameter(1, 2.288170);// mean1 6-8 pp 2 gaus
f3->FixParameter(2,7.379493e-03);//sigma1 6-8 pp 2 gaus
f3->FixParameter(3,8.522202e-01); //pro1 6-8 pp 2 gaus
f3->FixParameter(4,2.103316e-02);//sigma2 6-8 pp 2 gaus
*/
/*
//////this is for pp 5-6 with half bin width
f3->SetParameter(1,2.288915);
f3->FixParameter(2,2.868967e-03);
f3->FixParameter(3,1.668856e-01);
f3->FixParameter(4,8.988361e-03);
*/


//f3->SetParameter(3,-145930);
//f3->SetParameter(4,133024);
//f3->SetParameter(5,-28960);
//h1->Fit("f3","","",2.27,2.30);
//h1->Fit("f3","","",2.25,2.32); //6-8 pp old cut
//h1->Fit("f3","","",2.174,2.3414); //6-8 pp old cut and the latest.
//h1->Fit("f3","","",2.15,2.39); //8-10  pp old cut and the latest.
//h1->Fit("f3","","",2.2,2.34); //10-20 pp old cut


h1->Fit("f3","","",2.25,2.313); // 10-20 pp 2 gaus 1 step
h1->Fit("f3","","",2.23,2.36);//10-20 pp 2 gaus 2 step
h1->Fit("f3","","",2.22,2.36);//10-20 pp 2 gaus 3 step
h1->Fit("f3","","",2.2,2.37);//10-20 pp 2 gaus 4 step
h1->Fit("f3","","",2.2,2.4);//10-20 pp 2 gaus 5 step 
//h1->Fit("f3","","",2.2,2.41);
/*
h1->Fit("f3","","",2.23,2.305);// 6-8 pp 2 gaus 1 step
h1->Fit("f3","","",2.23,2.31);//6-8 pp 2 gaus 2 step
h1->Fit("f3","","",2.23,2.37);//6-8 pp 2 gaus 3 step
h1->Fit("f3","","",2.2,2.4);//6-8 pp 2 gaus 4 step
*/
/*
h1->Fit("f3","","",2.24,2.3);//5-6 pp 2 gaus 1 step
h1->Fit("f3","","",2.24,2.33);//5-6 pp 2 gaus 2 step
h1->Fit("f3","","",2.22,2.35);//5-6 pp 2 gaus 3 step
h1->Fit("f3","","",2.2,2.4);//5-6 pp 2 gaus 4 step
h1->Fit("f3","","",2.2,2.4);// 5-6 pp 2 gaus 5 step
*/
/*
h1->Fit("f3","","",2.25,2.3);//8-10 pp 2 gaus 1 step
h1->Fit("f3","","",2.25,2.34);//8-10 pp 2 gaus 2 step
h1->Fit("f3","","",2.23,2.34);//8-10 pp 2 gaus 3 step
h1->Fit("f3","","",2.2,2.4);//8-10 pp 2 gaus 4 step
h1->Fit("f3","","",2.2,2.4);//8-10 pp 2 gaus 5 step
h1->Fit("f3","","",2.2,2.4);//8-10 pp 2 gaus 6 step
*/

//h1->Fit("f3","","",2.185,2.34); //10-20 pp TMVA cut.and the latest.
//h1->Fit("f3","","",2.185,2.34); //10-20 pp newTMVA cut.
//h1->Fit("f3","","",2.244,2.32); //10-20 pp latestTMVA cut.
//h1->Fit("f3","","",2.216,2.402); //8-10 pp TMVA cut.
//h1->Fit("f3","","",2.15,2.41); //8-10 pp newTMVA cut.
//h1->Fit("f3","","",2.22,2.4);//5-6 pp TMVA cut.1018-------------
//h1->Fit("f3","","",2.19,2.34);//5-6 pp new TMVA cut.-----
//h1->Fit("f3","","",2.18,2.323); 
//h1->Fit("f3","","",2.18,2.32);
f3->GetParameters(par);
f2->SetParameters(&par[0]);
f1->SetParameters(&par[5]);
//f2->SetLineColor(2);
f1->SetLineColor(3);
//h1->SetMinimum(0);
h1->SetAxisRange(2.2,2.4);
//h1->SetAxisRange(2.18,2.42);
f1->Draw("same");
f2->Draw("same");
f3->Draw("same");
//Double_t a=f2->Integral(2.1,2.45);
//Double_t c=h1->GetBinWidth(1);
//Double_t b=a/c;

TLatex* tex;
tex = new TLatex(0.20,0.73,"10GeV<P_{T}<20GeV");
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.04);
tex->SetLineWidth(2);
tex->Draw();

//tex = new TLatex(0.2,0.78,"Number:1.09192e+03, error:2.61407e+02");
//tex->SetNDC();
//tex->SetTextFont(42);
//tex->SetTextSize(0.04);
//tex->SetLineWidth(2);
//tex->Draw();


tex = new TLatex(0.20,0.78,"|y| < 1.0");
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.04);
tex->SetLineWidth(2);
tex->Draw();

TLatex Tl;
Tl.SetNDC();
Tl.SetTextAlign(12);
Tl.SetTextSize(0.05);
Tl.SetTextFont(42);
Tl.DrawLatex(0.18,0.965, "#font[61]{CMS}");
Tl.DrawLatex(0.61,0.965, "#scale[0.8]{pp #sqrt{s_{NN}} = 5.02 TeV}");
/*
c1->SaveAs("5_6_pplatestTMVA_whole_2gaus_pol2.gif");
//h1->Write();
//output->Close();

TFile* result = new TFile("5_6_pp_TMVAcuts_2gaus_pol2.root", "RECREATE");
h1->Write();
f1->Write();
//f2->Write();
f3->Write();
result->Close();
*/
}
