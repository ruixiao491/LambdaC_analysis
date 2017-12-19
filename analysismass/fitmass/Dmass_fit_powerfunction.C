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
//this is actually the right fit for PbPb 2015 lambdaC with the plo4 background.
void Dmass_fit_powerfunction(){
TFile *f =new TFile("/home/xiao147/private/newchannel_lambda_CtoproduceDntuple/CMSSW_7_5_8_patch3/src/Bfinder/Bfinder/Dntuple/Dntuple_firstcuttry.root");
//TFile *f =new TFile("/home/xiao147/lambdaC/outputfile_sunjiancuts.root");
TH1F *h1 = (TH1F*) f->Get("hmass");
h1->Draw("E");
h1->SetMarkerColor(2);
h1->SetMarkerStyle(24);
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
TF1 *f2=new TF1("f2","gaus",2.1,2.45);
TF1 *f3=new TF1("f3","gaus+pol4(3)",2.1,2.45);
//TF1 *f1=new TF1("f1","gaus",2.1,2.45);
//TF1 *f2=new TF1("f2","gaus",2.1,2.45);
//TF1 *f3=new TF1("f3","gaus(0)+gaus(3)",2.1,2.45);

f3->SetParNames("Strength","Mean","Sigma","back1","back2","back3","back4","back5");
Double_t par[8];
f3->SetParameter(0,485);
f3->SetParameter(1,2.286);
f3->SetParameter(2,0.006);

h1->Fit("f3","","",2.1528,2.44);//This line is used for wei's cut and Jian's cut with PV refit
//h1->Fit("f3","","",2.104,2.45);//This line is used fot Jian's cut with PV refit.
//h1->Fit("f3","","",2.17,2.35);
f3->GetParameters(par);
f2->SetParameters(&par[0]);
f1->SetParameters(&par[3]);
f2->SetLineColor(3);
f1->SetLineColor(4);
//f3->SetLineColor(5);
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
h1->GetYaxis()->SetTitle("entries");
//pt = new TPaveText(0.10,0.7,0.3,0.9,"NDC");
//pt->SetFillColor(0);
//pt->SetTextSize(0.04);
//pt->SetTextAlign(12);
//text = pt->AddText("CMS #Lambda_{C} + #bar#Lambda_{C}");
//pt->Draw();

////The following is the TLatex method which is copied from Jian.
TLatex* tex;
tex = new TLatex(0.20,0.73,"P_{T}>10GeV");
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

}
