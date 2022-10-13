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


ax.plot(x, yver)
ax.set(xlim=(0, np.amax(x)), ylim=(0,np.amax(yver)))

plt.show()