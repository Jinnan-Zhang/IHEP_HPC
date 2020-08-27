//This is the file rootlogon.C
//Daya Bay plot style.
{
    if (gSystem->Getenv("TUTORIALROOT")) {
        // JUNO
        gROOT->ProcessLine(".L $EVTNAVIGATORROOT/$CMTCONFIG/libEvtNavigator.so");
        gROOT->ProcessLine(".L $GENEVENTV2ROOT/$CMTCONFIG/libGenEventV2.so");
        gROOT->ProcessLine(".L $SIMEVENTV2ROOT/$CMTCONFIG/libSimEventV2.so");
        gROOT->ProcessLine(".L $ELECEVENTROOT/$CMTCONFIG/libElecEvent.so");
        gROOT->ProcessLine(".L $CALIBEVENTROOT/$CMTCONFIG/libCalibEvent.so");
        gROOT->ProcessLine(".L $RECEVENTROOT/$CMTCONFIG/libRecEvent.so");
        gROOT->ProcessLine(".L $CONTEXTROOT/$CMTCONFIG/libContext.so");
    }
      TString includes;
      if (gSystem->Getenv("WORKTOP")) {
          TString worktop = gSystem->Getenv("WORKTOP");
          includes = TString::Format(".include %s/offline/InstallArea/include", worktop.Data());
      } else if (gSystem->Getenv("JUNOTOP")) {
          TString junotop = gSystem->Getenv("JUNOTOP");
          includes = TString::Format(".include %s/offline/InstallArea/include", junotop.Data());
      }
      gROOT->ProcessLine(includes);
  
    
    
    //Creating new style "DAYA"
  TStyle *dayaStyle= new TStyle("DAYA","Daya Bay style");
  Int_t icol=0;
  dayaStyle->SetFrameBorderMode(icol);
  dayaStyle->SetCanvasBorderMode(icol);
  dayaStyle->SetPadBorderMode(icol);
  dayaStyle->SetPadColor(icol);
  dayaStyle->SetCanvasColor(icol);
  dayaStyle->SetStatColor(icol);
  dayaStyle->SetTitleFillColor(icol);

  dayaStyle->SetPalette(1);
  // set the paper & margin sizes
  dayaStyle->SetPaperSize(TStyle::kUSLetter);
  //Margins, give some additional space on the Left/Bottom where axis labels go
  dayaStyle->SetPadTopMargin(.1);
  //dayaStyle->SetPadLeftMargin(.12);
  dayaStyle->SetPadLeftMargin(.16);
  dayaStyle->SetPadRightMargin(.16);
  //dayaStyle->SetPadBottomMargin(.12);
  dayaStyle->SetPadBottomMargin(.16);
  // set master font
  Int_t font=132;      //times new roman, regular (13), high precision (2)
  //Int_t font=42;     //tnr, bold (4), high precision (2) 

  //set master font size
  Double_t tsize=11./220; //should be set between 0.03-0.05, is in units of "% of pad"
  Double_t titlesize=13./220; //should be set between 0.03-0.05, is in units of "% of pad"

  // Text, Labels, Titles
  // All set the same here
  dayaStyle->SetTextFont(font);
  dayaStyle->SetTextSize(titlesize);

  dayaStyle->SetLabelFont(font,"xyz");
  dayaStyle->SetLabelSize(tsize,"xyz");
  dayaStyle->SetLabelOffset(0.01,"xyz");

  dayaStyle->SetTitleFont(font,"xyz");
  dayaStyle->SetTitleSize(titlesize,"xyz");
  dayaStyle->SetTitleYOffset(1); //offset the title of y axis a bit
  dayaStyle->SetTitleBorderSize(1);

  //use bold lines and markers
  dayaStyle->SetMarkerStyle(20);
  dayaStyle->SetMarkerSize(0);
  dayaStyle->SetHistLineWidth(2.);
  dayaStyle->SetLineStyleString(2,"[12 12]"); // postscript dashes

  //get rid of X error bars and y error bar caps
  //dayaStyle->SetErrorX(0.001);

  //legend and stat pad
  dayaStyle->SetStatBorderSize(1);
  dayaStyle->SetStatFont(132);
  dayaStyle->SetStatX(0.95);
  dayaStyle->SetStatY(0.95);
  dayaStyle->SetLegendBorderSize(0);
  dayaStyle->SetLegendFillColor(0);

  // put tick marks on top and RHS of plots
  dayaStyle->SetPadTickX(1);
  dayaStyle->SetPadTickY(1);
  // tick marks only on left and bottom
  //dayaStyle->SetPadTickX(0);
  //dayaStyle->SetPadTickY(0);

  // additional series styles (Thanks, Jianglai)
  //   1 = solid
  //   2 = long dash (30 10)
  //   3 = dotted (4 8)
  //   4 = dash-dot (15 12 4 12)
  //   5 = short dash ( 15 15 )
  //   6 = dash-dot-dot   gStyle->SetLineStyleString(1,"[]");
  dayaStyle->SetLineStyleString(2,"[30 10]");
  dayaStyle->SetLineStyleString(3,"[4 8]");
  dayaStyle->SetLineStyleString(4,"[15 12 4 12]");
  dayaStyle->SetLineStyleString(5,"[15 15]");
  dayaStyle->SetLineStyleString(6,"[15 12 4 12 4 12]");
  dayaStyle->SetOptDate(0);
  dayaStyle->SetDateY(.98);
  dayaStyle->SetStripDecimals(kFALSE);

  //  dayaStyle->SetEndErrorSize(5.0); //make the end of error bar longer 


  gROOT->SetStyle("DAYA");
  gROOT->ForceStyle();
  


}
