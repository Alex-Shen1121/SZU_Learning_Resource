dic = {str(x): 0 for x in range(10)}

telnum = input("请输入电话号码：")
for x in telnum:
    if x in dic.keys():
        dic[x] = dic[x] + 1

print(dic)
