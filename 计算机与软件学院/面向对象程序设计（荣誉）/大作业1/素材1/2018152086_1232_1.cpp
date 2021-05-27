2018152086:Problem1232:ÕýÈ·
#include<iostream>

using namespace std;

class Vehicle{
	protected:
		string no;
	public:
		virtual void display()=0;
};
class Car:public Vehicle{
	public:
	Car(){
	}
	Car(int a,int b,string c){
		num=a;
		weight=b;
		no=c;
	}
	void display(){
		cout<<no<<" "<<num*8+weight*2<<endl;
	}
	protected:
		int num;
		int weight;
};
class Truck:public Vehicle{
	public:
	Truck(){
	}
	Truck(int a,string b){
		weight=a;
		no=b;
	}
	void display(){
		cout<<no<<" "<<weight*5<<endl;
	}
	protected:
		int weight;
};
class Bus:public Vehicle{
	public:
	Bus(){
	}
	Bus(int a,string b){
		num=a;
		no=b;
	}
	void display(){
		cout<<no<<" "<<num*3<<endl;
	}
	protected:
		int num;
};

int main(){
	int t;
	int a,b;
	int type;
	string c;
	Vehicle *P;
	cin>>t;
	while(t--){
		cin>>type;
		switch(type){
			case 1:{
				cin>>c>>a>>b;
				Car A(a,b,c);
				P=&A;
				P->display();
				break;
			}
			case 2:{
				cin>>c>>a;
				Truck B(a,c);
				P=&B;
				P->display();
				break;
			}
			case 3:{
				cin>>c>>a;
				Bus C(a,c);
				P=&C;
				P->display();
				break;
			}
		}
//		cout<<"_____________"<<endl;
	}
	return 0;
} 

