import collections
import os
import sys


def Stat(path):
    file_num = 0
    code_line = 0
    space_lines = 0
    comments_lines = 0
    path = os.getcwd()+'/'+path
    if os.path.isfile(path):
        f = open(path, mode='r', encoding='UTF-8')
        while True:
            line = f.readline()
            if not line:
                break
            if line == '\n':
                space_lines += 1
            elif line[0] == '#':
                comments_lines += 1
            code_line += 1
    elif os.path.isdir(path):
        for file in os.listdir(path):
            file_path = path+'/'+file
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
                    else:
                        code_line += 1
    else:
        print("该路径下无py文件")
        return (0, 0, 0, 0)
    return (file_num, code_line, space_lines, comments_lines)


stat = Stat(sys.argv[1])
print("file_num:", stat[0])
print("code_line:", stat[1])
print("space_lines:", stat[2])
print("comments_lines:", stat[3])
