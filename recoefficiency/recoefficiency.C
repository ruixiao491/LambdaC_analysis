#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TCut.h>
//now this is ready to do the reconstruction efficiency.
void recoefficiency(){
	//TFile *f = TFile::Open("/scratch/hammer/x/xiao147/MC_pt5_withcuts_Dntuple/pkpi_pt5_Dntuple_withcuts.root");
	//TFile *f = TFile::Open("/scratch/hammer/x/xiao147/MC_pt10_withcuts_Dntuple/kstar_Dntuple_pt10.root");
	TFile *f = TFile::Open("/scratch/hammer/x/xiao147/MC_pt5_10_allnoweight_Dntuple/delta_whole5_10.root");  //this is for PbPb cuts
	TTree *ntlambdaCtopkpi  = (TTree *) f->Get("ntlambdaCtopkpi");
	TTree *ntGen = (TTree *) f->Get("ntGen");

	
	const Int_t NBINS = 3;
	Double_t edges[NBINS + 1]={6,8,10,20};
	TH1 *hDpt = new TH1D("hDpt","Dpt",NBINS,edges);
	TH1 *hGpt = new TH1D("hGpt","Gpt",NBINS,edges);
	TCanvas *c1 = new TCanvas("c1","c1");
	TCut *MC_cut = new TCut("fabs(Gy)<1&&abs(GpdgId)==4122&&GnDa==2");
	hDpt->Sumw2();
	hGpt->Sumw2();
	//I just use the same cut that I used for pp
  	//TCut *reco_cut = new TCut("fabs(Dy)<1.0&&Dchi2cl>0.10&&fabs(Dtrk1Eta)<1.2&&fabs(Dtrk2Eta)<1.2&&fabs(Dtrk3Eta)<1.2&&Dalpha<0.12&&DsvpvDistance/DsvpvDisErr>2.0");//pp cut except for eta and y.
	//the following cut is the PbPb cut.
	TCut * reco_cut = new TCut("fabs(Dy)<1.0&&Dchi2cl>0.10&&fabs(Dtrk1Eta)<1.2&&fabs(Dtrk2Eta)<1.2&&fabs(Dtrk3Eta)<1.2&&Dalpha<0.12&&DsvpvDistance/DsvpvDisErr>4.0");
  	ntlambdaCtopkpi->Project("hDpt","Dpt","Dgen==23333"&& *reco_cut);
	ntGen->Project("hGpt","Gpt", *MC_cut);
	//hDpt->Sumw2();
	//hGpt->Sumw2();
	//TH1F *hrecoefficiency = (TH1F*) hDpt->Clone("hrecoefficiency");
	TH1F *hrecoefficiency = new TH1F("hrecoefficiency","hrecoefficiency",NBINS,edges);
	hrecoefficiency->Divide(hDpt,hGpt,1,1,"B");
	//hrecoefficiency->Divide(hGpt);
	hrecoefficiency->Draw("e");
	//hDpt->Draw();
	//hGpt->Draw();
	TFile *result = new TFile("recoeffi_delta_PbPbcuts_pt5and10.root","RECREATE");
	hrecoefficiency->Write();
	result->Close();
}
