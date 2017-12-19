#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TCut.h>
//now this is ready to do the dN/dpt.
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
void dNdpt_calculate(){
    TFile *f1 = TFile::Open("recoeffi_weighted_ppcuts_4ptbins_withTMVAcuts.root"); 
	TH1F *hrecoeffi_weighted = (TH1F*) f1->Get("hrecoeffi_weighted");
 	double lumi=0.0361; //for 2015 pp.
	double BR=0.0635;
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	const Int_t NBINS = 4;
	Double_t edges[NBINS + 1]={5,6,8,10,20};
	TH1 *hDpt = new TH1D("hDpt","Dpt",NBINS,edges);
	hDpt->SetBinContent(1,1370.67);
	hDpt->SetBinContent(2,2166.85);
	hDpt->SetBinContent(3,1306.83);
	hDpt->SetBinContent(4,994.824);
	hDpt->SetBinError(1,319.425);
	hDpt->SetBinError(2,402.928);
	hDpt->SetBinError(3,267.275);
	hDpt->SetBinError(4,249.643);
	TCanvas *c1 = new TCanvas("c1","c1");

	divideBinWidth(hDpt);
    //hDpt->Draw("e");

	TH1F *h_crosssection = (TH1F*) hDpt->Clone("h_crosssection");
	h_crosssection->Divide(hrecoeffi_weighted);   //the error I am not sure. 
    h_crosssection->Scale(1./(2*lumi*BR));
	h_crosssection->Sumw2();
	h_crosssection->Scale(1./1000000); //this is for unit change.
	h_crosssection->Sumw2();
	gPad->SetLogy();
	h_crosssection->SetMarkerSize(1.5);
	h_crosssection->SetMarkerStyle(20);
	h_crosssection->SetMarkerColor(2);
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
	h_crosssection->SetLineColor(2);
    h_crosssection->Draw("e");
	c1->SaveAs("crosssection.gif");
	TFile * result = new TFile("crosssection.root","RECREATE");
	h_crosssection->Write();
	result->Close();

}
