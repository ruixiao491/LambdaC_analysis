#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TCut.h>
#include <TGraphErrors.h>
//now this is ready to do the dN/dpt.
void diffential_yield_withsys(){
    TFile *f1 = TFile::Open("differential_yield.root"); 
	TFile *f2 = TFile::Open("sys_differ_yield.root");
	TH1F *h_yield = (TH1F*) f1->Get("h_yield");
	TH1F *hsys_sum = (TH1F *)f2->Get("hsys_sum");
	TCanvas *c1 = new TCanvas("c1");
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	double x[2]={ 9, 15};
	double py[2]={h_yield->GetBinContent(3), h_yield->GetBinContent(4)};
	double zero[2] ={1,5};
	double ey_stat[2]={h_yield->GetBinError(3), h_yield->GetBinError(4)};
	double ey_sys[2]={0,hsys_sum->GetBinContent(4)/100*h_yield->GetBinContent(4)};

//	TFile * result = new TFile("crosssection_withsys.root","RECREATE");
//	h_yield->Write();
//	result->Close();
	h_yield->SetMarkerSize(1.5);
	h_yield->SetMarkerStyle(20);
	h_yield->SetMarkerColor(2);
	h_yield->GetXaxis()->CenterTitle();
	h_yield->GetYaxis()->CenterTitle();
	h_yield->GetXaxis()->SetTitleOffset(1.0);
	h_yield->GetYaxis()->SetTitleOffset(1.0);
	h_yield->GetXaxis()->SetLabelOffset(0.007);
	h_yield->GetYaxis()->SetLabelOffset(0.007);
	h_yield->GetXaxis()->SetTitleSize(0.045);
	h_yield->GetYaxis()->SetTitleSize(0.045);
	h_yield->GetXaxis()->SetTitleFont(42);
	h_yield->GetYaxis()->SetTitleFont(42);
	h_yield->GetXaxis()->SetLabelFont(42);
	h_yield->GetYaxis()->SetLabelFont(42);
	h_yield->GetXaxis()->SetLabelSize(0.04);
	h_yield->GetYaxis()->SetLabelSize(0.04);
	h_yield->GetXaxis()->SetTitle("P_{T} (GeV/c)");
	h_yield->GetYaxis()->SetTitle("dN/dP_{T} (GeV^{-1}c, |y_{#Lambda_{C}}|<1)");
    h_yield->SetLineColor(2);
	h_yield->Draw("e");
	c1->SetLogy();
	TGraphErrors *graph1 = new TGraphErrors(2,x,py,zero,ey_stat);
	TGraphErrors *graph1_sys = new TGraphErrors(2,x,py,zero,ey_sys);
	graph1_sys->GetXaxis()->CenterTitle();
	graph1_sys->GetYaxis()->CenterTitle();
	graph1_sys->GetXaxis()->SetTitleOffset(1.0);
	graph1_sys->GetYaxis()->SetTitleOffset(1.0);
	graph1_sys->GetXaxis()->SetLabelOffset(0.007);
	graph1_sys->GetYaxis()->SetLabelOffset(0.007);
	graph1_sys->GetXaxis()->SetTitleSize(0.045);
	graph1_sys->GetYaxis()->SetTitleSize(0.045);
	graph1_sys->GetXaxis()->SetTitleFont(42);
	graph1_sys->GetYaxis()->SetTitleFont(42);
	graph1_sys->GetXaxis()->SetLabelFont(42);
	graph1_sys->GetYaxis()->SetLabelFont(42);
	graph1_sys->GetXaxis()->SetLabelSize(0.04);
	graph1_sys->GetYaxis()->SetLabelSize(0.04);
	graph1_sys->GetXaxis()->SetTitle("P_{T} (GeV/c)");
	graph1_sys->GetYaxis()->SetTitle("dN/dP_{T} (GeV^{-1}c, |y_{#Lambda_{C}}|<1)");
	graph1_sys->SetMarkerColor(3);
	graph1_sys->SetMarkerStyle(20);
	graph1_sys->SetLineWidth(0);
	graph1_sys->SetFillStyle(1001);
	graph1_sys->SetLineColor(3);
	graph1_sys->SetFillColor(3);
	graph1_sys->Draw("2same");
	graph1->SetMarkerStyle(20);
	graph1->SetMarkerColor(2);
	graph1->SetMarkerSize(1.5);
	graph1->SetLineColor(2);
	graph1->Draw("psame");
	c1->SaveAs("diff_yield_withsys.gif");
}
