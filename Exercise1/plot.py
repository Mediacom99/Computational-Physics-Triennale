import matplotlib.pyplot as plt 
import numpy as np



x = np.genfromtxt("data.txt", delimiter=',',dtype=float, usecols=0)
y = np.genfromtxt("data.txt", delimiter=',',dtype=float, usecols=1)

yver = np.zeros(len(y), dtype=float);

for i in range(len(yver)):
	yver[i] = np.absolute(y[i] - np.pi*np.pi/6.0)

print(x)
print(yver)


plt.style.use('_mpl-gallery')


fig, ax = plt.subplots()
plt.tight_layout() #fai in modo che il grafico si centri bene nella figura
fig.set_size_inches(30/2.54, 30/2.54)


ax.scatter(x,yver)

ax.set_xlabel("N [Integer at which the summation stops]")
ax.set_ylabel("Delta_N = S(N) - pi^2 / 6")
ax.set_title("Exercise 1 - Direct Summation")
ax.set_xscale('log')

#ax.plot(x, yver)
ax.set(xlim=(0, np.amax(x)), ylim=(0,np.amax(yver) + np.amax(yver)/4))

plt.show()