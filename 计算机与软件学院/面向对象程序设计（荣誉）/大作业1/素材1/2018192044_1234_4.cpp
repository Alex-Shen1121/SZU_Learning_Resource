2018192044:Problem1234:正确
#include <iostream>
using namespace std;
#include<iomanip>
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
    GroupA() {}
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
    GroupB() {}
    int add(int x,int y)
    {
        return x+y;
    }
    int sub(int x,int y)
    {
        int sum=0,t1,t2,total=1;
        while(1)
        {
            t1=x%10;
            t2=y%10;
            if(x==0)
                break;
            if(t1<t2)
                t1=t1+10-t2;
            else
                t1-=t2;
            sum+=t1*total;
            total*=10;
            x/=10;
            y/=10;
        }
        return sum;
    }
    ~GroupB(){}
};
class GroupC:public Group
{
public:
    GroupC() {}
    int sub(int x,int y)
    {
        int sum=0,t1,t2,total=1;
        while(1)
        {
            t1=x%10;
            t2=y%10;
            if(x==0)
                break;
            if(t1<t2)
                t1=t1+10-t2;
            else
                t1-=t2;
            sum+=t1*total;
            total*=10;
            x/=10;
            y/=10;
        }
        return sum;
    }
    int add(int x,int y)
    {
        int sum=0,t1,t2,total=1,x1,y1;
        x1=x;
        y1=y;
        while(1)
        {
            t1=x%10;
            t2=y%10;
            if(x==0&&x1>y1)
                break;
            if(y==0&&x1<y1)
                break;
            if(t1+t2>=10)
                t1=(t1+t2)%10;
            else
                t1+=t2;
            sum+=t1*total;
            total*=10;
            x/=10;
            y/=10;
        }
        return sum;
    }
    ~GroupC(){}
};
int main()
{
    int t,type,num1,num2;
    char o;
    cin>>t;
    Group *p;
    while(t--)
    {
        cin>>type>>num1>>o>>num2;
        if(type==1)
        {
            GroupA A;
            p=&A;
            if(o=='+')
            {
                cout<<p->add(num1,num2)<<endl;
            }
            else
            {
                cout<<p->sub(num1,num2)<<endl;
            }
        }
        else if(type==2)
        {
            GroupB B;
            p=&B;
            if(o=='+')
            {
                cout<<p->add(num1,num2)<<endl;
            }
            else
            {
                cout<<p->sub(num1,num2)<<endl;
            }
        }
        else
        {
            GroupC C;
            p=&C;
            if(o=='+')
            {
                cout<<p->add(num1,num2)<<endl;
            }
            else
            {
                cout<<p->sub(num1,num2)<<endl;
            }
        }
    }
    return 0;
}
