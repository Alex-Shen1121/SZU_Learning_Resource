num1 = int(input("Enter the first number:"))
num2 = int(input("Enter the second number:"))

for i in range(min(num1, num2), 0, -1):
    if num1 % i == 0 and num2 % i == 0:
        print("GCD of", num1, "and", num2, "is", i)
        break


def CommDevisor(m, n):
  r = m % n
  while r != 0:
    m = n
    n = r
    r = m % n
  return n

print("GCD of", num1, "and", num2, "is", CommDevisor(num1,num2))
