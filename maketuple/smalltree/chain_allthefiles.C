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
#include <TChain.h>
#define  MAX_XB    20000
using namespace std;
void chain_allthefiles()
{
	TChain *ch1 = new TChain("ntlambdaCtopkpi");
	TChain *ch2 = new TChain("ntHi");
//	ch1->Add("/scratch/halstead/x/xiao147/2015PbPb_goldentrachecking_firsttry_Dntuple/goldenjson/whole/whole_addbranch/*.root");
//	ch2->Add("/scratch/halstead/x/xiao147/2015PbPb_goldentrachecking_firsttry_Dntuple/goldenjson/whole/whole_addbranch/*.root");
	ch1->Add("/scratch/halstead/x/xiao147/whole_2015_PbPb_goldernjson_trackingonly_lambdaC_pkpi/whole_addbranch/goldernjson/*.root");
	ch2->Add("/scratch/halstead/x/xiao147/whole_2015_PbPb_goldernjson_trackingonly_lambdaC_pkpi/whole_addbranch/goldernjson/*.root");
	ch1->AddFriend(ch2);
	cout<<" --finished the TChain part"<<endl;
//	TString outfile="/scratch/halstead/x/xiao147/2015PbPb_goldentrachecking_firsttry_Dntuple/goldenjson/whole/whole_addbranch/smallDntuple/Dntuple_small_cen10_100.root";
	TString outfile="/scratch/halstead/x/xiao147/whole_2015_PbPb_goldernjson_trackingonly_lambdaC_pkpi/whole_addbranch/goldernjson/smalltuple/goldenjson_smalltuple.root";
	TFile *outf = TFile::Open(Form("%s",outfile.Data()),"recreate");
	//TNtuple *nt = new TNtuple("nt","mergenewtuple","Dmass:Dpt:dls:Dchi2cl:Dalpha:Dtrk1Pt:Dtrk1Y:Dtrk2Pt:Dtrk2Y:Dtrk3Pt:Dtrk3Y:Dtrk1Eta:Dtrk2Eta:Dtrk3Eta:hiBin");
	TTree t1("t1","s simple Tree with several branches");
	float Dmass[MAX_XB];
	float Dpt[MAX_XB];
	float   DsvpvDistance[MAX_XB];
	float   DsvpvDisErr[MAX_XB];
	float   Dalpha[MAX_XB];
	float   Dchi2cl[MAX_XB];
	int     Dsize;
	float   Dtrk1Pt[MAX_XB];
    float   Dtrk1Y[MAX_XB];
	float   Dtrk2Pt[MAX_XB];
	float   Dtrk2Y[MAX_XB];
    float   Dtrk3Pt[MAX_XB];
	float   Dtrk3Y[MAX_XB];
	float   Dtrk1Eta[MAX_XB];
    float   Dtrk2Eta[MAX_XB];
    float   Dtrk3Eta[MAX_XB];
	int     hiBin;
	float   pion_pt[MAX_XB];
	float   kaon_pt[MAX_XB];
	float   proton_pt[MAX_XB];


ch1->SetBranchAddress("Dmass",Dmass);
ch1->SetBranchAddress("Dpt",Dpt);
ch1->SetBranchAddress("DsvpvDistance",DsvpvDistance);
ch1->SetBranchAddress("DsvpvDisErr",DsvpvDisErr);
ch1->SetBranchAddress("Dchi2cl",Dchi2cl);
ch1->SetBranchAddress("Dalpha",Dalpha);
ch1->SetBranchAddress("Dsize",&Dsize);
ch1->SetBranchAddress("Dtrk1Pt",Dtrk1Pt);
ch1->SetBranchAddress("Dtrk1Y",Dtrk1Y);

ch1->SetBranchAddress("Dtrk2Pt",Dtrk2Pt);
ch1->SetBranchAddress("Dtrk2Y",Dtrk2Y);
ch1->SetBranchAddress("Dtrk3Pt",Dtrk3Pt);
ch1->SetBranchAddress("Dtrk3Y",Dtrk3Y);
ch1->SetBranchAddress("Dtrk1Eta",Dtrk1Eta);
ch1->SetBranchAddress("Dtrk2Eta",Dtrk2Eta);
ch1->SetBranchAddress("Dtrk3Eta",Dtrk3Eta);
ch1->SetBranchAddress("hiBin",&hiBin);
ch1->SetBranchAddress("kaon_pt",kaon_pt);
ch1->SetBranchAddress("pion_pt",pion_pt);
ch1->SetBranchAddress("proton_pt",proton_pt);
float mass[MAX_XB];
float pt[MAX_XB];
float dls[MAX_XB];
float chi2cl[MAX_XB];
float alpha[MAX_XB];
float trk1Pt[MAX_XB];
float trk1Y[MAX_XB];
float trk2Pt[MAX_XB];
float trk2Y[MAX_XB];
float trk3Pt[MAX_XB];
float trk3Y[MAX_XB];
float trk1Eta[MAX_XB];
float trk2Eta[MAX_XB];
float trk3Eta[MAX_XB];
int   size;
int   Bin;
float kaonpt[MAX_XB];
float pionpt[MAX_XB];
float protonpt[MAX_XB];

t1.Branch("size",&size);
t1.Branch("Bin",&Bin);
t1.Branch("mass",mass,"mass[size]/F");
t1.Branch("pt",pt,"pt[size]/F");
t1.Branch("dls",dls,"dls[size]/F");
t1.Branch("chi2cl",chi2cl,"ch2cl[size]/F");
t1.Branch("alpha",alpha,"alpha[size]/F");
t1.Branch("trk1Pt",trk1Pt,"trk1Pt[size]/F");
t1.Branch("trk1Y",trk1Y,"trk1Y[size]/F");
t1.Branch("trk2Pt",trk2Pt,"trk2Pt[size]/F");
t1.Branch("trk2Y",trk2Y,"trk2Y[size]/F");
t1.Branch("trk3Pt",trk3Pt,"trk3Pt[size]/F");
t1.Branch("trk3Y",trk3Y,"trk3Y[size]/F");
t1.Branch("trk1Eta",trk1Eta,"trk1Eta[size]/F");
t1.Branch("trk2Eta",trk2Eta,"trk2Eta[size]/F");
t1.Branch("trk3Eta",trk3Eta,"trk3Eta[size]/F");
t1.Branch("kaonpt",kaon_pt,"kaonpt[size]/F");
t1.Branch("pionpt",pion_pt,"pionpt[size]/F");
t1.Branch("protonpt",proton_pt,"protonpt[size]/F");


for (int entry = 0; entry < ch1->GetEntries();entry++)
{
	ch1->GetEntry(entry);
	size = Dsize;
	Bin = hiBin;
	int dsize = 0;
	for (int i=0; i< Dsize; i++)
	{
		mass[dsize] = Dmass[i];
		pt[dsize] = Dpt[i];
		dls[dsize] = DsvpvDistance[i]/DsvpvDisErr[i];
		chi2cl[dsize] = Dchi2cl[i];
	    alpha[dsize] = Dalpha[i];
		trk1Pt[dsize] = Dtrk1Pt[i];
		trk1Y[dsize] = Dtrk1Y[i];
		trk2Pt[dsize] = Dtrk2Pt[i];
		trk2Y[dsize] = Dtrk2Y[i];
	    trk3Pt[dsize] = Dtrk3Pt[i];
		trk3Y[dsize] = Dtrk3Y[i];
        trk1Eta[dsize] = Dtrk1Eta[i];
		trk2Eta[dsize] = Dtrk2Eta[i];
		trk3Eta[dsize] = Dtrk3Eta[i];
		kaonpt[dsize] = kaon_pt[i];
		pionpt[dsize] = pion_pt[i];
		protonpt[dsize] = proton_pt[i];
		dsize++;
	}
	t1.Fill();
}//for entry
t1.Write();
outf->Write();
cout<<" --- Writing finished"<<endl;
outf->Close();
return 1;

}
