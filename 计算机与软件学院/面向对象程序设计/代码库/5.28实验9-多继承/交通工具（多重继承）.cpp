#include<iostream>
using namespace std;

class CVehicle {
protected:
	int max_speed, speed, weight;
public:
	CVehicle(int max_speed, int speed, int weight) {
		this->max_speed = max_speed;
		this->speed = speed;
		this->weight = weight;
	}
	void display() {
		cout << "Vehicle:" << endl;
		cout << "max_speed:" << max_speed << endl;
		cout << "speed:" << speed << endl;
		cout << "weight:" << weight << endl;
	}
};

class CBicycle :virtual public CVehicle {
protected:
	int height;
public:
	CBicycle(int max_speed, int speed, int weight, int height) :CVehicle(max_speed, speed, weight) {
		this->height = height;
	}
	void display() {
		cout << "Bicycle:" << endl;
		cout << "max_speed:" << max_speed << endl;
		cout << "speed:" << speed << endl;
		cout << "weight:" << weight << endl;
		cout << "height:" << height << endl;
	}
};

class CMotocar :virtual public CVehicle {
protected:
	int seat_num;
public:
	CMotocar(int max_speed, int speed, int weight, int seat_num) :CVehicle(max_speed, speed, weight) {
		this->seat_num = seat_num;
	}
	void display() {
		cout << "Motocar:" << endl;
		cout << "max_speed:" << max_speed << endl;
		cout << "speed:" << speed << endl;
		cout << "weight:" << weight << endl;
		cout << "seat_num:" << seat_num << endl;
	}
};

class CMotocycle :public CBicycle, public CMotocar {
public:
	CMotocycle(int max_speed, int speed, int weight, int height, int seat_num) :CVehicle(max_speed, speed, weight), CBicycle(max_speed, speed, weight, height), CMotocar(max_speed, speed, weight, seat_num) {};
	void display() {
		cout << "Motocycle:" << endl;
		cout << "max_speed:" << max_speed << endl;
		cout << "speed:" << speed << endl;
		cout << "weight:" << weight << endl;
		cout << "height:" << height << endl;
		cout << "seat_num:" << seat_num << endl;
	}

};

int main() {
	int max_speed, speed, weight, height, seat_num;
	cin >> max_speed >> speed >> weight >> height >> seat_num;
	CMotocycle C(max_speed, speed, weight, height, seat_num);
	C.CVehicle::display();
	cout << endl;
	C.CBicycle::display();
	cout << endl; 
	C.CMotocar::display(); 
	cout << endl;
	C.CMotocycle::display();
	return 0;
}
