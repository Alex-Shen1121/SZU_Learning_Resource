2017161095:Problem1120:´ð°¸´íÎó
//#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

class Animal
{
protected:
    string name;
    int age;
public:
    Animal(string n,int a):name(n),age(a){}
    virtual void speak()=0;
};

class tiger : virtual public Animal
{
public:
    tiger(string n,int a):Animal(n,a){}
    virtual void speak()
    {
        cout<<"Hello,I am "<<name<<",AOOO."<<endl;
    }
};

class dog : virtual public Animal
{
public:
    dog(string n,int a):Animal(n,a){}
    virtual void speak()
    {
        cout<<"Hello,I am "<<name<<",WangWang."<<endl;
    }
};

class duck : virtual public Animal
{
public:
    duck(string n,int a):Animal(n,a){}
    virtual void speak()
    {
        cout<<"Hello,I am "<<name<<",GAGA."<<endl;
    }
};

class pig : virtual public Animal
{
public:
    pig(string n,int a):Animal(n,a){}
    virtual void speak()
    {
        cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
    }
};



int main()
{
    int n,m,t,i,j,k,ans,num,sum,p,w;
    string s,ss;
    Animal *pp;
    cin>>t;
    while(t--)
    {
        cin>>s>>ss>>m;
        if(s=="Tiger")
        {
            tiger a(ss,m);
            pp=&a;
            pp->speak();
        }
        else if(s=="Dog")
        {
            dog a(ss,m);
            pp=&a;
            pp->speak();
        }
        else if(s=="Duck")
        {
            duck a(ss,m);
            pp=&a;
            pp->speak();
        }
        else if(s=="Pig")
        {
            pig a(ss,m);
            pp=&a;
            pp->speak();
        }
        else
        {
            cout<<"There is no Rabbit in our Zoo."<<endl;
        }
    }
}

