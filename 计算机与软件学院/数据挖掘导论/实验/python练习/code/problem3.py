def encryption(code):
    newCode = []

    # 每位数字都加上5,然后用和除以10的余数代替该数字
    for i in range(len(code)):
        newCode.append(str((int(code[i]) + 5) % 10))

    # 1-4，2-3交换，即反转字符串
    newCode.reverse()

    # 列表转换为字符串
    return ''.join(newCode)

if __name__ == '__main__':
    code = input()
    print(encryption(code))
