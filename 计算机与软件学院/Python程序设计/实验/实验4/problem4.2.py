D = {"what": 22, "are": 11, "you": 14, "doing": 5, "next": 9, "Saturday?": 4}
sum1 = []
sum2 = 0
for x in D.items():
    sum1.append((x[0],x[1]))
    # sum2 = sum2 + D[x[0]]
    sum2 = sum2 + x[1]

print(sum1)
print(sum2)
