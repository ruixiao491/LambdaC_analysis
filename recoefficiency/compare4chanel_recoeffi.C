#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TCut.h>
void compare4chanel_recoeffi(){
	TFile *f1 = TFile::Open("/scratch/hammer/x/xiao147/MC_reconefficiency/recoeffi_pkpi.root");
	TFile *f2 = TFile::Open("/scratch/hammer/x/xiao147/MC_reconefficiency/recoeffi_lambda1520.root");
	TFile *f3 = TFile::Open("/scratch/hammer/x/xiao147/MC_reconefficiency/recoeffi_deltaplusplus.root");
	TFile *f4 = TFile::Open("/scratch/hammer/x/xiao147/MC_reconefficiency/recoeffi_kstar.root");

	TH1F *hrecoeffi_pkpi = (TH1F*) f1->Get("hrecoefficiency");
	TH1F *hrecoeffi_lambda1520 = (TH1F*) f2->Get("hrecoefficiency");
	TH1F *hrecoeffi_delta = (TH1F*) f3->Get("hrecoefficiency");
	TH1F *hrecoeffi_kstar = (TH1F*) f4->Get("hrecoefficiency");
    
	TCanvas *c1 = new TCanvas("c1");
	gStyle->SetOptStat(0);
	gStyle->SetOptTitle(0);
	c1->Divide(2,2);
	c1->cd(1);
	hrecoeffi_pkpi->SetMarkerSize(1.5);
	hrecoeffi_pkpi->SetMarkerStyle(20);
	hrecoeffi_pkpi->SetMarkerColor(2);
	hrecoeffi_pkpi->SetLineColor(2);
	hrecoeffi_pkpi->SetAxisRange(0,1,"Y");
	hrecoeffi_pkpi->Draw("e");
    hrecoeffi_pkpi->GetXaxis()->CenterTitle();
    hrecoeffi_pkpi->GetYaxis()->CenterTitle();
	hrecoeffi_pkpi->GetXaxis()->SetTitleOffset(1.0);
	hrecoeffi_pkpi->GetYaxis()->SetTitleOffset(1.1);
	hrecoeffi_pkpi->GetXaxis()->SetLabelOffset(0.007);
	hrecoeffi_pkpi->GetYaxis()->SetLabelOffset(0.007);
	hrecoeffi_pkpi->GetXaxis()->SetTitleSize(0.05);
	hrecoeffi_pkpi->GetYaxis()->SetTitleSize(0.05);
	hrecoeffi_pkpi->GetXaxis()->SetTitleFont(42);
	hrecoeffi_pkpi->GetYaxis()->SetTitleFont(42);
	hrecoeffi_pkpi->GetXaxis()->SetLabelFont(42);
	hrecoeffi_pkpi->GetYaxis()->SetLabelFont(42);
	hrecoeffi_pkpi->GetXaxis()->SetLabelSize(0.05);
	hrecoeffi_pkpi->GetYaxis()->SetLabelSize(0.05);
	hrecoeffi_pkpi->GetXaxis()->SetTitle("P_{T} (GeV)");
	hrecoeffi_pkpi->GetYaxis()->SetTitle("recon effi");
    hrecoeffi_pkpi->SetTitle("P K #pi");
	TLatex Tl1;
	Tl1.SetNDC();
	Tl1.SetTextAlign(12);
	Tl1.SetTextSize(0.05);
	Tl1.SetTextFont(42);
	Tl1.DrawLatex(0.18,0.965, "#font[61]{P K #pi}");

	c1->cd(2);
	hrecoeffi_lambda1520->SetMarkerSize(1.5);
	hrecoeffi_lambda1520->SetMarkerStyle(20);
	hrecoeffi_lambda1520->SetMarkerColor(2);
	hrecoeffi_lambda1520->SetLineColor(2);
	hrecoeffi_lambda1520->SetAxisRange(0,1,"Y");
	hrecoeffi_lambda1520->Draw("e");
    hrecoeffi_lambda1520->GetXaxis()->CenterTitle();
    hrecoeffi_lambda1520->GetYaxis()->CenterTitle();
	hrecoeffi_lambda1520->GetXaxis()->SetTitleOffset(1.0);
	hrecoeffi_lambda1520->GetYaxis()->SetTitleOffset(1.1);
	hrecoeffi_lambda1520->GetXaxis()->SetLabelOffset(0.007);
	hrecoeffi_lambda1520->GetYaxis()->SetLabelOffset(0.01);
	hrecoeffi_lambda1520->GetXaxis()->SetTitleSize(0.05);
	hrecoeffi_lambda1520->GetYaxis()->SetTitleSize(0.05);
	hrecoeffi_lambda1520->GetXaxis()->SetTitleFont(42);
	hrecoeffi_lambda1520->GetYaxis()->SetTitleFont(42);
	hrecoeffi_lambda1520->GetXaxis()->SetLabelFont(42);
	hrecoeffi_lambda1520->GetYaxis()->SetLabelFont(42);
	hrecoeffi_lambda1520->GetXaxis()->SetLabelSize(0.05);
	hrecoeffi_lambda1520->GetYaxis()->SetLabelSize(0.05);
	hrecoeffi_lambda1520->GetXaxis()->SetTitle("P_{T} (GeV)");
	hrecoeffi_lambda1520->GetYaxis()->SetTitle("recon effi ");
	hrecoeffi_lambda1520->SetTitle("#Lambda(1520)");
	TLatex Tl2;
	Tl2.SetNDC();
	Tl2.SetTextAlign(12);
	Tl2.SetTextSize(0.05);
	Tl2.SetTextFont(42);
	Tl2.DrawLatex(0.18,0.965, "#font[61]{#Lambda(1520)}");
	c1->cd(3);
	hrecoeffi_delta->SetMarkerSize(1.5);
	hrecoeffi_delta->SetMarkerStyle(20);
	hrecoeffi_delta->SetMarkerColor(2);
	hrecoeffi_delta->SetLineColor(2);
	hrecoeffi_delta->SetAxisRange(0,1,"Y");
	hrecoeffi_delta->Draw("e");
    hrecoeffi_delta->GetXaxis()->CenterTitle();
    hrecoeffi_delta->GetYaxis()->CenterTitle();
	hrecoeffi_delta->GetXaxis()->SetTitleOffset(1.0);
	hrecoeffi_delta->GetYaxis()->SetTitleOffset(1.1);
	hrecoeffi_delta->GetXaxis()->SetLabelOffset(0.007);
	hrecoeffi_delta->GetYaxis()->SetLabelOffset(0.007);
	hrecoeffi_delta->GetXaxis()->SetTitleSize(0.05);
	hrecoeffi_delta->GetYaxis()->SetTitleSize(0.05);
	hrecoeffi_delta->GetXaxis()->SetTitleFont(42);
	hrecoeffi_delta->GetYaxis()->SetTitleFont(42);
	hrecoeffi_delta->GetXaxis()->SetLabelFont(42);
	hrecoeffi_delta->GetYaxis()->SetLabelFont(42);
	hrecoeffi_delta->GetXaxis()->SetLabelSize(0.05);
	hrecoeffi_delta->GetYaxis()->SetLabelSize(0.05);
	hrecoeffi_delta->GetXaxis()->SetTitle("P_{T} (GeV)");
	hrecoeffi_delta->GetYaxis()->SetTitle("recon effi");
    //hrecoeffi_delta->SetTitle("#Delta++");
	TLatex Tl3;
	Tl3.SetNDC();
	Tl3.SetTextAlign(12);
	Tl3.SetTextSize(0.05);
	Tl3.SetTextFont(42);
	Tl3.DrawLatex(0.18,0.965, "#font[61]{#Delta++}");

	c1->cd(4);
	hrecoeffi_kstar->SetAxisRange(0,1,"Y");
	hrecoeffi_kstar->Draw("e");
	hrecoeffi_kstar->SetMarkerSize(1.5);
	hrecoeffi_kstar->SetMarkerStyle(20);
	hrecoeffi_kstar->SetMarkerColor(2);
	hrecoeffi_kstar->SetLineColor(2);
    hrecoeffi_kstar->GetXaxis()->CenterTitle();
    hrecoeffi_kstar->GetYaxis()->CenterTitle();
	hrecoeffi_kstar->GetXaxis()->SetTitleOffset(1.0);
	hrecoeffi_kstar->GetYaxis()->SetTitleOffset(1.1);
	hrecoeffi_kstar->GetXaxis()->SetLabelOffset(0.007);
	hrecoeffi_kstar->GetYaxis()->SetLabelOffset(0.007);
	hrecoeffi_kstar->GetXaxis()->SetTitleSize(0.05);
	hrecoeffi_kstar->GetYaxis()->SetTitleSize(0.05);
	hrecoeffi_kstar->GetXaxis()->SetTitleFont(42);
	hrecoeffi_kstar->GetYaxis()->SetTitleFont(42);
	hrecoeffi_kstar->GetXaxis()->SetLabelFont(42);
	hrecoeffi_kstar->GetYaxis()->SetLabelFont(42);
	hrecoeffi_kstar->GetXaxis()->SetLabelSize(0.05);
	hrecoeffi_kstar->GetYaxis()->SetLabelSize(0.05);
	hrecoeffi_kstar->GetXaxis()->SetTitle("P_{T} (GeV)");
	hrecoeffi_kstar->GetYaxis()->SetTitle("recon effi");
    hrecoeffi_kstar->SetTitle("K*");
	TLatex Tl4;
	Tl4.SetNDC();
	Tl4.SetTextAlign(12);
	Tl4.SetTextSize(0.05);
	Tl4.SetTextFont(42);
	Tl4.DrawLatex(0.18,0.965, "#font[61]{K*}");
	
	c1->SaveAs("4channel_reco.gif");
}
