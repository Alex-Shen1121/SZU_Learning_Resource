import os

def isPrime(number):
    x = number
    for i in range(2, number):
        if x % i == 0:
            return False
    return True


def printPrimeNumbers(N):
    cnt = 0
    i = 2
    if os.path.exists('./problem1_data') == False:
        os.makedirs('./problem1_data')
    f = open("./problem1_data/First"+str(N)+"_Prime_Numbers.txt", mode="w")
    while True:
        if cnt >= N:
            break
        if isPrime(i):
            f.write(str(i)+' ')
            cnt += 1
        i += 1
    f.write('\n')
    f.close()


if __name__ == '__main__':
    N = int(input("请输入一个整数:"))
    if isPrime(N):
        print("这是一个质数")
    else:
        print("这是一个合数")
    N = int(input("打印前N个质数:"))
    printPrimeNumbers(N)
