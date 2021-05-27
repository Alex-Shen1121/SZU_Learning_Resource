2017161025:Problem1232:ÕýÈ·
#include<iostream>
#include <string>
using namespace std;
class Vehicle
{
protected:
	string NO;
public:
	Vehicle(string n) { NO = n; }
	virtual int fee() = 0;
};

class Car :Vehicle
{
public:
	int guest, weight;

	Car(string no1, int guest1, int weight1) :Vehicle(no1)
	{
		weight = weight1;
		guest = guest1;
	}

	int fee() { return guest * 8 + weight * 2; }
};
class Truck :Vehicle
{
public:
	int weight;

	Truck(string no1, int weight1) :Vehicle(no1), weight(weight1) {}

	int fee() { return weight * 5; }
};
class Bus :Vehicle
{
public:
	int guest;

	Bus(string no1, int guest1) :Vehicle(no1), guest(guest1) {}

	int fee() { return guest * 3; }
};
int main()
{
	Car c("", 0, 0);
	Truck t("", 0);
	Bus b("", 0);
	int i, repeat, ty, weight, guest;
	string no;

	cin >> repeat;

	for (i = 0; i < repeat; i++) 
	{
		cin >> ty >> no;

		switch (ty) 
		{
		case 1: cin >> guest >> weight; c = Car(no, guest, weight); cout << no << ' ' << c.fee() << endl; break;
		case 2: cin >> weight; t = Truck(no, weight); cout << no << ' ' << t.fee() << endl; break;
		case 3: cin >> guest; b = Bus(no, guest); cout << no << ' ' << b.fee() << endl; break;
		}
	}

	return 0;
}
