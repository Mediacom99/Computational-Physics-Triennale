import matplotlib.pyplot as plt 
import numpy as np


matrix = np.loadtxt("data.txt", dtype="i", delimiter=",")

plt.style.use('_mpl-gallery')

fig = plt.figure()
ax = fig.add_subplot();
c = ax.pcolor(matrix, cmap="plasma")
plt.tight_layout() #fai in modo che il grafico si centri bene nella figura
fig.colorbar(c, ax=ax);
#fig.set_size_inches(30/2.54, 30/2.54)


#ax.set_xlabel(r't')
#ax.set_ylabel(r'$\frac{d\theta}{dt}$')
#ax.set_title("Equazione Esercizio 16 - (RK4): "+ r'$\frac{d\theta}{dt}(t)$' + " - [Caso B, h = 0.01]")
#ax.legend(["RK4"], loc="upper right")


plt.show()