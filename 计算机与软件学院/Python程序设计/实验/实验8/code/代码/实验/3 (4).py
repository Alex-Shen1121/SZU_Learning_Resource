def match_pattern(list1, list2):
    if len(list2) > len(list1):
        return False
    for i in range(len(list1)-len(list2)+1):
        if list1[i:i+len(list2)] == list2:
            return True
    return False


list1 = [4, 10, 2, 3, 50, 100]
list2 = [3, 2, 50]
list3 = [2, 3, 50]
list4 = [2, 3, 40]
print(match_pattern(list1, list2))
print(match_pattern(list1, list3))
print(match_pattern(list1, list4))
