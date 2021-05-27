2017163058:Problem1120:正确
#include <iostream>
#include <fstream>
using namespace std;
//某个动物园内，有老虎、狗、鸭子和猪等动物，动物园的管理员为每个动物都起了一个名字，并且每个动物都有年龄、体重等信息。

//每到喂食的时候，不同的动物都会叫唤(speak)。每种动物的叫唤声均不同，老虎的叫唤声是“AOOO”，狗的叫唤声是“WangWang”，鸭子的叫唤声是“GAGA”，猪的叫唤声是“HENGHENG”。

//定义一个Animal的基类，Animal类有函数Speak()，并派生老虎、狗、鸭子和猪类，其能发出不同的叫唤声（用文本信息输出叫声）。
//
//编写程序，输入动物名称、名字、年龄，让动物园内的各种动物叫唤。
//
//要求：只使用一个基类指针，指向生成的对象并调用方法。
class Animal
{
protected:
    string name;
    int age;
public:
    virtual void Speak() = 0;
};
class Tiger:public Animal
{
public:
    Tiger(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",AOOO."<<endl;
    }
};
class Dog:public Animal
{
public:
    Dog(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",WangWang."<<endl;
    }
};
class Duck:public Animal
{
public:
    Duck(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",GAGA."<<endl;
    }
};
class Pig:public Animal
{
public:
    Pig(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
    }
};
int main()
{
//    freopen("C:\\Users\\acer\\Desktop\\in.txt", "r", stdin);
    string name, animal;
    int t, age;
    Animal *p;
    cin>>t;
    while(t --)
    {
        cin>>animal>>name>>age;
        if(animal == "Tiger")
        {
            Tiger tiger(name, age);
            p = &tiger;
            p->Speak();
        }
        else if(animal == "Dog")
        {
            Dog dog(name, age);
            p = &dog;
            p->Speak();
        }
        else if(animal == "Duck")
        {
            Duck duck(name, age);
            p = &duck;
            p->Speak();
        }
        else if(animal == "Pig")
        {
            Pig pig(name, age);
            p = &pig;
            p->Speak();
        }
        else
        {
            cout<<"There is no "<<animal<<" in our Zoo."<<endl;
        }

    }
    return 0;
}

