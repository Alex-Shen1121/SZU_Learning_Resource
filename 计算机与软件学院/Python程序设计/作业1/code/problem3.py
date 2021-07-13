import string

word_dic_Robert = {}
word_dic_Leo = {}


def parse(String):
    for ch in String:
        if ch not in string.ascii_letters:
            String = String.replace(ch, " ")
    return [word for word in String.split(' ') if len(word) >= 4]


def mostFrequentWords(filenames):
    f = open(filenames, mode='r')
    dic = word_dic_Leo if filenames == "war.txt" else word_dic_Robert
    while True:
        # 按行读入
        line = f.readline()

        if not line:
            break
        if line == '\n':
            continue

        wordlist = parse(line.lower())
        for temp in wordlist:
            if temp in dic.keys():
                dic[temp] += 1
            else:
                dic[temp] = 1

    f.close()


# 问题1
# String = "Shenzhen’s big, beautiful and rich place"
# print(parse(String))

# 问题2
mostFrequentWords("hyde.txt")
mostFrequentWords("treasure.txt")
mostFrequentWords("war.txt")
print(sorted(word_dic_Leo.items(),
             key=lambda kv: (kv[1], kv[0]),
             reverse=True)[:20])
print(sorted(word_dic_Robert.items(),
             key=lambda kv: (kv[1], kv[0]),
             reverse=True)[:20])
