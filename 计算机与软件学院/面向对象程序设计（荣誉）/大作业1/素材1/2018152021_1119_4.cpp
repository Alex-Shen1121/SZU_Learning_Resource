2018152021:Problem1119:ÕýÈ·
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class BaseAccount
{
protected:
    string name;
	string account;
    double balance;
public:
    BaseAccount(string n,string a,double b):name(n),account(a),balance(b){}
    virtual void deposit(double x)
    {
        balance+=x;
    }
    virtual void withdraw(double y)
    {
        balance-=y;
        if(balance<0)
        {
        	cout << "insufficient" << endl;
        	balance+=y;
		}
    }
	virtual void display()
    {
        cout << name << " " << account << " Balance:" << balance << endl;
    }   
};
class BasePlus:public BaseAccount
{
public:
    double limit_sum;
    BasePlus(string n,string a,double b):BaseAccount(n,a,b){}
    void deposit(double x)
    {
        balance+=x;
    }
    void withdraw(double y)
    {
        balance-=y;
        if(balance<-5000)
        {
        	cout << "insufficient" << endl;
        	balance+=y;
        	limit_sum=5000;
		}
		else if(balance>=-5000&&balance<0)
        {
        	limit_sum=5000+1*balance;
		}
	}
    void display()
    {
    	if(balance<0)
    		balance=0;
        cout<< name << " " << account << " Balance:" << balance << " " << "limit:" << limit_sum << endl;
    }
};
int main()
{
    int t;
    cin >> t;
    string name,account;
    double balance,x1,y1,x2,y2;
    while(t--)
    {
    	BaseAccount *p;
    	char a[20];
        cin >> name >> account >> balance >> x1 >> y1 >> x2 >> y2 ;
        strcpy(a,account.c_str());
		if(a[1]=='A')
    	{
    		p=new BaseAccount(name,account,balance);
    		p->deposit(x1);
    		p->withdraw(y1);
    		p->deposit(x2);
    		p->withdraw(y2);
    		p->display();
		}
		else if(a[1]=='P')
		{
			p=new BasePlus(name,account,balance);
			p->deposit(x1);
    		p->withdraw(y1);
    		p->deposit(x2);
    		p->withdraw(y2);
    		p->display();
		}
         
    }   
}
