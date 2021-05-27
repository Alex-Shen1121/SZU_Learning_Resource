2016071031:Problem1119:正确
#include <iostream>
#include <bits/stdc++.h>
// 考察向下转换
using namespace std;

class BaseAccount {
protected:
    string name;
    string account;
    int balance;
public:
    BaseAccount() {}
    BaseAccount(string name_, string account_, int balance_)
        :name(name_), account(account_), balance(balance_) {}
    virtual void deposit(int amount) {
        balance += amount;
    }

    virtual void withdraw(int amount) {
        if (amount > balance)
            cout<< "insufficient" <<endl;
        else
            balance -= amount;
    }
    virtual void display() {
        cout<< name << " " << account << " Balance:" << balance <<endl;
    }
};

class BasePlus: public BaseAccount {
    int limit;
    int limit_sum;
public:
    BasePlus() {
        limit = 5000;
        limit_sum = 0;
    }
    BasePlus(string name_, string account_, int balance_)
            : BaseAccount(name_, account_, balance_) {
                limit = 5000;
                limit_sum = 0;
            }
    void deposit(int amount) {
    	if (limit_sum > 0) {
    		if (limit_sum >= amount) {
    			limit_sum -= amount;
			} else {
				balance += amount - limit_sum;
				limit_sum = 0;
			}
		} else {
		    balance += amount;
		}
    }

    void withdraw(int amount) {
        if (amount > balance + limit) {
            cout<< "insufficient" <<endl;
        }else if (amount > balance) {
        	limit_sum += amount - balance;
            balance = 0;
        } else {
            balance -= amount;
        }

    }
    void display() {
        cout<< name << " " << account << " Balance:" << balance;
        cout<< " limit:" << limit - limit_sum <<endl;
    }
};


int main() {
//	freopen("ojdata.txt", "r", stdin);
    int t, balance, o1, o2, o3, o4;
    string name, account;

    BaseAccount *b;
    cin>>t;
    while (t--) {
        cin>>name>>account>>balance;
        if(account.find('A') != -1) {
            b = new BaseAccount(name, account, balance);
        } else {
            b = new BasePlus(name, account, balance);
        }
        cin>>o1>>o2>>o3>>o4;

        b->deposit(o1);
        b->withdraw(o2);
        b->deposit(o3);
        b->withdraw(o4);
        b->display();

    }
    return 0;
}


