2018192025:Problem1119:ÕýÈ·
#include<iostream>
#include<cstring>
using namespace std;
class BaseAccount
{
protected:
    char name[100];
    char account[100];
    double balance;
public:
    BaseAccount(char *pName, char *acc, double bal):balance(bal)
    {
        strcpy(name,pName);
        strcpy(account,acc);
    };
    virtual void deposit(double money)
    {
        balance+=money;
    }
    virtual void withdraw(double money)
    {
        if(balance-money<0)
            cout<<"insufficient"<<endl;
        else
            balance-=money;
    }
    virtual void display()
    {
        cout<<name<<' '<<account<<" Balance:"<<balance<<endl;
    }
};

class BasePlus:public BaseAccount
{
protected:
    double limit;
    double limit_sum;
public:
    BasePlus(char *pName, char *acc, double bal):BaseAccount(pName,acc,bal)
    {
        limit=5000;
        limit_sum=0;
    }
    virtual void deposit(double money)
    {
        if(limit_sum-money>=0)
            limit_sum-=money;
        else
        {
            balance+=money-limit_sum;
            limit_sum=0;
        }
    }
    virtual void withdraw(double money)
    {
        if(balance-limit_sum-money+5000<0)
            cout<<"insufficient"<<endl;
        else
        {
            if(balance-money>=0)
                balance-=money;
            else
            {
                limit_sum+=money-balance;
                balance=0;
            }
        }
    }
    virtual void display()
    {
        cout<<name<<' '<<account<<" Balance:"<<balance<<" limit:"<<limit-limit_sum<<endl;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char pName[100],acc[100];
        double bal,de1,de2,wi1,wi2;
        BaseAccount *pv;
        cin>>pName>>acc>>bal;
        cin>>de1>>wi1>>de2>>wi2;
        if(strncmp(acc,"BA",2)==0)
        {
            BaseAccount ss(pName,acc,bal);
            pv=&ss;
            pv->deposit(de1);
            pv->withdraw(wi1);
            pv->deposit(de2);
            pv->withdraw(wi2);
            pv->display();
        }
        else if(strncmp(acc,"BP",2)==0)
        {
            BasePlus ss(pName,acc,bal);
            pv=&ss;
            pv->deposit(de1);
            pv->withdraw(wi1);
            pv->deposit(de2);
            pv->withdraw(wi2);
            pv->display();
        }
    }
}

