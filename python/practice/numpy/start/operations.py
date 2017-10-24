import numpy as np

a = np.array([(1, 2, 3), (4, 5, 6)])
print(a)
print(a.ndim)
print(a.itemsize)
print(a.size)
print(a.dtype)
print(a.shape)

print(a.reshape(3, 2))
print(a.transpose())
print(a.flatten())
print(a)
print(a[1, 2])
print(a[0:, 1])  # slicing like list

array_1 = np.array([[1, 2, 3], [0, 0, 0]])
array_2 = np.array([[0, 0, 0], [7, 8, 9]])
print(array_1)
print(array_2)
print(np.concatenate((array_1, array_2)))
