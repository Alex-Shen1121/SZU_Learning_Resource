2018152029:Problem1120:ÕýÈ·
#include<bits/stdc++.h>
using namespace std;
 
class Animal
{
protected:
    string name;
    int year;
public:
    Animal(string n,int y):name(n),year(y){}
    virtual void Speak()=0;
 
};
 
class Tiger:public Animal
{
public:
    Tiger(string n,int y):Animal(n,y){}
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",";
        cout<<"AOOO."<<endl;
    }
};
 
class Pig:public Animal
{
public:
    Pig(string n,int y):Animal(n,y){}
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",";
        cout<<"HENGHENG."<<endl;
    }
};
 
class Duck:public Animal
{
public:
    Duck(string n,int y):Animal(n,y){}
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",";
        cout<<"GAGA."<<endl;
    }
};
 
class Dog:public Animal
{
public:
    Dog(string n,int y):Animal(n,y){}
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",";
        cout<<"WangWang."<<endl;
    }
};
 
int main()
{
    int T;
    cin>>T;
    Animal *pv;
    while(T--)
    {
        string kind,name;
        int year;
        cin>>kind>>name>>year;
        if(kind=="Tiger")
        {
            Tiger a(name,year);
            pv=&a;
            pv->Speak();
        }
        else if(kind=="Dog")
        {
            Dog a(name,year);
            pv=&a;
            pv->Speak();
        }
        else if(kind=="Duck")
        {
            Duck a(name,year);
            pv=&a;
            pv->Speak();
        }
        else if(kind=="Pig")
        {
            Pig a(name,year);
            pv=&a;
            pv->Speak();
        }
        else
            cout<<"There is no "<<kind<<" in our Zoo."<<endl;
    }
    return 0;
}
