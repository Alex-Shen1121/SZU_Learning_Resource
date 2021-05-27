2018152010:Problem1119:�𰸴���
#include<iostream>

using namespace std;
class BaseAccoumt
{
protected:
    string name,account;
    float balance;
public:
    BaseAccoumt(string na,string acc,float bal):name(na),account(acc),balance(bal){}
    virtual void Deposit(float money)
    {
        balance=balance+money;
    }
    virtual void Withdraw(float money)
    {
        if(balance-money>=0)
            balance=balance-money;
        else
            cout<<"insufficient"<<endl;
    }
    virtual void display()
    {
        cout<<name<<' '<<account<<' '<<"balance:"<<balance<<endl;

    }
};
class BasePlus:public BaseAccoumt
{
    float limit,limit_sum=0;
public:
    BasePlus(string name,string account,float balance):BaseAccoumt(name,account,balance),limit(5000){}
    void Deposit(float money)
    {
        if(limit_sum>0)
        {
            limit_sum=limit_sum-money;
            if(limit_sum<=0)
            {
                money=-limit_sum;
                limit_sum=0;
            }
            else
            {
                money=0;
            }
            limit=5000-limit_sum;
        }
        balance=balance+money;
    }
    void Withdraw(float money)
    {
        if(balance-money>=-limit)
        {
            balance=balance-money;
            if(balance<0)
            {
                limit_sum=-balance;
                limit=limit+balance;
                balance=0;
            }
        }
        else
            cout<<"insufficient"<<endl;
    }
    void display()
    {
        cout<<name<<' '<<account<<' '<<"balance:"<<balance<<' '<<"limit:"<<limit<<endl;
    }
};

int main()
{
    string name,account;
    int t;
    float balance,money;
    BaseAccoumt *per;
    cin>>t;
    while(t--)
    {
        cin>>name>>account>>balance;
        if(account[1]=='A')
        {
            BaseAccoumt BA(name,account,balance);
            per=&BA;
            cin>>money;
            per->Deposit(money);
            cin>>money;
            per->Withdraw(money);
            cin>>money;
            per->Deposit(money);
            cin>>money;
            per->Withdraw(money);
            per->display();
        }
        else
        {
            BasePlus BP(name,account,balance);
            per=&BP;
            cin>>money;
            per->Deposit(money);
            cin>>money;
            per->Withdraw(money);
            cin>>money;
            per->Deposit(money);
            cin>>money;
            per->Withdraw(money);
            per->display();
        }
    }
}

