2017182103:Problem1234:答案错误
#include <bits/stdc++.h>
using namespace std;

class Group
{
public:
    virtual int add(int x, int y)=0;//输出加法的运算结果
    virtual int sub(int x, int y)=0;//输出减法的运算结果
};

class GroupA:public Group
{
public:
    virtual int add(int x, int y)
    {
        return x+y;
    }

    virtual int sub(int x, int y)
    {
        return x-y;
    }
};

class GroupB:public Group
{
public:
    virtual int add(int x, int y)
    {
        return x+y;
    }

    virtual int sub(int x, int y)
    {
        int x0=0,x1=0,x2=0;
        int y0=0,y1=0,y2=0;

        x2 = x/100;
        x1 = (x%100)/10;
        x0 = (x%100)%10;

        y2 = y/100;
        y1 = (y%100)/10;
        y0 = (y%100)%10;

        if(x0-y0<0)
            x0+=10;
        if(x1-y1<0)
            x1+=10;

        return (x2-y2)*100+(x1-y1)*10+(x0-y0);
    }
};

class GroupC:public Group
{
public:
    virtual int add(int x, int y)
    {
        int x0=0,x1=0,x2=0;
        int y0=0,y1=0,y2=0;

        x2 = x/100;
        x1 = (x%100)/10;
        x0 = (x%100)%10;

        y2 = y/100;
        y1 = (y%100)/10;
        y0 = (y%100)%10;

        if(x0+y0>10)
            x0-=10;
        if(x1+y1>10)
            x1-=10;

        return (x2+y2)*100+(x1+y1)*10+(x0+y0);
    }

    virtual int sub(int x, int y)
    {
        return x-y;
    }
};

int main()
{
    int t;
    cin>>t;
    Group *g;
    while(t--)
    {
        int n,n1,n2;
        char type;
        cin>>n>>n1>>type>>n2;

        if(n==1)
        {
            GroupA a;
            g = &a;

            if(type=='+')
                cout<<g->add(n1,n2)<<endl;
            else
                cout<<g->sub(n1,n2)<<endl;
        }

        else if(n==2)
        {
            GroupB b;
            g = &b;

            if(type=='+')
                cout<<g->add(n1,n2)<<endl;
            else
                cout<<g->sub(n1,n2)<<endl;
        }
        else if(n==3)
        {
            GroupC c;
            g = &c;

            if(type=='+')
                cout<<g->add(n1,n2)<<endl;
            else
                cout<<g->sub(n1,n2)<<endl;
        }
    }
    return 0;
}

