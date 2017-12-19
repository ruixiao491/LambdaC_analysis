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
#define MAX_XB       20000
void Dmass_fit_forpp_PbPbTMVA_test(){
//TFile *f =new TFile("/scratch/halstead/x/xiao147/pkpichanneltuple.root");
//TFile *f = new TFile("/scratch/halstead/x/xiao147/pkpichanneltuple_whole.root");
//TNtuple *nt =(TNtuple *) f->Get("nt");
//TFile*f1 = TFile::Open("/scratch/hammer/x/xiao147/MC_pt4/TMVA_test_2channels.root");
//TTree *ntlambdaCtopkpi = (TTree *) f1->Get("ntlambdaCtopkpi");
//TFile *f =new TFile("/scratch/hammer/x/xiao147/Dntuple_lambdaCpkpi_whole_withPVerr.root");
//TFile *f = new TFile("/scratch/hammer/x/xiao147/Dntuple_lambdaCpkpi_skim2cuts_whole.root");
TFile *f = new TFile("/scratch/halstead/x/xiao147/trackonly_test_1113_shouldbedeletlater/MB9_trackonly_whole.root");
TTree *ntlambdaCtopkpi = (TTree *) f->Get("ntlambdaCtopkpi");
TH1F *h1 = new TH1F("h1","mass",50,2.1,2.45);
TH1F *h2 = new TH1F("h2","mass",50,2.1,2.45);

h1->SetMarkerColor(2);
h1->SetMarkerStyle(24);
TCanvas *c1 = new TCanvas("c1","c1");
//gStyle->SetTitleX(0.9);
gStyle->SetOptTitle(0);
gStyle->SetOptStat(0);
gStyle->SetOptFit(0);
gStyle->SetTitleX(0.8f); //title box x position
gStyle->SetTitleY(0.95);
gStyle->SetTitleW(0.2f);  //Title box width as fraction of pad size.
gStyle->SetTitleFontSize(0.06);


h1->SetTitle("5.02TeV PbPb");
h1->GetXaxis()->CenterTitle();
h1->GetYaxis()->CenterTitle();
h1->GetXaxis()->SetTitleOffset(1.0);
h1->GetYaxis()->SetTitleOffset(1.2);
h1->GetXaxis()->SetLabelOffset(0.007);
h1->GetYaxis()->SetLabelOffset(0.007);
h1->GetXaxis()->SetTitleSize(0.045);
h1->GetYaxis()->SetTitleSize(0.045);
h1->GetXaxis()->SetTitleFont(42);
h1->GetYaxis()->SetTitleFont(42);
h1->GetXaxis()->SetLabelFont(42);
h1->GetYaxis()->SetLabelFont(42);
h1->GetXaxis()->SetLabelSize(0.04);
h1->GetYaxis()->SetLabelSize(0.04);


h1->GetXaxis()->SetTitle("m_{pk#pi} (GeV/c^{2})");
h1->GetYaxis()->SetTitle("Entries");

//The following is the TLatex method which is copied from Jian.
TLatex* tex;
tex = new TLatex(0.20,0.73,"P_{T}>10GeV");
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.04);
tex->SetLineWidth(2);
tex->Draw();

//tex = new TLatex(0.20,0.83,"|y| < 1.0");
//tex->SetNDC();
//tex->SetTextFont(42);
//tex->SetTextSize(0.04);
//tex->SetLineWidth(2);
//tex->Draw();

tex = new TLatex(0.20,0.78,"centrality:30%-100%");
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.04);
tex->SetLineWidth(2);
tex->Draw();

TLatex Tl;
Tl.SetNDC();
Tl.SetTextAlign(12);
Tl.SetTextSize(0.05);
Tl.SetTextFont(42);
Tl.DrawLatex(0.18,0.965, "#font[61]{CMS}");
Tl.DrawLatex(0.61,0.965, "#scale[0.8]{PbPb #sqrt{s_{NN}} = 5.02 TeV}");

