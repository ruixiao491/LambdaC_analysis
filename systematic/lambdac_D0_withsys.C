#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TCut.h>
#include <TGraphErrors.h>
//now this is ready to do the dN/dpt.
void lambdac_D0_withsys(){
    /////pp///
	//TFile *f1 = TFile::Open("ratio_pp.root"); 
	//TFile *f2 = TFile::Open("ratio_lambdaCD0_withsys.root");
	///PbPb/////
	TFile *f1 = TFile::Open("ratio_PbPb.root");
	TFile *f2 = TFile::Open("ratio_lambdaCD0_withsys_PbPb.root");
	//TH1F *h_ratio_pp = (TH1F*) f1->Get("h_crosssection");///for pp
	TH1F *h_ratio_pp = (TH1F*) f1->Get("h_yield");//for PbPb
	TH1F *hsys_sum = (TH1F *)f2->Get("hsys_sum");
	TCanvas *c1 = new TCanvas("c1");
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	h_ratio_pp->SetMarkerStyle(20);
	h_ratio_pp->SetFillColor(15);
	h_ratio_pp->Draw();
	h_ratio_pp->GetXaxis()->CenterTitle();
	h_ratio_pp->GetYaxis()->CenterTitle();
	h_ratio_pp->GetXaxis()->SetTitleOffset(1.0);
	h_ratio_pp->GetYaxis()->SetTitleOffset(1.0);
	h_ratio_pp->GetXaxis()->SetLabelOffset(0.007);
	h_ratio_pp->GetYaxis()->SetLabelOffset(0.007);
	h_ratio_pp->GetXaxis()->SetTitleSize(0.045);
	h_ratio_pp->GetYaxis()->SetTitleSize(0.045);
	h_ratio_pp->GetXaxis()->SetTitleFont(42);
	h_ratio_pp->GetYaxis()->SetTitleFont(42);
	h_ratio_pp->GetXaxis()->SetLabelFont(42);
	h_ratio_pp->GetYaxis()->SetLabelFont(42);
	h_ratio_pp->GetXaxis()->SetLabelSize(0.04);
	h_ratio_pp->GetYaxis()->SetLabelSize(0.04);
	h_ratio_pp->GetXaxis()->SetTitle("P_{T} (GeV/c)");
	h_ratio_pp->GetYaxis()->SetTitle("#Lambda_{C}^{+} / D^{0} (|y_{#Lambda_{C}}|<1)");

    double x[4]={5.5,7,9,15};
	double py[4]={h_ratio_pp->GetBinContent(1), h_ratio_pp->GetBinContent(2), h_ratio_pp->GetBinContent(3), h_ratio_pp->GetBinContent(4)};
	double zero[4] ={0.5,1,1,5};
	double ey_stat[4]={h_ratio_pp->GetBinError(1), h_ratio_pp->GetBinError(2), h_ratio_pp->GetBinError(3), h_ratio_pp->GetBinError(4)};
	double ey_sys[4]={hsys_sum->GetBinContent(1)/100*h_ratio_pp->GetBinContent(1),hsys_sum->GetBinContent(2)/100*h_ratio_pp->GetBinContent(2), hsys_sum->GetBinContent(3)/100*h_ratio_pp->GetBinContent(3), hsys_sum->GetBinContent(4)/100*h_ratio_pp->GetBinContent(4)};

	TGraphErrors *graph1 = new TGraphErrors(4,x,py,zero,ey_stat);
	TGraphErrors *graph1_sys = new TGraphErrors(4,x,py,zero,ey_sys);
	graph1_sys->SetMarkerColor(7);
	graph1_sys->SetMarkerStyle(20);
	graph1_sys->SetLineWidth(0);
	graph1_sys->SetFillStyle(1001);
	graph1_sys->SetLineColor(7);
	graph1_sys->SetFillColor(7);
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
	graph1_sys->GetXaxis()->SetLabelFont(42);
	graph1_sys->GetXaxis()->SetLabelSize(0.04);
	graph1_sys->GetYaxis()->SetLabelSize(0.04);
	graph1_sys->GetXaxis()->SetTitle("P_{T} (GeV/c)");
	graph1_sys->GetYaxis()->SetTitle("#Lambda_{C}^{+} / D^{0} (|y_{#Lambda_{C}}|<1)");
	graph1_sys->Draw("2same");
	graph1->SetMarkerStyle(20);
	graph1->SetMarkerColor(2);
	graph1->Draw("psame");
	//c1->SaveAs("ratio_lambdac_D0_withsys.gif");
    c1->SaveAs("ratio_lambdac_D0_withsys_PbPb.gif");
}
