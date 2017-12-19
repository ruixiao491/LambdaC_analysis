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
void diffential_yield(){
    //TFile *f1 = TFile::Open("recoeffi_weighted_PbPbcuts.root");
	TFile *f1 = TFile::Open("recoeffi_weighted_PbPbcuts_4ptbins_withTMVAcuts.root");
	//TFile *f1 = TFile::Open("recoeffi_weighted.root"); 
	TH1F *hrecoeffi_weighted = (TH1F*) f1->Get("hrecoeffi_weighted");
 	
 	double N_evt=254828627  ;//this is not accurate.
	double BR=0.0635;
	
	const Int_t NBINS = 4;
	Double_t edges[NBINS + 1]={5,6,8,10,20};
	TH1 *hDpt = new TH1D("hDpt","Dpt",NBINS,edges);
	//hDpt->SetBinContent(1,1777.4);
	hDpt->SetBinContent(3,889.102);
	hDpt->SetBinContent(4,1606.3);
	//hDpt->SetBinError(1,328.209);
	hDpt->SetBinError(3,223.53);
	hDpt->SetBinError(4,385.993);
	TCanvas *c1 = new TCanvas("c1","c1");
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	divideBinWidth(hDpt);
    //hDpt->Draw("e");

	TH1F *h_yield = (TH1F*) hDpt->Clone("h_yield");
	h_yield->Sumw2();
	h_yield->Divide(hrecoeffi_weighted);   //the error I am not sure. 
    
    h_yield->Scale(1./(2*N_evt*BR));
	h_yield->Sumw2();
	gPad->SetLogy();
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
	c1->SaveAs("yield.gif");	
	TFile * result = new TFile("differential_yield.root","RECREATE");
	h_yield->Write();
	result->Close();

}
