2018152010:Problem1129:ÕýÈ·
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
class Card
{
protected:
    string ID,CName;
    float balance;
public:
    Card(string id,string name,float bal):ID(id),CName(name),balance(bal){}
    int Save(float money)
    {
        if(money>0)
        {
            balance=balance+money;
            return 1;
        }
        else
            return -1;
    }
    int Take(float money)
    {
        if(money<=balance&&money>0)
        {
            balance=balance-money;
            return 1;
        }
        else
            return -1;
    }
    virtual void Info()
    {
        cout<<ID<<'-'<<CName<<'-'<<balance<<endl;
    }
};

class TrafficCard:public Card
{
    float Tcounter;
public:
    TrafficCard(string id,string name,float bal,float t):Card(id,name,bal),Tcounter(t){}
    int Transfer(float money)
    {
        if(money>balance||money<0)
            return -1;
        else
        {
            Tcounter=Tcounter+money;
            balance=balance-money;
            return 1;
        }
    }
    void Info()
    {
        cout<<ID<<'-'<<CName<<'-'<<balance<<'-'<<Tcounter<<endl;
    }
};


class Upcard:public Card
{
    float Credit;
public:
    Upcard(string id,string name,float bal,float cr):Card(id,name,bal),Credit(cr){}
    int Take(float money)
    {
        if(money>balance&&money>0)
        {
            return over(money);
        }
        else if(money>0)
        {
            balance=balance-money;
            return 1;
        }
        else
            return -1;
    }
    int over(float money)
    {
        if(money<balance+Credit&&money>0)
        {
            Credit=Credit-(money-balance);
            balance=0;
            return 1;
        }
        else
            return -1;
    }
    void Info()
    {
        cout<<ID<<'-'<<CName<<'-'<<balance<<'-'<<Credit<<endl;
    }
};

void info(Card &s)
{
    s.Info();
}
int main()
{
     string ID,name;
     float balance,money,Cre,trans,m1,m2,m3,m4;
     int x;
     cin>>ID>>name>>balance;
     Card C1(ID,name,balance);
     cin>>ID>>name>>balance>>trans;
     TrafficCard C2(ID,name,balance,trans);
     cin>>ID>>name>>balance>>Cre;
     Upcard C3(ID,name,balance,Cre);
     cin>>m1>>m2>>m3>>m4;
     x=C1.Save(m1);
     x=C1.Save(m2);
     x=C1.Take(m3);
     x=C1.Take(m4);
     cin>>m1>>m2>>m3>>m4;
     x=C2.Save(m1);
     x=C2.Take(m2);
     x=C2.Transfer(m3);
     x=C2.Transfer(m4);
     cin>>m1>>m2>>m3>>m4;
     x=C3.Save(m1);
     x=C3.Take(m2);
     x=C3.over(m3);
     x=C3.over(m4);
     info(C1);
     info(C2);
     info(C3);
}

