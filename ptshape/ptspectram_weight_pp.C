#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TCut.h>
//now this is ready to do the reconstruction efficiency with TMVA cuts.
void ptspectram_weight_pp(){
	TFile *f = TFile::Open("crosssection.root");
    TH1 *h_crosssection = (TH1*) f->Get("h_crosssection");
	
	TCanvas *c1 = new TCanvas("c1","c1");
/*	
    Float_t content1=h_crosssection->GetBinContent(h_crosssection->FindBin(5.5));
	cout<<"content1"<<content1<<endl;
	Float_t err1=h_crosssection->GetBinError(h_crosssection->FindBin(5.5));
	Float_t content4=h_crosssection->GetBinContent(h_crosssection->FindBin(15));
	Float_t err4=h_crosssection->GetBinError(h_crosssection->FindBin(15));
	Float_t newcontent1= content1-err1;
	Float_t newcontent4= content4+err4;
	h_crosssection->SetBinContent(1,newcontent1);
	h_crosssection->SetBinError(1,err1);
	h_crosssection->SetBinContent(4,newcontent4);
	h_crosssection->SetBinError(4,err4);
*/
	h_crosssection->Draw("e");
	TF1 *f1 = new TF1("f1","[0]/(1+[1]*x^[2])+[3]",5,20);
	f1->SetParameter(0,6.10959e+05);
	f1->SetParameter(1,0.5);
	f1->SetParameter(2,6);
	h_crosssection->Fit("f1","","",5,20);
	//h_crosssection->Fit("f1","","",5,20);
    f1->Draw("same");

	cout<<"f1"<<f1->Eval(20)<<endl;
    



	c1->SaveAs("central_ptspectrafit_weight.gif");
	TFile *result = new TFile("ptspectrum_centra.root","RECREATE");
	h_crosssection->Write();
	f1->Write();
	result->Close();

}
