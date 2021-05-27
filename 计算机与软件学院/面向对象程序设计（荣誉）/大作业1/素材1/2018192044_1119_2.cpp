2018192044:Problem1119:ÕıÈ·
#include <iostream>
using namespace std;
class BaseAccount
{
protected:
    string name,account;
    int balance;
public:
    BaseAccount(string n,string a,int b):name(n),account(a),balance(b){}
    void deposit(int a)
    {
        balance+=a;
    }
    virtual void withdraw(int a)
    {
        if(a>balance)
            cout<<"insufficient"<<endl;
        else
            balance-=a;
    }
    virtual void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
    }
    ~BaseAccount(){}
};
class BasePlus:public BaseAccount
{
    int limit,limit_sum;
public:
    BasePlus(string n,string a,int b):BaseAccount(n,a,b),limit(5000),limit_sum(0){}
    void withdraw(int a)
    {
        if(a>(balance+limit-limit_sum))
            cout<<"insufficient"<<endl;
        else
        {
            balance-=a;
            if(balance<0)
            {
                limit_sum+=(-balance);
                balance=0;
            }
        }
    }
    void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit-limit_sum<<endl;
    }
};
int main()
{
    int t,balance,a;
    string name,account;
    cin>>t;
    BaseAccount *p;
    while(t--)
    {
        cin>>name>>account>>balance;
        if(account[1]=='A')
        {
            BaseAccount A(name,account,balance);
            p=&A;
            cin>>a;
            p->deposit(a);
            cin>>a;
            p->withdraw(a);
            cin>>a;
            p->deposit(a);
            cin>>a;
            p->withdraw(a);
            p->display();
        }
        else
        {
            BasePlus A(name,account,balance);
            p=&A;
            cin>>a;
            p->deposit(a);
            cin>>a;
            p->withdraw(a);
            cin>>a;
            p->deposit(a);
            cin>>a;
            p->withdraw(a);
            p->display();
        }
    }
    return 0;
}

