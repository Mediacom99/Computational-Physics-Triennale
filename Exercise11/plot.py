import matplotlib.pyplot as plt 
import numpy as np

 

x = np.genfromtxt("pdf3.txt", delimiter=' ',dtype=float, usecols=0)



plt.style.use('_mpl-gallery')

#fig = plt.figure()
#ax = fig.add_subplot(1,1,1)
#fig.set_size_inches(30/2.54, 30/2.54)
fig,ax = plt.subplots(layout="constrained");

n_bins = 100;
ax.hist(x, bins=n_bins, density=True);
#fit = np.polyfit(N,x,1)
#fitSimpson = np.polyfit(X,Y,1)
#print(fit)
#print(fitSimpson)
lsp = np.linspace(0,10,10000)
y = 2*lsp*np.exp(-lsp*lsp) 	

#t = np.poly1d(fit)
#s = np.poly1d(fitSimpson)
ax.plot(lsp,y, color = 'purple')
#ax.plot(lsp,s(lsp))
#ax.scatter(N,x, s=20, c="purple")
#ax.scatter(X,Y, s=20, c="green")
#ax.scatter(A,B, s=12, c="red")




#ax.text(0.95, 0.01, "Coefficienti angolari:\nTrapezio: 2.16 Simpson: 4.19",
# `       verticalalignment='bottom', horizontalalignment='right',
#        transform=ax.transAxes,
#        color='black', fontsize=10)


#ax.set_xlabel(r'$\log{(\frac{1}{N})}$')
#ax.set_ylabel("Discrepanza |Valore vero - valore calcolato| (log)")
ax.set_title("Istogramma valori "+r'$f_3(x)$')
ax.legend([r'$f_3(x)$',"Valori"])
#az.set_title("Esercizio 2, precisione quadrupla:"+r'$\chi_{1} = \phi_{1} + \epsilon \phi_{2}$')
#ax.set_xticks([198,199,200])
#az.set_xticks([198,199,200])
#ax.set_yscale('log')
#ax.set_xscale('log')
#ax.plot(x, yver)
#ax.set(xlim=(np.amin(x), 2*np.amax(x)), ylim=(np.amin(x),np.amax(y) + np.amax(y)/4))
#ax.set(xlim=(np.amin([np.amin(x),np.amin(x)]), (np.amax([np.amax(x),np.amax(x)]))), 
	#ylim=(np.amin([np.amin(y),np.amin(y)]), (np.amax([np.amax(y),np.amax(y)]))))
#az.set(xlim=(150, 201), ylim=(np.amin(x),np.amax(y) + np.amax(y)/4))
#ax.set(xlim=(np.amin(x)*0.75,np.amax(x)*1.5),ylim=(np.amin(x)*0.75,np.amax(x)*1.5))

#plt.tight_layout()


plt.show()