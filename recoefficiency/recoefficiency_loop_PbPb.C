#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TCut.h>
#define MAX_XB       20000
//now this is ready to do the reconstruction efficiency for PbPb with TMVA cuts..
void recoefficiency_loop_PbPb(){
	//TFile *f = TFile::Open("/scratch/hammer/x/xiao147/MC_pt5_withcuts_Dntuple/pkpi_pt5_Dntuple_withcuts.root");
	//TFile *f = TFile::Open("/scratch/hammer/x/xiao147/MC_pt10_withcuts_Dntuple/kstar_Dntuple_pt10.root");
	//TFile *f = TFile::Open("/scratch/hammer/x/xiao147/MC_pt5_10_allnoweight_Dntuple/kstar_whole5_10.root");  //this is for PbPb cuts
	//TFile *f = TFile::Open("root://xrootd.rcac.purdue.edu//store/user/rxiao/datafromscratchhammer/MC_lambdaCpkpi/MC_pt5_withcuts_Dntuple/kstar_pt5_Dntuple_withcuts.root");
	//TFile *f = TFile::Open("root://xrootd.rcac.purdue.edu//store/user/rxiao/datafromscratchhammer/MC_lambdaCpkpi/MC_pt5_withcuts_Dntuple/delta_pt5_Dntuple_withcuts.root");
	//TFile *f = TFile::Open("root://xrootd.rcac.purdue.edu//store/user/rxiao/datafromscratchhammer/MC_lambdaCpkpi/MC_pt5_withcuts_Dntuple/lambda1520_pt5_Dntuple_withcuts.root");
//	TFile *f = TFile::Open("root://xrootd.rcac.purdue.edu//store/user/rxiao/datafromscratchhammer/MC_lambdaCpkpi/MC_pt5_withcuts_Dntuple/pkpi_pt5_Dntuple_withcuts.root");
	//TFile *f = TFile::Open("/scratch/halstead/x/xiao147/official_MC/pt_4_MC_Dntuple/whole_addbranch/lambdaC_pkpi_pt4_whole.root");
    //TFile *f = TFile::Open("/scratch/halstead/x/xiao147/official_MC/pt_4_MC_Dntuple/whole_addbranch/lambda1520_pt4_whole.root");	
	//TFile *f = TFile::Open("/scratch/halstead/x/xiao147/official_MC/pt_4_MC_Dntuple/whole_addbranch/kstar_pt4_whole_official.root");
	TFile *f = TFile::Open("/scratch/halstead/x/xiao147/official_MC/pt_4_MC_Dntuple/whole_addbranch/delta_pt4_whole.root");

	TTree *ntlambdaCtopkpi  = (TTree *) f->Get("ntlambdaCtopkpi");
	TTree *ntGen = (TTree *) f->Get("ntGen");

	
	const Int_t NBINS = 4;
	Double_t edges[NBINS + 1]={5,6,8,10,20};
	TH1 *hDpt = new TH1D("hDpt","Dpt",NBINS,edges);
	TH1 *hGpt = new TH1D("hGpt","Gpt",NBINS,edges);
	TCanvas *c1 = new TCanvas("c1","c1");
	TCut *MC_cut = new TCut("fabs(Gy)<1&&abs(GpdgId)==4122&&(GisSignal==15||GisSignal==16)");
	hDpt->Sumw2();
	hGpt->Sumw2();
	ntGen->Project("hGpt","Gpt", *MC_cut);
	
	float   Dmass[MAX_XB];
	float   Dy[MAX_XB];
	float   DsvpvDistance[MAX_XB];
	float   DsvpvDisErr[MAX_XB];
	float   Dtrk1Eta[MAX_XB];
	float   Dtrk2Eta[MAX_XB];
	float   Dtrk3Eta[MAX_XB];
	float   Dalpha[MAX_XB];
	float   Dchi2cl[MAX_XB];
	int     Dsize;
	float   Dpt[MAX_XB];
	int     Dgen[MAX_XB];

	ntlambdaCtopkpi->SetBranchAddress("Dmass",Dmass);
	ntlambdaCtopkpi->SetBranchAddress("Dy",Dy);
	ntlambdaCtopkpi->SetBranchAddress("DsvpvDistance",DsvpvDistance);
	ntlambdaCtopkpi->SetBranchAddress("DsvpvDisErr",DsvpvDisErr);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk1Eta",Dtrk1Eta);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk2Eta",Dtrk2Eta);
	ntlambdaCtopkpi->SetBranchAddress("Dtrk3Eta",Dtrk3Eta);
	ntlambdaCtopkpi->SetBranchAddress("Dalpha",Dalpha);
	ntlambdaCtopkpi->SetBranchAddress("Dchi2cl",Dchi2cl);
	ntlambdaCtopkpi->SetBranchAddress("Dsize",&Dsize);
	ntlambdaCtopkpi->SetBranchAddress("Dpt",Dpt);
	ntlambdaCtopkpi->SetBranchAddress("Dgen",Dgen);

	for (int entry = 0; entry < ntlambdaCtopkpi->GetEntries(); entry++)
	{
		ntlambdaCtopkpi->GetEntry(entry);
		for (int icand = 0; icand < Dsize; icand++ )
		{
			if (Dgen[icand]==23333)
			{
            	if (Dpt[icand]>8&&Dpt[icand]<10)
				{
					if(DsvpvDistance[icand]/DsvpvDisErr[icand]>4.6431768574834038&&Dchi2cl[icand]>0.33510841187886442&&Dalpha[icand]<0.18851482981605913&&fabs(Dtrk1Eta[icand])<1.2&&fabs(Dtrk2Eta[icand])<1.2&&fabs(Dtrk3Eta[icand])<1.2&&fabs(Dy[icand])<1.0)
						{
							hDpt->Fill(Dpt[icand]);
							//cout<<"mass"<<Dmass[icand]<<endl;
						}//if 8-10 cut
				}//if 8-10
				if (Dpt[icand]>10&&Dpt[icand]<20)
				{
					if(DsvpvDistance[icand]/DsvpvDisErr[icand]>3.4469269876124975&&Dchi2cl[icand]>0.086999158864963691&&Dalpha[icand]<0.16893408284246497&&fabs(Dtrk1Eta[icand])<1.2&&fabs(Dtrk2Eta[icand])<1.2&&fabs(Dtrk3Eta[icand])<1.2&&fabs(Dy[icand])<1.0)
					{
						hDpt->Fill(Dpt[icand]);
					}//if 10-20 cut
				}//if 10-20
			}//23333
		}//for icand
	}//for entry
	TH1F *hrecoefficiency = new TH1F("hrecoefficiency","hrecoefficiency",NBINS,edges);
	hrecoefficiency->Sumw2();
	hrecoefficiency->Divide(hDpt,hGpt,1,1,"B");
	//hrecoefficiency->Divide(hGpt);
	hrecoefficiency->Draw("e");
	//hDpt->Draw();
//	hGpt->Draw();

//	TFile *result = new TFile("recoeffi_pkpi_PbPbcuts_pt5and10_TMVAcuts_pt5MC.root","RECREATE");
	TFile *result = new TFile("recoeffi_delta_PbPb_pt4_official.root","RECREATE");
	hrecoefficiency->Write();
	result->Close();

}
