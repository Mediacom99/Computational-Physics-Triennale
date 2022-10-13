import matplotlib.pyplot as plt 
import numpy as np

 

x = np.genfromtxt("data.txt", delimiter=',',dtype=float, usecols=0)
y = np.genfromtxt("data.txt", delimiter=',',dtype=float, usecols=2) 

yver = np.zeros(len(y), dtype=float);
ticks = np.zeros(950, dtype=float)
counter = 0.005
for i in range(len(ticks)):
	ticks[i]+=counter
	counter+=0.005
for i in range(len(yver)):
	yver[i] = np.absolute(y[i] - np.pi*np.pi/6.0)

print(x)
print(yver)



plt.style.use('_mpl-gallery')


fig, ax = plt.subplots()
plt.tight_layout() #fai in modo che il grafico si centri bene nella figura
fig.set_size_inches(30/2.54, 30/2.54)


ax.scatter(x,yver, s=12, c="purple")


ax.set_xlabel("N [Integer at which the summation stops] - logscale")
ax.set_ylabel(r'$ | \Delta N = S(N) - \frac{\pi^2}{6} | $')
ax.set_title("Exercise 1 - Inverse Summation - Quadruple_point_precision (128bit)")
ax.set_yticks(ticks)
#ax.set_xscale('log')

#ax.plot(x, yver)
ax.set(xlim=(0, np.amax(x)), ylim=(0,np.amax(yver) + np.amax(yver)/4))

plt.show()