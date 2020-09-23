#!/usr/bin/env python
# -*- coding: utf-8 -*-
'''
@ Author: Jinnan Zhang, jinnan.zhang@ihep.ac.cn
'''

import matplotlib.pyplot as plt
import ROOT
import numpy as np

# plot with function or data
def PlotAFCN(nPts=200):
    x=np.linspace(0.1,10,nPts)
    y=np.sin(x)/x
    plt.plot(x,y,label='sin(x)/x',color='coral',linestyle='-.')
    plt.legend(loc='best')
    plt.show()

# plot by ROOT method
def PlotByRoot(nPts=200):
    f_sim=ROOT.TF1("f_sim","sin(x)/x",0.1,10)
    f_sim.SetNpx(nPts)
    f_sim.Draw()
    #hold the window
    text=input()

# plot with ROOT data and matplotlib mathod
def PlotWithRootData():
    h_sim=ROOT.TH1D("h_sim","Simple histogram from root",200,-10,10)
    h_sim.FillRandom("gaus")
    # h_sim.Draw()
    # text=input()
    x=np.zeros(h_sim.GetNbinsX())
    h_sim.GetXaxis().GetCenter(x)
    y=np.asarray(h_sim)[1:-1]   # cut off over/underflow bins
    fig,ax=plt.subplots(figsize=(12,10))
    ax.step(x,y,color='black',label="Test Histogram")
    ax.set_xlabel('This is X')
    ax.set_ylabel('This is Y')
    ax.legend()
    plt.show()



if __name__ == "__main__":
    #Global plot style option
    # plt.style.use("Style/Paper.mplstyle")
    
    #Plot style within given scope
    with plt.style.context("Style/Paper.mplstyle"):
        PlotAFCN()
        PlotByRoot()
        PlotWithRootData()