2018192025:Problem1129:ÕýÈ·
#include<iostream>
#include<cstring>
using namespace std;
class NCard
{
protected:
    long number;
    string CName;
    int Counter;
public:
    virtual void initial(long num, string name, int counter)
    {
        number=num;
        CName=name;
        Counter=counter;
    }
    int save(int money)
    {
        if(money<=0)
            return -1;
        else
        {
            Counter+=money;
            return 1;
        }
    }
    int take(int money)
    {
        if(money<=0 || Counter-money<0)
            return -1;
        else
        {
            Counter-=money;
            return 1;
        }
    }
    virtual void info()
    {
        cout<<number<<'-'<<CName<<'-'<<Counter<<endl;
    }
};

class TCard:public NCard
{
protected:
    int Tcounter;
public:
    virtual void initial(long num, string name, int counter, int tcount)
    {
        number=num;
        CName=name;
        Counter=counter;
        Tcounter=tcount;
    }
    int transfer(int money)
    {
        if(money>Counter)
            return -1;
        else
        {
            Counter-=money;
            Tcounter+=money;
            return 1;
        }
    }
    virtual void info()
    {
        cout<<number<<'-'<<CName<<'-'<<Counter<<'-'<<Tcounter<<endl;
    }
};

class VIPCard:public NCard
{
protected:
    int Credit;
public:
    virtual void initial(long num, string name, int counter, int credit)
    {
        number=num;
        CName=name;
        Counter=counter;
        Credit=credit;
    }
    int over(int money)
    {
        if(money>Counter+Credit)
            return -1;
        else
        {
            Credit-=money-Counter;
            Counter=0;
            return 1;
        }
    }
    virtual void info()
    {
        cout<<number<<'-'<<CName<<'-'<<Counter<<'-'<<Credit<<endl;
    }
};

void show(NCard &obj)
{
    obj.info();
}

int main()
{
    int operate1,operate2,operate3,operate4;
    int counter1,counter2,counter3,tcount,credit;
    long num1,num2,num3;
    string name1,name2,name3;

    cin>>num1>>name1>>counter1;
    cin>>num2>>name2>>counter2>>tcount;
    cin>>num3>>name3>>counter3>>credit;

    NCard ss1;
    TCard ss2;
    VIPCard ss3;
    ss1.initial(num1,name1,counter1);
    ss2.initial(num2,name2,counter2,tcount);
    ss3.initial(num3,name3,counter3,credit);

    cin>>operate1>>operate2>>operate3>>operate4;
    if(ss1.save(operate1)==1);
    if(ss1.save(operate2)==1);
    if(ss1.take(operate3)==1);
    if(ss1.take(operate4)==1);

    cin>>operate1>>operate2>>operate3>>operate4;
    if(ss2.save(operate1)==1);
    if(ss2.take(operate2)==1);
    if(ss2.transfer(operate3)==1);
    if(ss2.transfer(operate4)==1);

    cin>>operate1>>operate2>>operate3>>operate4;
    if(ss3.save(operate1)==1);
    if(ss3.take(operate2)==1);
    if(ss3.over(operate3)==1);
    if(ss3.over(operate4)==1);

    show(ss1);
    show(ss2);
    show(ss3);

    return 0;
}

