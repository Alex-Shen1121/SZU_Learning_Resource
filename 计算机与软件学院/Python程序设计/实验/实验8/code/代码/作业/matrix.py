def matrix_dim(M):
    return [len(M), len(M[0])]


def mult_M_v(M, v):
    if len(M[0]) != len(v):
        return '非法输入'
    n, m = len(M), len(M[0])
    ans = []
    for i in range(n):
        sum = 0
        for j in range(m):
            sum += M[i][j]*v[j][0]
        ans.append([sum])
    return ans


def transpose(M):
    n, m = len(M), len(M[0])
    return [[M[j][i] for j in range(n)] for i in range(m)]


def large_col_sum(M):
    n, m = len(M), len(M[0])
    return max([sum([M[i][j] for i in range(n)]) for j in range(m)])


def switch_columns(M, i, j):
    n, m = len(M), len(M[0])
    if (i <= 0 or i > m or j <= 0 or j > m):
        return '非法输入'
    i = i-1
    j = j-1
    ans = M
    for k in range(n):
        ans[k][i], ans[k][j] = ans[k][j], ans[k][i]
    return ans
