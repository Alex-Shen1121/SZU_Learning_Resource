2018192024:Problem1119:ÕýÈ·
#include <iostream>
#include <cstring>
using namespace std;

class BaseAccount
{
protected:
    string name;
    char *account;
    int balance;
public:
    BaseAccount(){account=new char[50];}
    BaseAccount(string n,char *a,int b):name(n),account(a),balance(b){account=new char[50];strcpy(account,a);}
    virtual void deposit(int money){balance+=money;}
    virtual void withdraw(int money)
    {
        if(money>balance)
            cout<<"insufficient"<<endl;
        else
            balance-=money;
    }
    virtual void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
    }
    ~BaseAccount(){delete []account;}
};
class BasePlus:public BaseAccount
{
    int limit,limit_sum;
public:
    BasePlus(string n,char *a,int b,int l=5000,int ls=0):BaseAccount(n,a,b),limit(l),limit_sum(ls){}
    virtual void deposit(int money)
    {
        if(limit_sum>0)
        {
            money-=limit_sum;
            limit_sum=0;
        }
        balance+=money;
    }
    virtual void withdraw(int money)
    {
        if(money>balance+limit-limit_sum)
            cout<<"insufficient"<<endl;
        else
        {
            if(money>balance)
            {
                limit_sum=money-balance;
                balance=0;
            }
            else
                balance-=money;
        }
    }
    virtual void display()
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
        string n;
        char *a=new char[50];
        int b,money;
        BaseAccount *p;
        cin>>n>>a>>b;
        if(a[1]=='A')
        {
            BaseAccount ba(n,a,b);
            p=&ba;
            for(int i=0;i<4;i++)
            {
                cin>>money;
                if(i==0||i==2)
                    p->deposit(money);
                else
                    p->withdraw(money);
            }
            p->display();
        }
        else if(a[1]=='P')
        {
            BasePlus bp(n,a,b);
            p=&bp;
            for(int i=0;i<4;i++)
            {
                cin>>money;
                if(i==0||i==2)
                    p->deposit(money);
                else
                    p->withdraw(money);
            }
            p->display();
        }
    }
    return 0;
}

