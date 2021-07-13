def indexOfLargestElement(list):
    ans = []
    for x in range(len(list)):
        if list[x] == max(list):
            ans.append(x)
    return ans


print(indexOfLargestElement([2, 1, 3, 1, 3]))
