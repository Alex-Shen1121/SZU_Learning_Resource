2017047011:Problem1119:ÕýÈ·
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip> 
using namespace std;

class baseAccount
{ 
protected:
	string name;
	string no;
	double balance;
public:
	baseAccount(){}
	baseAccount(string name1,string no1,double b);
	void deposit(double num);
	virtual void withdraw(double num);
	virtual void display();
};

baseAccount::baseAccount(string name1,string no1,double b){
	name=name1;no=no1;balance=b;
}

void baseAccount::deposit(double num){
	balance+=num;
}

void baseAccount::withdraw(double num){
	if(num>balance)
		cout<<"insufficient"<<endl;
	else
		balance-=num;
}

void baseAccount::display(){
	cout<<name<<" "<<no<<" Balance:"<<balance<<endl;
}
//------------------------
class Cplus:public baseAccount
{ 
protected:
	double limit;
	double lmtnum;
public:
	Cplus(string name1,string no1,double b);
	void withdraw(double num);
	void display();
};

Cplus::Cplus(string name1,string no1,double b){
	name=name1;no=no1;balance=b;limit=5000;lmtnum=0;
}

void Cplus::withdraw(double num){
	if(num>limit+balance)
		cout<<"insufficient"<<endl;
	else if(num<=balance)
		balance-=num;
	else{
		lmtnum+=(num-balance);
		balance=0;
		limit=5000-lmtnum;
	}
}

void Cplus::display(){
	cout<<name<<" "<<no<<" Balance:"<<balance<<" limit:"<<limit<<endl;	
}
//------------------------
int main()
{
	int t,i;
	string name,no;
	double balance,num;
	
	cin>>t;
	while(t--)
	{
		cin>>name>>no>>balance;
		
		if(no[1]=='A'){
			baseAccount base(name,no,balance);
			for(i=0;i<4;i++){
				cin>>num;
				if(i%2==0)
					base.deposit(num);
				else 
					base.withdraw(num);				
			}
			base.display();
		}
		
		else if(no[1]=='P'){
			Cplus plus1(name,no,balance);
			for(i=0;i<4;i++){
				cin>>num;
				if(i%2==0)
					plus1.deposit(num);
				else 
					plus1.withdraw(num);				
			}
			plus1.display();
		}
		
	}
	
}
