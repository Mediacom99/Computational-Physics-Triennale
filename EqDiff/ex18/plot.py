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


ax.scatter(x3[0],y3[0],z3[0], color="green", marker="*")
ax.scatter(x[0],y[0],z[0], color="black", marker="*")
ax.scatter(x2[0],y2[0],z2[0], color="red", marker="*")
ax.plot(x,y,z, color="black"); 
ax.plot(x2,y2,z2, color="red");
ax.plot(x3,y3,z3, color="green");
ax.legend([r'$\vec{R}_3(t=0)$',r'$\vec{R}_1(t=0)$',
    r'$\vec{R}_2(t=0)$',r'$\vec{R}_1(t)$',r'$\vec{R}_2(t)$',r'$\vec{R}_3(t)$'], loc="upper right");
ax.set_xlabel("x");
ax.set_ylabel("y");
ax.set_zlabel("z")
fig.suptitle("Problema a 3 corpi gravitazionale: set dati iniziali 2\n h = 0.001 , T = 30s");


plt.show()