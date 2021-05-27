2018192008:Problem1120:ÕýÈ·
#include<iostream>

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

class Tiger:public Animal
{
public:
     Tiger(string n,int a):Animal(n,a){}
     virtual void speak()
     {
         cout<<"Hello,I am "<<name<<",AOOO."<<endl;
     }
};

class Pig:public Animal
{
public:
     Pig(string n,int a):Animal(n,a){}
     virtual void speak()
     {
         cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
     }
};

class Duck:public Animal
{
public:
     Duck(string n,int a):Animal(n,a){}
     virtual void speak()
     {
         cout<<"Hello,I am "<<name<<",GAGA."<<endl;
     }
};

class Dog:public Animal
{
public:
     Dog(string n,int a):Animal(n,a){}
     virtual void speak()
     {
         cout<<"Hello,I am "<<name<<",WangWang."<<endl;
     }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string kind,name;
        int a;
        cin>>kind>>name>>a;
        Animal *an;
        if(kind!="Tiger"&&kind!="Pig"&&kind!="Duck"&&kind!="Dog")
            cout<<"There is no "<<kind<<" in our Zoo."<<endl;
        else if(kind=="Tiger")
        {
            Tiger t1(name,a);
            an=&t1;
            an->speak();
        }
         else if(kind=="Pig")
        {
            Pig p1(name,a);
            an=&p1;
            an->speak();
        }
         else if(kind=="Duck")
        {
            Duck d1(name,a);
            an=&d1;
            an->speak();
        }
        else if(kind=="Dog")
        {
            Dog dog(name,a);
            an=&dog;
            an->speak();
        }

    }
}

