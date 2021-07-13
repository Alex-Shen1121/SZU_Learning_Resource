from tkinter import *
import random


class Demo:
    def __init__(self) -> None:
        window = Tk()
        window.title("Problem1")
        frame = Frame(window)
        frame.pack()

        self.canvas = Canvas(frame, width=400, height=200, bg='white')
        self.canvas.pack()

        display_button = Button(frame, text='Display', command=self.reset)
        display_button.pack()

        window.mainloop()

    def reset(self):
        self.canvas.delete("all")
        for i in range(0, 10):
            x, y = random.randint(0, 400), random.randint(0, 200)
            r = random.randint(5, 10)
            self.canvas.create_oval(x-r, y-r, x+r, y+r,
                                    fill=self.rand_color())

    def rand_color(self):
        colorArr = ['1', '2', '3', '4', '5', '6', '7',
                    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F']
        color = ""
        for i in range(6):
            color += colorArr[random.randint(0, 14)]
        return "#"+color


Demo()
