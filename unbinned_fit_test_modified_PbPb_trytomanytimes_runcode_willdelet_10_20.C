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
#include <RooDataSet.h>
#include <RooFormulaVar.h>
#include <RooRealVar.h>
using namespace RooFit;
void unbinned_fit_test_modified_PbPb_trytomanytimes_runcode_willdelet_10_20(){
//pp 10-20
TFile * f = new TFile("/scratch/halstead/x/xiao147/pp2015_lambdaC_pt8_makeup_halstead/MB1_20_pp_2015_adddaughterpt/pp_eventselection_trackquality_trigger/TMVA_histogram_version2/mass_tuple_whole.root");
//pp 10-20 pol2
TFile *f_fun = new TFile("/home/xiao147/private/newchannel_lambda_CtoproduceDntuple/CMSSW_7_5_8_patch3/src/Bfinder/Bfinder/Dntuple/TMVA_official_MC/signal_exaction/ROOT_signalextraction_witheventselection/signalectraction/forAN_plot/change_fit_function/pp/pol2/10_20_pp_officialTMVAcuts_2gaus_pol2_weighted_ptcuts_eventselection_withLoption_change_fit_funcition.root");






TF1 *f3 = (TF1*) f_fun->Get("f3");
TH1F *h1 = (TH1F*) f_fun->Get("h1");
double w1 = f3->GetParameter(2);
double w2 = f3->GetParameter(4);
double r1 = f3->GetParameter(3);
double mean_value = f3->GetParameter(1);
double pol1_value = f3->GetParameter(7);
double pol2_value = f3->GetParameter(8);
double pol3_value = f3->GetParameter(9);
double float_width_parameter = f3->GetParameter(5);
double numbers = f3->GetParameter(0);
double numberb = f3->Integral(2.2,2.4)/h1->GetBinWidth(0)-f3->GetParameter(0);
TH1F *h_output = new TH1F ("h_output","output",2,0,2);
cout<<"numbers"<<numbers<<endl;
cout<<"numberb"<<numberb<<endl;



TNtuple *nt1 = (TNtuple*)f->Get("nt1");
RooRealVar mass("mass","mass",2.2,2.4);
RooDataSet ds("ds","ds",nt1,mass);
ds.Print();
cout<<"begin fitting"<<endl;
RooRealVar mean("mean","mean",mean_value,mean_value,mean_value);
RooRealVar width1("width1","width1",w1,w1,w1);
RooRealVar width2("width2","width2",w2,w2,w2);
RooRealVar ratio("ratio","ratio",r1,r1,r1);
RooRealVar p1("p1","p1",pol1_value,1e+1,1e+6);
RooRealVar p2("p2","p2",pol2_value,-9e+5,-2e+1);
//RooRealVar p3("p3","p3",pol3_value,-2e+4,-2e+2);
RooRealVar float_width("float_width","float_width",float_width_parameter,float_width_parameter,float_width_parameter);
RooFormulaVar scale_width1("scale width1","scaled width1","width1*(1+float_width)",RooArgSet(width1,float_width));
RooFormulaVar scale_width2("scale width2","scaled width2","width2*(1+float_width)",RooArgSet(width2,float_width));
RooGaussian sigma1("sigma1","gauss(mass,mean,scale_width1)",mass,mean,scale_width1);
RooGaussian sigma2("sigma2","gauss(mass,mean,scale_width2)",mass,mean,scale_width2);
RooAddPdf signal("signal","signal",RooArgList(sigma1,sigma2),ratio);
RooPolynomial back("back","second polynomial",mass,RooArgList(p1,p2));
//RooPolynomial back("back","second polynomial",mass,RooArgList(p1,p2,p3));
RooRealVar NumSig("NumSig","Number of Signal",numbers,-1e4,1e4);
RooRealVar NumBkg("NumBkg","Number of Background",numberb,-1e8,1e8);
RooAddPdf model("model","model",RooArgList(signal,back),RooArgList(NumSig,NumBkg));

//model.fitTo(ds,Extended(kTRUE)); 
model.fitTo(ds,Extended(kTRUE),Range(2.26,2.32)); //10-20
//model.fitTo(ds,Extended(kTRUE),Range(2.24,2.32)); //10-20

RooRealVar mean_2("mean_2","mean_2",mean.getVal(),2.26,2.31);
RooRealVar width1_2("width1_2","width1_2",width1.getVal(),width1.getVal(),width1.getVal());
RooRealVar width2_2("width2_2","width2_2",width2.getVal(),width2.getVal(),width2.getVal());
RooRealVar ratio_2("ratio_2","ratio_2",ratio.getVal(),ratio.getVal(),ratio.getVal());
RooRealVar p1_2("p1_2","p1_2",p1.getVal(),5e+3,1e+5);
RooRealVar p2_2("p2_2","p2_2",p2.getVal(),-9e+5,-9e+1);
//RooRealVar p3_2("p3_2","p3_2",p3.getVal(),-2e+4,-2e+2);
RooRealVar float_width_2("float_width_2","float_width_2",float_width.getVal(),-0.5,0.5);
RooFormulaVar scale_width1_2("scale width1_2","scaled width1_2","width1_2*(1+float_width_2)",RooArgSet(width1_2,float_width_2));
RooFormulaVar scale_width2_2("scale width2_2","scaled width2_2","width2_2*(1+float_width_2)",RooArgSet(width2_2,float_width_2));
RooGaussian sigma1_2("sigma1_2","gauss(mass,mean_2,scale_width1_2)",mass,mean_2,scale_width1_2);
RooGaussian sigma2_2("sigma2_2","gauss(mass,mean_2,scale_width2_2)",mass,mean_2,scale_width2_2);
RooAddPdf signal_2("signal_2","signal_2",RooArgList(sigma1_2,sigma2_2),ratio_2);
RooPolynomial back_2("back_2","second polynomial",mass,RooArgList(p1_2,p2_2));
//RooPolynomial back_2("back_2","second polynomial",mass,RooArgList(p1_2,p2_2,p3_2));
RooRealVar NumSig_2("NumSig_2","Number of Signal_2",NumSig.getVal(),-1e4,1e4);
RooRealVar NumBkg_2("NumBkg_2","Number of Background",NumBkg.getVal(),-1e6,1e6);
RooAddPdf model_2("model_2","model_2",RooArgList(signal_2,back_2),RooArgList(NumSig_2,NumBkg_2));
//model.fitTo(ds,Extended(kTRUE));
model_2.fitTo(ds,Extended(kTRUE),Range(2.24,2.35));
//cout<<"number----"<<NumSig.getVal();

RooRealVar mean_3("mean_3","mean_3",mean_2.getVal(),2.26,2.31);
RooRealVar width1_3("width1_3","width1_3",width1_2.getVal(),width1_2.getVal(),width1_2.getVal());
RooRealVar width2_3("width2_3","width2_3",width2_2.getVal(),width2_2.getVal(),width2_2.getVal());
RooRealVar ratio_3("ratio_3","ratio_3",ratio_2.getVal(),ratio_2.getVal(),ratio_2.getVal());
RooRealVar p1_3("p1_3","p1_3",p1_2.getVal(),5e+3,1e+5);
RooRealVar p2_3("p2_3","p2_3",p2_2.getVal(),-9e+5,-9e+1);
//RooRealVar p3_3("p3_3","p3_3",p3_2.getVal(),-2e+4,-2e+2);
RooRealVar float_width_3("float_width_3","float_width_3",float_width_2.getVal(),-0.5,0.5);
RooFormulaVar scale_width1_3("scale width1_3","scaled width1_3","width1_3*(1+float_width_3)",RooArgSet(width1_3,float_width_3));
RooFormulaVar scale_width2_3("scale width2_3","scaled width2_3","width2_3*(1+float_width_3)",RooArgSet(width2_3,float_width_3));
RooGaussian sigma1_3("sigma1_3","gauss(mass,mean_3,scale_width1_3)",mass,mean_3,scale_width1_3);
RooGaussian sigma2_3("sigma2_3","gauss(mass,mean_3,scale_width2_3)",mass,mean_3,scale_width2_3);
RooAddPdf signal_3("signal_3","signal_2",RooArgList(sigma1_3,sigma2_3),ratio_3);
RooPolynomial back_3("back_3","second polynomial_3",mass,RooArgList(p1_3,p2_3));
//RooPolynomial back_3("back_3","second polynomial_3",mass,RooArgList(p1_3,p2_3,p3_3));
RooRealVar NumSig_3("NumSig_3","Number of Signal_3",NumSig_2.getVal(),-1e4,1e4);
RooRealVar NumBkg_3("NumBkg_3","Number of Background_3",NumBkg_2.getVal(),-1e6,1e6);
RooAddPdf model_3("model_3","model_3",RooArgList(signal_3,back_3),RooArgList(NumSig_3,NumBkg_3));
//model.fitTo(ds,Extended(kTRUE));
model_3.fitTo(ds,Extended(kTRUE),Range(2.22,2.38));
//turn 4
RooRealVar mean_4("mean_4","mean_4",mean_3.getVal(),2.26,2.31);
RooRealVar width1_4("width1_4","width1_4",width1_3.getVal(),width1_3.getVal(),width1_3.getVal());
RooRealVar width2_4("width2_4","width2_4",width2_3.getVal(),width2_3.getVal(),width2_3.getVal());
RooRealVar ratio_4("ratio_4","ratio_4",ratio_3.getVal(),ratio_3.getVal(),ratio_3.getVal());
RooRealVar p1_4("p1_4","p1_4",p1_3.getVal(),5e+3,1e+5);
RooRealVar p2_4("p2_4","p2_4",p2_3.getVal(),-9e+5,-9e+1);
//RooRealVar p3_4("p3_4","p3_4",p3_3.getVal(),-2e+4,-2e+2);
RooRealVar float_width_4("float_width_4","float_width_4",float_width_3.getVal(),-0.5,0.5);
RooFormulaVar scale_width1_4("scale width1_4","scaled width1_4","width1_3*(1+float_width_3)",RooArgSet(width1_4,float_width_4));
RooFormulaVar scale_width2_4("scale width2_4","scaled width2_4","width2_3*(1+float_width_3)",RooArgSet(width2_4,float_width_4));
RooGaussian sigma1_4("sigma1_4","gauss(mass,mean_4,scale_width1_4)",mass,mean_4,scale_width1_4);
RooGaussian sigma2_4("sigma2_4","gauss(mass,mean_4,scale_width2_4)",mass,mean_4,scale_width2_4);
RooAddPdf signal_4("signal_4","signal_4",RooArgList(sigma1_4,sigma2_4),ratio_4);
RooPolynomial back_4("back_4","second polynomial_4",mass,RooArgList(p1_4,p2_4));
//RooPolynomial back_4("back_4","second polynomial_4",mass,RooArgList(p1_4,p2_4,p3_4));
RooRealVar NumSig_4("NumSig_4","Number of Signal_4",NumSig_3.getVal(),-1e4,1e4);
RooRealVar NumBkg_4("NumBkg_4","Number of Background_4",NumBkg_3.getVal(),-1e6,1e6);
RooAddPdf model_4("model_4","model_4",RooArgList(signal_4,back_4),RooArgList(NumSig_4,NumBkg_4));
//model.fitTo(ds,Extended(kTRUE));
model_4.fitTo(ds,Extended(kTRUE),Range(2.22,2.4));
///turn 5

RooRealVar mean_5("mean_5","mean_5",mean_4.getVal(),2.26,2.31);
RooRealVar width1_5("width1_5","width1_5",width1_4.getVal(),width1_4.getVal(),width1_4.getVal());
RooRealVar width2_5("width2_5","width2_5",width2_4.getVal(),width2_4.getVal(),width2_4.getVal());
RooRealVar ratio_5("ratio_5","ratio_5",ratio_4.getVal(),ratio_4.getVal(),ratio_4.getVal());
RooRealVar p1_5("p1_5","p1_5",p1_4.getVal(),5e+3,1e+5);
RooRealVar p2_5("p2_5","p2_5",p2_4.getVal(),-9e+5,-9e+1);
//RooRealVar p3_5("p3_5","p3_5",p3_4.getVal(),-2e+4,-2e+2);
RooRealVar float_width_5("float_width_5","float_width_5",float_width_4.getVal(),-0.5,0.5);
RooFormulaVar scale_width1_5("scale width1_5","scaled width1_5","width1_5*(1+float_width_5)",RooArgSet(width1_5,float_width_5));
RooFormulaVar scale_width2_5("scale width2_5","scaled width2_5","width2_5*(1+float_width_5)",RooArgSet(width2_5,float_width_5));
RooGaussian sigma1_5("sigma1_5","gauss(mass,mean_5,scale_width1_5)",mass,mean_5,scale_width1_5);
RooGaussian sigma2_5("sigma2_5","gauss(mass,mean_5,scale_width2_5)",mass,mean_5,scale_width2_5);
RooAddPdf signal_5("signal_5","signal_5",RooArgList(sigma1_5,sigma2_5),ratio_5);
RooPolynomial back_5("back_5","second polynomial_5",mass,RooArgList(p1_5,p2_5));
//RooPolynomial back_5("back_5","second polynomial_5",mass,RooArgList(p1_5,p2_5,p3_5));
RooRealVar NumSig_5("NumSig_5","Number of Signal_5",NumSig_4.getVal(),-1e4,1e4);
RooRealVar NumBkg_5("NumBkg_5","Number of Background_5",NumBkg_4.getVal(),-1e6,1e6);
RooAddPdf model_5("model_5","model_5",RooArgList(signal_5,back_5),RooArgList(NumSig_5,NumBkg_5));

//model_5.fitTo(ds,Extended(kTRUE),Range(2.215,2.39));
model_5.fitTo(ds,Extended(kTRUE),Range(2.2,2.4));

//model_4.plotOn(massframe,Range("full"));
//model_4.plotOn(massframe,Components(back_4));
//back.plotOn(massframe,Range("full"));
//model_5.plotOn(massframe,Range("full"));
//model_5.plotOn(massframe,Components(back_5));
//signal.plotOn(massframe,Range("full"));
RooPlot *massframe = new RooPlot("mass","mass",mass,2.2,2.4,25);
ds.plotOn(massframe);
TCanvas *c1 = new TCanvas("c1","c1",600,600);
gStyle->SetOptTitle(0);
gStyle->SetOptStat(0);
gStyle->SetOptFit(0);
gStyle->SetTitleX(0.8f);
gStyle->SetTitleY(0.95);
gStyle->SetTitleW(0.2f);
gStyle->SetTitleFontSize(0.06);

massframe->Draw();
model_5.plotOn(massframe,Range("full"));
model_5.plotOn(massframe,Components(back_5));

/*
model.plotOn(massframe,Range("full"));
model.plotOn(massframe,Components(back));
*/
massframe->SetXTitle("m_{pk#pi} (GeV/c^{2})");
massframe->SetTitleOffset(1.5,"Y");
massframe->SetTitleOffset(1.0,"X");
massframe->SetTitleFont(42,"X");
massframe->SetTitleFont(42,"Y");
massframe->SetLabelFont(42,"Y");
massframe->SetLabelFont(42,"X");
massframe->SetLabelSize(0.033,"X");
massframe->SetLabelSize(0.032,"Y");
massframe->SetTitleSize(0.034,"X");
massframe->SetTitleSize(0.033,"Y");
massframe->SetMinimum(58000);
massframe->Draw();


TLatex* tex;
tex = new TLatex(0.52,0.85,"pp: 10GeV < P_{T} < 20GeV");
//tex = new TLatex(0.17,0.5,"PbPb: 10GeV < P_{T} < 20GeV");
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.033);
tex->SetLineWidth(2);
tex->Draw();

