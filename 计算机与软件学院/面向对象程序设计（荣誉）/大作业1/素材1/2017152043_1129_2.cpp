2017152043:Problem1129:正确
#include<iostream>
using namespace std;


//类定义
class NCard{
protected:
    int ID;
    char CName;
    int Counter;;
public:
    NCard(){}
    void initial(int id,char cname,int counter);
    bool save(int money);
    bool take(int money);
    virtual void info();
};



//类实现
void NCard::initial(int id,char cname,int counter)
{
    ID = id;
    CName = cname;
    Counter = counter;
}

bool NCard::save(int money)
{
    if(money <= 0)
        return -1;
    else{
        Counter += money;
        return 1;
    }
}

bool NCard::take(int money)
{
    if(money <= 0)
        return -1;
    else if(money > Counter)
        return -1;
    else{
        Counter -= money;
        return 1;
    }
}

void NCard::info()
{
    cout << ID << "-" << CName << "-" << Counter << endl;
}



//类定义
class TCard:public NCard{
    int Tcounter;
public:
    TCard(){}
    void initial(int id,char cname,int counter,int tcounter);
    bool transfer(int money);
    void info();
};



//类实验
void TCard::initial(int id,char cname,int counter,int tcounter)
{
    ID = id;
    CName = cname;
    Counter = counter;
    Tcounter = tcounter;
}

bool TCard::transfer(int money)
{
    if(money <= 0 || money > Counter)
        return -1;
    else{
        Tcounter += money;
        Counter -= money;
        return 1;
    }
}

void TCard::info()
{
    cout << ID << "-" << CName << "-" << Counter << "-" << Tcounter << endl;
}




//类定义
class VCard:public NCard{
    int Credit;
public:
    VCard(){}
    void initial(int id,char cname,int counter,int credit);
    bool over(int money);
    void info();
};



//类实现
void VCard::initial(int id,char cname,int counter,int credit)
{
    ID = id;
    CName = cname;
    Counter = counter;
    Credit = credit;
}

bool VCard::over(int money)
{
    if(money <= 0 || money > (Counter + Credit))
        return -1;
    else{
        Credit -= money - Counter;
        Counter = 0;
        return 1;
    }
}

void VCard::info()
{
    cout << ID << "-" << CName << "-" << Counter << "-" << Credit << endl;
}


void show(NCard &obj)
{
    obj.info();
}



//主函数
int main(){
    int id;
    char cname;
    int counter;
    int tcounter;
    int credit;
    NCard n;
    TCard t;
    VCard v;
    cin >> id >> cname >> counter;
    n.initial(id,cname,counter);
    cin >> id >> cname >> counter >> tcounter;
    t.initial(id,cname,counter,tcounter);
    cin >> id >> cname >> counter >> credit;
    v.initial(id,cname,counter,credit);
    int in,out;
    cin >> in >> out;
    n.save(in);
    n.take(out);
    cin >> in >> out;
    n.save(in);
    n.take(out);
    cin >> in >> out;
    t.save(in);
    t.take(out);
    cin >> in >> out;
    t.transfer(in);
    t.transfer(out);
    cin >> in >> out;
    v.save(in);
    v.take(out);
    cin >> in >> out;
    v.over(in);
    v.over(out);

    show(n);
    show(t);
    show(v);

    return 0;
}
