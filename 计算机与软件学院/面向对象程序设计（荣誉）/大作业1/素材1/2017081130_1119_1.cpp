2017081130:Problem1119:´ð°¸´íÎó
#include <iostream>
using namespace std;
class BaseAccount
{
protected:
    string name;
    string account;
    float balance;
public:
    BaseAccount(){};
    BaseAccount(string n,string a,float b):name(n),account(a),balance(b){};
    void deposit(float num)
    {
        balance+=num;
    }
    int withdraw(float num)
    {
        if(num>balance)
        {
            cout<<"insufficient"<<endl;
            return 0;
        }
        else
        {
            balance-=num;
            return 1;
        }
    }
    void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
    }
};
class BasePlus:virtual public BaseAccount
{
    float limit;
    float limit_sum;
public:
    BasePlus(){};
    BasePlus(string n,string a,float b,float l,float lsum):BaseAccount(n,a,b),limit(l),limit_sum(lsum){};
    int withdraw(float num)
    {
        if(num>balance+(limit-limit_sum))
        {
            cout<<"insufficient"<<endl;
            return 0;
        }
        else if(num<balance)
        {
            balance-=num;
            return 1;
        }
        else
        {
            balance=0;
            limit_sum+=(num-balance);
            return 1;
        }
    }
    void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit<<endl;
    }
};
int main()
{
    int t;
    float balance,dnum,wnum,dnum1,wnum1;
    string name,account;
    cin>>t;
    while(t--)
    {
        cin>>name>>account>>balance;
        BaseAccount a(name,account,balance);
        BasePlus p(name,account,balance,5000,0);
        cin>>dnum>>wnum>>dnum1>>wnum1;
        a.deposit(dnum);
        a.withdraw(wnum);
        a.deposit(dnum1);
        a.withdraw(dnum1);
        a.display();
        p.deposit(dnum);
        p.withdraw(wnum);
        p.deposit(dnum1);
        p.withdraw(wnum1);
        p.display();
    }
}

