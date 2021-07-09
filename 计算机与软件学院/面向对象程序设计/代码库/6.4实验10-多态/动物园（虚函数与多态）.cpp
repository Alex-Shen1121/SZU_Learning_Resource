#include<iostream>
using namespace std;

class Animal {
protected:
	string name;
	int age;
public:
	Animal() {}
	virtual void Speak() = 0;
};

class Tiger :public Animal {
public:
	Tiger(string name, int age) {
		this->name = name;
		this->age = age;
	}
	void Speak() {
		cout << "Hello,I am " << name << ",AOOO." << endl;
	}
};

class Dog :public Animal {
public:
	Dog(string name, int age) {
		this->name = name;
		this->age = age;
	}
	void Speak() {
		cout << "Hello,I am " << name << ",WangWang." << endl;
	}
};

class Duck :public Animal {
public:
	Duck(string name, int age) {
		this->name = name;
		this->age = age;
	}
	void Speak() {
		cout << "Hello,I am " << name << ",GAGA." << endl;
	}
};

class Pig :public Animal {
public:
	Pig(string name, int age) {
		this->name = name;
		this->age = age;
	}
	void Speak() {
		cout << "Hello,I am " << name << ",HENGHENG." << endl;
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		Animal* p;
		string type, name;
		int age;
		cin >> type >> name >> age;
		if (type == "Tiger") {
			Tiger obj(name, age);
			p = &obj;
			p->Speak();
		}
		else if (type == "Dog") {
			Dog obj(name, age);
			p = &obj;
			p->Speak();
		}
		else if (type == "Duck") {
			Duck obj(name, age);
			p = &obj;
			p->Speak();
		}
		else if (type == "Pig") {
			Pig obj(name, age);
			p = &obj;
			p->Speak();
		}
		else {
			cout << "There is no " << type << " in our Zoo." << endl;
		}
	}
	return 0;
}
