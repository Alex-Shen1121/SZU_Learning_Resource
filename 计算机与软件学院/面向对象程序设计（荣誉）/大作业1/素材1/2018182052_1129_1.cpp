2018182052:Problem1129:ÕýÈ·
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <iomanip>
#define ADDRESS "C:\\Users\\241\\Desktop\\in.txt","r",stdin
using namespace std;
class Card
{
protected:
    string ID;
    char CName;
    int balance;
public:
    Card() {}
    Card(const string& i,char n,int b):ID(i),CName(n),balance(b) {}
    void initial(const string& i,char n,int b)
    {
        ID=i;
        CName=n;
        balance=b;
    }
    int save(int am)
    {
        if(am<=0)
            return -1;
        balance+=am;
        return 1;
    }
    int take(int am)
    {
        if(am>balance||am<=0)
            return -1;
        balance-=am;
        return 1;
    }
    virtual void info()const
    {
        cout<<ID<<"-"<<CName<<"-"<<balance<<endl;
    }
};
class Tcard:public Card
{
protected:
    int Tcounter;
public:
    Tcard() {}
    Tcard(const string& i,char n,int b,int c):Card(i,n,b),Tcounter(c) {}
    int transfer(int am)
    {
        if(am<=0||am>balance)
            return -1;
        balance-=am;
        Tcounter+=am;
        return 1;
    }
    virtual void info()const
    {
        cout<<ID<<"-"<<CName<<"-"<<balance<<"-"<<Tcounter<<endl;
    }
};
class VIPcard:public Card
{
protected:
    int Credit;
public:
    VIPcard() {}
    VIPcard(const string& i,char n,int b,int c):Card(i,n,b),Credit(c) {}
    int over(int am)
    {
        if(am<=balance||am>balance+Credit)
            return -1;
        am-=balance;
        balance=0;
        Credit-=am;
    }
    virtual void info()const
    {
        cout<<ID<<"-"<<CName<<"-"<<balance<<"-"<<Credit<<endl;
    }

};
void show(Card& obj)
{
    obj.info();
}
int main()
{
//    freopen(ADDRESS);
    string ID;
    char ch(0);
    int balance(0);
    int other(0);
    cin>>ID>>ch>>balance;
    Card a(ID,ch,balance);
    cin>>ID>>ch>>balance>>other;
    Tcard b(ID,ch,balance,other);
    cin>>ID>>ch>>balance>>other;
    VIPcard c(ID,ch,balance,other);

    int d[4];
    cin>>d[0]>>d[1]>>d[2]>>d[3];
    a.save(d[0]);
    a.save(d[1]);
    a.take(d[2]);
    a.take(d[3]);
    cin>>d[0]>>d[1]>>d[2]>>d[3];
    b.save(d[0]);
    b.take(d[1]);
    b.transfer(d[2]);
    b.transfer(d[3]);
    cin>>d[0]>>d[1]>>d[2]>>d[3];
    c.save(d[0]);
    c.take(d[1]);
    c.over(d[2]);
    c.over(d[3]);

    show(a);
    show(b);
    show(c);

    return 0;
}

