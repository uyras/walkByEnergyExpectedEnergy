# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt

for i in range(1,11):
    a = np.loadtxt("data/allEnergy"+str(i)+"_1.dat")
    mins = {}
    maxs = {}
    avgs = {}
    for d in a:
        if mins.has_key(d[0]):
            if (mins[d[0]]>d[1]): mins[d[0]]=d[1]
        else:
            mins[d[0]]=d[1]
            
        if maxs.has_key(d[0]):
            if (maxs[d[0]]<d[1]): maxs[d[0]]=d[1]
        else:
            maxs[d[0]]=d[1]
            
        if avgs.has_key(d[0]):
            avgs[d[0]].append(d[1])
        else:
            avgs[d[0]]=[d[1]]
            
    for d in avgs.keys():
        avgs[d] = np.mean(avgs[d])
    plt.figure()
    plt.plot(mins.keys(),mins.values(), ".",label='minimum')
    plt.plot(maxs.keys(),maxs.values(), ".",label='maximum')
    plt.plot(avgs.keys(),avgs.values(), ".",label='average')
    plt.title('energy landscape, exp.'+str(i))
    plt.xlabel(u'spin excess')
    plt.ylabel(u'energy')
    plt.legend()
    plt.xlim(-21,30)
    plt.savefig("res/e_min_max_1_"+str(i)+".png",dpi=300);