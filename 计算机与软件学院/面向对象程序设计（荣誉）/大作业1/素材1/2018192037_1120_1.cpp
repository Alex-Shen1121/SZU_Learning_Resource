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
        int a;
        string type,n;
        cin>>type;
        cin>>n;
        cin>>a;
        if(type == "Tiger")
        {
            Tiger Tiger(n,a);
            Tiger.speak();
        }
        else if(type == "Dog")
        {
            Dog dog(n,a);
            dog.speak();
        }
        else if(type == "Duck")
        {
            Duck duck(n,a);
            duck.speak();
        }
        else if(type == "Pig")
        {
            Pig pig(n,a);
            pig.speak();
        }
        else
        {
            cout<<"There is no "<<type<<" in our Zoo."<<endl;
        }
    }
}

