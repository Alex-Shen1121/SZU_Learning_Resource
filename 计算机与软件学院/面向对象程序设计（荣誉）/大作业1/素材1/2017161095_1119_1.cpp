2017161095:Problem1119:ÕýÈ·
//#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

class BaseAccount
{
protected:
    string name,account;
    double balance;
public:
    BaseAccount(string n,string a,double b):name(n),account(a),balance(b){}
    void deposit(double x)
    {
        balance+=x;
    }
    virtual void withdraw(double x)
    {
        if(x>balance) cout<<"insufficient"<<endl;
        else balance-=x;
    }
    virtual void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
    }
};

class BasePlus : public BaseAccount
{
protected:
    double limit,limit_sum;
public:
    BasePlus(string n,string a,double b,double l,double ls):BaseAccount(n,a,b),limit(l),limit_sum(ls){}
    virtual void withdraw(double x)
    {
        if(x>balance)
        {
            if(x-balance+limit_sum>limit)  cout<<"insufficient"<<endl;
            else limit_sum+=x-balance,balance=0;
        }
        else
            balance-=x;
    }
    virtual void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit-limit_sum<<endl;
    }

};

int main()
{
    int n,m,t,i,j,k,ans,num,sum,p,w;
    string s,ss;
    double balance,x,y;
    BaseAccount *pp;
    cin>>t;
    while(t--)
    {
         cin>>s>>ss>>balance;
         if(ss[1]=='A')
         {
             BaseAccount q(s,ss,balance);
             cin>>x>>y;
             pp=&q;
             pp->deposit(x);
             pp->withdraw(y);
             cin>>x>>y;
             pp->deposit(x);
             pp->withdraw(y);
             pp->display();
         }
         else
         {
             BasePlus q(s,ss,balance,5000,0);
             cin>>x>>y;
             pp=&q;
             pp->deposit(x);
             pp->withdraw(y);
             cin>>x>>y;
             pp->deposit(x);
             pp->withdraw(y);
             pp->display();
         }
    }
    return 0;
}

