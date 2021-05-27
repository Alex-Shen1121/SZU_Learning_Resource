2018192040:Problem1232:正确
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class Vehicle{ 
protected:

	string no;//编号

public:
	Vehicle(){
	};
	Vehicle(string n):no(n){
	};
	virtual void display()=0;//应收费用

};

class Car:protected Vehicle{
	int num;
	int height;
public:
	Car(string n,int N,int h):Vehicle(n),num(N),height(h){
	};
	Car(){
	};
	void display(){
		cout<<no<<" "<<num*8+height*2<<endl;
	}
};

class Truck:protected Vehicle{
	int height;
public:
	Truck(string n,int h):Vehicle(n),height(h){
	};
	Truck(){
	};
	void display(){
		cout<<no<<" "<<height*5<<endl;
	}
};

class Bus:protected Vehicle{
	int num;
public:
	Bus(string n,int N):Vehicle(n),num(N){
	};
	Bus(){
	};
	void display(){
		cout<<no<<" "<<num*3<<endl;
	}
};

int main(){
	int n;
	cin>>n;
	while(n--){
		int type;
		cin>>type;
		string no;
		cin>>no;
		if(type == 1){
			int num,height;
			cin>>num>>height;
			Car car(no,num,height);
			car.display();
		}
		if(type == 2){
			int height;
			cin>>height;
			Truck truck(no,height);
			truck.display();
		}
		if(type == 3){
			int num;
			cin>>num;
			Bus bus(no,num);
			bus.display();
		}
	}
}
