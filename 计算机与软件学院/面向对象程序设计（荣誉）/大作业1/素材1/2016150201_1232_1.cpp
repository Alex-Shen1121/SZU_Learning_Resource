2016150201:Problem1232:正确
#include<iostream>
using namespace std;
class Vehicle{
protected:
    string no;//编号
public:
	Vehicle(string n):no(n){
	}
    virtual void display()=0;//应收费用
};
class Car:public Vehicle{
	int id;
	int custNum;
	int weight;
public:
	Car(int ids,string n,int cn,int we):id(ids),Vehicle(n),custNum(cn),weight(we){
	}
	void virtual display(){
		cout<<no<<" "<<8*custNum+weight*2<<endl;
	}
}; 
class Truck:public Vehicle{
	int id;
	int weight;
public:	
	Truck(int ids,string n,int we):id(ids),Vehicle(n),weight(we){
	}
	void virtual display(){
		cout<<no<<" "<<weight*5<<endl;
	}
}; 
class Bus:public Vehicle{
	int id;
	int custNum;
public:	
	Bus(int ids,string n,int cn):id(ids),Vehicle(n),custNum(cn){
	}
	void virtual display(){
		cout<<no<<" "<<custNum*3<<endl;
	}
}; 
int main(){
	int t,id,cn,we;
	string no;
	Vehicle *v;
	cin>>t;
	while(t--){
	  cin>>id;
	  if(id==1){
	  	cin>>no>>cn>>we;
	  	Car c(id,no,cn,we);
	  	v=&c;
	  	v->display();}
	  else if(id==2){
	  	cin>>no>>we;
	  	Truck tr(id,no,we);
	  	v=&tr;
	  	v->display();
	  }	
	  else if(id==3){
	  	cin>>no>>cn;
	  	Bus b(id,no,cn);
	  	v=&b;
	  	v->display();
	  }
	}
}
