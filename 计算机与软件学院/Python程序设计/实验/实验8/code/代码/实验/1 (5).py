list = ['1', '2', '5', '8']
for i in range(4):
    for j in range(4):
        for k in [1, 3]:
            if i != j and j != k and i != k:
                str = list[i]+list[j]+list[k]
                print(str)
