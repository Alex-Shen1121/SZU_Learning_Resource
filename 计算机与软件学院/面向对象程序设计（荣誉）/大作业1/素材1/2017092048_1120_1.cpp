2017092048:Problem1120:ÕýÈ·

#include <iostream>
#include <string>
#include <iomanip>
#include <map>

using namespace std;

class Animal{
protected:
	string name;
	int age;
public:
	Animal() {}
	Animal(string n = "", int a = 0) {
		name = n;
		age = a;
	}
	~Animal() {};
	virtual void speak() = 0;
};

class Tiger:public Animal {
public:
	Tiger(string n, int a) :Animal(n, a) {}

	virtual ~Tiger() {

	}

	void speak() {
		cout << "Hello,I am " << name << ",AOOO." << endl;
	}
};

class Dog:public Animal {
public:
	Dog(string n, int a) : Animal(n, a) {};

	virtual ~Dog() {

	}

	void speak() {
		cout << "Hello,I am " << name << ",WangWang." << endl;
	}
};

class Duck:public Animal {
public:
	Duck(string n, int a) : Animal(n, a) {}

	virtual ~Duck() {

	}

	void speak() {
		cout << "Hello,I am " << name << ",GAGA." << endl;

	}
};

class Pig:public Animal {
public:
	Pig(string n, int a) : Animal(n, a) {}

	virtual ~Pig() {

	}

	void speak() {
		cout << "Hello,I am " << name << ",HENGHENG." << endl;

	}
};

int main() {
	int samples;
	cin >> samples;
	Animal *pa;
	while (samples--) {
		string type;
		string name;
		int age;
		cin >> type >> name >> age;

		if (type == "Tiger") {
			pa = new Tiger(name, age);
		}
		else if (type == "Dog") {
			pa = new Dog(name, age);
		}
		else if (type == "Duck") {
			pa = new Duck(name, age);
		}
		else if (type == "Pig") {
			pa = new Pig(name, age);
		}
		else {
			cout << "There is no " << type << " in our Zoo." << endl;
			continue;
		}
		pa->speak();
	}
	return 0;
}
