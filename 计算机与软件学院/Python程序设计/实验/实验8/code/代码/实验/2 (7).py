import turtle as t
x = 1
y = 1
d = 1
long = 33

X = [-169, -171, -128, -139]
Y = [158, 33, 110, 65]
D = [53, 53, 106, 74]
q = 0


t.setup(700, 500)
t.screensize(800, 800, "black")
t.pencolor("red")
t.speed(10)
t.pensize(5)
t.goto(-300, 200)
t.clear()
t.hideturtle()


t.fillcolor("red")
t.begin_fill()
for _ in range(2):
	t.forward(600)
	t.right(90)
	t.forward(400)
	t.right(90)
t.end_fill()
t.penup()
t.pencolor("yellow")
t.pensize(1)
t.goto(-250, 74)
t.pendown()
t.setheading(72)
t.fillcolor("yellow")
t.begin_fill()
for _ in range(5):
    t.forward(90)
    t.right(144)
t.end_fill()


for _ in range(4):

    t.setheading(D[q])
    t.begin_fill()
    t.penup()
    t.goto(X[q], Y[q])
    t.pendown()
    for _ in range(5):
        t.forward(long)
        t.right(144)
    t.end_fill()
    q += 1

t.done()
