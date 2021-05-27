2018192024:Problem1129:ÕýÈ·
#include <iostream>

using namespace std;

class normalCard
{
protected:
    int id,Counter;
    string CName;
public:
    normalCard(){}
    void initial(int i,int c,string n){id=i;Counter=c;CName=n;}
    int take(int money)
    {
        if(money<0)
            return -1;
        if(Counter<money)
            return -1;
        Counter-=money;
        return 1;
    }
    int save(int money)
    {
        if(money<0)
            return -1;
        Counter+=money;
        return 1;
    }
    virtual void info()
    {
        cout<<id<<"-"<<CName<<"-"<<Counter<<endl;
    }
    friend void show(normalCard &obj);
};
class transCard:public normalCard
{
    int Tcounter;
public:
    void initial(int i,int c,string n,int t){id=i;Counter=c;CName=n;Tcounter=t;}
    int transfer(int money)
    {
        if(money<0)
            return -1;
        if(money>Counter)
            return -1;
        Counter-=money;
        Tcounter+=money;
        return 1;
    }
    virtual void info()
    {
        cout<<id<<"-"<<CName<<"-"<<Counter<<"-"<<Tcounter<<endl;
    }
    friend void show(normalCard &obj);
};
class vipCard:public normalCard
{
    int Credict;
public:
    void initial(int i,int c,string n,int t){id=i;Counter=c;CName=n;Credict=t;}
    int over(int money)
    {
        if(money<0)
            return -1;
        if(money>Counter+Credict)
            return -1;
        if(money>Counter)
        {
            Credict-=money-Counter;
            Counter=0;
        }
        else
            Counter-=money;
        return 1;
    }
    virtual void info()
    {
        cout<<id<<"-"<<CName<<"-"<<Counter<<"-"<<Credict<<endl;
    }
    friend void show(normalCard &obj);
};
void show(normalCard &obj)
{
    obj.info();
}

int main()
{
    int i1,c1,i2,c2,t2,i3,c3,t3;
    string n1,n2,n3;
    cin>>i1>>n1>>c1;
    normalCard card1;
    card1.initial(i1,c1,n1);
    cin>>i2>>n2>>c2>>t2;
    transCard card2;
    card2.initial(i2,c2,n2,t2);
    cin>>i3>>n3>>c3>>t3;
    vipCard card3;
    card3.initial(i3,c3,n3,t3);
    int m1,m2,m3,m4;
    cin>>m1>>m2>>m3>>m4;
    card1.save(m1);
    card1.take(m2);
    card1.save(m3);
    card1.take(m4);
    show(card1);
    cin>>m1>>m2>>m3>>m4;
    card2.save(m1);
    card2.take(m2);
    card2.transfer(m3);
    card2.transfer(m4);
    show(card2);
    cin>>m1>>m2>>m3>>m4;
    card3.save(m1);
    card3.take(m2);
    card3.over(m3);
    card3.over(m4);
    show(card3);
   return 0;
}

