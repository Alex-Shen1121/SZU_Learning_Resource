def generate_triangles():
    ans, i = 0, 1
    while True:
        ans, i = ans+i, i+1
        yield ans


def generate_triangles_under(n):
    for ans in generate_triangles():
        if(ans > n):
            break
        print(ans,end=', ')


g = generate_triangles()
for _ in range(5):
    print(next(g),end=', ')
print()
generate_triangles_under(50)
