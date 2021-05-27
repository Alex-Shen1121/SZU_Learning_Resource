2018152019:Problem1119:ÕýÈ·
#include <iostream>

#include<string.h>

using namespace std;

class BaseAccount
{
protected:
    string name;
    string account;
    double balance;
public:
    BaseAccount(string n,string a,double b)
    {
        name=n;
        account=a;
        balance=b;
    }
    virtual void deposit(double in)
    {
        balance+=in;
        //cout<<balance<<"--"<endl;
    }
    virtual void withdraw(double out)
    {
        if(out>balance)
            cout<<"insufficient"<<endl;
        else
            balance-=out;
            //cout<<balance<<"**"<<endl;
    }
    virtual void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
    }
};

class BasePlus:public BaseAccount
{
protected:
    double limit=5000;
    double limit_sum=0;
public:
    BasePlus(string n,string a,double b):BaseAccount(n,a,b){}
    virtual void deposit(double in)
    {
        balance+=in;
    }
    virtual void withdraw(double out)
    {
        if(out>balance+limit)
            cout<<"insufficient"<<endl;
        else
        {
            if(balance<out)
            {
                limit=limit-(out-balance);
                balance=0;
                limit_sum=5000-limit;
                //cout<<balance<<"--"<<limit<<"--"<<limit_sum<<endl;
            }
            else
                balance-=out;
        }
    }
    virtual void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit<<endl;
    }
};

int main()
{
    BaseAccount *p;
    int times;
    cin>>times;
    while(times--)
    {
        string n,a;
        double b,in,out;
        cin>>n>>a>>b;
        if(a.find('A',0)==1)
        {
            BaseAccount base(n,a,b);
            p=&base;
            cin>>in>>out;
            p->deposit(in);
            p->withdraw(out);
            cin>>in>>out;
            p->deposit(in);
            p->withdraw(out);
            p->display();
        }
        else
        {
            BasePlus over(n,a,b);
            p=&over;
            cin>>in>>out;
            p->deposit(in);
            p->withdraw(out);
            cin>>in>>out;
            p->deposit(in);
            p->withdraw(out);
            p->display();
        }

    }
    return 0;
}
