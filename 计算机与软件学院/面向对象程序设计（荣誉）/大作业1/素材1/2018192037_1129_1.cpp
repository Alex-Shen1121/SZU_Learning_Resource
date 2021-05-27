2018192037:Problem1129:ÕýÈ·
#include<bits/stdc++.h>
using namespace std;

class CNormal
{
protected:
    int id;
    string name;
    int counter;
public:
    void initiai(int i,string n,int c)
    {
        id = i;
        name = n;
        counter = c;
    }
    virtual int save(int m)
    {
        if(m>0)
        {
            counter+=m;
            return 1;
        }
        else return -1;
    }
    virtual int take(int m)
    {
        if(m>0 && counter-m>=0)
        {
            counter-=m;
            return 1;
        }
        else return -1;
    }
    virtual void info()
    {
        cout<<id<<"-"<<name<<"-"<<counter<<endl;
    }

};

class CVIP:public CNormal
{
    int Credit;
public:
    void initiai(int i,string n,int c,int q)
    {
        id = i;
        name = n;
        counter = c;
        Credit = q;
    }
    int over(int m)
    {
        if(m>0 && Credit+counter-m>=0)
        {
            counter-=m;
            if(counter<0)
            {
                Credit+=counter;
                counter=0;
            }
            return 1;
        }
        else return -1;
    }
    void info()
    {
        cout<<id<<"-"<<name<<"-"<<counter
        <<"-"<<Credit<<endl;
    }
};

class CTransfer:public CNormal
{
    int Tcounter;
public:
    void initiai(int i,string n,int c,int q)
    {
        id = i;
        name = n;
        counter = c;
        Tcounter = q;
    }
    int transfer(int m)
    {
        if(m>0 && counter+Tcounter-m>=0)
        {
            counter-=m;
            Tcounter += m;
            return 1;
        }
        else return -1;
    }
    void info()
    {
        cout<<id<<"-"<<name<<"-"<<counter
        <<"-"<<Tcounter<<endl;
    }
};

void show(CNormal &obj)
{
    obj.info();
}


int main()
{
    string n;
    int id,m1,m2;
    cin>>id>>n>>m1;
    CNormal C1;
    C1.initiai(id,n,m1);
    cin>>id>>n>>m1>>m2;
    CTransfer C2;
    C2.initiai(id,n,m1,m2);
    cin>>id>>n>>m1>>m2;
    CVIP C3;
    C3.initiai(id,n,m1,m2);
    int q1,q2,q3,q4;
    cin>>q1>>q2>>q3>>q4;
    C1.save(q1);
    C1.save(q2);
    C1.take(q3);
    C1.take(q4);
    cin>>q1>>q2>>q3>>q4;
    C2.save(q1);
    C2.take(q2);
    C2.transfer(q3);
    C2.transfer(q4);
    cin>>q1>>q2>>q3>>q4;
    C3.save(q1);
    C3.take(q2);
    C3.over(q3);
    C3.over(q4);
    show(C1);
    show(C2);
    show(C3);
}

