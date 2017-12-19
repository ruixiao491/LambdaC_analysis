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
void fit_forsignal_singlegaus(){
//TFile *f =new TFile("hist_pp_10_20.root");
TFile *f = new TFile("Normalized_Dmass_pp_10_20.root");
TH1F *h_whole_withcuts_sig = (TH1F*) f->Get("h_whole_withcuts_sig");
h_whole_withcuts_sig->Rebin(2);
h_whole_withcuts_sig->Draw("E");
h_whole_withcuts_sig->SetMarkerColor(2);
h_whole_withcuts_sig->SetMarkerStyle(20);
h_whole_withcuts_sig->SetMarkerSize(1.5);
TCanvas *c1 = new TCanvas("c1","c1");
//gStyle->SetTitleX(0.9);
gStyle->SetOptTitle(0);
gStyle->SetOptStat(0);
gStyle->SetOptFit(1);
gStyle->SetTitleX(0.8f); //title box x position
gStyle->SetTitleY(0.95);
gStyle->SetTitleW(0.2f);  //Title box width as fraction of pad size.
gStyle->SetTitleFontSize(0.06);


h_whole_withcuts_sig->SetTitle("5.02TeV PP");
h_whole_withcuts_sig->GetXaxis()->CenterTitle();
h_whole_withcuts_sig->GetYaxis()->CenterTitle();
h_whole_withcuts_sig->GetXaxis()->SetTitleOffset(1.0);
h_whole_withcuts_sig->GetYaxis()->SetTitleOffset(1.2);
h_whole_withcuts_sig->GetXaxis()->SetLabelOffset(0.007);
h_whole_withcuts_sig->GetYaxis()->SetLabelOffset(0.007);
h_whole_withcuts_sig->GetXaxis()->SetTitleSize(0.045);
h_whole_withcuts_sig->GetYaxis()->SetTitleSize(0.045);
h_whole_withcuts_sig->GetXaxis()->SetTitleFont(42);
h_whole_withcuts_sig->GetYaxis()->SetTitleFont(42);
h_whole_withcuts_sig->GetXaxis()->SetLabelFont(42);
h_whole_withcuts_sig->GetYaxis()->SetLabelFont(42);
h_whole_withcuts_sig->GetXaxis()->SetLabelSize(0.04);
h_whole_withcuts_sig->GetYaxis()->SetLabelSize(0.04);


h_whole_withcuts_sig->GetXaxis()->SetTitle("m_{pk#pi} (GeV/c^{2})");
h_whole_withcuts_sig->GetYaxis()->SetTitle("Entries");

//after here would do fit.
Double_t c=h_whole_withcuts_sig->GetBinWidth(1);
//TF1 *f1=new TF1("f1","gaus",2.1,2.45);
//TF1 *f2=new TF1("f2","gaus",2.1,2.45);
TF1 *f3=new TF1("f3","0.007*[0]*TMath::Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])",2.1,2.45);
f3->SetParNames("Strength1","mean","sigma1");
Double_t par[3];
//f3->SetParameter(0,3500); //6-20 the latest10,8,6
f3->SetParameter(1,2.286);
f3->SetParameter(2,0.007);

//f3->SetParameter(3,-145930);
//f3->SetParameter(4,133024);
//f3->SetParameter(5,-28960);
//h_whole_withcuts_sig->Fit("f3","","",2.27,2.30);
//h_whole_withcuts_sig->Fit("f3","","",2.175,2.328); //6-8 pp old cut and the latest.MC
//h_whole_withcuts_sig->Fit("f3","","",2.16,2.40); //8-10  pp old cut and the latest.MC
h_whole_withcuts_sig->Fit("f3","","",2.25,2.32); //10-20 pp latestTMVA cut.MC
//h_whole_withcuts_sig->Fit("f3","","",2.23,2.32);//5-6 pp new TMVA cut. MC
//h_whole_withcuts_sig->Fit("f3","","",2.18,2.323); //PbPb 10-20 MC. 
//h_whole_withcuts_sig->Fit("f3","","",2.18,2.32); //PbPb 8-10 MC.
f3->GetParameters(par);
//f2->SetParameters(&par[3]);
//f1->SetParameters(&par[0]);
//f1->SetParameter(0,par[0]);
//f1->SetParameter(1,par[1]);
//f1->SetParameter(2,par[2]);

//f2->SetParameter(0,par[3]);
//f2->SetParameter(1,par[1]);
//f2->SetParameter(0,par[4]);

//f2->SetLineColor(2);
//f1->SetLineColor(3);
//h_whole_withcuts_sig->SetAxisRange(2.15,2.43);
//h_whole_withcuts_sig->SetAxisRange(2.18,2.42);
//f1->Draw("same");
//f2->Draw("same");
f3->Draw("same");
//Double_t a=f2->Integral(2.1,2.45);
//Double_t c=h_whole_withcuts_sig->GetBinWidth(1);
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
//c1->SaveAs("10_20_PbPblatestTMVAcuts_MC_singlegaus.gif");
//h_whole_withcuts_sig->Write();
//output->Close();
/*
TFile* result = new TFile("10_20PbPb_singalgaus.root", "RECREATE");
h_whole_withcuts_sig->Write();
//f1->Write();
//f2->Write();
f3->Write();
result->Close();
*/
}
