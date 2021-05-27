2018192008:Problem1119:ÕýÈ·
#include<iostream>

using namespace std;

class BaseAccount
{
protected:

    string name,account;
    int balance;
public:
    BaseAccount(string n,string a,int b):name(n),account(a),balance(b){}
    void deposit(int m)
    {
        balance+=m;
    }
    virtual void withdraw(int m)
    {
        if(balance<m)
            cout<<"insufficient"<<endl;
        else
            balance-=m;
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
    BasePlus(string n,string a,int b):BaseAccount(n,a,b)
    {
        limit=5000;
        limit_sum=0;
    }
    virtual void withdraw(int m)
    {
        if(m>balance+limit)
            cout<<"insufficient"<<endl;
        else
        {
            if(m>balance)
            {
                m=m-balance;
                balance=0;
                limit-=m;
                limit_sum=5000-limit;
            }
            else
            {
                balance-=m;
            }
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
        string n,a;
        int b;
        cin>>n>>a>>b;
        BaseAccount *b1;
        BaseAccount ba(n,a,b);
        BasePlus bp(n,a,b);
        if(a[1]=='A')
        {
            b1=&ba;
            int x1,x2,x3,x4;
            cin>>x1>>x2>>x3>>x4;
            b1->deposit(x1);
            b1->withdraw(x2);
            b1->deposit(x3);
            b1->withdraw(x4);
            b1->display();
        }
        else if(a[1]=='P')
        {
            b1=&bp;
            int x1,x2,x3,x4;
            cin>>x1>>x2>>x3>>x4;
            b1->deposit(x1);
            b1->withdraw(x2);
            b1->deposit(x3);
            b1->withdraw(x4);
            b1->display();
        }
    }
}

