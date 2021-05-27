2018151066:Problem1119:���д���
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
    virtual void deposit(int n)
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

class BasePlus:virtual public BaseAccount
{
protected:
    int limit,limit_sum;
public:
    BasePlus(string name,string a,int balance):limit(5000),limit_sum(0),BaseAccount(name,a,balance) {};
    void deposit(int n)
    {
        if(balance>0)
            balance+=n;
        else if(n>limit_sum)
        {
            balance+=n-limit_sum;
            limit_sum=0;
        }
        else if(limit_sum>=n)
        {
            limit_sum-=n;
        }
    }
    void withdraw(int n)
    {
        if(n+limit_sum>limit)
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
    void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit-limit_sum<<endl;
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

        if(account[1]=='A')
        {
            pv=new BaseAccount(name,account,balance);
        }
        else
        {
            pv=new BasePlus(name,account,balance);
        }
        pv->deposit(d1);
        pv->withdraw(w1);
        pv->deposit(d2);
        pv->withdraw(w2);
        pv->display();
        delete pv;
    }
}

