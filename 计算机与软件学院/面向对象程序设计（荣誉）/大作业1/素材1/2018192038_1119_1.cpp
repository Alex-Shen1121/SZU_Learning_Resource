2018192038:Problem1119:ÕýÈ·
#include <iostream>

using namespace std;

class BaseAccount
{
protected:
    string name;
    string account;
    int balance;
public:
    BaseAccount(string nn,string acc,int b):name(nn),account(acc),balance(b){}
    void deposit(int m)
    {
        balance+=m;
    }
    virtual void withdraw(int m)
    {
        if(balance>=m)
        {
            balance-=m;
        }
        else
        {
            cout<<"insufficient"<<endl;
        }
    }
    virtual void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
    }
};

class BasePlus:public BaseAccount
{
    int limit;
public:
    BasePlus(string nn,string acc,int b):BaseAccount(nn,acc,b),limit(5000){}
    void withdraw(int m)
    {
        if(limit+balance>=m)
        {
            if(balance>=m)
            {
                balance-=m;
            }
            else
            {

                //cout<<limit<<endl;
                limit-=(m-balance);
                balance=0;
               // cout<<limit<<endl;
            }
        }
        else
        {
            cout<<"insufficient"<<endl;
        }
    }
    void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit<<endl;
    }
};

int main()
{
    string name;
    string account;
    int balance;
    int t,money;
    cin>>t;
    BaseAccount *p=NULL;
    while(t--)
    {
        string sub;
        cin>>name>>account>>balance;
        sub=account.substr(0,2);
        //cout<<sub<<endl;
        if(sub=="BA")
        {

            BaseAccount ba(name,account,balance);
            p=&ba;
            cin>>money;
            p->deposit(money);
            cin>>money;
            p->withdraw(money);
            cin>>money;
            p->deposit(money);
            cin>>money;
            p->withdraw(money);
            p->display();
        }
        else if(sub=="BP")
        {
            //cin>>limit;
            BasePlus bp(name,account,balance);
            p=&bp;
            cin>>money;
            p->deposit(money);
            cin>>money;
            p->withdraw(money);
            cin>>money;
            p->deposit(money);
            cin>>money;
            p->withdraw(money);
            p->display();
        }
    }
    return 0;
}

