from matrix import *

M = [[5, 6, 7], [0, -3, 5]]
v = [[1], [2], [3]]

print(matrix_dim(M))
print(mult_M_v(M, v))
print(transpose(M))
print(large_col_sum(M))
print(switch_columns(M, 1, 2))
