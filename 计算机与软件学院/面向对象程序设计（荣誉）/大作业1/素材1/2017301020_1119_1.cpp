2017301020:Problem1119:ÕýÈ·
#include <iostream>
#include <cstring>
using namespace std;

class BaseAccount{
protected:
    string name;
    char account[10];
    double balance;
public:
    BaseAccount(string name1,char *account1,double balance1);
    void deposit(double a);
    virtual bool withdraw(double a);
    virtual void display();
    virtual void display1();
};

BaseAccount::BaseAccount(string name1,char *account1,double balance1){
    name=name1;
    balance=balance1;
    int lo=strlen(account1);
    for(int i=0;i<lo;i++){
        account[i]=account1[i];
    }
}

bool BaseAccount::withdraw(double a){
    if(a>balance){
        return 1;
    }
    else{
        balance-=a;
        return 0;
    }
}

void BaseAccount::deposit(double a){
    balance+=a;
}

void BaseAccount::display(){
    cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
}

void BaseAccount::display1(){
    cout<<"insufficient"<<endl;
}

class BasePulus:public BaseAccount{
    double limit=5000;
    double limit_sum=0;
public:
    BasePulus(string name1,char *account1,double balance1):BaseAccount(name1,account1,balance1){}
    virtual bool withdraw(double a);
    virtual void display();
    virtual void display1();
};

bool BasePulus::withdraw(double a){
    if(a>balance+limit-limit_sum){
        return 1;
    }
    else{
        if(a>balance){
            limit-=(a-balance);
            balance=0;
        }
        else
             balance-=a;
        return 0;
    }
}

void BasePulus::display1(){
    cout<<"insufficient"<<endl;
}

void BasePulus::display(){
    cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit<<endl;
}

int main()
{
    int t;
    double balance,m;
    string name;
    char account[10];
    cin>>t;
    while(t--){
        cin>>name>>account>>balance;
        if(account[1]=='A'){
            BaseAccount a(name,account,balance);
            cin>>m;
            a.deposit(m);
            cin>>m;
            if(a.withdraw(m))
                a.display1();
            cin>>m;
            a.deposit(m);
            cin>>m;
            if(a.withdraw(m))
                a.display1();
            a.display();
        }
        else{
            BasePulus a(name,account,balance);
            cin>>m;
            a.deposit(m);
            cin>>m;
            if(a.withdraw(m))
                a.display1();
            cin>>m;
            a.deposit(m);
            cin>>m;
            if(a.withdraw(m))
                a.display1();
            a.display();
        }
    }
    return 0;
}

