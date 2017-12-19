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
#define  MAX_XB    20000
using namespace std;
  Bool_t istest = false;
  int make_lambdatuple(TString infile="", TString outfile="",  Bool_t iseos=false)
  {
	  if(istest)
  {  infile="/scratch/halstead/x/xiao147/Dntuple_MB14_Run2015E_PromptReco_v1_lambdaCmixchannels_pp_20170905_noptcut.root";
     outfile="fnt.root";
	 iseos=false;
  }
     TString ifname;
	 if(iseos) ifname = Form("root://eoscms.cern.ch//eos/cms%s",infile.Data());
	 else ifname = infile;
	 if (!TFile::Open(ifname))   { cout << " fail to open file" << endl; return 0;}	 
	 TFile* f = TFile::Open(infile);
     TTree * ntLambdaCtolambdapi = (TTree *) f->Get("ntLambdaCtolambdapi");
	 TFile* outf = TFile::Open(Form("%s", outfile.Data()),"recreate");
//	 TChain *chain = new TChain("ntLambdaCtolambdapi");
//	 chain->Add(ifname);
//	 chain->ls();
	TNtuple *nt = new TNtuple("nt", "lambdachannel",
           "mass:pt:dls:chi2:alpha:Dtrk1Pt:Dtrk1Phi:Dtrk1Dxy:Dtrk1Y:Dtrk2Pt:Dtrk2Phi:Dtrk2Dxy:Dtrk2Y:Dtrk3Pt:Dtrk3Phi:Dtrk3Dxy:Dtrk3Y:DtktkResmass:DtktkRes_alpha_new:DtktkRes_chi2cl:resdls:DtktkRespt:DtktkReseta");
     float Dmass[MAX_XB];
     float Dpt[MAX_XB];
     float   DsvpvDistance[MAX_XB];
     float   DsvpvDisErr[MAX_XB];
     float   Dalpha[MAX_XB];
     float   Dchi2cl[MAX_XB];
     int     Dsize;
	 float   Dtrk1Pt[MAX_XB];
     float   Dtrk1Phi[MAX_XB];
     float   Dtrk1Dxy[MAX_XB];
     float   Dtrk1Y[MAX_XB];
     float   Dtrk2Pt[MAX_XB];
     float   Dtrk2Phi[MAX_XB];
     float   Dtrk2Dxy[MAX_XB];
     float   Dtrk2Y[MAX_XB];
     float   Dtrk3Pt[MAX_XB];
     float   Dtrk3Phi[MAX_XB];
     float   Dtrk3Dxy[MAX_XB];
     float   Dtrk3Y[MAX_XB];
	 float   DtktkResmass[MAX_XB];
	 float   DtktkRes_alpha_new[MAX_XB];
	 float   DtktkRes_chi2cl[MAX_XB];
	 float   DtktkRes_svpvDistance[MAX_XB];
	 float   DtktkRes_svpvDisErr[MAX_XB];
	 float   DtktkRespt[MAX_XB];
	 float   DtktkReseta[MAX_XB];
   ntLambdaCtolambdapi->SetBranchAddress("Dmass",Dmass);
   ntLambdaCtolambdapi->SetBranchAddress("Dpt",Dpt);
   ntLambdaCtolambdapi->SetBranchAddress("DsvpvDistance",DsvpvDistance);
   ntLambdaCtolambdapi->SetBranchAddress("DsvpvDisErr",DsvpvDisErr);
   ntLambdaCtolambdapi->SetBranchAddress("Dchi2cl",Dchi2cl);
   ntLambdaCtolambdapi->SetBranchAddress("Dalpha",Dalpha);
   ntLambdaCtolambdapi->SetBranchAddress("Dsize",&Dsize);
   ntLambdaCtolambdapi->SetBranchAddress("Dtrk1Pt",Dtrk1Pt);
   ntLambdaCtolambdapi->SetBranchAddress("Dtrk1Phi",Dtrk1Phi);
   ntLambdaCtolambdapi->SetBranchAddress("Dtrk1Dxy",Dtrk1Dxy);
   ntLambdaCtolambdapi->SetBranchAddress("Dtrk1Y",Dtrk1Y);

   ntLambdaCtolambdapi->SetBranchAddress("Dtrk2Pt",Dtrk2Pt);
   ntLambdaCtolambdapi->SetBranchAddress("Dtrk2Phi",Dtrk2Phi);
   ntLambdaCtolambdapi->SetBranchAddress("Dtrk2Dxy",Dtrk2Dxy);
   ntLambdaCtolambdapi->SetBranchAddress("Dtrk2Y",Dtrk2Y);
   ntLambdaCtolambdapi->SetBranchAddress("Dtrk3Pt",Dtrk3Pt);
   ntLambdaCtolambdapi->SetBranchAddress("Dtrk3Phi",Dtrk3Phi);
   ntLambdaCtolambdapi->SetBranchAddress("Dtrk3Phi",Dtrk3Phi);
   ntLambdaCtolambdapi->SetBranchAddress("Dtrk3Dxy",Dtrk3Dxy);
   ntLambdaCtolambdapi->SetBranchAddress("Dtrk3Y",Dtrk3Y);
   ntLambdaCtolambdapi->SetBranchAddress("DtktkResmass",DtktkResmass);
   ntLambdaCtolambdapi->SetBranchAddress("DtktkRes_alpha_new",DtktkRes_alpha_new);
   ntLambdaCtolambdapi->SetBranchAddress("DtktkRes_chi2cl",DtktkRes_chi2cl);
   ntLambdaCtolambdapi->SetBranchAddress("DtktkRes_svpvDistance",DtktkRes_svpvDistance);
   ntLambdaCtolambdapi->SetBranchAddress("DtktkRes_svpvDisErr",DtktkRes_svpvDisErr);
   ntLambdaCtolambdapi->SetBranchAddress("DtktkRespt",DtktkRespt);
   ntLambdaCtolambdapi->SetBranchAddress("DtktkReseta",DtktkReseta);

   // cout<<"a"<<endl; 
    float   nt_array[70000];
    for (int entry = 0; entry < ntLambdaCtolambdapi->GetEntries(); entry++)
    //for (int entry = 0; entry < 100; entry++)		
    {
       ntLambdaCtolambdapi->GetEntry(entry);
//		if (Dsize!=0){
//		cout<<"Dsize"<<Dsize<<endl;}
		//cout<<"b"<<endl;
       //ntLambdaCtolambdapi->GetEntry(entry);
        for (int i = 0; i < Dsize; i++ )
        {
          nt_array[0] = Dmass[i];
          nt_array[1] = Dpt[i];
          nt_array[2] = DsvpvDistance[i]/DsvpvDisErr[i];
          nt_array[3] = Dchi2cl[i];
          nt_array[4] = Dalpha[i];
          nt_array[5] = Dtrk1Pt[i];
          nt_array[6] = Dtrk1Phi[i];
          nt_array[7] = Dtrk1Dxy[i];
          nt_array[8] = Dtrk1Y[i];
          nt_array[9] = Dtrk2Pt[i];
          nt_array[10] = Dtrk2Phi[i];
          nt_array[11] = Dtrk2Dxy[i];
          nt_array[12] = Dtrk2Y[i];
          nt_array[13] = Dtrk3Pt[i];
          nt_array[14] = Dtrk3Phi[i];
          nt_array[15] = Dtrk3Dxy[i];
          nt_array[16] = Dtrk3Y[i];
		  nt_array[17] = DtktkResmass[i];
		  nt_array[18] = DtktkRes_alpha_new[i];
		  nt_array[19] = DtktkRes_chi2cl[i];
		  nt_array[20] = DtktkRes_svpvDistance[i]/DtktkRes_svpvDisErr[i];
		  nt_array[21] = DtktkRespt[i];
		  nt_array[22] = DtktkReseta[i];
          nt->Fill(nt_array);
       }
    }

nt->Write();
outf->Write();
cout<<"--- Writing finished"<<endl;
outf->Close();

return 0;

}

int main(int argc, char *argv[])
{
	if(argc==3)
    {	
		make_lambdatuple(argv[1], argv[2]);
	}
	else
	{
		std::cout << "Usage: mergeForest <input_collection> <output_file>" << std::endl;
		return 1;
	}
	return 0;
}
