num = int(input("Enter an integer:"))

# 是否可以同时被 5 和 7 整除
if num % 5 == 0 and num % 7 == 0:
    print("Is", num, " divisible by 5 and 7? True")
else:
    print("Is", num, " divisible by 5 and 7? False")

# 是否可以被 5 或 7 整除
if num % 5 == 0 or num % 7 == 0:
    print("Is", num, " divisible by 5 or 7? True")
else:
    print("Is", num, " divisible by 5 or 7? False")

# 是否只可以被其中一个整除，但不能同时被两者整除
if num % 5 == 0 and num % 7 != 0 or num % 5 != 0 and num % 7 == 0:
    print("Is", num, " divisible by 5 or 7, but not both? True")
else:
    print("Is", num, " divisible by 5 or 7, but not both? False")