//nt->Draw("mass>>h1","dls>2&& pt>6&& pt<8&&chi2>0.1&&abs(Dtrk1Y)<1.2&&abs(Dtrk2Y)<1.2&&abs(Dtrk3Y)<1.2&&alpha<0.10&&mass>2.1&&mass<2.45", "e");
//ntlambdaCtopkpi->Project("h1","Dmass","DsvpvDistance/DsvpvDisErr>3.54057&&Dpt>10&&Dpt<20&&Dchi2cl>0.12007&&Dalpha<0.197842&&Dtrk1Y<1.2163937017051210&&Dtrk1Y>-1.0863461246360331&&Dtrk2Y<1.2000298936645715&&Dtrk2Y>-1.1966406612512390&&Dtrk3Y>-1.2257109331471328&&Dtrk3Y<1.3126434028889937&&Dmass>2.1&&Dmass<2.45"); //fot PbPb 10-20 TMVA
//nt->Project("h1","mass","dls>2.5708297645394071&&pt>5&&pt<6&&chi2>0.041689804&&alpha<0.2&&abs(Dtrk1Y)<1.1403849867506648&&abs(Dtrk2Y)<1.1852549507620627&&abs(Dtrk3Y)<1.4224289435913149&&mass>2.1&&mass<2.45"); //fot pp 5_6 TMVA new
//nt->Project("h1","mass","dls>2.2067712234549575&&pt>6&&pt<8&&chi2>0.15175714&&alpha<0.19986&&abs(Dtrk1Y)<1.2336290243299868&&abs(Dtrk2Y)<1.2763163222867580&&abs(Dtrk3Y)<1.4546841761746760&&mass>2.1&&mass<2.45"); //fot pp 6-8 TMVA new
//nt->Project("h1","mass","dls>2.1268353403086460&&pt>8&&pt<10&&chi2>0.16775795&&alpha<0.18267&&abs(Dtrk1Y)<1.1035199952817765&&abs(Dtrk2Y)<1.1829739338734198&&abs(Dtrk3Y)<1.1285068120553465&&mass>2.1&&mass<2.45"); //fot pp 8-10 TMVA new
//nt->Project("h1","mass","dls>2.2999243868265857&&pt>10&&pt<20&&chi2>0.090253931&&alpha<0.13521&&abs(Dtrk1Y)<1.0726858866575544&&abs(Dtrk2Y)<1.0772992046501422&&abs(Dtrk3Y)<1.3596399860641353&&mass>2.1&&mass<2.45"); //fot pp 10-20 TMVA new
//ntlambdaCtopkpi->Project("h1","Dmass","DsvpvDistance/DsvpvDisErr>2.6081244112321165&&Dpt>20&&Dpt<50&&Dchi2cl>0.062764485108&&Dalpha<0.1681331996183&&abs(Dtrk1Y)<1.0832043213574851&&abs(Dtrk2Y)<1.0535828694671312&&abs(Dtrk3Y)<1.2201823915419&&Dmass>2.1&&Dmass<2.45"); //fot PbPb 20-50 TMVA new
//ntlambdaCtopkpi->Project("h1","Dmass","DsvpvDistance/DsvpvDisErr>3.5922988982679849&&Dpt>10&&Dpt<20&&Dchi2cl>0.142399445018&&Dalpha<0.1968435880070&&abs(Dtrk1Y)<1.1537294705527470e&&abs(Dtrk2Y)<1.2947648618645256&&abs(Dtrk3Y)<1.39956912249644&&Dmass>2.1&&Dmass<2.45"); //fot PbPb 10-20 TMVA new
//ntlambdaCtopkpi->Project("h1","Dmass","DsvpvDistance/DsvpvDisErr>3.7268794321927805&&Dpt>8&&Dpt<10&&Dchi2cl>0.11916161775293807&&Dalpha<0.18056292894936304&&abs(Dtrk1Y)<1.1302324726910804&&abs(Dtrk2Y)<0.95808183193555663&&abs(Dtrk3Y)<1.1772539165325420&&Dmass>2.1&&Dmass<2.45"); //fot PbPb 10-20 TMVA
//ntlambdaCtopkpi->Project("h1","Dmass","DsvpvDistance/DsvpvDisErr>4.0878852050240155&&Dpt>8&&Dpt<10&&Dchi2cl>0.13323969644998118&&Dalpha<0.19438430161181697&&abs(Dtrk1Y)<1.1602584517801346&&abs(Dtrk2Y)<1.2676181158340694&&abs(Dtrk3Y)<1.2530868469923007&&Dmass>2.1&&Dmass<2.45"); //fot PbPb 8-10 TMVA cut 1
//ntlambdaCtopkpi->Project("h1","Dmass","DsvpvDistance/DsvpvDisErr>4.0878852050240155&&Dpt>9&&Dpt<10&&Dchi2cl>0.13323969644998118&&Dalpha<0.19438430161181697&&abs(Dtrk1Y)<1.1602584517801346&&abs(Dtrk2Y)<1.2676181158340694&&abs(Dtrk3Y)<1.2530868469923007&&Dmass>2.1&&Dmass<2.45"); //fot PbPb 9-10 TMVA cut 1
//ntlambdaCtopkpi->Project("h1","Dmass","DsvpvDistance/DsvpvDisErr>3.3332746939062581&&Dpt>20&&Dpt<30&&Dchi2cl>0.108595&&Dalpha<0.0870739&&Dtrk1Y<1.1084859717939577&&Dtrk1Y>-0.95847908372890711&&Dtrk2Y<0.96380885480151857&&Dtrk2Y>-0.99679792913158372&&Dtrk3Y>-1.0388818590591007&&Dtrk3Y<1.1067912419337520&&Dmass>2.1&&Dmass<2.45"); //fot PbPb 10-20 TMVA

