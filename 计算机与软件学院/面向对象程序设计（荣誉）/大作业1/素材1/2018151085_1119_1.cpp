2018151085:Problem1119:答案错误
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
	virtual int deposit(int num1,int num2)//存款 
	{
		return balance=balance+num1+num2;
	}
	
	virtual int withdraw(int num3,int num4)//取款 
	{
		return balance=balance-num3-num4;
	}
	
	virtual void display()
	{
		if(balance<0)
			cout<<"insufficient"<<endl;
		else
			cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
	}
	
};

class BasePuls:public BaseAccount
{ 
protected:
	int limit;
	int limit_sum;
public:
	BasePuls(string Name,string Account,int Balance):BaseAccount(Name,Account,Balance),limit(5000){}
	virtual int deposit(int num1,int num2)//存款
	{
		return balance=balance+num1+num2;
	}
	
	virtual int withdraw(int num3,int num4)//取款 
	{
		balance=balance-num3-num4;
		if(balance>-5000)
			return balance=0;
	}
	
	
	virtual void display()
	{
		limit_sum=balance+limit;
		if(limit_sum<0)
			cout<<"insufficient"<<endl;
		else
			cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit<<endl;
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
			p->deposit(n1,n3);
			p->withdraw(n2,n4);
			p->display();
			delete p;
		}
		
		else 
		{
			cin>>balance;
			p=new BasePuls(name,account,balance);
			cin>>n1>>n2>>n3>>n4;
			p->deposit(n1,n3);
			p->withdraw(n2,n4);
			p->display();
			delete p;
		}
	}
		
}
