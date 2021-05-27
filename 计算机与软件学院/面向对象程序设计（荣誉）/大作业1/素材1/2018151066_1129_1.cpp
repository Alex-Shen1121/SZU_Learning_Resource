2018151066:Problem1129:正确
#include<iostream>
using namespace std;
//类定义
class CardN
{
protected:
    int ID;
    char CName;
    int Counter;
public:
    void initial(int id,char name,int counter);
    int save(int n);
    int take(int n);
    virtual void info();
};
class CardT:public CardN
{
protected:
    int Tcounter;
public:
    void initial(int id,char name,int counter,int t);
    int transfer(int n);
    void info();

};
class CardG:public CardN
{
protected:
    int Credit;
public:
    void initial(int id,char name,int counter,int c);
    int over(int n);
    void info();
};

//类实现
void CardG::initial(int id,char name,int counter,int c)
{
    ID=id;
    CName=name;
    Counter=counter;
    Credit=c;
}
void CardT::initial(int id,char name,int counter,int t)
{
    ID=id;
    CName=name;
    Counter=counter;
    Tcounter=t;
};
void CardN::initial(int id,char name,int counter)
{
    ID=id;
    CName=name;
    Counter=counter;
}
int CardN::save(int n)
{
    if(n>0)
    {
        Counter+=n;
        return 1;
    }
    else
        return -1;
}
int  CardN::take(int n)
{
    if(n>0)
    {
        if(n<Counter)
        {
            Counter-=n;
            return 1;
        }
    }
    return -1;
}
void CardN::info()
{
    cout<<ID<<"-"<<CName<<"-"<<Counter<<endl;
}
void CardT::info()
{
    cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Tcounter<<endl;
}
void CardG::info()
{
    cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Credit<<endl;
}
int CardT::transfer(int n)
{
    if(Counter>n)
    {
        Tcounter+=n;
        Counter-=n;
        return 1;
    }
    return -1;
}
int CardG::over(int n)
{
    if(n>Counter+Credit)
        return -1;
    else
    {
        Credit-=n-Counter;
        Counter=0;
        return 1;
    }
}


//主函数

void show(CardN &obj)
{
    obj.info();
}
int main()
{
    int idn,idt,idg;
    char namen,namet,nameg;
    int countern,countert,counterg;
    cin>>idn>>namen>>countern;
    CardN cardn;
    cardn.initial(idn,namen,countern);
    int tcounter;
    cin>>idt>>namet>>countert>>tcounter;
    CardT cardt;
    cardt.initial(idt,namet,countert,tcounter);
    int credit;
    cin>>idg>>nameg>>counterg>>credit;
    CardG cardg;
    cardg.initial(idg,nameg,counterg,credit);
    int s1,s2,g1,g2;
    cin>>s1>>s2>>g1>>g2;
    cardn.save(s1);
    cardn.save(s2);
    cardn.take(g1);
    cardn.take(g2);
    show(cardn);
    int s3,g3,c1,c2;
    cin>>s3>>g3>>c1>>c2;
    cardt.save(s3);
    cardt.take(g3);
    cardt.transfer(c1);
    cardt.transfer(c2);
    show(cardt);
    int s4,g4,o1,o2;
    cin>>s4>>g4>>o1>>o2;
    cardg.save(s4);
    cardg.take(g4);
    cardg.over(o1);
    cardg.over(o2);
    show(cardg);
}

