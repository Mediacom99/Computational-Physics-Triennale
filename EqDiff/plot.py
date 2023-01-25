import matplotlib.pyplot as plt 
import numpy as np

 #PLOT EQUAZIONI DIFFERENZIALI

x = np.genfromtxt("DataE.txt", delimiter=',',dtype=np.longdouble, usecols=0)
y = np.genfromtxt("DataE.txt", delimiter=',',dtype=np.longdouble, usecols=1)

A = np.genfromtxt("DataRK2.txt", delimiter=',',dtype=np.longdouble, usecols=0)
B = np.genfromtxt("DataRK2.txt", delimiter=',',dtype=np.longdouble, usecols=1) 

C = np.genfromtxt("DataRK4.txt", delimiter=',',dtype=np.longdouble, usecols=0)
D = np.genfromtxt("DataRK4.txt", delimiter=',',dtype=np.longdouble, usecols=1)

h = np.genfromtxt("h.txt", dtype=np.double, usecols=0)
E = np.genfromtxt("devsE.txt", dtype=np.double, usecols=0)
RK2 = np.genfromtxt("devsRK2.txt", dtype=np.double, usecols=0)
RK4 = np.genfromtxt("devsRK4.txt", dtype=np.double, usecols=0)

plt.style.use('_mpl-gallery')

#fig,axs = plt.subplots(1, sharex=True, sharey=True)
fig = plt.figure()
ax = fig.add_subplot(1,1,1)
plt.tight_layout() #fai in modo che il grafico si centri bene nella figura
fig.set_size_inches(30/2.54, 30/2.54)


lsp = np.linspace(-8,2,1000)

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


ax.scatter(h,E, color = "green", s=1)
ax.scatter(h,RK2, color="red",s=1)
ax.scatter(h,RK4, color="purple",s=1)
#ax.plot(lsp,np.sin(lsp) - 10, color = "blue")
#axs[1].plot(C,D, color = "purple")

ax.set_xlabel("h, passi di integrazione")
ax.set_ylabel("Deviazioni dalla soluzione esatta")
ax.set_title("Deviazione dalla soluzione esatta a x = " + r'$\frac{\pi}{2}$')
ax.legend(["Eulero","Runge Kutta 2","Runge Kutta 4"], loc="upper left")
#axs[1].legend(["Runge Kutta 4"])
#axs[2].legend(["Soluzione esatta"])


ax.set(xlim=(np.amin(h) - 5,np.amax(h) + 5),ylim=(np.amin(E)-5,np.amax(E)+5))


plt.show()