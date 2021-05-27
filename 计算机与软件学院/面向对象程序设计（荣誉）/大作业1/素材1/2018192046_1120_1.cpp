2018192046:Problem1120:´ð°¸´íÎó
#include<iostream>
using namespace std;
class Animal
{
protected:
    string type,name;
    int age;
public:
    Animal(string _type,string _name,int _age):type(_type),name(_name),age(_age){}
    virtual void Speak()=0;
};
class Tiger:public Animal
{
public:
    Tiger(string _type,string _name,int _age):Animal(_type,_name,_age){}
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",AOOO"<<endl;
    }
};
class Dog:public Animal
{
public:
    Dog(string _type,string _name,int _age):Animal(_type,_name,_age){}
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",WangWang"<<endl;
    }
};
class Duck:public Animal
{
public:
    Duck(string _type,string _name,int _age):Animal(_type,_name,_age){}
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",GAGA"<<endl;
    }
};
class Pig:public Animal
{
public:
    Pig(string _type,string _name,int _age):Animal(_type,_name,_age){}
    void Speak()
    {
        cout<<"Hello,I am "<<name<<",HENGHENG"<<endl;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Animal *pv;
        string type,name;
        int age;
        cin>>type>>name>>age;
        if(type=="Tiger")
        {
            Tiger P(type,name,age);
            pv=&P;
            pv->Speak();
        }
        else if(type=="Dog")
        {
            Dog P(type,name,age);
            pv=&P;
            pv->Speak();
        }
        else if(type=="Pig")
        {
            Pig P(type,name,age);
            pv=&P;
            pv->Speak();
        }
        else if(type=="Duck")
        {
            Duck P(type,name,age);
            pv=&P;
            pv->Speak();
        }
        else
        {
            cout<<"There is no Rabbit in our Zoo."<<endl;
        }
    }
}

