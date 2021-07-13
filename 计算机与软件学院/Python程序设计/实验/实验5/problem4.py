def print_yanghui_triangle(N):
    triangle = [['1'] for i in range(N)]
    for i in range(1, N):
        triangle[i].extend(str(int(triangle[i-1][j])+int(triangle[i-1][j+1]))
                           for j in range(len(triangle[i-1])-1))
        triangle[i].append('1')

    for i in range(len(triangle)):
        # print('{:^30}'.format(' '.join(triangle[i])))
        print(' '.join(triangle[i]).center(len(' '.join(triangle[N-1]))))


N = int(input('N:'))
print_yanghui_triangle(N)
