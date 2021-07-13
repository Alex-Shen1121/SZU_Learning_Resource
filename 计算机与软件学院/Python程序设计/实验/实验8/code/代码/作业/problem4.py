import os
import string


def offByOne(str1, str2):
    l1, l2 = len(str1), len(str2)
    if l1 != l2:
        return False
    cnt = 0
    for i in range(l1):
        if(str1[i] != str2[i]):
            cnt += 1
        if cnt > 1:
            return False
    return True


def offBySwap(str1, str2):
    l1, l2 = len(str1), len(str2)
    if l1 != l2 or str1 == str2:
        return False
    for i in range(l1-1):
        str3 = str2[:i]+str2[i+1]+str2[i]+str2[i+2:]
        if str1 == str3:
            return True
    return False


def offByExtra(str1, str2):
    l1, l2 = len(str1), len(str2)
    if abs(l1-l2) != 1:
        return False
    if l2 > l1:
        str1, str2 = str2, str1
        l = l2
    else:
        l = l1
    for i in range(l):
        str3 = str1[:i]+str1[i+1:]
        if str2 == str3:
            return True
    return False


def ListOfNeighbors(str, L):
    print(str, "的邻居：")
    sum = 1
    for x in L:
        if offByExtra(str, x) or offByOne(str, x) or offBySwap(str, x):
            if sum % 5 != 0:
                print(x, end=' ')
            else:
                print(x)
            sum += 1
    print("\n一共", sum - 1, "个")

# list1 = [["read", "rexd"], ["read", "xexd"],
#          ["read", "readx"], ["read", "eadx"],
#          ["a", "x"], ["a", "a"], ["a", "A"]]
# for x in list1:
#     print("str1 =", x[0], "str2 =", x[1], "   ", offByOne(x[0], x[1]))


# list2 = [["read", "raed"], ["read", "erad"],
#          ["reaxd", "read"], ["read", "erda"],
#          ["read", "erbx"], ["x", "Y"],
#          ["aaa", "aaa"]]
# for x in list2:
#     print("str1 =", x[0], "str2 =", x[1], "   ", offBySwap(x[0], x[1]))

# list3 = [["abcd", "abxcd"], ["abxcd", "abcd"],
#          ["abcda", "abcd"], ["abcd", "bcda"],
#          ["abcd", "abcdef"], ["abcd", "abcd"]]
# for x in list3:
#     print("str1 =", x[0], "str2 =", x[1], "   ", offByExtra(x[0], x[1]))

f = open("EnglishWords.txt", mode='r')
wordList = []
while True:
    line = f.readline()
    if not line:
        break
    wordList.append(line[:-1])

Str = "code"
ListOfNeighbors(Str, wordList)
