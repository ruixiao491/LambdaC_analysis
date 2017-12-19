#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TCut.h>
//now this is ready to do the reconstruction efficiency.
void ptshape_2recoeffi_ratio(){
	TFile *f1 = TFile::Open("recoeffi_weighted_PbPbcuts_ptspectra_withTMVAcuts_updown.root"); 
	TFile *f2 = TFile::Open("recoeffi_weighted_PbPbcuts_ptspectra_withTMVAcuts_downup.root");
	TFile *f3 = TFile::Open("recoeffi_weighted_PbPbcuts_4ptbins_withTMVAcuts.root");
	TH1F *h_updown = (TH1F*)f1->Get("hrecoeffi_weighted");
	TH1F *h_downup = (TH1F*)f2->Get("hrecoeffi_weighted");
	TH1F *h_centr = (TH1F*)f3->Get("hrecoeffi_weighted");
	TCanvas *c1 = new TCanvas("c1","c1");
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	h_updown->Add(h_centr,-1);
	h_downup->Add(h_centr,-1);
	TH1F *ratio = (TH1F*)h_updown->Clone("ratio");
	ratio->Sumw2();
	ratio->Divide(h_downup);
	h_downup->SetLineColor(2);
	h_downup->SetMarkerStyle(20);
	h_downup->SetMarkerSize(1);
	h_downup->SetMarkerColor(2);
	h_updown->SetMarkerColor(9);
	h_updown->SetMarkerSize(1);
	h_updown->SetMarkerStyle(20);
	h_updown->SetLineColor(9);
	h_updown->Divide(h_centr);
	h_downup->Divide(h_centr);
	h_downup->Draw("e");
	h_updown->Draw("esame");
cout<<"1 ="<<h_updown->GetBinContent(1)<<" 2 = "<<h_updown->GetBinContent(2)<<" 3 = "<<h_updown->GetBinContent(3)<<" 4 ="<<h_updown->GetBinContent(4)<<endl;
cout<<"1 ="<<h_downup->GetBinContent(1)<<" 2 = "<<h_downup->GetBinContent(2)<<" 3 = "<<h_downup->GetBinContent(3)<<" 4="<<h_downup->GetBinContent(4)<<endl;
	//ratio->Draw("e");
	c1->SaveAs("h_ptshape_sigma.gif");
	TFile *result = new TFile("recoeffi_ratio_ptshape.root","RECREATE");
	ratio->Write();
	h_downup->Write();
	h_downup->Write();
	result->Close();
}
