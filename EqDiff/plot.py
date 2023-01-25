import matplotlib.pyplot as plt 
import numpy as np

 #PLOT EQUAZIONI DIFFERENZIALI

x = np.genfromtxt("DataE.txt", delimiter=',',dtype=np.longdouble, usecols=0)
y = np.genfromtxt("DataE.txt", delimiter=',',dtype=np.longdouble, usecols=1)

A = np.genfromtxt("DataRK2.txt", delimiter=',',dtype=np.longdouble, usecols=0)
B = np.genfromtxt("DataRK2.txt", delimiter=',',dtype=np.longdouble, usecols=1) 

C = np.genfromtxt("DataRK4.txt", delimiter=',',dtype=np.longdouble, usecols=0)
D = np.genfromtxt("DataRK4.txt", delimiter=',',dtype=np.longdouble, usecols=1)

h = np.array([0.9,0.5,0.1,0.05,0.01,0.005,0.001])
E = np.array([0.90000000000000002220,1.3750000000,1.0743914914,1.0392067962,1.00788013351727952433,1.00393233478518400029,1.00078499006596076046]) 
RK2 = np.array([0.90000000000000002220,1.0234375000,0.9978552766,0.9998211900,0.99999989967605931301,0.99999971265094572426,0.99999968333642241623])
RK4 = np.array([0.77849999999999996996,0.9971297935,0.9974947947,0.9997837592,0.99999968293064017341,0.99999968293179403715,0.99999968293183459796])

for i in range(len(h)):
	h[i] = np.log(h[i])

for i in range(len(h)):
	E[i] = np.log(np.absolute(1 - E[i]))

for i in range(len(h)):
	RK2[i] = np.log(np.absolute(1 - RK2[i]))

for i in range(len(h)):
	RK4[i] = np.log(np.absolute(1 - RK4[i]))


plt.style.use('_mpl-gallery')

#fig,axs = plt.subplots(1, sharex=True, sharey=True)
fig = plt.figure()
ax = fig.add_subplot(1,1,1)
plt.tight_layout() #fai in modo che il grafico si centri bene nella figura
fig.set_size_inches(30/2.54, 30/2.54)


lsp = np.linspace(np.amin(h),np.amax(h),1000)

#fig.text(0.5,0.04,"x", ha='center')
#fig.text(0.04,0.5, "f(x)", va='center',rotation='vertical')

#ax.plot(x,y, color = "green") #Eulero
#ax.plot(A,B, color = "red")  #Runge Kutta 2
#ax.plot(C,D, color = "purple") #RK4
fitE = np.polyfit(h,E,1)
Ef = np.poly1d(fitE)
ax.plot(lsp,Ef(lsp), color="green")

fitRK2 = np.polyfit(h,RK2,1)
RK2f = np.poly1d(fitRK2)
ax.plot(lsp,RK2f(lsp), color="red")

fitRK4 = np.polyfit(h,RK4,1)
RK4f = np.poly1d(fitRK4)
ax.plot(lsp,RK4f(lsp), color="purple")


ax.scatter(h,E, color = "green")
ax.scatter(h,RK2, color="red")
ax.scatter(h,RK4, color="purple")
#ax.plot(lsp,np.sin(lsp) - 10, color = "blue")
#axs[1].plot(C,D, color = "purple")

ax.set_xlabel("h, passi di integrazione")
ax.set_ylabel("Deviazioni dalla soluzione esatta")
ax.set_title("Deviazione dalla soluzione esatta a x = " + r'$\frac{\pi}{2}$')
ax.legend(["Eulero","Runge Kutta 2","Runge Kutta 4"])
#axs[1].legend(["Runge Kutta 4"])
#axs[2].legend(["Soluzione esatta"])


ax.set(xlim=(np.amin(h) - 5,np.amax(h) + 5),ylim=(np.amin(E)-5,np.amax(E)+5))


plt.show()