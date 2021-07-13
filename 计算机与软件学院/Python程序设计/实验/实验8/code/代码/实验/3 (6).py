def is_almost_symmetric(list1):
    if list1 == list1[::-1]:
        return False, None, None
    for i in range(len(list1)):
        for j in range(i+1, len(list1)):
            temp = list1[:]
            temp[i], temp[j] = temp[j], temp[i]
            if temp == temp[::-1]:
                return True, i, j
    return False, None, None


list1 = [1, 2, 2, 3, 7, 1]
bool, i, j = is_almost_symmetric(list1)
if bool:
    print("{}是“几乎对称”列表，交换第{}和第{}个元素".format(list1, i+1, j+1))
else:
    print("{}不是“几乎对称”列表".format(list1))
