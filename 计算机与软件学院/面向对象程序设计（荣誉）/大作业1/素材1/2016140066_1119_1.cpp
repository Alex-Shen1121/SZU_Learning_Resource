2016140066:Problem1119:´ð°¸´íÎó
#include <iostream>
#include<string>
using namespace std;
class BaseAccount
{
protected:
    string account,name;
    int balance;
public:
    BaseAccount(){}
    BaseAccount(string N,string A,int B):name(N),account(A),balance(B){}
    void deposit(int money)
    {
        balance=balance+money;
    }
    virtual void withdraw(int money)
    {
        if(balance<money)
        {
            cout<<"insufficient"<<endl;
        }
        else
        {
            balance=balance-money;
        }
    }
    virtual void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
    }
};
class BasePlus:public BaseAccount
{
    int limit,limit_num;
public:
    BasePlus(){}
    BasePlus(string N,string A,int B):BaseAccount(N,A,B){limit=5000;limit_num=0;}
    virtual void withdraw(int money)
    {
        if((balance+limit)<money)
        {
            cout<<"insufficient2"<<endl;
        }
        else
        {
            if(balance<money)
            {
                limit_num=limit_num+(money-balance);
                balance=0;
                limit=5000-limit_num;
            }
            else
            {
                balance=balance-money;
            }
        }
    }
    virtual void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit<<endl;
    }
};
void diaoyong(BaseAccount *p,int d1,int w1,int d2,int w2)
{
    p->deposit(d1);
    p->withdraw(w1);
    p->deposit(d2);
    p->withdraw(w2);
    p->display();
}
int main()
{
    int t,B,d1,w1,d2,w2;
    string N,A;
    cin>>t;
    while(t--)
    {
        cin>>N>>A>>B>>d1>>w1>>d2>>w2;
        if(A[1]=='A')
        {
            BaseAccount *s=new BaseAccount(N,A,B);
            diaoyong(s,d1,w1,d2,w2);
            delete s;
        }
        else
        {
            BasePlus *s=new BasePlus(N,A,B);
            diaoyong(s,d1,w1,d2,w2);
            delete s;
        }

    }
    return 0;
}
