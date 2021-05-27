2018152026:Problem1234:正确
#include <bits/stdc++.h>
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
    virtual int add(int x,int y)
    {
        cout<<x+y<<endl;
    }
    virtual int sub(int x,int y)
    {
        cout<<x-y<<endl;
    }
};

class GroupB:public Group
{
public:
    virtual int add(int x,int y)
    {
        cout<<x+y<<endl;
    }
    virtual int sub(int x,int y)
    {
        int n;
        if(x%10>=y%10)
            n=x%10-y%10;
        else
            n=x%10-y%10+10;
        n+=(x/10-y/10)*10;
        n+=(x/100)*100;
        cout<<n<<endl;
    }
};

class GroupC:public Group
{
public:
    virtual int add(int x,int y)
    {
        int n;
        n=x%10+y%10;
        if(n>=10)
            n-=10;
        x=x/10;
        y=y/10;
        if((x%10+y%10)>=10)
            n+=(x%10+y%10-10)*10;
        else
            n+=(x%10+y%10)*10;
        x=x/10;
        y=y/10;
        n+=x*100+y*100;
        cout<<n<<endl;
    }
    virtual int sub(int x,int y)
    {
        int n;
        if(x%10>=y%10)
            n=x%10-y%10;
        else
            n=x%10-y%10+10;
        x=x/10;
        y=y/10;
        if(x%10>=y%10)
            n+=(x%10-y%10)*10;
        else
            n+=(x%10-y%10+10)*10;
        n+=(x/10)*100-(y/10)*100;
        cout<<n<<endl;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Group *p;
        int n;
        int xx,yy;
        char c;
        cin>>n>>xx>>c>>yy;
        if(n==1)
        {
            GroupA a;
            p=&a;
        }
        else if(n==2)
        {
            GroupB b;
            p=&b;
        }
        else if(n==3)
        {
            GroupC c;
            p=&c;
        }
        if(c=='+')
            p->add(xx,yy);
        else if(c=='-')
            p->sub(xx,yy);
    }
    return 0;
}
