import math


def isValid(side1, side2, side3):
    sides = [side1, side2, side3]
    if sorted(sides)[0]+sorted(sides)[1] > sorted(sides)[2]:
        print("可以组成三角形。")
        return True
    else:
        print("不可以组成三角形。")
        return False


def perimeter(side1, side2, side3):
    print("三角形周长是：", side1+side2+side3)


def area(side1, side2, side3):
    p = (side1+side2+side3)/2
    print("三角形面积是：", math.sqrt(p*(p-side1)*(p-side2)*(p-side3)))
