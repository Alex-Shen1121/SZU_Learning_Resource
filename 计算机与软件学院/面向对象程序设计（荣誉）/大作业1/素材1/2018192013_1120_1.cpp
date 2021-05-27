2018192013:Problem1120:ÕýÈ·
#include <iostream>
using namespace std;

class Animal
{
protected:
    string name;
    int age;
public:
    Animal(string n=" ",int a=0):name(n),age(a){}
    virtual void speak()=0;
};

class Tiger:public Animal
{
public:
    Tiger(string n,int a):Animal(n,a){}
    void speak(){cout<<"Hello,I am "<<name<<",AOOO."<<endl;}
};

class Dog:public Animal
{
public:
    Dog(string n,int a):Animal(n,a){}
    void speak(){cout<<"Hello,I am "<<name<<",WangWang."<<endl;}
};

class Duck:public Animal
{
public:
    Duck(string n,int a):Animal(n,a){}
    void speak(){cout<<"Hello,I am "<<name<<",GAGA."<<endl;}
};

class Pig:public Animal
{
public:
    Pig(string n,int a):Animal(n,a){}
    void speak(){cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;}
};

int main()
{
    int t;
    cin>>t;
    Animal *a;
    while(t--)
    {
        string type,name;
        int age;
        cin>>type>>name>>age;
        if(type=="Tiger")
        {
            Tiger t(name,age);
            a=&t;
            a->speak();
        }
        else if(type=="Dog")
        {
            Dog d(name,age);
            a=&d;
            a->speak();
        }
        else if(type=="Duck")
        {
            Duck d(name,age);
            a=&d;
            a->speak();
        }
        else if(type=="Pig")
        {
            Pig p(name,age);
            a=&p;
            a->speak();
        }
        else
            cout<<"There is no "<<type<<" in our Zoo."<<endl;
    }
    return 0;
}

