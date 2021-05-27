2017152043:Problem1120:ÕýÈ·
#include<iostream>
#include<cstring>
using namespace std;

class Animal{
protected:
	int age;
	int weight;
	string name;
public:
	Animal(){}
	void getInfo(string nam,int ag)
	{
		name = nam;
		age = ag;
	}
	virtual void speak(){}
	~Animal(){}
};

class Tiger:public Animal{
public:
	Tiger(){}
	void speak()
	{
		cout << "Hello,I am " << name << ",AOOO." << endl;
	}
	~Tiger(){}
};

class Dog:public Animal{
public:
	Dog(){}
	void speak()
	{
		cout << "Hello,I am " << name << ",WangWang." << endl;
	}
	~Dog(){}
};

class Duck:public Animal{
public:
	Duck(){}
	void speak()
	{
		cout << "Hello,I am " << name << ",GAGA." << endl;
	}
	~Duck(){}
};

class Pig:public Animal{
public:
	Pig(){}
	void speak()
	{
		cout << "Hello,I am " << name << ",HENGHENG." << endl;
	}
	~Pig(){}
};

int main(){
	int t;
	cin >> t;
	Tiger tiger;
	Dog dog;
	Duck duck;
	Pig pig;
	Animal *pa;
	string type,nam;
	int ag;
	while(t--){
		cin >> type >> nam >> ag;
		if(type == "Tiger"){
			tiger.getInfo(nam,ag);
			pa = &tiger;
			pa->speak();
		}
		else if(type == "Dog"){
			dog.getInfo(nam,ag);
			pa = &dog;
			pa->speak();
		}
		else if(type == "Duck"){
			duck.getInfo(nam,ag);
			pa = &duck;
			pa->speak();
		}
		else if(type == "Pig"){
			pig.getInfo(nam,ag);
			pa = &pig;
			pa->speak();
		}
		else
			cout << "There is no " << type << " in our Zoo." << endl;
	}
	return 0;
}

