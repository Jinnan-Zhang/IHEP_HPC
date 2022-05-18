# -*- coding: utf-8 -*-
''' pure nue -> nue
author: Jinnan Zhang
zhangjinnan@ihep.ac.cn
date: 2021.11.17
'''
from pyexpat.errors import XML_ERROR_PARTIAL_CHAR



def show_2d_contour_and_projection(data_x, data_y, data_z, nominal_xs=[0], nominal_ys=[0],nominal_z='',nominal_maker= r'$\clubsuit$', s_marker=600,marker_color='g',marker_label='', xlabel='X []', ylabel="Y []", zlabel="Z []", save_file_name='contour.png', fmt_x='%.2f', fmt_y='%.2f', fmt_z='%.2f', figsize=(12, 10), cmap='coolwarm', levels=5,contour_colors=['r','violet','blue'], linestyle='solid', xscale='linear', yscale='linear', zscale='linear',xlim='',ylim='',zlim='',xticks='',yticks='',zticks=''):
    import numpy as np
    x = np.array(data_x)
    y = np.array(data_y)
    z = np.array(data_z)

    if xlim=='':
        xlim=(np.min(x),np.max(x))
    if ylim=='':
        ylim=(np.min(y),np.max(y))
    if zlim=='':
        zlim=(np.min(z),np.max(z))

    total_N = z.shape[0]
    Nx = len(set(x))
    # Ny = len(set(y))
    Ny = int(total_N/Nx)
    import matplotlib.pyplot as plt
    import matplotlib.gridspec as gridspec

    xx = x.reshape(Nx, Ny)
    yy = y.reshape(Nx, Ny)
    zz = z.reshape(Nx, Ny)
    fig = plt.figure(tight_layout=True, figsize=figsize)
    gs = gridspec.GridSpec(3, 4, hspace=0, wspace=0)

    axs = {}
    axs['2D'] = fig.add_subplot(gs[1:3, 0:3])
    axs['the_y'] = fig.add_subplot(gs[0, 0:3])
    axs['the_x'] = fig.add_subplot(gs[1:3, 3])

    index_x_unit = xlabel.index('[')
    index_y_unit = ylabel.index('[')

    # import matplotlib.cm as cm
    # CS = axs['2D'].contourf(xx, yy, zz, cmap=cmap,levels=levels)
    if not cmap == '':
        if zscale == 'log':
            axs['2D'].imshow(np.log(zz), interpolation='lanczos', origin='lower', extent=(
                np.min(data_x), np.max(data_x), np.min(data_y), np.max(data_y)), aspect='auto', cmap=cmap)
        else:
            axs['2D'].imshow(zz, interpolation='lanczos', origin='lower', extent=(
                np.min(data_x), np.max(data_x), np.min(data_y), np.max(data_y)), aspect='auto', cmap=cmap)
    CS = axs['2D'].contour(xx, yy, zz, levels=levels,colors=contour_colors, linestyles=linestyle,linewidths=3)
    plt.clabel(CS, fmt=fmt_z)
    if not marker_label =='':
    #     axs['2D'].scatter(nominal_xs,nominal_ys,marker=nominal_maker,s=s_marker,c=marker_color)
    # else:
        axs['2D'].scatter(nominal_xs,nominal_ys,marker=nominal_maker,s=s_marker,c=marker_color,label=marker_label)
        # axs['2D'].legend(frameon=1)

    axs['2D'].set_xlabel(xlabel)
    axs['2D'].set_ylabel(ylabel)
    axs['2D'].set_xlim(xmin=xlim[0],xmax=xlim[1])
    axs['2D'].set_ylim(ymin=ylim[0],ymax=ylim[1])
    axs['2D'].set_xscale(xscale)
    axs['2D'].set_yscale(yscale)
    axs['2D'].grid()
    if xticks != '':
        axs['2D'].set_xticks(xticks)
    if yticks != '':
        axs['2D'].set_yticks(yticks)

    
    for nominal_x in nominal_xs:
        index_purity = np.where(x == nominal_x)
        x_purity = y[index_purity]
        y_purity = z[index_purity]
        axs['the_x'].plot(y_purity,
                          x_purity,
                          label=f'{xlabel[:index_x_unit-1]}: {fmt_x} {xlabel[index_x_unit+1:-1]}' % (nominal_x),
                          linestyle='-.')
        
        axs['the_x'].yaxis.tick_right()
        axs['the_x'].yaxis.set_label_position("right")
        # axs['the_x'].set_ylim(np.min(x_purity), np.max(x_purity))
        axs['the_x'].set_ylim(ymin=ylim[0],ymax=ylim[1])
        axs['the_x'].set_xlabel(zlabel)
        axs['the_x'].set_ylabel(ylabel)
        axs['the_x'].set_xscale(zscale)
        axs['the_x'].set_yscale(yscale)
        axs['the_x'].grid('major')
        # axs['the_x'].legend()
    if not nominal_z=='':
        axs['the_x'].vlines(x=nominal_z,ymin=np.min(x_purity),ymax=np.max(x_purity),colors='gray',linestyle='--')
    if yticks != '':
        axs['the_x'].set_yticks(yticks)
    if zticks != '':
        axs['the_x'].set_xticks(zticks)

    fig.legend(bbox_to_anchor=(0.99, 0.8))

    
    for nominal_y in nominal_ys:
        index_sigma = np.where(y == nominal_y)
        x_sigma = x[index_sigma]
        y_sigma = z[index_sigma]
        if ylabel[index_y_unit+1:-1] == '%':
            axs['the_y'].plot(x_sigma,y_sigma,label=f'{ylabel[:index_y_unit-1]}: {fmt_y}%%' % (nominal_y))
        else:
            axs['the_y'].plot(x_sigma,y_sigma,label=f'{ylabel[:index_y_unit-1]}: {fmt_y} {ylabel[index_y_unit+1:-1]}' % (nominal_y))
        axs['the_y'].xaxis.tick_top()
        axs['the_y'].xaxis.set_label_position('top')
        axs['the_y'].set_ylabel(zlabel)
        # axs['the_y'].set_xlabel(xlabel)
        axs['the_y'].set_title(xlabel)
        # axs['the_y'].set_xlim(xmax=np.max(x_sigma), xmin=np.min(x_sigma))
        axs['the_y'].set_xlim(xmin=xlim[0],xmax=xlim[1])
        axs['the_y'].set_xscale(xscale)
        axs['the_y'].set_yscale(zscale)
        axs['the_y'].grid('major')
    if not nominal_z=='':
        axs['the_y'].hlines(y=nominal_z,xmin=np.min(x_sigma),xmax=np.max(x_sigma),colors='gray',linestyle='--')
    axs['the_y'].legend(frameon=True)
    if xticks != '':
        axs['the_y'].set_xticks(xticks)
    if zticks != '':
        axs['the_y'].set_yticks(zticks)
    if save_file_name !='':
        fig.savefig(save_file_name, dpi=200)
        print(save_file_name+' saved!')
        plt.close()
