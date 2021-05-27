2018192044:Problem1120:ÕýÈ·
#include <iostream>
using namespace std;
class Animal
{
protected:
    string name;
    int age;
public:
    Animal(string n,int a):name(n),age(a){}
    virtual void Speak()=0;
    ~Animal(){}
};
class Tiger:public Animal
{
public:
    Tiger(string n,int a):Animal(n,a){}
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",AOOO."<<endl;
    }
};
class Dog:public Animal
{
public:
    Dog(string n,int a):Animal(n,a){}
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",WangWang."<<endl;
    }
};
class Duck:public Animal
{
public:
    Duck(string n,int a):Animal(n,a){}
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",GAGA."<<endl;
    }
};
class Pig:public Animal
{
public:
    Pig(string n,int a):Animal(n,a){}
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
    }
};
int main()
{
    int t,age;
    string name,type;
    cin>>t;
    Animal *p;
    while(t--)
    {
        cin>>type>>name>>age;
        if(type=="Tiger")
        {
            Tiger A(name,age);
            p=&A;
            p->Speak();
        }
        else if(type=="Dog")
        {
            Dog A(name,age);
            p=&A;
            p->Speak();
        }
        else if(type=="Duck")
        {
            Duck A(name,age);
            p=&A;
            p->Speak();
        }
        else if(type=="Pig")
        {
            Pig A(name,age);
            p=&A;
            p->Speak();
        }
        else
            cout<<"There is no "<<type<<" in our Zoo."<<endl;
    }
    return 0;
}

