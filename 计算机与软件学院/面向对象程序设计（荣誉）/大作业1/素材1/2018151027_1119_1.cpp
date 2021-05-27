2018151027:Problem1119:±‡“Î¥ÌŒÛ
v#include <iostream>
#include<cstring>
using namespace std;
class BaseAccount
{
protected:
    string name;
    char account[10];
    int balance;
public:
    BaseAccount(string n,char *a,int b):name(n),balance(b)
    {
        strcpy(account,a);
    }
    void deposit(int g)
    {
        balance+=g;
    }
    virtual void withdraw(int g)
    {
        if(g>balance)
            cout<<"insufficient"<<endl;
        else
            balance-=g;
    }
    virtual void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
    }
};
class BasePlus: public BaseAccount
{
protected:
    int limit;
    int limit_sum;
public:
    BasePlus(string n,char *a,int b):BaseAccount(n,a,b),limit(5000),limit_sum(0){}
    void withdraw(int g)
    {
        if(g>limit-limit_sum+balance)
            cout<<"insufficient"<<endl;
        else if(g>balance)
        {
            g-=balance;
            balance=0;
            limit_sum+=g;
        }
        else
            balance-=g;
    }
    void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit-limit_sum<<endl;
    }
};

main()
{
   string name;
    char account[10];
    int balance;
    int gold;
    int t;
    BaseAccount *p;
    cin>>t;
    while(t--)
    {
        cin>>name>>account>>balance;
        if(account[1]=='A')
        {
            p=new BaseAccount(name,account,balance);
            cin>>gold;
            p->deposit(gold);
            cin>>gold;
            p->withdraw(gold);
            cin>>gold;
            p->deposit(gold);
            cin>>gold;
            p->withdraw(gold);
            p->display();
        }
        else
        {
            p=new BasePlus(name,account,balance);
            cin>>gold;
            p->deposit(gold);
            cin>>gold;
            p->withdraw(gold);
            cin>>gold;
            p->deposit(gold);
            cin>>gold;
            p->withdraw(gold);
            p->display();
        }

    }

}

