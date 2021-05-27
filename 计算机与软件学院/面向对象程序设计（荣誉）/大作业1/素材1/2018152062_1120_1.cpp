2018152062:Problem1120:答案错误
#include <iostream>
using namespace std;
/*某个动物园内，有老虎、狗、鸭子和猪等动物，动物园的管理员为每个动物都起了一个名字，
并且每个动物都有年龄、体重等信息。每到喂食的时候，不同的动物都会叫唤(speak)。
每种动物的叫唤声均不同，老虎的叫唤声是“AOOO”，狗的叫唤声是“WangWang”，
鸭子的叫唤声是“GAGA”，猪的叫唤声是“HENGHENG”。
定义一个Animal的基类，Animal类有函数Speak()，并派生老虎、狗、鸭子和猪类，
其能发出不同的叫唤声（用文本信息输出叫声）。
编写程序，输入动物名称、名字、年龄，让动物园内的各种动物叫唤。
要求：只使用一个基类指针，指向生成的对象并调用方法。*/
class Animal
{
protected:
    string type;
public:
    Animal(string _type):type(_type){}
    virtual void speak(){};
};
class Tiger:public Animal
{
protected:
    string name;
    int age;
public:
    Tiger(string _type,string _name,int _age):Animal(_type),name(_name),age(_age){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<","<<"AOOO."<<endl;
    }
};
class Dog:public Animal
{
protected:
    string name;
    int age;
public:
    Dog(string _type,string _name,int _age):Animal(_type),name(_name),age(_age){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<","<<"WangWang."<<endl;
    }
};
class Duck:public Animal
{
protected:
    string name;
    int age;
public:
    Duck(string _type,string _name,int _age):Animal(_type),name(_name),age(_age){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<","<<"GAGA."<<endl;
    }
};
class Pig:public Animal
{
protected:
    string name;
    int age;
public:
    Pig(string _type,string _name,int _age):Animal(_type),name(_name),age(_age){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<","<<"HENGHENG."<<endl;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Animal *p;
        string type;
        string name;
        int age;
        cin>>type>>name>>age;
        if(type=="Tiger")
        {
            Tiger tiger(type,name,age);
            p=&tiger;
            p->speak();
        }
        else if(type=="Duck")
        {
            Duck duck(type,name,age);
            p=&duck;
            p->speak();
        }
        else if(type=="Dog")
        {
            Dog dog(type,name,age);
            p=&dog;
            p->speak();
        }
        else if(type=="Pig")
        {
            Pig pig(type,name,age);
            p=&pig;
            p->speak();
        }
        else
            cout<<"There is no "<<name<<" in our Zoo."<<endl;
    }
    return 0;
}

