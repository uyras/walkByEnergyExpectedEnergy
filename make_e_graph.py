# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt

for i in range(1,11):
    a,b = np.loadtxt("energy"+str(i)+".dat", unpack=True)
    plt.plot(a,b,".")
    plt.title('energy landscape')
    plt.xlabel(u'spin excess')
    plt.ylabel(u'energy')
    plt.savefig("e"+str(i)+".png",dpi=300);