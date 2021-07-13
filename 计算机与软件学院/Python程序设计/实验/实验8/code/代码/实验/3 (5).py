def isconsecurivefour(list1):
    for i in range(len(list1)-3):
        if list1[i:i+4].count(list1[i]) == 4:
            return True
    return False


list = input().split(',')
list = [int(list[i]) for i in range(len(list))]
if isconsecurivefour(list):
    print("包含四个连续相等的数字")
else:
    print("不包含四个连续相等的数字")
