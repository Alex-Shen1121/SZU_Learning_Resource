2018152035:Problem1234:正确
#include <iostream>
#include<stdio.h>
#include<string>
#include<iomanip>
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
    int add(int x,int y)
    {
        return x+y;
    }
    int sub(int x, int y)
    {
        return x-y;
    }
};
class GroupB:public Group
{
public:
    int add(int x,int y)
    {
        return x+y;
    }
    int sub(int x, int y)
    {
        int a,b,sum=0,i=0,num;
        while(x||y)
        {
            a=x%10;
            b=y%10;
            if(a<b)
            {
                num=a+10-b;
            }
            else
            {
                num=a-b;
            }
            int ii;
            ii=i;
            while(ii--)
            {
                num=10*num;
            }
            i++;
            sum+=num;
            x=x/10;
            y=y/10;
        }
        return sum;
    }
};
class GroupC:public Group
{
public:
    int add(int x,int y)
    {
        int a,b,sum=0,i=0,num;
        while(x||y)
        {
            a=x%10;
            b=y%10;
            if(a+b>=10)
            {
                num=a+b-10;
            }
            else
            {
                num=a+b;
            }
            int ii;
            ii=i;
            while(ii--)
            {
                num=10*num;
            }
            i++;
            sum+=num;
            x=x/10;
            y=y/10;
        }
        return sum;
    }
    int sub(int x, int y)
    {
        int a,b,sum=0,i=0,num;
        while(x||y)
        {
            a=x%10;
            b=y%10;
            if(a<b)
            {
                num=a+10-b;
            }
            else
            {
                num=a-b;
            }
            int ii;
            ii=i;
            while(ii--)
            {
                num=10*num;
            }
            i++;
            sum+=num;
            x=x/10;
            y=y/10;
        }
        return sum;
    }
};
int main()
{
    //freopen("C:\\Users\\241\\Desktop\\1.txt","r",stdin);
    int T;
    cin>>T;
    int t,x,y;
    char type;
    Group *p;
    while(T--)
    {
        cin>>t>>x>>type>>y;
        if(t==1)
        {
            GroupA a;
            p=&a;
            if(type=='+')
                cout<<p->add(x,y)<<endl;
            else
                cout<<p->sub(x,y)<<endl;
        }
        else if(t==2)
        {
            GroupB b;
            p=&b;
            if(type=='+')
                cout<<p->add(x,y)<<endl;
            else
                cout<<p->sub(x,y)<<endl;
        }
        else if(t==3)
        {
            GroupC c;
            p=&c;
            if(type=='+')
                cout<<p->add(x,y)<<endl;
            else
                cout<<p->sub(x,y)<<endl;
        }
    }
}

