#!/usr/bin/env python
# -*- coding: utf-8 -*-
import matplotlib.pyplot as plt
import ROOT
import numpy as np

def PlotAHist(nPts=200):
    x=np.linspace(0.1,10,nPts)
    y=np.sin(x)/x
    plt.plot(x,y,label='sin(x)/x',color='coral',linestyle='-.')
    plt.legend(loc='best')
    plt.show()

def PlotByRoot(nPts=200):
    f_sim=ROOT.TF1("f_sim","sin(x)/x",0.1,10)
    f_sim.SetNpx(nPts)
    f_sim.Draw()
    #hold the window
    text=input()


if __name__ == "__main__":
    #全局使用
    # plt.style.use("Style/Paper.mplstyle")
    
    #或限制style作用域
    with plt.style.context("Style/Paper.mplstyle"):
        PlotAHist()
        PlotByRoot()