2018152021:Problem1119:±‡“Î¥ÌŒÛ
#include<iostream>
using namespace std;
class BaseAccount
{
protected:
	string name,account;
	double balance;
public:
	BaseAccount(string n,string a,double b):name(n),account(a),balance(b){}
	double deposit(double x)
	{
		balance+=x;
		return balance;
	}
	double withdraw(double y)
	{
		balance-=y;
		return balance;
	}
	void display()
	{
		cout << name << " " << account << " Balance:" << balance << endl;
	}	
};
class BasePlus:public BaseAccount
{
public:
	double limit_sum;
	BasePlus(string n,string a,double b):name(n),account(a),balance(b){}
	double deposit(double x)
	{
		balance+=x;
		return balance;
	}
	double withdraw(double y)
	{
		balance-=y;
		return balance;
	}
	void display()
	{
		cout<< name << " " << account << " Balance:" << balance << "limit:" << limit_sum << endl;
	}
};
int main()
{
	int t;
	cin >> t;
	string name,account;
	BaseAccount *p;
	double balance,x1,y1,x2,y2;
	while(t--)
	{
		cin >> name >> account >> balance >> x1 >> y1 >> x2 >> y2 ;
		
		p=new BasePlus(name,account,balance);
		
	}	
}
