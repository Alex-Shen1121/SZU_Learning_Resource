2018152106:Problem1120:´ð°¸´íÎó
#include<iostream>
using namespace std;

class Animal
{
protected:
	string name;
	int age;
	int weight;
public:
	Animal(string n,int a):name(n),age(a){}
	virtual void speak()=0;
};

class Tiger:public Animal
{
public:
	Tiger(string n,int a):Animal(n,a){}
	void speak()
	{
		cout<<"Hello,I am "<<name<<",AOOO."<<endl;
	}
};

class Pig:public Animal
{
public:
	Pig(string n,int a):Animal(n,a){}
	void speak()
	{
		cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
	}
};

class Duck:public Animal
{
public:
	Duck(string n,int a):Animal(n,a){}
	void speak()
	{
		cout<<"Hello,I am "<<name<<",GAGA."<<endl;
	}
};

int main()
{
	int t;
	Animal *p;
	cin>>t;
	while(t--)
	{
		string a,name;
		int age;
		cin>>a>>name>>age;
		if(a=="Tiger")
		{
			Tiger animal(name,age);
			p=&animal;
			p->speak();
		}
		else if(a=="Pig")
		{
			Pig animal(name,age);
			p=&animal;
			p->speak();
		}
		else if(a=="Duck")
		{
			Duck animal(name,age);
			p=&animal;
			p->speak();
		}
		else
		{
			cout<<"There is no "<<a<<" in our Zoo."<<endl;
		}
	}
	return 0;
}
