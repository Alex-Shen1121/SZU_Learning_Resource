num = input("Enter a number between 0 and 1000:")
while int(num) < 0 or int(num) > 1000:
    print("Please input a correct number")
    num = input("Enter a number between 0 and 1000:")

ans = 1
for char in num:
    if int(char) % 2 == 1:
        ans *= int(char)

print("The result is", ans)
