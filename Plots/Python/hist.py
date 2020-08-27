#!/usr/bin/env python
# -*- coding=utf8 -*-
"""
# Author: MiaoYu ---> miaoyu@ihep.ac.cn
# Created Time : Thu Aug 27 20:22:38 2020
# File Name: hist.py
# Example for histograms in matplotlib
"""

import numpy as np
import matplotlib.pyplot as plt
from ROOT import TH1D, TH2D, TCanvas

#plt.style.use('fivethirtyeight')
plt.style.use('bmh')


def draw_hist1d():
    """ draw a 1d histogram """
    data = np.random.normal(100, 20, 10000)
    plt.hist(data, bins=100, range=(0, 200), histtype="step", color="royalblue")

def draw_hist2d():
    datax = np.random.normal(100, 20, 10000)
    datay = np.random.normal(100, 30, 10000)
    ec = plt.hist2d(datax, datay, bins=(100, 100), range=((0, 200), (0, 200)))
    cbar = plt.colorbar()
    cbar.set_label('entries')



if __name__ == "__main__" :
    #with plt.style.context("Style/Paper.mplstyle"):
    
    fig = plt.figure(figsize=(10, 4))

    # PLOT 1
    ax = fig.add_subplot(1, 2, 1)
    draw_hist1d()

    # PLOT 2
    ax = fig.add_subplot(1, 2, 2)
    draw_hist2d()

    plt.show()

