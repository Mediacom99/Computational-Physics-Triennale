import matplotlib.pyplot as plt 
import numpy as np

 #PLOT EQUAZIONI DIFFERENZIALI

filename = "energia.txt"

e = np.genfromtxt(filename, delimiter=',',dtype=float, usecols=0)
t = np.genfromtxt(filename, delimiter=',',dtype=float, usecols=1)



#h = np.genfromtxt("h.txt", dtype=np.double, usecols=0)
#E = np.genfromtxt("devsE.txt", dtype=np.double, usecols=0)
#RK2 = np.genfromtxt("devsRK2.txt", dtype=np.double, usecols=0)
#RK4 = np.genfromtxt("devsRK4.txt", dtype=np.double, usecols=0)

plt.style.use('_mpl-gallery')

#fig,axs = plt.subplots(1, sharex=True, sharey=True)
#fig = plt.figure(layout="constrained")
#ax = plt.figure().add_subplot(projection="3d")
ax = plt.figure().add_subplot();
plt.tight_layout() #fai in modo che il grafico si centri bene nella figura
#fig.set_size_inches(30/2.54, 30/2.54)



ax.plot(t,e, color="black"); 
ax.legend(["E(t)"]);
ax.set_title("Energia totale del sistema in funzione del tempo - Set dati iniziali 2\n h = 0.001 , T = 10s");
ax.set_xlabel("t");
ax.set_ylabel("E(t)");

#ax.set_title("Attrattore di Lorenz - Piano (y,z) - Runge Kutta 4\n[Time=60s], Dati iniziali: [0.45,7,2]");

plt.show()