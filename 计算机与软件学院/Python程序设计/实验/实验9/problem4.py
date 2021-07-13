from os import stat
from tkinter import *
from tkinter.filedialog import askopenfilename
import tkinter.messagebox
import numpy as np
import string


class Demo:
    def __init__(self) -> None:
        window = Tk()
        frame1 = Frame(window)
        frame1.pack()
        frame2 = Frame(window)
        frame2.pack()
        scrollbar = Scrollbar(frame1)
        scrollbar.pack(side=RIGHT, fill=Y)
        self.text = Text(frame1, width=50, height=20, wrap=WORD,
                         yscrollcommand=scrollbar.set)
        self.text.configure(state='disabled')
        self.text.pack()

        scrollbar.config(command=self.text.yview)

        self.label1 = Label(
            frame2, text='Enter a file name:').grid(row=1, column=1)
        self.path = Label(frame2, height=1)
        self.path.grid(row=1, column=2)
        self.browse = Button(frame2, text='Browse',
                             command=self.choose_file).grid(row=1, column=3)
        self.show_result = Button(
            frame2, text='Show Result', command=self.show).grid(row=1, column=4)

        self.file_path = ''
        window.mainloop()

    def choose_file(self):
        self.file_path = askopenfilename(title='Select the .txt / .py file', filetypes=[
            ('Python', '*.py'), ('Txt', '*.txt')], initialdir='I:\\大二下\\Python程序设计')
        self.path.configure(text=self.file_path)

    def show(self):
        dic = {i: 0 for i in string.ascii_lowercase}
        if self.file_path == "":
            tkinter.messagebox.showwarning('警告！', "当前路径下无文件。")
            return
        else:
            f = open(self.file_path, mode='r')
            while True:
                line = f.readline()
                if not line:
                    break
                line = line.lower()
                for ch in line:
                    if ch in dic:
                        dic[ch] += 1
        self.text.configure(state='normal')
        self.text.delete('1.0', 'end')
        for i in dic:
            self.text.insert(END, "{} appear {} times\n".format(i, dic[i]))
        self.text.configure(state='disabled')


Demo()
