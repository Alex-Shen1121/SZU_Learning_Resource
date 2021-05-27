2017182103:Problem1120:ÕýÈ·
#include <iostream>
using namespace std;

class Animal
{
protected:
    string name;
    int age,weight;
public:
    Animal(string n=" ",int a=0):name(n),age(a) {}
    virtual void speak()=0;
    ~Animal() {}
};
class Tiger:public Animal
{
public:
    Tiger(string n,int a):Animal(n,a) {}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",AOOO."<<endl;
    }
    ~Tiger() {}
};

class Dog:public Animal
{
public:
    Dog(string n,int a):Animal(n,a) {}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",WangWang."<<endl;
    }
    ~Dog() {}
};

class Duck:public Animal
{
public:
    Duck(string n,int a):Animal(n,a) {}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",GAGA."<<endl;
    }
    ~Duck() {}
};

class Pig:public Animal
{
public:
    Pig(string n,int a):Animal(n,a) {}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
    }
    ~Pig() {}
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string type;
        cin>>type;

        Animal *a;

        string name;
        int age;
        cin>>name>>age;

        if(type=="Tiger")
        {
            Tiger t(name,age);
            a = &t;
            a->speak();
        }
        else if(type=="Dog")
        {
            Dog d(name,age);
            a = &d;
            a->speak();
        }
        else if(type=="Duck")
        {
            Duck duck(name,age);
            a = &duck;
            a->speak();
        }
        else if(type=="Pig")
        {
            Pig p(name,age);
            a = &p;
            a->speak();
        }
        else
            cout<<"There is no "<<type<<" in our Zoo."<<endl;

    }
    return 0;
}

