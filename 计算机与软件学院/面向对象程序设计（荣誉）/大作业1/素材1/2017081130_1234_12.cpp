2017081130:Problem1234:ÕýÈ·
#include <iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
class Group
{
public:
    Group(){};
    virtual int add(int x, int y)
    {
        return 1;
    }
    virtual int sub(int x, int y)
    {
        return 1;
    }

};
class GroupA:virtual public Group
{
public:
    GroupA(){};
    int add(int x,int y)
    {
        return x+y;
    }
    int sub(int x,int y)
    {
        return x-y;
    }

};
class GroupB:virtual public Group
{
public:
    GroupB(){};
    int add(int x,int y)
    {
        return x+y;
    }
    int sub(int x,int y)
    {
        int i,n=0,sum=0,a;
        while(x!=0||y!=0)
        {
            if(x%10>y%10)
                a=x%10-y%10;
            else
                a=x%10+10-y%10;
            x=x/10;
            y=y/10;
            if(n>0)
            {
                for(i=1;i<=n;i++)
                    a*=10;
            }
            sum+=a;
            n++;

        }
        return sum;
    }
};
class GroupC:virtual public Group
{
public:
    GroupC(){};
    int add(int x,int y)
    {
        int a,n,sum=0,i;
        n=0;
        while(x!=0||y!=0)
        {
            a=(x%10+y%10)%10;
            x=x/10;
            y=y/10;
            if(n>0)
            {
                for(i=1;i<=n;i++)
                    a*=10;
            }
            sum+=a;
            n++;
        }
        return sum;

    }
    int sub(int x,int y)
    {
        int i,n=0,sum=0,a;
        while(x!=0||y!=0)
        {
            if(x%10>y%10)
                a=x%10-y%10;
            else
                a=x%10+10-y%10;
            x=x/10;
            y=y/10;
            if(n>0)
            {
                for(i=1;i<=n;i++)
                    a*=10;
            }
            sum+=a;
            n++;

        }
        return sum;
    }
};
int main()
{
    int t,x,y,level;
    char ch;
    cin>>t;
    while(t--)
    {
        Group *g;
        cin>>level;
        cin>>x>>ch>>y;
        if(level==1)
        {
            GroupA ga;
            g=&ga;
            if(ch=='+')
                cout<<g->add(x,y)<<endl;
            else
                cout<<g->sub(x,y)<<endl;
        }
        else if(level==2)
        {
            GroupB gb;
            g=&gb;
            if(ch=='+')
                cout<<g->add(x,y)<<endl;
            else
                cout<<g->sub(x,y)<<endl;
        }
        else if(level==3)
        {
            GroupC gc;
            g=&gc;
            if(ch=='+')
                cout<<g->add(x,y)<<endl;
            else
                cout<<g->sub(x,y)<<endl;
        }
    }
}

