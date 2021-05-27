2018152102:Problem1119:´ð°¸´íÎó
#include <iostream>

using namespace std;
class BaseAccount {
protected:
    string name;
    string account;
    int balance;
public:
    BaseAccount(string na,string acco,int bal) : name(na),account(acco),balance(bal){}
    void deposit(int money) {
        balance  += money;
    }
    virtual void withdraw(int money) {
        if(money > balance) {
            cout<<"insufficient"<<endl;
            return;
        }
        balance -= money;
    }
    virtual void display() {
        cout<<name<<" "<<"Balance:"<<balance<<endl;
    }
};


class BasePlus:public BaseAccount {
protected:
    int limit;
    int limit_sum;
public:
    BasePlus(string na,string acco,int bal,int lim = 5000,int lim_s = 0):BaseAccount(na,acco,bal),limit(lim),limit_sum(lim_s) {}
    void withdraw(int money) {
        if(balance+limit < money ) {
            cout<<"insufficient"<<endl;
            return;
        }
        if(money<=balance) {
            balance -= money;
        } else {
            limit_sum = money - balance;
            balance = 0;
            limit -= limit_sum;
            limit_sum = 0;
        }
    }
    void display() {
        cout<<name<<" "<<"Balance:"<<balance<<" limit:"<<limit<<endl;
    }
};
int main() {
    int t;

    cin>>t;


    while(t--) {
        string name;
        char  account[32];
        int balance;
        BaseAccount * p;
        cin>>name>>account>>balance;
        if(account[1] == 'A') {
            BaseAccount acco(name,account,balance);
            p = &acco;
            int money;

            for(int i=0;i<2;i++) {
                cin>>money;
                p->deposit(money);
                cin>>money;
                p->withdraw(money);
            }
            p->display();
        }else {
            BasePlus acco(name,account,balance);
            p = &acco;
            int money;

            for(int i=0;i<2;i++) {
                cin>>money;
                p->deposit(money);
                cin>>money;
                p->withdraw(money);
            }

            p->display();
        }


    }

    return 0;
}

