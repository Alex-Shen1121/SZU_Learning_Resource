import math

radius = float(input("Enter the radius of a cylinder:"))
length = float(input("Enter the length of a cylinder:"))

area = radius*radius*math.pi
print("The area is", area)
print("The volume is", area*length)
