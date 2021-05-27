2017144045:Problem1120:ÕýÈ·
#include <iostream>
using namespace std;
class Animal
{
protected:
	string name;
public:
	virtual void Speak()=0;
	Animal()
	{	
	}
	Animal(string n)
	{
		name=n;
	}

};

class Tiger:public Animal
{
public:
	Tiger(string n):Animal(n)
	{
	}
	virtual void Speak()
	{
		cout<<"Hello,I am "<<name<<","<<"AOOO."<<endl;
	}
};

class Dog:public Animal
{
public:
	Dog(string n):Animal(n)
	{
	}
	virtual void Speak()
	{
		cout<<"Hello,I am "<<name<<","<<"WangWang."<<endl;
	}
};

class Duck:public Animal
{
public:
	Duck(string n):Animal(n)
	{
	}
	virtual void Speak()
	{
		cout<<"Hello,I am "<<name<<","<<"GAGA."<<endl;
	}
};

class Pig:public Animal
{
public:
	Pig(string n):Animal(n)
	{
	}
	virtual void Speak()
	{
		cout<<"Hello,I am "<<name<<","<<"HENGHENG."<<endl;
	}
};

/*void fn(Animal & c)
{
	c.Speak();
}*/

int main()
{
	int t;
	cin>>t;
	string l;
	string n;
	int age;
	while(t--)
	{
		cin>>l>>n>>age;
		if(l=="Tiger")
		{
			Tiger t(n);
			t.Speak();
		}
		else if(l=="Dog")
		{
			Dog d(n);
			d.Speak();
		}
		else if(l=="Duck")
		{
			Duck du(n);
			du.Speak();
		}
		else if(l=="Pig")
		{
			Pig p(n);
			p.Speak();
		}
		else
		    cout<<"There is no "<<l<<" in our Zoo."<<endl;
	}
}
