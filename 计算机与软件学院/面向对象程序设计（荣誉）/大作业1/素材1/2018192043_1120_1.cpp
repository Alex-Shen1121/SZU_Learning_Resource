2018192043:Problem1120:ÕýÈ·
#include <iostream>
using namespace std;
class Animal
{
protected:
    string name;
    int age;
public:
    Animal(string names,int ages):name(names),age(ages){}
    virtual void speak()=0;
    ~Animal(){}
};
class Tiger:public Animal
{
public:
    Tiger(string names,int ages):Animal(names,ages){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",AOOO."<<endl;
    }
    ~Tiger(){}
};
class Dog:public Animal
{
public:
    Dog(string names,int ages):Animal(names,ages){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",WangWang."<<endl;
    }
    ~Dog(){}
};
class Duck:public Animal
{
public:
    Duck(string names,int ages):Animal(names,ages){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",GAGA."<<endl;
    }
    ~Duck(){}
};
class Pig:public Animal
{
public:
    Pig(string names,int ages):Animal(names,ages){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
    }
    ~Pig(){}
};
int main()
{
    Animal *p;
    int t,age;
    string type,name;
    cin>>t;
    while(t--)
    {
        cin>>type>>name>>age;
        if(type=="Tiger")
        {
            Tiger a(name,age);
            p=&a;
            p->speak();
        }
        else if(type=="Pig")
        {
            Pig a(name,age);
            p=&a;
            p->speak();
        }
        else if(type=="Dog")
        {
            Dog a(name,age);
            p=&a;
            p->speak();
        }
        else if(type=="Duck")
        {
            Duck a(name,age);
            p=&a;
            p->speak();
        }
        else
        {
            cout<<"There is no "<<type<<" in our Zoo."<<endl;
        }
    }
    return 0;
}

