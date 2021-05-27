2018192046:Problem1129:正确
#include<iostream>
using namespace std;
//------类声明------
class normal
{
protected:
    string ID,CName;
    int Counter;
public:
    normal(string _ID="0",string _CName="0",int _Counter=0):ID(_ID),CName(_CName),Counter(_Counter) {}
    void initial(string _ID,string _CName,int _Counter);
    int save(int a);
    int take(int a);
    virtual void info();
};
class Traffic:public normal
{
    int Tcounter;
public:
    Traffic(string _ID="0",string _CName="0",int _Counter=0,int _Tcounter=0):normal(_ID,_CName,_Counter),Tcounter(_Tcounter) {}
    void initial(string _ID,string _CName,int _Counter,int _Tcounter);
    int transfer(int a);
    void info();
};
class VIP:public normal
{
    int Credit;
public:
    VIP(string _ID="0",string _CName="0",int _Counter=0,int _Credit=0):normal(_ID,_CName,_Counter),Credit(_Credit) {}
    void initial(string _ID,string _CName,int _Counter,int _Credit);
    int over(int a);
    void info();
};
//------类实现------
void normal::initial(string _ID,string _CName,int _Counter)
{
    ID=_ID;
    CName=_CName;
    Counter=_Counter;
}
int normal::save(int a)
{
    if(a<0)
        return -1;
    Counter+=a;
    return 1;
}
int normal::take(int a)
{
    if(a<0||Counter<a)
        return -1;
    Counter-=a;
    return 1;
}
void normal::info()
{
    cout<<ID<<"-"<<CName<<"-"<<Counter<<endl;
}
void Traffic::initial(string _ID,string _CName,int _Counter,int _Tcounter)
{
    ID=_ID;
    CName=_CName;
    Counter=_Counter;
    Tcounter=_Tcounter;
}
int Traffic::transfer(int a)
{
    if(a>Counter||a<0)
        return -1;
    Counter-=a;
    Tcounter+=a;
    return 1;
}
void Traffic::info()
{
    cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Tcounter<<endl;
}
void VIP::initial(string _ID,string _CName,int _Counter,int _Credit)
{
    ID=_ID;
    CName=_CName;
    Counter=_Counter;
    Credit=_Credit;
}
int VIP::over(int a)
{
    if(a<0||a>(Credit+Counter))
        return -1;
    else
    {
        if(Counter<a)
        {
            a-=Counter;
            Counter=0;
            Credit-=a;
        }
        else
        {
            Counter-=a;
        }
    }
    return 1;
}
void VIP::info()
{
    cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Credit<<endl;
}
//------主函数------
void show(normal *obj)
{
    obj->info();
}
int main()
{
    normal P1;
    Traffic P2;
    VIP P3;
    string ID,name;
    int counter;
    cin>>ID>>name>>counter;
    P1.initial(ID,name,counter);
    int Tcounter;
    cin>>ID>>name>>counter>>Tcounter;
    P2.initial(ID,name,counter,Tcounter);
    int credit;
    cin>>ID>>name>>counter>>credit;
    P3.initial(ID,name,counter,credit);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    P1.save(a),P1.save(b),P1.take(c),P1.take(d);
    cin>>a>>b>>c>>d;
    P2.save(a),P2.take(b),P2.transfer(c),P2.transfer(d);
    cin>>a>>b>>c>>d;
    P3.save(a),P3.take(b),P3.over(c),P3.over(d);
    normal *_P;
    _P=&P1;
    show(_P);
    _P=&P2;
    show(_P);
    _P=&P3;
    show(_P);
}

