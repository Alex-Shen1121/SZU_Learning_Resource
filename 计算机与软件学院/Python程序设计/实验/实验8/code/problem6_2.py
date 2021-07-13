import collections
import os
import sys


def Stat():
    file_num = 0
    code_line = 0
    space_lines = 0
    comments_lines = 0
    for folder in os.walk(os.getcwd()+'/代码'):
        print(folder[0])
        for i in folder[1]:
            for file in os.listdir(folder[0]+'/'+i):
                file_path = folder[0]+'/'+i+'/'+file
                # 判断是否为python文件
                if file.endswith('.py'):
                    file_num += 1
                    f = open(file_path, mode='r', encoding='UTF-8')
                    while True:
                        line = f.readline()
                        if not line:
                            break
                        if line == '\n':
                            space_lines += 1
                        elif line[0] == '#':
                            comments_lines += 1
                        code_line += 1
        return (file_num, code_line, space_lines, comments_lines)


stat = Stat()
print("file_num:", stat[0])
print("code_line:", stat[1])
print("space_lines:", stat[2])
print("comments_lines:", stat[3])
