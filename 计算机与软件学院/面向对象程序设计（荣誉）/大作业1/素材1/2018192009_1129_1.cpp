2018192009:Problem1129:ÕýÈ·
#include <iostream>
#include <cmath>
using namespace std;
class normal
{
protected:
    int id;
    string CName;
    int counter;
public:
    normal(){}
    normal(int d,string name,int c):id(d),CName(name),counter(c){}
    void initial(){}
    int save(int money)
    {
        if(money<0)
            return -1;
        counter+=money;
        return 1;
    }
    int take(int money)
    {
        if(money>counter||money<0)
            return -1;
        counter-=money;
        return 1;
    }
    virtual void info()
    {
        cout<<id<<"-"<<CName<<"-"<<counter<<endl;
    }
};
class tran:public normal
{
    int tcounter;
public:
    tran(int d,string name,int c,int tc):normal(d,name,c),tcounter(tc){}
    int transfer(int money)
    {
        if(money>counter)
            return -1;
        counter-=money;
        tcounter+=money;
        return 1;
    }
    virtual void info()
    {
        cout<<id<<"-"<<CName<<"-"<<counter<<"-"<<tcounter<<endl;
    }
};
class credit:public normal
{
    int limit;
public:
    credit(int d,string name,int c,int tc):normal(d,name,c),limit(tc){}
    int over(int money)
    {
        if(money>counter+limit)
            return -1;
        counter-=money;
        limit+=counter;
        counter=0;
        return 1;
    }
    virtual void info()
    {
        cout<<id<<"-"<<CName<<"-"<<counter<<"-"<<limit<<endl;
    }
};
void show(normal &a)
{
    a.info();
}
int main()
{
    int id,counter;
    string name;
    int tc,limit;
    int money;

    cin>>id>>name>>counter;
    normal a(id,name,counter);
    cin>>id>>name>>counter>>tc;
    tran b(id,name,counter,tc);
    cin>>id>>name>>counter>>limit;
    credit c(id,name,counter,limit);

    cin>>money;
    a.save(money);
    cin>>money;
    a.save(money);
    cin>>money;
    a.take(money);
    cin>>money;
    a.take(money);

    cin>>money;
    b.save(money);
    cin>>money;
    b.take(money);
    cin>>money;
    b.transfer(money);
    cin>>money;
    b.transfer(money);

    cin>>money;
    c.save(money);
    cin>>money;
    c.take(money);
    cin>>money;
    c.over(money);
    cin>>money;
    c.over(money);

    show(a);
    show(b);
    show(c);
    return 0;
}

