if __name__ == '__main__':
    name = []
    name.append('Lihua')
    name.append('Rain')
    name.append('Jack'),
    name.append('Xiuxiu')
    name.append('Peiqi')
    name.append('Black')
    print(name)

    name.insert(name.index('Black'), 'Blue')
    name.insert(name.index('Black') + 1, 'White')
    print(name)

    name[name.index('Xiuxiu')] = '秀秀'
    print(name)

    numList = [1, 2, 3, 4, 2, 5, 6, 2]
    name.extend(numList)
    print(name)
    temp = name[2:11:2]
    print(temp)
