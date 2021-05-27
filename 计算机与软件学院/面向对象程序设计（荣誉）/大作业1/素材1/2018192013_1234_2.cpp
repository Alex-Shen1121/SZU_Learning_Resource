2018192013:Problem1234:´ð°¸´íÎó
#include <iostream>
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
    int add(int x,int y){return x+y;}
    int sub(int x,int y){return x-y;}
};

class GroupB:public Group
{
public:
    int add(int x,int y){return x+y;}
    int sub(int x,int y)
    {
        int i,s=0;
        for(i=1;x!=0;i*=10)
        {
            if(y!=0)
            {
                if(x%10>=y%10)
                    s+=(x%10-y%10)*i;
                else
                    s+=(x%10+10-y%10)*i;
                y=(y-y%10)/10;
            }
            else
                s+=x%10*i;
            x=(x-x%10)/10;
        }
        return s;
    }
};

class GroupC:public Group
{
public:
    int add(int x,int y)
    {
        int i,s=0;
        for(i=1;x!=0;i*=10)
        {
            if(y!=0)
            {
                s+=(x%10+y%10)%10*i;
                y=(y-y%10)/10;
            }
            else
                s+=x%10*i;
            x=(x-x%10)/10;
        }
        return s;
    }
    int sub(int x,int y)
    {
        int i,s=0;
        for(i=1;x!=0;i*=10)
        {
            if(y!=0)
            {
                if(x%10>=y%10)
                    s+=(x%10-y%10)*i;
                else
                    s+=(x%10+10-y%10)*i;
                y=(y-y%10)/10;
            }
            else
                s+=x%10*i;
            x=(x-x%10)/10;
        }
        return s;
    }
};

int main()
{
    int t;
    cin>>t;
    Group *p;
    while(t--)
    {
        int type,x,y;
        char op;
        cin>>type>>x>>op>>y;
        if(type==1)
        {
            GroupA ga;
            p=&ga;
            if(op=='+')
                cout<<p->add(x,y)<<endl;
            if(op=='-')
                cout<<p->sub(x,y)<<endl;
        }
        else if(type==2)
        {
            GroupB gb;
            p=&gb;
            if(op=='+')
                cout<<p->add(x,y)<<endl;
            if(op=='-')
                cout<<p->sub(x,y)<<endl;
        }
        else if(type==3)
        {
            GroupC gc;
            p=&gc;
            if(op=='+')
                cout<<p->add(x,y)<<endl;
            if(op=='-')
                cout<<p->sub(x,y)<<endl;
        }
    }
    return 0;
}

