#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TCut.h>
#define MAX_XB       20000
//This code is to draw the reco-efficiency vs eta in order to make sure the eta cut.
void recoeffvseta(){
	TFile *f = TFile::Open("/scratch/hammer/x/xiao147/lambda1520_Dntuple_5.root");
	TTree *ntlambdaCtopkpi  = (TTree *) f->Get("ntlambdaCtopkpi");
	TTree *ntGen = (TTree *) f->Get("ntGen");
	ntGen->Show(0);
	TH1F *hDeta = new TH1F("hDeta","Deta",50,-1.5,1.5);
    TH1F *hGeta = new TH1F("hGeta","Geta",50,-1.5,1.5);
    TCanvas *c1 = new TCanvas("c1","c1");

///here I am think about we should apply the Gen level cut for ntGen. But now I have not applied the cuts.
    TCut *MC_cut = new TCut("fabs(Geta)<1.2");
	TCut *data_cut = new TCut("");
   // ntGen->Draw("Geta>>hGeta","Gpt>10");
    ntlambdaCtopkpi->Project("hDeta","Deta","Dgen==23333&&Dpt>10");
	ntGen->Project("hGeta","Geta","Gpt>10&&fabs(Geta)<1.2");
    TH1F *hrecoefficiency = (TH1F*) hDeta->Clone("hrecoefficiency");
	hrecoefficiency->Divide(hGeta);
	hrecoefficiency->Draw();
    //hDeta->Draw();
	//hGeta->Draw();
}
	

