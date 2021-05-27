2018152037:Problem1120:ÕýÈ·
#include<iostream>
#include<string>
using namespace std;

class Animal
{
	string name;
	int nl;
public:
	Animal(string n,int l)
	{
		name=n;
		nl=l;
	}
	virtual void speak()
	{
	}
	void print()
	{
		cout<<"Hello,I am "<<name<<","; 
	}
};

class Tiger:public Animal
{
public:
	Tiger(string n,int l):Animal(n,l)
	{
	}
	void speak()
	{
		cout<<"AOOO."<<endl;
	}
};

class Dog:public Animal
{
public:
	Dog(string n,int l):Animal(n,l)
	{
	}
	void speak()
	{
		cout<<"WangWang."<<endl;
	}
};

class Duck:public Animal
{
public:
	Duck(string n,int l):Animal(n,l)
	{
	}
	void speak()
	{
		cout<<"GAGA."<<endl;
	}
};

class Pig:public Animal
{
public:
	Pig(string n,int l):Animal(n,l)
	{
	}
	void speak()
	{
		cout<<"HENGHENG."<<endl;
	}
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		Animal *aa;
		string n,an;
		int l;
		cin>>an>>n>>l;
		if(an=="Tiger")
		{
			Tiger a1(n,l);
			aa=&a1;
			aa->print();
			aa->speak();
		}
		else if(an=="Dog")
		{
			Dog a2(n,l);
			aa=&a2;
			aa->print();
			aa->speak();
		}
		else if(an=="Duck")
		{
			Duck a3(n,l);
			aa=&a3;
			aa->print();
			aa->speak();
		}
		else if(an=="Pig")
		{
			Pig a4(n,l);
			aa=&a4;
			aa->print();
			aa->speak();
		}
		else
		{
			cout<<"There is no "<<an<<" in our Zoo."<<endl;
		}
	}
	return 0;
}