//nt->Project("h1","mass","dls>2.385751889575297&&pt>4&&pt<5&&chi2>0.26&&alpha<0.2179&&Dtrk1Y<1.5546881516577449&&Dtrk1Y>-0.52216174367354973&&Dtrk2Y<1.4529470768193127&&Dtrk2Y>-0.887245770515742&&Dtrk3Y<1.391798693601565&&Dtrk3Y>-0.74556397390526941&&mass>2.1&&mass<2.45");//TMVA 4-5 pp

//nt->Project("h1","mass","dls>2.385751889575297&&pt>5&&pt<6&&chi2>0.26&&alpha<0.2179&&Dtrk1Y<1.5546881516577449&&Dtrk1Y>-0.52216174367354973&&Dtrk2Y<1.4529470768193127&&Dtrk2Y>-0.887245770515742&&Dtrk3Y<1.391798693601565&&Dtrk3Y>-0.74556397390526941&&mass>2.1&&mass<2.45");//TMVA 5-6 pp
//nt->Project("h1","mass","dls>2.&&pt>6&&pt<8&&chi2>0.04967&&alpha<0.1964865&&Dtrk1Y<1.0687390422030725&&Dtrk1Y>-1.0510824099341085&&Dtrk2Y<1.3071943895026441&&Dtrk2Y>-1.2942315136099436&&Dtrk3Y<1.6854528601603727&&Dtrk3Y>-1.2636786398904991&&mass>2.1&&mass<2.45");//TMVA 6-8 pp
//nt->Project("h1","mass","dls>1.9896339092179474&&pt>8&&pt<10&&chi2>0.044531&&alpha<0.18846&&Dtrk1Y<1.1411278694138265&&Dtrk1Y>-1.0387668110696671&&Dtrk2Y<1.0984671035886100&&Dtrk2Y>-1.2741580698417918&&Dtrk3Y<1.4199411826735879&&Dtrk3Y>-1.2026087489050470&&mass>2.1&&mass<2.45");//TMVA 8-10 pp
//nt->Project("h1","mass","dls>2.03305&&pt>10&&pt<20&&chi2>0.067054&&alpha<0.1387&&Dtrk1Y<1.261410280145415&&Dtrk1Y>-1.021735909603&&Dtrk2Y<1.1534945942552628&&Dtrk2Y>-1.2250246056325682&&Dtrk3Y<1.2398243626868617&&Dtrk3Y>-1.0747070603239208&&mass>2.1&&mass<2.45");//TMVA 10-20 pp
/////test here the cut are not exact right.
//ntlambdaCtopkpi->Project("h1","Dmass","DsvpvDistance/DsvpvDisErr>3.5922988982679849&&Dpt>15&&Dpt<167&&Dchi2cl>0.142399445018&&Dalpha<0.1968435880070&&abs(Dtrk1Y)<1.1537294705527470e&&abs(Dtrk2Y)<1.2947648618645256&&abs(Dtrk3Y)<1.39956912249644&&Dmass>2.1&&Dmass<2.45"); //fot PbPb 10-20 TMVA new

