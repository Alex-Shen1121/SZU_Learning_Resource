2018151085:Problem1119:正确
#include<bits/stdc++.h>
using namespace std;

class BaseAccount
{ 
protected:
	string name;
	string account;
	int balance;
public:
	BaseAccount(string Name,string Account,int Balance):name(Name),account(Account),balance(Balance){}
	virtual void deposit(int n)//存款 
	{
		balance=balance+n;
	}
	
	virtual void withdraw(int n)//取款 
	{
		if(n>balance)
			cout<<"insufficient"<<endl;
		else
		{
			balance-=n;
		}
	}
	
	virtual void display()
	{
		cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
	}
	
};

class BasePuls:public BaseAccount
{ 
protected:
	int limit;
	int limit_sum;
public:
	BasePuls(string Name,string Account,int Balance):BaseAccount(Name,Account,Balance),limit(5000),limit_sum(0){}
	virtual void deposit(int n)//存款
	{
		balance=balance+n;
	}
	
	virtual void withdraw(int n)//取款 
	{
		if(n>balance+limit)
			cout<<"insufficient"<<endl;
		else
		{
			balance-=n;
			if(balance<0)
			{
				limit_sum=limit_sum+(-balance);
				balance=0;
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
	int t;
	cin>>t;
	
	BaseAccount *p;
	string name,account;
	int balance,n1,n2,n3,n4;
	while(t--)
	{
		cin>>name>>account;
		
		if(account[1]=='A')
		{
			cin>>balance;
			p=new BaseAccount(name,account,balance);
			cin>>n1>>n2>>n3>>n4;
			p->deposit(n1);
			p->withdraw(n2);
			p->deposit(n3);
			p->withdraw(n4);
			p->display();
			delete p;
		}
		
		else 
		{
			cin>>balance;
			p=new BasePuls(name,account,balance);
			cin>>n1>>n2>>n3>>n4;
			p->deposit(n1);
			p->withdraw(n2);
			p->deposit(n3);
			p->withdraw(n4);
			p->display();
			delete p;
		}
	}
		
}
