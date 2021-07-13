import numpy as np

n = int(input("请输入n："))
mat = np.random.randint(0, 100, (2*n, 2*n))
res = np.array([np.average(mat[:n, :n]),
                np.average(mat[0:n, n:2*n]),
                np.average(mat[n:2*n, :n]),
                np.average(mat[n:2*n, n:2*n])]).reshape(2, 2)
print("mat:\n", mat)
print("res:\n", res)
