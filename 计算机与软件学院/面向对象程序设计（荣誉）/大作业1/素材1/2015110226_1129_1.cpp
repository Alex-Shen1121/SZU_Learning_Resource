2015110226:Problem1129:ÕıÈ·
#include <bits/stdc++.h>
using namespace std;

class card{
protected:
    int id;
    string name;
    int counter;
public:
    card(int a,string b,int c):id(a),name(b),counter(c){}
    void initial(){}
    virtual int save(int v){
        if(v < 0) return -1;
        counter += v;
        return 1;
    }
    virtual int take(int v){
        if(v < 0) return -1;
        if(v > counter) return -1;
        counter -= v;
        return 1;
    }
    virtual void info(){
        cout<<id<<'-'<<name<<'-'<<counter<<endl;
    }
};
class traffic:public card{
protected:
    int Tcounter;
public:
    traffic(int a,string b,int c,int d):card(a,b,c),Tcounter(d){}
    int transfer(int v){
        if(take(v) == 1){
            Tcounter += v;
            return 1;
        }
        return -1;
    }
    void info(){
        cout<<id<<'-'<<name<<'-'<<counter<<'-'<<Tcounter<<endl;
    }
};
class vip:public card{
protected:
    int credit;
public:
    vip(int a,string b,int c,int d):card(a,b,c),credit(d){}
    int over(int v){
        if(v < 0) return -1;
        if(counter > v){
            counter -= v;
            return 1;
        }
        if(counter < v && counter + credit > v){
            v -= counter;
            counter = 0;
            credit -= v;
            return 1;
        }
        return -1;
    }
    void info(){
        cout<<id<<'-'<<name<<'-'<<counter<<'-'<<credit<<endl;
    }
};


int main(){
    int a,b,c,d;
    string b1;
    cin>>a>>b1>>c;
    card c1(a,b1,c);
    cin>>a>>b1>>c>>d;
    traffic t1(a,b1,c,d);
    cin>>a>>b1>>c>>d;
    vip v1(a,b1,c,d);
    cin>>a>>b>>c>>d;
    c1.save(a);
    c1.save(b);
    c1.take(c);
    c1.take(d);
    c1.info();
    cin>>a>>b>>c>>d;
    t1.save(a);
    t1.take(b);
    t1.transfer(c);
    t1.transfer(d);
    t1.info();
    cin>>a>>b>>c>>d;
    v1.save(a);
    v1.take(b);
    v1.over(c);
    v1.over(d);
    v1.info();
    return 0;
}



