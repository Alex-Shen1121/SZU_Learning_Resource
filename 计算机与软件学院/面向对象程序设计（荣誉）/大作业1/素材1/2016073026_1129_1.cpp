2016073026:Problem1129:正确
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;
//类定义
class NCard{
protected:
    int ID;
    char CName;
    int Counter;
public:
    void initial(int id,char name,int ct);
    int save(int m);
    int take(int m);
    virtual void info();
};

class TCard:public NCard{
protected:
    int Tcounter;
public:
    void initial(int id,char name,int ct,int tc);
    int transfer(int m);
    virtual void info();
};

class VipCard:public TCard{
    int Credit;
public:
    void initial(int id,char name,int ct,int cred);
    int over(int m);
    virtual void info();
};

//类实现
void NCard::initial(int id,char name,int ct){
    ID=id;  CName=name; Counter=ct;
}
int NCard::save(int m){
    if(m>0){Counter+=m; return 1;}
        else return -1;
}
int NCard::take(int m){
    if(m>0&&m<=Counter){Counter-=m; return 1;}
    else return -1;
}
void NCard::info(){
    cout<<ID<<"-"<<CName<<"-"<<Counter<<endl;
}

void TCard::initial(int id,char name,int ct,int tc){
    ID=id;  CName=name; Counter=ct; Tcounter=tc;
}
int TCard::transfer(int m){
    if(m<=Counter){Counter-=m; Tcounter+=m; return 1;}
    else return -1;
}
void TCard::info(){
    cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Tcounter<<endl;
}

void VipCard::initial(int id,char name,int ct,int cred){
    ID=id;  CName=name; Counter=ct; Credit=cred;
}
int VipCard::over(int m){
    if(m<=Credit+Counter){
        Credit-=m-Counter;
        Counter=0;
        return 1;
    }
    else
        return -1;
}

void VipCard::info(){
    cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Credit<<endl;
}

//多态函数
void show(NCard & obj){
    obj.info();
}

//主函数
int main()
{
    int id,ct,tc,cd;
    char name;
    cin>>id>>name>>ct;
    NCard ncard;
    ncard.initial(id,name,ct);
    cin>>id>>name>>ct>>tc;
    TCard tcard;
    tcard.initial(id,name,ct,tc);
    cin>>id>>name>>ct>>cd;
    VipCard vipcard;
    vipcard.initial(id,name,ct,cd);

    int n1,n2,n3,n4;
    cin>>n1>>n2>>n3>>n4;
    ncard.save(n1);
    ncard.save(n2);
    ncard.take(n3);
    ncard.take(n4);
    cin>>n1>>n2>>n3>>n4;
    tcard.save(n1);
    tcard.take(n2);
    tcard.transfer(n3);
    tcard.transfer(n4);
    cin>>n1>>n2>>n3>>n4;
    vipcard.save(n1);
    vipcard.take(n2);
    vipcard.over(n3);
    vipcard.over(n4);
    show(ncard);
    show(tcard);
    show(vipcard);
    return 0;
}

