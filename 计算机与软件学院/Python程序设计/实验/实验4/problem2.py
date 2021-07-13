import os
import string


def removePunctuations(word):
    for ch in word:
        if ch in string.punctuation or ch == '\n':
            word = word.replace(ch, " ")
    temp = word.split(' ')
    for i in range(len(temp)-1, -1, -1):
        if temp[i] == '' or temp[i] == '\n':
            del temp[i]
    return temp


def cnt(dic, worlist):
    for x in wordlist:
        if x in dic.keys():
            dic[x] = dic[x]+1


keyword_list = ["and", "as", "assert", "break", "class",
                "continue", "def", "del", "elif", "else",
                "except", "False", "finally", "for", "from",
                "global", "if", "import", "in", "is", "lambda",
                "None", "nonlocal", "not", "or", "pass", "raise",
                "return", "True", "try", "while", "with", "yield"]
dic = {i: 0 for i in keyword_list}


f = open("ofdm_tx_main.py", mode='r')

while True:
    line = f.readline()

    if not line:
        break
    if line == '\n':
        continue
    wordlist = removePunctuations(line)
    cnt(dic, wordlist)

sum=0
for x in dic.items():
    print(x[0],"出现",x[1],"次")
    sum+=x[1]
f.close()
print(sum)
