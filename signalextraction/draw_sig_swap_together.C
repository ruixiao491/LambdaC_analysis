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
void draw_sig_swap_together(){
TFile *f1=new TFile("Normalized_Dmass_pp_5_6.root");
TH1F *h_signal = (TH1F*) f1->Get("h_whole_withcuts_sig");
TH1F *h_swapped = (TH1F*) f1->Get("h_whole_withcuts_swapped");
TCanvas *c1 = new TCanvas("c1","c1");
gStyle->SetOptTitle(0);
gStyle->SetOptStat(0);

h_signal->GetXaxis()->CenterTitle();
h_signal->GetYaxis()->CenterTitle();
h_signal->GetXaxis()->SetTitleOffset(1.0);
h_signal->GetYaxis()->SetTitleOffset(1.0);
h_signal->GetXaxis()->SetLabelOffset(0.007);
h_signal->GetYaxis()->SetLabelOffset(0.007);
h_signal->GetXaxis()->SetTitleSize(0.045);
h_signal->GetYaxis()->SetTitleSize(0.045);
h_signal->GetXaxis()->SetTitleFont(42);
h_signal->GetYaxis()->SetTitleFont(42);
h_signal->GetXaxis()->SetLabelFont(42);
h_signal->GetYaxis()->SetLabelFont(42);
h_signal->GetXaxis()->SetLabelSize(0.04);
h_signal->GetYaxis()->SetLabelSize(0.04);
h_signal->GetXaxis()->SetTitle("m_{pk#pi} (GeV/c^{2})");
h_signal->GetYaxis()->SetTitle("Entries");
h_signal->Draw("E");
h_signal->SetMarkerColor(2);
h_signal->SetMarkerStyle(20);
h_signal->SetMarkerSize(1.5);
h_signal->SetLineColor(2);
h_swapped->Draw("esame");
h_swapped->SetMarkerColor(9);
h_swapped->SetMarkerStyle(20);
h_swapped->SetMarkerSize(1.5);
h_swapped->SetLineColor(9);

TLatex* tex;
tex = new TLatex(0.20,0.83,"5GeV<P_{T}<6GeV");
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
Tl.DrawLatex(0.75,0.93, "#scale[0.8]{pp MC}");


leg = new TLegend(0.7,0.7,0.9,0.9);
leg->AddEntry(h_signal,"Gen-matched signal","lep");
leg->AddEntry(h_swapped,"swapped candidates","lep");
leg->Draw();
c1->SaveAs("draw_sig_swapped_together_pp_5_6.gif");
}
