2018151085:Problem1120:ÕýÈ·
#include<bits/stdc++.h>
using namespace std;

class Animal
{ 
protected:
	string name;
	string call;
	int age;
public:
	Animal(string Name,string Call,int Age):name(Name),call(Call),age(Age){}
	virtual void speak()=0;
};

class Tiger:public Animal
{
public:
	Tiger(string Name,string Call,int Age):Animal(Name,Call,Age){}
	virtual void speak()
	{
		cout<<"Hello,I am "<<call<<",AOOO."<<endl;
	}
};

class Dog:public Animal
{
public:
	Dog(string Name,string Call,int Age):Animal(Name,Call,Age){}
	virtual void speak()
	{
		cout<<"Hello,I am "<<call<<",WangWang."<<endl;
	}
};

class Duck:public Animal
{
public:
	Duck(string Name,string Call,int Age):Animal(Name,Call,Age){}
	virtual void speak()
	{
		cout<<"Hello,I am "<<call<<",GAGA."<<endl;
	}
};

class Pig:public Animal
{
public:
	Pig(string Name,string Call,int Age):Animal(Name,Call,Age){}
	virtual void speak()
	{
		cout<<"Hello,I am "<<call<<",HENGHENG."<<endl;
	}
};

int main()
{
	int t;
	cin>>t;
	
	Animal *p;
	string name,call;
	int age;
	while(t--)
	{
		cin>>name;
		
		if(name=="Tiger")
		{
			cin>>call>>age;
			p=new Tiger(name,call,age);
			p->speak();
			delete p;
		}
		
		else if(name=="Dog")
		{
			cin>>call>>age;
			p=new Dog(name,call,age);
			p->speak();
			delete p;
		}
		
		else if(name=="Duck")
		{
			cin>>call>>age;
			p=new Duck(name,call,age);
			p->speak();
			delete p;
		}
		
		else if(name=="Pig")
		{
			cin>>call>>age;
			p=new Pig(name,call,age);
			p->speak();
			delete p;
		}
		
		else
		{
			cin>>call>>age;
			cout<<"There is no "<<name<<" in our Zoo."<<endl;
		}
			
	}
}
