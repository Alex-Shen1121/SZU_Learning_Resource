2016073026:Problem1119:´ð°¸´íÎó
#include <iostream>

using namespace std;

class BaseAccount{
protected:
    string name,account;
    double balance;
public:
    BaseAccount(string na,string ac,double bal):name(na),account(ac),balance(bal){}
    void deposit(double m){balance+=m;}
    virtual void withdraw(double m){
        if(balance<m)   cout<<"insufficien\n";
        else balance-=m;
    }
    virtual void display(){cout<<name<<" "<<account<<" Balance:"<<balance<<endl;}
};

class BasePlus:public BaseAccount{
    double limit,limit_sum;
public:
    BasePlus(string na,string ac,double bal):BaseAccount(na,ac,bal),limit(5000),limit_sum(0){}
    void deposit(double m){balance+=m;}
    virtual void withdraw(double m){
        if(balance+(limit-limit_sum)<m)
            cout<<"insufficien\n";
        else
            balance-=m;
        if(balance<0){
            limit_sum-=balance;
            balance=0;
        }
    }
    virtual void display(){cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit-limit_sum<<endl;}
};

int main()
{
    BaseAccount *pb;
    int t;
    cin>>t;
    while(t--){
        string account,name;
        double balance,money;
        cin>>name>>account>>balance;
        if(account[1]=='A') pb=new BaseAccount(name,account,balance);
        else if(account[1]=='P')    pb=new BasePlus(name,account,balance);
        cin>>money;
        pb->deposit(money);
        cin>>money;
        pb->withdraw(money);
        cin>>money;
        pb->deposit(money);
        cin>>money;
        pb->withdraw(money);
        pb->display();
    }
    return 0;
}

