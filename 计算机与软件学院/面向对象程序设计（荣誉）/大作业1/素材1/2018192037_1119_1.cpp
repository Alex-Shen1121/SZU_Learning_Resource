2018192037:Problem1119:ÕýÈ·
#include<bits/stdc++.h>
using namespace std;

class BaseAccount
{
protected:
    string name;
    string account;
    int  balance;
public:
    BaseAccount(){}
    BaseAccount(string n,string ac,int b)
    {
        name = n;
        account = ac;
        balance = b;
    }
    virtual void deposit(int mon)
    {
        balance += mon;
    }
    virtual void withdraw(int mon)
    {
        if(balance-mon>=0)
            balance -= mon;
        else
            cout<<"insufficient"<<endl;
    }
    virtual void display()
    {
        cout<<name<<" "<<account<<" Balance:"
        <<balance<<endl;
    }
};

class BasePlus:public BaseAccount
{
protected:
    int limit;
    int limit_sum;
public:
    BasePlus(){}
    BasePlus(string n,string ac,int b)
    {
        name = n;
        account = ac;
        balance = b;
        limit = 5000;
        limit_sum = 0;
    }
    void deposit(int mon)
    {
        balance += mon;
    }
    void withdraw(int mon)
    {
        if(balance+limit-mon>=0)
        {
            balance -= mon;
            if(balance <0)
            {
                limit_sum += balance ;
                limit += balance;
                balance = 0;
            }
        }

        else
            cout<<"insufficient"<<endl;
    }
    void display()
    {
        cout<<name<<" "<<account<<" Balance:"
        <<balance<<" limit:"<<limit
        <<endl;
    }
};


int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        BaseAccount *p;
        string name,acc;
        int ba;
        cin>>name>>acc>>ba;
        if(acc[1]=='A')
        {
            int money;
            BaseAccount b(name,acc,ba);
            cin>>money;
            b.deposit(money);
            cin>>money;
            b.withdraw(money);
            cin>>money;
            b.deposit(money);
            cin>>money;
            b.withdraw(money);
            p = &b;
            p->display();
        }
        else
        {
            int money;
            BasePlus b(name,acc,ba);
            cin>>money;
            b.deposit(money);
            cin>>money;
            b.withdraw(money);
            cin>>money;
            b.deposit(money);
            cin>>money;
            b.withdraw(money);
            p = &b;
            p->display();
        }
    }
}

