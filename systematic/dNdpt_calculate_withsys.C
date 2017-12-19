#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TCut.h>
#include <TGraphErrors.h>
//now this is ready to do the dN/dpt.
void dNdpt_calculate_withsys(){
    TFile *f1 = TFile::Open("crosssection.root"); 
	TFile *f2 = TFile::Open("sys_crosssection.root");
	TH1F *h_crosssection = (TH1F*) f1->Get("h_crosssection");
	TH1F *hsys_sum = (TH1F *)f2->Get("hsys_sum");
	TCanvas *c1 = new TCanvas("c1");
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
/*
	hsys_sum->SetBinError(1,0);
	hsys_sum->SetBinError(2,0);
	hsys_sum->SetBinError(3,0);
	hsys_sum->SetBinError(4,0);
	TGraphErrors *crosssection_errorsys = new TGraphErrors(hsys_sum);
	for(int ibin = 0; ibin<crosssection_errorsys->GetN();ibin++)
	{
		crosssection_errorsys->GetEX()[ibin]=0.5;
		crosssection_errorsys->GetEYlow()[ibin]=0;
		

	crosssection_errorsys->SetMarkerColor(kRed+1);
	crosssection_errorsys->SetMarkerStyle(20);
	crosssection_errorsys->SetLineWidth(0);
	crosssection_errorsys->SetFillStyle(0);
	crosssection_errorsys->SetLineColor(kRed+1);
	crosssection_errorsys->Draw("2");
	hsys_sum->Draw("same");
*/	
	//crosssection_errorsys->SetFillColor(15);
	//crosssection_errorsys->Draw("A2");

	h_crosssection->SetMarkerStyle(20);
	h_crosssection->SetFillColor(15);
	h_crosssection->Draw();
	h_crosssection->GetXaxis()->CenterTitle();
	h_crosssection->GetYaxis()->CenterTitle();
	h_crosssection->GetXaxis()->SetTitleOffset(1.0);
	h_crosssection->GetYaxis()->SetTitleOffset(1.0);
	h_crosssection->GetXaxis()->SetLabelOffset(0.007);
	h_crosssection->GetYaxis()->SetLabelOffset(0.007);
	h_crosssection->GetXaxis()->SetTitleSize(0.045);
	h_crosssection->GetYaxis()->SetTitleSize(0.045);
	h_crosssection->GetXaxis()->SetTitleFont(42);
	h_crosssection->GetYaxis()->SetTitleFont(42);
	h_crosssection->GetXaxis()->SetLabelFont(42);
	h_crosssection->GetYaxis()->SetLabelFont(42);
	h_crosssection->GetXaxis()->SetLabelSize(0.04);
	h_crosssection->GetYaxis()->SetLabelSize(0.04);
	h_crosssection->GetXaxis()->SetTitle("P_{T} (GeV/c)");
	h_crosssection->GetYaxis()->SetTitle("d#sigma/dP_{T} (#mub GeV^{-1}c, |y_{#Lambda_{C}}|<1)");

/*	
	crosssection_errorsys->SetMarkerColor(kRed+1);
	crosssection_errorsys->SetMarkerStyle(20);
	crosssection_errorsys->SetLineWidth(0);
	crosssection_errorsys->SetFillStyle(0);
	crosssection_errorsys->SetLineColor(kRed+1);
	crosssection_errorsys->Draw("2");
	hsys_sum->Draw("same");
*/

	double x[4]={5.5, 7, 9, 15};
	double py[4]={h_crosssection->GetBinContent(1), h_crosssection->GetBinContent(2), h_crosssection->GetBinContent(3), h_crosssection->GetBinContent(4)};
	double zero[4] ={0.5,1,1,5};
	double ey_stat[4]={h_crosssection->GetBinError(1), h_crosssection->GetBinError(2), h_crosssection->GetBinError(3), h_crosssection->GetBinError(4)};
	double ey_sys[4]={hsys_sum->GetBinContent(1)/100*h_crosssection->GetBinContent(1), hsys_sum->GetBinContent(2)/100*h_crosssection->GetBinContent(2), hsys_sum->GetBinContent(3)/100*h_crosssection->GetBinContent(3), hsys_sum->GetBinError(4)/100*h_crosssection->GetBinContent(4)};

//	TFile * result = new TFile("crosssection_withsys.root","RECREATE");
//	h_crosssection->Write();
//	result->Close();
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
	graph1_sys->GetYaxis()->SetTitle("d#sigma/dP_{T} (#mub GeV^{-1}c, |y_{#Lambda_{C}}|<1)");
    c1->SetLogy();
	graph1_sys->Draw("a2");
	graph1->SetMarkerStyle(20);
	graph1->SetMarkerColor(2);
	graph1->Draw("psame");
	c1->SaveAs("crosssection_withsys.gif");
}
