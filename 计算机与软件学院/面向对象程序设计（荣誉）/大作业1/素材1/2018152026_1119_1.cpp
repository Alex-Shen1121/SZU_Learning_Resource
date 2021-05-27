2018152026:Problem1119:ÕýÈ·
#include<iostream>
#include<cstdio>
#include<string>
 
using namespace std;
 
class BaseAccount 
{
protected:
    string name, account;
    int balance;
public:
    BaseAccount() {}
    BaseAccount(string name, string account, int balance)
      :name(name),account(account),balance(balance) {}
    virtual void deposit(int x) 
    {
        balance += x;
    }
    virtual void withdraw(int x) 
    {
        if (balance < x) 
        {
            cout << "insufficient" << endl;
        } else 
        {
            balance -= x;
        }
    }
    virtual void display() 
    {
        cout << name << " " << account << " " << "Balance:" << balance << endl;
    }
};
 
class BasePlus: public BaseAccount
{
private:
    int limitsum;
    int limit;
public:
    BasePlus() 
    {
      limit = 5000;
      limitsum = 0;
    }
    BasePlus(string name,string account,int balance)
        :BaseAccount(name,account,balance) 
    {
        limit = 5000;
        limitsum = 0;
    }
    void deposit(int x) 
    {
       
      if (limitsum) 
      {
         
        if (limitsum > x) 
        {
          limitsum -= x;
          x = 0;
        } 
        else 
        {
          x -= limitsum;
          limitsum = 0;
        }
      }
       
      balance += x;
    }
    void withdraw(int x) 
    {
         
        if (balance >= x) 
        {
            balance -= x;
        } 
        else if (balance + limit - limitsum >= x) 
        {
            limitsum += x - balance;
            balance = 0;
        } 
        else 
        {
            cout << "insufficient" << endl;
        }
    }
    void display() 
    {
        cout << name << " " << account << " " << "Balance:" << balance << " limit:" << limit - limitsum << endl;
    }
};
 
int main() 
{
    int t;
    cin >> t;
    while (t--)
    {
        string name, account;
        int balance;
        cin >> name >> account >> balance;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        BaseAccount *p;
        if (account[1] == 'A') 
        {
            BaseAccount tmp(name, account, balance);
            p = &tmp;
            p->deposit(a);
            p->withdraw(b);
            p->deposit(c);
            p->withdraw(d);
            p->display();
        } 
        else 
        {
            BasePlus tmp(name, account, balance);
            p = &tmp;
            p->deposit(a);
            p->withdraw(b);
            p->deposit(c);
            p->withdraw(d);
            p->display();
        }
    }
    return 0;
}