////////////////the latest TMVA test//////no track y or eta.
//nt->Project("h1","mass","dls>2.0567947541710949&&pt>10&&pt<20&&chi2>0.052311155858355128&&alpha<0.18578151058528442&&abs(Dtrk1Y)<1.2&&abs(Dtrk2Y)<1.2&&abs(Dtrk3Y)<1.2&&mass>2.1&&mass<2.45");//TMVA 10-20 pp latest.
//nt->Project("h1","mass","dls>1.9962837410042045&&pt>8&&pt<10&&chi2>0.045594948264545000&&alpha<0.17552951974295602&&abs(Dtrk1Y)<1.2&&abs(Dtrk2Y)<1.2&&abs(Dtrk3Y)<1.2&&mass>2.1&&mass<2.45");//TMVA 8-10 pp latest.
//nt->Project("h1","mass","dls>2.0553102716912526&&pt>6&&pt<8&&chi2>0.048977854761238913&&alpha<0.17856266296587384&&abs(Dtrk1Y)<1.2&&abs(Dtrk2Y)<1.2&&abs(Dtrk3Y)<1.2&&mass>2.1&&mass<2.45");//TMVA 6-8 pp latest.
//nt->Project("h1","mass","dls>2.6979993536749927&&pt>5&&pt<6&&chi2>0.26705336676903046&&alpha<0.21379631639014482&&abs(Dtrk1Y)<1.2&&abs(Dtrk2Y)<1.2&&abs(Dtrk3Y)<1.2&&mass>2.1&&mass<2.45");//TMVA 5_6 pp latest.
//nt->Project("h1","mass","dls>2.6979993536749927&&pt>5&&pt<6&&chi2>0.26705336676903046&&alpha<0.21379631639014482&&abs(Dtrk1Y)<1.2&&abs(Dtrk2Y)<1.2&&abs(Dtrk3Y)<1.2&&mass>2.1&&mass<2.45");//TMVA 5_6 pp latest.
ntlambdaCtopkpi->Project("h1","Dmass","DsvpvDistance/DsvpvDisErr>3.4469269876124975&&Dpt>10&&Dpt<20&&Dchi2cl>0.086999158864963691&&Dalpha<0.16893408284246497&&abs(Dtrk1Eta)<1.2&&abs(Dtrk2Eta)<1.2&&abs(Dtrk3Eta)<1.2&&Dmass>2.1&&Dmass<2.45");//TMVA 10_20 PbPb latest.
//ntlambdaCtopkpi->Project("h1","Dmass","DsvpvDistance/DsvpvDisErr>2.0568628691246609&&Dpt>9&&Dpt<10&&Dchi2cl>0.11892479442600319&&Dalpha<0.204&&abs(Dtrk1Eta)<1.2&&abs(Dtrk2Eta)<1.2&&abs(Dtrk3Eta)<1.2&&Dmass>2.1&&Dmass<2.45");//TMVA 9_10 PbPb latest.
//ntlambdaCtopkpi->Project("h1","Dmass","DsvpvDistance/DsvpvDisErr>4.6431768574834038&&Dpt>8&&Dpt<10&&Dchi2cl>0.33510841187886442&&Dalpha<0.18851482981605913&&abs(Dtrk1Eta)<1.2&&abs(Dtrk2Eta)<1.2&&abs(Dtrk3Eta)<1.2&&Dmass>2.1&&Dmass<2.45");//TMVA 8_10 PbPb latest.
//ntlambdaCtopkpi->Project("h1","Dmass","DsvpvDistance/DsvpvDisErr>4.1969126030306354&&Dpt>6&&Dpt<8&&Dchi2cl>0.29562611977043635&&Dalpha<0.12684689200468829&&abs(Dtrk1Eta)<1.2&&abs(Dtrk2Eta)<1.2&&abs(Dtrk3Eta)<1.2&&Dmass>2.1&&Dmass<2.45");//TMVA 6_8 PbPb latest.till now do not have data.

