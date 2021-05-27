2018192008:Problem1234:ÕıÈ·
#include<iostream>

using namespace std;
class Group
{
public:
    virtual int add(int x, int y)=0;
    virtual int sub(int x, int y)=0;
};
class GroupA:public Group
{
public:
    virtual int add(int x,int y)
    {
        return x+y;
    }
    virtual int sub(int x,int y)
    {
        return x-y;
    }
};

class GroupB:public Group
{
public:
    virtual int add(int x,int y)
    {
        return x+y;
    }
    virtual int sub(int x,int y)
    {
        int index=0;
        int sum=0,i=1;
        while(x||y)
        {
            int a,b;
            a=x%10;
            b=y%10;
            if(a<b)
                index=a+10-b;
            else
                index=a-b;
            x/=10;
            y/=10;
            sum+=index*i;
            i*=10;
        }
        return sum;
    }
};

class GroupC:public Group
{
public:
    virtual int add(int x,int y)
    {
       int index=0;
       int sum=0,i=1;
        while(x||y)
        {
            int a,b;
            a=x%10;
            b=y%10;
            if(a+b>=10)
                index=a+b-10;
            else
                index=a+b;
            x/=10;
            y/=10;
            sum+=index*i;
            i*=10;
        }
        return sum;
    }
    virtual int sub(int x,int y)
    {
         int index=0;
        int sum=0,i=1;
        while(x||y)
        {
            int a,b;
            a=x%10;
            b=y%10;
            if(a<b)
                index=a+10-b;
            else
                index=a-b;
            x/=10;
            y/=10;
            sum+=index*i;
            i*=10;
        }
        return sum;
    }
};
int main()
{
    int t;
    cin>>t;
    Group *g;
    GroupA ga;
    GroupB gb;
    GroupC gc;
    while(t--)
    {
        int k,x,y;
        char f;
        cin>>k>>x>>f>>y;
        if(k==1)
        {
            g=&ga;
            if(f=='+')
                cout<<g->add(x,y)<<endl;
            else
                cout<<g->sub(x,y)<<endl;
        }
        else if(k==2)
        {
            g=&gb;
            if(f=='+')
                cout<<g->add(x,y)<<endl;
            else
                cout<<g->sub(x,y)<<endl;
        }
        else if(k==3)
        {
            g=&gc;
            if(f=='+')
                cout<<g->add(x,y)<<endl;
            else
                cout<<g->sub(x,y)<<endl;
        }
    }
}

