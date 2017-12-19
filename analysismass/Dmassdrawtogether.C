#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <TH2D.h>
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
#include <TLegend.h>
void Dmassdrawtogether(){
TFile *f1=new TFile("outputfile.root");
TFile *f2=new TFile("outputfile_Weipvrefit.root");
TH1F *h1 = (TH1F*) f1->Get("hmass");
TH1F *h2 = (TH1F*) f2->Get("hmass");
//here I will add several lines to do normalization.
double a=h1->Integral();
double b=h2->Integral();
double s=b/a;
cout<<"s"<<s<<endl;
h1->Scale(s);



h1->Draw("E");
h1->SetMarkerColor(2);
h1->SetMarkerStyle(24);
h2->Draw("esame");
h2->SetMarkerColor(3);
h2->SetMarkerStyle(30);
leg = new TLegend(0.1,0.7,0.48,0.9);
leg->SetHeader("normalized lambda_C mass");
leg->AddEntry(h1,"withoutPVrefit","lep");
leg->AddEntry(h2,"withPVrefit","lep");
leg->Draw();
}
