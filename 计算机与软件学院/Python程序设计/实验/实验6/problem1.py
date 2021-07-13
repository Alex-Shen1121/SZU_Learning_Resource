def sum(a, b, c):
    print("a=%d, b=%d, c=%d" % (a, b, c))
    print(a+b+c)


sum(*(1,  2,  3))
sum(1, *(2, 3))
# sum(*(1,), b=2, 3)
sum(*(1,), b=2,  c=3)
sum(*(1,  2), c=3)
sum(a=1,  *(2,  3))
sum(b=1, *(2, 3))
sum(c=1, *(2, 3))
