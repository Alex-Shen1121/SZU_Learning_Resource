if __name__ == '__main__':
    str1 = open('../file/text1.txt').read()
    str2 = open('../file/text2.txt').read()
    f = open('../file/text3.txt', 'w')

    # 合并字符串 并写入文件
    # 对字符串进行排序：
    # 排序规则: 1.字符lower大小(a<b<c<...)
    #          2.大小写(A<a)
    f.write(''.join(sorted(str1 + str2, key=lambda x: (x.lower(), x))))
    f.close()

    print(u'txt3写入成功')
