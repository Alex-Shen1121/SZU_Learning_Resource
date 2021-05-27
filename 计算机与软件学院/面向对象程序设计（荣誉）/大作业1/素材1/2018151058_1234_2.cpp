2018151058:Problem1234:ÕıÈ·
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
        int len1=1,len2=1,len,i;
        int a[15],b[15],c[15];
        for(i=0; i<15; i++)
        {
            c[i]=0;
            a[i]=0;
            b[i]=0;

        }
        i=0;
        while((x*10)/10!=0)
        {
            a[i]=x%10;
            x=x/10;
            i++;
            len1++;
        }
        i=0;
        while((y*10)/10!=0)
        {
            b[i]=y%10;
            y=y/10;
            len2++;
            i++;
        }
        len=len2;
        for(i=0; i<len; i++)
        {
            if(a[i]<b[i])
                c[i]=a[i]+10-b[i];
            else
                c[i]=a[i]-b[i];
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
        int len1=1,len2=1,i;
        int a[15],b[15],c[15];
        for(i=0; i<15; i++)
        {
            c[i]=0;
            a[i]=0;
            b[i]=0;

        }
        i=0;
        while((x*10)/10!=0)
        {
            a[i]=x%10;
            x=x/10;
            i++;
            len1++;
        }
        i=0;
        while((y*10)/10!=0)
        {
            b[i]=y%10;
            y=y/10;
            len2++;
            i++;
        }
        int min,max;
        if(len1>len2)
        {
            max=len1,min=len2;
        }
        else
        {
            max=len2,min=len1;
        }
        for(i=0; i<min; i++)
        {

                c[i]=(a[i]+b[i])%10;

        }
        for(i=min; i<max; i++)
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
        int len1=1,len2=1,len,i;
        int a[15],b[15],c[15];
        for(i=0; i<15; i++)
        {
            c[i]=0;
            a[i]=0;
            b[i]=0;

        }
        i=0;
        while((x*10)/10!=0)
        {
            a[i]=x%10;
            x=x/10;
            i++;
            len1++;
        }
        i=0;
        while((y*10)/10!=0)
        {
            b[i]=y%10;
            y=y/10;
            len2++;
            i++;
        }
        len=len2;
        for(i=0; i<len; i++)
        {
            if(a[i]<b[i])
                c[i]=a[i]+10-b[i];
            else
                c[i]=a[i]-b[i];
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

