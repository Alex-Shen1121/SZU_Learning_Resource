2018151020:Problem1234:±‡“Î¥ÌŒÛ
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;
class OrdinaryCard
{
protected:
    string CName;
    int ID;
    double Counter;
public:
    OrdinaryCard(string na,int id,double balance)
    :CName(na),ID(id),Counter(balance){}

    void initial(string na,int id,double balance)
    {
        CName = na;
        ID = id;
        Counter = balance;
    }
    int save(double money)
    {
        if(money<0)
            return -1;
        Counter+=money;
        return 1;
    }
    int take(double money)
    {
        if(money<0)
            return -1;
        if(Counter<money)
            return -1;
        else
            return 1;
    }
    virtual void info()
    {
        cout<<ID<<"-"<<CName<<"-"<<Counter<<endl;
    }
    virtual int transfer(double money);
    virtual int over(double money);

};
class TrafficCard:public OrdinaryCard
{
protected:
    double Tcounter;
public:
    TrafficCard(string na,int id,double balance,double tfc):OrdinaryCard(na,id,balance),Tcounter(tfc){}
    int transfer(double money)
    {
        if(money<0)
            return -1;
        if(money>Counter)
            return -1;
        Tcounter+=money;
        Counter-=money;
        return 1;
    }
    void info()
    {
        cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Tcounter<<endl;
    }
};
class VipCard:public OrdinaryCard
{
protected:
    double credit;
public:
    VipCard(string na,int id,double balance,double belief):OrdinaryCard(na,id,balance),credit(belief){}
    int over(double money)
    {
        if(money>credit+Counter)
            return -1;
        else
        {
            if(money>Counter)
            {
                money-=Counter;
                Counter=0;
                credit-=money;
            }
            else
            {
                Counter-=money;
            }
        }
    }
    void info()
    {
        cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<credit<<endl;
    }
};
void show(OrdinaryCard &obj)
{
    obj.info();
}
int main()
{
    int id;
    string na;
    double co,Tco,over;
    cin>>id>>na>>co;
    OrdinaryCard Ocard(na,id,co);
    cin>>id>>na>>co>>Tco;
    TrafficCard Tcard(na,id,co,Tco);
    cin>>id>>na>>co>>over;
    VipCard Vcard(na,id,co,over);

    double m1,m2,m3,m4;
    cin>>m1>>m2>>m3>>m4;
    OrdinaryCard *K;
    K = &Ocard;
    K->save(m1);
    K->save(m2);
    K->take(m3);
    K->take(m4);

    cin>>m1>>m2>>m3>>m4;
    K = &Tcard;
    K->save(m1);
    K->take(m2);
    K->transfer(m3);
    K->transfer(m4);

    cin>>m1>>m2>>m3>>m4;
    K = &Vcard;
    K->save(m1);
    K->take(m2);
    K->over(m3);
    K->over(m4);
    return 0;
}

