import matplotlib.pyplot as plt 
import numpy as np

 #PLOT EQUAZIONI DIFFERENZIALI

x = np.genfromtxt("DataE.txt", delimiter=',',dtype=np.longdouble, usecols=0)
y = np.genfromtxt("DataE.txt", delimiter=',',dtype=np.longdouble, usecols=1)

A = np.genfromtxt("DataRK2.txt", delimiter=',',dtype=np.longdouble, usecols=0)
B = np.genfromtxt("DataRK2.txt", delimiter=',',dtype=np.longdouble, usecols=1) 



plt.style.use('_mpl-gallery')

fig = plt.figure()
ax = fig.add_subplot(1,1,1)
plt.tight_layout() #fai in modo che il grafico si centri bene nella figura
fig.set_size_inches(30/2.54, 30/2.54)


lsp = np.linspace(0,np.amax(A),1000)


ax.plot(x,y, color = "green") #Eulero
ax.plot(A,B, color = "red");  #Runge Kutta 2


ax.plot(lsp,np.sin(lsp), color = "blue")


ax.set_xlabel("x")
ax.set_ylabel("f(x)")
ax.set_title("Risoluzione equazione differenziale oscillatore armonico")
ax.legend(["Eulero","Runge-Kutta 2","Funzione teorica"])

ax.set(xlim=(0,np.amax(x)),ylim=(-10.5,10.5))

plt.show()