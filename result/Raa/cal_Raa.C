#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TCut.h>
//now this is ready to do the dN/dpt.
/*
void divideBinWidth(TH1* h)
{
	for(int i=1;i<=h->GetNbinsX();i++)
	{
		Float_t contentvalue=h->GetBinContent(i);
		Float_t content_err=h->GetBinError(i);
		contentvalue/=h->GetBinWidth(i);
		content_err/=h->GetBinWidth(i);
		h->SetBinContent(i,contentvalue);
		h->SetBinError(i,content_err);
	}
}
*/
void cal_Raa(){
    TFile *f1 = TFile::Open("crosssection.root"); 
    TH1F *h_crosssection = (TH1F*) f1->Get("h_crosssection");
	TFile *f2 = TFile::Open("differential_yield.root");
	TH1F *h_yield = (TH1F*) f2->Get("h_yield");
	TCanvas *c1 = new TCanvas("c1","c1");
	double Taa=1.405/1000;  //i did not add the error, I do not know how to deal with the error.
   	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
    //h_crosssection->Scale(1000000);
	h_crosssection->Sumw2();
	TH1F *h_Raa = (TH1F*) h_yield->Clone("h_Raa");
	h_Raa->Divide(h_crosssection);
	//the error I am not sure. 
    h_Raa->Scale(1./(Taa));
	h_Raa->Sumw2();
	h_Raa->SetMarkerSize(1.5);
	h_Raa->SetMarkerStyle(20);
	h_Raa->SetMarkerColor(2);
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
    h_Raa->SetLineColor(2);
    h_Raa->Draw("e");
	c1->SaveAs("Raa.gif");	
	TFile * result = new TFile("Raa.root","RECREATE");
	h_Raa->Write();
	result->Close();

}
