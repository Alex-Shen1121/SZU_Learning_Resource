2018192046:Problem1234:正确
#include<iostream>
#include<cmath>
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
    int sub(int x,int y)
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
    int sub(int x,int y)
    {
        int flag=0;
        int sum=0;
        int _x=x,_y=y;
        while(_y!=0)
        {
            flag++;
            int a=_x%10;
            int b=_y%10;
            if(a<b)
            {
                int t=1;
                for(int i=0;i<flag;i++)
                    t*=10;
                sum+=t;
            }
            _x/=10;
            _y/=10;
        }
        return x-y+sum;
    }
};
class GroupC:public Group
{
public:
    int add(int x,int y)
    {
        int flag=0;
        int sum=0;
        int _x=x,_y=y;
        while(_y!=0)
        {
            flag++;
            int a=_x%10;
            int b=_y%10;
            if(a+b>10)
            {
                int t=1;
                for(int i=0;i<flag;i++)
                    t*=10;
                sum+=t;
            }
            _x/=10;
            _y/=10;
        }
        return x+y-sum;
    }
    int sub(int x,int y)
    {
        int flag=0;
        int sum=0;
        int _x=x,_y=y;
        while(_y!=0)
        {
            flag++;
            int a=_x%10;
            int b=_y%10;
            if(a<b)
            {
                int t=1;
                for(int i=0;i<flag;i++)
                    t*=10;
                sum+=t;
            }
            _x/=10;
            _y/=10;
        }
        return x-y+sum;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Group *pv;
        int type;
        cin>>type;
        int a,b;
        char d;
        cin>>a;
        cin>>d;
        cin>>b;
        if(type==1)
        {
            GroupA P;
            pv=&P;
            if(d=='+')
                cout<<pv->add(a,b)<<endl;
            else if(d=='-')
                cout<<pv->sub(a,b)<<endl;
        }
        else if(type==2)
        {
            GroupB P;
            pv=&P;
            if(d=='+')
                cout<<pv->add(a,b)<<endl;
            else if(d=='-')
                cout<<pv->sub(a,b)<<endl;
        }
        else if(type==3)
        {
            GroupC P;
            pv=&P;
            if(d=='+')
                cout<<pv->add(a,b)<<endl;
            else if(d=='-')
                cout<<pv->sub(a,b)<<endl;
        }
    }
}

