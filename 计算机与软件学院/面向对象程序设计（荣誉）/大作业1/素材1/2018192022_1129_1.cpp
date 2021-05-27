2018192022:Problem1129:ÕýÈ·
#include <iostream>
#include <iomanip>
#include <cstring>
#define PI 3.14
using namespace std;
class NCard
{
protected:
    string ID;
    char CName;
    double balance;
public:
    NCard(){}
    NCard(string a,char b, double c):ID(a),CName(b),balance(c){}
    virtual void initial(string a,char b, double c)
    {
        ID=a;
        CName=b;
        balance=c;
    }
    bool judge(double x)
    {
        int n;
        n=(int)x;
        n=(double)n;
        if(x-n!=0)
            return false;
        else
            return true;
    }
    virtual int save(double x)
    {
        if(x<=0||!judge(x))
            return -1;
        else
        {
            balance+=x;
            return 1;
        }
    }
    virtual int take(double x)
    {
        if(x<=0||!judge(x))
            return -1;
        else if(x>balance)
            return -1;
        else
        {
            balance-=x;
            return 1;
        }
    }
    virtual void info()
    {
        cout<<ID<<"-"<<CName<<"-"<<balance<<endl;
    }
};
class TrafficCard:public NCard
{
protected:
    double Tbalance;
public:
    TrafficCard(){}
    TrafficCard(string a,char b, double c,double d)
    {
        ID=a;
        CName=b;
        balance=c;
        Tbalance=d;
    }
    int transfer(double x)
    {
        if(x<=0||!judge(x))
            return -1;
        else if(x>balance)
            return -1;
        else
        {
            balance-=x;
            Tbalance+=x;
            return 1;
        }
    }
    void initial(string a,char b, double c,double d)
    {
        ID=a;
        CName=b;
        balance=c;
        Tbalance=d;
    }
    void info()
    {
        cout<<ID<<"-"<<CName<<"-"<<balance<<"-"<<Tbalance<<endl;
    }
};
class VIPCard:public NCard
{
protected:
    double credit;
public:
    VIPCard(){}
    VIPCard(string a,char b, double c,double d)
    {
        ID=a;
        CName=b;
        balance=c;
        credit=d;
    }
    void initial(string a,char b, double c,double d)
    {
        ID=a;
        CName=b;
        balance=c;
        credit=d;
    }
    int over(double x)
    {
        if(x<=0||!judge(x))
            return -1;
        else if(x>balance+credit)
            return -1;
        else if(x<=balance)
        {
            balance-=x;
            return 1;
        }
        else
        {
            credit-=(x-balance);
            balance=0;
            return 1;
        }
    }
    void info()
    {
        cout<<ID<<"-"<<CName<<"-"<<balance<<"-"<<credit<<endl;
    }
};
void show(NCard& obj)
{
    obj.info();
}
int main()
{
    string ID1,ID2,ID3;
    char name1,name2,name3;
    double balance1,balance2,balance3,Trafficbalance,credit;
    cin>>ID1>>name1>>balance1
        >>ID2>>name2>>balance2>>Trafficbalance
        >>ID3>>name3>>balance3>>credit;
    NCard p1;
    TrafficCard p2;
    VIPCard p3;
    p1.initial(ID1,name1,balance1);
    p2.initial(ID2,name2,balance2,Trafficbalance);
    p3.initial(ID3,name3,balance3,credit);
    double a1,b1,c1,d1;
    double a2,b2,c2,d2;
    double a3,b3,c3,d3;
    cin>>a1>>b1>>c1>>d1
        >>a2>>b2>>c2>>d2
        >>a3>>b3>>c3>>d3;
    p1.save(a1);
    p1.save(b1);
    p1.take(c1);
    p1.take(d1);
    show(p1);
    p2.save(a2);
    p2.take(b2);
    p2.transfer(c2);
    p2.transfer(d2);
    show(p2);
    p3.save(a3);
    p3.take(b3);
    p3.over(c3);
    p3.over(d3);
    show(p3);
    return 0;
}
