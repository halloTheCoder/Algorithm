import numpy as np
import matplotlib.pyplot as plt

x = np.arange(0, 3 * np.pi, 0.1)
y = np.sin(x)
z = np.cos(x)
plt.plot(x, y)
plt.show()
plt.plot(x, z)
plt.show()

a = np.arange(0, 10, 0.1)
b = np.exp(a)
c = np.log(a)
d = np.log10(a)

plt.plot(a, b)
plt.show()

plt.plot(a, c)
plt.show()

plt.plot(a, d)
plt.show()
