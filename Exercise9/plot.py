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



y = numpy.genfromtxt("M246Bernoulli.txt", delimiter=',', dtype=float, usecols=2)
N = numpy.genfromtxt("M246Bernoulli.txt", delimiter=',',dtype=float, usecols=3)

ax.scatter(N,y)

fit = numpy.polyfit(N,y,1)
print(fit)


#Printo con i dati fittati
t=numpy.poly1d(fit)
lsp = numpy.linspace(numpy.amin(N),numpy.amax(N),100)
ax.plot(lsp, t(lsp), color='red')

#str = "Fit Gaussiano:\n"+r'$\mu_{u} = $'+"{}\n".format(norm.mean)+r'$ \sigma_{u} = $'+"{}".format(norm.stdev)
str = "Risultato fit:\n"+r'$ Coefficiente\ angolare = $'+"{}".format(fit[0])

ax.text(-12.5,-18.5,str)
ax.set_xlabel(r'$\log(\frac{5}{N^2})$')
ax.set_ylabel(r'$\log(M_{64})$')

ax.legend(["Dati","fit lineare"])
plt.grid(False);

plt.show()