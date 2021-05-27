2018152035:Problem1120:ÕýÈ·
#include <iostream>
#include<stdio.h>
#include<string>
using namespace std;
class animal
{
protected:
    int age;
    string name;
public:
    animal(string n,int a):name(n),age(a) {}
    virtual void speak()=0;
};
class tiger:public animal
{
public:
    tiger(string n,int a):animal(n,a) {}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",AOOO."<<endl;
    }
};
class dog:public animal
{
public:
    dog(string n,int a):animal(n,a) {}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",WangWang."<<endl;
    }
};
class Duck:public animal
{
public:
    Duck(string n,int a):animal(n,a) {}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",GAGA."<<endl;
    }
};
class Pig:public animal
{
public:
    Pig(string n,int a):animal(n,a) {}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
    }
};
int main()
{
    //freopen("C:\\Users\\241\\Desktop\\1.txt","r",stdin);
    int T,a;
    string n,type;
    cin>>T;
    while(T--)
    {
        animal *p;
        cin>>type>>n>>a;
        if(type=="Tiger")
        {
            tiger t(n,a);
            p=&t;
            p->speak();
        }
        else if(type=="Pig")
        {
            Pig pp(n,a);
            p=&pp;
            p->speak();
        }
        else if(type=="Duck")
        {
            Duck d(n,a);
            p=&d;
            p->speak();
        }
        else if(type=="Dog")
        {
            dog dg(n,a);
            p=&dg;
            p->speak();
        }
        else
        {
            cout<<"There is no "<<type<<" in our Zoo."<<endl;
        }
    }
}

