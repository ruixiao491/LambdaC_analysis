#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TCut.h>
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
void ptshapeinoneplot(){
	TFile *f1 = TFile::Open("ptspectrum_updown.root"); 
	TFile *f2 = TFile::Open("ptspectrum_downup.root");
	TFile *f3 = TFile::Open("ptspectrum_centra.root");
	
	TFile *f_pkpi = TFile::Open("root://xrootd.rcac.purdue.edu//store/user/rxiao/datafromscratchhammer/MC_lambdaCpkpi/MC_pt5_withcuts_Dntuple/pkpi_pt5_Dntuple_withcuts.root");
	TTree *ntGen_pkpi = (TTree *)f_pkpi->Get("ntGen");
	TCanvas *c1 = new TCanvas("c1","c1");
	const Int_t NBINS = 4;
	Double_t edges[NBINS + 1]={5,6,8,10,20};
	TH1 *hGpt_pkpi = new TH1D("hGpt_pkpi","Gpt",NBINS,edges);
	hGpt_pkpi->Sumw2();

	TH1F *h_updown = (TH1F*)f1->Get("h_crosssection");
	TH1F *h_downup = (TH1F*)f2->Get("h_crosssection");
	TH1F *h_centr = (TH1F*)f3->Get("h_crosssection");
	TF1 *f_updown = (TF1*) f1->Get("f1");
	TF1 *f_downup = (TF1*) f2->Get("f1");
	TF1 *f_cen = (TF1*) f3->Get("f1");
    TCut *MC_cut = new TCut("fabs(Gy)<1&&abs(GpdgId)==4122&&(GisSignal==15||GisSignal==16)");
	ntGen_pkpi->Project("hGpt_pkpi","Gpt",*MC_cut);
    divideBinWidth(hGpt_pkpi);
	double scale=h_centr->Integral()/hGpt_pkpi->Integral();
	hGpt_pkpi->Scale(scale);

	h_updown->SetLineColor(2);
	h_downup->SetLineColor(3);
	h_centr->SetLineColor(9);
	h_updown->SetMarkerColor(2);
	h_downup->SetMarkerColor(3);
	h_centr->SetMarkerColor(9);
	f_updown->SetLineColor(2);
	f_downup->SetLineColor(3);
	f_cen->SetLineColor(9);
	hGpt_pkpi->SetLineColor(7);
	hGpt_pkpi->SetMarkerSize(1.5);
	hGpt_pkpi->SetMarkerColor(7);
	hGpt_pkpi->SetMarkerStyle(20);
	hGpt_pkpi->Draw();
	f_updown->Draw("same");
	f_downup->Draw("same");
	f_cen->Draw("same");

	TFile *result = new TFile("ptshapeinoneplots.root","RECREATE");
	hGpt_pkpi->Write();
	f_updown->Write();
	f_downup->Write();
	f_cen->Write();
	result->Close();

}
