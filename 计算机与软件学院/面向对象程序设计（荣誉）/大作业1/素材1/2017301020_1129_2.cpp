2017301020:Problem1129:ÕýÈ·
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class NormalCard{
protected:
    string ID,name;
    double counter;
public:
    NormalCard(){}
    void initial(string ID1,string name1,double counter1);
    bool save(double);
    bool take(double);
    virtual void info();
};

void NormalCard::initial(string ID1,string name1,double counter1){
    ID=ID1;
    name=name1;
    counter=counter1;
}

bool NormalCard::save(double a){
   if(a<0)
        return -1;
   else{
        counter+=a;
        return 1;
   }
}

bool NormalCard::take(double a){
    if(a<0||a>counter)
        return -1;
    else{
        counter-=a;
        return 1;
    }
}

void NormalCard::info(){
    cout<<ID<<"-"<<name<<"-"<<counter<<endl;
}

class TranCard:public NormalCard{
    double tcounter;
public:
    TranCard(){}
    void initial(string ID1,string name1,double counter1,double tcounter1);
    bool Transfer(double a);
    void info();
};

void TranCard::initial(string ID1,string name1,double counter1,double tcounter1){
    ID=ID1;
    name=name1;
    counter=counter1;
    tcounter=tcounter1;
}

bool TranCard::Transfer(double a){
    if(a>counter)
        return -1;
    else{
        counter-=a;
        tcounter+=a;
        return 1;
    }
}

void TranCard::info(){
    cout<<ID<<"-"<<name<<"-"<<counter<<"-"<<tcounter<<endl;
}

class VipCard:public NormalCard{
    double credit,now=0;
public:
    VipCard(){}
    void initial(string ID1,string name1,double counter1,double credit1);
    bool over(double a);
    void info();
};

void VipCard::initial(string ID1,string name1,double counter1,double credit1){
    ID=ID1;
    name=name1;
    counter=counter1;
    credit=credit1;
}

bool VipCard::over(double a){
    if(a>counter+credit)
        return -1;
    else{
        now+=(a-counter);
        counter=0;
        return 1;
    }
}

void VipCard::info(){
    cout<<ID<<"-"<<name<<"-"<<counter<<"-"<<credit-now<<endl;
}

void show(NormalCard &obj){
    obj.info();
}

int main()
{
    string ID,name;
    double balance,tbalance,credit,w1,w2,d1,d2,c1,c2,t1,t2;
    NormalCard a;
    TranCard b;
    VipCard c;
    cin>>ID>>name>>balance;
    a.initial(ID,name,balance);
    cin>>ID>>name>>balance>>tbalance;
    b.initial(ID,name,balance,tbalance);
    cin>>ID>>name>>balance>>credit;
    c.initial(ID,name,balance,credit);
    cin>>d1>>d2>>w1>>w1;
    a.save(d1);
    a.save(d2);
    a.take(w1);
    a.take(w2);
    cin>>d1>>w1>>c1>>c2;
    b.save(d1);
    b.take(w1);
    b.Transfer(c1);
    b.Transfer(c2);
    cin>>d1>>w1>>t1>>t2;
    c.save(d1);
    c.take(w1);
    c.over(t1);
    c.over(t2);
    show(a);
    show(b);
    show(c);
    return 0;
}

