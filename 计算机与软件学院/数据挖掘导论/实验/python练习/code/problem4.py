if __name__ == '__main__':
    # 创建字典与数据
    mp = {'min': [], 'max': []}
    list = [11, 33, 22, 44, 55, 66, 77, 88, 99, 90]

    # 根据数据大小插入相应列表
    for x in list:
        if x < 66:
            mp['min'].append(x)
        else:
            mp['max'].append(x)

    print('min:', mp['min'])
    print('max:', mp['max'])
