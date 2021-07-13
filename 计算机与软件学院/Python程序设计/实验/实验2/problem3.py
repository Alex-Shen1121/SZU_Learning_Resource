import math


def my_sqrt(n):
    nextGuess, lastGuess = n, 1
    while math.fabs(nextGuess-lastGuess) > 0.0001:
        lastGuess = nextGuess
        nextGuess = (lastGuess+n/lastGuess)/2
    return nextGuess


if __name__ == '__main__':
    n = int(input("请输入一个整数："))
    print("平方根为：" + str(my_sqrt(n)))
