2018152087:Problem1119:ÕýÈ·
#include<iostream>
#include<string.h>
using namespace std;
class BaseAccount
{
protected:
	char name[100];
	char account[100];
	int balance;
public:
	BaseAccount()
	{
		
	 } 
	BaseAccount(char n[],char a[],int b)
	{
		strcpy(name,n);
		strcpy(account,a);
		balance=b;
	}
	virtual void deposit(int num)
	{
		balance+=num;
	}
	virtual void withdraw(int num)
	{
		if(balance<num)
			cout<<"insufficient"<<endl;
		else
			balance-=num;
	}
	virtual void display()
	{
		cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
	}
};
class BasePlus:public BaseAccount
{
	int limit;
	int limit_sum;
public:
	BasePlus(char n[],char a[],int b)
	{
		strcpy(name,n);
		strcpy(account,a);
		balance=b;
		limit=5000;
		limit_sum=0;
	}
	virtual void deposit(int num)
	{
		balance+=num;
	}
	virtual void withdraw(int num)
	{
		if(balance+limit<num)
			cout<<"insufficient"<<endl;
		else 
		{
			if(balance>=num)
				balance-=num;
			else 
			{
				limit=limit+balance-num;
				balance=0;
				limit_sum=5000-limit;
			}
		}
	
	}
	virtual void display()
	{
		cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit<<endl;
	}
};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char name[100];
		char account[100];
		cin>>name>>account;
		int balance;
		cin>>balance;
		BaseAccount *p;
		if(account[1]=='A')
		{
			BaseAccount ex(name,account,balance);
			p=&ex;
		}
		else
		{
			BasePlus ex(name,account,balance);
			p=&ex; 
		}
		int num1;
		cin>>num1;
		p->deposit(num1);
		int num2;
		cin>>num2;
		p->withdraw(num2);
		int num3;
		cin>>num3;
		p->deposit(num3);
		int num4;
		cin>>num4;
		p->withdraw(num4);
		p->display();
	}
}
