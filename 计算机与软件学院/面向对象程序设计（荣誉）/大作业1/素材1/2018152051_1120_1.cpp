2018152051:Problem1120:ÕýÈ·
#include<iostream>
using namespace std;
class Animal
{ 
protected:
	string name;
	int age;
public:
	Animal(){}
	Animal(string n,int Age)
	{
		name = n;
		age = Age;
	}
	void virtual speak(){}
};
class CTiger:public Animal
{
public:
	CTiger(){}
	CTiger(string s,int a)
	{
		name = s;
		age = a;
	}
	void speak()
	{
		cout<<"Hello,I am "<<name<<",AOOO."<<endl;
	}
};
class Cdog:public Animal
{
public:
	Cdog(){}
	Cdog(string s,int a)
	{
		name = s;
		age = a;
	}
	void speak()
	{
		cout<<"Hello,I am "<<name<<",WangWang."<<endl;
	}
};
class Cduck:public Animal
{
public:
	Cduck(){}
	Cduck(string s,int a)
	{
		name = s;
		age = a;
	}
	void speak()
	{
		cout<<"Hello,I am "<<name<<",GAGA."<<endl;
	}
};
class CPig:public Animal
{
public:
	CPig(){}
	CPig(string s,int a)
	{
		name = s;
		age = a;
	}
	void speak()
	{
		cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
	}
};

int main()
{
	int T;
	cin>>T;
	Animal *pv;
	while(T--)
	{
		string S,Name;
		int age;
		cin>>S;
		if(S == "Tiger")
		{
			cin>>Name>>age;
			CTiger tiger(Name,age);
			pv = &tiger;
			pv->speak();
		}
		else if(S == "Duck")
		{
			cin>>Name>>age;
			Cduck duck(Name,age);
			pv = &duck;
			pv->speak();
		}
		else if(S == "Pig")
		{
			cin>>Name>>age;
			CPig pig(Name,age);
			pv = &pig;
			pv->speak();
		}
		else if(S == "Dog")
		{
			cin>>Name>>age;
			Cdog dog(Name,age);
			pv = &dog;
			pv->speak();
		}
		else
		{
			cin>>Name>>age;
			cout<<"There is no "<<S<<" in our Zoo."<<endl;
		}
	}
}
