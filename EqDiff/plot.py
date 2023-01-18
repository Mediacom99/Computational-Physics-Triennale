import matplotlib.pyplot as plt 
import numpy as np

 #PLOT EQUAZIONI DIFFERENZIALI

x = np.genfromtxt("DataE.txt", delimiter=',',dtype=float, usecols=0)
y = np.genfromtxt("DataE.txt", delimiter=',',dtype=float, usecols=1)

A = np.genfromtxt("DataRK2.txt", delimiter=',',dtype=float, usecols=0)
B = np.genfromtxt("DataRK2.txt", delimiter=',',dtype=float, usecols=1) 

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


#fitTrapezio = np.polyfit(x,y,1)
#fitSimpson = np.polyfit(X,Y,1)
#print(fitTrapezio)
#print(fitSimpson)
lsp = np.linspace(0,np.amax(A),1000)
#t = np.poly1d(fitTrapezio)
#s = np.poly1d(fitSimpson)


ax.plot(x,y, color = "green") #Eulero
ax.plot(A,B, color = "red");  #Runge Kutta 2


ax.plot(lsp,np.sin(lsp), color = "blue")
#ax.plot(lsp,s(lsp))
#ax.scatter(x,y, s=20, c="purple")
#ax.scatter(X,Y, s=20, c="green")
#ax.scatter(A,B, s=12, c="red")

#ax.text(0.95, 0.01, "Coefficienti angolari:\nTrapezio: 2.16 Simpson: 4.19",
#        verticalalignment='bottom', horizontalalignment='right',
#        transform=ax.transAxes,
#        color='black', fontsize=10)


ax.set_xlabel("x")
ax.set_ylabel("f(x)")
ax.set_title("Risoluzione equazione differenziale oscillatore armonico")
ax.legend(["Eulero","Runge-Kutta 2","Funzione teorica"])
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
ax.set(xlim=(0,np.amax(x)),ylim=(-10.5,10.5))

plt.show()