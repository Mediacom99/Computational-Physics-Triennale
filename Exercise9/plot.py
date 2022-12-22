import matplotlib.pyplot as plt 
import numpy as np

 

x = np.genfromtxt("gauss.txt",dtype=float);

plt.style.use('_mpl-gallery')

fig = plt.figure()
ax = fig.add_subplot(1,1,1)
plt.tight_layout() #fai in modo che il grafico si centri bene nella figura
fig.set_size_inches(30/2.54, 30/2.54)

n,bins,patches = plt.hist(x,100, density = True, facecolor='g');

plt.grid(True);

plt.show()