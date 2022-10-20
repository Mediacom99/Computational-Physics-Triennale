import matplotlib.pyplot as plt 
import numpy as np

 

x = np.genfromtxt("doppiaPrecisione.txt", delimiter=',',dtype=float, usecols=0)
y1 = np.genfromtxt("doppiaPrecisione.txt", delimiter=',',dtype=float, usecols=1) 
y2 = np.genfromtxt("doppiaPrecisione.txt", delimiter=',', dtype=float, usecols=2)

yver1 = np.zeros(len(y1), dtype=float)
yver2 = np.zeros(len(y2), dtype=float)
TICKS = np.zeros(950, dtype=float)
TICKSX = [5000, 10000,20000,100000, 500000]
counter = 0.005
for i in range(len(TICKS)):
	TICKS[i]+=counter
	counter+=0.005
for i in range(len(yver1)):
	yver1[i] = np.absolute(y1[i] - np.pi*np.pi/6.0)
for i in range(len(yver2)):
	yver2[i] = np.absolute(y2[i] - np.pi*np.pi/6.0)

#print(x)
#print(yver1)



plt.style.use('_mpl-gallery')

fig = plt.figure()
ax0 = fig.add_subplot(1,1,1)
plt.tight_layout() #fai in modo che il grafico si centri bene nella figura
fig.set_size_inches(30/2.54, 30/2.54)


ax0.scatter(x,yver1, s=12, c="purple")
ax0.scatter(x,yver2, s=12, c="green")
ax0.legend(['Somma diretta','Somma inversa'])


ax0.set_xlabel("N [Integer at which the summation stops]")
ax0.set_ylabel(r'$ | \Delta N = S(N) - \frac{\pi^2}{6} | $')
ax0.set_title("Exercise 1 - Direct Summation - Single_Point_Precision(32bit)")
ax0.set_yticks(TICKS)
ax0.set_yscale('log')
#ax0.set_xticks(TICKSX)

#ax0.plot(x, yver1)
ax0.set(xlim=(np.amin(x), np.amax(x)), ylim=(0,np.amax(yver1) + np.amax(yver1)/4))

plt.show()