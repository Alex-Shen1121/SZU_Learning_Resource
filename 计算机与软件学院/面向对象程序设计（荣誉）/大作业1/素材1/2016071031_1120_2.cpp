2016071031:Problem1120:答案错误
#include <iostream>
#include <bits/stdc++.h>
// 考察向下转换
using namespace std;

class Animal {
    string kind;
    string name;
    int age;
public:
    Animal(){};
    Animal(string kind_, string name_, int age_) {
        kind = kind_;
        name = name_;
        age = age_;
    }
    virtual void speak(){}
    string getName() { return name;}
};

class Tiger: public Animal {
public:
    Tiger(){};
    Tiger(string kind_, string name_, int age_)
        :Animal(kind_, name_, age_) {}
    void speak() {
        cout<< "Hello,I am " << getName() << ",AOOO." <<endl;
    }
};

class Pig: public Animal {
public:
    Pig(){};
    Pig(string kind_, string name_, int age_)
        :Animal(kind_, name_, age_) {}
    void speak() {
        cout<< "Hello,I am " << getName() << ",HENGHENG." <<endl;
    }
};

class Dog: public Animal {
public:
    Dog(){};
    Dog(string kind_, string name_, int age_)
        :Animal(kind_, name_, age_) {}
    void speak() {
        cout<< "Hello,I am " << getName() << ",WangWang." <<endl;
    }
};

class Duck: public Animal {
public:
    Duck(){};
    Duck(string kind_, string name_, int age_)
        :Animal(kind_, name_, age_) {}
    void speak() {
        cout<< "Hello, I am " << getName() << ", GAGA." <<endl;
    }
};


int main() {
    int t, age;
    string kind, name;
    Animal *a;

    cin>>t;
    while (t--) {
        cin>>kind>>name>>age;
        if (kind == "Tiger") {
            a = new Tiger(kind, name, age);
            a->speak();
        } else if (kind == "Pig") {
            a = new Pig(kind, name, age);
            a->speak();
        } else if (kind == "Dog") {
            a = new Dog(kind, name, age);
            a->speak();
        } else if (kind == "Duck") {
            a = new Duck(kind, name, age);
            a->speak();
        } else {
            cout<< "There is no " << kind << " in our Zoo." <<endl;
        }
    }
    return 0;
}

