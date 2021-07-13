import numpy as np

from numpy import linalg
A = np.array([[2, 1, -2], [1, -1, -1], [1, 1, 3]])
b = np.array([3, 0, 12])
x = linalg.solve(A, b)
print(x)
