#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TCut.h>
//now this is ready to do the reconstruction efficiency.
void twofunc_weight_fromdata(){
	TFile *f1 = TFile::Open("ptspectrum_updown.root");//updown
	TFile *f2 = TFile::Open("ptspectrum_centra.root");//downu[


	TF1  *f_updown = (TF1*) f1->Get("f1");
	TF1  *f_downup = (TF1*) f2->Get("f1");

    TF1 *f_1 = new TF1("f_1","[0]/(1+[1]*x^[2])+[3]",5,20);
	TF1 *f_2 = new TF1("f_2","[0]/(1+[1]*x^[2])+[3]",5,20);
	/*
	f_1->SetParameter(0,f_updown->GetParameter(0));
	f_1->SetParameter(1,f_updown->GetParameter(1));
	f_1->SetParameter(2,f_updown->GetParameter(2));
	f_1->SetParameter(3,f_updown->GetParameter(3));
	f_2->SetParameter(0,f_downup->GetParameter(0));
	f_2->SetParameter(1,f_downup->GetParameter(1));
	f_2->SetParameter(2,f_downup->GetParameter(2));
	f_2->SetParameter(3,f_downup->GetParameter(3));
   */

	f_1->SetParameter(0,f_updown->GetParameter(0));
	f_1->SetParameter(1,f_updown->GetParameter(1));
	f_1->SetParameter(2,f_updown->GetParameter(2));
	f_1->SetParameter(3,f_updown->GetParameter(3));
	f_2->SetParameter(0,f_downup->GetParameter(0));
	f_2->SetParameter(1,f_downup->GetParameter(1));
	f_2->SetParameter(2,f_downup->GetParameter(2));
	f_2->SetParameter(3,f_downup->GetParameter(3));


    f_1->SetLineColor(3);
	f_2->SetLineColor(9);
	f_updown->SetLineColor(4);
	f_downup->SetLineColor(5);
	f_1->Draw();
	f_2->Draw("same");
	f_updown->Draw("same");
	f_downup->Draw("same");
	//cout<<"f_1"<<f_1->Eval(20)<<endl;
	//cout<<"f_2"<<f_2->Eval(20)<<endl;
	TF1 *weight_twofunction =new TF1("weight_twofunction","f_1/f_2",5,20);
	//weight_twofunction->Draw();
	cout<<"a"<<weight_twofunction->Eval(5)<<endl;	
	cout<<"b"<<weight_twofunction->Eval(20)<<endl;
	TFile *result = new TFile("weight_2functions_updown_centra.root","RECREATE");
	weight_twofunction->Write();
	result->Close();

}
