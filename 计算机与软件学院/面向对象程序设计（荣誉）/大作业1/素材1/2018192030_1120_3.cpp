2018192030:Problem1120:ÔËÐÐ´íÎó
#include <iostream>
#include <cstring>
using namespace std;
class Animal
{
protected:
    char name[100];
    int age;
public:
    Animal(char *n,int a):age(a)
    {
        strcpy(name,n);
    }
    virtual void Speak(){}
};
class Tiger:public Animal
{
public:
    Tiger(char *n,int a):Animal(n,a){}
    virtual void Speak()
    {
        cout <<"Hello,I am "<< name <<",AOOO."<<endl;
    }
};
class Dog:public Animal
{
public:
    Dog(char *n,int a):Animal(n,a){}
    virtual void Speak()
    {
        cout <<"Hello,I am "<< name <<",WangWang."<<endl;
    }
};
class Duck:public Animal
{
public:
    Duck(char *n,int a):Animal(n,a){}
    virtual void Speak()
    {
        cout <<"Hello,I am "<< name <<",GAGA."<<endl;
    }
};
class Pig:public Animal
{
public:
    Pig(char *n,int a):Animal(n,a){}
    virtual void Speak()
    {
        cout <<"Hello,I am "<<name<<",HENGHENG."<<endl;
    }
};
int main()
{
    int a,t;
    char n[100];
    string kind;
    Animal *p;
    cin>>t;
    while(t--)
    {
        cin>>kind>>n>>a;
        if(kind=="Tiger")
        {
            Tiger tiger(n,a);
            p=&tiger;
        }
        else if(kind=="Dog")
        {
            Dog dog(n,a);
            p=&dog;
        }
        else if(kind=="Duck")
        {
            Duck duck(n,a);
            p=&duck;
        }
        else if(kind=="Pig")
        {
            Pig pig(n,a);
            p=&pig;
        }
        p->Speak();
    }
    return 0;
}
