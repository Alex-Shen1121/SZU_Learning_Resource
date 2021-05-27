2018191214:Problem1119:ÕýÈ·
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
class BaseAccount
{
protected:
	char name[20],account[6];
	int balance;
public:
	BaseAccount(){}
	BaseAccount(char na[20],char ac[6],int ba)
	{
		strcpy(name,na);
		strcpy(account,ac);
		balance=ba;
	}
	virtual void deposit(int money)
	{
		if(balance>=money)
			balance=balance-money;
		else
			cout<<"insufficient"<<endl;
	}
	virtual void withdraw(int money)
	{
		balance=money+balance;
	}
	virtual void display()
	{
		cout<<name<<" "<<account<<" "<<"Balance:"<<balance<<endl;
	}
};
class BasePlus:public BaseAccount
{
protected:
	int limit;
	int limit_sum;
public:
	BasePlus(){}
	BasePlus(char na[20],char ac[6],int ba):limit(5000),limit_sum(5000),BaseAccount(na,ac,ba){}
	void deposit(int money)
	{
		if(balance+limit_sum>=money)
			if(balance>=money)
				balance=balance-money;
			else
			{
				money=money-balance;
				balance=balance-balance;
				limit_sum=limit_sum-money;
			}
		else
			cout<<"insufficient"<<endl;
	}
	void withdraw(int money)
	{
		if(limit_sum<5000 &&limit_sum+money<=5000)
			limit_sum=limit_sum+money;
		else if(limit_sum<5000 && limit_sum+money>5000)
		{
			balance=balance+limit_sum+money-5000;
			limit_sum=5000;
		}
		else if(limit>=5000)
			balance+=money;
	}
	void display()
	{
		cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit_sum<<endl;
	}
};
int main()
{
	int t,balance,money;
	char name[20],account[6];
	BaseAccount *BA;
	cin>>t;
	while(t--)
	{
		cin>>name>>account>>balance;
		if(account[1]=='A')
		{
			BA=new BaseAccount(name,account,balance);
			cin>>money;
	        BA->withdraw(money);
			cin>>money;
			BA->deposit(money);
			cin>>money;
			BA->withdraw(money);
			cin>>money;
			BA->deposit(money);
			BA->display();
		}
		else if(account[1]=='P')
		{
			BA=new BasePlus(name,account,balance);
			cin>>money;
	        BA->withdraw(money);
			cin>>money;
			BA->deposit(money);
			cin>>money;
			BA->withdraw(money);
			cin>>money;
			BA->deposit(money);
			BA->display();
		}
	}
	return 0;
}


