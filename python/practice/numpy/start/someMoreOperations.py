import numpy as np

a = np.array([(1, 2, 3), (4, 5, 6), (7, 8, 9)])
print(a.min(), a.max(), a.sum())

print(a.sum(axis=0), a.sum(axis=1))

print(np.sqrt(a))
print(np.std(a))

b = np.array([0, 1, 0])
print(a + b)
print(a - b)
print(a * b)
print(a / b)

print(np.hstack((a, b)))
print(np.vstack((a, b)))
