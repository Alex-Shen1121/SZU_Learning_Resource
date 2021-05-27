2018182052:Problem1120:ÕýÈ·
#include <iostream>
#include<cstdio>
#include<cstring>
#include <string>
#define ADDRESS "C:\\Users\\241\\Desktop\\in.txt","r",stdin
using namespace std;
class Animal
{
protected:
    string name;
    int wei;
    int age;
public:
    Animal() {}
    Animal(const string& n,int a):name(n),wei(60),age(a) {}
    virtual void speak()const=0;
};
class Tiger:public Animal
{
public:
    Tiger(const string& n,int a):Animal(n,a) {}
    void speak()const
    {
        cout<<"Hello,I am "<<name<<",AOOO."<<endl;
    }
};
class Dog:public Animal
{
public:
    Dog(const string& n,int a):Animal(n,a) {}
    void speak()const
    {
        cout<<"Hello,I am "<<name<<",WangWang."<<endl;
    }
};
class Duck:public Animal
{
public:
    Duck(const string& n,int a):Animal(n,a) {}
    void speak()const
    {
        cout<<"Hello,I am "<<name<<",GAGA."<<endl;
    }
};
class Pig:public Animal
{
public:
    Pig(const string& n,int a):Animal(n,a) {}
    void speak()const
    {
        cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
    }
};
int main()
{
  //  freopen(ADDRESS);
    int T(0);
    cin>>T;
    string cmd;
    string name;
    int age;
    Animal* p;
    while(T--)
    {
        cin>>cmd>>name>>age;
        if(cmd=="Tiger")
        {
            Tiger te(name,age);
            p=&te;
            p->speak();
        }
        else if(cmd=="Pig")
        {
            Pig te(name,age);
            p=&te;
            p->speak();
        }
        else if(cmd=="Duck")
        {
            Duck te(name,age);
            p=&te;
            p->speak();
        }
        else if(cmd=="Dog")
        {
            Dog te(name,age);
            p=&te;
            p->speak();
        }
        else
        {
            cout<<"There is no "<<cmd<<" in our Zoo."<<endl;
        }
    }
    return 0;
}
