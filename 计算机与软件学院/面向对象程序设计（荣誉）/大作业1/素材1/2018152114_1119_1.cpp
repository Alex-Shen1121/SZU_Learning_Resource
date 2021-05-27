2018152114:Problem1119:ÕýÈ·
#include<iostream>
#include<cstring>
using namespace std;
class BaseAccount
{
protected:
	string name;
	string account;
	int balance;
public:
	BaseAccount(string _name,string _account,int _balance):name(_name),account(_account),balance(_balance)
	{
	}
	void deposit(int num)
	{
		balance+=num;
	}
	virtual void withdraw(int num)
	{
		if(num>balance)
			cout<<"insufficient"<<endl;
		else
			balance-=num;
	}
	virtual void display()
	{
		cout<<name<<" "<<account<<" "<<"Balance:"<<balance<<endl;
	}
		virtual ~BaseAccount()
	{
	}
};
class BasePlus:public BaseAccount
{
protected:
	int limit;
	int limit_sum;
public:
	BasePlus(string _name,string _account,int _balance):BaseAccount(_name,_account,_balance)
	{
		limit=5000;
	}
	virtual void withdraw(int num)
	{
		if(num>balance+limit)
			cout<<"insufficient"<<endl;
		else if(balance<=num&&num<=balance+limit)
		{
			limit_sum=num-balance;
			limit-=limit_sum;
			balance=0;
		}
		else if(num<balance)
		{
			balance-=num;
			limit=5000;
		}

	}
	virtual void display()
	{
		cout<<name<<" "<<account<<" "<<"Balance:"<<balance<<" "<<"limit:"<<limit<<endl;
	}
};
int main()
{
	int t;
	cin>>t;
	string _name,_account;
	int _balance;
	int num1,num2,num3,num4;
	BaseAccount* ps;
	while(t--)
	{
		cin>>_name>>_account>>_balance;
		cin>>num1>>num2>>num3>>num4;
		if(_account[1]=='A')
		{
			BaseAccount ba(_name,_account,_balance);
			ps=&ba;
			ps->deposit(num1);
			ps->withdraw(num2);
			ps->deposit(num3);
			ps->withdraw(num4);
			ps->display();
		}
		else if(_account[1]=='P')
		{
			BasePlus bp(_name,_account,_balance);
			ps=&bp;
			ps->deposit(num1);
			ps->withdraw(num2);
			ps->deposit(num3);
			ps->withdraw(num4);
			ps->display();
		}
	}
	return 0;
}

