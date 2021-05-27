2018152007:Problem1119:ÕýÈ·
#include <iostream>

using namespace std;
class BaseAccount
{
protected:
    string name;
    string account;
    int balance;
public:
    BaseAccount(string n,string a,int b):name(n),account(a),balance(b){}
    void deposit(int a)
    {
        balance=balance+a;
    }
    virtual void withdraw(int a)
    {
        if(balance-a<0)
            cout<<"insufficient"<<endl;
        else
            balance=balance-a;
    }
    virtual void display()
    {
        cout<<name<<' '<<account<<' '<<"Balance:"<<balance<<endl;
    }
};
class BasePlus:public BaseAccount
{
private:
    int limit;
public:
    BasePlus(string n,string a,int b):BaseAccount(n,a,b)
    {
        limit=5000;
    }
    void withdraw(int a)
    {
        if(balance-a<0)
        {
            if(balance+limit-a<0)
                cout<<"insufficient"<<endl;
            else
            {
                limit=limit-(a-balance);
                balance=0;
            }
        }
        else
            balance=balance-a;
    }
    void display()
    {
        cout<<name<<' '<<account<<' '<<"Balance:"<<balance<<' '<<"limit:"<<limit<<endl;
    }
};
int main()
{
    int time;
    cin>>time;
    while(time--)
    {
        BaseAccount *B;
        string n,a;
        int b;
        cin>>n>>a>>b;
        int c,d,e,f;
        cin>>c>>d>>e>>f;
        if(a[1]=='A')
        {
            BaseAccount *A=new BaseAccount(n,a,b);
            B=A;
        }
        else
        {
            BasePlus *P=new BasePlus(n,a,b);
            B=P;
        }
        B->deposit(c);
        B->withdraw(d);
        B->deposit(e);
        B->withdraw(f);
        B->display();
    }
    return 0;
}

