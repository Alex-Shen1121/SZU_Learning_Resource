2018192043:Problem1129:ÕýÈ·
#include <iostream>
#include <cmath>
using namespace std;
class Ncard
{
protected:
    string ID,CName;
    int Counter;
public:
    virtual void initial(string IDs,string CNames,int Counters)
    {
        ID=IDs;
        CName=CNames;
        Counter=Counters;
    }
    int save(int m)
    {
        if(m<=0)
            return -1;
        Counter+=m;
        return 1;
    }
    int take(int m)
    {
        if(m<=0 || Counter-m<0)
            return -1;
        Counter-=m;
        return 1;
    }
    virtual void info()
    {
        cout<<ID<<"-"<<CName<<"-"<<Counter<<endl;
    }
};
class TCard:public Ncard
{
    int Tcounter;
public:
    void initial(string IDs,string CNames,int Counters,int Tcounters)
    {
        ID=IDs;
        CName=CNames;
        Counter=Counters;
        Tcounter=Tcounters;
    }
    int transfer(int m)
    {
        if(m<0 || Counter-m<0)
            return -1;
        Counter-=m;
        Tcounter+=m;
        return 1;
    }
    void info()
    {
        cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Tcounter<<endl;
    }
};
class VCard:public Ncard
{
    int Credit;
public:
    void initial(string IDs,string CNames,int Counters,int Credits)
    {
        ID=IDs;
        CName=CNames;
        Counter=Counters;
        Credit=Credits;
    }
    int over(int m)
    {
        if(m<0 || Counter+Credit-m<0)
            return -1;
        Credit+=Counter-m;
        Counter=0;
        return 1;
    }
    void info()
    {
        cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Credit<<endl;
    }
};
void show(Ncard &obj)
{
    obj.info();
}
int main()
{
    string ID,CName;
    int Counter,Tcounter,Credit,m;
    Ncard x1;
    TCard x2;
    VCard x3;
    cin>>ID>>CName>>Counter;
    x1.initial(ID,CName,Counter);
    cin>>ID>>CName>>Counter>>Tcounter;
    x2.initial(ID,CName,Counter,Tcounter);
    cin>>ID>>CName>>Counter>>Credit;
    x3.initial(ID,CName,Counter,Credit);
    cin>>m;
    x1.save(m);
    cin>>m;
    x1.save(m);
    cin>>m;
    x1.take(m);
    cin>>m;
    x1.take(m);
    cin>>m;
    x2.save(m);
    cin>>m;
    x2.take(m);
    cin>>m;
    x2.transfer(m);
    cin>>m;
    x2.transfer(m);
    cin>>m;
    x3.save(m);
    cin>>m;
    x3.take(m);
    cin>>m;
    x3.over(m);
    cin>>m;
    x3.over(m);
    show(x1);
    show(x2);
    show(x3);
    return 0;
}

