2018151058:Problem1234:´ğ°¸´íÎó
#include <iostream>
#include<iomanip>
#include<cmath>
using namespace std;
class Group

{

public:

    virtual int add(int x, int y)=0;

    virtual int sub(int x, int y)=0;
};
class A:public Group
{
public:
    int add(int x, int y)
    {
        return x+y;
    }
    int sub(int x,int y)
    {
        return x-y;
    }
};
class B:public Group
{
public:
    int add(int x, int y)
    {
        return x+y;
    }
    int sub(int x,int y)
    {
        int len1=0,len2=0,len,i;
        int a[15],b[15],c[15];
        for(i=0; i<15; i++)
        {
            c[i]=0;
            a[i]=-1;
            b[i]=-1;

        }
        i=0;
        while(x/10!=0)
        {
            a[i]=x%10;
            x=x/10;
            len1++;
        }
        i=0;
        while(y/10!=0)
        {
            a[i]=y%10;
            y=y/10;
            len2++;
        }
        len=len2;
        for(i=0; i<len; i++)
        {
            if(a[i]<b[i])
                c[i]=a[i]+10-b[i];
            else
                c[i]=c[i]+a[i];
        }
        for(i=len; i<len1; i++)
        {
            c[i]=c[i]+a[i];
        }
        int result=0;
        for(i=0; i<len1; i++)
        {
            result+=c[i]*pow(10,i);
        }
        return result;
    }
};
class C:public Group
{
public:
    int add(int x, int y)
    {
        int len1=0,len2=0,len,i;
        int a[15],b[15],c[15];
        for(i=0; i<15; i++)
        {
            c[i]=0;
            a[i]=-1;
            b[i]=-1;

        }
        i=0;
        while(x/10!=0)
        {
            a[i]=x%10;
            x=x/10;
            len1++;
        }
        i=0;
        while(y/10!=0)
        {
            a[i]=y%10;
            y=y/10;
            len2++;
        }
        len=len2;
        for(i=0; i<len; i++)
        {
            c[i]=(a[i]+b[i])%10;
        }
        for(i=len; i<len1; i++)
        {
            c[i]=c[i]+a[i];
        }
        int result=0;
        for(i=0; i<len1; i++)
        {
            result+=c[i]*pow(10,i);
        }
        return result;
    }
    int sub(int x,int y)
    {
        int len1=0,len2=0,len,i;
        int a[15],b[15],c[15];
        for(i=0; i<15; i++)
        {
            c[i]=0;
            a[i]=-1;
            b[i]=-1;

        }
        i=0;
        while(x/10!=0)
        {
            a[i]=x%10;
            x=x/10;
            len1++;
        }
        i=0;
        while(y/10!=0)
        {
            a[i]=y%10;
            y=y/10;
            len2++;
        }
        len=len2;
        for(i=0; i<len; i++)
        {
            c[i]=a[i]-b[i];
        }
        for(i=len; i<len1; i++)
        {
            if(a[i]<b[i])
                c[i]=a[i]+10-b[i];
            else
                c[i]=c[i]+a[i];
        }
        int result=0;
        for(i=0; i<len1; i++)
        {
            result+=c[i]*pow(10,i);
        }
        return result;
    }
};
int main()
{
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        Group *p;
        int type;
        int x,y;
        char a;
        cin>>type;
        if(type==1)
        {
            p=new A;
            cin>>x>>a>>y;
            if(a=='+')
                cout<<p->add(x,y)<<endl;
            if(a=='-')
                cout<<p->sub(x,y)<<endl;
        }
        if(type==2)
        {
            p=new B;
            cin>>x>>a>>y;
            if(a=='+')
                cout<<p->add(x,y)<<endl;
            if(a=='-')
                cout<<p->sub(x,y)<<endl;
        }
        if(type==3)
        {
            p=new C;
            cin>>x>>a>>y;
            if(a=='+')
                cout<<p->add(x,y)<<endl;;
            if(a=='-')
                cout<<p->sub(x,y)<<endl;
        }
        delete p;

    }

    return 0;
}

