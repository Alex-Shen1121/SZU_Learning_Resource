2017163058:Problem1119:正确
#include <iostream>
#include <fstream>
using namespace std;
//某银行的支票账户分为两类，一类为基本支票账户BaseAccount，另一类为具有透支保护特性的BasePlus支票账户。
//
//BaseAccount支票账户的信息包括：客户姓名(name)、账户(account)、当前结余(balance)
//
//BaseAccount支票账户可以执行的操作包括：存款(deposit)、取款(withdraw)、显示账户信息(display)。注意：取款金额不能透支，否则显式出错信息“insufficient”。
//
//BasePlus支票账户除包含BaseAccount的所有信息外，还包括以下信息：
//
//请实现BaseAccount类和BasePlus类，其中BasePlus类继承于BaseAccount类，注意BaseAccount账户名称以BA开头，BasePlus账户名称以BP开头。
class BaseAccount
{
protected:
    string name, account;
    int balance;
public:
    BaseAccount(string n, string a, int b):name(n), account(a), balance(b){}
    void deposit(int money)
    {
        balance += money;
    }
    virtual void withdraw(int money)
    {
        if(balance < money)
        {
            cout<<"insufficient"<<endl;
        }
        else
        {
            balance -= money;
        }
    }
    virtual void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
    }
};
//透支上限(limit：默认为5000)，当前透支总额(limit_sum)；BasePlus支票账户可执行的操作与BaseAccount相同，但有两种操作的实现不同：
//
//(1)对于取款操作，可以在透支上限范围内透支，超过则显示出错信息“insufficient”；
//
//(2)对于显示操作，必须显示BasePlus的其他信息。
class BasePlus:public BaseAccount
{
private:
    int limit, limits_sum;
public:
    BasePlus(string name, string account, int balance):BaseAccount(name, account, balance), limit(5000), limits_sum(0){}
    void withdraw(int money)
    {
        if(money <= balance)
        {
            balance -= money;
        }
        else if(balance > 0 && money < balance + limit)
        {
            limits_sum += (money-balance);
            balance = 0;
        }
        else if(money + limits_sum < limit)
        {
            limits_sum += money;
        }
        else
        {
            cout<<"insufficient"<<endl;
        }
    }
    void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit-limits_sum<<endl;
    }
};
int main()
{
//    freopen("C:\\Users\\acer\\Desktop\\in.txt", "r", stdin);
    string name, account;
    int balance, money, t;
    cin>>t;
    BaseAccount *p;
    while(t --)
    {
        cin>>name>>account>>balance;
        if(account[1] == 'A')
        {
            BaseAccount baseAccount(name, account, balance);
            p = &baseAccount;
            for(int i=0;i<2;i++)
            {
                cin>>money;
                p->deposit(money);
                cin>>money;
                p->withdraw(money);
            }
            p->display();
        }
        else
        {
            BasePlus basePlus(name, account, balance);
            p = &basePlus;
            for(int i=0;i<2;i++)
            {
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

