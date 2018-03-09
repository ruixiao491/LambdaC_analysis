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
void toyMC(){
	TFile *f_2 = new TFile("/home/xiao147/private/newchannel_lambda_CtoproduceDntuple/CMSSW_7_5_8_patch3/src/Bfinder/Bfinder/Dntuple/TMVA_official_MC/signal_exaction/ROOT_signalextraction_witheventselection/2gaus_fit_MC/changefit_option/pp/pp_10_20_TMVA_changefit_L_2gaus_fit.root");
	TF1 *f_signal = new TF1 ("f_signal","0.007*[0]*([3]*TMath::Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[3])*TMath::Gaus(x,[1],[4])/(sqrt(2*3.14159)*[4]))",2.1,2.45);
	TFile* outf = TFile::Open("test_histogram_fit_withL.root","recreate");
	TNtuple *nt =new TNtuple("nt","fit_goodness","signal_number");
	TF1 *f_pol2 = new TF1 ("f_pol2","pol2",2.1,2.45);
	TF1 *fit_fun = (TF1*) f_2->Get("f3");
	f_pol2->SetParameter(0,-4.129462e+04);
	f_pol2->SetParameter(1,4.224655e+04);
	f_pol2->SetParameter(2,-9.916298e+03);
	f_signal->SetParameter(0,9.578706e+02);
	f_signal->SetParameter(1,2.288447e+00);
	f_signal->SetParameter(2,6.240261e-03);
	f_signal->SetParameter(3,6.339557e-01);
	f_signal->SetParameter(4,1.699704e-02);
	//TH1F *h1 = new TH1F("h1","h1",50,2.1,2.45);
	TH1F *h_signal =  new TH1F("h_signal","h_signal",50,2.1,2.45);
	TH1F *h_background = new TH1F("h_background","h_background",50,2.1,2.45);
	//h1->Sumw2();
	h_signal->Sumw2();
	h_background->Sumw2();
	h_signal->SetAxisRange(2.2,2.4);
	h_background->SetAxisRange(2.2,2.4);
	//h1->SetAxisRange(2.2,2.4);
	TCanvas *c1 = new TCanvas("c1","c1",600,600);
	//double ratio = 959./9.759152e+04;
	float nt_array[70000];
	double ratio = 959./1.705587e+05;
	double b;
	cout<<"ratio"<<ratio<<endl;
	for (int j=0; j<5000; j++)
	{
	    TH1F *h1 = new TH1F("h1","h1",50,2.1,2.45);
		h1->Sumw2();
		h1->SetAxisRange(2.2,2.4);
		for (int i=0; i < 1.705587e+05; i++)
		{
			double a = gRandom->Rndm(i);
			if (a<= ratio)
			{
				b = f_signal->GetRandom();
			//	h_signal->Fill(b);
			}
			else if (a>ratio)
			{
				b = f_pol2->GetRandom();
			//	h_background->Fill(b);
			}
			h1->Fill(b);
		}//i


		cout<<" initial histogram yield" <<h1->Integral()<<endl;
		h1->SetLineColor(9);
		h1->Draw("e");
		TF1 *f1=new TF1("f1","pol2",2.1,2.45);
		TF1 *f2=new TF1("f2","0.007*[0]*([3]*TMath::Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[3])*TMath::Gaus(x,[1],[4])/(sqrt(2*3.14159)*[4]))",2.1,2.45);
		TF1 *f3=new TF1("f3","0.007*[0]*([3]*TMath::Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[3])*TMath::Gaus(x,[1],[4])/(sqrt(2*3.14159)*[4]))+pol2(5)",2.1,2.45);
		f3->SetParNames("Strength","Mean1","Sigma1","pro1","Sigma2","back1","back2","back3");
		Double_t par[8];
		f3->SetParameter(0,1000);
		f3->SetParameter(1,fit_fun->GetParameter(1));
		f3->FixParameter(2,fit_fun->GetParameter(2));
		f3->FixParameter(3,fit_fun->GetParameter(3));
		f3->FixParameter(4,fit_fun->GetParameter(4));
		h1->Fit("f3","IL","",2.26,2.3);
		h1->Fit("f3","IL","",2.24,2.33);
		h1->Fit("f3","IL","",2.22,2.36);
		h1->Fit("f3","IL","",2.21,2.39);
		h1->Fit("f3","IL","",2.2,2.4);
		h1->Fit("f3","IL","",2.2,2.4);
		f3->GetParameters(par);
		f2->SetParameters(&par[0]);
		f1->SetParameters(&par[5]);
		h1->SetAxisRange(2.2,2.4);
		f1->Draw("same");
		f2->Draw("same");
		f3->Draw("same");
		cout<<"fit: "<<f3->GetParameter(0)<<endl;
		nt_array[0] = f3->GetParameter(0);
		nt->Fill(nt_array);
	}//j

nt->Write();
outf->Write();
cout<<"--writing finished"<<endl;
outf->Close();
return 0;
}
