2018192043:Problem1234:正确
#include <iostream>
#include <cmath>
using namespace std;
class Group
{
public:
    virtual int add(int x, int y)=0;//输出加法的运算结果
    virtual int sub(int x, int y)=0;//输出减法的运算结果
    virtual ~Group(){}
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
    ~GroupA(){}
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
        int result=0,longs=1;
        if(x>y)
        {
            while(x/pow(10,longs)!=0)
            {
                longs++;
            }
        }
        else
        {
            while(y/pow(10,longs)!=0)
            {
                longs++;
            }
        }
        for(int i=longs-1; i>=1; i--)
        {
            int temp1=x/(int)(pow(10,i-1)+0.5);
            int temp2=y/(int)(pow(10,i-1)+0.5);
            if(temp1-temp2<0)
                result+=(temp1+10-temp2)%10*(int)(pow(10,i-1)+0.5);
            else
                result+=(temp1-temp2)%10*(int)(pow(10,i-1)+0.5);
            x-=temp1*(int)(pow(10,i-1)+0.5);
            y-=temp2*(int)(pow(10,i-1)+0.5);
        }
        return result;
    }
    ~GroupB(){}
};
class GroupC:public Group
{
public:
    int add(int x,int y)
    {
        int result=0,longs=1;
        if(x>y)
        {
            while(x/pow(10,longs)!=0)
            {
                longs++;
            }
        }
        else
        {
            while(y/pow(10,longs)!=0)
            {
                longs++;
            }
        }
        for(int i=longs-1; i>=1; i--)
        {
            int temp1=x/(int)(pow(10,i-1)+0.5);
            int temp2=y/(int)(pow(10,i-1)+0.5);
            result+=(temp1+temp2)%10*(int)(pow(10,i-1)+0.5);
            x-=temp1*(int)(pow(10,i-1)+0.5);
            y-=temp2*(int)(pow(10,i-1)+0.5);
        }
        return result;
    }
    int sub(int x,int y)
    {
        int result=0,longs=1;
        if(x>y)
        {
            while(x/pow(10,longs)!=0)
            {
                longs++;
            }
        }
        else
        {
            while(y/pow(10,longs)!=0)
            {
                longs++;
            }
        }
        for(int i=longs; i>=1; i--)
        {
            int temp1=x/(int)(pow(10,i-1)+0.5);
            int temp2=y/(int)(pow(10,i-1)+0.5);
            if(temp1-temp2<0)
                result+=(temp1+10-temp2)%10*(int)(pow(10,i-1)+0.5);
            else
                result+=(temp1-temp2)%10*(int)(pow(10,i-1)+0.5);
            x-=temp1*(int)(pow(10,i-1)+0.5);
            y-=temp2*(int)(pow(10,i-1)+0.5);
        }
        return result;
    }
    ~GroupC(){}
};
int main()
{
    int t,x,y,student;
    char type;
    Group *p;
    cin>>t;
    while(t--)
    {
        cin>>student>>x>>type>>y;
        if(student==1)
        {
            GroupA a;
            p=&a;
            if(type=='+')
                cout<<p->add(x,y)<<endl;
            else
                cout<<p->sub(x,y)<<endl;
        }
        else if(student==2)
        {
            GroupB a;
            p=&a;
            if(type=='+')
                cout<<p->add(x,y)<<endl;
            else
                cout<<p->sub(x,y)<<endl;
        }
        else if(student==3)
        {
            GroupC a;
            p=&a;
            if(type=='+')
                cout<<p->add(x,y)<<endl;
            else
                cout<<p->sub(x,y)<<endl;
        }
    }
    return 0;
}
 
