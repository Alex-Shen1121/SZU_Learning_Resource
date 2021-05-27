2018192013:Problem1119:ÕýÈ·
#include <iostream>
#include <string>
using namespace std;

class BaseAccount
{
protected:
    string name,account;
    int balance;
public:
    BaseAccount(string n,string a,int b):name(n),account(a),balance(b){}
    void deposit(int a){balance+=a;}
    virtual void withdraw(int a)
    {
        if(a>balance)
            cout<<"insufficient"<<endl;
        else
            balance-=a;
    }
    virtual void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
    }
};

class BasePlus:public BaseAccount
{
    int limit,limit_sum;
public:
    BasePlus(string n,string a,int b,int l=5000,int l_s=0):BaseAccount(n,a,b),limit(l),limit_sum(l_s){}
    void withdraw(int a)
    {
        if(a>balance+limit)
            cout<<"insufficient"<<endl;
        else if(a>balance&&a<=balance+limit)
        {
            limit_sum=a-balance;
            limit-=(a-balance);
            balance=0;
        }
        else
            balance-=a;
    }
    void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit<<endl;
    }
};

int main()
{
    int t;
    cin>>t;
    BaseAccount *p;
    while(t--)
    {
        string name,account;
        int balance,a,b,c,d;
        cin>>name>>account>>balance;
        cin>>a>>b>>c>>d;
        string s(account,0,2);
        if(s=="BA")
        {
            BaseAccount ba(name,account,balance);
            p=&ba;
            p->deposit(a);
            p->withdraw(b);
            p->deposit(c);
            p->withdraw(d);
            p->display();
        }
        else if(s=="BP")
        {
            BasePlus bp(name,account,balance);
            p=&bp;
            p->deposit(a);
            p->withdraw(b);
            p->deposit(c);
            p->withdraw(d);
            p->display();
        }
    }
    return 0;
}

