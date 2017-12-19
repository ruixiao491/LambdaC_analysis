#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TCut.h>
//now this is for the sys uncer for pp cross section.Till now have not fill the hmassfit_sys_lambdaC and hcuteffi_sys_lambdaC.
void sys_lambdac_D0_pp(){
	//TFile *f1 = TFile::Open("");  
	//TH1* hptspectra_sys_lambdaC = (TH1*)f1->Get("");
    double ppTrackingEfficiency_lambdaC = 11;////here I have not get the value of this variable.
	double ppTrackingEfficiency_D0 = 8;
	double BR_Uncertainty_lambdaC =5.2 ; //I have not get this value.
	double BR_Uncertainty_D0 =1.3;
	const Int_t NBINS = 4;
	Double_t edges[NBINS + 1]={5,6,8,10,20};
	TH1 *hmassfit_sys_lambdaC = new TH1D("hmassfit_sys_lambdaC","LambdaC_mass_sys",NBINS,edges);
	TH1 *hcuteffi_sys_lambdaC = new TH1D("hcuteffi_sys_lambdaC","cuteffi_sys_lambdaC",NBINS,edges);
	TH1 *hptspectra_sys_lambdaC = new TH1D("hptspectra_sys_lambdaC","pt_shape_lambdaC",NBINS,edges);
	TH1 *hmassfit_sys_D0 = new TH1D("hmassfit_sys_D0","D0mass",NBINS,edges);
	TH1 *hcuteffi_sys_D0 = new TH1D("hcuteffi_sys_D0","cuteffi_sys_D0",NBINS,edges);
	TH1 *hptspectra_sys_D0 = new TH1D("hptspectra_sys_D0","pt_shape_D0",NBINS,edges);
	TCanvas *c1 = new TCanvas("c1","c1");
	double sys_sum =0;
	sys_sum+=BR_Uncertainty_lambdaC*BR_Uncertainty_lambdaC+BR_Uncertainty_D0*BR_Uncertainty_D0;
	trackefficiency=ppTrackingEfficiency_lambdaC*ppTrackingEfficiency_lambdaC+ppTrackingEfficiency_D0*ppTrackingEfficiency_D0-2*ppTrackingEfficiency_lambdaC*ppTrackingEfficiency_D0;
	cout<<"trackefficiency"<<trackefficiency<<endl;
	sys_sum+=trackefficiency*trackefficiency;
	hmassfit_sys_lambdaC->SetBinContent(1,1.4);
	hmassfit_sys_lambdaC->SetBinContent(2,7.9);
	hmassfit_sys_lambdaC->SetBinContent(3,4.8);
	hmassfit_sys_lambdaC->SetBinContent(4,1.8);

	hcuteffi_sys_lambdaC->SetBinContent(1,10.5);
	hcuteffi_sys_lambdaC->SetBinContent(2,17.3);
	hcuteffi_sys_lambdaC->SetBinContent(3,10.7);
	hcuteffi_sys_lambdaC->SetBinContent(4,5.2);

	hptspectra_sys_lambdaC->SetBinContent(1,1.3);
	hptspectra_sys_lambdaC->SetBinContent(2,1.3);
	hptspectra_sys_lambdaC->SetBinContent(3,0.7);
	hptspectra_sys_lambdaC->SetBinContent(4,0.8);

	hmassfit_sys_D0->SetBinContent(1,3);
	hmassfit_sys_D0->SetBinContent(2,3);
	hmassfit_sys_D0->SetBinContent(3,1.7);
	hmassfit_sys_D0->SetBinContent(4,4);

	hptspectra_sys_D0->SetBinContent(1,2);
	hptspectra_sys_D0->SetBinContent(2,1);
	hptspectra_sys_D0->SetBinContent(3,1);
	hptspectra_sys_D0->SetBinContent(4,1);

	hcuteffi_sys_D0->SetBinContent(1,3.6);
	hcuteffi_sys_D0->SetBinContent(2,3.6);
	hcuteffi_sys_D0->SetBinContent(3,3.6);
	hcuteffi_sys_D0->SetBinContent(4,3.6);

	//below should be pt bin to pt bin.
    for(int i =1; i<= NBINS; i++)
	{
		Float_t contentvalue=hmassfit_sys_lambdaC->GetBinContent(i)*hmassfit_sys_lambdaC->GetBinContent(i);
		hmassfit_sys_lambdaC->SetBinContent(i,contentvalue);
		Float_t contentvalue2=hmassfit_sys_D0->GetBinContent(i)*hmassfit_sys_D0->GetBinContent(i);
		hmassfit_sys_D0->SetBinContent(i,contentvalue2);
	}
    for(int i =1; i<=NBINS; i++)
	{
		Float_t content=hcuteffi_sys_lambdaC->GetBinContent(i)*hcuteffi_sys_lambdaC->GetBinContent(i);
		hcuteffi_sys_lambdaC->SetBinContent(i,content);
		Float_t content2=hcuteffi_sys_D0->GetBinContent(i)*hcuteffi_sys_D0->GetBinContent(i);
		hcuteffi_sys_D0->SetBinContent(i,content2);
	}

	for(int i = 1; i<=NBINS; i++)
	{
		Float_t content=hptspectra_sys_lambdaC->GetBinContent(i)*hptspectra_sys_lambdaC->GetBinContent(i);
		hptspectra_sys_lambdaC->SetBinContent(i,content);
	    Float_t content2=hptspectra_sys_D0->GetBinContent(i)*hptspectra_sys_D0->GetBinContent(i);
		hptspectra_sys_D0->SetBinContent(i,content2);
	}

    TH1F *hsys_sum = (TH1F*) hmassfit_sys_lambdaC->Clone("hsys_sum");
	hsys_sum->Sumw2();
	hsys_sum->Add(hcuteffi_sys_lambdaC);
	hsys_sum->Add(hptspectra_sys_lambdaC);
	hsys_sum->Add(hmassfit_sys_D0);
	hsys_sum->Add(hcuteffi_sys_D0);
	hsys_sum->Add(hptspectra_sys_D0);
	for(int i =1; i<=NBINS; i++)
	{
		Float_t cont=sqrt(hsys_sum->GetBinContent(i)+sys_sum);
		
		hsys_sum->SetBinContent(i,cont);
	}
////here I did not take the track efficiency into account.	
	hsys_sum->Draw();
	TFile *result = new TFile("ratio_lambdaCD0_withsys.root","RECREATE");
	hsys_sum->Write();
	result->Close();
}
