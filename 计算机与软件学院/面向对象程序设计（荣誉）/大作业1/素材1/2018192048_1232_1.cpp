2018192048:Problem1232:ÕýÈ·
#include<iostream>
using namespace std;

class Vehicle{
protected:
	string no;
public:
	Vehicle(){}
	Vehicle(string n):no(n){}
	virtual void display()=0;
	~Vehicle(){}
};

class Car:public Vehicle{
protected:
	int customer;
	int weight;
public:
	Car(){}
	Car(string n,int c,int w):Vehicle(n),customer(c),weight(w){}
	void display(){
		cout<<Vehicle::no<<" "<<customer*8+weight*2<<endl;
	}
	~Car(){}
};

class Truck:public Vehicle{
protected:
	int weight;
public:
	Truck(){}
	Truck(string n,int w):Vehicle(n),weight(w){}
	void display(){
		cout<<Vehicle::no<<" "<<weight*5<<endl;
	}
	~Truck(){}
};

class Bus:public Vehicle{
protected:
	int customer;
public:
	Bus(){}
	Bus(string n,int c):Vehicle(n),customer(c){}
	void display(){
		cout<<Vehicle::no<<" "<<customer*3<<endl;
	}
	~Bus(){}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int type;
		cin>>type;
		string no;
		int customer,weight;
		Vehicle *pv;
		if(type==1){
			cin>>no>>customer>>weight;
			Car a(no,customer,weight);
			pv=&a;
			pv->display();
		}
		else if(type==2){
			cin>>no>>weight;
			Truck a(no,weight);
			pv=&a;
			pv->display();
		}
		else if(type==3){
			cin>>no>>customer;
			Bus a(no,customer);
			pv=&a;
			pv->display();
		}
	}
	return 0;
}
