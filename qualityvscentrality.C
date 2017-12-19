#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <TH2D.h>
#include <TMath.h>
#include <TF2.h>
#include <TNamed.h>
#include <TNtuple.h>
#include <TTree.h>
#include <TMath.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TLatex.h>
#define MAX_XB       20000
using namespace std;
void qualityvscentrality(){
TFile*f = TFile::Open("/scratch/hammer/x/xiao147/Dntuple_lambdaCpkpi_whole_withPVerr.root");
//f->ls();
TTree * ntlambdaCtopkpi = (TTree *) f->Get("ntlambdaCtopkpi");
TTree *ntHi = (TTree *) f->Get("ntHi");
TH2 *h1 = new TH2F("h1","PVxE vs hiBin",200,0,200,250,0,0.01);
//ntHi->Show(0);
float PVxE;
int hiBin;
cout<<"c"<<endl;
ntlambdaCtopkpi->SetBranchAddress("PVxE",&PVxE);
cout<<"b"<<endl;
ntHi->SetBranchAddress("hiBin",&hiBin);
cout<<"a"<<endl;
//for (int entry = 0; entry < ntlambdaCtopkpi->GetEntries(); entry++)
for (int entry = 0; entry < 1000; entry++)
{
     ntlambdaCtopkpi->GetEntry(entry);
     ntHi->GetEntry(entry);
     h1->Fill(hiBin,PVxE);    
}
h1->Draw("colz");
gPad->SetLogz();
h1->GetXaxis()->SetTitle("hiBin");
h1->GetYaxis()->SetTitle("PVxE");

}
