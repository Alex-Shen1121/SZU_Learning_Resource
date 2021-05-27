2018151014:Problem1120:ÕýÈ·
#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
	Animal(string n, int a) : name(n), age(a) {
		
	}
	
	virtual void speak() = 0;
	
protected:
	string name;
	int age;
};

class Tiger : public Animal {
public:
	Tiger(string n, int a) : Animal(n, a) {
		
	}
	
	void speak() {
		cout << "Hello,I am " << name << ",AOOO.\n";
	}
};

class Pig : public Animal {
public:
	Pig(string n, int a) : Animal(n, a) {
		
	}
	
	void speak() {
		cout << "Hello,I am " << name << ",HENGHENG.\n";
	}
};

class Duck : public Animal {
public:
	Duck(string n, int a) : Animal(n, a) {
		
	}
	
	void speak() {
		cout << "Hello,I am " << name << ",GAGA.\n";
	}
};

class Dog : public Animal {
public:
	Dog(string n, int a) : Animal(n, a) {
		
	}
	
	void speak() {
		cout << "Hello,I am " << name << ",WangWang.\n";
	}
};

int main(void) {
	
	int t;
	cin >> t;
	while (t--) {
		Animal *ptr;
		string type;
		string name;
		int age;
		
		cin >> type >> name >> age;
		if (type == "Tiger") {
			ptr = new Tiger(name, age);
			ptr->speak();
		}
		else if (type == "Pig") {
			ptr = new Pig(name, age);
			ptr->speak();
		}
		else if (type == "Dog") {
			ptr = new Dog(name, age);
			ptr->speak();
		}
		else if (type == "Duck") {
			ptr = new Duck(name, age);
			ptr->speak();
		}
		else {
			cout << "There is no " << type << " in our Zoo.\n";
			continue;
		}
		delete ptr;
	}
	
	return 0;
}
