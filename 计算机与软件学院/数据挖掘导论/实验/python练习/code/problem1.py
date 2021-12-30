import math

# 根据输入判断输出
def callatz(number):
    return number if isPrime(number) else 3 * number + 1

# 质数判断
def isPrime(n):
    if n <= 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True


if __name__ == '__main__':
    number = int(input('输入:'))
    print('输出：',callatz(number))
