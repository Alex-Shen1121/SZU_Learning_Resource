2018151051:Problem1119:´ð°¸´íÎó
#include<iostream>
#include<cstring>
using namespace std;
class BaseAccount
{
protected:
	char name[10];
	char account[10];
	double balance;
public:
	BaseAccount(){}
	BaseAccount(char n[],char a[],double b)
	{
		strcpy(name,n);
		strcpy(account,a);
		balance=b;	
	}
	virtual void deposit(double money)
	{
		balance=balance+money;
	}
	virtual void withdraw(double money)
	{
		if((balance-money)<0)
			cout<<"insufficient"<<endl;
		else if((balance-money)>=0)
			balance=balance-money;
	}
	virtual void display()
	{
		cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
	}
};
class BasePlus:public BaseAccount
{
	double limit;
	double limit_sum;
public:
	BasePlus(){}
	BasePlus(char n[],char a[],double b)
	{
		strcpy(name,n);
		strcpy(account,a);
		balance=b;
		limit=5000;
		limit_sum=0;
	}
	virtual void deposit(double money)
	{
		if(balance==0)
		{
			if((limit_sum-money)>=0)
				limit_sum=limit_sum-money;
			else
			{
				limit_sum=0;
				balance=balance+(money-limit_sum);
			}
		}
		else if(balance>0)
		{
			balance=balance+money;
		}
	}
	virtual void withdraw(double money)
	{
		double value;
		value=limit-limit_sum+balance;
		if(value-money<0)
			cout<<"insufficient"<<endl;
		else if(value-money>=0)
		{
			if(balance==0)
			{
				limit_sum=limit_sum+money;
			}
			else if(balance>0)
			{
				double s;
				s=money-balance;
				if(s<=0)
					balance=balance-money;
				else if(s>0)
				{
					balance=0;
					limit_sum=limit_sum+s;
				}
			}
		}
	}
	virtual void display()
	{
		cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit-limit_sum<<endl;
	}
};
int main()
{
	int n,i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		char name[10];
		char account[10];
		double balance;
		cin>>name>>account>>balance;
		BaseAccount *p;
		if(account[1]=='A')
		{
			p=new BaseAccount(name,account,balance);
		}
		else if(account[1]=='P')
		{
			p=new BasePlus(name,account,balance);
		}
		for(int j=1;j<=4;j++)
		{
			int money;
			cin>>money;
			if(j%2!=0)
				p->deposit(money);
			else if(j%2==0)
				p->withdraw(money);
		}
		p->display();
		delete []p;
	}
	return 0;
}
