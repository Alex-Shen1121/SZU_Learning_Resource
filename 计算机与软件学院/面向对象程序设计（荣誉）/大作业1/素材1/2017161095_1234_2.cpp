2017161095:Problem1234:正确
//#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

class Group

{

public:

virtual int add(int x, int y)=0;//输出加法的运算结果

virtual int sub(int x, int y)=0;//输出减法的运算结果

};

class GroupA : virtual public Group
{
    virtual int add(int x, int y)//输出加法的运算结果
    {
        return x+y;
    }

    virtual int sub(int x, int y)//输出减法的运算结果
    {
        return x-y;
    }
};

class GroupB : virtual public Group
{
    virtual int add(int x, int y)//输出加法的运算结果
    {
        return x+y;
    }

    virtual int sub(int x, int y)//输出减法的运算结果
    {
        int num=1,ans=0;
        while(x||y)
        {
            ans+=abs(x-y)%10*num;
            num*=10;
            x/=10;
            y/=10;
        }
        return ans;
    }
};

class GroupC : virtual public Group
{
    virtual int add(int x, int y)//输出加法的运算结果
    {
        int num=1,ans=0;
        while(x||y)
        {
            ans+=(x+y)%10*num;
            num*=10;
            x/=10;
            y/=10;
        }
        return ans;
    }

    virtual int sub(int x, int y)//输出减法的运算结果
    {
        int num=1,ans=0;
        while(x||y)
        {
            ans+=abs(x-y)%10*num;
            num*=10;
            x/=10;
            y/=10;
        }
        return ans;
    }
};

int main()
{
    int n,m,i,j,k,ans,t,type,x,y;
    char s;
    cin>>t;
    Group *p;
    while(t--)
    {
        cin>>type;
        cin>>x>>s>>y;
        if(type==1)
        {
            GroupA b;
            p=&b;
            if(s=='+')
            cout<<p->add(x,y)<<endl;
            else
            cout<<p->sub(x,y)<<endl;
        }
        else if(type==2)
        {
            GroupB b;
            p=&b;
            if(s=='+')
            cout<<p->add(x,y)<<endl;
            else
            cout<<p->sub(x,y)<<endl;
        }
        else if(type==3)
        {
            GroupC b;
            p=&b;
            if(s=='+')
            cout<<p->add(x,y)<<endl;
            else
            cout<<p->sub(x,y)<<endl;
        }
    }

    return 0;
}

