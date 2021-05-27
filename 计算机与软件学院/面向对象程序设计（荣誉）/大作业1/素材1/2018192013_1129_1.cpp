2018192013:Problem1129:ÕýÈ·
#include <iostream>
using namespace std;

class NCard
{
protected:
    int ID,Counter;
    string CName;
public:
    NCard(int id=0,string n="",int c=0):ID(id),CName(n),Counter(c){}
    int save(int a)
    {
        if(a>0)
            Counter+=a;
        else
            return -1;
        return 1;
    }
    int take(int a)
    {
        if(a>0&&a<=Counter)
            Counter-=a;
        else
            return -1;
        return 1;
    }
    virtual void info()
    {
        cout<<ID<<"-"<<CName<<"-"<<Counter<<endl;
    }
};

class TCard:public NCard
{
    int Tcounter;
public:
    TCard(int id=0,string n="",int c=0,int tc=0):NCard(id,n,c),Tcounter(tc){}
    int transfer(int a)
    {
        if(a>0&&a<=Counter)
        {
            Counter-=a;
            Tcounter+=a;
        }
        else
            return -1;
        return 1;
    }
    void info()
    {
        cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Tcounter<<endl;
    }
};

class VIPCard:public NCard
{
    int Credit;
public:
    VIPCard(int id=0,string n="",int c=0,int cre=0):NCard(id,n,c),Credit(cre){}
    int over(int a)
    {
        if(a>Counter&&a<=Counter+Credit)
        {
            Credit-=(a-Counter);
            Counter=0;
        }
        else
            return -1;
        return 1;
    }
    void info()
    {
        cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Credit<<endl;
    }
};

void show(NCard &obj)
{
    obj.info();
}

int main()
{
    int id1,id2,id3,counter1,counter2,counter3,Tcounter,credit;
    string name1,name2,name3;
    NCard c1;
    TCard c2;
    VIPCard c3;
    cin>>id1>>name1>>counter1;
    cin>>id2>>name2>>counter2>>Tcounter;
    cin>>id3>>name3>>counter3>>credit;
    c1=NCard(id1,name1,counter1);
    c2=TCard(id2,name2,counter2,Tcounter);
    c3=VIPCard(id3,name3,counter3,credit);

    int a1,a2,a3,a4;
    cin>>a1>>a2>>a3>>a4;
    c1.save(a1);
    c1.save(a2);
    c1.take(a3);
    c1.take(a4);
    cin>>a1>>a2>>a3>>a4;
    c2.save(a1);
    c2.take(a2);
    c2.transfer(a3);
    c2.transfer(a4);
    cin>>a1>>a2>>a3>>a4;
    c3.save(a1);
    c3.take(a2);
    c3.over(a3);
    c3.over(a4);

    show(c1);
    show(c2);
    show(c3);

    return 0;
}

