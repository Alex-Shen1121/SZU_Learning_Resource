2018182052:Problem1119:´ð°¸´íÎó
#include <iostream>
#include<cstdio>
#include<cstring>
#include <string>
#include<iomanip>
#define ADDRESS "C:\\Users\\241\\Desktop\\in.txt","r",stdin
using namespace std;
class BaseAccount
{
protected:
    string name;
    string account;
    double balance;
public:
    BaseAccount(const string& n,const string &a,double b):name(n),account(a),balance(b) {}
    void deposit(double amo)
    {
        balance+=amo;
    }
    virtual bool withdraw(double amo)
    {
        if(amo>=balance)
        {
            cout<<"insufficient"<<endl;
            return false;
        }
        balance-=amo;
        return true;
    }
    virtual void display()const
    {
        cout<<name<<" "<<account<<fixed<<setprecision(0)<<" Balance:"<<balance<<endl;
    }
};
class BasePlus:public BaseAccount
{
protected:
    double limit;
    double limit_sum;
public:
    BasePlus(const string& n,const string &a,double b):BaseAccount(n,a,b),limit(5000.00),limit_sum(0.0) {}
    virtual bool withdraw(double amo)
    {
        if(amo<=balance)
        {
            balance-=amo;
            return true;
        }
        else if(amo>balance&&amo<=balance+limit-limit_sum)
        {
            amo-=balance;
            balance=0.0;
            limit_sum+=amo;
            return true;
        }
        else
        {
            cout<<"insufficient"<<endl;
            return false;
        }
    }
    virtual void display()const
    {
        cout<<name<<" "<<account<<fixed<<setprecision(0)<<" Balance:"<<balance<<" limit:"<<(limit-limit_sum)<<endl;
    }
};
int main()
{
 //   freopen(ADDRESS);
    int T(0);
    cin>>T;
    BaseAccount *p;
    string name,acc;
    int d[5];
    while(T--)
    {
        cin>>name>>acc>>d[4]>>d[0]>>d[1]>>d[2]>>d[3];
        if(acc[1]=='A')
        {
            p=new BaseAccount(name,acc,d[4]);
        }
        else if(acc[1]='P')
        {
            p=new BasePlus(name,acc,d[4]);
        }
        p->deposit(d[0]);
        p->withdraw(d[1]);
        p->deposit(d[2]);
        p->withdraw(d[3]);
        p->display();
        delete p;
    }
    return 0;
}
