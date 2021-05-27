2017182013:Problem1119:ÕýÈ·
#include <bits/stdc++.h>

using namespace std;

class BaseAccount
{
protected:
    string name,account;
    int balance;
public:
    BaseAccount(string n,string a,int b):name(n),account(a),balance(b){}
    void deposit(int m)
    {
        balance+=m;
    }
    virtual void withdraw(int m)
    {
        if(balance>=m)
            balance-=m;
        else
            cout<<"insufficient"<<endl;
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
    BasePlus(string n,string a,int b):BaseAccount(n,a,b)
    {
        limit=5000;
    }
    void withdraw(int m)
    {
        if(balance+limit>=m)
        {
            if(balance>=m)
                balance-=m;
            else
            {
                limit= limit +balance-m;
                balance=0;
            }
        }
        else
            cout<<"insufficient"<<endl;
    }
    void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit<<endl;
    }
};
int main()
{
    //freopen("C:\\Users\\241\\Desktop\\c\\s.txt",stdin,"r");
    int n;
    cin>>n;
    while(n--)
    {
        BaseAccount *p;
        string name,account;
        int balance,limit;
        cin>>name>>account>>balance;
        if(account[1]=='P')
        {

            BasePlus bp(name,account,balance);
            p = &bp;
            int num;
            cin>>num;
            p->deposit(num);
            cin>>num;
            p->withdraw(num);
            cin>>num;
            p->deposit(num);
            cin>>num;
            p->withdraw(num);
            p->display();
        }
        else
        {
            BaseAccount ba(name,account,balance);
            p = &ba;
            int num;
            cin>>num;
            p->deposit(num);
            cin>>num;
            p->withdraw(num);
            cin>>num;
            p->deposit(num);
            cin>>num;
            p->withdraw(num);
            p->display();
        }

    }
    return 0;
}

