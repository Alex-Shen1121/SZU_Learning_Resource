2017152043:Problem1232:正确
#include<iostream>
using namespace std;

class Vehicle{
protected:
	string no;//编号
public:
	Vehicle(){}
	virtual void display()=0;//应收费用
	void getNo(string num)
	{
		no = num;
	}
};

class Car:public Vehicle{
	int people;
	int weight;
public:
	Car(){}
	void display()
	{
		cout << no << " " << (people * 8 + weight * 2) << endl;
	}
	void getPW(int p,int w)
	{
		people = p;
		weight = w;
	}
};

class Truck:public Vehicle{
	int weight;
public:
	Truck(){}
	void display()
	{
		cout << no << " " << weight * 5 << endl;
	}
	void getW(int w)
	{
		weight = w;
	}
};

class Bus:public Vehicle{
	int people;
public:
	Bus(){}
	void display()
	{
		cout << no << " " << people * 3 << endl;
	}
	void getP(int p)
	{
		people = p;
	}
};


int main(){
	int t;
	cin >> t;
	Car car;
	Truck truck;
	Bus bus;
	Vehicle *pv;
	int type,p,w;
	string num;
	while(t--){	
		cin >> type >> num;
		if(type == 1){
			cin >> p >> w;
			car.getNo(num);
			car.getPW(p,w);
			pv = &car;
			pv->display();
		}
		else if(type == 2){
			cin >> w;
			truck.getNo(num);
			truck.getW(w);
			pv = &truck;
			pv->display();
		}
		else if(type == 3){
			cin >> p;
			bus.getNo(num);
			bus.getP(p);
			pv = &bus;
			pv->display();
		}
	}
	return 0;
}

