# 检查该串中是否两类字符[数字和英文字符]都包含
def check1(string: str):
    bool1, bool2 = False, False
    for ch in string:
        if ch.isalpha():
            bool1 = True
        if ch.isnumeric():
            bool2 = True
        if bool1 and bool2:
            break
    return bool1 and bool2

# 检查每种字符是否都唯一
def check2(string: str):
    mp = set()
    for ch in string:
        if ch in mp:
            return False
        mp.add(ch)
    return True


if __name__ == '__main__':
    string = str(input())
    print(check1(string) and check2(string))
