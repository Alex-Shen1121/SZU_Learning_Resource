2017133026:Problem1129:ÕýÈ·
#include <iostream>

using namespace std;
class BaseCard{
protected:
    int ID;
    char Cname;
    int Counter;
public:
    BaseCard(){

    }
    void initial(int ID1,char Cname1,int Counter1){
        ID=ID1;
        Cname=Cname1;
        Counter=Counter1;
    }
    int save(int v){
        if(v>0){
            Counter+=v;
            return 1;
        }
        return -1;
    }
    int take(int v){
        if(v>0 && v<=Counter){
            Counter-=v;
            return 1;
        }
        return -1;
    }
    virtual void info(){
        cout<<ID<<"-"<<Cname<<"-"<<Counter<<endl;
    }
};

class TransCard:public BaseCard{
protected:
    int Tcounter;
public:
    TransCard(){

    }
    void initial(int ID1,char Cname1,int Counter1,int Tcounter1){
        ID=ID1;
        Cname=Cname1;
        Counter=Counter1;
        Tcounter=Tcounter1;
    }
    int transfer(int v){
        if(v<=Counter){
            Tcounter+=v;
            Counter-=v;
            return 1;
        }
        return -1;
    }
    virtual void info(){
        cout<<ID<<"-"<<Cname<<"-"<<Counter<<"-"<<Tcounter<<endl;
    }
};

class VIPCard:public BaseCard{
protected:
    int Credit;
public:
    VIPCard(){

    }
    void initial(int ID1,char Cname1,int Counter1,int Credit1){
        ID=ID1;
        Cname=Cname1;
        Counter=Counter1;
        Credit=Credit1;
    }
    int over(int v){
        if(v<=Counter+Credit){
            Credit-=(v-Counter);
            Counter=0;
            return 1;
        }
        return -1;
    }
    virtual void info(){
        cout<<ID<<"-"<<Cname<<"-"<<Counter<<"-"<<Credit<<endl;
    }
};
void show(BaseCard *c){
    c->info();
}
int main()
{
    int ID;
    char Cname;
    int balance,tb,credit;
    cin>>ID>>Cname>>balance;
    BaseCard b;
    b.initial(ID,Cname,balance);
    cin>>ID>>Cname>>balance>>tb;
    TransCard t1;
    t1.initial(ID,Cname,balance,tb);
    cin>>ID>>Cname>>balance>>credit;
    VIPCard V1;
    V1.initial(ID,Cname,balance,credit);
    int value;
    cin>>value;
    b.save(value);
    cin>>value;
    b.save(value);
    cin>>value;
    b.take(value);
    cin>>value;
    b.take(value);

    cin>>value;
    t1.save(value);
    cin>>value;
    t1.take(value);
    cin>>value;
    t1.transfer(value);
    cin>>value;
    t1.transfer(value);

    cin>>value;
    V1.save(value);
    cin>>value;
    V1.take(value);
    cin>>value;
    V1.over(value);
    cin>>value;
    V1.over(value);
    show(&b);
    show(&t1);
    show(&V1);
    return 0;
}


