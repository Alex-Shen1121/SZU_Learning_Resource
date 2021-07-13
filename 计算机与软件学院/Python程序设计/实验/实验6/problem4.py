print(list(filter(lambda x: int(x) >= 0, ['12', '-2', '0'])))
print(list(filter(lambda x: x[0] == 'w', ['hello', 'world'])))
print(list(filter(lambda x: x[:4] == 'tech', ['technology','method', 'technique'])))
print(list(filter(lambda x: x % 3 == 0 or x % 5 == 0, range(20))))
