2018152100:Problem1129:正确
#include <iostream>
 
using namespace std;
 
//普通卡类定义
class NCard
{
public:
    int ID;
    char CName;
    unsigned int Counter;
    NCard();
    void initial(int id,char c,unsigned int countt);
    int save(int w);
    int take(int w);
    virtual void info();
 
};
 
//普通卡类实现
NCard::NCard(){}
void NCard::initial(int id,char c,unsigned int countt)
{
    ID=id;
    CName=c;
    Counter=countt;
}
 
int NCard::save(int w)
{
    if (w<=0) return -1;
    Counter+=w;
    return 1;
}
 
int NCard::take(int w)
{
    if (w<=0||w>Counter) return -1;
    Counter-=w;
    return 1;
}
 
void NCard::info()
{
    cout << ID << "-" << CName << "-" << Counter << endl;
}
 
//交通卡类定义
class Tcard:public NCard
{
    int Tcounter;
public:
    Tcard();
    void initial(int id,char c,unsigned int countt,int tcount);
    int transfer(int w);
    void info();
};
 
//交通卡类实现
Tcard::Tcard(){}
void Tcard::initial(int id,char c,unsigned int countt,int tcount)
{
    ID=id;
    CName=c;
    Counter=countt;
    Tcounter=tcount;
}
 
int Tcard::transfer(int w)
{
    if (take(w)==1)
    {
        Tcounter+=w;
        return 1;
    }
    else return -1;
}
void Tcard::info()
{
    cout << ID << "-" << CName << "-" << Counter << "-" << Tcounter << endl;
}
 
//贵宾卡类定义
class Vcard:public NCard
{
    int Credit;
public:
    Vcard();
    void initial(int id,char c,unsigned int countt,int cred);
    int over(int w);
    void info();
};
 
//贵宾卡类实现
Vcard::Vcard(){}
void Vcard::initial(int id,char c,unsigned int countt,int cred)
{
    ID=id;
    CName=c;
    Counter=countt;
    Credit=cred;
}
int Vcard::over(int w)
{
    if (take(w)==-1)
    {
        int m=Counter;
        if (w-m>Credit)
            return -1;
        else
        {
            take(m);
            Credit-=(w-m);
            return 1;
        }
    }
    else return -1;
}
 
void Vcard::info()
{
    cout << ID << "-" << CName << "-" << Counter << "-" << Credit << endl;
}
 
//多态函数
void show(NCard &obj)
{
    obj.info();
}
 
//主函数
int main()
{
    int id,t,cred;
    int w1,w2,w3,w4;
    unsigned int countt;
    char q;
    NCard a;
    Tcard b;
    Vcard c;
 
    cin >> id >> q >> countt;
    a.initial(id,q,countt);
 
    cin >> id >> q >> countt >> t;
    b.initial(id,q,countt,t);
 
    cin >> id >> q >> countt >> cred;
    c.initial(id,q,countt,cred);
 
    cin >> w1 >> w2 >> w3 >> w4;
    a.save(w1);a.save(w2);
    a.take(w3);a.take(w4);
 
    cin >> w1 >> w2 >> w3 >> w4;
    b.save(w1);b.take(w2);
    b.transfer(w3);b.transfer(w4);
 
    cin >> w1 >> w2 >> w3 >> w4;
    c.save(w1);c.take(w2);
    c.over(w3);c.over(w4);
 
    show(a);
    show(b);
    show(c);
 
    return 0;
}
