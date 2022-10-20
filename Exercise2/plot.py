import matplotlib.pyplot as plt 
import numpy as np

 

x = np.genfromtxt("dataSingola.txt", delimiter=',',dtype=int, usecols=1)
y = np.genfromtxt("dataSingola.txt", delimiter=',',dtype=float, usecols=0) 
X = np.genfromtxt("dataQuadruplaE10-8.txt", delimiter=',',dtype=int, usecols=1)
Y = np.genfromtxt("dataQuadruplaE10-8.txt", delimiter=',',dtype=float, usecols=0)


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
ax.scatter(X,Y, s=12, c="green")


ax.set_xlabel("n of " + r'$\phi_{1}^n$')
ax.set_ylabel(r'$\Delta_n = |\chi_n - \phi_{1}^n|$')
ax.set_title("Esercizio 2, precisione singola: "+r'$\chi_{1} = \phi_{1} + \epsilon \phi_{2}$')
ax.legend(["Precisione singola", "Precisione quadrupla con "+r'$\epsilon = 10^{-8}$'])
#az.set_title("Esercizio 2, precisione quadrupla:"+r'$\chi_{1} = \phi_{1} + \epsilon \phi_{2}$')
#ax.set_xticks([198,199,200])
#az.set_xticks([198,199,200])
ax.set_yscale('log')

#ax.plot(x, yver)
#ax.set(xlim=(np.amin(x), 2*np.amax(x)), ylim=(np.amin(x),np.amax(y) + np.amax(y)/4))
ax.set(xlim=(150, 201), ylim=(np.amin(x),np.amax(y) + np.amax(y)/4))
#az.set(xlim=(150, 201), ylim=(np.amin(x),np.amax(y) + np.amax(y)/4))



plt.show()