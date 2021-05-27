2018192038:Problem1120:ÕýÈ·
#include <iostream>

using namespace std;

class Animal
{
public:
    virtual void Speak()=0;
};

class Tiger:public Animal
{
    string name;
    int age;
public:
    Tiger(string nn,int aa):name(nn),age(aa){}
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",AOOO."<<endl;
    }
};
class Dog:public Animal
{
    string name;
    int age;
public:
    Dog(string nn,int aa):name(nn),age(aa){}
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",WangWang."<<endl;
    }
};
class Duck:public Animal
{
    string name;
    int age;
public:
    Duck(string nn,int aa):name(nn),age(aa){}
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",GAGA."<<endl;
    }
};
class Pig:public Animal
{
    string name;
    int age;
public:
    Pig(string nn,int aa):name(nn),age(aa){}
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
    }
};


int main()
{
    string type,name;
    int age;
    int t;
    cin>>t;
    Animal *aa=NULL;
    while(t--)
    {
        cin>>type>>name>>age;
        if(type=="Tiger")
        {
            Tiger tig(name,age);
            aa=&tig;
            aa->Speak();
        }
        else if(type=="Dog")
        {
            Dog dd(name,age);
            aa=&dd;
            aa->Speak();
        }
        else if(type=="Duck")
        {
            Duck duc(name,age);
            aa=&duc;
            aa->Speak();
        }
        else if(type=="Pig")
        {
            Pig pp(name,age);
            aa=&pp;
            aa->Speak();
        }
        else
        {
            cout<<"There is no "<<type<<" in our Zoo."<<endl;
        }
    }
    return 0;
}

