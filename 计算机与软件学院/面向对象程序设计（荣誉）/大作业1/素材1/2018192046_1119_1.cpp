2018192046:Problem1119:ÕýÈ·
#include<iostream>
#include<string>
using namespace std;
class BaseAccount
{
protected:
    string name;
    string account;
    double balance;
public:
    BaseAccount(string _name,string _account,double _balance):name(_name),account(_account),balance(_balance){}
    virtual void deposit(double r)
    {
        balance+=r;
    }
    virtual void withdraw(double r)
    {
        if(r>balance)
            cout<<"insufficient"<<endl;
        else
            balance-=r;
    }
    virtual void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
    }
};
class BasePlus:public BaseAccount
{
    double limit;
    double limit_sum;
public:
    BasePlus(string _name,string _account,double _balance):BaseAccount(_name,_account,_balance)
    {
        limit=5000;
        limit_sum=0;
    }
    void deposit(double r)
    {
        if(limit_sum!=0)
        {
            limit_sum-=r;
            if(limit_sum<0)
            {
                balance=balance+limit_sum*(-1);
                limit_sum=0;
            }
        }
        else
        {
            balance+=r;
        }
        //display();
    }
    void withdraw(double r)
    {
        if((balance+limit-limit_sum)>=r)
        {
            if(balance-r<0)
            {
                r=r-balance;
                balance=0;
                limit_sum+=r;
            }
            else
            {
                balance-=r;
            }
        }
        else
        {
            cout<<"insufficient"<<endl;
        }
        //display();
    }
    void display()
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
        string name,account;
        double balance;
        cin>>name>>account>>balance;
        string flag(account,0,2);
        if(flag=="BA")
        {
            BaseAccount P(name,account,balance);
            double num;
            cin>>num;
            P.deposit(num);
            cin>>num;
            P.withdraw(num);
            cin>>num;
            P.deposit(num);
            cin>>num;
            P.withdraw(num);
            P.display();
        }
        else if(flag=="BP")
        {
            BasePlus P(name,account,balance);
            double num;
            cin>>num;
            P.deposit(num);
            cin>>num;
            P.withdraw(num);
            cin>>num;
            P.deposit(num);
            cin>>num;
            P.withdraw(num);
            P.display();
        }
    }
}

