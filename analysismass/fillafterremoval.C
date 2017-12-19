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
#define PION_MASS   0.13957018
#define ELECTRON_MASS 0.0005
#define KS_MASS       0.497614
#define PHOTON_MASS   0.015
//here I need double check the mass for Ks and for photon.
//this code is for lambdaC to normal lambda and pion. Even though we give up this channel.
using namespace std;

Bool_t istest = true;
char pt_range[70];
char hname1[70];
char hname2[70];
char hname3[70];
char hname4[70];
char hname5[70];
char hname6[70];
TH1F *htktkresmass[7];
TH1F *hKsmass[7];
TH1F *hphotonmass[7];
TH1F *hwithoutremovemass[7];
TH1F *hmass[7];
TH1F *hwithoutremoveDmass[7];
Int_t ptbins[8]={3,5,8,10,15,25,40,80};


int decideptbin(float drespt)
{
  int ipt = -1;
   
  for (int i=0; i<7;i++)
  {
    if (drespt >= ptbins[i] && drespt < ptbins[i+1])
    {
      ipt = i;
      break;
    }
  }
  return ipt;

}



int fillafterremoval(TString infile="", TString outfile="",  Bool_t iseos=false)
{

     if(istest)
     {
         infile="/scratch/hammer/x/xiao147/skim_whole.root";
         outfile="histogram_whole_significance10_0508.root";
         iseos=false;
     }
     TString ifname;
     if(iseos) ifname = Form("root://eoscms.cern.ch//eos/cms%s",infile.Data());
     else ifname = infile;
     if (!TFile::Open(ifname))   { cout << " fail to open file" << endl; return 0;}
     TFile* f = TFile::Open(ifname);
     TTree * ntlambdaCtolambdapi = (TTree *) f->Get("ntlambdaCtolambdapi");
 

     for (Int_t i=0;i<7;i++)
     { 
 
        sprintf(hname1,"lambda_ptbin_%i",i);
        sprintf(pt_range, "p_{T}: %i to %i GeV", ptbins[i], ptbins[i+1]);
        sprintf(hname2,"Ks_ptbin_%i",i);
        sprintf(hname3,"photon_ptbin_%i",i);
        sprintf(hname4,"withoutremove_ptbin_%i",i);
        sprintf(hname5,"lambdaC_ptbin_%i",i);
        sprintf(hname6,"withoutremove_Dmass_ptbin_%i",i);
        htktkresmass[i]=new TH1F(hname1,pt_range,200,1.015,1.215);
        hKsmass[i]=new TH1F(hname2,pt_range,100,0.3,0.7);
        hphotonmass[i]=new TH1F(hname3,pt_range,20,0,0.2);
        hwithoutremovemass[i]=new TH1F(hname4,pt_range,200,1.015,1.215);
        hmass[i]=new TH1F(hname5,pt_range,35,2.1,2.45);
        hwithoutremoveDmass[i]=new TH1F(hname6,pt_range,35,2.1,2.45);
     }

     float   Dmass[MAX_XB];
     float   Dy[MAX_XB];
     float   DsvpvDistance[MAX_XB];
     float   DsvpvDisErr[MAX_XB];
     float   Dtrk1Pt[MAX_XB];
     float   Dtrk2Pt[MAX_XB];
     float   Dtrk1Eta[MAX_XB];
     float   Dtrk2Eta[MAX_XB];
     float   Dalpha[MAX_XB];
     float   Dchi2cl[MAX_XB];
     int     Dsize;
     float   Dpt[MAX_XB];
     float   DtktkResmass[MAX_XB];
     float   DtktkRes_alpha_new[MAX_XB];
     float   DtktkRes_chi2cl[MAX_XB];
     float   DtktkRes_svpvDistance[MAX_XB];
     float   DtktkRes_svpvDisErr[MAX_XB];
     float   DtktkRespt[MAX_XB];
     float   DRestrk1Pt[MAX_XB];
     float   DRestrk1Eta[MAX_XB];
     float   DRestrk1Phi[MAX_XB];
     float   DRestrk2Pt[MAX_XB];
     float   DRestrk2Eta[MAX_XB];
     float   DRestrk2Phi[MAX_XB];
        
     TLorentzVector    tk1;
     TLorentzVector    tk2;
     TLorentzVector    tk3;
     TLorentzVector    tk4;
     TLorentzVector    Res_Ks;
     TLorentzVector    Res_photon;
  ntlambdaCtolambdapi->SetBranchAddress("Dmass",Dmass);
  ntlambdaCtolambdapi->SetBranchAddress("Dy",Dy);
  ntlambdaCtolambdapi->SetBranchAddress("DsvpvDistance",DsvpvDistance);
  ntlambdaCtolambdapi->SetBranchAddress("DsvpvDisErr",DsvpvDisErr);
  ntlambdaCtolambdapi->SetBranchAddress("Dtrk1Pt",Dtrk1Pt);
  ntlambdaCtolambdapi->SetBranchAddress("Dtrk2Pt",Dtrk2Pt);
  ntlambdaCtolambdapi->SetBranchAddress("Dtrk1Eta",Dtrk1Eta);
  ntlambdaCtolambdapi->SetBranchAddress("Dtrk2Eta",Dtrk2Eta);
  ntlambdaCtolambdapi->SetBranchAddress("Dalpha",Dalpha);
  ntlambdaCtolambdapi->SetBranchAddress("Dchi2cl",Dchi2cl);
  ntlambdaCtolambdapi->SetBranchAddress("Dsize",&Dsize);
  ntlambdaCtolambdapi->SetBranchAddress("Dpt",Dpt);
  ntlambdaCtolambdapi->SetBranchAddress("DtktkResmass",DtktkResmass);
  ntlambdaCtolambdapi->SetBranchAddress("DtktkRes_alpha_new",DtktkRes_alpha_new);
  ntlambdaCtolambdapi->SetBranchAddress("DtktkRes_chi2cl",DtktkRes_chi2cl);
  ntlambdaCtolambdapi->SetBranchAddress("DtktkRes_svpvDistance",DtktkRes_svpvDistance);
  ntlambdaCtolambdapi->SetBranchAddress("DtktkRes_svpvDisErr",DtktkRes_svpvDisErr);
  ntlambdaCtolambdapi->SetBranchAddress("DtktkRespt",DtktkRespt);
  ntlambdaCtolambdapi->SetBranchAddress("DRestrk1Pt",DRestrk1Pt);
  ntlambdaCtolambdapi->SetBranchAddress("DRestrk1Eta",DRestrk1Eta);
  ntlambdaCtolambdapi->SetBranchAddress("DRestrk1Phi",DRestrk1Phi);
  ntlambdaCtolambdapi->SetBranchAddress("DRestrk2Pt",DRestrk2Pt);
  ntlambdaCtolambdapi->SetBranchAddress("DRestrk2Eta",DRestrk2Eta);
  ntlambdaCtolambdapi->SetBranchAddress("DRestrk2Phi",DRestrk2Phi);





  for (int entry = 0; entry < ntlambdaCtolambdapi->GetEntries(); entry++)
//for (int entry = 0; entry <100; entry++)
   {
     ntlambdaCtolambdapi->GetEntry(entry);
        for (int icand = 0; icand < Dsize; icand++ )
        {
          
//               if (cos(DtktkRes_alpha_new[icand])>0.997 && DtktkRes_chi2cl[icand]>0.10 && DtktkRes_svpvDistance[icand]/DtktkRes_svpvDisErr[icand]>5.0)
               if (cos(DtktkRes_alpha_new[icand])>0.997 && DtktkRes_chi2cl[icand]>0.10 && DtktkRes_svpvDistance[icand]/DtktkRes_svpvDisErr[icand]>10.0)
               {           
                              
                           int ipt = decideptbin(DtktkRespt[icand]);  
                           int dpt = decideptbin(Dpt[icand]);
//cout<<"ipt"<<ipt<<endl;
//cout<<"Dpt"<<Dpt[icand]<<endl;
//cout<<"dpt"<<dpt<<endl;
                           if (ipt < 0 || dpt < 0) continue;

                           //fill lambda mass plot without removial.
                           hwithoutremovemass[ipt]->Fill(DtktkResmass[icand]);
                          // if (Dalpha[icand]<0.12 && Dchi2cl[icand]>0.05 && DsvpvDistance[icand]/DsvpvDisErr[icand]>1.5 && DtktkResmass[icand]>1.10 && DtktkResmass[icand]<1.13)
                           if (Dalpha[icand]<0.2 && Dchi2cl[icand]>0.05 && DsvpvDistance[icand]/DsvpvDisErr[icand]>1.0 && DtktkResmass[icand]>1.11 && DtktkResmass[icand]<1.12)
                           {
                         //  int Dpt = decideptbin(Dpt[icand]);
                          
                           hwithoutremoveDmass[dpt]->Fill(Dmass[icand]);
                           }
                           tk1.SetPtEtaPhiM(DRestrk1Pt[icand],DRestrk1Eta[icand],DRestrk1Phi[icand],PION_MASS);
                           tk2.SetPtEtaPhiM(DRestrk2Pt[icand],DRestrk2Eta[icand],DRestrk2Phi[icand],PION_MASS);
                           Res_Ks=tk1+tk2; 
                           hKsmass[ipt]->Fill(Res_Ks.Mag());                                          
//cout<<"ipt"<<ipt<<endl;
                           if (Res_Ks.Mag()<KS_MASS-0.02 || Res_Ks.Mag()>KS_MASS+0.02)
                           {

                               //reconstruct photons
                               tk3.SetPtEtaPhiM(DRestrk1Pt[icand],DRestrk1Eta[icand],DRestrk1Phi[icand],ELECTRON_MASS);
                               tk4.SetPtEtaPhiM(DRestrk2Pt[icand],DRestrk2Eta[icand],DRestrk2Phi[icand],ELECTRON_MASS);
                               Res_photon=tk3+tk4;
                               hphotonmass[ipt]->Fill(Res_photon.Mag());
                               if (Res_photon.Mag()>PHOTON_MASS)
                               {
                                    htktkresmass[ipt]->Fill(DtktkResmass[icand]);
                                 
                                    if (Dalpha[icand]<0.2 && Dchi2cl[icand]>0.05 && DsvpvDistance[icand]/DsvpvDisErr[icand]>1.0 && DtktkResmass[icand]>1.10 && DtktkResmass[icand]<1.13)
                                    {
                                       hmass[dpt]->Fill(Dmass[icand]);
                                    }
                                     

                               }
                           }
                           
                             
             }

                      
        } 

    }
for (Int_t i=0; i<7; i++)
{
  htktkresmass[i]->SetTitle(Form("Resmass pt%i - %i",ptbins[i],ptbins[i+1]));
  hKsmass[i]->SetTitle(Form("Ksmass pt%i - %i",ptbins[i],ptbins[i+1]));
  hphotonmass[i]->SetTitle(Form("Photonmass pt%i - %i",ptbins[i],ptbins[i+1]));
  hwithoutremovemass[i]->SetTitle(Form("Beforeremoval_Resmass pt%i - %i",ptbins[i],ptbins[i+1]));
  hmass[i]->SetTitle(Form("lambda_Cmass pt%i - %i",ptbins[i],ptbins[i+1]));
  hwithoutremoveDmass[i]->SetTitle(Form("Beforeremovelambda_Cmass pt%i - %i",ptbins[i],ptbins[i+1]));
}
TFile * output = new TFile(Form("%s",outfile.Data()),"RECREATE");

for (Int_t i=0; i<7; i++)
{
  htktkresmass[i]->Write();
  hKsmass[i]->Write();
  hphotonmass[i]->Write();
  hwithoutremovemass[i]->Write();
  hmass[i]->Write();
  hwithoutremoveDmass[i]->Write();
}
output->Close();



return 1;
}




int main(int argc, char *argv[])
{
  if(argc==3)
   {
       fillafterremoval(argv[1], argv[2]);
    }
  else
    {
      std::cout << "Usage: mergeForest <input_collection> <output_file>" << std::endl;
      return 1;
    }

  return 0;
}


