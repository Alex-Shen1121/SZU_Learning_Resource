2018192045:Problem1234:答案错误
#include<iostream>
using namespace std;
#include<cstring>
#include<iomanip>
class Group
{

public:

    virtual int add(int x, int y)=0;//输出加法的运算结果

    virtual int sub(int x, int y)=0;//输出减法的运算结果

};
class GroupA:public Group
{

public:

    int add(int x, int y)
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
    int add(int x, int y)
    {
        return x+y;
    }

    int sub(int x, int y)
    {
        int sum_;
        sum_=x-y;
        if(x%10<y%10)
            sum_+=10;
        if(x%100<y%100)
            sum_+=100;
        if(x%100<y%100)
            sum_+=1000;
        return sum_;
    }

};
class GroupC:public Group
{

public:
    int add(int x, int y)
    {
        int sum;
        sum=x+y;
        if(x%10+y%10>=10)
            sum-=10;
        if(((x-x%10)%100)+((y-y%10)%100)>=100)
            sum-=100;
        return sum;
    }

    int sub(int x, int y)
    {
        int sum_;
        sum_=x-y;
        if(x%10<y%10)
            sum_+=10;
        if(x%100<y%100)
            sum_+=100;
        if(x%1000<y%1000)
            sum_+=1000;
        return sum_;
    }
};
int main()
{
    int num1,num2,t,group;
    char type;
    Group *p;
    cin>>t;
    while(t--)
    {
        cin>>group;
        int i;
        cin>>num1>>type>>num2;
        if(group==1)
        {
            GroupA A;
            p=&A;
            if(type=='+')
                cout<<p->add(num1,num2)<<endl;
            if(type=='-')
                cout<<p->sub(num1,num2)<<endl;
        }
        if(group==2)
        {
            GroupB A;
            p=&A;
            if(type=='+')
                cout<<p->add(num1,num2)<<endl;
            if(type=='-')
                cout<<p->sub(num1,num2)<<endl;
        }
        if(group==3)
        {
            GroupC A;
            p=&A;
            if(type=='+')
                cout<<p->add(num1,num2)<<endl;
            if(type=='-')
                cout<<p->sub(num1,num2)<<endl;
        }
    }
}

