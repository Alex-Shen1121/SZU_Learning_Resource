def isPrime(a):
    for i in range(2, a):
        if a % i == 0:
            return True
    return False


def printFactorial(a):
    ans = 1
    for i in range(1,a+1):
        ans *= i
    print(a,"!:",ans)


num = int(input("input a num:"))
for i in range(num+1,4,-1):
    if isPrime(i):
        printFactorial(i)
