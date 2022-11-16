import matplotlib.pyplot as plt 
import numpy as np

 

x = np.genfromtxt("ex3TrapezioPlot.txt", delimiter=',',dtype=float, usecols=0)
y = np.genfromtxt("ex3TrapezioPlot.txt", delimiter=',',dtype=float, usecols=2) 
X = np.genfromtxt("ex3SimpsonPlot.txt", delimiter=',',dtype=float, usecols=0)
Y = np.genfromtxt("ex3SimpsonPlot.txt", delimiter=',',dtype=float, usecols=2)
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


fitTrapezio = np.polyfit(x,y,1)
fitSimpson = np.polyfit(X,Y,1)
print(fitTrapezio)
print(fitSimpson)
lsp = np.linspace(-6,-0,5, 1000)
t = np.poly1d(fitTrapezio)
s = np.poly1d(fitSimpson)
ax.plot(lsp,t(lsp))
ax.plot(lsp,s(lsp))
ax.scatter(x,y, s=20, c="purple")
ax.scatter(X,Y, s=20, c="green")
#ax.scatter(A,B, s=12, c="red")


ax.set_xlabel(r'$\log{(\frac{1}{N})}$')
ax.set_ylabel("Discrepanza |Valore vero - valore calcolato|")
ax.set_title("Andamento Trapezio vs Simpson")
ax.legend(["Fit trapezio y = 2x + q","Fit Simpson y = 4x+q","Metodo del trapezio","Metodo di Simpson"])
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
ax.set(xlim=(-6,-0.5),ylim=(-15,5))

plt.show()