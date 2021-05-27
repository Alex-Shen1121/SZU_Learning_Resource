2018192010:Problem1119:ÕýÈ·
#include <iostream>

using namespace std;
class BaseAccount
{
protected:
    string name,account;
    int balance;
public:
    BaseAccount(){}
    BaseAccount(string n,string a,int b):name(n),account(a),balance(b){}
    ~BaseAccount(){}
    void deposit(int m)
    {
        balance += m;
    }
    virtual void withdraw(int m)
    {
        if(m <= balance)
            balance -= m;
        else
            cout << "insufficient" << endl;
    }
    virtual void display()
    {
        cout << name << ' ' << account << ' ' << "Balance:" << balance << endl;
    }
};
class BasePlus:public BaseAccount
{
protected:
    int limit,limit_sum;
public:
    BasePlus(){}
    BasePlus(string n,string a,int b):BaseAccount(n,a,b),limit(5000),limit_sum(0){}
    void withdraw(int m)
    {
        if(m <= balance)
            balance -= m;
        else if(m <= balance+limit)
        {
            limit = limit - (m-balance);
            limit_sum = m - balance;
            balance = 0;
        }
        else
            cout << "insufficient" << endl;
    }
    void display()
    {
        cout << name << ' ' << account << ' ' << "Balance:" << balance;
        cout << ' ' << "limit:" << limit << endl;
    }
};
int main()
{
    int t;
    string no,name;
    int b,m;
    cin >> t;
    while(t--)
    {
        BaseAccount *pv;
        cin >> name >> no >> b;
        if(no[1]=='A')
        {
            pv = new BaseAccount(name,no,b);
            cin >> m;
            pv->deposit(m);
            cin >> m;
            pv->withdraw(m);
            cin >> m;
            pv->deposit(m);
            cin >> m;
            pv->withdraw(m);
            pv->display();
            delete pv;
        }
        else if(no[1]=='P')
        {
            pv = new BasePlus(name,no,b);
            cin >> m;
            pv->deposit(m);
            cin >> m;
            pv->withdraw(m);
            cin >> m;
            pv->deposit(m);
            cin >> m;
            pv->withdraw(m);
            pv->display();
            delete pv;
        }
    }
    return 0;
}

