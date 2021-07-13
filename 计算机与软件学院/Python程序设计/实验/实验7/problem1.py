import math


class RegularPoylygon:
    def __init__(self, n=3, side=1, x=0, y=0) -> None:
        self.n = n
        self.side = side
        self.x = x
        self.y = y

    def getPerimeter(self):
        print("Perimeter = {:.3f}".format(self.n*self.side))

    def getArea(self):
        print("Area = {:.3f}".format(self.n*self.side *
                                     self.side/math.tan(math.pi/self.n)/4))

    def distanceToPolygon(self, other):
        print("Distance is {:.3f}".format(
            math.sqrt(pow(self.x-other.x, 2) + pow(self.y-other.y, 2))))


square = RegularPoylygon(4, 8, 0, 0)
triangle = RegularPoylygon(3, 3, 1, 1)
square.getArea()
square.getPerimeter()

triangle.getArea()
triangle.getPerimeter()

square.distanceToPolygon(triangle)
triangle.distanceToPolygon(square)
