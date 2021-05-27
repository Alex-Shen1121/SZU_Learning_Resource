2016102048:Problem1120:正确
#include <bits/stdc++.h>
using namespace std;

class Animal
{ 
protected:

	string name;
	int age;


public:

	virtual void Speak()=0;//应收费用
	Animal(string n,int a):name(n),age(a){
	}

	~Animal(){
	}
};

class Tiger:public Animal 
{
public:
	Tiger(string n,int a):Animal(n,a) 
	{
	}
	virtual void Speak()
	{
		cout<<"Hello,I am "<<name<<",AOOO."<<endl;
	}	
	~Tiger()
	{
	}
};

class Dog:public Animal
{

public:
	Dog(string n,int a):Animal(n,a)
	{
	}
	virtual void Speak()
	{
		cout<<"Hello,I am "<<name<<",WangWang."<<endl;
	}
	~Dog(){
	}
};

class Duck:public Animal
{

public:
	Duck(string n,int a):Animal(n,a)
	{
		
	}
	virtual void Speak()
	{
		cout<<"Hello,I am "<<name<<",GAGA."<<endl;
	}
	~Duck()
	{
	}
};

class Pig:public Animal
{

public:
	Pig(string n,int a):Animal(n,a)
	{
		
	}
	virtual void Speak()
	{
		cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
	}
	~Pig()
	{
	}
};
int main()
{
	int t;
	cin>>t;
	string type,name;
	int age;
	
	while(t--)
	{
		Animal *p;
		cin>>type>>name>>age;
		if(type=="Tiger")
		{
			Tiger ti(name,age);
			p=&ti;
			p->Speak();
		}
		else if(type=="Dog")
		{
			Dog d(name,age);
			p=&d;
			p->Speak();
		}
		else if(type=="Duck")
		{
			Duck du(name,age);
			p=&du;
			p->Speak();
		}
		else if(type=="Pig")
		{
			Pig pi(name,age);
			p=&pi;
			p->Speak();
		}
		else
		{
			cout<<"There is no "<<type<<" in our Zoo."<<endl;
		}
		
	}
	return 0;
}
