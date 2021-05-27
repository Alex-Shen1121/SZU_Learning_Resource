2018151058:Problem1119:ÕýÈ·
#include <iostream>
using namespace std;
class BaseAccount
{
protected:
    string name;
    string num;
    int balance;
public:
    BaseAccount() {};
    BaseAccount(string n,string n1,int b)
    {
        name=n;
        num=n1;
        balance=b;
    }
    virtual void desposit(int n)
    {
        balance+=n;
    }
    virtual bool withdraw(int n)
    {
        if(n>balance)
        {
             cout<<"insufficient"<<endl;
             return 0;
        }

        else
            balance-=n;
            return 1;
    }
    virtual void display()
    {
        cout<<name<<" "<<num<<" Balance:"<<balance<<endl;
    }

};
class BasePlus:public BaseAccount
{
protected:
    int limit,limit_sum;
public:
    BasePlus() {};
    BasePlus(string n,string n1,int b):BaseAccount(n,n1,b)
    {
        limit=5000;
        limit_sum=0;
    }
    int getlimit(){return limit;}
    virtual void desposit(int n)
    {
        if(limit_sum==0)
        {
            balance+=n;
        }
        if(limit_sum>0&&balance==0)
        {
            limit_sum-=n;
            limit+=n;
            if(limit_sum<0)
            {
                balance=0-limit_sum;
                limit_sum=0;
                limit=5000;
            }

        }


    }
        virtual bool withdraw(int n)
        {
            if(n>balance+limit)
            {
                cout<<"insufficient"<<endl;
                return 0;
            }

            else
            {
                if(balance>=n)
                {
                    balance-=n;
                    return 1;
                }
                else if(balance<n)
                {
                    limit_sum+=n-balance;
                    balance=0;
                    limit-=limit_sum;
                    return 1;
                }
            }
            return 1;
        }
        virtual void display()
        {
            cout<<name<<" "<<num<<" Balance:"<<balance<<" limit:"<<limit<<endl;
        }

    };


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        BaseAccount *p;
        string name;
        string num;
        int balance;
        int a,b,c,d;
        cin>>name>>num;
        if(num.find('P',0)==1)
        {
            cin>>balance;
            BasePlus a1(name,num,balance);
            p=&a1;
            cin>>a>>b>>c>>d;
            p->desposit(a);
            p->withdraw(b);
            p->desposit(c);
            p->withdraw(d);
            p->display();
        }
        else
        {
            cin>>balance;
            BaseAccount b1(name,num,balance);
            cin>>a>>b>>c>>d;
            p=&b1;
            p->desposit(a);
            p->withdraw(b);
            p->desposit(c);
            p->withdraw(d);
            p->display();
        }


    }
    return 0;
}

