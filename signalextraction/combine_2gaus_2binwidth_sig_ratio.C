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
void combine_2gaus_2binwidth_sig_ratio(){
TFile *f1=new TFile("halfbinwidth_fit_sig_ratio_pp.root");
//TFile *f2=new TFile("mybinwidth_fit_sig_ratio_pp.root");
TFile *f3=new TFile("singlegaus_fit_sig_ratio_pp.root");

TH1F *h_half = (TH1F*) f1->Get("hfit_sig_ratio");
//TH1F *h_my = (TH1F*) f2->Get("hfit_sig_ratio");
TH1F *h_single = (TH1F*) f3->Get("hfit_sig_ratio");
TCanvas *c1 = new TCanvas("c1","c1");
gStyle->SetOptTitle(0);
gStyle->SetOptStat(0);

h_half->GetXaxis()->CenterTitle();
h_half->GetYaxis()->CenterTitle();
h_half->GetXaxis()->SetTitleOffset(1.0);
h_half->GetYaxis()->SetTitleOffset(1.0);
h_half->GetXaxis()->SetLabelOffset(0.007);
h_half->GetYaxis()->SetLabelOffset(0.007);
h_half->GetXaxis()->SetTitleSize(0.045);
h_half->GetYaxis()->SetTitleSize(0.045);
h_half->GetXaxis()->SetTitleFont(42);
h_half->GetYaxis()->SetTitleFont(42);
h_half->GetXaxis()->SetLabelFont(42);
h_half->GetYaxis()->SetLabelFont(42);
h_half->GetXaxis()->SetLabelSize(0.04);
h_half->GetYaxis()->SetLabelSize(0.04);
h_half->GetXaxis()->SetTitle("P_{T} (GeV)");
h_half->GetYaxis()->SetTitle("ratio of fit signal and true signal");
h_half->SetAxisRange(0,1,"Y");
h_half->Draw("E");
h_half->SetMarkerColor(2);
h_half->SetMarkerStyle(20);
h_half->SetMarkerSize(1.5);
h_half->SetLineColor(2);
//h_my->SetAxisRange(0,1,"Y");
//h_my->Draw("esame");
//h_my->SetMarkerColor(3);
//h_my->SetMarkerStyle(20);
//h_my->SetMarkerSize(1.5);
//h_my->SetLineColor(3);
h_single->Draw("esame");
h_single->SetMarkerColor(9);
h_single->SetMarkerStyle(20);
h_single->SetMarkerSize(1.5);
h_single->SetLineColor(9);


leg = new TLegend(0.7,0.4,0.9,0.6);
leg->AddEntry(h_half,"half_bin_width","lep");
//leg->AddEntry(h_my,"bin_width","lep");
leg->AddEntry(h_single,"single_gaus","lep");
leg->Draw();
c1->SaveAs("combine_2binwidth_fit_sig_ratio.gif");
}
