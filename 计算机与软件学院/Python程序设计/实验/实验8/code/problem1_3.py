import numpy as np

A = np.random.randint(0, 10, size=(3, 2))
B = np.random.randint(0, 10, size=(3, 3, 3))
C = np.random.randint(0, 10, size=(3, 1))
# print(A**2)
# print(np.sqrt(A))
# print(A)
# print(C)
# print(A + C)
# print(B + C)
print(B)
B[:, 0:2, 0:2] -= 20
print(B)
