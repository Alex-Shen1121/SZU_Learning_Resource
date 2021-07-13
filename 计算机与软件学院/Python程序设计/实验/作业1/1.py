def offByOne(str1,str2):
    l1 = len(str1)
    l2 = len(str2)
    flag = -1
    if l1 != l2:
        return False
    else:
        if l1 == 1 and l2 == 1:
            return True
        for i in range(0,l1):
            if str1[i] != str2[i]:
                flag+=1
        if flag > 0:
            return False
        else:
            return True

def offBySwap(str1,str2):
    l1 = len(str1)
    l2 = len(str2)
    flag = -1
    pos1 = -1
    pos2 = -1
    if l1 != l2:
        return False
    else:
        for i in range(0, l1):
            if str1[i] != str2[i]:
                    pos1 = i
                    pos2 = i+1
                    break
        str3 = str1[0:pos1]+str1[pos2]+str1[pos1+1:pos2]+str1[pos1]+str1[pos2+1:]
        # print(str3)
        if str3 == str2:
            return True
        else:
            return False


def offByExtra(str1,str2):
    l1 = len(str1)
    l2 = len(str2)
    flag = 1
    cha =max(l1, l2) - min(l1,l2)
    str3=[]
    if cha != 1:
        return False
    else:
        if l2 > l1:
            for i in range(0, l1):
                if str2[i] != str1[i]:
                    list_str = list(str2)
                    list_str.pop(i)
                    str3 = ''.join(list_str)
                    flag = 0
                    break
            if flag:
                str3 =str2[:-1]
            if str3 != str1:
                return False
            else:
                return True
        else:
            for i in range(0, l2):
                if str1[i] != str2[i]:
                    list_str = list(str1)
                    list_str.pop(i)
                    str3 = ''.join(list_str)
                    flag = 0
                    break
            if flag:
                str3 =str1[:-1]
            if str3 != str2:
                return False
            else:
                return True

def ListOfNeighbors(str,L):
    file = open('作业1/'+L, 'r')
    result = []
    while True:
        line = file.readline()
        if line=='\n':
            continue
        line = line.replace("\n","")
        if line == "":
            break
        if offByExtra(str,line) or offByOne(str,line) or offBySwap(str,line):
            if str != line:
                result.append(line)
    file.close()

str = (input("请输入字符串:"))
ListOfNeighbors(str,"EnglishWords.txt")
