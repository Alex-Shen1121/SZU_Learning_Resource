2018151044:Problem1120:ÕýÈ·
#include<string>
#include<iostream>
using namespace std;
class AN
{
protected:
	int year;
	string name;
public:
	AN(string s,int a):name(s),year(a) {}
	virtual void Speak()=0;
};
class Tiger:public AN
{
public:
	Tiger(string s,int a):AN(s,a) {}
	void Speak()
	{
		cout<<"Hello,I am "<<name<<",AOOO."<<endl;
	}
};
class Dog:public AN
{
public:
	Dog(string s,int a):AN(s,a) {}
	void Speak()
	{
		cout<<"Hello,I am "<<name<<",WangWang."<<endl;
	}
};
class Duck:public AN
{
public:
	Duck(string s,int a):AN(s,a) {}
	void Speak()
	{
		cout<<"Hello,I am "<<name<<",GAGA."<<endl;
	}
};
class Pig:public AN
{
public:
	Pig(string s,int a):AN(s,a) {}
	void Speak()
	{
		cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
	}
};
int main()
{
	int t;
	AN *p;
	cin>>t;
	while(t--)
	{
		string type,name;
		int year;
		cin>>type>>name>>year;
		if(type=="Tiger")
		{
			p=new Tiger(name,year);
			p->Speak();
			delete p;
		}
		else if(type=="Dog")
		{
			p=new Dog(name,year);
			p->Speak();
			delete p;
		}
		else if(type=="Duck")
		{
			p=new Duck(name,year);
			p->Speak();
			delete p;
		}
		else if(type=="Pig")
		{
			p=new Pig(name,year);
			p->Speak();
			delete p;
		}
		else 
			cout<<"There is no "<<type<<" in our Zoo."<<endl;
	}
}
