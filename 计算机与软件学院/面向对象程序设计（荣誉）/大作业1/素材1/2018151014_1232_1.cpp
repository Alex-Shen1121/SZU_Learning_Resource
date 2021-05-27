2018151014:Problem1232:ÕýÈ·
#include <iostream>

using namespace std;

class Vehicle {
public:
	Vehicle(string n) : no(n) {
		
	}
	virtual void display() = 0;
protected:
	string no;
};

class Car : public Vehicle {
public:
	Car(string n, int s, float w) : Vehicle(n), seats(s), weight(w) {
		
	}
	
	void display() {
		cout << no << ' ' << 8*seats + 2*weight << endl;
	}
private:
	int seats;
	float weight;
};

class Truck : public Vehicle {
public:
	Truck(string n, float w) : Vehicle(n), weight(w) {
		
	}
	
	void display() {
		cout << no << ' ' << 5*weight << endl;
	}
private:
	float weight;
};

class Bus : public Vehicle {
public:
	Bus(string n, int s) : Vehicle(n), seats(s) {
		
	}
	
	void display() {
		cout << no << ' ' << 3*seats << endl;
	}
private:
	int seats;
};

int main(void) {
	
	int t;
	cin >> t;
	while (t--) {
		int x;
		int seats;
		float weight;
		string no;
		Vehicle *ptr;
		
		cin >> x;
		if (x == 1) {
			cin >> no >> seats >> weight;
			ptr = new Car(no, seats, weight);
			ptr->display();
		}
		else if (x == 2) {
			cin >> no >> weight;
			ptr = new Truck(no, weight);
			ptr->display();
		}
		
		else if (x == 3) {
			cin >> no >> seats;
			ptr = new Bus(no, seats);
			ptr->display();
		}
		
		delete ptr;
	}
	
	return 0;
}
