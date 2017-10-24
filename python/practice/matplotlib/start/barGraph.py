from matplotlib import pyplot as plt

plt.bar([1, 3, 5, 7, 9], [5, 2, 7, 8, 2], label='one', color='c')
plt.bar([2, 4, 6, 8, 10], [8, 6, 2, 5, 6], label='two', color='g')
plt.legend()
plt.title('Info')
plt.xlabel('X value')
plt.ylabel('Y value')
plt.title('Info')
plt.show()
