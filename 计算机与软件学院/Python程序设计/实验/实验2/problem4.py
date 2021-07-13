import Triangle

a, b, c = map(eval, input("请输入三角形的三边长：").split())
if Triangle.isValid(a, b, c):
    Triangle.perimeter(a, b, c)
    Triangle.area(a, b, c)
