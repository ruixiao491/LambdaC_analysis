#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TCut.h>
//now this is for the sys uncer for Raa.
void sys_Raa(){
    double ppTrackingEfficiency = 11;////here I have not get the value of this variable.
	double PbPbTrackingEfficiency = 14;
	double ppLumiUncertainty = 2.3; ///I have not get this value.//just copy the value from Hao.
	double PbPbNevents = 2;
	const Int_t NBINS = 4;
	Double_t edges[NBINS + 1]={5,6,8,10,20};
	TH1 *hmassfit_sys_pp = new TH1D("hmassfit_sys_pp","Dmass_sys_pp",NBINS,edges);
	TH1 *hcuteffi_sys_pp = new TH1D("hcuteffi_sys_pp","cuteffi_sys_pp",NBINS,edges);
	TH1 *hptspectra_sys_pp = new TH1D("hptspectra_sys_pp","pt_shape_pp",NBINS,edges);
	TH1 *hmassfit_sys_PbPb = new TH1D("hmassfit_sys_PbPb","Dmass_sys_PbPb",NBINS,edges);
	TH1 *hcuteffi_sys_PbPb = new TH1D("hcuteffi_sys_PbPb","cuteffi_sys_PbPb",NBINS,edges);
	TH1 *hptspectra_sys_PbPb = new TH1D("hptspectra_sys_PbPb","pt_shape_PbPb",NBINS,edges);
	TCanvas *c1 = new TCanvas("c1","c1");
	double sys_sum =0;
	sys_sum+=ppLumiUncertainty*ppLumiUncertainty;
	
	double trackefficiency = sqrt(ppTrackingEfficiency*ppTrackingEfficiency+PbPbTrackingEfficiency*PbPbTrackingEfficiency);
	cout<<"trackeffi"<<trackefficiency<<endl;
	sys_sum+=trackefficiency*trackefficiency;
	
	
	hmassfit_sys_pp->SetBinContent(1,1.4);
	hmassfit_sys_pp->SetBinContent(2,7.9);
	hmassfit_sys_pp->SetBinContent(3,4.8);
	hmassfit_sys_pp->SetBinContent(4,1.8);

	hcuteffi_sys_pp->SetBinContent(1,10.5);
	hcuteffi_sys_pp->SetBinContent(2,17.3);
	hcuteffi_sys_pp->SetBinContent(3,10.7);
	hcuteffi_sys_pp->SetBinContent(4,5.2);

	hptspectra_sys_pp->SetBinContent(1,1.3);
	hptspectra_sys_pp->SetBinContent(2,1.3);
	hptspectra_sys_pp->SetBinContent(3,0.7);
	hptspectra_sys_pp->SetBinContent(4,0.8);

	hmassfit_sys_PbPb->SetBinContent(4,1.7);
	hcuteffi_sys_PbPb->SetBinContent(4,6);
	hptspectra_sys_PbPb->SetBinContent(4,5);


	//below should be pt bin to pt bin.
    for(int i =1; i<= NBINS; i++)
	{
		Float_t contentvalue=hmassfit_sys_pp->GetBinContent(i)*hmassfit_sys_pp->GetBinContent(i);
		hmassfit_sys_pp->SetBinContent(i,contentvalue);
		Float_t contentvalue2=hmassfit_sys_PbPb->GetBinContent(i)*hmassfit_sys_PbPb->GetBinContent(i);
		hmassfit_sys_PbPb->SetBinContent(i,contentvalue2);
	}
    for(int i =1; i<=NBINS; i++)
	{
		Float_t content=hcuteffi_sys_pp->GetBinContent(i)*hcuteffi_sys_pp->GetBinContent(i);
		hcuteffi_sys_pp->SetBinContent(i,content);
		Float_t content2=hcuteffi_sys_PbPb->GetBinContent(i)*hcuteffi_sys_PbPb->GetBinContent(i);
		hcuteffi_sys_PbPb->SetBinContent(i,content2);
	}

	for(int i = 1; i<=NBINS; i++)
	{
		Float_t content=hptspectra_sys_pp->GetBinContent(i)*hptspectra_sys_pp->GetBinContent(i);
		hptspectra_sys_pp->SetBinContent(i,content);
		Float_t content_2=hptspectra_sys_PbPb->GetBinContent(i)*hptspectra_sys_PbPb->GetBinContent(i);
		hptspectra_sys_PbPb->SetBinContent(i,content_2);
	}
    TH1F *hsys_sum = (TH1F*) hmassfit_sys_pp->Clone("hsys_sum");
	hsys_sum->Sumw2();
	hsys_sum->Add(hcuteffi_sys_pp);
	hsys_sum->Add(hptspectra_sys_pp);
	hsys_sum->Add(hmassfit_sys_PbPb);
	hsys_sum->Add(hcuteffi_sys_PbPb);
	hsys_sum->Add(hptspectra_sys_PbPb);
	for(int i =1; i<=NBINS; i++)
	{
		Float_t cont=sqrt(hsys_sum->GetBinContent(i)+sys_sum);
		
		hsys_sum->SetBinContent(i,cont);
	}
	hsys_sum->Draw();
	TFile *result = new TFile("sys_Raa.root","RECREATE");
	hsys_sum->Write();
	result->Close();
}