//nt->Project("h1","mass","dls>2.6069100006778565&&pt>4&&pt<5&&chi2>0.15959913779907128&&alpha<0.19970228135330317&&abs(Dtrk1Y)<1.2&&abs(Dtrk2Y)<1.2&&abs(Dtrk3Y)<1.2&&mass>2.1&&mass<2.45");//TMVA 4_5 pp latest.
//ntlambdaCtopkpi->Project("h2","Dmass","DsvpvDistance/DsvpvDisErr>2.6069100006778565&&Dpt>4&&Dpt<5&&Dchi2cl>0.15959913779907128&&Dalpha<0.19970228135330317&&abs(Dtrk1Eta)<1.2&&abs(Dtrk2Eta)<1.2&&abs(Dtrk3Eta)<1.2&&Dmass>2.1&&Dmass<2.45&&Dgen==23333");//TMVA 4_5 pp MC.


//ntlambdaCtopkpi->Project("h1","Dmass","DsvpvDistance/DsvpvDisErr>4.8858387241015402e&&Dpt>8&&Dpt<10&&Dchi2cl>0.35237679998061466&&Dalpha<0.19554112156565626&&abs(Dtrk1Eta)<1.2&&abs(Dtrk2Eta)<1.2&&abs(Dtrk3Eta)<1.2&&Dmass>2.1&&Dmass<2.45");//TMVA 8_10 PbPb newest11.
//ntlambdaCtopkpi->Project("h1","Dmass","DsvpvDistance/DsvpvDisErr>4.8849754695798753&&Dpt>8&&Dpt<10&&Dchi2cl>0.31740156212971082&&Dalpha<0.18472811446660858&&abs(Dtrk1Eta)<1.2&&abs(Dtrk2Eta)<1.2&&abs(Dtrk3Eta)<1.2&&Dmass>2.1&&Dmass<2.45");//TMVA 8_10 PbPb newest1.
//ntlambdaCtopkpi->Project("h1","Dmass","DsvpvDistance/DsvpvDisErr>4.6653527409025273&&Dpt>8&&Dpt<10&&Dchi2cl>0.31719447604854234&&Dalpha<0.19781478137653596&&abs(Dtrk1Eta)<1.2&&abs(Dtrk2Eta)<1.2&&abs(Dtrk3Eta)<1.2&&Dmass>2.1&&Dmass<2.45");//TMVA 8_10 PbPb newest1.-----
//ntlambdaCtopkpi->Project("h1","Dmass","DsvpvDistance/DsvpvDisErr>4.6431768574834038&&Dpt>8&&Dpt<10&&Dchi2cl>0.33510841187886442&&Dalpha<0.18851482981605913&&abs(Dtrk1Eta)<1.2&&abs(Dtrk2Eta)<1.2&&abs(Dtrk3Eta)<1.2&&Dmass>2.1&&Dmass<2.45");//TMVA 8_10 PbPb newest1.real
//ntlambdaCtopkpi->Project("h1","Dmass","DsvpvDistance/DsvpvDisErr>3.8996727296422549&&Dpt>8&&Dpt<10&&Dchi2cl>0.32623184767115&&Dalpha<0.18566430509955692&&abs(Dtrk1Eta)<1.2&&abs(Dtrk2Eta)<1.2&&abs(Dtrk3Eta)<1.2&&Dmass>2.1&&Dmass<2.45");//TMVA 8_10 PbPb newest2.

//h1->SetMinimum(0);
//h2->SetMinimum(0);
h1->Sumw2();
h1->Draw("e");
//h2->Draw("esame");
//TFile* result = new TFile("hist_pp_10_20_TMVA_latest_whole.root", "RECREATE");
TFile * result = new TFile("hist_PbPb_10_20_trackonly_test.root","RECREATE");
h1->Write();
//h2->Write();
result->Close();

}
