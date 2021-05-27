2018152044:Problem1119:ÕýÈ·
#include<iostream>
#include<string>
using namespace std;
class BaseAccount
{
protected:
    string name;
    string account;
    double balance;
public:
    BaseAccount(string n,string acc,double bal)
    {
        name=n;
        account=acc;
        balance=bal;
    }
    void deposit(double x)
    {
        balance+=x;
    }
    virtual void withdraw(double x)
    {
        if(balance<x)
        {
            cout<<"insufficient"<<endl;
            return;
        }
        balance-=x;
    }
    virtual void display()
    {
        cout<<name<<" "<<account<<" "<<"Balance:"<<balance<<endl;
    }
};
class BasePlus:public BaseAccount
{
protected:
    double limit;
    double limit_sum;
public:
    BasePlus(string n,string acc,double bal):BaseAccount(n,acc,bal)
    {
        limit=5000;
        limit_sum=0;
    }
    virtual void withdraw(double x)
    {
        if(balance+limit<x)
        {
            cout<<"insufficient"<<endl;
            return;
        }
        if(balance<x)
        {
            limit=limit+balance-x;
            balance=0;
            limit_sum+=5000-limit;
            return;
        }
        balance-=x;
    }
    virtual void display()
    {
        cout<<name<<" "<<account<<" "<<"Balance:"<<balance<<" limit:"<<limit<<endl;
    }
};

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        BaseAccount *s;
        string name;
        string account;
        double balance;
        cin>>name>>account>>balance;
        if(account[1]=='A')
        {
            BaseAccount BA(name,account,balance);
            s=&BA;
            double a,b,c,d;
            cin>>a>>b>>c>>d;
            s->deposit(a);
            s->withdraw(b);
            s->deposit(c);
            s->withdraw(d);
            s->display();
        }
        else if(account[1]=='P')
        {
            BasePlus BP(name,account,balance);
            s=&BP;
            double a,b,c,d;
            cin>>a>>b>>c>>d;
            s->deposit(a);
            s->withdraw(b);
            s->deposit(c);
            s->withdraw(d);
            s->display();
        }
    }
    return 0;
}
