2018151066:Problem1232:ÕýÈ·
#include <iostream>
#include<string>
using namespace std;

class Vehicle
{
protected:
	string no;
public:
	Vehicle(string n) :no(n) {}
	virtual void display() = 0;
};
class Car :public Vehicle
{
protected:
	int num, weight;
public:
	Car(int num_, int weight_, string no) :num(num_), weight(weight_), Vehicle(no) {}
	void display()
	{
		cout << no << " " << num * 8 + weight * 2 << endl;
	}
};
class Truck :public Vehicle
{
protected:
	int weight;
public:
	Truck(int weight_, string no) :weight(weight_), Vehicle(no) {}
	void display()
	{
		cout << no << " " << weight * 5 << endl;
	}
};
class Bus :virtual public Vehicle
{
protected:
	int num;
public:
	Bus(int num_, string no) :num(num_), Vehicle(no) {}
	void display()
	{
		cout << no << " " << num * 3 << endl;
	}
};

int main()
{
	int t;
	cin >> t;
	Vehicle *pv;
	while (t--)
	{
		int cmd;
		string no;
		cin >> cmd;
		if (cmd == 1)
		{
			int weight, num;
			cin >> no >> num >> weight;
			pv=new Car (num, weight, no);
		}
		else if (cmd == 2)
		{
			int weight;
			cin >> no >> weight;
			pv =new Truck(weight, no);
		}
		else
		{
			int num;
			cin >> no >> num;
			pv=new Bus(num, no);
		}
		pv->display();
	}
	delete pv;
	return 0;
}
