2017047011:Problem1129:ÕýÈ·
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip> 
using namespace std;

class Card
{
protected:
	string id;
	string name;
	double balance;
public:
	Card(){}
	int deposit(double num);
	int withdraw(double num);
	virtual void check(){}
};
//------------------------
class ptcard:public Card
{
public:
	ptcard(){}
	ptcard(string i,string n,double b);
	int deposit(double num);
	int withdraw(double num);
	void check();
};

ptcard::ptcard(string i,string n,double b){
	id=i;name=n;balance=b;
}

int ptcard::deposit(double num){
	if(num<=0)
		return -1;
	balance+=num;
	return 1;
}

int ptcard::withdraw(double num){
	if(num<=0)
		return -1;
	if(num>balance)
		return -1;
	balance-=num;
	return 1;
}

void ptcard::check(){
	cout<<id<<"-"<<name<<"-"<<balance<<endl;
}
//------------------------
class tfcard:public ptcard
{
	double tfbalance;
public:
	tfcard(){}
	tfcard(string i,string n,double b,double tfb);
	void check();
	int transfer(double num);
};

tfcard::tfcard(string i,string n,double b,double tfb){
	id=i;name=n;balance=b;tfbalance=tfb;
}

void tfcard::check(){
	cout<<id<<"-"<<name<<"-"<<balance<<"-"<<tfbalance<<endl;
}

int tfcard::transfer(double num){
	if(num<=0)
		return -1;
	if(num>balance)
		return -1;
	balance-=num;
	tfbalance+=num;
	return 1;
}
//------------------------
class vipcard:public ptcard
{
	double limit;
public:
	vipcard(){}
	vipcard(string i,string n,double b,double lm);
	void check();
	int over(double num);
};

vipcard::vipcard(string i,string n,double b,double lm){
	id=i;name=n;balance=b;limit=lm;
}

void vipcard::check(){
	cout<<id<<"-"<<name<<"-"<<balance<<"-"<<limit<<endl;
}

int vipcard::over(double num){
	if(num<=0)
		return -1;
	if(num>balance+limit)
		return -1;
	balance-=num;
	if(balance<0){
		limit=limit+balance;
		balance=0;
	}
	return 1;	
}
//------------------------
void show(Card &obj){
	obj.check();
}
//------------------------
int main()
{
	string id1,id2,id3,name1,name2,name3;
	double b1,b2,b3,tfb,lmb;
	double num;
	int i;
	
	cin>>id1>>name1>>b1;
	cin>>id2>>name2>>b2>>tfb;
	cin>>id3>>name3>>b3>>lmb;
	
	ptcard pt(id1,name1,b1);
	tfcard tf(id2,name2,b2,tfb);
	vipcard vip(id3,name3,b3,lmb);
	
	for(i=0;i<4;i++){
		cin>>num;
		if(i<2)
			pt.deposit(num);
		else 
			pt.withdraw(num);
	} 
	show(pt);
	
	for(i=0;i<4;i++){
		cin>>num;
		if(i==0)
			tf.deposit(num);
		else if(i==1)
			tf.withdraw(num);
		else 
			tf.transfer(num);
	}
	show(tf);
	
	for(i=0;i<4;i++){
		cin>>num;
		if(i==0)
			vip.deposit(num);
		else if(i==1)
			vip.withdraw(num);
		else 
			vip.over(num);
	}
	show(vip);
}
