2018152035:Problem1119:ÕýÈ·
#include <iostream>
#include<stdio.h>
#include<string>
using namespace std;
class BaseAccount
{
protected:
    string name,idnumber;
    int balance;
public:
    BaseAccount(string n,string i,int b):name(n),idnumber(i),balance(b) {}
    virtual void deposit(int m)
    {
        balance+=m;
    }
    virtual void withdraw(int m)
    {
        if(balance-m>=0)
            balance-=m;
        else
            cout<<"insufficient"<<endl;
    }
    virtual void display()
    {
        cout<<name<<' '<<idnumber<<" Balance:"<<balance<<endl;
    }
};
class BasePlus:public BaseAccount
{
    int limit,limit_sum;
public:
    BasePlus(string n,string i,int b):BaseAccount(n,i,b),limit(5000),limit_sum(0) {}
    void withdraw(int m)
    {
        int n=balance-m;
        if(n>=0)
            balance-=m;
        else
        {
            if(n+limit>=0)
            {
                balance=0;
                limit+=n;
                limit_sum-=n;
            }
            else
            {
                cout<<"insufficient"<<endl;
            }
        }
    }
    void display()
    {
        cout<<name<<' '<<idnumber<<" Balance:"<<balance<<" limit:"<<limit<<endl;
    }
};
int main()
{
    //freopen("C:\\Users\\241\\Desktop\\1.txt","r",stdin);
    int T,a,t;
    string n,type;
    cin>>T;
    while(T--)
    {
        t=2;
        BaseAccount *p;
        cin>>n>>type;
        if(type[0]=='B'&&type[1]=='A')
        {
            cin>>a;
            BaseAccount aa(n,type,a);
            p=&aa;
            while(t--)
            {
                cin>>a;
                p->deposit(a);
                cin>>a;
                p->withdraw(a);
            }
            p->display();
        }
        else
        {
            cin>>a;
            BasePlus aa(n,type,a);
            p=&aa;
            while(t--)
            {
                cin>>a;
                p->deposit(a);
                cin>>a;
                p->withdraw(a);
            }
            p->display();
        }
    }
}

