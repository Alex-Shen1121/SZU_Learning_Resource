2018151066:Problem1119:ÔËÐÐ´íÎó
#include<iostream>
#include<string>
using namespace std;
class  BaseAccount
{
protected:
    string name,account;
    int balance;
public:
    BaseAccount();
    BaseAccount(string n,string a,int b):name(n),account(a),balance(b) {}
    void deposit(int n)
    {
        balance+=n;
    }
    virtual void withdraw(int n)
    {
        if(n>balance)
            cout<<"insufficient"<<endl;
        else
            balance-=n;
    }
    virtual void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
    }
};

class BasePlus:public BaseAccount
{
protected:
    int limit,limit_sum;
public:
    BasePlus(string name,string a,int balance):limit(5000),limit_sum(0),BaseAccount(name,a,balance) {};
    void withdraw(int n)
    {
        if(limit_sum>limit)
            cout<<"insufficient"<<endl;
        else if(n>balance)
        {
            limit_sum=n-balance;
            balance=0;
        }
        else if(n<=balance)
        {
            balance-=n;
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
        BaseAccount *pv;
        string name,account;
        int balance;
        cin>>name>>account>>balance;
        int d1,w1,d2,w2;
        cin>>d1>>w1>>d2>>w2;
        if(account[2]=='A')
        {
            BaseAccount ba(name,account,balance);
            pv=&ba;
        }
        else
        {
            BasePlus bp(name,account,balance);
            pv=&bp;
        }
        pv->deposit(d1);
        pv->withdraw(w1);
        pv->deposit(d2);
        pv->withdraw(w2);
        pv->display();
        delete pv;
    }
}

