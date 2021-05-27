2018152007:Problem1234:正确
#include <iostream>

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
    int add(int x,int y)
    {
        int a;
        a=x+y;
        return a;
    }
    int sub(int x,int y)
    {
        int a;
        a=x-y;
        return a;
    }
};
class GroupB:public Group
{
public:
    int add(int x,int y)
    {
        int a;
        a=x+y;
        return a;
    }
    int sub(int x,int y)
    {
        int a[10]={0},b[10]={0},c=0,d=0,e,f,g=0,h,i=0;
        while(x)
        {
            a[c]=x%10;
            c++;
            x=x/10;
        }
        while(y)
        {
            b[d]=y%10;
            d++;
            y=y/10;
        }
        if(d<c)
        {
            e=c;
        }
        else
        {
            e=d;
        }
        for(f=e-1;f>=0;f--)
        {
            g=g*10;
            if(a[f]<b[f])
                a[f]=a[f]+10;
            g=a[f]-b[f]+g;
        }
        return g;
    }
};
class GroupC:public Group
{
public:
      int add(int x,int y)
    {
        int a[10]={0},b[10]={0},c=0,d=0,e,f,g=0,h,i=0;
        while(x)
        {
            a[c]=x%10;
            c++;
            x=x/10;
        }
        while(y)
        {
            b[d]=y%10;
            d++;
            y=y/10;
        }
        if(d<c)
        {
            e=c;
        }
        else
        {
            e=d;
        }
        for(f=e-1;f>=0;f--)
        {
            g=g*10;
            if(a[f]+b[f]>10)
                a[f]=a[f]-10;
            g=a[f]+b[f]+g;
        }
        return g;
    }
      int sub(int x,int y)
    {
        int a[10]={0},b[10]={0},c=0,d=0,e,f,g=0,h,i=0;
        while(x)
        {
            a[c]=x%10;
            c++;
            x=x/10;
        }
        while(y)
        {
            b[d]=y%10;
            d++;
            y=y/10;
        }
        if(d<c)
        {
            e=c;
        }
        else
        {
            e=d;
        }
        for(f=e-1;f>=0;f--)
        {
            g=g*10;
            if(a[f]<b[f])
                a[f]=a[f]+10;
            g=a[f]-b[f]+g;
        }
        return g;
    }
};
int main()
{
    int time;
    cin>>time;
    while(time--)
    {
        Group *g;
        int type;
        cin>>type;
        if(type==1)
        {
           int a,b,result;
           char c;
           cin>>a>>c>>b;
           GroupA *p=new GroupA();
           g=p;
           if(c=='+')
                result=g->add(a,b);
            else
                result=g->sub(a,b);
            cout<<result<<endl;
            delete p;
        }

        else if(type==2)
        {
           int a,b,result;
           char c;
           cin>>a>>c>>b;
           GroupB *p=new GroupB();
           g=p;
           if(c=='+')
                result=g->add(a,b);
            else
                result=g->sub(a,b);
            cout<<result<<endl;
            delete p;
        }
        else
        {
           int a,b,result;
           char c;
           cin>>a>>c>>b;
           GroupC *p=new GroupC();
           g=p;
           if(c=='+')
                result=g->add(a,b);
            else
                result=g->sub(a,b);
            cout<<result<<endl;
            delete p;
        }


    }
    return 0;
}

