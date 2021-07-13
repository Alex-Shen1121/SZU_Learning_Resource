
from turtle import *


def go_to(x, y):
    up()
    goto(x, y)
    down()


def person(x, y, r):
    head(x, y, r)
    eye(x, y, r)
    mouth(x, y)
    leg(x, y)
    hand(x, y)


def head(x, y, r):
    go_to(x, y)
    speed(6)
    circle(r)


def eye(x, y, r):
    go_to(x-40, y+150)
    forward(30)
    go_to(x-40, y+130)
    right(90)
    circle(r/10)
    go_to(x+40, y+150)
    left(90)
    forward(30)
    right(90)
    go_to(x+40, y+130)
    circle(r/10)
    left(90)


def mouth(x, y):
    go_to(x-5, y+50)
    right(45)
    forward(30)
    left(90)
    forward(30)


def leg(x, y):
    go_to(x-5, y)
    right(135)
    forward(180)
    right(30)
    forward(100)
    left(120)
    go_to(x, y-180)
    forward(100)
    right(120)
    forward(100)
    left(120)


def hand(x, y):
    go_to(x, y-60)
    forward(100)
    left(60)
    forward(80)
    go_to(x, y - 90)
    right(60)
    forward(100)
    right(60)
    forward(80)
    left(60)


def big_Circle(size):
    speed(1)
    for i in range(150):
        forward(size)
        right(0.3)


def line(size):
    speed(1)
    forward(51*size)


def small_Circle(size):
    speed(1)
    for i in range(210):
        forward(size)
        right(0.786)


def heart(x, y, size):
    go_to(x, y)
    left(150)
    begin_fill()
    line(size)
    big_Circle(size)
    small_Circle(size)
    left(120)
    small_Circle(size)
    big_Circle(size)
    line(size)
    end_fill()


def show_figure():
    pensize(2)
    color('red', 'pink')
    getscreen().tracer(10, 0)

    person(-350, 95, 100)
    heart(0, 0, 0.8)

    done()


if __name__ == "__main__":
    show_figure()
