2018151051:Problem1120:ÕýÈ·
#include<iostream>
#include<string>
using namespace std;
class Animal
{
protected:
	string name;
	int year;
public:
	Animal(){}
	virtual void speak()=0;
};
class Tiger:public Animal
{
public:
	Tiger(string n,int y)
	{
		name=n;
		year=y;
	}
	virtual void speak()
	{
		cout<<"Hello,I am "<<name<<",AOOO."<<endl;
	}
};
class Dog:public Animal
{
public:
	Dog(string n,int y)
	{
		name=n;
		year=y;
	}
	virtual void speak()
	{
		cout<<"Hello,I am "<<name<<",WangWang."<<endl;
	}
};
class Duck:public Animal
{
public:
	Duck(string n,int y)
	{
		name=n;
		year=y;
	}
	virtual void speak()
	{
		cout<<"Hello,I am "<<name<<",GAGA."<<endl;
	}
};
class Pig:public Animal
{
public:
	Pig(string n,int y)
	{
		name=n;
		year=y;
	}
	virtual void speak()
	{
		cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
	}
};
int main()
{
	int n,i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		Animal *p;
		string ask;
		cin>>ask;
		string name;
		int year;
		cin>>name>>year;
		if(ask=="Tiger")
		{
			p=new Tiger(name,year);
			p->speak();
		}
		else if(ask=="Dog")
		{
			p=new Dog(name,year);
			p->speak();
		}
		else if(ask=="Duck")
		{
			p=new Duck(name,year);
			p->speak();
		}
		else if(ask=="Pig")
		{
			p=new Pig(name,year);
			p->speak();
		}
		else
		{
			cout<<"There is no "<<ask<<" in our Zoo."<<endl;
		}
	}
	return 0;
}
