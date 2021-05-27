2017161025:Problem1119:ÕýÈ·
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
 
class BaseAccount
{
public:
    BaseAccount(string n, string a, int b)
        :name(n), account(a), balance(b) {}
    void deposit(int a) { 
        balance += a;
    }
    virtual int withdraw(int a) {
        if (a > balance) 
            return 0;
        balance -= a;
        return 1;
    }
    virtual void display() {
        cout << name << ' ' << account <<
            " Balance:" << balance << endl;
    }
    virtual ~BaseAccount() {}
protected:
    string name, account;
    int balance;
};
 
class BasePlus :public BaseAccount
{
public:
    BasePlus(string n, string a, int b, int l = 5000)
        :BaseAccount(n, a, b), limit(l) {}
    int withdraw(int a) {
        if (a > limit + balance) return 0;
        else if (a < balance) balance -= a;
        else { limit -= (a - balance); balance = 0; }
        return 1;
    }
    ~BasePlus() {}
    virtual void display() {
        cout << name << ' ' << account <<
            " Balance:" << balance <<
            " limit:" << limit << endl;
    }
private:
    int limit;
};
 
 
int main()
{
    int t;
    cin >> t;
    BaseAccount* obj = NULL;
    for (int i = 0; i < t; i++) {
        string a, b; int c, d, e, f;
        cin >> a >> b >> c;
 
        if (b[1] == 'P')
            obj = new BasePlus(a, b, c);
        else
            obj = new BaseAccount(a, b, c);
 
        cin >> c >> d >> e >> f;
        obj->deposit(c);
        if (obj->withdraw(d) == 0) {
            cout << "insufficient" << endl;
        }
        obj->deposit(e);
        if (obj->withdraw(f) == 0) {
            cout << "insufficient" << endl;
        }
        obj->display();
        delete obj;
        obj = NULL;
    }
    return 0;
}
