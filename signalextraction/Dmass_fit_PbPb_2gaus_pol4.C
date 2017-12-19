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
#include <TFile.h>
#include <TH1F.h>
//this is actually the right fit for PbPb 2015 lambdaC with the plo4 background.
void Dmass_fit_PbPb_2gaus_pol4(){
TFile * f = new TFile("hist_PbPb_10_20_TMVA_latest.root");
//TFile *f = new TFile("hist_PbPb_10_20_TMVA.root");
//TFile *f = new TFile("hist_PbPb_10_20_TMVA_anothercut.root");
//TFile *f = new TFile("hist_PbPb_20_50_TMVA_anothercut.root");
//TFile *f = new TFile("hist_PbPb_8_10_TMVA_newest2.root");
//TFile *f = new TFile("hist_PbPb_8_10_TMVA_newest1012.root");
//TFile *f = new TFile("hist_pp_5_6_TMVA_latest_whole.root");
//TFile *f =new TFile("/home/xiao147/private/newchannel_lambda_CtoproduceDntuple/CMSSW_7_5_8_patch3/src/Bfinder/Bfinder/Dntuple/Dntuple_firstcuttry.root");
//TFile *f =new TFile("/home/xiao147/lambdaC/outputfile_sunjiancuts.root");
//TH1F *h1 = (TH1F*) f->Get("hmass"); //for firstcuttry and sunjiancuts.root
TH1F *h1 = (TH1F*) f -> Get("h1");
//h1->Rebin(2);
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

//here I want to use pol2 to try the background.
TF1 *f1=new TF1("f1","pol4",2.1,2.45);
TF1 *f2=new TF1("f2","0.007*[0]*([3]*TMath::Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[3])*TMath::Gaus(x,[1],[4])/(sqrt(2*3.14159)*[4]))",2.1,2.45);
//TF1 *f3=new TF1("f3","0.007*[0]*TMath::Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+pol4(3)",2.1,2.45);
TF1 *f3=new TF1("f3","0.007*[0]*([3]*TMath::Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[3])*TMath::Gaus(x,[1],[4])/(sqrt(2*3.14159)*[4]))+pol4(5)",2.1,2.45);
//TF1 *f1=new TF1("f1","gaus",2.1,2.45);
//TF1 *f2=new TF1("f2","gaus",2.1,2.45);
//TF1 *f3=new TF1("f3","gaus(0)+gaus(3)",2.1,2.45);

f3->SetParNames("Strength","Mean","Sigma1","pro","Sigma2","back1","back2","back3","back4","back5");
Double_t par[10];
/*
//The following is for PbPb 8-10
f3->SetParameter(0,1500);
f3->SetParameter(1,2.287098);
f3->FixParameter(2,7.434553e-03);
f3->FixParameter(3,8.778714e-01);
f3->SetParameter(4,2.305937);
f3->FixParameter(5,1.924537e-02);
*/
////The following is for PbPb 10-20-----the new half bin width.
f3->SetParameter(0,2000);
f3->SetParameter(1,2.288897);
f3->FixParameter(2,6.999098e-03);
f3->FixParameter(3,8.341185e-01);
f3->FixParameter(4,1.327229e-02);



//h1->Fit("f3","","",2.24,2.3);
//h1->Fit("f3","","",2.27,2.34);//8-10 latest.1012---realpol3

//h1->Fit("f3","","",2.265,2.318);//8-10 pol4 -step1
//h1->Fit("f3","","",2.2,2.4);//8-10 pol4 -step2

h1->Fit("f3","","",2.23,2.303);//10-20 pol4-step 1
h1->Fit("f3","","",2.2,2.35);//10-20 pol4-step 2
h1->Fit("f3","","",2.104,2.45);//10-20 pol4-step 3
//h1->Fit("f3","","",2.104,2.45); // this is the new old cuts.
//h1->Fit("f3","","",2.183,2.4);//this is for old cuts.
//h1->Fit("f3","","",2.1528,2.44);//---This line is used for wei's cut and Jian's cut with PV refit
//h1->Fit("f3","","",2.104,2.45);//This line is used fot Jian's cut with PV refit.
//h1->Fit("f3","","",2.17,2.35);
f3->GetParameters(par);
//f2->SetParameters(&par[0]);
f1->SetParameters(&par[5]);
//f2->SetLineColor(2);
f1->SetLineColor(3);
//f3->SetLineColor(5);

f2->SetParameter(0,par[0]);
f2->SetParameter(1,par[1]);
f2->SetParameter(2,par[2]);
f2->SetParameter(3,par[3]);
f2->SetParameter(4,par[4]);
f2->SetParameter(5,par[5]);
//h1->SetMinimum(0);
h1->SetAxisRange(2.2,2.4);
h1->Draw("e");
//h1->Integral(2.1,2.45);
f1->Draw("same");
f2->Draw("same");
f3->Draw("same");
//Double_t a=f2->Integral(2.1,2.45);
//Double_t c=h1->GetBinWidth(1);
//Double_t b=a/c;
//cout<<"number"<<b<<endl;
//h1->SetTitle(Form("nlambdaC%ewithoutPVrefitJiancut",b));
h1->SetTitle("5.02TeV PbPb");
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
//pt = new TPaveText(0.10,0.7,0.3,0.9,"NDC");
//pt->SetFillColor(0);
//pt->SetTextSize(0.04);
//pt->SetTextAlign(12);
//text = pt->AddText("CMS #Lambda_{C} + #bar#Lambda_{C}");
//pt->Draw();

////The following is the TLatex method which is copied from Jian.
TLatex* tex;
tex = new TLatex(0.20,0.73,"10GeV<P_{T}<20GeV");
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

c1->SaveAs("TMVA_10_20_PbPb_newest_1002_2guas_pol4_1mean.gif");
TFile* result = new TFile("10_20_PbPb_TMVAcuts_2gaus_pol4_1mean.root", "RECREATE");
h1->Write();
f1->Write();
f3->Write();
result->Close();

}
