2018152021:Problem1120:ÕýÈ·
#include <iostream>
#include <string.h>
using namespace std;
class Animal
{
protected:
    string name;
    int age;
public:
    Animal(string n,int a):name(n),age(a){}
    virtual void Speak()=0;
};
class Tiger :public Animal
{
public:
    Tiger(string n,int a):Animal(n,a){}
    virtual void Speak()
    {
        cout <<"Hello,I am "<< name <<",AOOO."<<endl;
    }
};
class Dog :public Animal
{
public:
    Dog(string n,int a):Animal(n,a){}
    virtual void Speak()
    {
        cout <<"Hello,I am "<< name <<",WangWang."<<endl;
    }
};
class Duck :public Animal
{
public:
    Duck(string n,int a):Animal(n,a){}
    virtual void Speak()
    {
        cout <<"Hello,I am "<< name <<",GAGA."<<endl;
    }
};
class Pig :public Animal
{
public:
    Pig(string n,int a):Animal(n,a){}
    virtual void Speak()
    {
        cout <<"Hello,I am "<< name <<",HENGHENG."<<endl;
    }
};
int main()
{
    int age,t;
    string name,part;
 	Animal *p;
    cin >> t;
    while(t--)
    {
        cin >> part >> name >> age;
        if(part=="Tiger")
        {
            p=new Tiger(name,age);
        }
        else if(part=="Dog")
        {
            p=new Dog(name,age);
        }
        else if(part=="Duck")
        {
            p=new Duck(name,age);
        }
        else if(part=="Pig")
        {
            p=new Pig(name,age);
        }
        else
        {
            cout <<"There is no "<< part <<" in our Zoo."<<endl;
            continue;
        }
        p->Speak();
    }
    return 0;
}
