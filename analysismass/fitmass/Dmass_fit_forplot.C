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
void Dmass_fit_forplot(){
TFile *f =new TFile("/scratch/halstead/x/xiao147/pkpichanneltuple.root");
TNtuple *nt =(TNtuple *) f->Get("nt");
TH1F *h1 = new TH1F("h1","mass",50,2.1,2.45);
//TFile * output = new TFile("histogramsave.root","RECREATE");
float mass[MAX_XB];
float pt[MAX_XB];
float dls[MAX_XB];
float chi2[MAX_XB];
float alpha[MAX_XB];
float Dtrk1Pt[MAX_XB];
float Dtrk1Phi[MAX_XB];
float Dtrk1Dxy[MAX_XB];
float Dtrk1Y[MAX_XB];
float Dtrk2Pt[MAX_XB];
float Dtrk2Phi[MAX_XB];
float Dtrk2Dxy[MAX_XB];
float Dtrk2Y[MAX_XB];
float Dtrk3Pt[MAX_XB];
float Dtrk3Phi[MAX_XB];
float   Dtrk3Dxy[MAX_XB];
float   Dtrk3Y[MAX_XB];

nt->SetBranchAddress("mass",mass);
nt->SetBranchAddress("pt",pt);
nt->SetBranchAddress("dls",dls);
nt->SetBranchAddress("chi2",chi2);
nt->SetBranchAddress("alpha",alpha);
nt->SetBranchAddress("Dtrk1Pt", Dtrk1Pt);
nt->SetBranchAddress("Dtrk1Phi", Dtrk1Phi);
nt->SetBranchAddress("Dtrk1Dxy", Dtrk1Dxy);
nt->SetBranchAddress("Dtrk1Y", Dtrk1Y);
nt->SetBranchAddress("Dtrk2Pt", Dtrk2Pt);
nt->SetBranchAddress("Dtrk2Phi", Dtrk2Phi);
nt->SetBranchAddress("Dtrk2Dxy", Dtrk2Dxy);
nt->SetBranchAddress("Dtrk2Y", Dtrk2Y);
nt->SetBranchAddress("Dtrk3Pt", Dtrk3Pt);
nt->SetBranchAddress("Dtrk3Phi", Dtrk3Phi);
nt->SetBranchAddress("Dtrk3Dxy", Dtrk3Dxy);
nt->SetBranchAddress("Dtrk3Y", Dtrk3Y);

//nt->Draw("mass>>h1","dls>2 && pt>8&&chi2>0.1&&abs(Dtrk1Y)<1.2&&abs(Dtrk2Y)<1.2&&abs(Dtrk3Y)<1.2&&alpha<0.08&&mass>2.1&&mass<2.45", "e");

//nt->Project("h1","mass","dls>2 && pt>8&&chi2>0.1&&abs(Dtrk1Y)<1.2&&abs(Dtrk2Y)<1.2&&abs(Dtrk3Y)<1.2&&alpha<0.08&&mass>2.1&&mass<2.45");

//h1->SetTitle(Form("nlambdaC%ewithoutPVrefitJiancut",b));
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

//The following is the TLatex method which is copied from Jian.
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

//tex = new TLatex(0.20,0.78,"centrality:30%-100%");
//tex->SetNDC();
//tex->SetTextFont(42);
//tex->SetTextSize(0.04);
//tex->SetLineWidth(2);
//tex->Draw();

TLatex Tl;
Tl.SetNDC();
Tl.SetTextAlign(12);
Tl.SetTextSize(0.05);
Tl.SetTextFont(42);
Tl.DrawLatex(0.18,0.965, "#font[61]{CMS}");
Tl.DrawLatex(0.61,0.965, "#scale[0.8]{PbPb #sqrt{s_{NN}} = 5.02 TeV}");

nt->Draw("mass>>h1","dls>2&& pt>6&&chi2>0.1&&abs(Dtrk1Y)<1.2&&abs(Dtrk2Y)<1.2&&abs(Dtrk3Y)<1.2&&alpha<0.12&&mass>2.1&&mass<2.45", "e");
//after here would do fit.
Double_t c=h1->GetBinWidth(1);
TF1 *f1=new TF1("f1","pol2",2.1,2.45);
TF1 *f2=new TF1("f2","gaus",2.1,2.45);
TF1 *f3=new TF1("f3","0.007*[0]*TMath::Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+pol2(3)",2.1,2.45);
f3->SetParNames("Strength","Mean","Sigma","back1","back2","back3");
Double_t par[6];
f3->SetParameter(0,3500);
f3->SetParameter(1,2.286);
f3->SetParameter(2,0.007);
//f3->SetParameter(3,-145930);
//f3->SetParameter(4,133024);
//f3->SetParameter(5,-28960);
h1->Fit("f3","","",2.2,2.3);
//h1->Fit("f3","","",2.243,2.39);
f3->GetParameters(par);
f2->SetParameters(&par[0]);
f1->SetParameters(&par[3]);
f2->SetLineColor(3);
f1->SetLineColor(4);
f1->Draw("same");
f2->Draw("same");
f3->Draw("same");
//Double_t a=f2->Integral(2.1,2.45);
//Double_t c=h1->GetBinWidth(1);
//Double_t b=a/c;

//h1->Write();
//output->Close();

TFile* result = new TFile("result.root", "RECREATE");
h1->Write();
f1->Write();
f2->Write();
f3->Write();
result->Close();

}
