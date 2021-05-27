2018192037:Problem1120:ÕýÈ·
#include<bits/stdc++.h>
using namespace std;

class CAnimal
{
protected:
    string name;
    int age;
public:
    CAnimal(){}
    virtual void speak()=0;
};

class Tiger:public CAnimal
{
public:
    Tiger(string n,int y)
    {
        name = n;
        age = y;
    }
    void speak()
    {
        cout<<"Hello,I am "<<name<<",AOOO."<<endl;
    }
};

class Dog:public CAnimal
{
public:
    Dog(string n,int y)
    {
        name = n;
        age = y;
    }
    void speak()
    {
        cout<<"Hello,I am "<<name<<",WangWang."<<endl;
    }
};

class Duck:public CAnimal
{
public:
    Duck(string n,int y)
    {
        name = n;
        age = y;
    }
    void speak()
    {
        cout<<"Hello,I am "<<name<<",GAGA."<<endl;
    }
};

class Pig:public CAnimal
{
public:
    Pig(string n,int y)
    {
        name = n;
        age = y;
    }
    void speak()
    {
        cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
    }
};


int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        CAnimal *p;
        int a;
        string type,n;
        cin>>type;
        cin>>n;
        cin>>a;
        if(type == "Tiger")
        {
            Tiger Tiger(n,a);
            p = &Tiger;
            p->speak();
        }
        else if(type == "Dog")
        {
            Dog dog(n,a);
            p = &dog;
            p->speak();
        }
        else if(type == "Duck")
        {
            Duck duck(n,a);
            p = &duck;
            p->speak();
        }
        else if(type == "Pig")
        {
            Pig pig(n,a);
            p = &pig;
            p->speak();
        }
        else
        {
            cout<<"There is no "<<type<<" in our Zoo."<<endl;
        }

    }
}

