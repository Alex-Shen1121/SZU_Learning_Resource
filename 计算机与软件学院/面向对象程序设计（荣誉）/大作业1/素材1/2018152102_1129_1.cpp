2018152102:Problem1129:ÕýÈ·
#include <iostream>
#include <string>
 
using namespace std;
 
class CARD{
protected:
    int ID;
    string CName;
    int Counter;
public:
    CARD(int id,string cname,int counter = 0):ID(id),CName(cname),Counter(counter) {}
    int save(int mon);
    int take(int mon);
    virtual void info();
};
 
class Traffic_card:public CARD{
protected:
    int T_account;
public:
    Traffic_card(int id,string cname,int counter,int t_account)
        :CARD(id,cname,counter),T_account(t_account) {}
    int transfer(int mon);
    void info();
};
 
class VIP_card:public CARD {
protected:
    int Credit;
public:
    VIP_card(int credit,int id,string cname,int counter)
        :CARD(id,cname,counter),Credit(credit) {}
    int over(int mon);
    void info();
};
 
void show(CARD& card);
 
int main() {
    int ID;
    string CName;
    int Counter;
    int T_account;
    int Credit;
    int mon;
 
    cin>>ID>>CName>>Counter;
    CARD card(ID,CName,Counter);
    cin>>ID>>CName>>Counter>>T_account;
    Traffic_card t_card(ID,CName,Counter,T_account);
    cin>>ID>>CName>>Counter>>Credit;
    VIP_card vip_card(Credit,ID,CName,Counter);
 
    //common_card
    for(int i=0;i<2;i++) {
        cin>>mon;
        card.save(mon);
    }
    for(int i=0;i<2;i++) {
        cin>>mon;
        card.take(mon);
    }
 
    //traffic_card
    cin>>mon;
    t_card.save(mon);
    cin>>mon;
    t_card.take(mon);
    for(int i=0;i<2;i++) {
        cin>>mon;
        t_card.transfer(mon);
    }
 
    //vip_card
    cin>>mon;
    vip_card.save(mon);
    cin>>mon;
    vip_card.take(mon);
    for(int i=0;i<2;i++) {
        cin>>mon;
        vip_card.over(mon);
    }
 
    show(card);
    show(t_card);
    show(vip_card);
 
    return 0;
}
 
 
 
 
void show(CARD& card) {
    card.info();
}
 
int CARD::save(int mon) {
    if(mon <= 0) return -1;
 
    Counter += mon;
    return 1;
}
 
int CARD::take(int mon) {
    if(mon > 0 && mon <= Counter) {
        Counter -= mon;
        return 1;
    }
    return -1;
}
 
void CARD::info() {
    cout<<ID<<"-"<<CName<<"-"<<Counter;
    cout<<endl;
}
 
int Traffic_card::transfer(int mon) {
    if(mon > 0 && mon <= Counter) {
        T_account += mon;
        Counter -= mon;
        return 1;
    }
    return -1;
}
 
void Traffic_card::info() {
    cout<<ID<<"-"<<CName<<"-"<<Counter;
    cout<<"-"<<T_account;
    cout<<endl;
}
 
int VIP_card::over(int mon) {
    if(mon > Counter && mon - Counter <= Credit) {
        mon -= Counter;
        Counter = 0; //Óà¶îÇåÁã
        Credit -= mon;
        return 1;
    }
    return -1;
}
 
void VIP_card::info() {
     cout<<ID<<"-"<<CName<<"-"<<Counter;
     cout<<"-"<<Credit;
     cout<<endl;
}
 
