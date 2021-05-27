2018151020:Problem1119:ÕýÈ·
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;
class BaseAccount
{
protected:
    string name,account;
    double balance;
public:
    BaseAccount(string na,string ac,double ba):name(na),account(ac),balance(ba){}
    void deposit(double money)
    {
        balance+=money;
    }
    virtual void withdraw(double takeout)
    {
        if(takeout>balance)
        {
            cout<<"insufficient"<<endl;
            return;
        }
        else
        {
            balance-=takeout;
        }
    }
    virtual void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
    }
};
class Baseplus:public BaseAccount
{
protected:
    double limit,limit_sum;
public:
    Baseplus(string na,string ac,double ba):BaseAccount(na,ac,ba)
    {
        limit = 5000;
        limit_sum = 0;
    }
    void withdraw(double takeout)
    {
        if(takeout>(limit-limit_sum)+balance)
        {
            cout<<"insufficient"<<endl;
            return;
        }
        else
        {
            if(takeout>balance)
            {
                takeout-=balance;
                balance = 0;
                limit_sum+=takeout;
            }
            else
            {
                balance-=takeout;
            }
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
    string na,ac;
    double money,m1,t1,m2,t2;
    while(t--)
    {
        BaseAccount *K;
        cin>>na>>ac>>money
            >>m1>>t1>>m2>>t2;
        if(ac[1]=='A')
        {
            BaseAccount *BA = new BaseAccount(na,ac,money);
            K = BA;
        }
        else if(ac[1]=='P')
        {
            Baseplus *BP = new Baseplus(na,ac,money);
            K = BP;
        }
        K->deposit(m1);
        K->withdraw(t1);
        K->deposit(m2);
        K->withdraw(t2);
        K->display();
    }

    return 0;
}

