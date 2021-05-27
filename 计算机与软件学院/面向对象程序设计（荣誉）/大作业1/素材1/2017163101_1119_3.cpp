2017163101:Problem1119:ÕýÈ·
#include<iostream>
#include<cstdio>
#include<string>;
using namespace std;
class BaseAccount {
protected:
    string name, account;
    int balance;
public:
    BaseAccount() {}
    BaseAccount(string name, string account, int balance)
      :name(name),account(account),balance(balance) {}
    virtual void deposit(int accno) {
        balance += accno;
    }
    virtual void withdraw(int accno) {
        if (balance < accno) {
            cout << "insufficient" << endl;
        } else {
            balance -= accno;
        }
    }
    virtual void display() {
        cout << name << " " << account << " " << "Balance:" << balance << endl;
    }
};
 
class BasePlus: public BaseAccount{
private:
    int limit_sum;
    int limit;
public:
    BasePlus() {
      limit = 5000;
      limit_sum = 0;
    }
    BasePlus(string name,string account,int balance)
        :BaseAccount(name,account,balance) {
        limit = 5000;
        limit_sum = 0;
    }
    void deposit(int accno) {
     
      if (limit_sum) {
        
        if (limit_sum > accno) {
          limit_sum -= accno;
          accno = 0;
        } else {
          accno -= limit_sum;
          limit_sum = 0;
        }
      }
  
      balance += accno;
    }
    void withdraw(int accno) {
         
        if (balance >= accno) {
            balance -= accno;
        
        } else if (balance + limit - limit_sum >= accno) {
            limit_sum += accno - balance;
            balance = 0;
        } else {
            cout << "insufficient" << endl;
        }
    }
    void display() {
        cout << name << " " << account << " " << "Balance:" << balance << " limit:" << limit - limit_sum << endl;
    }
};
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        string name, account;
        int balance;
        cin >> name >> account >> balance;
        int d1,w1,d2,w2;
        cin >>d1>>w1 >>d2 >>w2;
        BaseAccount *b;
        if (account[1] == 'A') {
            BaseAccount BA(name, account, balance);
            b = &BA;
            b->deposit(d1);
            b->withdraw(w1);
            b->deposit(d2);
            b->withdraw(w2);
            b->display();
        } else {
            BasePlus BP(name, account, balance);
            b = &BP;
            b->deposit(d1);
            b->withdraw(w1);
            b->deposit(d2);
            b->withdraw(w2);
            b->display();
        }
    }
    return 0;
}
