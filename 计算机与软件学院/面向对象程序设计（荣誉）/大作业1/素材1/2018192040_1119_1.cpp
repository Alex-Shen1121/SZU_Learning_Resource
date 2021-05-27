2018192040:Problem1119:´ð°¸´íÎó
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class BaseAccount{ 
protected:
	string name;
	string account;
	int balance;
public:
	BaseAccount(){
	};
	BaseAccount(string n,string a,int b):name(n),account(a),balance(b){
	};
	virtual void display(){
		cout<<name<<" "<<"BA"<<account<<" Balance:"<<balance<<endl;
	}
	void deposit(int num){
		balance += num;
	}
	virtual void withdraw(int num){
		if(balance < num)
			cout<<"insufficient"<<endl;
		else
			balance -= num;
	}
};

class BasePlus:public BaseAccount{
	int limit;
	int limit_sum;
public:
	BasePlus():limit(5000),limit_sum(0){
	};
	BasePlus(string n,string a,int b):limit(5000),BaseAccount(n,a,b){
	};
	void display(){
		cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit<<endl;
	}
	void withdraw(int num){
		if(balance + limit < num)
			cout<<"insufficient"<<endl;
		else if(balance < num){
			int N = num - balance;
			balance = 0;
			limit -= N;
		}
		else{
			balance -= num;
		}
	}
};



int main(){
	int n;
	cin>>n;
	while(n--){
		string name,account;
		int balance;
		cin>>name>>account>>balance;
		if(!account.find("BA")){
			BaseAccount ba(name,account,balance);
			int n1,n2,n3,n4;
			cin>>n1>>n2>>n3>>n4;
			ba.deposit(n1);
			ba.withdraw(n2);
			ba.deposit(n3);
			ba.withdraw(n4);
			ba.display();
		}
		else{
			BasePlus bp(name,account,balance);
			int n1,n2,n3,n4;
			cin>>n1>>n2>>n3>>n4;
			bp.deposit(n1);
			bp.withdraw(n2);
			bp.deposit(n3);
			bp.withdraw(n4);
			bp.display();
		}
	}
}
