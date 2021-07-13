import string

dic = {i: string.ascii_lowercase.find(i) + 1 for i in string.ascii_lowercase}


def is_special_word(word):
    for i in range(len(word)-2):
        if abs(dic[word[i+2]]-dic[word[i+1]]) < abs(dic[word[i+1]]-dic[word[i]]):
            return False
    return True


word = str(input("请输入单词："))
print(is_special_word(word))
