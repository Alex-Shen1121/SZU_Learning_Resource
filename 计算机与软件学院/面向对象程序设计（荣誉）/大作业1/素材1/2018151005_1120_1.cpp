2018151005:Problem1120:正确
#include<iostream>
#include<string>
using namespace std;
class Animal
{
protected:
    string name;
    int age;
public:
    Animal(){}
    Animal(string name0,int age0):name(name0),age(age0){}
    virtual void speak()=0;//应收费用
};
class Tiger:public Animal
{
public:
    Tiger(){}
    Tiger(string name0,int age0):Animal(name0,age0){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",AOOO."<<endl;
    }
};
class Dog:public Animal
{
public:
    Dog(){}
    Dog(string name0,int age0):Animal(name0,age0){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",WangWang."<<endl;
    }
};
class Duck:public Animal
{
public:
    Duck(){}
    Duck(string name0,int age0):Animal(name0,age0){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",GAGA."<<endl;
    }
};
class Pig:public Animal
{
public:
    Pig(){}
    Pig(string name0,int age0):Animal(name0,age0){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
    }
};
int main()
{
    int t;
    cin>>t;
    Animal* pa;
    while(t--)
    {
        string name;
        int age;
        string type;
        cin>>type>>name>>age;
        if(type=="Tiger")
        {
            Tiger a(name,age);
            pa=&a;
            pa->speak();
        }
        else if(type=="Dog")
        {
            Dog a(name,age);
            pa=&a;
            pa->speak();
        }
        else if(type=="Duck")
        {
            Duck a(name,age);
            pa=&a;
            pa->speak();
        }
        else if(type=="Pig")
        {
            Pig a(name,age);
            pa=&a;
            pa->speak();
        }
        else
        {
            cout<<"There is no "<<type<<" in our Zoo."<<endl;
        }
    }
}

