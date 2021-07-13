import itertools


def sum0(lst):
    for i in itertools.combinations("01234567", 3):
        if lst[int(i[0])]+lst[int(i[1])]+lst[int(i[2])] == 0:
            return True
    return False


print(sum0([-3, 11, 21, 5, 10, 11, 2, 1]))
print(sum0(([2, 3, 4, 5, 6, 7, 8, 9])))
