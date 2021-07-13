import time
import random


# 代码1：创建列表
l = [i for i in range(10**8)]
# l = [i for i in range(10**6)]

# 代码2：创建集合
s = {i for i in range(10**8)}
# s = {i for i in range(10**6)}

startTime = time.time()  # 开始时间
# 代码3：检查一个元素是否在一个集合里
num = random.randint(0, 1e9)
if num in s:
    print("在集合")
else:
    print("不在集合")
# num = 5
# if num in s:
#     print("在集合")
endTime = time.time()  # 结束时间
runTime = int((endTime - startTime) * 1000)
# 代码4：输出结果
print("check runtime for set: ", runTime)


startTime = time.time()  # 开始时间
# 代码5：检查一个元素是否在一个列表里
num = random.randint(0, 1e9)
if num in l:
    print("在集合")
else:
    print("不在集合")
endTime = time.time()  # 结束时间
runTime = int((endTime - startTime) * 1000)
# 代码6：输出结果
print("check runtime for list: ", runTime)

# 代码7：仿照上面例子，测试集合与列表中删除元素在时间上的差别
startTime = time.time()  # 开始时间
# 代码5：检查一个元素是否在一个列表里
num = random.randint(0, 1e8)
l.remove(num)
endTime = time.time()  # 结束时间
runTime = int((endTime - startTime) * 1000)
# 代码6：输出结果
print("remove runtime for list: ", runTime)

startTime = time.time()  # 开始时间
# 代码5：检查一个元素是否在一个列表里
num = random.randint(0, 1e8)
s.remove(num)
endTime = time.time()  # 结束时间
runTime = int((endTime - startTime) * 1000)
# 代码6：输出结果
print("remove runtime for set: ", runTime)
