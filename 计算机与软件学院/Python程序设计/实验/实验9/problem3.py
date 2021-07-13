import math
from tkinter import *
import random
import tkinter.messagebox


class Demo:
    def __init__(self) -> None:
        window = Tk()
        window.title("Problem1")
        frame = Frame(window)
        frame.pack()

        self.canvas = Canvas(frame, width=400, height=200, bg='white')
        self.canvas.pack()

        self.x1, self.x2 = random.randint(0, 400), random.randint(0, 400)
        self.y1, self.y2 = random.randint(0, 200), random.randint(0, 200)
        self.r = 20

        self.canvas.create_oval(
            self.x1-self.r, self.y1-self.r,
            self.x1+self.r, self.y1+self.r,
            fill='red', tag='circle1',)

        self.canvas.create_oval(
            self.x2-self.r, self.y2-self.r,
            self.x2+self.r, self.y2+self.r,
            fill='red', tags='circle2')

        self.canvas.create_line(self.x1, self.y1,
                                self.x2, self.y2,
                                tags='line')

        self.canvas.create_text((self.x1+self.x2)/2, (self.y1+self.y2)/2,
                                text="{:.2f}".format(self.get_dis()), tags='dis')

        self.canvas.bind("<B1-Motion>", self.MouseEvent)

        window.mainloop()

    def get_dis(self):
        return math.sqrt((self.x1-self.x2)**2+(self.y1-self.y2)**2)

    def MouseEvent(self, event):
        cur_x, cur_y = event.x, event.y
        if cur_x > self.x1-self.r and cur_x < self.x1+self.r and cur_y > self.y1-self.r and cur_y < self.y1+self.r:
            if(cur_x==self.x2 and cur_y == self.y2):
                tkinter.messagebox.showinfo(
                    "Problem 3", "禁止重叠")
                return
            self.x1 = cur_x
            self.y1 = cur_y
            self.canvas.delete('circle1')
            self.canvas.create_oval(
                self.x1-self.r, self.y1-self.r,
                self.x1+self.r, self.y1+self.r,
                fill='red', tag='circle1',)

            self.canvas.delete('line')
            self.canvas.create_line(self.x1, self.y1,
                                    self.x2, self.y2,
                                    tags='line')

            self.canvas.delete('dis')
            self.canvas.create_text((self.x1+self.x2)/2, (self.y1+self.y2)/2,
                                    text="{:.2f}".format(self.get_dis()),tags='dis')
        
        elif cur_x > self.x2-self.r and cur_x < self.x2+self.r and cur_y > self.y2-self.r and cur_y < self.y2+self.r:
            if(cur_x == self.x1 and cur_y == self.y1):
                tkinter.messagebox.showinfo(
                    "Problem 3", "禁止重叠")
                return
            self.x2 = cur_x
            self.y2 = cur_y
            self.canvas.delete('circle2')
            self.canvas.create_oval(
                self.x2-self.r, self.y2-self.r,
                self.x2+self.r, self.y2+self.r,
                fill='red', tag='circle2',)

            self.canvas.delete('line')
            self.canvas.create_line(self.x1, self.y1,
                                    self.x2, self.y2,
                                    tags='line')

            self.canvas.delete('dis')
            self.canvas.create_text((self.x1+self.x2)/2, (self.y1+self.y2)/2,
                                    text="{:.2f}".format(self.get_dis()), tags='dis')


Demo()
