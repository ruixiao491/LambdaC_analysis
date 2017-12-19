#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TCut.h>
//now this is ready to do the dN/dpt.
void divideBinWidth(TH1* h)
{
	for(int i=1;i<=h->GetNbinsX();i++)
	{
		Float_t contentvalue=h->GetBinContent(i);
		Float_t content_err=h->GetBinError(i);
		contentvalue/=h->GetBinWidth(i);
		content_err/=h->GetBinWidth(i);
		h->SetBinContent(i,contentvalue);
		h->SetBinError(i,content_err);
	}
}
void cal_lambdaCDratio(){
    TFile *f1 = TFile::Open("crosssection.root"); 
	TH1F *h_lambdaCcrossection = (TH1F*) f1->Get("h_crosssection");
    TFile *f2 = TFile::Open("/home/xiao147/private/newchannel_lambda_CtoproduceDntuple/CMSSW_7_5_8_patch3/src/Bfinder/Bfinder/Dntuple/ROOTFile/Dmesonresult/CrossSectionFONLLPPMB.root");
	TH1F *h_Dcrosssection = (TH1F*) f2->Get("hPtSigma");
	const Int_t NBINS = 4;
	Double_t edges[NBINS + 1]={5,6,8,10,20};
	TH1 *hD_samerange = new TH1D("hD_samerange","DD_samerange",NBINS,edges);
	///
	Float_t conten_1=h_Dcrosssection->GetBinContent(h_Dcrosssection->FindBin(5.5));
	Float_t conten_2=h_Dcrosssection->GetBinContent(5);
	Float_t conten_3=h_Dcrosssection->GetBinContent(6);
	Float_t conten_4=h_Dcrosssection->GetBinContent(7);
	Float_t conten_5=h_Dcrosssection->GetBinContent(8);
	Float_t conten_6=h_Dcrosssection->GetBinContent(9);
	Float_t bin1=h_Dcrosssection->GetBinWidth(4);
	Float_t bin2=h_Dcrosssection->GetBinWidth(5);
	Float_t bin3=h_Dcrosssection->GetBinWidth(6);
	Float_t bin4=h_Dcrosssection->GetBinWidth(7);
	Float_t bin5=h_Dcrosssection->GetBinWidth(8);
	Float_t bin6=h_Dcrosssection->GetBinWidth(9);
	Float_t error_old1=h_Dcrosssection->GetBinError(4);
	Float_t error_old2=h_Dcrosssection->GetBinError(5);
	Float_t error_old3=h_Dcrosssection->GetBinError(6);
	Float_t error_old4=h_Dcrosssection->GetBinError(7);
	Float_t error_old5=h_Dcrosssection->GetBinError(8);
	Float_t error_old6=h_Dcrosssection->GetBinError(9);
    Float_t contentvalue1=conten_1*bin1; //5-6
	Float_t contentvalue2=conten_2*bin2;  //6-8
	Float_t contentvalue3=conten_3*bin3;  //8-10
	Float_t contentvalue4=conten_4*bin4+conten_5*bin5+conten_6*bin6; //10-20
	Float_t error1=error_old1*bin1;
	Float_t error2=error_old2*bin2;
	Float_t error3=error_old3*bin3;
	Float_t error4=error_old4*bin4+error_old5*bin5+error_old6*bin6;
	hD_samerange->SetBinContent(1,contentvalue1);
	hD_samerange->SetBinContent(2,contentvalue2);
	hD_samerange->SetBinContent(3,contentvalue3);
	hD_samerange->SetBinContent(4,contentvalue4);
	hD_samerange->SetBinError(1,error1);
	hD_samerange->SetBinError(2,error2);
	hD_samerange->SetBinError(3,error3);
	hD_samerange->SetBinError(4,error4);
    hD_samerange->Scale(1./1000000);
	hD_samerange->Sumw2();
///
    divideBinWidth(hD_samerange);

    //for ratio
	h_lambdaCcrossection->Divide(hD_samerange);


	

	TCanvas *c1 = new TCanvas("c1","c1");
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	h_lambdaCcrossection->SetMarkerSize(1.5);
	h_lambdaCcrossection->SetMarkerStyle(20);
	h_lambdaCcrossection->SetMarkerColor(2);
    h_lambdaCcrossection->GetXaxis()->CenterTitle();
	h_lambdaCcrossection->GetYaxis()->CenterTitle();
	h_lambdaCcrossection->GetXaxis()->SetTitleOffset(1.0);
    h_lambdaCcrossection->GetYaxis()->SetTitleOffset(1.0);
	h_lambdaCcrossection->GetXaxis()->SetLabelOffset(0.007);
	h_lambdaCcrossection->GetYaxis()->SetLabelOffset(0.007);
	h_lambdaCcrossection->GetXaxis()->SetTitleSize(0.045);
	h_lambdaCcrossection->GetYaxis()->SetTitleSize(0.045);
	h_lambdaCcrossection->GetXaxis()->SetTitleFont(42);
	h_lambdaCcrossection->GetYaxis()->SetTitleFont(42);
	h_lambdaCcrossection->GetXaxis()->SetLabelFont(42);
    h_lambdaCcrossection->GetYaxis()->SetLabelFont(42);
	h_lambdaCcrossection->GetXaxis()->SetLabelSize(0.04);
	h_lambdaCcrossection->GetYaxis()->SetLabelSize(0.04);
	h_lambdaCcrossection->GetXaxis()->SetTitle("P_{T} (GeV/c)");
	h_lambdaCcrossection->GetYaxis()->SetTitle("#Lambda_{C}^{+} / D^{0} (|y_{#Lambda_{C}}|<1)");
	h_lambdaCcrossection->SetLineColor(2);
    h_lambdaCcrossection->SetAxisRange(0,1,"Y");
	h_lambdaCcrossection->Draw("e");
	c1->SaveAs("lambdaC_Dratio_pp.gif");	
	TFile * result = new TFile("ratio_pp.root","RECREATE");
	h_lambdaCcrossection->Write();
	result->Close();

}
