# -*- coding:utf-8 -*-

class Person(object):
    def __init__(self, name='', age=20, sex='man'):
        self.__name = name
        self.__age = age
        self.__sex = sex

    def setName(self, name):
        self.__name = name

    def setAge(self, age):
        self.__age = age

    def setSex(self, sex):
        self.__sex = sex

    def show(self):
        print("Name:", self.__name)
        print("Age:", self.__age)
        print("Sex:", self.__sex)


class Teacher(Person):
    def __init__(self, name='', age=30, sex='man', department='Computer'):
        Person.__init__(self, name, age, sex)
        self.setDepartment(department)

    def setDepartment(self, department):
        self.__department=department

    def show(self):
        Person.show(self)
        print("Department:",self.__department)


if __name__ == '__main__':
    zhangsan = Person('Zhang San', 19, 'man')
    zhangsan.show()

    lisi = Teacher('Li Xi', 32, 'man', 'Math')
    lisi.show()
    lisi.setAge(40)
    lisi.setName("Li Si")
    lisi.show()
