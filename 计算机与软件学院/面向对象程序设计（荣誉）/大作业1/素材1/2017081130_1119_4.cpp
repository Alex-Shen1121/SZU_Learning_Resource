2017081130:Problem1119:ÕýÈ·
#include <iostream>
using namespace std;
class BaseAccount
{
protected:
    string name;
    string account;
    float balance;
public:
    BaseAccount(){};
    BaseAccount(string n,string a,float b):name(n),account(a),balance(b){};
    void deposit(float num)
    {
        balance+=num;
    }
    virtual void withdraw(float num)
    {
        if(num>balance)
        {
            cout<<"insufficient"<<endl;
        }
        else
        {
            balance-=num;
        }
    }
    virtual void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
    }
};
class BasePlus:public BaseAccount
{
    float limit;
    float limit_sum;
public:
    BasePlus(){};
    BasePlus(string n,string a,float b,float l,float lsum):BaseAccount(n,a,b),limit(l),limit_sum(lsum){};
    void withdraw(float num)
    {
        if(num>balance+(limit-limit_sum))
        {
            cout<<"insufficient"<<endl;
        }
        else if(num<balance)
        {
            balance-=num;
        }
        else
        {
            limit_sum+=(num-balance);
            balance=0;
        }
    }
    void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit-limit_sum<<endl;
    }
};
int main()
{
    int t,i;
    float balance,dnum,wnum,dnum1,wnum1;
    string name,account;
    BaseAccount *a;
    cin>>t;
    while(t--)
    {
        cin>>name>>account>>balance;
        cin>>dnum>>wnum>>dnum1>>wnum1;
        BaseAccount ba(name,account,balance);
        BasePlus bp(name,account,balance,5000,0);
        if(account[1]=='A')
        {
            a=&ba;
            a->deposit(dnum);
            a->withdraw(wnum);
            a->deposit(dnum1);
            a->withdraw(wnum1);
            a->display();
        }
        else
        {
            a=&bp;
            a->deposit(dnum);
            a->withdraw(wnum);
            a->deposit(dnum1);
            a->withdraw(wnum1);
            a->display();
        }
    }
}

