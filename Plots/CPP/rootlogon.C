// logon file
{
  // Graphs
  gStyle->SetMarkerStyle(6);
  gStyle->SetMarkerSize(1.2);
  //gStyle->SetMarkerColor(4);
  gStyle->SetEndErrorSize(0);

  // Titles
  gStyle->SetTitleW(-1); // should autorange it
  gStyle->SetTitleFillColor(0);
  gStyle->SetTitleBorderSize(0);
  gStyle->SetTitleY(0.995);

  // Histograms
  //gStyle->SetHistLineColor(4);
  gStyle->SetHistLineWidth(2);
  gStyle->SetLineWidth(1); 
  gStyle->SetFuncWidth(2);
  //  gStyle->SetHistFillColor(4); 
  //gStyle->SetErrorX(0);

  // Labels
  Int_t font=132;
  Double_t tsize=0.06;
  gStyle->SetLabelFont(font,"xyz"); 
  gStyle->SetLabelSize(tsize,"xyz");
  gStyle->SetLabelOffset(0.01,"xyz");
  gStyle->SetTitleFont(font,"xyz");
  gStyle->SetTitleSize(tsize,"xyz");
  gStyle->SetTitleOffset(1.1,"z"); 
  gStyle->SetTitleOffset(1.0,"xy");
  gStyle->SetTitleBorderSize(0);
  gStyle->SetStatFont(font);
  gStyle->SetStatFontSize(tsize);
  gStyle->SetStatBorderSize(1);
  gStyle->SetStatX(0.98);
  gStyle->SetStatY(0.98);
  gStyle->SetTextFont(font);

  gStyle->SetLabelFont(font,"X");
  gStyle->SetLabelFont(font,"Y");
  gStyle->SetLabelFont(font,"Z");
  gStyle->SetTitleFont(font,"X");
  gStyle->SetTitleFont(font,"Y");
  gStyle->SetTitleFont(font,"Z");
  gStyle->SetTitleOffset(1., "X");
  gStyle->SetTitleOffset(1., "Y");
  gStyle->SetTitleOffset(1.1, "Z");

  gStyle->SetTitleSize(tsize, "X");
  gStyle->SetTitleSize(tsize, "Y");
  gStyle->SetTitleSize(tsize, "Z");
  gStyle->SetLabelSize(tsize,"X");
  gStyle->SetLabelSize(tsize,"Y");
  gStyle->SetLabelSize(tsize,"Z");
  gStyle->SetStatFontSize(0.08);

  // Canvas
  //gStyle->SetCanvasDefH(450);  
  //gStyle->SetCanvasDefW(450);  
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetCanvasColor(0);

  // Pads
  gStyle->SetPadBorderMode(0);
  //gStyle->SetPadLeftMargin(0.1);
  //gStyle->SetPadRightMargin(0.1);
  gStyle->SetPadLeftMargin(0.14);
  gStyle->SetPadRightMargin(0.08); // <--- chg for COLZ
  gStyle->SetPadBottomMargin(0.14); // <--- chg for COLZ
  gStyle->SetPadTopMargin(0.08); // <--- chg for COLZ
   //gStyle->SetPadLeftMargin(0.08);
   //gStyle->SetPadRightMargin(0.04); // <--- chg for COLZ
  //gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);

  // Legend
  gStyle->SetLegendBorderSize(0);

  // Statistics
  //gStyle->SetOptDate();
  gStyle->SetOptFit();
  gStyle->SetOptStat(0);
  //gStyle->SetOptStat(1111);
      // n name of histogram
      // e number of entries
      // m mean value
      // r rms
      // u underflows
      // o overflows
      // i integral of bin
  gStyle->SetStatBorderSize(0);
  gStyle->SetStatX(0.85);
  gStyle->SetStatY(0.85);

  gStyle->SetTimeOffset(0); // offset to start of epoch

  Int_t icol=0;
  gStyle->SetFrameBorderMode(icol);
  gStyle->SetCanvasBorderMode(icol);
  gStyle->SetPadBorderMode(icol);
  gStyle->SetPadColor(icol);
  gStyle->SetCanvasColor(icol);
  gStyle->SetStatColor(icol);
  gStyle->SetTitleFillColor(icol);
  gStyle->SetPaperSize(TStyle::kUSLetter);
  gStyle->SetFillColor(10);

  //TTF fonts
  if(!gROOT->IsBatch()) 
    gSystem->Load("libGX11TTF.so");

  // PostScript
  gStyle->SetHeaderPS("%%Author: \n");

  gStyle->SetPalette(1);

  //We want the debug info as well
  TString IncludePath(gSystem->GetIncludePath());
  IncludePath.Append(" -I..");
  gSystem->SetIncludePath(IncludePath);

  TString GccOpt(gSystem->GetMakeExe());
  GccOpt.ReplaceAll("-O", "-O -g");
  gSystem->SetMakeExe(GccOpt);

  //gROOT->ForceStyle();
  printf("Loaded rootlogon.C\n");

  //hist->SetDirectory(gROOT)
}

