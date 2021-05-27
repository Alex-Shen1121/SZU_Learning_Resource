2017161095:Problem1129:正确
//#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

// 普通卡类定义
class card
{
protected:
    string id,name;
    unsigned int counter;
public:
    void initial(string id,string name,unsigned int m);
    int save(int x);
    int take(int x);
    virtual void info();
};

// 普通卡类实现
void card::initial(string id,string name,unsigned int m)
{
    this->id=id;
    this->name=name;
    this->counter=m;
}

int card::save(int x)
{
    if(x<0) return -1;
    else counter+=x;
    return 1;
}

int card::take(int x)
{
    if(x<0||x>counter) return -1;
    else counter-=x;
    return 1;
}

void card::info()
{
    cout<<id<<"-"<<name<<"-"<<counter<<endl;
}

// 交通卡定义
class transcard : virtual public card
{
    int Tcounter;
public:
    void initial(string id,string name,unsigned int m,int mm);
    int transfer(int x);
    void info();
};

// 交通卡实现
void transcard::initial(string id,string name,unsigned int m,int mm)
{
    this->id=id;
    this->name=name;
    this->counter=m;
    this->Tcounter=mm;
}

int transcard::transfer(int x)
{
    if(take(x)!=-1)
    {
        Tcounter+=x;
        return 1;
    }
    else
        return -1;
}

void transcard::info()
{
    cout<<id<<"-"<<name<<"-"<<counter<<"-"<<Tcounter<<endl;
}

// 贵宾卡定义
class vipcard : virtual public card
{
    int Credit;
public:
    void initial(string id,string name,unsigned int m,int mm);
    int over(int x);
    void info();
};

// 贵宾卡类实现

void vipcard::initial(string id,string name,unsigned int m,int mm)
{
    this->id=id;
    this->name=name;
    this->counter=m;
    this->Credit=mm;
}

int vipcard::over(int x)
{
    if(x>Credit+counter) return -1;
    Credit-=x-counter,counter=0;
    return 1;
}

void vipcard::info()
{
    cout<<id<<"-"<<name<<"-"<<counter<<"-"<<Credit<<endl;
}

// 多态函数
void show(card &obj)
{
    obj.info();
}

// 主函数
int main()
{
    int n,m,i,j,k,ans,num,sum,x,xx,y,yy;
    string s,ss;
    card a;
    transcard b;
    vipcard c;
    cin>>s>>ss>>num;
    a.initial(s,ss,num);
    cin>>s>>ss>>num>>sum;
    b.initial(s,ss,num,sum);
    cin>>s>>ss>>num>>sum;
    c.initial(s,ss,num,sum);
    //
    cin>>x>>xx>>y>>yy;
    a.save(x);
    a.save(xx);
    a.take(y);
    a.take(yy);
    //
    cin>>x>>xx>>y>>yy;
    b.save(x);
    b.take(xx);
    b.transfer(y);
    b.transfer(yy);
    //
    cin>>x>>xx>>y>>yy;
    c.save(x);
    c.take(xx);
    c.over(y);
    c.over(yy);
    //
    show(a);
    show(b);
    show(c);

    return 0;
}

