#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TCut.h>
//This is get mass specture from MC to do the signal exrtraction---first step..
void signalexact(){
	/*
	TFile *f1 = TFile::Open("/scratch/hammer/x/xiao147/MC_pt5_withcuts_Dntuple/pkpi_pt5_Dntuple_withcuts.root");
	TFile *f2 = TFile::Open("/scratch/hammer/x/xiao147/MC_pt5_withcuts_Dntuple/lambda1520_pt5_Dntuple_withcuts.root");
	TFile *f3 = TFile::Open("/scratch/hammer/x/xiao147/MC_pt5_withcuts_Dntuple/delta_pt5_Dntuple_withcuts.root");
	TFile *f4 = TFile::Open("/scratch/hammer/x/xiao147/MC_pt5_withcuts_Dntuple/kstar_pt5_Dntuple_withcuts.root");
*/

	TFile *f1 = TFile::Open("root://xrootd.rcac.purdue.edu//store/user/rxiao/datafromscratchhammer/MC_lambdaCpkpi/MC_pt5_withcuts_Dntuple/pkpi_pt5_Dntuple_withcuts.root");
	TFile *f2 = TFile::Open("root://xrootd.rcac.purdue.edu//store/user/rxiao/datafromscratchhammer/MC_lambdaCpkpi/MC_pt5_withcuts_Dntuple/lambda1520_pt5_Dntuple_withcuts.root");
	TFile *f3 = TFile::Open("root://xrootd.rcac.purdue.edu//store/user/rxiao/datafromscratchhammer/MC_lambdaCpkpi/MC_pt5_withcuts_Dntuple/delta_pt5_Dntuple_withcuts.root");
	TFile *f4 = TFile::Open("root://xrootd.rcac.purdue.edu//store/user/rxiao/datafromscratchhammer/MC_lambdaCpkpi/MC_pt5_withcuts_Dntuple/kstar_pt5_Dntuple_withcuts.root");



	TTree *t1  = (TTree *) f1->Get("ntlambdaCtopkpi");
	TTree *t2  = (TTree *) f2->Get("ntlambdaCtopkpi");
	TTree *t3  = (TTree *) f3->Get("ntlambdaCtopkpi");
	TTree *t4  = (TTree *) f4->Get("ntlambdaCtopkpi");
	
	TH1F *h1_signal = new TH1F("h1_signal","mass",100,2.1,2.45);
	TH1F *h2_signal = new TH1F("h2_signal","mass",100,2.1,2.45);
	TH1F *h3_signal = new TH1F("h3_signal","mass",100,2.1,2.45);
	TH1F *h4_signal = new TH1F("h4_signal","mass",100,2.1,2.45);

	TH1F *h1_swapped = new TH1F("h1_swapped","mass",100,2.1,2.45);
	TH1F *h2_swapped = new TH1F("h2_swapped","mass",100,2.1,2.45);
	TH1F *h3_swapped = new TH1F("h3_swapped","mass",100,2.1,2.45);
	TH1F *h4_swapped = new TH1F("h4_swapped","mass",100,2.1,2.45);

	TH1F *h1_nocut_signal = new TH1F("h1_nocut_signal","mass",100,2.1,2.45);
	TH1F *h2_nocut_signal = new TH1F("h2_nocut_signal","mass",100,2.1,2.45);
	TH1F *h3_nocut_signal = new TH1F("h3_nocut_signal","mass",100,2.1,2.45);
	TH1F *h4_nocut_signal = new TH1F("h4_nocut_signal","mass",100,2.1,2.45);

	TH1F *h1_nocut_swapped = new TH1F("h1_nocut_swapped","mass",100,2.1,2.45);
	TH1F *h2_nocut_swapped = new TH1F("h2_nocut_swapped","mass",100,2.1,2.45);
	TH1F *h3_nocut_swapped = new TH1F("h3_nocut_swapped","mass",100,2.1,2.45);
	TH1F *h4_nocut_swapped = new TH1F("h4_nocut_swapped","mass",100,2.1,2.45);
	
	h1_signal->Sumw2();
	h2_signal->Sumw2();
	h3_signal->Sumw2();
	h4_signal->Sumw2();
	
	h1_swapped->Sumw2();
	h2_swapped->Sumw2();
	h3_swapped->Sumw2();
	h4_swapped->Sumw2();

	h1_nocut_signal->Sumw2();
	h2_nocut_signal->Sumw2();
	h3_nocut_signal->Sumw2();
	h4_nocut_signal->Sumw2();
	
	h1_nocut_swapped->Sumw2();
	h2_nocut_swapped->Sumw2();
	h3_nocut_swapped->Sumw2();
	h4_nocut_swapped->Sumw2();

	gStyle->SetOptTitle(0);
//	gStyle->SetOptStat(0);
	TCanvas *c1 = new TCanvas("c1","c1");
///////The follwoing is to test the cut efficiency.
	//TCut * reco_cut = new TCut("fabs(Dy)<1.0&&Dchi2cl>0.28&&fabs(Dtrk1Eta)<1.2&&fabs(Dtrk2Eta)<1.2&&fabs(Dtrk3Eta)<1.2&&Dalpha<0.18578151058528442&&DsvpvDistance/DsvpvDisErr>2.0567947541710949&&Dpt>10&&Dpt<20");   //pp 10-20 TMVA cuts.
	//TCut * reco_cut = new TCut("fabs(Dy)<1.0&&Dchi2cl>0.48&&fabs(Dtrk1Eta)<1.2&&fabs(Dtrk2Eta)<1.2&&fabs(Dtrk3Eta)<1.2&&Dalpha<0.21379631639014482&&DsvpvDistance/DsvpvDisErr>2.6979993536749927&&Dpt>5&&Dpt<6");   //pp 5-6 TMVA cuts.


	//TCut * reco_cut = new TCut("fabs(Dy)<1.0&&Dchi2cl>0.28&&fabs(Dtrk1Eta)<1.2&&fabs(Dtrk2Eta)<1.2&&fabs(Dtrk3Eta)<1.2&&Dalpha<0.17552951974295602&&DsvpvDistance/DsvpvDisErr>1.9962837410042045&&Dpt>8&&Dpt<10");   //pp 8-10 TMVA cuts.

	TCut * reco_cut = new TCut("fabs(Dy)<1.0&&Dchi2cl>0.048977854761238913&&fabs(Dtrk1Eta)<1.2&&fabs(Dtrk2Eta)<1.2&&fabs(Dtrk3Eta)<1.2&&Dalpha<0.17856266296587384&&DsvpvDistance/DsvpvDisErr>2.51&&Dpt>6&&Dpt<8");   //pp 6-8 TMVA cuts.

	//TCut * reco_cut = new TCut("fabs(Dy)<1.0&&Dchi2cl>0.33&&fabs(Dtrk1Eta)<1.2&&fabs(Dtrk2Eta)<1.2&&fabs(Dtrk3Eta)<1.2&&Dalpha<0.16893408284246497&&DsvpvDistance/DsvpvDisErr>3.4469269876124975&&Dpt>10&&Dpt<20");   //PbPb 10-20 TMVA cuts.
//////The following is the optimazation cut from TMVA.
	//the following cut is the PbPb cut.
	//TCut * reco_cut = new TCut("fabs(Dy)<1.0&&Dchi2cl>0.052311155858355128&&fabs(Dtrk1Eta)<1.2&&fabs(Dtrk2Eta)<1.2&&fabs(Dtrk3Eta)<1.2&&Dalpha<0.18578151058528442&&DsvpvDistance/DsvpvDisErr>2.0567947541710949&&Dpt>10&&Dpt<20");   //pp 10-20 TMVA cuts.
//	TCut * reco_cut = new TCut("fabs(Dy)<1.0&&Dchi2cl>0.045594948264545000&&fabs(Dtrk1Eta)<1.2&&fabs(Dtrk2Eta)<1.2&&fabs(Dtrk3Eta)<1.2&&Dalpha<0.17552951974295602&&DsvpvDistance/DsvpvDisErr>1.9962837410042045&&Dpt>8&&Dpt<10");   //pp 8-10 TMVA cuts.
//	TCut * reco_cut = new TCut("fabs(Dy)<1.0&&Dchi2cl>0.048977854761238913&&fabs(Dtrk1Eta)<1.2&&fabs(Dtrk2Eta)<1.2&&fabs(Dtrk3Eta)<1.2&&Dalpha<0.17856266296587384&&DsvpvDistance/DsvpvDisErr>2.0553102716912526&&Dpt>6&&Dpt<8");   //pp 6-8 TMVA cuts.
//	TCut * reco_cut = new TCut("fabs(Dy)<1.0&&Dchi2cl>0.26705336676903046&&fabs(Dtrk1Eta)<1.2&&fabs(Dtrk2Eta)<1.2&&fabs(Dtrk3Eta)<1.2&&Dalpha<0.21379631639014482&&DsvpvDistance/DsvpvDisErr>2.6979993536749927&&Dpt>5&&Dpt<6");   //pp 5-6 TMVA cuts.
//	TCut * reco_cut = new TCut("fabs(Dy)<1.0&&Dchi2cl>0.086999158864963691&&fabs(Dtrk1Eta)<1.2&&fabs(Dtrk2Eta)<1.2&&fabs(Dtrk3Eta)<1.2&&Dalpha<0.16893408284246497&&DsvpvDistance/DsvpvDisErr>3.4469269876124975&&Dpt>10&&Dpt<20");   //PbPb 10-20 TMVA cuts.
//	TCut * reco_cut = new TCut("fabs(Dy)<1.0&&Dchi2cl>0.33510841187886442&&fabs(Dtrk1Eta)<1.2&&fabs(Dtrk2Eta)<1.2&&fabs(Dtrk3Eta)<1.2&&Dalpha<0.18851482981605913&&DsvpvDistance/DsvpvDisErr>4.6431768574834038&&Dpt>8&&Dpt<10");   //PbPb 8-10 TMVA cuts.

   t1->Project("h1_signal","Dmass",*reco_cut&&"Dgen==23333","7.07070707");//this is for pkpi.
   t2->Project("h2_signal","Dmass",*reco_cut&&"Dgen==23333"); // this is for lambda1520, its weight is 1.
   t3->Project("h3_signal","Dmass",*reco_cut&&"Dgen==23333","2.20202020"); //this is for delta.
   t4->Project("h4_signal","Dmass",*reco_cut&&"Dgen==23333","2.66666667");// this is for kstar.
   
   
   t1->Project("h1_swapped","Dmass",*reco_cut&&"Dgen==23344","7.07070707");//this is for pkpi.
   t2->Project("h2_swapped","Dmass",*reco_cut&&"Dgen==23344"); // this is for lambda1520, its weight is 1.
   t3->Project("h3_swapped","Dmass",*reco_cut&&"Dgen==23344","2.20202020"); //this is for delta.
   t4->Project("h4_swapped","Dmass",*reco_cut&&"Dgen==23344","2.66666667");// this is for kstar.
   
   //the following is no cuts histograms.
   t1->Project("h1_nocut_signal","Dmass","Dgen==23333","7.07070707");//this is for pkpi.
   t2->Project("h2_nocut_signal","Dmass","Dgen==23333"); // this is for lambda1520, its weight is 1.
   t3->Project("h3_nocut_signal","Dmass","Dgen==23333","2.20202020"); //this is for delta.
   t4->Project("h4_nocut_signal","Dmass","Dgen==23333","2.66666667");// this is for kstar.
  
   t1->Project("h1_nocut_swapped","Dmass","Dgen==23344","7.07070707");//this is for pkpi.
   t2->Project("h2_nocut_swapped","Dmass","Dgen==23344"); // this is for lambda1520, its weight is 1.
   t3->Project("h3_nocut_swapped","Dmass","Dgen==23344","2.20202020"); //this is for delta.
   t4->Project("h4_nocut_swapped","Dmass","Dgen==23344","2.66666667");// this is for kstar.
   
   TH1F *h_whole_withcuts_sig = (TH1F*) h1_signal->Clone("h_whole_withcuts_sig");
   h_whole_withcuts_sig->Sumw2();
   h_whole_withcuts_sig->Add(h2_signal);
   h_whole_withcuts_sig->Add(h3_signal);
   h_whole_withcuts_sig->Add(h4_signal);

   TH1F *h_whole_nocuts_sig = (TH1F*) h1_nocut_signal->Clone("h_whole_nocuts_sig");
   h_whole_nocuts_sig->Sumw2();
   h_whole_nocuts_sig->Add(h2_nocut_signal);
   h_whole_nocuts_sig->Add(h3_nocut_signal);
   h_whole_nocuts_sig->Add(h4_nocut_signal);

   TH1F *h_whole_withcuts_swapped = (TH1F*) h1_swapped->Clone("h_whole_withcuts_swapped");
   h_whole_withcuts_swapped->Sumw2();
   h_whole_withcuts_swapped->Add(h2_swapped);
   h_whole_withcuts_swapped->Add(h3_swapped);
   h_whole_withcuts_swapped->Add(h4_swapped);

   TH1F *h_whole_nocuts_swapped = (TH1F*) h1_nocut_swapped->Clone("h_whole_nocuts_swapped");
   h_whole_nocuts_swapped->Sumw2();
   h_whole_nocuts_swapped->Add(h2_nocut_swapped);
   h_whole_nocuts_swapped->Add(h3_nocut_swapped);
   h_whole_nocuts_swapped->Add(h4_nocut_swapped);
 
  h_whole_withcuts_sig->Draw("e");
  /*
   TFile * result = new TFile("Normalized_Dmass_pp_10_20.root","RECREATE");
   h_whole_withcuts_sig->Write();
   h_whole_withcuts_swapped->Write();
   h_whole_nocuts_sig->Write();
   h_whole_nocuts_swapped->Write();
   result->Close();
*/
}
