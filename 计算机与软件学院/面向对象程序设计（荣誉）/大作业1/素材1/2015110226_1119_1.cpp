2015110226:Problem1119:ÕıÈ·
#include <bits/stdc++.h>
using namespace std;

class BaseAccount{
protected:
    string name;
    string account;
    int balance;
public:
    BaseAccount(string a,string b,int c):name(a),account(b),balance(c){}
    virtual void deposit(int v){
        balance += v;
    }
    virtual void withdraw(int v){
        if(v > balance){
            cout<<"insufficient"<<endl;
        }else{
            balance -= v;
        }
    }
    virtual void display(){
        cout<<name<<' '<<account<<" Balance:"<<balance<<endl;
    }
};
class BasePlus:public BaseAccount{
protected:
    int limit;//5000
    int limit_sum;
public:
    BasePlus(string a,string b,int c):BaseAccount(a,b,c){
        limit = 5000;
        limit_sum = 0;
    }
    void deposit(int v){
        if(limit_sum > 0){
            if(limit_sum > v) limit_sum -= v;
            else {
                v -= limit_sum;
                limit_sum = 0;
                balance += v;
            }
        }else{
            balance += v;
        }
    }
    void withdraw(int v){
        if(v > balance - limit_sum + limit){
            cout<<"insufficient"<<endl;
        }else{
            balance -= v;
            if(balance < 0){
                limit_sum += (-balance);
                balance = 0;
            }
        }
    }
    void display(){
        cout<<name<<' '<<account<<" Balance:"<<balance<<" limit:"<<limit-limit_sum<<endl;
    }
};


int main(){
    int time;
    cin>>time;
    while(time--){
        string a,b;
        int c,d;
        cin>>a>>b>>c;
        BaseAccount *p;
        if(b[1]=='A'){
            p = new BaseAccount(a,b,c);
        cin>>d;
        p->deposit(d);
        cin>>d;
        p->withdraw(d);
        cin>>d;
        p->deposit(d);
        cin>>d;
        p->withdraw(d);
        p->display();
        }
        else {
            p = new BasePlus(a,b,c);
        cin>>d;
        p->deposit(d);
        cin>>d;
        p->withdraw(d);
        cin>>d;
        p->deposit(d);
        cin>>d;
        p->withdraw(d);
        p->display();
        }
    }
    return 0;
}


