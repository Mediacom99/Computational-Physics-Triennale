import matplotlib.pyplot as plt 
import numpy as np

 

x = np.genfromtxt("ex3TrapezioPlot.txt", delimiter=',',dtype=float, usecols=0)
y = np.genfromtxt("ex3TrapezioPlot.txt", delimiter=',',dtype=float, usecols=2) 

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


ax.scatter(x,y, s=12, c="purple")
#ax.scatter(X,Y, s=12, c="green")
#ax.scatter(A,B, s=12, c="red")


ax.set_xlabel(r'$\log{(\frac{1}{N})}$')
ax.set_ylabel("Discrepanza |Valore vero - valore calcolato|")
ax.set_title("Metodo del trapezio")
#ax.legend(["Metodo del trapezio"])
#az.set_title("Esercizio 2, precisione quadrupla:"+r'$\chi_{1} = \phi_{1} + \epsilon \phi_{2}$')
#ax.set_xticks([198,199,200])
#az.set_xticks([198,199,200])
ax.set_yscale('log')
ax.set_xscale('log')
#ax.plot(x, yver)
#ax.set(xlim=(np.amin(x), 2*np.amax(x)), ylim=(np.amin(x),np.amax(y) + np.amax(y)/4))
ax.set(xlim=(np.amin(x), np.amax(x)), ylim=(np.amin(y),np.amax(y)))
#az.set(xlim=(150, 201), ylim=(np.amin(x),np.amax(y) + np.amax(y)/4))



plt.show()