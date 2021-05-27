2018151005:Problem1119:正确
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
/*某银行的支票账户分为两类，一类为基本支票账户BaseAccount，另一类为具有透支保护特性的BasePlus支票账户。


BaseAccount支票账户的信息包括：客户姓名(name)、账户(account)、当前结余(balance)；BaseAccount支票账户可
以执行的操作包括：存款(deposit)、取款(withdraw)、显示账户信息(display)。注意：取款金额不能透支，否则显
式出错信息“insufficient”。*/

class BaseAccount
{
protected:
    string name;
    char account[8];
    float balance;
public:
    BaseAccount(){}
    BaseAccount(string name0,char* account0,float balance0):name(name0),balance(balance0)
    {
        strcpy(account,account0);
    }
    virtual void deposit(float money)
    {
        balance+=money;
    }
    virtual void withdraw(float money)
    {
        if(balance>=money)
        {
            balance-=money;
        }
        else
        {
            cout<<"insufficient"<<endl;
        }
    }
    virtual void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
    }
};
/*BasePlus支票账户除包含BaseAccount的所有信息外，还包括以下信息：透支上限(limit：默认为5000)，当前透支总
额(limit_sum)；BasePlus支票账户可执行的操作与BaseAccount相同，但有两种操作的实现不同：(1)对于取款操作，
可以在透支上限范围内透支，超过则显示出错信息“insufficient”；(2)对
于显示操作，必须显示BasePlus的其他信息。*/


class BasePlus:public BaseAccount
{
private:
    float limit;
    float limit_sum;
public:
    BasePlus():limit(5000),limit_sum(0){}
    BasePlus(string name0,char* account0,float balance0):BaseAccount(name0,account0,balance0),
        limit(5000),limit_sum(0){}
    virtual void deposit(float money)
    {
        int balance_real=balance-limit_sum+money;
        if(balance_real>=0)
        {
            balance=balance_real;
            limit_sum=0;
        }
        else
        {
            balance=0;
            limit_sum=-balance_real;
        }
    }
    virtual void withdraw(float money)
    {
        int balance_real=balance-limit_sum-money;
        if(balance_real>=0)
        {
            balance=balance_real;
            limit_sum=0;
        }
        else if(balance_real<0&&balance_real>=-limit)
        {
            balance=0;
            limit_sum=-balance_real;
        }
        else
        {
            cout<<"insufficient"<<endl;
        }
    }
    virtual void display()
    {
        cout<<name<<" "<<account<<" Balance:"<<balance<<" limit:"<<limit-limit_sum<<endl;
    }
};
void yunxing(BaseAccount* pa)
{
    float m1,m2,m3,m4;
    cin>>m1>>m2>>m3>>m4;
    pa->deposit(m1);
    pa->withdraw(m2);
    pa->deposit(m3);
    pa->withdraw(m4);
    pa->display();
}
/*请实现BaseAccount类和BasePlus类，其中BasePlus类继承于BaseAccount类，注意BaseAccount账户名称以BA开头，
BasePlus账户名称以BP开头。

要求只使用一个基类指针，指向所建立的对象，然后使用指针调用类中的方法。*/
int main()
{
    int t;
    cin>>t;
    BaseAccount* pa;
    while(t--)
    {
        string name;
        char account[8];
        float balance;
        cin>>name>>account>>balance;
        char type[3];
        type[0]=account[0];
        type[1]=account[1];
        type[2]='\0';
        if(strcmp(type,"BA")==0)
        {
            BaseAccount a(name,account,balance);
            pa=&a;
            yunxing(pa);
        }
        else if(strcmp(type,"BP")==0)
        {
            BasePlus a(name,account,balance);
            pa=&a;
            yunxing(pa);
        }
    }
}

