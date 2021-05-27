2017044015:Problem1119:ÕýÈ·
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class BaseAccount{
protected:
    string name, accout;
    double balance;
public:
    BaseAccount(string nstr, string astr, double bal){
        name = nstr;
        accout =  astr;
        balance = bal;
    }
    virtual void deposit(double d){
        balance += d;
    }
    virtual void withdraw(double d){
        if(balance < d)
        {
            cout<<"insufficient"<<endl;
            return;
        }
        balance = balance - d;
    }
    virtual void display(){
        cout<<name<<" "<<accout<<" Balance:"<<balance<<endl;
    }
};

class BasePlus: public BaseAccount{
protected:
    double limit, limit_sum;
public:
    BasePlus(string nstr, string astr, double bal):BaseAccount(nstr, astr, bal){
        limit = 5000;
        limit_sum = 0;
    }
    virtual void deposit(double d){
        if(limit_sum > 0){
            if(limit_sum > d){
                limit_sum -= d;
                limit += d;
                return;
            }
            d = d - limit_sum;
            balance += d;
            limit = 5000;
            return;
        }
        balance += d;
        return;
    }
    virtual void withdraw(double d){
        if((balance + limit - limit_sum) < d)
        {
            cout<<"insufficient"<<endl;
            return;
        }
        balance = balance - d;
        if(balance < 0)
        {
            limit_sum = 0 - balance;
            balance = 0;
            limit = limit - limit_sum;
            return;
        }
    }
    virtual void display(){
        cout<<name<<" "<<accout<<" Balance:"
        <<balance<<" "<<"limit:"<<limit<<endl;
    }
};

int main()
{
    int t;
    double bal, op1, op2, op3, op4;
    string nstr, astr;
    cin>>t;
    while(t--){
        cin>>nstr>>astr>>bal;
        BaseAccount* p;
        if(astr[1] == 'A'){
            p = new BaseAccount(nstr, astr, bal);
            cin>>op1>>op2>>op3>>op4;
            p->deposit(op1);
            p->withdraw(op2);
            p->deposit(op3);
            p->withdraw(op4);
            p->display();
        }
        else if(astr[1] == 'P'){
            p = new BasePlus(nstr, astr, bal);
            cin>>op1>>op2>>op3>>op4;
            p->deposit(op1);
            p->withdraw(op2);
            p->deposit(op3);
            p->withdraw(op4);
            p->display();
        }
    }
    return 0;
}

