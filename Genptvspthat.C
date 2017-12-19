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
void Genptvspthat(){
    //TFile*f = TFile::Open("/scratch/hammer/x/xiao147/Dntuple_lambdaC_pkpi_delta_pthattest_whole.root");
    TFile*f = TFile::Open("/scratch/hammer/x/xiao147/Dntuple_lambdaC_pkpi_lambda1520_whole.root");
	//TFile*f = TFile::Open("oo.root");
    //TFile*f = TFile::Open("/scratch/hammer/x/xiao147/Dntuple_lambdaC_pkpi_kstar_pthattest_whole.root");
    //f->ls();
    TTree *ntGen = (TTree *) f->Get("ntGen");
    TTree *ntHi = (TTree *) f->Get("ntHi");

    TNtuple* nt = new TNtuple("nt", "", "gpt:pthat:pid:size");
    //ntHi->Show(0);
    float Gpt[MAX_XB];
    float pthat;
    int GpdgId[MAX_XB];
    int Gsize;
    //cout<<"c"<<endl;
    ntGen->SetBranchAddress("Gpt",Gpt);
    //cout<<"b"<<endl;
    ntHi->SetBranchAddress("pthat",&pthat);
    ntGen->SetBranchAddress("GpdgId",GpdgId);
    ntGen->SetBranchAddress("Gsize",&Gsize);
    //cout<<"a"<<endl;
    cout<<"entry"<<ntGen->GetEntries()<<endl;
    for (int entry = 0; entry < ntGen->GetEntries(); entry++)
    {
        ntGen->GetEntry(entry);
        ntHi->GetEntry(entry);
        for (int icand = 0; icand < Gsize; icand++ )
        {
            //	 cout<<"entry"<<entry;
            //cout<<"pthat"<<pthat<<"Gpt"<<Gpt[icand]<<endl;
            //if (Gpt[icand]>10&& abs(GpdgId[icand])==4122)
            //{
            //    h1->Fill(pthat,Gpt[icand]); 
            //}

            nt->Fill(Gpt[icand], pthat, GpdgId[icand], Gsize);
        }
    }
    //h1->SetMarkerStyle(kFullCircle);
    //h1->Draw("");
    //gPad->SetLogz();
    //h1->GetXaxis()->SetTitle("pthat");
    //h1->GetYaxis()->SetTitle("Gpt");

    TFile* result = new TFile("result.root", "RECREATE");
    nt->Write();
    result->Close();
}
