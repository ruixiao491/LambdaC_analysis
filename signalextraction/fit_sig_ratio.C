#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TCut.h>
//now this is ready to do the reconstruction efficiency.
void fit_sig_ratio(){
	
	TFile *f1 = TFile::Open("pp5_6_2gaus_1mean_halfbinwidth.root");
	TFile *f2 = TFile::Open("pp6_8_2gaus_1mean_halfbinwidth.root");
	TFile *f3 = TFile::Open("pp8_10_2gaus_1mean_halfbinwidth.root");
	TFile *f4 = TFile::Open("pp10_20_2gaus_1mean_halfbinwidth.root");
	/*

	TFile *f1 = TFile::Open("pp5_6_2gaus_1mean.root");
	TFile *f2 = TFile::Open("pp6_8_2gaus_1mean.root");
	TFile *f3 = TFile::Open("pp8_10_2gaus_1mean.root");
	TFile *f4 = TFile::Open("pp10_20_2gaus_1mean.root");
*/
/*
	TFile *f1 = TFile::Open("5_6pp_singalgaus.root");
	TFile *f2 = TFile::Open("6_8pp_singalgaus.root");
	TFile *f3 = TFile::Open("8_10pp_singalgaus.root");
	TFile *f4 = TFile::Open("10_20pp_singalgaus.root");

*/
 	TH1F *h5_6 = (TH1F*)f1->Get("h_whole_withcuts_sig");
	TH1F *h6_8 = (TH1F*)f2->Get("h_whole_withcuts_sig");
	TH1F *h8_10 = (TH1F*)f3->Get("h_whole_withcuts_sig");
	TH1F *h10_20 = (TH1F*)f4->Get("h_whole_withcuts_sig");
	TF1 * f5_6 =(TF1*)f1->Get("f3");
	TF1 * f6_8 =(TF1*)f2->Get("f3");
	TF1 * f8_10 =(TF1*)f3->Get("f3");
	TF1 * f10_20 = (TF1*)f4->Get("f3");

	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	const Int_t NBINS = 4;
	Double_t edges[NBINS + 1]={5,6,8,10,20};
	TH1 *hfit_sig_ratio = new TH1D("hfit_sig_ratio","ratio",NBINS,edges);
    hfit_sig_ratio->Sumw2();	
	TCanvas *c1 = new TCanvas("c1","c1");

	double fit_5_6 = f5_6->GetParameter(0);
    //cout<<"fit"<<fit_5_6<<endl;	
	double fit_6_8 = f6_8->GetParameter(0);
	double fit_8_10 = f8_10->GetParameter(0);
	double fit_10_20 = f10_20->GetParameter(0);

	double true1 = h5_6->GetEntries();
	double true2 = h6_8->GetEntries();
	double true3 = h8_10->GetEntries();
	double true4 = h10_20->GetEntries();

	double cont1 = fit_5_6/true1;
	double cont2 = fit_6_8/true2;
	double cont3 = fit_8_10/true3;
	double cont4 = fit_10_20/true4;

	double fit_5_6_err = f5_6->GetParError(0);
    double fit_6_8_err = f6_8->GetParError(0);
	double fit_8_10_err = f8_10->GetParError(0);
	double fit_10_20_err = f10_20->GetParError(0);

	double err1 = fit_5_6_err/true1;
	double err2 = fit_6_8_err/true2;
	double err3 = fit_8_10_err/true3;
	double err4 = fit_10_20_err/true4;



	hfit_sig_ratio->SetBinContent(1,cont1);
	hfit_sig_ratio->SetBinContent(2,cont2);
	hfit_sig_ratio->SetBinContent(3,cont3);
	hfit_sig_ratio->SetBinContent(4,cont4);

	hfit_sig_ratio->SetBinError(1,err1);
	hfit_sig_ratio->SetBinError(2,err2);
	hfit_sig_ratio->SetBinError(3,err3);
	hfit_sig_ratio->SetBinError(4,err4);

	hfit_sig_ratio->Sumw2();
	hfit_sig_ratio->SetAxisRange(0,1,"Y");
	hfit_sig_ratio->Draw("e");
	c1->SaveAs("halfbinwidth_fit_sig_ratio.gif");

	
	TFile *result = new TFile("halfbinwidth_fit_sig_ratio_pp.root","RECREATE");
	hfit_sig_ratio->Write();
	result->Close();
}
