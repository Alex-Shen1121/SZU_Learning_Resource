2017152043:Problem1119:ÕýÈ·
#include<iostream>
#include<cstring>
using namespace std;

class BaseAccount{
protected:
	string name;
	string account;
	int balance;
public:
	BaseAccount(string nam,string acc,int bal):name(nam),account(acc),balance(bal){}
	virtual void deposit(int money)
	{
		balance += money;
	}
	virtual void withdraw(int money)
	{
		if(money <= balance)
			balance -= money;
		else
			cout << "insufficient" << endl;
		
	}
	virtual void display()
	{
		cout << name << " " << account << " Balance:" << balance << endl;
	}
};

class BasePlus:public BaseAccount{
	int limit;
	int limit_sum;
public:
	BasePlus(string nam,string acc,int bal):BaseAccount(nam,acc,bal)
	{
		limit = 5000;
		limit_sum = 0;
	}

	void withdraw(int money)
	{
		if(money <= balance)
			balance -= money;
		else if(money > balance && money <= (limit + balance)){
			limit_sum = money - balance;
			balance = 0;
		}
		else
			cout << "insufficient" << endl;
		limit -= limit_sum;
	}
	void display()
	{
		cout << name << " " << account << " Balance:" << balance << " limit:" << limit << endl;
	}
};


int main(){
	int t;
	BaseAccount *pba;
	string nam;
	char acc[10];
	int bal;
	int in,out;
	cin >> t;
	while(t--){
		cin >> nam >> acc >> bal;
		if(acc[1] == 'A'){
			string str(acc);
			BaseAccount ba(nam,str,bal);
			pba = &ba;
			cin >> in >> out;
			pba->deposit(in);
			pba->withdraw(out);
			cin >> in >> out;
			pba->deposit(in);
			pba->withdraw(out);
			pba->display();
		}
		else if(acc[1] == 'P'){
			string str(acc);
			BasePlus bp(nam,str,bal);
			pba = &bp;
			cin >> in >> out;
			pba->deposit(in);
			pba->withdraw(out);
			cin >> in >> out;
			pba->deposit(in);
			pba->withdraw(out);
			pba->display();
		}
	}
	
	
	return 0;
}

