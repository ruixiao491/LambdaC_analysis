#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TCut.h>
//now this is ready to do the dN/dpt.
void cal_relativeerr(TH1* h)
{
	for(int i=1;i<=h->GetNbinsX();i++)
	{
		Float_t contentvalue=h->GetBinContent(i);
		Float_t content_err=h->GetBinError(i);
		contentvalue=content_err/contentvalue;
		h->SetBinContent(i,contentvalue);
		
	}
}
void relative_err_recoeffi(){
//TFile *f1= TFile::Open("recoeffi_weighted.root");
TFile *f1 = TFile::Open("recoeffi_weighted_PbPbcuts_3ptbins.root"); 
	TH1F *hrecoeffi_weighted = (TH1F*) f1->Get("hrecoeffi_weighted");
	TCanvas *c1 = new TCanvas("c1","c1");
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	cal_relativeerr(hrecoeffi_weighted);
	hrecoeffi_weighted->Sumw2();
    //gPad->SetLogy();
    hrecoeffi_weighted->SetMarkerSize(1.5);
	hrecoeffi_weighted->SetMarkerStyle(20);
	hrecoeffi_weighted->SetMarkerColor(2);
	hrecoeffi_weighted->GetXaxis()->CenterTitle();
	hrecoeffi_weighted->GetYaxis()->CenterTitle();
	hrecoeffi_weighted->GetXaxis()->SetTitleOffset(1.0);
	hrecoeffi_weighted->GetYaxis()->SetTitleOffset(1.0);
	hrecoeffi_weighted->GetXaxis()->SetLabelOffset(0.007);
	hrecoeffi_weighted->GetYaxis()->SetLabelOffset(0.007);
	hrecoeffi_weighted->GetXaxis()->SetTitleSize(0.045);
	hrecoeffi_weighted->GetYaxis()->SetTitleSize(0.045);
	hrecoeffi_weighted->GetXaxis()->SetTitleFont(42);
	hrecoeffi_weighted->GetYaxis()->SetTitleFont(42);
	hrecoeffi_weighted->GetXaxis()->SetLabelFont(42);
	hrecoeffi_weighted->GetYaxis()->SetLabelFont(42);
	hrecoeffi_weighted->GetXaxis()->SetLabelSize(0.04);
	hrecoeffi_weighted->GetYaxis()->SetLabelSize(0.04);
	hrecoeffi_weighted->GetXaxis()->SetTitle("P_{T} (GeV/c)");
	hrecoeffi_weighted->GetYaxis()->SetTitle("relative uncertainty of eff");
	hrecoeffi_weighted->SetLineColor(2);


	hrecoeffi_weighted->Draw("e");
    	
	
	
	
	
//	c1->SaveAs("relativeerr_recoeffi.gif");
//	TFile * result = new TFile("relativeerr_recoeffi.root","RECREATE");
//	hrecoeffi_weighted->Write();
//	result->Close();

}
