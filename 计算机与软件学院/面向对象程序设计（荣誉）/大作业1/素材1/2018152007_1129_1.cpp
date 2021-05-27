2018152007:Problem1129:ÕýÈ·
#include <iostream>

using namespace std;
class putong
{
protected:
    string ID;
    string CName;
    int balance;
public:
    putong(string i,string c,int b):ID(i),CName(c),balance(b){}
    int save(int a)
    {
        if(a<0)
            return -1;
        else
            balance=balance+a;
            return 1;
    }
    int take(int c)
    {
        if(c<0)
        {
            return -1;
        }
        else
        {
             if(balance>c)
            {
                balance=balance-c;
                return 1;
            }
            else
                return -1;
        }

    }
    virtual int transfer(int a){};
    virtual int over(int a){};
    virtual void info()
    {
        cout<<ID<<'-'<<CName<<'-'<<balance<<endl;
    }
};
class jiaotong:public putong
{
private:
    int Tcounter;
public:
    jiaotong(string i,string c,int b,int t):putong(i,c,b)
    {
        Tcounter=t;
    }
    int transfer(int c)
    {
        if(balance>c)
        {
            balance=balance-c;
            Tcounter=Tcounter+c;
            return 1;
        }
        else
            return -1;
    }
    void info()
    {
        cout<<ID<<'-'<<CName<<'-'<<balance<<'-'<<Tcounter<<endl;
    }
};
class guibin:public putong
{
private:
    int Credit;
public:
    guibin(string i,string c,int b,int C):putong(i,c,b)
    {
        Credit=C;
    }
    int over(int c)
    {
        if(balance+Credit<c)
        {
            return -1;
        }
        else
        {
            if(balance>c)
            {
                balance=balance-c;
            }
            else
            {

                Credit=Credit-(c-balance);
                balance=0;
            }
        }
    }
    void info()
    {
        cout<<ID<<'-'<<CName<<'-'<<balance<<'-'<<Credit<<endl;
    }
};
void show(putong &pt)
{
    pt.info();
}
int main()
{
    string I1,I2,I3,c1,c2,c3;
    int b1,b2,b3,t,C;
    cin>>I1>>c1>>b1;
    cin>>I2>>c2>>b2>>t;
    cin>>I3>>c3>>b3>>C;
    putong *p1=new putong(I1,c1,b1);
    putong *p2;
    jiaotong *j2=new jiaotong(I2,c2,b2,t);
    p2=j2;
    putong *p3;
    putong *g3=new guibin(I3,c3,b3,C);
    p3=g3;
    int d1,d2,d3,d4,e1,e2,e3,e4,f1,f2,f3,f4,g;
    cin>>d1>>d2>>d3>>d4;
    cin>>e1>>e2>>e3>>e4;
    cin>>f1>>f2>>f3>>f4;
    g=p1->save(d1);
    g=p1->save(d2);
    g=p1->take(d3);
    g=p1->take(d4);
    g=p2->save(e1);
    g=p2->take(e2);
    g=p2->transfer(e3);
    g=p2->transfer(e4);
    g=p3->save(f1);
    g=p3->take(f2);
    g=p3->over(f3);
    g=p3->over(f4);
    show(*p1);
    show(*p2);
    show(*p3);
    return 0;
}

