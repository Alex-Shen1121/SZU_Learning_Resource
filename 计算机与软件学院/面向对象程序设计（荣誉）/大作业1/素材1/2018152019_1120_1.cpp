2018152019:Problem1120:´ð°¸´íÎó
#include <iostream>

#include<string.h>

using namespace std;

class Animal
{
protected:
    string name;
    int age;
public:
    virtual void Speak()=0;
    virtual void display()=0;
};

class Tiger:public Animal
{
public:
    Tiger(string n,int a)
    {
        name=n;
        age=a;
    }
    void Speak()
    {
        cout<<"AOOO";
    }
    void display()
    {
        cout<<"Hello,I am "<<name<<",";
    }
};

class Dog:public Animal
{
public:
    Dog(string n,int a)
    {
        name=n;
        age=a;
    }
    void Speak()
    {
        cout<<"WangWang";
    }
    void display()
    {
        cout<<"Hello,I am "<<name<<",";
    }
};

class Duck:public Animal
{
public:
    Duck(string n,int a)
    {
        name=n;
        age=a;
    }
    void Speak()
    {
        cout<<"GAGA";
    }
    void display()
    {
        cout<<"Hello,I am "<<name<<",";
    }
};

class Pig:public Animal
{
public:
    Pig(string n,int a)
    {
        name=n;
        age=a;
    }
    void Speak()
    {
        cout<<"HENGHENG";
    }
    void display()
    {
        cout<<"Hello,I am "<<name<<",";
    }
};

int main()
{
    Animal *panimal;
    int times;
    cin>>times;
    while(times--)
    {
        string type;
        cin>>type;

            if(type=="Tiger")
            {
                string n;
                int a;
                cin>>n>>a;
                Tiger tiger(n,a);
                panimal=&tiger;
                panimal->display();
                panimal->Speak();
                cout<<"."<<endl;
            }
            else if(type=="Dog")
            {
                string n;
                int a;
                cin>>n>>a;
                Dog dog(n,a);
                panimal=&dog;
                panimal->display();
                panimal->Speak();
                cout<<"."<<endl;
            }
            else if(type=="Duck")
            {
                string n;
                int a;
                cin>>n>>a;
                Duck duck(n,a);
                panimal=&duck;
                panimal->display();
                panimal->Speak();
                cout<<"."<<endl;
            }
            else if(type=="Pig")
            {
                string n;
                int a;
                cin>>n>>a;
                Pig pig(n,a);
                panimal=&pig;
                panimal->display();
                panimal->Speak();
                cout<<"."<<endl;
            }
            else
            {
                string n;
                int a;
                cin>>n>>a;
                cout<<"There is no "<<n<<" in our Zoo";
                cout<<"."<<endl;
            }

    }
    return 0;
}
