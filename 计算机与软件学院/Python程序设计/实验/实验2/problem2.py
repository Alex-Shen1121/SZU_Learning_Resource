import os

def isPrime(number):
    x = int(number)
    for i in range(2, int(number)):
        if x % i == 0:
            return False
    return True


def printEmirpNumbers(N):
    cnt = 0
    i = 10
    if os.path.exists('./problem2_data') == False:
        os.makedirs('./problem2_data')
    f = open("./problem2_data/First"+str(N)+"_Emirp_Numbers.txt", mode="w")
    while True:
        num = str(i)
        if cnt >= N:
            break
        if isPrime(num) and isPrime(num[::-1]):
            f.write(num + ' ')
            cnt += 1
            if cnt % 10 == 0:
                f.write('\n')
        i += 1
    f.close()


if __name__ == '__main__':
    N = int(input("打印前N个emirp数:"))
    printEmirpNumbers(N)
