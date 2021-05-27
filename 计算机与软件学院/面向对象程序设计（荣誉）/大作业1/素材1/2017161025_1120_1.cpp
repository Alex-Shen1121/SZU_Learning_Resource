2017161025:Problem1120:ÕýÈ·
#pragma warning (disable: 4996)
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 512;

class Animal
{
protected:
	char name[maxn];
	int age;
public:
	Animal(char *n, int a) :age(a) { strcpy(name, n); }

	virtual void Speak()
	{
		cout << "Hello,I am " << name << "(Fake)" << endl;
	}
};

class Tiger :public Animal
{
public:
	Tiger(char *n, int a) :Animal(n, a) {}

	virtual void Speak()
	{
		cout << "Hello,I am " << name << ",AOOO." << endl;
	}
};
class Dog :public Animal
{
public:
	Dog(char *n, int a) :Animal(n, a) {}

	virtual void Speak()
	{
		cout << "Hello,I am " << name << ",WangWang." << endl;
	}
};
class Duck :public Animal
{
public:
	Duck(char *n, int a) :Animal(n, a) {}

	virtual void Speak()
	{
		cout << "Hello,I am " << name << ",GAGA." << endl;
	}
};
class Pig :public Animal
{
public:
	Pig(char *n, int a) :Animal(n, a) {}

	virtual void Speak()
	{
		cout << "Hello,I am " << name << ",HENGHENG." << endl;
	}
};


int main()
{
	int age, t;
	char name[maxn];
	string kind;

	Animal *p;
	cin >> t;
	while (t--)
	{
		cin >> kind >> name >> age;
		if (kind == "Tiger")
		{
			Tiger tiger(name, age);
			p = &tiger;
		}
		else if (kind == "Dog")
		{
			Dog dog(name, age);
			p = &dog;
		}
		else if (kind == "Duck")
		{
			Duck duck(name, age);
			p = &duck;
		}
		else if (kind == "Pig")
		{
			Pig pig(name, age);
			p = &pig;
		}
		else
		{
			cout << "There is no " << kind << " in our Zoo." << endl;
			continue;
		}
		p->Speak();
	}
	return 0;
}
