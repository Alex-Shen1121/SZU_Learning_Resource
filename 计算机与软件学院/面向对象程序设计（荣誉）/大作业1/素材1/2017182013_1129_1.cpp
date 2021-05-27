2017182013:Problem1129:ÕýÈ·
#include <bits/stdc++.h>

using namespace std;

class CNormal
{
protected:
    string id;
    string name;
    int counter;
public:
    CNormal(string ID,string n,int c):id(ID),name(n),counter(c){}
    int  save(int m)
    {
        if(m<=0)
            return -1;
        counter += m;
        return 1;
    }
    virtual int take(int m)
    {
        if(m<=0)
            return -1;
        if(counter>=m)
        {
            counter -= m;
            return 1;
        }
        else
            return -1;
    }
    virtual void info()
    {
        cout<<id<<"-"<<name<<"-"<<counter<<endl;
    }
};
class CTraffic:public CNormal
{
    int Tcounter;
public:
    CTraffic(string ID,string n,int c,int t):CNormal(ID,n,c),Tcounter(t){}
    int transfer(int m)
    {
        if(m<=0)
            return -1;
        if(counter>=m)
        {
            counter -= m;
            Tcounter += m;
            return 1;
        }
        else
            return -1;
    }
    void info()
    {
        cout<<id<<"-"<<name<<"-"<<counter<<"-"<<Tcounter<<endl;
    }
};
class VIP:public CNormal
{
    int credit;
public:
    VIP(string ID,string n,int c,int cr):CNormal(ID,n,c),credit(cr){}
    int  over(int m)
    {
        if(m<=0)
            return -1;
        if(counter+credit>=m && counter<m)
        {
            credit = credit+counter-m;
            counter = 0;
            return 1;
        }
        else
            return -1;
    }
    void info()
    {
        cout<<id<<"-"<<name<<"-"<<counter<<"-"<<credit<<endl;
    }
};

void show(CNormal &obj)
{
    obj.info();
}
int main()
{
    string id,name;
    int counter,tcounter,credit;
    cin>>id>>name>>counter;
    CNormal n(id,name,counter);

    cin>>id>>name>>counter>>tcounter;
    CTraffic t(id,name,counter,tcounter);

    cin>>id>>name>>counter>>credit;
    VIP v(id,name,counter,credit);

    int m1,m2,m3,m4,m;
    cin>>m1>>m2>>m3>>m4;
    m = n.save(m1);
    m = n.save(m2);
    m = n.take(m3);
    m = n.take(m4);

    cin>>m1>>m2>>m3>>m4;
    m = t.save(m1);
    m = t.take(m2);
    m = t.transfer(m3);
    m = t.transfer(m4);

    cin>>m1>>m2>>m3>>m4;
    m = v.save(m1);
    m = v.take(m2);
    m = v.over(m3);
    m = v.over(m4);

    show(n);
    show(t);
    show(v);

    return 0;
}

