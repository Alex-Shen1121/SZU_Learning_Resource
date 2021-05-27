2017044015:Problem1129:´ð°¸´íÎó
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Card{
protected:
    string ID;
    char CName;
    double Counter;
public:
    virtual void initial(string s, char c, double d){
        ID = s;
        CName = c;
        Counter = d;
    }
    virtual int save(double d){
        if(d <= 0)
            return -1;
        Counter += d;
        return 1;
    }
    virtual int take(double d){
        if(d <= 0)
            return -1;
        if(d > Counter)
            return 0;
        Counter -= d;
    }
    virtual void info(){
        cout<<ID<<"-"<<CName<<"-"<<Counter<<endl;
    }
};

class TCard: public Card{
protected:
    double TCounter;
public:
    virtual void initial(string s, char c, double d, double t){
        ID = s;
        CName = c;
        Counter = d;
        TCounter = t;
    }
    int transfer(double d){
        if(d <= 0)
            return -1;
        if(d > Counter)
            return 0;
        Counter -= d;
        TCounter += d;
        return 1;
    }
    virtual void info(){
        cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<TCounter<<endl;
    }
};

class VCard: public Card{
protected:
    double Credit, cur_overtake;
public:
    virtual void initial(string s, char c, double d, double cre){
        ID = s;
        CName = c;
        Counter = d;
        Credit = cre;
        cur_overtake = 0;
    }
    int over(double d){
        if(d <= 0)
            return -1;
        if(d > Counter + Credit)
            return 0;
        cur_overtake = 0;
        cur_overtake = d - Counter;
        Credit -= cur_overtake;
        return 1;
    }
    virtual void info(){
        cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Credit<<endl;
    }
};

void show(Card& obj);

void show(Card& obj){
    obj.info();
}

int main()
{
    double bal, tcou, cre, op1, op2, op3, op4;
    string id;
    char c;
    Card card;
    TCard tc;
    VCard vc;
    cin>>id>>c>>bal;
    card.initial(id, c, bal);
    cin>>id>>c>>bal>>tcou;
    tc.initial(id, c, bal, tcou);
    cin>>id>>c>>bal>>cre;
    vc.initial(id, c, bal, cre);

    cin>>op1>>op2>>op3>>op4;
    card.save(op1);
    card.take(op2);
    card.save(op3);
    card.take(op4);

    cin>>op1>>op2>>op3>>op4;
    tc.save(op1);
    tc.take(op2);
    tc.transfer(op3);
    tc.transfer(op4);

    cin>>op1>>op2>>op3>>op4;
    vc.save(op1);
    vc.take(op2);
    vc.over(op3);
    vc.over(op4);

    show(card);
    show(tc);
    show(vc);
    return 0;
}

