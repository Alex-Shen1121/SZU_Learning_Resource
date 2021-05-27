2018151027:Problem1120:ÕýÈ·
#include <iostream>
using namespace std;
class Animal
{
protected:
    string type;
public:
    virtual void speak()=0;
    Animal(string n):type(n){}

};
class Tiger: public Animal
{
protected:
    string name;
    int age;
public:
    Tiger(string t,string n,int a):Animal(n),name(n),age(a){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",AOOO."<<endl;
    }
};
class Dog: public Animal
{
protected:
    string name;
    int age;
public:
    Dog(string t,string n,int a):Animal(n),name(n),age(a){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",WangWang."<<endl;
    }
};
class Duck: public Animal
{
protected:
    string name;
    int age;
public:
    Duck(string t,string n,int a):Animal(n),name(n),age(a){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",GAGA."<<endl;
    }
};
class Pig: public Animal
{
protected:
    string name;
    int age;
public:
    Pig(string t,string n,int a):Animal(n),name(n),age(a){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
    }
};
main()
{
    string type;
    string name;
    int age;
    int t;
    Animal *p;
    cin>>t;
    while(t--)
    {
        cin>>type;
        if(type=="Tiger")
        {
            cin>>name>>age;
            p=new Tiger(type,name,age);
            p->speak();
        }
        else if(type=="Pig")
        {
            cin>>name>>age;
            p=new Pig(type,name,age);
            p->speak();
        }
        else if(type=="Duck")
        {
            cin>>name>>age;
            p=new Duck(type,name,age);
            p->speak();

        }
        else if(type=="Dog")
        {
            cin>>name>>age;
            p=new Dog(type,name,age);
            p->speak();
        }
        else
        {
            cin>>name>>age;
            cout<<"There is no "<<type<<" in our Zoo."<<endl;
        }


    }

}

