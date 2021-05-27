2018192010:Problem1129:ÕýÈ·
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
class NCard
{
protected:
    string ID,CName;
    int counter;
public:
    NCard(){}
    virtual void initial(string n,string name,int c)
    {
        ID=n;
        CName=name;
        counter=c;
    }
    int save(int m)
    {
        if(m>0)
        {
            counter += m;
            return 1;
        }
        return -1;
    }
    int take(int m)
    {
        if(m>0 && m<=counter)
        {
            counter -= m;
            return 1;
        }
        return -1;
    }
    virtual void info()
    {
        cout << ID << '-' << CName << '-' << counter << endl;
    }
};
class Traffic:public NCard
{
protected:
    int Tcounter;
public:
    Traffic(){}
    void initial(string n,string name,int c,int ct)
    {
        ID=n;
        CName=name;
        counter=c;
        Tcounter = ct;
    }
    int transfer(int m)
    {
        if(m > counter)
            return -1;
        else
        {
            Tcounter +=m;
            counter -=m;
        }
    }
    void info()
    {
        cout << ID << '-' << CName << '-' << counter << '-' << Tcounter << endl;
    }
};
class VIP:public NCard
{
protected:
    int Credit;
public:
    VIP(){}
    void initial(string n,string name,int c,int cr)
    {
        ID=n;
        CName=name;
        counter=c;
        Credit = cr;
    }
    int over(int m)
    {
        if(m > Credit+counter)
            return -1;
        else if(m > counter)
        {
            Credit -=(m-counter);
            counter =0;
        }
        else
        {
            counter -=m;
        }
        return 1;
    }
    void info()
    {
        cout << ID << '-' << CName << '-' << counter << '-' << Credit << endl;
    }
};
void show(NCard & obj)
{
    obj.info();
}
int main()
{
    string n,namem;
    int c,cr,ct,m1,m2,m3,m4;
    NCard B;
    Traffic T;
    VIP V;
    cin >> n >> namem >> c;
    B.initial(n,namem,c);
    cin >> n >> namem >> c >> ct;
    T.initial(n,namem,c,ct);
    cin >> n >> namem >> c >> cr;
    V.initial(n,namem,c,cr);
    cin >> m1 >> m2 >> m3 >> m4;
    B.save(m1);
    B.save(m2);
    B.take(m3);
    B.take(m4);
    cin >> m1 >> m2 >> m3 >> m4;
    T.save(m1);
    T.take(m2);
    T.transfer(m3);
    T.transfer(m4);
    cin >> m1 >> m2 >> m3 >> m4;
    V.save(m1);
    V.take(m2);
    V.over(m3);
    V.over(m4);
    show(B);
    show(T);
    show(V);
    return 0;
}

