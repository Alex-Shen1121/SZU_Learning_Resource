#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;
#define PI 3.14

class Employee {
protected:
	string name, position;
	int grade, year;
public:
	Employee() {};
	Employee(string n, string p, int g, int y) {
		name = n;
		position = p;
		grade = g;
		year = y;
	}
	virtual int salary() {
		return 1000 + 500 * grade + 50 * year;
	}
};

class Teamleader :public Employee {
public:
	Teamleader(string n, string p, int g, int y) :Employee(n, p, g, y) {
	}
	int salary() {
		return 3000 + 800 * grade + 100 * year;
	}
};

class Manager :public Employee {
public:
	Manager(string n, string p, int g, int y) :Employee(n, p, g, y) {
	}
	int salary() {
		return 5000 + 1000 * (grade + year);
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		Employee t;
		Employee* p = &t;
		string name, position;
		int grade, year;
		cin >> name >> position >> grade >> year;
		if (!(position == "Employee" || position == "Teamleader" || position == "Manager")) {
			cout << "error position." << endl;
			continue;
		}
		if (grade < 0 || year < 0) {
			cout << "error grade or year." << endl;
			continue;
		}
		if (position == "Employee") {
			Employee obj(name, position, grade, year);
			p = &obj;
			cout << name << ":" << position << ",Salary:" << p->salary() << endl;
		}
		else if (position == "Teamleader") {
			Teamleader obj(name, position, grade, year);
			p = &obj;
			cout << name << ":" << position << ",Salary:" << p->salary() << endl;
		}
		else if (position == "Manager") {
			Manager obj(name, position, grade, year);
			p = &obj;
			cout << name << ":" << position << ",Salary:" << p->salary() << endl;
		}
		
	}
	return 0;
}
