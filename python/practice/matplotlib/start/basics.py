from matplotlib import pyplot as plt
from matplotlib import style

style.use('ggplot')

x = [4, 5, 8]
y = [0, 10, 0]

x2 = [2, 5, 10]
y2 = [0, 10, 0]

plt.plot(x, y, 'g', label='line 1', linewidth=5)
plt.plot(x2, y2, 'c', label='line 2', linewidth=5)
plt.title("info")
plt.xlabel('X-AXIS')
plt.ylabel('Y-AXIS')
plt.legend()
plt.grid(True, color='k')
plt.show()
