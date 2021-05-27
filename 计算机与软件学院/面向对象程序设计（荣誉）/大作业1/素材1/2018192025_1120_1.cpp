2018192025:Problem1120:ÕýÈ·
#include<iostream>
#include<cstring>
using namespace std;
class Animal
{
protected:
    int age;
    string name;
public:
    Animal(string no, int pAge):name(no),age(pAge) {};
    virtual void Speak()=0;
};

class Tiger:public Animal
{
public:
    Tiger(string no, int pAge):Animal(no,pAge) {};
    virtual void Speak()
    {
        cout<<"Hello,I am "<<name<<",AOOO."<<endl;
    }
};

class Dog:public Animal
{
public:
    Dog(string no, int pAge):Animal(no,pAge) {};
    virtual void Speak()
    {
        cout<<"Hello,I am "<<name<<",WangWang."<<endl;
    }
};

class Duck:public Animal
{
public:
    Duck(string no, int pAge):Animal(no,pAge) {};
    virtual void Speak()
    {
        cout<<"Hello,I am "<<name<<",GAGA."<<endl;
    }
};

class Pig:public Animal
{
public:
    Pig(string no, int pAge):Animal(no,pAge) {};
    virtual void Speak()
    {
        cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Animal *p;
        string pName,no;
        int pAge;
        cin>>pName>>no>>pAge;
        if(pName=="Tiger")
        {
            Tiger ss(no,pAge);
            p=&ss;
            p->Speak();
        }
        else if(pName=="Dog")
        {
            Dog ss(no,pAge);
            p=&ss;
            p->Speak();
        }
        else if(pName=="Duck")
        {
            Duck ss(no,pAge);
            p=&ss;
            p->Speak();
        }
        else if(pName=="Pig")
        {
            Pig ss(no,pAge);
            p=&ss;
            p->Speak();
        }
        else
            cout<<"There is no "<<pName<<" in our Zoo."<<endl;
    }
}

