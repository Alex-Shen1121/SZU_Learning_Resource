2018151027:Problem1129:正确
#include <iostream>
using namespace std;

//类定义
class Ncard
{
protected:
    string id;
    char name;
    int balance;
public:
    virtual void initialize(string id, char n, int b);
    int deposit(int x);
    virtual int withdraw(int x);
    virtual void info();
    //virtual void show(Ncard &obj);
};
class Tcard: public Ncard
{
protected:
    int travelbalance;
public:
    int transfer(int g);
    void info();
    void initialize(string id,char name,int balance,int tbalance);
};
class Vcard: public Ncard
{
protected:
    int credit;
public:
    int over(int g);
    int withdraw(int g);
    void info();
    void initialize(string id,char name,int balance,int credit);
};

//类实现
void Ncard::initialize(string i, char n, int b)
{
    id=i;
    name=n;
    balance=b;
}
int Ncard::deposit(int g)
{
    if(g<0)
        return -1;
    else
        balance+=g;
    return 1;
}
int Ncard::withdraw(int g)
{
    if(g>balance||g<0)
        return -1;
    else
        balance-=g;
    return 1;
}
void Ncard::info()
{
    cout<<id<<"-"<<name<<"-" <<balance<<endl;
}
void Tcard::initialize(string i,char n,int b,int t)
{
    id=i;
    name=n;
    balance=b;
    travelbalance=t;
}
int Tcard::transfer(int g)
{
    if(g>balance||g<0)
        return -1;
    else
    {
        balance-=g;
        travelbalance+=g;
        return 1;
    }
}
void Tcard::info()
{
    cout<<id<<"-"<<name<<"-" <<balance<<"-"<<travelbalance<<endl;
}
void Vcard::initialize(string i,char n,int b,int c)
{
    id=i;
    name=n;
    balance=b;
    credit=c;
}
int Vcard::over(int g)
{
    if(g>credit)
        return -1;
    else
    {
        g=g-balance;
        balance=0;
        credit-=g;
    }
    return 1;
}
int Vcard::withdraw(int x)
{
    if(x>credit+balance||x<0)
        return -1;
    else if(x>balance)
        over(x);
    else
        balance-=x;
    return 1;
}
void Vcard::info()
{
    cout<<id<<"-"<<name<<"-" <<balance<<"-"<<credit<<endl;
}
void show(Ncard &obj)
{
    obj.info();
}

//主函数
main()
{
    string id;
    char name;
    int balance,credit,tbalance;
    int g1,g2,g3,g4;
    Ncard n;
    Tcard t;
    Vcard v;
    cin>>id>>name>>balance;
    n.initialize(id,name,balance);
    cin>>id>>name>>balance>>tbalance;
    t.initialize(id,name,balance,tbalance);
    cin>>id>>name>>balance>>credit;
    v.initialize(id,name,balance,credit);
    cin>>g1>>g2>>g3>>g4;
    n.deposit(g1);
    n.deposit(g2);
    n.withdraw(g3);
    n.withdraw(g4);
    cin>>g1>>g2>>g3>>g4;
    t.deposit(g1);
    t.withdraw(g2);
    t.transfer(g3);
    t.transfer(g4);
    cin>>g1>>g2>>g3>>g4;
    v.deposit(g1);
    v.withdraw(g2);
    v.over(g3);
    v.over(g4);
    show(n);
    show(t);
    show(v);

}

