2018152044:Problem1129:ÕýÈ·
#include<iostream>
#include<string>
using namespace std;
class normal
{
protected:
    int ID;
    string CName;
    int Counter;
public:
    normal()
    {
    }
    normal(int ID_,string CName_,int Counter_)
    {
        ID=ID_;
        CName=CName_;
        Counter=Counter_;
    }
    void initial(int ID_,string CName_,int Counter_)
    {
        ID=ID_;
        CName=CName_;
        Counter=Counter_;
    }
    int save(int x)
    {
        if(x<=0)
            return -1;
        Counter+=x;
        return 1;
    }
    int take(int x)
    {
        if(x<=0)
            return -1;
        if(Counter<x)
            return -1;
        Counter-=x;
        return 1;
    }
    virtual void info()
    {
        cout<<ID<<"-"<<CName<<"-"<<Counter<<endl;
    }
};

class trans:public normal
{
protected:
    int Tcounter;
public:
    trans()
    {
        Tcounter=0;
    }
    void initial(int ID_,string CName_,int Counter_,int x)
    {
        ID=ID_;
        CName=CName_;
        Counter=Counter_;
        Tcounter=x;
    }
    int transfer(int x)
    {
        if(x<=0)
            return -1;
        if(Counter<x)
            return -1;
        Counter-=x;
        Tcounter+=x;
        return 1;
    }
    virtual void info()
    {
        cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Tcounter<<endl;
    }
};
class VIP:public normal
{
protected:
    int Credit;
public:
    VIP()
    {
        Credit=0;
    }
    void initial(int ID_,string CName_,int Counter_,int x)
    {
        ID=ID_;
        CName=CName_;
        Counter=Counter_;
        Credit=x;
    }
    int over(int x)
    {
        if(Credit+Counter<x)
            return -1;
        if(Counter<x)
        {
            Credit=Credit+Counter-x;
            Counter=0;
            return 1;
        }
        Counter-=x;
        return 1;
    }
    virtual void info()
    {
        cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Credit<<endl;
    }
};

void show(normal &obj)
{
    obj.info();
}

int main()
{
    int ID;
    string name;
    int Counter;
    int x;
    cin>>ID>>name>>Counter;
    normal a;
    a.initial(ID,name,Counter);
    cin>>ID>>name>>Counter>>x;
    trans b;
    b.initial(ID,name,Counter,x);
    cin>>ID>>name>>Counter>>x;
    VIP c;
    c.initial(ID,name,Counter,x);
    int a1,b1,c1,d1;
    cin>>a1>>b1>>c1>>d1;
    a.save(a1);
    a.save(b1);
    a.take(c1);
    a.take(d1);
    show(a);
    cin>>a1>>b1>>c1>>d1;
    b.save(a1);
    b.take(b1);
    b.transfer(c1);
    b.transfer(d1);
    show(b);
    cin>>a1>>b1>>c1>>d1;
    c.save(a1);
    c.take(b1);
    c.over(c1);
    c.over(d1);
    show(c);
    return 0;
}
