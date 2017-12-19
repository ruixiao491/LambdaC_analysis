#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TCut.h>
#define MAX_XB       20000
#define MAX_GEN      6000
//now this is ready for systematic (acc*eff with pp TMVA cuts) have not tested.

Int_t ptbins[3]={8,10,20};
Double_t dls[2]={4.6431768574834038,3.4469269876124975};
Double_t alpha[2]={0.18851482981605913,0.16893408284246497};
Double_t vertexpro[2]={0.33510841187886442,0.086999158864963691};

int decideptbin(float drespt)
{
	  int ipt = -1; 
	     
	  for (int i=0; i<2;i++)
	   {
		  if (drespt >= ptbins[i] && drespt < ptbins[i+1])
			{   
			    ipt = i;
				break;
			}   
		}
	return ipt;
}





void systematic_recoeffi_PbPb_weight(){
//	TFile *f1 = TFile::Open("root://xrootd.rcac.purdue.edu//store/user/rxiao/datafromscratchhammer/MC_lambdaCpkpi/MC_pt5_withcuts_Dntuple/pkpi_pt5_Dntuple_withcuts.root");
	//TFile *f1 = TFile::Open("root://xrootd.rcac.purdue.edu//store/user/rxiao/datafromscratchhammer/MC_lambdaCpkpi/MC_pt5_withcuts_Dntuple/lambda1520_pt5_Dntuple_withcuts.root");
	//TFile *f1 = TFile::Open("root://xrootd.rcac.purdue.edu//store/user/rxiao/datafromscratchhammer/MC_lambdaCpkpi/MC_pt5_withcuts_Dntuple/delta_pt5_Dntuple_withcuts.root");
	TFile *f1 = TFile::Open("root://xrootd.rcac.purdue.edu//store/user/rxiao/datafromscratchhammer/MC_lambdaCpkpi/MC_pt5_withcuts_Dntuple/kstar_pt5_Dntuple_withcuts.root");
	
	
	//TFile *f1 = TFile::Open("/scratch/hammer/x/xiao147/MC_pt5_withcuts_Dntuple/pkpi_pt5_Dntuple_withcuts.root");
	//TFile *f1 = TFile::Open("/scratch/hammer/x/xiao147/MC_pt10_withcuts_Dntuple/kstar_Dntuple_pt10.root");
	//TFile *f1 = TFile::Open("/scratch/hammer/x/xiao147/MC_pt5_10_allnoweight_Dntuple/kstar_whole5_10.root");  //this is for PbPb cuts
	//TFile *f2 = TFile::Open("weight_2functions.root");
	TFile *f2 = TFile::Open("weight_2functions_downup_centra.root");
	TTree *ntlambdaCtopkpi  = (TTree *) f1->Get("ntlambdaCtopkpi");
	TTree *ntGen = (TTree *) f1->Get("ntGen");
	TF1 * weight_2func = (TF1*)f2->Get("weight_twofunction");
	
	const Int_t NBINS = 4;
	Double_t edges[NBINS + 1]={5,6,8,10,20};
	TH1 *hDpt = new TH1D("hDpt","Dpt",NBINS,edges);
	TH1 *hGpt = new TH1D("hGpt","Gpt",NBINS,edges);
	TCanvas *c1 = new TCanvas("c1","c1");
	hDpt->Sumw2();
	hGpt->Sumw2();
	
	float   Dmass[MAX_XB];
	float   Dy[MAX_XB];
	float   DsvpvDistance[MAX_XB];
	float   DsvpvDisErr[MAX_XB];
	float   Dtrk1Eta[MAX_XB];
	float   Dtrk2Eta[MAX_XB];
	float   Dtrk3Eta[MAX_XB];
	float   Dtrk1Y[MAX_XB];
	float   Dtrk2Y[MAX_XB];
	float   Dtrk3Y[MAX_XB];
	float   Dalpha[MAX_XB];
	float   Dchi2cl[MAX_XB];
	int     Dsize;
	float   Dpt[MAX_XB];
	int     Dgen[MAX_XB];

	int     Gsize;
	float   Gy[MAX_GEN];
	int     GpdgId[MAX_GEN];
	int     GisSignal[MAX_GEN];
	float   Gpt[MAX_GEN];


	ntlambdaCtopkpi->SetBranchAddress("Dmass",Dmass);
	ntlambdaCtopkpi->SetBranchAddress("Dy",Dy);
	ntlambdaCtopkpi->SetBranchAddress("DsvpvDistance",DsvpvDistance);
	ntlambdaCtopkpi->SetBranchAddress("DsvpvDisErr",DsvpvDisErr);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk1Eta",Dtrk1Eta);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk2Eta",Dtrk2Eta);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk3Eta",Dtrk3Eta);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk1Y",Dtrk1Y);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk2Y",Dtrk2Y);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk3Y",Dtrk3Y);
	ntlambdaCtopkpi->SetBranchAddress("Dalpha",Dalpha);
	ntlambdaCtopkpi->SetBranchAddress("Dchi2cl",Dchi2cl);
	ntlambdaCtopkpi->SetBranchAddress("Dsize",&Dsize);
	ntlambdaCtopkpi->SetBranchAddress("Dpt",Dpt);
	ntlambdaCtopkpi->SetBranchAddress("Dgen",Dgen);

	ntGen->SetBranchAddress("Gsize",&Gsize);
    ntGen->SetBranchAddress("Gy",Gy);
	ntGen->SetBranchAddress("GpdgId",GpdgId);
	ntGen->SetBranchAddress("GisSignal",GisSignal);
	ntGen->SetBranchAddress("Gpt",Gpt);



	for (int entry = 0; entry < ntlambdaCtopkpi->GetEntries(); entry++)
	{
		ntlambdaCtopkpi->GetEntry(entry);
		ntGen->GetEntry(entry);
		double weight_reco=0;
		double weight_gen=0;
		for (int icand = 0; icand < Dsize; icand++ )
		{
			
		      int ipt = decideptbin(Dpt[icand]);
			  if (ipt < 0) continue;
//			  cout<<"pt"<<Dpt[icand]<<" dis"<<dls[ipt]<<endl;
			  if (DsvpvDistance[icand]/DsvpvDisErr[icand]>dls[ipt]&&Dchi2cl[icand]>vertexpro[ipt]&&Dalpha[icand]<alpha[ipt]&&fabs(Dy[icand])<1&&fabs(Dtrk1Eta[icand])<1.2&&fabs(Dtrk2Eta[icand])<1.2&&fabs(Dtrk3Eta[icand])<1.2&&Dgen[icand]==23333)
			  {
			       weight_reco=weight_2func->Eval(Dpt[icand]);
			       if (weight_reco<0)
			       {
				      weight_reco=0;
			       }
			      hDpt->Fill(Dpt[icand],weight_reco);
				 // hDpt->Fill(Dpt[icand]);
              }

			
		}//for icand ntlambdac
		for (int icand = 0; icand < Gsize; icand++ )
		{
			if (fabs(Gy[icand])<1&&fabs(GpdgId[icand])==4122&& (GisSignal[icand]==15||GisSignal[icand]==16))
			{
				int igpt = decideptbin(Gpt[icand]);
				if (igpt<0) continue;
				weight_gen=weight_2func->Eval(Gpt[icand]);
				if (weight_gen<0)
				{
					weight_gen=0;
				}
			//	hGpt->Fill(Gpt[icand]);
				hGpt->Fill(Gpt[icand],weight_gen);

			}//if
		}//for icand ntGen

	}//for entry
	TH1F *hrecoeffi_fun1 = new TH1F("hrecoeffi_fun1","hrecoefficiency_fun1",NBINS,edges);
	hrecoeffi_fun1->Sumw2();
	hrecoeffi_fun1->Divide(hDpt,hGpt,1,1,"B");
	hrecoeffi_fun1->Draw("e");
	//hDpt->SetLineColor(2);
	//hGpt->SetLineColor(3);
	//hGpt->SetMinimum(0);
	//hGpt->Draw();
	//hDpt->Draw();
	
	TFile *result = new TFile("recoeffi_kstar_PbPbcuts_TMVAcuts_fun1_downup_cent.root","RECREATE");
	hrecoeffi_fun1->Write();
	result->Close();

}
