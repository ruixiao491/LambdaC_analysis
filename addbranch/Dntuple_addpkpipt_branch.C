#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <TH2D.h>
#include <TMath.h>
#include <TF1.h>
#include <TNamed.h>
#include <TNtuple.h>
#include <TTree.h>
#include <TMath.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TLatex.h>
#include <TLorentzVector.h>
#define MAX_XB       20000
#define KAON_MASS   0.493677
#define PION_MASS   0.13957018
#define PROTON_MASS 0.9383

using namespace std;
//string particlebranch[700]={"kaon_pt","pion_pt","proton_pt"};
int findPdgid(Double_t tkmass)
{ 
	if(TMath::Abs(tkmass-KAON_MASS)<0.1) return 0;//KAON_PDGID;
	else if(TMath::Abs(tkmass-PION_MASS)<0.1) return 1;//PION_PDGID;
	else if(TMath::Abs(tkmass-PROTON_MASS)<0.1) return 2;//PROTON_PDGID;
	else
	{   
		cout<<"ERROR: find particle pdgid falied >> Particle mass: "<<tkmass<<endl;
		return 0;
	}

}





void Dntuple_addpkpipt_branch()
{
	//TFile * f1 = TFile::Open("/scratch/halstead/x/xiao147/PbPb2015_lambdaC_pt8_makeup_hammer/whole_adddaughterbranch/MB5_7_lambdaC_2015_PbPb_makeup_whole.root","update");
	//TFile * f1 = TFile::Open("/scratch/halstead/x/xiao147/official_MC/pt_4_MC_Dntuple/MC_weight_forTMVA/weight_MC_official_adddaguhterbranch/weight_MC_whole_official_MC_TMVA.root","update");
	//TFile * f1 = TFile::Open("/scratch/halstead/x/xiao147/official_MC/pt_10/pt_10_PbPb_Dntuple/addbranch/lambdaC_pkpi_PbPb_pt10_Dntuple_whole.root","update");
	//TFile * f1 = TFile::Open("/scratch/halstead/x/xiao147/PbPb2015_lambdaC_pt8_makeup_hammer/whole/MB5_lambda_C_2015_PbPb_makeup_hammer_2skim_whole.root","update");
	//TFile * f1 = TFile::Open("/scratch/halstead/x/xiao147/whole_2015_PbPb_goldernjson_trackingonly_lambdaC_pkpi/whole_addbranch/trackingonly/MB2_trackingonly_whole.root","update");
	TFile * f1 = TFile::Open("/scratch/halstead/x/xiao147/whole_2015_PbPb_goldernjson_trackingonly_lambdaC_pkpi/whole_addbranch/goldernjson/MB4_goldernjson_whole.root","update");
	TTree *ntlambdaCtopkpi = (TTree*)f1->Get("ntlambdaCtopkpi");
	Int_t Dsize;
	float   Dtrk1Pt[MAX_XB];
	float   Dtrk2Pt[MAX_XB];
	float   Dtrk3Pt[MAX_XB];
	float   Dtk1mass_Dfindersave[MAX_XB];
	float   Dtk2mass_Dfindersave[MAX_XB];
	float   Dtk3mass_Dfindersave[MAX_XB];

	ntlambdaCtopkpi->SetBranchAddress("Dsize",&Dsize);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk1Pt",Dtrk1Pt);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk2Pt",Dtrk2Pt);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk3Pt",Dtrk3Pt);
	ntlambdaCtopkpi->SetBranchAddress("Dtk1mass_Dfindersave",Dtk1mass_Dfindersave);
	ntlambdaCtopkpi->SetBranchAddress("Dtk2mass_Dfindersave",Dtk2mass_Dfindersave);
	ntlambdaCtopkpi->SetBranchAddress("Dtk3mass_Dfindersave",Dtk3mass_Dfindersave);


	cout<<" -- Building daughter pt branch"<<endl;
	Float_t kaon_pt[MAX_XB];
	Float_t pion_pt[MAX_XB];
	Float_t proton_pt[MAX_XB];
	//Float_t particlebranch[3]={kaon_pt[dsize],pion_pt[dsize],proton_pt[dsize]};

	TBranch *newdaughter_kaon_pt = ntlambdaCtopkpi->Branch("kaon_pt",kaon_pt,"kaon_pt[Dsize]/F");
	TBranch *newdaughter_pion_pt = ntlambdaCtopkpi->Branch("pion_pt",pion_pt,"pion_pt[Dsize]/F");
	TBranch *newdaughter_proton_pt =  ntlambdaCtopkpi->Branch("proton_pt",proton_pt,"proton_pt[Dsize]/F");

	cout<<" -- Filling daughter pt branch"<<endl;

	for (int entry = 0; entry < ntlambdaCtopkpi->GetEntries(); entry++)
	{
		ntlambdaCtopkpi->GetEntry(entry);
		int dsize =0;
		for (int i = 0; i < Dsize; i++ )
		{
				
				int pdgId1=findPdgid(Dtk1mass_Dfindersave[i]);
			    int pdgId2=findPdgid(Dtk2mass_Dfindersave[i]);
				int pddId3=findPdgid(Dtk3mass_Dfindersave[i]);
				
				if (pdgId1==0)
				{
					kaon_pt[dsize]=Dtrk1Pt[i];
				}
				else if (pdgId1==1)
				{
					pion_pt[dsize]=Dtrk1Pt[i];
				}
				else if (pdgId1==2)
				{
					proton_pt[dsize]=Dtrk1Pt[i];
				}
				if (pdgId2==0)
				{
					kaon_pt[dsize]=Dtrk2Pt[i];
				}
				else if (pdgId2==1)
				{
					pion_pt[dsize]=Dtrk2Pt[i];
				}
				else if (pdgId2==2)
				{
					proton_pt[dsize]=Dtrk2Pt[i];
				}
				if (pddId3==0)
				{
					kaon_pt[dsize]=Dtrk3Pt[i];
				}
				else if (pddId3==1)
				{
					pion_pt[dsize]=Dtrk3Pt[i];
				}
				else if (pddId3==2)
				{
					proton_pt[dsize]=Dtrk3Pt[i];
				}

//		cout<<"proton_pt "<<kaon_pt[dsize]<<endl;
		dsize++;

	   }//for i
	
		newdaughter_kaon_pt->Fill();
		newdaughter_pion_pt->Fill();
		newdaughter_proton_pt->Fill();

	}//for entry

	ntlambdaCtopkpi->Write("",TObject::kOverwrite);//save only the new version of the tree.
	
	cout<<" --End"<<endl;
	cout<<endl;
	return 1;
}
