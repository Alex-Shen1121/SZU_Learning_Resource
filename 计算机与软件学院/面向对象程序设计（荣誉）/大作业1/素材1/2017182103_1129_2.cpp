2017182103:Problem1129:ÕýÈ·
#include <bits/stdc++.h>
using namespace std;

class Putong
{
protected:
    int ID,Counter;
    char CName;
public:
    Putong() {}
    Putong(int i,char n,int c):ID(i),CName(n),Counter(c) {}
    void initial(int i,char n,int c)
    {
        ID = i;
        CName =n;
        Counter = c;
    }
    int save(int m)
    {
        if(m<=0)
            return -1;
        else
            Counter += m;
        return 1;
    }
    int take(int m)
    {
        if(m<=0||m>Counter)
            return -1;
        else
            Counter -= m;
        return 1;
    }
    virtual void info()
    {
        cout<<ID<<"-"<<CName<<"-"<<Counter<<endl;
    }
};

class Jiaotong:public Putong
{
    int Tcounter;
public:
    Jiaotong() {}
    Jiaotong(int i,char n,int c,int t):Putong(i,n,c),Tcounter(t) {}
    void initial(int i,char n,int c,int t)
    {
        ID = i;
        CName =n;
        Counter = c;
        Tcounter = t;
    }
    int transfer(int m)
    {
        if(m>Counter)
            return -1;
        else
        {
            Counter -= m;
            Tcounter += m;
            return 1;
        }
    }
    void info()
    {
        cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Tcounter<<endl;
    }
};

class Guibin:public Putong
{
    int Credit;
public:
    Guibin() {}
    Guibin(int i,char n,int c,int cre):Putong(i,n,c),Credit(cre) {}
    void initial(int i,char n,int c,int cre)
    {
        ID = i;
        CName =n;
        Counter = c;
        Credit = cre;
    }
    int over(int m)
    {
        if(m>Counter+Credit)
            return -1;
        else
        {
            Credit -= (m-Counter);
            Counter = 0;
            return 1;
        }
    }

    void info()
    {
        cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Credit<<endl;
    }
};

void show(Putong &obj)
{
    obj.info();
}

int main()
{
    int i1,i2,i3,c1,c2,c3,t,c;
    int m1,m2,m3,m4,m5,m6,m7,m8,m9,m10,m11,m12;
    char n1,n2,n3;

    Putong p;
    Jiaotong j;
    Guibin g;

    cin>>i1>>n1>>c1;
    cin>>i2>>n2>>c2>>t;
    cin>>i3>>n3>>c3>>c;

    p.initial(i1,n1,c1);
    j.initial(i2,n2,c2,t);
    g.initial(i3,n3,c3,c);

    cin>>m1>>m2>>m3>>m4;
    p.save(m1);
    p.save(m2);
    p.take(m3);
    p.take(m4);

    cin>>m5>>m6>>m7>>m8;
    j.save(m5);
    j.take(m6);
    j.transfer(m7);
    j.transfer(m8);

    cin>>m9>>m10>>m11>>m12;
    g.save(m9);
    g.take(m10);
    g.over(m11);
    g.over(m12);

    show(p);
    show(j);
    show(g);


    return 0;
}

