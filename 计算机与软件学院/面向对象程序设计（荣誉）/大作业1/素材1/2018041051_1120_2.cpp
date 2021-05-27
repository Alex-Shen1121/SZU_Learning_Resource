2018041051:Problem1120:ÕýÈ·
#include<iostream>
#include<string>
#include<cstring>
 
using namespace std;
 
class Animal
{
protected:
    string name;
    int age;
public:
    Animal(){}
    Animal(string name1,int age1):name(name1),age(age1){}
    virtual void Speak()=0;
    virtual ~Animal(){}
};
 
class Tiger:public Animal
{
public:
    Tiger(){}
    Tiger(string name1,int age1):Animal(name1,age1){}
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",AOOO."<<endl;
    }
};
 
class Pig:public Animal
{
public:
    Pig(){}
    Pig(string name1,int age1):Animal(name1,age1){}
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
    }
    ~Pig(){}
};
 
class Dog:public Animal
{
public:
    Dog(){}
    Dog(string name1,int age1):Animal(name1,age1){}
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",WangWang."<<endl;
    }
    ~Dog(){}
};
 
class Duck:public Animal
{
public:
    Duck(){}
    Duck(string name1,int age1):Animal(name1,age1){}
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",GAGA."<<endl;
    }
    ~Duck(){}
};
 
int main()
{
    Animal *a;
 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string type,name;
        cin>>type>>name>>n;
        if(type=="Tiger")
        {
            a=new Tiger(name,n);
            a->Speak();
        }
        else if(type=="Pig")
        {
            a=new Pig(name,n);
            a->Speak();
        }
        else if(type=="Duck")
        {
            a=new Duck(name,n);
            a->Speak();
        }
        else if(type=="Dog")
        {
            a=new Dog(name,n);
            a->Speak();
        }
        else
        {
            cout<<"There is no "<<type<<" in our Zoo."<<endl;
        }	
    }
    delete a;
    return 0;
}
