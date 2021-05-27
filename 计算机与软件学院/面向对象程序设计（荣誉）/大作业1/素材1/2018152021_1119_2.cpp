2018152021:Problem1119:±‡“Î¥ÌŒÛ
#include<iostream>
using namespace std;
class BaseAccount
{
protected:
    string name;
	char account[20];
    double balance;
public:
    BaseAccount(string n,char a[20],double b):name(n),account(a),balance(b){}
    void deposit(double x)
    {
        balance+=x;
    }
    void withdraw(double y)
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
    BasePlus(string n,char a,double b):BaseAccount(n,a,b){}
    double deposit(double x)
    {
        balance+=x;
        return balance;
    }
    void withdraw(double y)
    {
        balance-=y;
        if(balance<-5000)
        {
        	cout << "insufficient" << endl;
        	balance+=y;
		}
		if(balance<0)
			limit_sum=-1*balance;
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
    string name;
    char account[20];
    BaseAccount *p;
    double balance,x1,y1,x2,y2;
    while(t--)
    {
        cin >> name >> account >> balance >> x1 >> y1 >> x2 >> y2 ;
    	if(account[1]=='A')
    	{
    		p->BaseAccount(name,aczcount,balance);
    		p->deposit(x1);
    		p->withdraw(y1);
    		p->deposit(x2);
    		p->withdraw(y2);
    		p->display();
		}
         
    }   
}
