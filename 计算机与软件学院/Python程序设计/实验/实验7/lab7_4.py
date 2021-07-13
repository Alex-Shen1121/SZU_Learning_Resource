# -*- coding:utf-8 -*-

class Person(object):
    def __init__(self, name='', age=20, sex='man'):
        pass

    def setName(self, name):
        pass

    def setAge(self, age):
        pass

    def setSex(self, sex):
        pass

    def show(self):
        pass


class Teacher(Person):
    def __init__(self, name='', age=30, sex='man', department='Computer'):
        Person.__init__(self, name, age, sex)
        self.setDepartment(department)

    def setDepartment(self, department):
        pass

    def show(self):
        pass


if __name__ == '__main__':
    zhangsan = Person('Zhang San', 19, 'man')
    zhangsan.show()

    lisi = Teacher('Li Xi', 32, 'man', 'Math')
    lisi.show()
    lisi.setAge(40)
    lisi.setName("Li Si")
    lisi.show()
