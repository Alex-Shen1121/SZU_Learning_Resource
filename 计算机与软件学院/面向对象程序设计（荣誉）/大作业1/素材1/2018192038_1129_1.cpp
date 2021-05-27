2018192038:Problem1129:正确
#include <iostream>

using namespace std;

class NCard
{
protected:
    int ID;
    char CName;
    int Counter;
public:
    NCard(){}
    NCard(int id,char name,int cnt):ID(id),CName(name),Counter(cnt){}
    void initial(int id,char name,int cnt)
    {
        ID=id;
        CName=name;
        Counter=cnt;
    }
    int save(int m)
    {
        if(m<0)
        {
            return -1;
        }
        else
        {
            Counter+=m;
            return 1;
        }
    }
    int take(int m)
    {
        if(m<0)
        {
            return -1;
        }
        else
        {
            if(Counter>m)
            {
                Counter-=m;
                return 1;
            }
            else
            {
                return -1;
            }

        }
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
    TCard(){}
    void initial(int id,char name,int cnt,int tco)
    {
        ID=id;
        CName=name;
        Counter=cnt;
        Tcounter=tco;
    }
    int transfer(int m)
    {
        if(m<=Counter)
        {
            Tcounter+=m;
            Counter-=m;
            return 1;
        }
        else return -1;
    }
    void info()
    {
        cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Tcounter<<endl;
    }
};

class VCard:public NCard
{
    int Credit;
public:
    VCard(){}
    void initial(int id,char name,int cnt,int cre)
    {
        ID=id;
        CName=name;
        Counter=cnt;
        Credit=cre;
    }
    int over(int m)
    {
        if(m<=Counter+Credit)
        {
            Credit-=(m-Counter);
            Counter=0;
            return 1;
        }
        else
        {
            return -1;
        }
    }
    void info()
    {
        cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Credit<<endl;
    }
};
//----多态函数----
void show(NCard &obj)
{
    obj.info();
}
//----主函数----
int main()
{
    int ID;
    char CName;
    int Counter;
    int Tcounter;
    int Credit;
    int money;
    NCard nc;
    TCard tc;
    VCard vc;

    cin>>ID>>CName>>Counter;
    nc.initial(ID,CName,Counter);
    cin>>ID>>CName>>Counter>>Tcounter;
    tc.initial(ID,CName,Counter,Tcounter);
    cin>>ID>>CName>>Counter>>Credit;
    vc.initial(ID,CName,Counter,Credit);

    cin>>money;
    nc.save(money);
    cin>>money;
    nc.save(money);
    cin>>money;
    nc.take(money);
    cin>>money;
    nc.take(money);

    cin>>money;
    tc.save(money);
    cin>>money;
    tc.take(money);
    cin>>money;
    tc.transfer(money);
    cin>>money;
    tc.transfer(money);

    cin>>money;
    vc.save(money);
    cin>>money;
    vc.take(money);
    cin>>money;
    vc.over(money);
    cin>>money;
    vc.over(money);

    show(nc);
    show(tc);
    show(vc);

    return 0;
}

