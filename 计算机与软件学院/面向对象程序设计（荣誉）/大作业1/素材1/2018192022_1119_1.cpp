2018192022:Problem1119:ÕýÈ·
#include <iostream>
#include <iomanip>
#include <cstring>
#define PI 3.14
using namespace std;
class BaseAccount
{
protected:
    string name,account;
    double balance;
public:
    BaseAccount(){}
    BaseAccount(string a,string b,double c)
    {
        name=a;
        account=b;
        balance=c;
    }
    virtual void deposit(double x)
    {
        balance+=x;
    }
    virtual void withdraw(double x)
    {
        if(x>balance)
            cout<<"insufficient"<<endl;
        else
        {
            balance-=x;
        }
    }
    virtual void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
    }
};
class BasePlus:public BaseAccount
{
protected:
    double limit,limit_sum;
public:
    BasePlus(){limit=5000;limit_sum=0;}
    BasePlus(string a,string b,double c)
    {
        name=a;
        account=b;
        balance=c;
        limit=5000;
        limit_sum=0;
    }
    void deposit(double x)
    {
        if(limit_sum)
        {
            if(limit_sum > x)
            {
                limit_sum -= x;
                x = 0;
            }
            else
            {
                x -= limit_sum;
                limit_sum = 0;
            }
        }
        balance += x;
    }
    void withdraw(double x)
    {
        if(balance >= x)
        {
            balance -= x;
        }
        else if(balance + limit - limit_sum >= x)
        {
            limit_sum += x - balance;
            balance = 0;
        }
        else
        {
            cout << "insufficient" << endl;
        }
    }
    void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit-limit_sum<<endl;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string name,account;
        double balance;
        cin>>name>>account>>balance;
        if(account[1]=='A')
        {
            BaseAccount p(name,account,balance);
            double a,b,c,d;
            cin>>a>>b>>c>>d;
            p.deposit(a);
            p.withdraw(b);
            p.deposit(c);
            p.withdraw(d);
            p.display();
        }
        else if(account[1]=='P')
        {
            BasePlus p(name,account,balance);
            double a,b,c,d;
            cin>>a>>b>>c>>d;
            p.deposit(a);
            p.withdraw(b);
            p.deposit(c);
            p.withdraw(d);
            p.display();
        }
    }
    return 0;
}
