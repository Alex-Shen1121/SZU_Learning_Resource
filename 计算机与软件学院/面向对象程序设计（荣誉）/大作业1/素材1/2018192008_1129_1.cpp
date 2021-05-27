2018192008:Problem1129:ÕýÈ·
#include <iostream>

using namespace std;

class Ncard
{
protected:
    int ID,Counter;
    char name;
public:
    Ncard(int i,char n,int c):ID(i),name(n),Counter(c){}
    int save(int m)
    {
        if(m>0)
            Counter+=m;
        else
            return -1;
        return 1;
    }
    virtual int take(int m)
    {
        if(m>Counter||m<=0)
            return -1;
        else
            Counter-=m;
        return 1;
    }
    virtual void info()
    {
        cout<<ID<<"-"<<name<<"-"<<Counter<<endl;
    }
};

class TranCard:public Ncard
{
    int Tcounter;
public:

    TranCard(int i,char n,int c,int t):Ncard(i,n,c),Tcounter(t){}
    int transfer(int m)
    {
        if(m>Counter)
            return -1;
        else
        {
            Tcounter+=m;
            Counter-=m;
        }
        return 1;
    }
     virtual void info()
    {
        cout<<ID<<"-"<<name<<"-"<<Counter<<"-"<<Tcounter<<endl;
    }
};

class VIP:public Ncard
{
    int Credit;
public:
    VIP(int i,char n,int c,int cr):Ncard(i,n,c),Credit(cr){}
    int over(int m)
    {
        if(m>Counter+Credit)
            return -1;
        else
        {
            if(m>Counter)
            {
                m-=Counter;
                Counter=0;
                Credit-=m;
            }
            else
                Counter-=m;
        }
    }
     virtual void info()
    {
        cout<<ID<<"-"<<name<<"-"<<Counter<<"-"<<Credit<<endl;
    }
};
void show(Ncard &obj)
{
    obj.info();
}
int main()
{
    int n1,n2,n3,t1;
    char a1,a2,a3;
    int c1,c2,c3,cr;
    cin>>n1>>a1>>c1;
    cin>>n2>>a2>>c2>>t1;
    cin>>n3>>a3>>c3>>cr;
    Ncard p1(n1,a1,c1);
    TranCard p2(n2,a2,c2,t1);
    VIP p3(n3,a3,c3,cr);
    int x1,x2,x3,x4;
    cin>>x1>>x2>>x3>>x4;
    p1.save(x1);
    p1.save(x2);
    p1.take(x3);
    p1.take(x4);
    cin>>x1>>x2>>x3>>x4;
    p2.save(x1);
    p2.take(x2);
    p2.transfer(x3);
    p2.transfer(x4);
    cin>>x1>>x2>>x3>>x4;
    p3.save(x1);
    p3.take(x2);
    p3.over(x3);
    p3.over(x4);
    show(p1);
    show(p2);
    show(p3);

}

