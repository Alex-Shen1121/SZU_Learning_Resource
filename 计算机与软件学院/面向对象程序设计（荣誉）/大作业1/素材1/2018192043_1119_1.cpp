2018192043:Problem1119:ÕýÈ·
#include <iostream>
using namespace std;
class BaseAccount
{
protected:
    string name,account;
    int balance;
public:
    BaseAccount(string ns,string as,int bs):name(ns),account(as),balance(bs){}
    void deposit(int m)
    {
        balance+=m;
    }
    virtual void withdraw(int m)
    {
        if(balance-m<0)
            cout<<"insufficient"<<endl;
        else
            balance-=m;
    }
    virtual void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
    }
    ~BaseAccount(){}
};
class BasePlus:public BaseAccount
{
    int limit;
public:
    BasePlus(string ns,string as,int bs,int ls=5000):BaseAccount(ns,as,bs),limit(ls){}
    void withdraw(int m)
    {
        if(balance+limit-m<0)
            cout<<"insufficient"<<endl;
        else if(balance-m<0)
        {
            limit+=balance-m;
            balance=0;
        }
        else
            balance-=m;
    }
    void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit<<endl;
    }
    ~BasePlus(){}
};
int main()
{
    int t,balance,m;
    string name,account;
    cin>>t;
    while(t--)
    {
        cin>>name>>account>>balance;
        if(account[0]=='B' && account[1]=='A')
        {
            BaseAccount a(name,account,balance);
            cin>>m;
            a.deposit(m);
            cin>>m;
            a.withdraw(m);
            cin>>m;
            a.deposit(m);
            cin>>m;
            a.withdraw(m);
            a.display();
        }
        else
        {
            BasePlus a(name,account,balance);
            cin>>m;
            a.deposit(m);
            cin>>m;
            a.withdraw(m);
            cin>>m;
            a.deposit(m);
            cin>>m;
            a.withdraw(m);
            a.display();
        }
    }
    return 0;
}

