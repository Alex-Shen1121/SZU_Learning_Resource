2017182103:Problem1119:ÕýÈ·
#include <iostream>
using namespace std;

class BaseAccount
{
protected:
    string name,account;
    int balance;
public:
    BaseAccount(string n="",string a="",int b=0):name(n),account(a),balance(b) {}
    virtual void deposit(int m)
    {
        balance += m;
    }
    virtual void withdraw(int m)
    {
        if((balance-m)<0)
            cout<<"insufficient"<<endl;
        else
            balance -= m;
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
    BasePlus(string n,string a,int b):BaseAccount(n,a,b),limit_sum(0),limit(5000){}
     virtual void deposit(int m)
    {
        if(limit_sum==0)
             balance += m;
        else if((limit_sum-m)<=0)
        {
            balance = m - limit_sum;
            limit_sum = 0;
            limit = 5000;
        }
        else
        {
            limit_sum = limit_sum - m;
            limit = 5000 - limit_sum;
        }
    }
    virtual void withdraw(int m)
    {
        if((balance+limit-m)<0)
            cout<<"insufficient"<<endl;
        else if((balance-m)<0&&(balance+limit-m)>=0)
        {
            limit_sum = m - balance;
            balance = 0;
            limit = limit - limit_sum;
        }
        else
        {
            balance -= m;
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
        BaseAccount *BA;

        string name,a;
        int b,m1,m2,m3,m4;

        cin>>name>>a>>b;
        cin>>m1>>m2>>m3>>m4;

        if(a[1]=='A')
        {
            BaseAccount ba(name,a,b);
            BA = &ba;
            BA->deposit(m1);
            BA->withdraw(m2);
            BA->deposit(m3);
            BA->withdraw(m4);
            BA->display();
        }
        else
        {
            BasePlus bp(name,a,b);
            BA = &bp;
            BA->deposit(m1);
            BA->withdraw(m2);
            BA->deposit(m3);
            BA->withdraw(m4);
            BA->display();
        }
    }
    return 0;
}

