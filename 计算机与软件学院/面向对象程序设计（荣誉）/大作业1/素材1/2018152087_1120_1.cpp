2018152087:Problem1120:´ğ°¸´íÎó
#include<iostream>
using namespace std;
class Animal
{
protected:
	string name;
	int old;
public:
	virtual void speak()=0;
};
class Tiger:public Animal
{
public:
	Tiger(string n,int o)
	{
		name=n;
		old=o;
	}
	void speak()
	{
		cout<<"Hello,I am "<<name<<","<<"AOOO."<<endl;
	}
};
class Dog:public Animal
{
public:
	Dog(string n,int o)
	{
		name=n;
		old=o;
	}
	void speak()
	{
		cout<<"Hello,I am "<<name<<","<<"WangWang."<<endl;
	}
};
class Duck:public Animal
{
public:
	Duck(string n,int o)
	{
		name=n;
		old=o;
	}
	void speak()
	{
		cout<<"Hello,I am "<<name<<","<<"GAGA."<<endl;
	}
};
class Pig:public Animal
{
public:
	Pig(string n,int o)
	{
		name=n;
		old=o;
	}
	void speak()
	{
		cout<<"Hello,I am "<<name<<","<<"HENGHENG."<<endl;
	}
};
int main()
{
	int t;
	cin>>t;
	Animal *p;
	while(t--)
	{
		string n;
		int o;
		string name;
		cin>>name;
		if(name=="Tiger")
		{
			cin>>n>>o;
			Tiger ex(n,o);
			p=&ex;
			p->speak();
		}
		else if(name=="Pig")
		{
			cin>>n>>o;
			Pig ex(n,o);
			p=&ex;
			p->speak();
		}
		else if(name=="Duck")
		{
			cin>>n>>o;
			Duck ex(n,o);
			p=&ex;
			p->speak();
		}
		else if(name=="Dog")
		{
			cin>>n>>o;
			Dog ex(n,o);
			p=&ex;
		}
		else 
		{
			cin>>n>>o;
			cout<<"There is no "<<name<<" in our Zoo."<<endl;
		}
	}
}
