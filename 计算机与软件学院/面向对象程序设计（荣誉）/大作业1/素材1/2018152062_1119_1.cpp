2018152062:Problem1119:正确
#include <iostream>
using namespace std;
/*某银行的支票账户分为两类，一类为基本支票账户BaseAccount，另一类为具有透支保护特性的BasePlus支票账户。
BaseAccount支票账户的信息包括：客户姓名(name)、账户(account)、当前结余(balance)；
BaseAccount支票账户可以执行的操作包括：存款(deposit)、取款(withdraw)、显示账户信息(display)。
注意：取款金额不能透支，否则显式出错信息“insufficient”。*/
class BaseAccount
{
protected:
    string name;
    string account;
    float balance;
public:
    BaseAccount(string _name,string _account,float _balance):name(_name),account(_account),balance(_balance){}
    virtual void deposit(float e)
    {
        balance+=e;
    }
    virtual void withdraw(float e)
    {
        if(e<=balance)
            balance-=e;
        else
            cout<<"insufficient"<<endl;
    }
    virtual void print()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
    }
};
/*BasePlus支票账户除包含BaseAccount的所有信息外，还包括以下信息：透支上限(limit：默认为5000)，
当前透支总额(limit_sum)；BasePlus支票账户可执行的操作与BaseAccount相同，
但有两种操作的实现不同：(1)对于取款操作，可以在透支上限范围内透支，超过则显示出错信息“insufficient”；
(2)对于显示操作，必须显示BasePlus的其他信息。
请实现BaseAccount类和BasePlus类，其中BasePlus类继承于BaseAccount类，
注意BaseAccount账户名称以BA开头，BasePlus账户名称以BP开头。
要求只使用一个基类指针，指向所建立的对象，然后使用指针调用类中的方法。*/
class BasePlus:public BaseAccount
{
protected:
    float limit;
public:
    BasePlus(string _name,string _account,float _balance):BaseAccount(_name,_account,_balance)
    {
        limit=5000;
    }
    void deposit(float e)
    {
        balance+=e;
    }
    void withdraw(float e)
    {
        if(e<=limit+balance)
        {
            if(e<=balance)
                balance-=e;
            else
            {
                limit-=(e-balance);
                balance=0;
            }
        }
        else
            cout<<"insufficient"<<endl;
    }
    void print()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit<<endl;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        BaseAccount *p;
        string name;
        char account[10];
        float balance;
        float d1,w1,d2,w2;
        cin>>name>>account>>balance>>d1>>w1>>d2>>w2;
        if(account[1]=='A')
        {
            BaseAccount u(name,account,balance);
            p=&u;
            p->deposit(d1);
            p->withdraw(w1);
            p->deposit(d2);
            p->withdraw(w2);
            p->print();
        }
        else
        {
            BasePlus v(name,account,balance);
            p=&v;
            p->deposit(d1);
            p->withdraw(w1);
            p->deposit(d2);
            p->withdraw(w2);
            p->print();
        }
    }
    return 0;
}

