2016154114:Problem1120:ÕýÈ·
#include<iostream>
#include<string>
using namespace std;

class Animal
{
protected:
    string name;
	int age;
public:
    Animal(string n,int a):name(n),age(a){}
    virtual void Speak()=0;
};

class Tiger:public Animal
{
public:
    Tiger(string n,int a):Animal(n,a){}
    virtual void Speak()
    {
		cout<<"Hello,I am "<<name<<",AOOO."<<endl;
    }
};

class Dog:public Animal
{
public:
    Dog(string n,int a):Animal(n,a){}
    virtual void Speak()
    {
		cout<<"Hello,I am "<<name<<",WangWang."<<endl;
    }
};

class Duck:public Animal
{
public:
    Duck(string n,int a):Animal(n,a){}
    virtual void Speak()
    {
		cout<<"Hello,I am "<<name<<",GAGA."<<endl;
    }
};

class Pig:public Animal
{
public:
    Pig(string n,int a):Animal(n,a){}
    virtual void Speak()
    {
		cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
    }
};

int main()
{
    int i;
    cin>>i;
    while(i--)
    {
		Animal *zoo;
		string name,type;
		int age;
        cin>>type>>name>>age;
        if(type=="Tiger")
		{
			Tiger t(name,age);
			zoo=&t;
			zoo->Speak();
		}
		else if(type=="Dog")
        {
			Dog dg(name,age);
			zoo=&dg;
			zoo->Speak();
        }
		else if(type=="Duck")
        {
			Duck dk(name,age);
			zoo=&dk;
			zoo->Speak();
        }
		else if(type=="Pig")
		{
			Pig p(name,age);
			zoo=&p;
			zoo->Speak();
		}
		else
			cout<<"There is no "<<type<<" in our Zoo."<<endl;
    }
	return 0;
}
