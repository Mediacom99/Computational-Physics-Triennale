import matplotlib.pyplot as plt 
import numpy as np

 #PLOT EQUAZIONI DIFFERENZIALI

filename = "XYZtData4.txt"

x = np.genfromtxt(filename, delimiter=',',dtype=np.longdouble, usecols=0)
y = np.genfromtxt(filename, delimiter=',',dtype=np.longdouble, usecols=1)

z = np.genfromtxt(filename, delimiter=',',dtype=np.longdouble, usecols=2)
t = np.genfromtxt(filename, delimiter=',',dtype=np.longdouble, usecols=3) 



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



ax.plot(y,z, color="black"); 
ax.legend(["RK4-"+r'$h=\frac{1}{144}$']);
ax.set_xlabel("y");
ax.set_ylabel("z");


ax.set_title("Attrattore di Lorenz - Piano (y,z) - Runge Kutta 4\n[Time=60s], Dati iniziali: [0.45,7,2]");

plt.show()