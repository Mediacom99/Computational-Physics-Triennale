import matplotlib.pyplot as plt 
import numpy as np

 #PLOT EQUAZIONI DIFFERENZIALI

x = np.genfromtxt("DataE.txt", delimiter=',',dtype=np.longdouble, usecols=0)
y = np.genfromtxt("DataE.txt", delimiter=',',dtype=np.longdouble, usecols=1)

A = np.genfromtxt("DataRK2.txt", delimiter=',',dtype=np.longdouble, usecols=0)
B = np.genfromtxt("DataRK2.txt", delimiter=',',dtype=np.longdouble, usecols=1) 



plt.style.use('_mpl-gallery')

fig,axs = plt.subplots(2, sharex=True)
#ax = fig.add_subplot(1,1,1)
plt.tight_layout() #fai in modo che il grafico si centri bene nella figura
fig.set_size_inches(30/2.54, 30/2.54)


lsp = np.linspace(0,np.amax(A),1000)


axs[0].plot(x,y, color = "green") #Eulero
axs[0].plot(A,B, color = "red");  #Runge Kutta 2


axs[0].plot(lsp,np.sin(lsp), color = "blue")


axs[0].set_xlabel("x")
axs[0].set_ylabel("f(x)")
axs[0].set_title("Risoluzione equazione differenziale oscillatore armonico")
axs[0].legend(["Eulero","Funzione teorica"])
axs[1].legend(["Runge Kutta 2"])

axs[0].set(xlim=(0,np.amax(x)),ylim=(-10.5,10.5))
axs[1].set(xlim=(0,np.amax(x)),ylim=(-10.5,10.5))

plt.show()