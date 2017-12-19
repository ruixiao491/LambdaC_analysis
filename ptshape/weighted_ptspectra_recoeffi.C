#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TCut.h>
#include <TLatex.h>
void weighted_ptspectra_recoeffi(){
	//TFile *f1 = TFile::Open("/scratch/hammer/x/xiao147/MC_reconefficiency/recoeffi_pkpi.root");//for pt5 and pp cuts
	//TFile *f2 = TFile::Open("/scratch/hammer/x/xiao147/MC_reconefficiency/recoeffi_lambda1520.root");
	//TFile *f3 = TFile::Open("/scratch/hammer/x/xiao147/MC_reconefficiency/recoeffi_deltaplusplus.root");
	//TFile *f4 = TFile::Open("/scratch/hammer/x/xiao147/MC_reconefficiency/recoeffi_kstar.root");
/*
	TFile * f1 = TFile::Open("/scratch/hammer/x/xiao147/MC_recoeffi_PbPbcuts_pt10/recoeffi_pkpi_pt10.root");  //PbPb cuts only have pt >10
	TFile * f2 = TFile::Open("/scratch/hammer/x/xiao147/MC_recoeffi_PbPbcuts_pt10/recoeffi_lambda1520_pt10.root");  //PbPb cuts
	TFile * f3 = TFile::Open("/scratch/hammer/x/xiao147/MC_recoeffi_PbPbcuts_pt10/recoeffi_delta_pt10.root");   //PbPb cuts
	TFile * f4 = TFile::Open("/scratch/hammer/x/xiao147/MC_recoeffi_PbPbcuts_pt10/recoeffi_kstar_pt10.root");   //PbPb cuts

*/
/*
	TFile * f1 = TFile::Open("/scratch/hammer/x/xiao147/MC_reconeffi_pt5and10/PbPbcuts/recoeffi_pkpi_PbPbcuts_pt5and10.root");
	TFile * f2 = TFile::Open("/scratch/hammer/x/xiao147/MC_reconeffi_pt5and10/PbPbcuts/recoeffi_lambda1520_PbPbcuts_pt5and10.root");
	TFile * f3 = TFile::Open("/scratch/hammer/x/xiao147/MC_reconeffi_pt5and10/PbPbcuts/recoeffi_delta_PbPbcuts_pt5and10.root");
	TFile * f4 = TFile::Open("/scratch/hammer/x/xiao147/MC_reconeffi_pt5and10/PbPbcuts/recoeffi_kstar_PbPbcuts_pt5and10.root");
*/
//////////The following is for PbPb TMVA cut reco efficiency///////
/*    
	TFile * f1 = TFile::Open("/scratch/hammer/x/xiao147/MC_withTMVAcuts_recoeffi/PbPb_withTMVA_Recoeffi/recoeffi_pkpi_PbPbcuts_pt5and10_TMVAcuts.root");
	TFile * f2 = TFile::Open("/scratch/hammer/x/xiao147/MC_withTMVAcuts_recoeffi/PbPb_withTMVA_Recoeffi/recoeffi_lambda1520_PbPbcuts_pt5and10_TMVAcuts.root");
	TFile * f3 = TFile::Open("/scratch/hammer/x/xiao147/MC_withTMVAcuts_recoeffi/PbPb_withTMVA_Recoeffi/recoeffi_delta_PbPbcuts_pt5and10_TMVAcuts.root");
	TFile * f4 = TFile::Open("/scratch/hammer/x/xiao147/MC_withTMVAcuts_recoeffi/PbPb_withTMVA_Recoeffi/recoeffi_kstar_PbPbcuts_pt5and10_TMVAcuts.root");
*/
/*

	///The following is for pp TMVA cut reco efficiency/////////
	TFile * f1 = TFile::Open("/scratch/hammer/x/xiao147/MC_withTMVAcuts_recoeffi/pp_withTMVA_Recoeffi/recoeffi_pkpi_pp_TMVAcuts.root");
	TFile * f2 = TFile::Open("/scratch/hammer/x/xiao147/MC_withTMVAcuts_recoeffi/pp_withTMVA_Recoeffi/recoeffi_lambda1520_pp_TMVAcuts.root");
	TFile * f3 = TFile::Open("/scratch/hammer/x/xiao147/MC_withTMVAcuts_recoeffi/pp_withTMVA_Recoeffi/recoeffi_delta_pp_TMVAcuts.root");
	TFile * f4 = TFile::Open("/scratch/hammer/x/xiao147/MC_withTMVAcuts_recoeffi/pp_withTMVA_Recoeffi/recoeffi_kstar_pp_TMVAcuts.root");
*/
//////////////////////
/*
	TFile * f1 = TFile::Open("recoeffi_pkpi_ppcuts_TMVAcuts_fun1.root");
	TFile * f2 = TFile::Open("recoeffi_lambda1520_ppcuts_TMVAcuts_fun1.root");
	TFile * f3 = TFile::Open("recoeffi_delta_ppcuts_TMVAcuts_fun1.root");
	TFile * f4 = TFile::Open("recoeffi_kstar_ppcuts_TMVAcuts_fun1.root");
*/

	TFile * f1 = TFile::Open("recoeffi_pkpi_PbPbcuts_TMVAcuts_fun1_updown_cent.root");
	TFile * f2 = TFile::Open("recoeffi_lambda1520_PbPbcuts_TMVAcuts_fun1_updown_cent.root");
	TFile * f3 = TFile::Open("recoeffi_delta_PbPbcuts_TMVAcuts_fun1_updown_cent.root");
	TFile * f4 = TFile::Open("recoeffi_kstar_PbPbcuts_TMVAcuts_fun1_updown_cent.root");


	TH1F *hrecoeffi_pkpi = (TH1F*) f1->Get("hrecoeffi_fun1");
	TH1F *hrecoeffi_lambda1520 = (TH1F*) f2->Get("hrecoeffi_fun1");
	TH1F *hrecoeffi_delta = (TH1F*) f3->Get("hrecoeffi_fun1");
	TH1F *hrecoeffi_kstar = (TH1F*) f4->Get("hrecoeffi_fun1");

	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	double BR_pkpi =0.035;
	double BR_lambda1520 =0.00495;
	double BR_delta =0.0109 ;
	double BR_kstar =0.0132;
	double sum=BR_pkpi+BR_lambda1520+BR_delta+BR_kstar;
	double weight_pkpi=BR_pkpi/sum;
	double weight_lambda1520=BR_lambda1520/sum;
	double weight_delta=BR_delta/sum;
	double weight_kstar=BR_kstar/sum;
	TCanvas *c1 = new TCanvas("c1","c1");

    hrecoeffi_pkpi->Scale(weight_pkpi);
	hrecoeffi_pkpi->Sumw2();
	hrecoeffi_lambda1520->Scale(weight_lambda1520);
	hrecoeffi_lambda1520->Sumw2();
	hrecoeffi_delta->Scale(weight_delta);
	hrecoeffi_delta->Sumw2();
	hrecoeffi_kstar->Scale(weight_kstar);
	hrecoeffi_kstar->Sumw2();

	TH1F *hrecoeffi_weighted = (TH1F*)hrecoeffi_pkpi->Clone("hrecoeffi_weighted");
	hrecoeffi_weighted->Add(hrecoeffi_lambda1520);
	hrecoeffi_weighted->Sumw2();
	hrecoeffi_weighted->Add(hrecoeffi_delta);
	hrecoeffi_weighted->Sumw2();
	hrecoeffi_weighted->Add(hrecoeffi_kstar);
	hrecoeffi_weighted->Sumw2();
	hrecoeffi_weighted->SetMarkerSize(1.5);
	hrecoeffi_weighted->SetMarkerColor(2);
	hrecoeffi_weighted->SetMarkerStyle(20);
	hrecoeffi_weighted->SetLineColor(2);
  	hrecoeffi_weighted->GetXaxis()->CenterTitle();
	hrecoeffi_weighted->GetYaxis()->CenterTitle();
	hrecoeffi_weighted->GetXaxis()->SetTitleOffset(1.0);
	hrecoeffi_weighted->GetYaxis()->SetTitleOffset(1.2);
	hrecoeffi_weighted->GetXaxis()->SetLabelOffset(0.007);
	hrecoeffi_weighted->GetYaxis()->SetLabelOffset(0.007);
	hrecoeffi_weighted->GetXaxis()->SetTitleSize(0.045);
	hrecoeffi_weighted->GetYaxis()->SetTitleSize(0.045);
	hrecoeffi_weighted->GetXaxis()->SetTitleFont(42);
	hrecoeffi_weighted->GetYaxis()->SetTitleFont(42);
	hrecoeffi_weighted->GetXaxis()->SetLabelFont(42);
	hrecoeffi_weighted->GetYaxis()->SetLabelFont(42);
	hrecoeffi_weighted->GetXaxis()->SetLabelSize(0.04);
	hrecoeffi_weighted->GetYaxis()->SetLabelSize(0.04);
	hrecoeffi_weighted->GetXaxis()->SetTitle("P_{T} (GeV)");
	hrecoeffi_weighted->GetYaxis()->SetTitle("accp#times eff(reco)");
	hrecoeffi_weighted->SetAxisRange(0,1,"Y");
	hrecoeffi_weighted->Draw("e");
    
	///here want to compare with the previous result.
	TFile * f_old = TFile::Open("recoeffi_weighted.root");
	TH1F *weight_old = (TH1F*) f_old->Get("hrecoeffi_weighted");
    weight_old->SetMarkerSize(1.5);
	weight_old->SetMarkerColor(3);
	weight_old->SetLineColor(3);
	weight_old->SetMarkerStyle(20);
//	weight_old->Draw("esame");
	cout<<"2= "<<hrecoeffi_weighted->GetBinContent(2)<<" 3= "<<hrecoeffi_weighted->GetBinContent(3)<<" 4= "<<hrecoeffi_weighted->GetBinContent(4)<<endl;
	
	//TLatex Tl;
	//Tl.SetNDC();
	//Tl.SetTextAlign(12);
	//Tl.SetTextSize(0.05);
	//Tl.SetTextFont(42);
	//Tl.DrawLatex(0.18,0.92, "#font[61]{PbPb cuts}");
	

  //c1->SaveAs("weightedreco.gif");//pp cuts
	c1->SaveAs("weighted_ptspectra_PbPbcuts_withTMVAcuts_updown.gif");
	TFile * result = new TFile("recoeffi_weighted_PbPbcuts_ptspectra_withTMVAcuts_updown.root","RECREATE");
	hrecoeffi_weighted->Write();
	result->Close();

}
