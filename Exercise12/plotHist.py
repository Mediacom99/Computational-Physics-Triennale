import matplotlib.pyplot as plt 
import numpy
from statistics import NormalDist
import scipy.stats as stats

 

plt.style.use('_mpl-gallery')
fig,ax = plt.subplots();
#fig.set_size_inches(100/2.54, 100/2.54)
#plt.subplots_adjust(wspace=None, hspace=None)
fig.tight_layout()
#fig.subplots_adjust( left=None, bottom=None,  right=None, top=None, wspace=None, hspace=None)



x = numpy.genfromtxt("datiAR.txt", delimiter=' ',dtype=float, usecols=0)
#y = numpy.genfromtxt("varData.txt", delimiter=',', dtype=float, usecols=0)
#N = numpy.genfromtxt("varData.txt", delimiter=',',dtype=float, usecols=1)
ax.hist(x,100, density = True, facecolor='b', edgecolor='black', linewidth=1.0);


norm = NormalDist.from_samples(x)
mu = norm.mean
sigma = norm.stdev
print(mu)
print(sigma)

#fit = numpy.polyfit(N,y,1)
#print(fit)


#Printo con i dati fittati
lsp = numpy.linspace(mu - 3*sigma, mu + 3*sigma, 100)
ax.plot(lsp, stats.norm.pdf(lsp, norm.mean, norm.stdev), color='red')

#str = "Fit Gaussiano:\n"+r'$\mu_{u} = $'+"{}\n".format(norm.mean)+r'$ \sigma_{u} = $'+"{}".format(norm.stdev)
str = "Risultato fit:\n"+r'$ \mu = $'+"{}\n".format(mu)+r'$\sigma = $'+"{}".format(sigma)

ax.text(-3,0.4,str)

ax.legend(["Fit Gaussiano","dati metodo Accept/Reject"])
plt.grid(False);

plt.show()