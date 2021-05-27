2018151066:Problem1120:ÕýÈ·
#include<iostream>
#include<string>
using namespace std;
class  Animal
{
public:
	virtual void speak() = 0;
};
class Tiger :public Animal
{
protected:
	int age;
	string name;
public:
	Tiger(int a, string n) :age(a), name(n) {}
	void speak()
	{
		cout << "Hello,I am " << name << ",AOOO." << endl;
	}
};

class Pig :public Animal
{
protected:
	int age;
	string name;
public:
	Pig(int a, string n) :age(a), name(n) {}
	void speak()
	{
		cout << "Hello,I am " << name << ",HENGHENG." << endl;
	}
};

class Duck :public Animal
{
protected:
	int age;
	string name;
public:
	Duck(int a, string n) :age(a), name(n) {}
	void speak()
	{
		cout << "Hello,I am " << name << ",GAGA." << endl;
	}
};

class Dog :public Animal
{
protected:
	int age;
	string name;
public:
	Dog(int a, string n) :age(a), name(n) {}
	void speak()
	{
		cout << "Hello,I am " << name << ",WangWang." << endl;
	}
};
int main()
{
	int t;
	Animal *pv;
	cin >> t;
	while (t--)
	{
		string type, name;
		int age;
		cin >> type >> name >> age;
		if (type == "Tiger")
		{
			pv=new Tiger(age, name);
			pv->speak();
		}
		else if (type == "Dog")
		{
			pv=new Dog(age, name);
			pv->speak();

		}
		else if (type == "Duck")
		{
			pv=new Duck(age, name);
			pv->speak();

		}
		else if (type == "Pig")
		{
			pv=new Pig(age, name);
			pv->speak();
		}
		else
			cout << "There is no " << type << " in our Zoo." << endl;
	}
	delete pv;
	return 0;
}
