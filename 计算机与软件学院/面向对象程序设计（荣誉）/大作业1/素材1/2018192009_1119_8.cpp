2018192009:Problem1119:ÕýÈ·
#include <iostream>
#include <cstring>
using namespace std;
class baseAccount
{
protected:
    string name;
    char acc[50];
    int balance;
public:
    baseAccount(){}
    baseAccount(string n,char a[50],int ba):name(n),balance(ba)
    {
        strcpy(acc,a);
    }
    void deposit(int money)
    {
        balance+=money;
    }
    virtual void withdrow(int money)
    {
        if(money>balance)
            cout<<"insufficient"<<endl;
        else
            balance-=money;
    }
    virtual void display()
    {
        cout<<name<<" ";
        cout<<acc;
        cout<<" Balance:"<<balance<<endl;
    }
};
class basePlus:public baseAccount
{
    int limit;
    int limit_sum;
public:
    basePlus(string n,char a[50],int ba):baseAccount(n,a,ba)
    {
        limit=5000;
        limit_sum=0;
    }
    virtual void withdrow(int money)
    {
        if(money>balance+limit)
            cout<<"insufficient"<<endl;
        else
        {
            balance-=money;
            if(balance<0)
            {
                limit_sum=-balance;
                balance=0;
                limit-=limit_sum;
            }
        }
    }
    virtual void display()
    {
        cout<<name<<" ";
        cout<<acc;
        cout<<" Balance:"<<balance<<" limit:"<<limit<<endl;
    }
};
int main()
{
    int t;
    cin>>t;
    string name;
    char acc[50];
    int balance;
    int money;
    baseAccount *p;
    while(t--)
    {
        cin>>name>>acc>>balance;
        if(acc[1]=='A')
        {
            baseAccount a(name,acc,balance);
            p=&a;
            cin>>money;
            p->deposit(money);
            cin>>money;
            p->withdrow(money);
            cin>>money;
            p->deposit(money);
            cin>>money;
            p->withdrow(money);
            p->display();
        }
        else
        {
            basePlus b(name,acc,balance);
            p=&b;
            cin>>money;
            p->deposit(money);
            cin>>money;
            p->withdrow(money);
            cin>>money;
            p->deposit(money);
            cin>>money;
            p->withdrow(money);
            p->display();
        }
    }
    return 0;
}

