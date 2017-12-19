#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TCut.h>
#include <TGraphErrors.h>
//now this is ready to do the dN/dpt.
void Raa_withsys(){
    TFile *f1 = TFile::Open("Raa.root"); 
	TFile *f2 = TFile::Open("sys_crosssection.root");
	TH1F *h_Raa = (TH1F*) f1->Get("h_Raa");
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

	h_Raa->SetMarkerStyle(20);
	h_Raa->SetFillColor(15);
	h_Raa->Draw();
	h_Raa->GetXaxis()->CenterTitle();
	h_Raa->GetYaxis()->CenterTitle();
	h_Raa->GetXaxis()->SetTitleOffset(1.0);
	h_Raa->GetYaxis()->SetTitleOffset(1.0);
	h_Raa->GetXaxis()->SetLabelOffset(0.007);
	h_Raa->GetYaxis()->SetLabelOffset(0.007);
	h_Raa->GetXaxis()->SetTitleSize(0.045);
	h_Raa->GetYaxis()->SetTitleSize(0.045);
	h_Raa->GetXaxis()->SetTitleFont(42);
	h_Raa->GetYaxis()->SetTitleFont(42);
	h_Raa->GetXaxis()->SetLabelFont(42);
	h_Raa->GetYaxis()->SetLabelFont(42);
	h_Raa->GetXaxis()->SetLabelSize(0.04);
	h_Raa->GetYaxis()->SetLabelSize(0.04);
	h_Raa->GetXaxis()->SetTitle("P_{T} (GeV/c)");
	h_Raa->GetYaxis()->SetTitle("R_{AA}");

/*	
	crosssection_errorsys->SetMarkerColor(kRed+1);
	crosssection_errorsys->SetMarkerStyle(20);
	crosssection_errorsys->SetLineWidth(0);
	crosssection_errorsys->SetFillStyle(0);
	crosssection_errorsys->SetLineColor(kRed+1);
	crosssection_errorsys->Draw("2");
	hsys_sum->Draw("same");
*/

	double x[2]={9, 15};
	double py[2]={h_Raa->GetBinContent(3), h_Raa->GetBinContent(4)};
	double zero[2] ={1,5};
	double ey_stat[2]={h_Raa->GetBinError(3), h_Raa->GetBinError(4)};
	double ey_sys[2]={0, hsys_sum->GetBinContent(4)/100*h_Raa->GetBinContent(4)};

//	TFile * result = new TFile("crosssection_withsys.root","RECREATE");
//	h_Raa->Write();
//	result->Close();
	TGraphErrors *graph1 = new TGraphErrors(2,x,py,zero,ey_stat);
	TGraphErrors *graph1_sys = new TGraphErrors(2,x,py,zero,ey_sys);
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
	graph1_sys->GetYaxis()->SetTitle("R_{AA}");
	graph1_sys->Draw("2same");
	graph1->SetMarkerStyle(20);
	graph1->SetMarkerColor(2);
	graph1->SetLineColor(2);
	graph1->Draw("psame");
	c1->SaveAs("Raa_withsys.gif");
}
