2018152035:Problem1129:ÕýÈ·
#include <iostream>
#include<stdio.h>
#include<string>
#include<iomanip>
using namespace std;

class commoncard
{
protected:
    int id;
    char name;
    int balance;
public:
    commoncard(int i,char n,int b):id(i),name(n),balance(b) {}
    virtual int save(int m)
    {
        if(m>0)
        {
            balance+=m;
            return 1;
        }
        else
            return -1;
    }
    virtual int take(int m)
    {
        if(m>0)
        {
            if(balance-m>0)
            {
                balance-=m;
                return 1;
            }
            else
                return -1;
        }
        else
            return -1;
    }
    virtual void info()
    {
        cout<<id<<'-'<<name<<'-'<<balance<<endl;
    }
};
class transportcard:public commoncard
{
    int Tcounter;
public:
    transportcard(int i,char n,int b,int t):commoncard(i,n,b),Tcounter(t) {}
    int transfer(int m)
    {
        if(m>0)
        {
            if(m<=balance)
            {
                balance-=m;
                Tcounter+=m;
                return 1;
            }
            else
                return -1;
        }
        else
            return -1;
    }
    void info()
    {
        cout<<id<<'-'<<name<<'-'<<balance<<'-'<<Tcounter<<endl;
    }
};
class vipcard:public commoncard
{
    int Credit;
public:
    vipcard(int i,char n,int b,int c):commoncard(i,n,b),Credit(c) {}
    int over(int m)
    {
        if(m>0)
        {
            if(balance+Credit>=m)
            {
                Credit-=(m-balance);
                balance=0;
                return 1;
            }
            else
                return -1;
        }
        else
            return -1;
    }
    void info()
    {
        cout<<id<<'-'<<name<<'-'<<balance<<'-'<<Credit<<endl;
    }
};
int main()
{
    //freopen("C:\\Users\\241\\Desktop\\1.txt","r",stdin);
    int id,b,c,t,num;
    char name;
    commoncard *p;
    cin>>id>>name>>b;
    commoncard a(id,name,b);
    cin>>id>>name>>b>>t;
    transportcard aa(id,name,b,t);
    cin>>id>>name>>b>>c;
    vipcard aaa(id,name,b,c);

    p=&a;
    cin>>num;
    p->save(num);
    cin>>num;
    p->save(num);
    cin>>num;
    p->take(num);
    cin>>num;
    p->take(num);
    p->info();

    p=&aa;
    cin>>num;
    p->save(num);
    cin>>num;
    p->take(num);
    cin>>num;
    aa.transfer(num);
    cin>>num;
    aa.transfer(num);
    p->info();

    p=&aaa;
    cin>>num;
    p->save(num);
    cin>>num;
    p->take(num);
    cin>>num;
    aaa.over(num);
    cin>>num;
    aaa.over(num);
    p->info();

}

