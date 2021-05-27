2018192045:Problem1119:ÕýÈ·
#include<iostream>
using namespace std;
#include<cstring>
class BaseAccount
{
protected:
    string name;
    char account[30];
    float balance;
public:
    BaseAccount() {}
    BaseAccount(string n,char* a,float b):name(n),balance(b)
    {
        strcpy(account,a);
    }
    void depoist(float m)
    {
        balance+=m;
    }
    virtual void withdraw(float m)
    {
        if(m<=balance)
        {
            balance-=m;
        }
        else
            cout<<"insufficient"<<endl;
    }
    virtual void display()
    {
        cout<<name<<' '<<account<<" Balance:"<<balance<<endl;
    }
};
class BasePlus:public BaseAccount
{
    int limit,limit_sum;
public:
    BasePlus(string n,char* a,float b):BaseAccount(n,a,b),limit(5000),limit_sum(0) {}
    void withdraw(float m)
    {
        if(m<=balance)
        {
            balance-=m;
        }
        else if(m<=balance+limit)
        {
            limit_sum=m-balance;
            limit-=limit_sum;
            balance=0;
        }
        else
            cout<<"insufficient"<<endl;
    }
    void display()
    {
        cout<<name<<' '<<account<<" Balance:"<<balance<<" limit:"<<limit<<endl;
    }
};
int main ()
{
    int t;
    float a1,b1,a2,b2,balance;
    char account[20];
    string name;
    BaseAccount *p;
    cin>>t;
    while(t--)
    {
        cin>>name>>account>>balance>>a1>>b1>>a2>>b2;
        if(account[1]=='P')
        {
            BasePlus A(name,account,balance);
            p=&A;
            p->depoist(a1);
            p->withdraw(b1);
            p->depoist(a2);
            p->withdraw(b2);
            p->display();

        }
        if(account[1]=='A')
        {
            BaseAccount A(name,account,balance);
            p=&A;
            p->depoist(a1);
            p->withdraw(b1);
            p->depoist(a2);
            p->withdraw(b2);
            p->display();
        }
    }
}

