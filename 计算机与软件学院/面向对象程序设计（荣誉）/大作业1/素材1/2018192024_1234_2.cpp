2018192024:Problem1234:ÕıÈ·
#include <iostream>
#include <cmath>
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
    virtual int add(int x, int y){return x+y;}
    virtual int sub(int x, int y){return x-y;}
};
class GroupB:public Group
{
public:
    virtual int add(int x, int y){return x+y;}
    virtual int sub(int x, int y)
    {
        double p[10],flag=0,sum=0;
        for(int i=0;;i++)
        {
            p[i]=x%10-y%10;
            if(p[i]<0)
                p[i]+=10;
            x/=10;
            y/=10;
            if(x==0&&y==0)
                break;
            flag++;
        }
        for(int i=flag;i>=0;i--)
            sum+=p[i]*pow(10,i);
        return (int)sum;
    }
};
class GroupC:public Group
{
public:
    virtual int add(int x, int y)
    {
        double p[10],flag=0,sum=0;
        for(int i=0;;i++)
        {
            p[i]=x%10+y%10;
            if(p[i]>=10)
                p[i]-=10;
            x/=10;
            y/=10;
            if(x==0&&y==0)
                break;
            flag++;
        }
        for(int i=flag;i>=0;i--)
            sum+=p[i]*pow(10,i);
        return (int)sum;
    }
    virtual int sub(int x, int y)
    {
        double p[10],flag=0,sum=0;
        for(int i=0;;i++)
        {
            p[i]=x%10-y%10;
            if(p[i]<0)
                p[i]+=10;
            x/=10;
            y/=10;
            if(x==0&&y==0)
                break;
            flag++;
        }
        for(int i=flag;i>=0;i--)
            sum+=p[i]*pow(10,i);
        return (int)sum;
    }
};


int main()
{
    int t,x,y;
    cin>>t;
    Group** g=new Group*[t];
    for(int i=0;i<t;i++)
    {
        int type;
        char cmd;
        cin>>type>>x>>cmd>>y;
        if(type==1)
        {
            GroupA a;
            g[i]=&a;
            if(cmd=='+')
                cout<<g[i]->add(x,y)<<endl;
            else if(cmd=='-')
                cout<<g[i]->sub(x,y)<<endl;
        }
        else if(type==2)
        {
            GroupB b;
            g[i]=&b;
            if(cmd=='+')
                cout<<g[i]->add(x,y)<<endl;
            else if(cmd=='-')
                cout<<g[i]->sub(x,y)<<endl;
        }
        else if(type==3)
        {
            GroupC c;
            g[i]=&c;
            if(cmd=='+')
                cout<<g[i]->add(x,y)<<endl;
            else if(cmd=='-')
                cout<<g[i]->sub(x,y)<<endl;
        }
    }
    return 0;
}

