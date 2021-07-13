import math
from functools import reduce


def lcm(*nums):
    if not nums:
        return 1
    return reduce(lambda x, y: int(x*y/math.gcd(x, y)), nums)


print(lcm(3, 5))
print(lcm(41, 106, 12))
print(lcm(1, 2, 6, 24, 120, 720))
print(lcm(3))
print(lcm())
