2017133026:Problem1119:ÕýÈ·
#include <iostream>

using namespace std;
class BaseAccount{
protected:
    string name;
    string account;
    int balance;
public:
    BaseAccount(string n,string a,int b){
        name=n;
        account=a;
        balance=b;
    }
    void deposit(int v){
        balance+=v;
    }
    virtual void withdraw(int v){
        if(balance<v){
            cout<<"insufficient"<<endl;
            return;
        }
        balance-=v;
    }
    virtual void display(){
        cout<<name<<" "<<account<<" "<<"Balance:"<<balance<<endl;
    }

};
class BasePlus:public BaseAccount{
    int limit;
    int limit_sum;
public:
    BasePlus(string n,string a,int b):BaseAccount(n,a,b){
        limit=5000;
        limit_sum=0;
    }
    void withdraw(int v){
        if(v>limit+balance){
            cout<<"insufficient"<<endl;
        }else{
            if(balance>=v){
                balance-=v;
            }else{
                limit-=(v-balance);
                limit_sum+=(v-balance);
                balance=0;
            }
        }
    }

    void display(){
        cout<<name<<" "<<account<<" "<<"Balance:"<<balance<<" limit:"<<limit<<endl;
    }
};

int main()
{
    int t;
    cin>>t;
    string name,acc;
    int balance;
    BaseAccount *ba;
    int value;
    while(t--){
        cin>>name>>acc>>balance;
        if(acc[1]=='A'){
            BaseAccount ba1(name,acc,balance);
            ba=&ba1;
            cin>>value;
            ba->deposit(value);
            cin>>value;
            ba->withdraw(value);
            cin>>value;
            ba->deposit(value);
            cin>>value;
            ba->withdraw(value);
            ba->display();
        }else if(acc[1]=='P'){
            BasePlus bp(name,acc,balance);
            ba=&bp;
            cin>>value;
            ba->deposit(value);
            cin>>value;
            ba->withdraw(value);
            cin>>value;
            ba->deposit(value);
            cin>>value;
            ba->withdraw(value);
            ba->display();
        }
    }
    return 0;
}

