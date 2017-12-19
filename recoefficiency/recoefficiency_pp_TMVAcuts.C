#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TCut.h>
//now this is ready to do the reconstruction efficiency with TMVA cuts.
void recoefficiency_pp_TMVAcuts(){
	//TFile *f = TFile::Open("/scratch/hammer/x/xiao147/MC_pt5_withcuts_Dntuple/kstar_pt5_Dntuple_withcuts.root");
	//TFile *f = TFile::Open("/scratch/hammer/x/xiao147/MC_pt10_withcuts_Dntuple/kstar_Dntuple_pt10.root");
	//TFile *f = TFile::Open("root://xrootd.rcac.purdue.edu//store/user/rxiao/datafromscratchhammer/MC_lambdaCpkpi/MC_pt5_withcuts_Dntuple/kstar_pt5_Dntuple_withcuts.root");
//	TFile *f = TFile::Open("/scratch/hammer/x/xiao147/MC_pt5_10_allnoweight_Dntuple/delta_whole5_10.root");  //this is for PbPb cuts
	//TFile *f = TFile::Open("/scratch/halstead/x/xiao147/official_MC/pt_4_MC_Dntuple/kstar_pt4_whole_official.root");
	//TFile *f = TFile::Open("/scratch/halstead/x/xiao147/official_MC/pt_4_MC_Dntuple/delta_pt4_whole.root");
	//TFile *f = TFile::Open("/scratch/halstead/x/xiao147/official_MC/pt_4_MC_Dntuple/lambda1520_pt4_whole.root");
	TFile *f = TFile::Open("/scratch/halstead/x/xiao147/official_MC/pt_4_MC_Dntuple/lambdaC_pkpi_pt4_whole.root");
	TTree *ntlambdaCtopkpi  = (TTree *) f->Get("ntlambdaCtopkpi");
	TTree *ntGen = (TTree *) f->Get("ntGen");

	
	const Int_t NBINS = 4;
	Double_t edges[NBINS + 1]={5,6,8,10,20};
	TH1 *hDpt_5_6 = new TH1D("hDpt_5_6","Dpt",NBINS,edges);
	TH1 *hDpt_6_8 = new TH1D("hDpt_6_8","Dpt",NBINS,edges);
	TH1 *hDpt_8_10 = new TH1D("hDpt_8_10","Dpt",NBINS,edges);
	TH1 *hDpt_10_20 = new TH1D("hDpt_10_20","Dpt",NBINS,edges);
	TH1 *hGpt = new TH1D("hGpt","Gpt",NBINS,edges);
	TCanvas *c1 = new TCanvas("c1","c1");
	TCut *MC_cut = new TCut("fabs(Gy)<1&&abs(GpdgId)==4122&&(GisSignal==15||GisSignal==16)");
	hDpt_5_6->Sumw2();
	hDpt_6_8->Sumw2();
	hDpt_8_10->Sumw2();
	hDpt_10_20->Sumw2();
	hGpt->Sumw2();
	ntGen->Project("hGpt","Gpt", *MC_cut);
/*
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




	TCut *reco_5_6_cut = new TCut("dls>2.6979993536749927&&pt>5&&pt<6&&chi2>0.26705336676903046&&alpha<0.21379631639014482&&abs(Dtrk1Y)<1.2&&abs(Dtrk2Y)<1.2&&abs(Dtrk3Y)<1.2&&mass>2.1&&mass<2.45");
	TCut *reco_6_8_cut = new TCut("dls>2.0553102716912526&&pt>6&&pt<8&&chi2>0.048977854761238913&&alpha<0.17856266296587384&&abs(Dtrk1Y)<1.2&&abs(Dtrk2Y)<1.2&&abs(Dtrk3Y)<1.2&&mass>2.1&&mass<2.45");
	TCut *reco_8_10_cut = new TCut("dls>1.9962837410042045&&pt>8&&pt<10&&chi2>0.045594948264545000&&alpha<0.17552951974295602&&abs(Dtrk1Y)<1.2&&abs(Dtrk2Y)<1.2&&abs(Dtrk3Y)<1.2&&mass>2.1&&mass<2.45");
	TCut *reco_10_20_cut = new TCut("dls>2.0567947541710949&&pt>10&&pt<20&&chi2>0.052311155858355128&&alpha<0.18578151058528442&&abs(Dtrk1Y)<1.2&&abs(Dtrk2Y)<1.2&&abs(Dtrk3Y)<1.2&&mass>2.1&&mass<2.45");
*/	
	
	TCut *reco_5_6_cut = new TCut("DsvpvDistance/DsvpvDisErr>2.6979993536749927&&Dpt>5&&Dpt<6&&Dchi2cl>0.26705336676903046&&Dalpha<0.21379631639014482&&fabs(Dtrk1Y)<1.2&&fabs(Dtrk2Y)<1.2&&fabs(Dtrk3Y)<1.2&&fabs(Dy)<1");
	TCut *reco_6_8_cut = new TCut("DsvpvDistance/DsvpvDisErr>2.0553102716912526&&Dpt>6&&Dpt<8&&Dchi2cl>0.048977854761238913&&Dalpha<0.17856266296587384&&fabs(Dtrk1Y)<1.2&&fabs(Dtrk2Y)<1.2&&fabs(Dtrk3Y)<1.2&&fabs(Dy)<1");
	TCut *reco_8_10_cut = new TCut("DsvpvDistance/DsvpvDisErr>1.9962837410042045&&Dpt>8&&Dpt<10&&Dchi2cl>0.045594948264545000&&Dalpha<0.17552951974295602&&fabs(Dtrk1Y)<1.2&&fabs(Dtrk2Y)<1.2&&fabs(Dtrk3Y)<1.2&&fabs(Dy)<1");
	TCut *reco_10_20_cut = new TCut("DsvpvDistance/DsvpvDisErr>2.0567947541710949&&Dpt>10&&Dpt<20&&Dchi2cl>0.052311155858355128&&Dalpha<0.18578151058528442&&fabs(Dtrk1Y)<1.2&&fabs(Dtrk2Y)<1.2&&fabs(Dtrk3Y)<1.2&&fabs(Dy)<1");
	
	
	ntlambdaCtopkpi->Project("hDpt_5_6","Dpt","Dgen==23333"&& *reco_5_6_cut);
	ntlambdaCtopkpi->Project("hDpt_6_8","Dpt","Dgen==23333"&& *reco_6_8_cut);
	ntlambdaCtopkpi->Project("hDpt_8_10","Dpt","Dgen==23333"&& *reco_8_10_cut);
	ntlambdaCtopkpi->Project("hDpt_10_20","Dpt","Dgen==23333"&& *reco_10_20_cut);
   	TH1F *hDpt =(TH1F*) hDpt_5_6->Clone("hDpt");
	hDpt->Sumw2();
	hDpt->Add(hDpt_6_8);
	hDpt->Sumw2();
	hDpt->Add(hDpt_8_10);
	hDpt->Sumw2();
	hDpt->Add(hDpt_10_20);
	hDpt->Sumw2();








	TH1F *hrecoefficiency = new TH1F("hrecoefficiency","hrecoefficiency",NBINS,edges);
	hrecoefficiency->Divide(hDpt,hGpt,1,1,"B");
	//hrecoefficiency->Divide(hGpt);
	hrecoefficiency->Draw("e");
//	hDpt->SetLineColor(2);
//	hGpt->SetLineColor(3);
//	hGpt->SetMinimum(0);
//	hGpt->Draw();
//	hDpt->Draw();
/*
	TFile *result = new TFile("recoeffi_kstar_pp_TMVAcuts.root","RECREATE");
	hrecoefficiency->Write();
	result->Close();
*/
	
	TFile *result = new TFile("recoeffi_pkpi_pp_TMVAcuts_official_pt4.root","RECREATE");
	hrecoefficiency->Write();
	result->Close();

}
