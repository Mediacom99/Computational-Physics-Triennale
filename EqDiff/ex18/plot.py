import matplotlib.pyplot as plt 
import numpy as np

 #PLOT EQUAZIONI DIFFERENZIALI

filename = "data1.txt"
filename2 = "data2.txt"
filename3 = "data3.txt"

x = np.genfromtxt(filename, delimiter=',',dtype=np.longdouble, usecols=0)
y = np.genfromtxt(filename, delimiter=',',dtype=np.longdouble, usecols=1)
z = np.genfromtxt(filename, delimiter=',',dtype=np.longdouble, usecols=2)

x2 = np.genfromtxt(filename2, delimiter=',',dtype=np.longdouble, usecols=0)
y2 = np.genfromtxt(filename2, delimiter=',',dtype=np.longdouble, usecols=1)
z2 = np.genfromtxt(filename2, delimiter=',',dtype=np.longdouble, usecols=2)

x3 = np.genfromtxt(filename3, delimiter=',',dtype=np.longdouble, usecols=0)
y3 = np.genfromtxt(filename3, delimiter=',',dtype=np.longdouble, usecols=1)
z3 = np.genfromtxt(filename3, delimiter=',',dtype=np.longdouble, usecols=2)


#h = np.genfromtxt("h.txt", dtype=np.double, usecols=0)
#E = np.genfromtxt("devsE.txt", dtype=np.double, usecols=0)
#RK2 = np.genfromtxt("devsRK2.txt", dtype=np.double, usecols=0)
#RK4 = np.genfromtxt("devsRK4.txt", dtype=np.double, usecols=0)

plt.style.use('_mpl-gallery')

#fig,axs = plt.subplots(1, sharex=True, sharey=True)
#fig = plt.figure(layout="constrained")
plt.tight_layout() #fai in modo che il grafico si centri bene nella figura
fig = plt.figure(figsize=(30,11))
ax = fig.add_subplot(projection="3d")
#ax = plt.figure().add_subplot();
#fig.set_size_inches(30/2.54, 30/2.54)


ax.scatter(x3[0],y3[0],z3[0], color="purple")
ax.plot(x,y,z, color="black"); 
ax.plot(x2,y2,z2, color="red");
ax.plot(x3,y3,z3, color="green");
#ax.legend(["RK4-"+r'$h=\frac{1}{144}$']);
#ax.set_xlabel("y");
#ax.set_ylabel("z");
#ax.set_title("Attrattore di Lorenz - Piano (y,z) - Runge Kutta 4\n[Time=60s], Dati iniziali: [0.45,7,2]");

plt.show()