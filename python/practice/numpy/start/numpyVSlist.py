import numpy as np
import sys
import time

my_array = np.array([(1, 2, 3), (4, 5, 6)], float)
print(np.transpose(my_array))

# SHOWING NUMPY TAKES LESS MEMORY THAN LIST
# SPACE COMPLEXITY
s = list(range(1000))
print(sys.getsizeof(0) * len(s))

d = np.arange(1000)
print(d.size * d.itemsize)  # SHOWING NUMPY TAKES LESS MEMORY THAN LIST

# TIME COMPLEXITY
SIZE = 1000000
L1 = list(range(SIZE))
L2 = list(range(SIZE))
start = time.time()
result = [x + y for x, y in zip(L1, L2)]
print((time.time() - start) * 1000)

A1 = np.arange(SIZE)
A2 = np.arange(SIZE)
start = time.time()
result = A1 + A2
print((time.time()-start)*1000)

