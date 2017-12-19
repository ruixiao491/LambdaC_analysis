#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TCut.h>
//now this is for the sys uncer for pp cross section.Till now have not fill the hmassfit_sys and hcuteffi_sys.
void sys_crosssection(){
	//TFile *f1 = TFile::Open("");  
	//TH1* hptspectra_sys = (TH1*)f1->Get("");
    double ppTrackingEfficiency = 11;////here I have not get the value of this variable.
	double ppLumiUncertainty = 2.3; ///I have not get this value.//just copy the value from Hao.
	double BR_Uncertainty =5.2 ; //I have not get this value.
	const Int_t NBINS = 4;
	Double_t edges[NBINS + 1]={5,6,8,10,20};
	TH1 *hmassfit_sys = new TH1D("hmassfit_sys","Dmass_sys",NBINS,edges);
	TH1 *hcuteffi_sys = new TH1D("hcuteffi_sys","cuteffi_sys",NBINS,edges);
	TH1 *hptspectra_sys = new TH1D("hptspectra_sys","pt_shape",NBINS,edges);
	TCanvas *c1 = new TCanvas("c1","c1");
	double sys_sum =0;
	sys_sum+=ppLumiUncertainty*ppLumiUncertainty;
	sys_sum+=BR_Uncertainty*BR_Uncertainty;
	sys_sum+=ppTrackingEfficiency*ppTrackingEfficiency;
	hmassfit_sys->SetBinContent(1,1.4);
	hmassfit_sys->SetBinContent(2,7.9);
	hmassfit_sys->SetBinContent(3,4.8);
	hmassfit_sys->SetBinContent(4,1.8);

	hcuteffi_sys->SetBinContent(1,10.5);
	hcuteffi_sys->SetBinContent(2,17.3);
	hcuteffi_sys->SetBinContent(3,10.7);
	hcuteffi_sys->SetBinContent(4,5.2);

	hptspectra_sys->SetBinContent(1,1.3);
	hptspectra_sys->SetBinContent(2,1.3);
	hptspectra_sys->SetBinContent(3,0.7);
	hptspectra_sys->SetBinContent(4,0.8);

	//below should be pt bin to pt bin.
    for(int i =1; i<= NBINS; i++)
	{
		Float_t contentvalue=hmassfit_sys->GetBinContent(i)*hmassfit_sys->GetBinContent(i);
		hmassfit_sys->SetBinContent(i,contentvalue);
	}
    for(int i =1; i<=NBINS; i++)
	{
		Float_t content=hcuteffi_sys->GetBinContent(i)*hcuteffi_sys->GetBinContent(i);
		hcuteffi_sys->SetBinContent(i,content);
	}

	for(int i = 1; i<=NBINS; i++)
	{
		Float_t content=hptspectra_sys->GetBinContent(i)*hptspectra_sys->GetBinContent(i);
		hptspectra_sys->SetBinContent(i,content);
	}
    TH1F *hsys_sum = (TH1F*) hmassfit_sys->Clone("hsys_sum");
	hsys_sum->Sumw2();
	hsys_sum->Add(hcuteffi_sys);
	hsys_sum->Add(hptspectra_sys);
	for(int i =1; i<=NBINS; i++)
	{
		Float_t cont=sqrt(hsys_sum->GetBinContent(i)+sys_sum);
		
		hsys_sum->SetBinContent(i,cont);
	}
////here I did not take the track efficiency into account.	
	hsys_sum->Draw();
	TFile *result = new TFile("sys_crosssection.root","RECREATE");
	hsys_sum->Write();
	result->Close();
}
