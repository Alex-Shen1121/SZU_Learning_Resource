2017163101:Problem1232:正确
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
class Vehicle
{ 
protected:
	string no;//编号
public:
	virtual void display()=0;//应收费用
	Vehicle(string n):no(n){
		
	}
};
class Car:public Vehicle{
	private:
		int num,weight;
	public:
		Car(string no,int n,int weight):Vehicle(no),num(n),weight(weight){
		}
	void display(){
		float money=num*8+weight*2;
		cout<<no<<" "<<money<<endl;
	}
};
class Truck:public Vehicle{
	private:
		int weight;
	public:
		Truck(string n,int weight):Vehicle(n),weight(weight){
			
		}
		
	void display(){
		float money=weight*5;
		cout<<no<<" "<<money<<endl;
	}
};
class Bus:public Vehicle{
	private:
		int num;
	public:
		Bus(string n,int num):Vehicle(n),num(num){
		}
	void display(){
		float money=num*3;
		cout<<no<<" "<<money<<endl;
	}
};
int main(){
	int t;
	cin>>t;
	
	while(t--){
		int flag,num,weight;
		string no;
		cin>>flag;
		Vehicle *pv;
		if(flag==1){
			cin>>no>>num>>weight;
			pv=new Car(no,num,weight);
			pv->display();
		}
		else if(flag==2){
			cin>>no>>weight;
			pv=new Truck(no,weight);
			pv->display();
		}
		else {
			cin>>no>>num;
			pv=new Bus(no,num);
			pv->display();
		}
		delete pv;
	}
	return 0;
}
