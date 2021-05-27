2018192045:Problem1120:´ð°¸´íÎó
#include<iostream>
using namespace std;
#include<cstring>
class Animal
{
protected:
    string name;
    int age;
public:
    Animal(string n,int a):name(n),age(a) {}
    virtual void speak()=0;

};
class Tiger:public Animal
{
public:
    Tiger(string n,int a):Animal(n,a) {}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",AOOO."<<endl;
    }
};
class Dog:public Animal
{
public:
    Dog(string n,int a):Animal(n,a) {}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",WangWang."<<endl;
    }
};
class Pig:public Animal
{
public:
    Pig(string n,int a):Animal(n,a) {}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
    }
};
class Duck:public Animal
{
public:
    Duck(string n,int a):Animal(n,a) {}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",GAGA."<<endl;
    }
};
int main()
{
    string type,name;
    int age,t;
    Animal *p;
    cin>>t;
    while(t--)
    {
        cin>>type>>name>>age;
        if(type=="Tiger")
        {
            Tiger A(name,age);
            p=&A;
            p->speak();
        }
        if(type=="Duck")
        {
            Duck A(name,age);
            p=&A;
            p->speak();
        }
        if(type=="Pig")
        {
            Pig A(name,age);
            p=&A;
            p->speak();
        }
        if(type=="Dog")
        {
            Dog A(name,age);
            p=&A;
            p->speak();
        }
        else
        {
            cout<<"There is no "<<type<<" in our Zoo."<<endl;
        }

    }
}

