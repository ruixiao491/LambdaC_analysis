#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <TH2D.h>
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
#include <TLegend.h>
void combine_ppPbPb_weightedrecoeff(){
//TFile *f1=new TFile("recoeffi_weighted.root");
//TFile *f2=new TFile("recoeffi_weighted_PbPbcuts.root");
TFile *f1 = new TFile("recoeffi_weighted_ppcuts_4ptbins_withTMVAcuts.root");
TFile *f2 = new TFile("recoeffi_weighted_PbPbcuts_4ptbins_withTMVAcuts_pt5MC.root");

TH1F *h1 = (TH1F*) f1->Get("hrecoeffi_weighted");
TH1F *h2 = (TH1F*) f2->Get("hrecoeffi_weighted");

TCanvas *c1 = new TCanvas("c1","c1");
gStyle->SetOptTitle(0);
gStyle->SetOptStat(0);

h1->GetXaxis()->CenterTitle();
h1->GetYaxis()->CenterTitle();
h1->GetXaxis()->SetTitleOffset(1.0);
h1->GetYaxis()->SetTitleOffset(1.0);
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
h1->GetXaxis()->SetTitle("P_{T} (GeV)");
h1->GetYaxis()->SetTitle("accp#times eff(reco)");
h1->SetAxisRange(0,1,"Y");
h1->Draw("E");
h1->SetMarkerColor(2);
h1->SetMarkerStyle(20);
h1->SetMarkerSize(1.5);
h1->SetLineColor(2);
h2->SetAxisRange(0,1,"Y");
h2->Draw("esame");
h2->SetMarkerColor(3);
h2->SetMarkerStyle(20);
h2->SetMarkerSize(1.5);
h2->SetLineColor(3);

leg = new TLegend(0.1,0.7,0.3,0.9);
//leg->SetHeader("#Lambda_{C}/D^{0}");
leg->AddEntry(h1,"PP","lep");
leg->AddEntry(h2,"PbPb","lep");
leg->Draw();
c1->SaveAs("combine_ppPbPb_weighted_recoeffi.gif");
}
