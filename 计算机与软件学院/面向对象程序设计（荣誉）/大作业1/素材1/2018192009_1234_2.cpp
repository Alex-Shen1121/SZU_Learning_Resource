2018192009:Problem1234:ÕıÈ·
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
        int tag=0;
        int answer=0;
        int i=1;
        while(x||y)
        {
            int a,b;
            a=x%10;
            b=y%10;
            if(a<b)
                tag=a+10-b;
            else
                tag=a-b;
            x/=10;
            y/=10;
            answer+=tag*i;
            i*=10;
        }
        return answer;
    }
};
class GroupC:public Group
{
public:
    virtual int add(int x, int y)
    {
        int tag=0;
        int answer=0;
        int i=1;
        while(x||y)
        {
            int a,b;
            a=x%10;
            b=y%10;
            if(a+b>=10)
                tag=a+b-10;
            else
                tag=a+b;
            x/=10;
            y/=10;
            answer+=tag*i;
            i*=10;
        }
        return answer;
    }
    virtual int sub(int x, int y)
    {
        int tag=0;
        int answer=0;
        int i=1;
        while(x||y)
        {
            int a,b;
            a=x%10;
            b=y%10;
            if(a<b)
                tag=a+10-b;
            else
                tag=a-b;
            x/=10;
            y/=10;
            answer+=tag*i;
            i*=10;
        }
        return answer;
    }
};
int main()
{
    int t;
    cin>>t;
    int a,b,level;
    char m;
    Group *p;
    while(t--)
    {
        cin>>level>>a>>m>>b;
        if(level==1)
        {
            GroupA aa;
            p=&aa;
            if(m=='+')
                cout<<p->add(a,b)<<endl;
            else
                cout<<p->sub(a,b)<<endl;
        }
        else if(level==2)
        {
            GroupB bb;
            p=&bb;
            if(m=='+')
                cout<<p->add(a,b)<<endl;
            else
                cout<<p->sub(a,b)<<endl;
        }
        else if(level==3)
        {
            GroupC cc;
            p=&cc;
            if(m=='+')
                cout<<p->add(a,b)<<endl;
            else
                cout<<p->sub(a,b)<<endl;
        }
    }
    return 0;
}

