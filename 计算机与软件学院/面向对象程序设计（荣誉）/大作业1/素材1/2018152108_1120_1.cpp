2018152108:Problem1120:´ð°¸´íÎó
#include<iostream>
using namespace std;

class Animal
{
protected:
	string name;
	int age;
	double weight;
public:
	Animal(string n,int a)
	{
		name = n;
		age = a;
		weight = 0;
	}
	virtual void speak()
	{
	}
};

class tiger:public Animal
{
public:
	tiger(string n,int a):Animal(n,a){}
	void speak()
	{
		cout<<"Hello,I am "<<name<<","<<"AOOO"<<endl;
	}
};

class dog:public Animal
{
public:
	dog(string n,int a):Animal(n,a){}
	void speak()
	{
		cout<<"Hello,I am "<<name<<","<<"WangWang"<<endl;
	}
};

class duck:public Animal
{
public:
	duck(string n,int a):Animal(n,a){}
	void speak()
	{
		cout<<"Hello,I am "<<name<<","<<"GAGA"<<endl;
	}
};

class pig:public Animal
{
public:
	pig(string n,int a):Animal(n,a){}
	void speak()
	{
		cout<<"Hello,I am "<<name<<","<<"HENGHENG"<<endl;
	}
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string type,name;
		int age;
		Animal *p;
		cin>>type>>name>>age;
		if(type=="Tiger")
		{
			tiger a(name,age);
			p = &a;
			p->speak();
		}
		else if(type=="Dog")
		{
			dog a(name,age);
			p = &a;
			p->speak();
		}
		else if(type=="Duck")
		{
			duck a(name,age);
			p = &a;
			p->speak();
		}
		else if(type=="Pig")
		{
			pig a(name,age);
			p = &a;
			p->speak();
		}
		else
		{
			cout<<"There is no "<<type<<" in our Zoo."<<endl;
		}
	}
	return 0;
}
