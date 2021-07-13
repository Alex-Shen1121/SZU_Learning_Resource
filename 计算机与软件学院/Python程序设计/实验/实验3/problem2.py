def merge_1(list1, list2):
    list1.extend(list2)
    list1.sort()
    return list1


def merge_2(list1, list2):
    ans = []
    while list1 and list2:
        if list1[0] > list2[0]:
            ans.append(list2[0])
            del list2[0]
        else:
            ans.append(list1[0])
            del list1[0]
    if len(list1) > 0:
        ans.extend(list1)
    elif len(list2) > 0:
        ans.extend(list2)

    return ans


print(merge_1([2, 4, 7, 8, 11], [1, 4, 5, 6]))
print(merge_2([2, 4, 7, 8, 11], [1, 4, 5, 6]))
