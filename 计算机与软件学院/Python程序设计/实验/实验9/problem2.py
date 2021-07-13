from tkinter import *
import tkinter.messagebox
import numpy as np


class Demo:
    def __init__(self) -> None:
        window = Tk()
        window.title("Problem1")
        frame = Frame(window)
        frame.pack()

        self.a = StringVar()
        self.b = StringVar()
        self.c = StringVar()
        self.d = StringVar()
        self.e = StringVar()
        self.f = StringVar()

        Entry(frame, textvariable=self.a).grid(row=1, column=1)
        Label(frame, text="x + ").grid(row=1, column=2)
        Entry(frame, textvariable=self.b,).grid(row=1, column=3)
        Label(frame, text="y = ").grid(row=1, column=4)
        Entry(frame, textvariable=self.e).grid(row=1, column=5)

        Entry(frame, textvariable=self.c).grid(row=2, column=1)
        Label(frame, text="x + ").grid(row=2, column=2)
        Entry(frame, textvariable=self.d).grid(row=2, column=3)
        Label(frame, text="y = ").grid(row=2, column=4)
        Entry(frame, textvariable=self.f).grid(row=2, column=5)

        Button(frame, text='计算', command=self.cal).grid(row=3, column=3)

        window.mainloop()

    def cal(self):
        a = self.a.get()
        b = self.b.get()
        c = self.c.get()
        d = self.d.get()
        e = self.e.get()
        f = self.f.get()
        if a.isdigit() and b.isdigit() and c.isdigit() and d.isdigit() and e.isdigit() and f.isdigit():
            x = np.linalg.solve(
                [[int(a), int(b)], [int(c), int(d)]], [int(e), int(f)])
            tkinter.messagebox.showinfo(
                "求解二元一次方程", "x = {:.2f}, y = {:.2f}".format(x[0], x[1]))
        else:
            tkinter.messagebox.showinfo(
                "求解二元一次方程", "非法输入")


Demo()
