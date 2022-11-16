import matplotlib.pyplot as plt 
import numpy as np

 

x1 = np.genfromtxt("numeroDiPunti.txt", delimiter=',',dtype=float, usecols=0)
x2 = np.genfromtxt("numeroDiPunti2.txt", delimiter=',',dtype=float, usecols=0)
x3 = np.genfromtxt("numeroDiPuntiGIUSTI.txt", delimiter=',',dtype=float, usecols=0)
y1 = np.genfromtxt("datiRColonna1.txt", delimiter=',',dtype=float, usecols=0) 
y2 = np.genfromtxt("datiRColonna2.txt", delimiter=',',dtype=float, usecols=0)
y3 = np.genfromtxt("datiRColonna3GIUSTI.txt", delimiter=',',dtype=float, usecols=0)
#print(y)
#print(np.amin(y))
#print(np.amax(y))
#yver = np.zeros(len(y), dtype=float);
#TICKS = np.zeros(950, dtype=float)
#counter = 0.005
#for i in range(len(TICKS)):
#	TICKS[i]+=counter
#	counter+=0.005
#for i in range(len(yver)):
#	yver[i] = np.absolute(y[i] - np.pi*np.pi/6.0)

#print(x)
#print(yver)


plt.style.use('_mpl-gallery')

fig = plt.figure()
ax = fig.add_subplot(1,1,1)
plt.tight_layout() #fai in modo che il grafico si centri bene nella figura
fig.set_size_inches(30/2.54, 30/2.54)


fitTrapezio = np.polyfit(x1,y1,1)
fitSimpson = np.polyfit(x2,y2,1)
fit3 = np.polyfit(x3,y3,1)
print(fitTrapezio)
print(fitSimpson)
print(fit3)
lsp = np.linspace(-9,-0.5,10000)
t = np.poly1d(fitTrapezio)
s = np.poly1d(fitSimpson)
f3 = np.poly1d(fit3)
ax.plot(lsp,t(lsp), color="purple")
ax.plot(lsp,s(lsp), color="green")
ax.plot(lsp,f3(lsp), color="red")
ax.scatter(x1,y1, s=20, c="purple")
ax.scatter(x2,y2, s=20, c="green")
ax.scatter(x3,y3, s=20, c="red")
#ax.scatter(A,B, s=12, c="red")


ax.set_xlabel(r'$\log{(\frac{1}{N})}$')
ax.set_ylabel("Discrepanza |Valore vero - valore calcolato|")
ax.set_title("Andamenti Metodo di Romberg")
ax.legend(["Colonna 1(Trapezio): "+r'$\frac{1}{N^{2}}$',"Colonna 2(Simpson): "+r'$\frac{1}{N^{4}}$',"Colonna 3: "+r'$\frac{1}{N^{6}}$'])
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
ax.set(xlim=(-9,-0.5),ylim=(-33,1))

plt.show()