int a = round(NumSig_5.getVal());
int b = round(NumSig_5.getError());
//int a = round(NumSig_2.getVal());
//int b = round(NumSig_2.getError());
tex = new TLatex(0.52,0.8,Form("yield: %i #pm %i ",a,b));
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.033);
tex->SetLineWidth(2);
tex->Draw();

/*
tex = new TLatex(0.17,0.55,"centrality:0%-30%");
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.033);
tex->SetLineWidth(2);
tex->Draw();
*/


tex = new TLatex(0.52,0.75,"|y| < 1.0");
tex->SetNDC();
tex->SetTextFont(42);
tex->SetTextSize(0.033);
tex->SetLineWidth(2);
tex->Draw();

TLatex Tl; 
Tl.SetNDC();
Tl.SetTextAlign(12);
Tl.SetTextSize(0.045);
Tl.SetTextFont(42);
Tl.DrawLatex(0.1,0.93, "#font[61]{CMS }");
Tl.DrawLatex(0.22,0.93, "#scale[0.8]{Preliminary}");
Tl.DrawLatex(0.59,0.93, "#scale[0.8]{38.2 nb^{-1} (5.02 TeV)}");//pp
//Tl.DrawLatex(0.57,0.93, "#scale[0.8]{101.573 #mub^{-1} (5.02 TeV)}");
//Tl.DrawLatex(0.59,0.93, "#scale[0.8]{43.862 #mub^{-1} (5.02 TeV)}");
h_output->SetBinContent(1,a);
h_output->SetBinError(1,b);



c1->SaveAs("/home/xiao147/private/newchannel_lambda_CtoproduceDntuple/CMSSW_7_5_8_patch3/src/Bfinder/Bfinder/Dntuple/TMVA_official_MC/signal_exaction/ROOT_signalextraction_witheventselection/signalectraction/forAN_plot/unbinnedfit/pp/pp_10_20_TMVA_pol2_official_official.gif");
TFile *result = new TFile("/home/xiao147/private/newchannel_lambda_CtoproduceDntuple/CMSSW_7_5_8_patch3/src/Bfinder/Bfinder/Dntuple/TMVA_official_MC/signal_exaction/ROOT_signalextraction_witheventselection/signalectraction/forAN_plot/unbinnedfit/pp/pp_10_20_pol2_TMVA_offical.root","RECREATE");
h_output->Write();
result->Close();

}
