#include<iostream>
using namespace std;

class Vehicle {
protected:
	string no;//±àºÅ
public:
	Vehicle(string no) {
		this->no = no;
	}
	virtual void display() = 0;
};

class Car :public Vehicle {
protected:
	int num, weight;
public:
	Car(string no, int num, int weight) :Vehicle(no) {
		this->num = num;
		this->weight = weight;
	}
	void display() {
		cout << no << " " << num * 8 + weight * 2 << endl;
	}
};

class Bus :public Vehicle {
protected:
	int num;
public:
	Bus(string no, int num) :Vehicle(no) {
		this->num = num;
	}
	void display() {
		cout << no << " " << num * 3 << endl;
	}
};

class Truck :public Vehicle {
protected:
	int weight;
public:
	Truck(string no, int weight) : Vehicle(no) {
		this->weight = weight;
	}
	void display() {
		cout << no << " " << weight * 5 << endl;
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		Vehicle* p;
		int type;
		string no;
		int num, weight;
		cin >> type;
		switch (type) {
		case 1: {
			cin >> no >> num >> weight;
			Car obj(no, num, weight);
			p = &obj;
			p->display();
			break;
		}
		case 2: {
			cin >> no >> weight;
			Truck obj(no,weight);
			p = &obj;
			p->display();
			break;
		}
		case 3: {
			cin >> no >> num;
			Bus obj(no, num);
			p = &obj;
			p->display();
			break;
		}
		}
	}
	return 0;
}
