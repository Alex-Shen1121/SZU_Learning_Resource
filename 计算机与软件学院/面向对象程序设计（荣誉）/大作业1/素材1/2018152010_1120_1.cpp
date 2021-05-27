2018152010:Problem1120:ÕýÈ·
#include<iostream>

using namespace std;
class Animal
{
protected:
    string type,name;
    int age;
public:
    Animal(string t,string n,int a):type(t),name(n),age(a){}
    virtual void display()=0;
};

class Dog:public Animal
{
public:
    Dog(string type,string name,int age):Animal(type,name,age){}
    void display()
    {
        cout<<"Hello,I am "<<name<<','<<"WangWang."<<endl;
        //Hello,I am Jumpjump,AOOO.
    }
};

class Tiger:public Animal
{
public:
    Tiger(string type,string name,int age):Animal(type,name,age){}
    void display()
    {
        cout<<"Hello,I am "<<name<<','<<"AOOO."<<endl;

    }
};

class Pig:public Animal
{
public:
    Pig(string type,string name,int age):Animal(type,name,age){}
    void display()
    {
        cout<<"Hello,I am "<<name<<','<<"HENGHENG."<<endl;
        //Hello,I am Jumpjump,AOOO.
    }
};

class Duck:public Animal
{
public:
    Duck(string type,string name,int age):Animal(type,name,age){}
    void display()
    {
        cout<<"Hello,I am "<<name<<','<<"GAGA."<<endl;
        //Hello,I am Jumpjump,AOOO.
    }
};

int main()
{
    string name,type;
    int t,age;
    Animal *pv;
    cin>>t;
    while(t--)
    {
        cin>>type>>name>>age;
        if(type=="Dog")
        {
           Dog dog(type,name,age);
           pv=&dog;
           pv->display();
        }
        else if(type=="Pig")
        {
            Pig pig(type,name,age);
            pv=&pig;
            pv->display();
        }
        else if(type=="Tiger")
        {
            Tiger tiger(type,name,age);
            pv=&tiger;
            pv->display();
        }
        else if(type=="Duck")
        {
            Duck duck(type,name,age);
            pv=&duck;
            pv->display();
        }
        else
            cout<<"There is no "<<type<<" in our Zoo."<<endl;
    }


}

