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
        int sum[10];
        for(int i=1;i<100;i++)
        {
            if(x/(10*i)==0&&y/(10*i)==0)
                break;
            int xx = x%(10*i);
            int yy = y%(10*i);
            sum[i-1]=xx-yy;
        }
    }
};

class GroupC:public Group
{
public:
    virtual int add(int x, int y)
    {
      
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

        else  if(n==2)
        {
            GroupB b;
            g = &b;

            if(type=='+')
                cout<<g->add(n1,n2)<<endl;
            else
                cout<<g->sub(n1,n2)<<endl;
        }

        else
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

