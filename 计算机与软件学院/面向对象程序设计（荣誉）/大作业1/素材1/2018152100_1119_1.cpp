2018152100:Problem1119:ÕýÈ·
#include <iostream>
#include <string>
using namespace std;

class BaseAccount
{
protected:
    string name;
    int balance;
    string account;
public:
    BaseAccount(string n,string a,int b):name(n),account(a),balance(b){}
    void deposit(int w)
    {
        balance+=w;
    }
    virtual void withdraw(int w)
    {
        if (w<=balance)
            balance-=w;
        else cout << "insufficient" << endl;
    }
    virtual void display()
    {
        cout << name <<
        " " << account <<
         " Balance:" <<
         balance << endl;
    }
};

class BasePlus:public BaseAccount
{
    int limit,limit_sum;
public:
    BasePlus(string n,string a,int b,int l=5000,int ls=0):BaseAccount(n,a,b),limit(l),limit_sum(ls){}
    void withdraw(int w)
    {
        if (w<=balance) balance-=w;
        else if (w<=(balance+limit-limit_sum))
        {
            limit_sum+=(w-balance);
            balance=0;
        }
        else cout << "insufficient" << endl;
    }
    void display()
    {
        cout << name << " " << account << " Balance:" << balance  << " limit:" << limit-limit_sum << endl;
    }
};

int main()
{
    int t,b,w;
    string n,ac;
    cin >> t;
    BaseAccount *pb;
    while (t--)
    {
        cin >> n >> ac >> b;
        BaseAccount ba(n,ac,b);
        BasePlus bp(n,ac,b);
        if (ac[1]=='A') pb=&ba;
        else pb=&bp;
        for (int i=0;i<2;i++)
        {
            cin >> w;
            pb->deposit(w);
            cin >> w;
            pb->withdraw(w);
        }
        pb->display();

    }
    return 0;
}

