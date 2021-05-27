2018151058:Problem1129:正确
#include<iostream>
using namespace std;
class comman
{
protected:
    int num;
    char name;
    int balance;
public:
    comman() {};
    void initial(int n1, char n2, int b);
    virtual int save(int a);
    virtual int take(int a);
    virtual void check();

};
class Trancard: public comman
{
protected:
    int tran_balance;
public:
    Trancard() {};
    void initial(int n1, char n2, int b, int t);
    int save(int a);
    int take(int a);
    void check();
    int transfer(int a);

};
class Vipcard: public comman
{
protected:
    int limit;
public:
    Vipcard() {};
    void initial(int n1, char n2, int b, int t);
    int save(int a);
    int take(int a);
    void check();
    int over(int a);
};
//普通类实现
void comman::initial(int n1, char n2, int b)
{
    num = n1;
    name = n2;
    balance = b;
}
int comman::save(int a)
{
    if(a < 0)
        return -1;
    else
        balance += a;
    return 1;
}
int comman::take(int a)
{
     if(a > balance||a<0)
        return -1;
    else
        balance -= a;
    return 1;
}
void comman::check()
{
    cout << num << "-" << name << "-" << balance << endl;
}
//交通卡类实现
void Trancard::initial(int n1, char n2, int b, int t)
{
    num = n1;
    name = n2;
    balance = b;
    tran_balance = t;
}
int Trancard::save(int a)
{
    if(a < 0)
        return -1;
    else
        balance += a;
    return 1;
}
int Trancard::take(int a)
{
    if(a > balance||a<0)
        return -1;
    else
        balance -= a;
    return 1;
}
void Trancard::check()
{
    cout << num << "-" << name << "-" << balance << "-" << tran_balance << endl;
}
int Trancard::transfer(int a)
{
    if(a > balance)
        return 1;
    balance -= a;
    tran_balance += a;
    return 1;

}
//贵宾卡类实现
void Vipcard::initial(int n1, char n2, int b, int t)
{
    num = n1;
    name = n2;
    balance = b;
    limit = t;
}
int Vipcard::save(int a)
{
    if(a < 0)
        return -1;
    else
        balance += a;
    return 1;
}
int Vipcard::take(int a)
{
    if(a > balance||a<0)
        return -1;
    else
        balance -= a;
    return 1;
}
void Vipcard::check()
{
     cout << num << "-" << name << "-" << balance << "-" << limit << endl;
}
int Vipcard::over(int a)
{
    if(a>limit+balance)
        return -1;
    limit=limit-(a-balance);
    balance=0;
    return 1;
}
void show(comman &a)
{
    a.check();
}
int main()
{
    //输入并初始化
    int n1,b,t;
    char n2;
    comman c1;
    Trancard c2;
    Vipcard c3;
    cin>>n1>>n2>>b;
    c1.initial(n1,n2,b);
    cin>>n1>>n2>>b>>t;
    c2.initial(n1,n2,b,t);
    cin>>n1>>n2>>b>>t;
    c3.initial(n1,n2,b,t);
    //输入数据并按顺序操作
    int x,y,m,n;
    cin>>x>>y>>m>>n;
    c1.save(x);
    c1.save(y);
    c1.take(m);
    c1.take(n);
    cin>>x>>y>>m>>n;
    c2.save(x);
    c2.take(y);
    c2.transfer(m);
    c2.transfer(n);
    cin>>x>>y>>m>>n;
    c3.save(x);
    c3.take(y);
    c3.over(m);
    c3.over(n);
    //输出最终状态
    show(c1);
    show(c2);
    show(c3);
    return 0;
}

