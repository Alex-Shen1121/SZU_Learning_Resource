2018151027:Problem1234:´ð°¸´íÎó
#include <iostream>
#include<iomanip>
#include<cstring>
using namespace std;
class Group
{
protected:

public:
    virtual int add(int x, int y)=0;
    virtual int sub(int x, int y)=0;
};
class GroupA: public Group
{
protected:

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
class GroupB: public Group
{
protected:

public:
    int add(int x, int y)
    {
        return x+y;
    }
    int sub(int x, int y)
    {
        int a[10];
        int b[10];
        int i,ten=10,w=0,yl,xl,xt,yt;
        xt=x;
        yt=y;
        for(yl=1; ;yl++)
        {
            if(y/10==0)
                break;
            else
                y=y/10;
        }

        for(xl=1; ;xl++)
        {
            if(x/10==0)
                break;
            else
                x=x/10;
        }

        for(i=0;i<xl;i++)
        {
            if(i==0)
            {
                a[i]=xt%ten;
            }
            else
            {
                a[i]=xt/ten;
                ten=ten*10;
            }
        }

        ten=10;
        for(i=0;i<yl;i++)
        {
            if(i==0)
            {
                b[i]=yt%ten;
            }
            else
            {
                b[i]=yt/ten;
                ten=ten*10;
            }
        }

        for(i=0;i<yl;i++)
        {
            if(a[i]>b[i])
                a[i]=a[i]-b[i];
            else
                a[i]=(a[i]+10-b[i])%10;
        }
        ten=1;

        for(i=0;i<xl;i++)
        {
            w=w+a[i]*ten;
            ten=ten*10;
        }

        return w;
    }
};
class GroupC: public Group
{
protected:

public:
    int add(int x, int y)
    {
        int a[10];
        int b[10];
        int i,ten=10,w=0,yl,xl,xt,yt;
        xt=x;
        yt=y;
        for(yl=1; ;yl++)
        {
            if(y/10==0)
                break;
            else
                y=y/10;
        }

        for(xl=1; ;xl++)
        {
            if(x/10==0)
                break;
            else
                x=x/10;
        }

        for(i=0;i<xl;i++)
        {
            if(i==0)
            {
                a[i]=xt%ten;
            }
            else
            {
                a[i]=xt/ten;
                ten=ten*10;
            }
        }

        ten=10;
        for(i=0;i<yl;i++)
        {
            if(i==0)
            {
                b[i]=yt%ten;
            }
            else
            {
                b[i]=yt/ten;
                ten=ten*10;
            }
        }

        for(i=0;i<yl;i++)
        {
            a[i]=(a[i]+b[i])%10;
        }
        ten=1;

        for(i=0;i<xl;i++)
        {
            w=w+a[i]*ten;
            ten=ten*10;
        }

        return w;
    }
    int sub(int x, int y)
    {
        int a[10];
        int b[10];
        int i,ten=10,w=0,yl,xl,xt,yt;
        xt=x;
        yt=y;
        for(yl=1; ;yl++)
        {
            if(y/10==0)
                break;
            else
                y=y/10;
        }

        for(xl=1; ;xl++)
        {
            if(x/10==0)
                break;
            else
                x=x/10;
        }

        for(i=0;i<xl;i++)
        {
            if(i==0)
            {
                a[i]=xt%ten;
            }
            else
            {
                a[i]=xt/ten;
                ten=ten*10;
            }
        }

        ten=10;
        for(i=0;i<yl;i++)
        {
            if(i==0)
            {
                b[i]=yt%ten;
            }
            else
            {
                b[i]=yt/ten;
                ten=ten*10;
            }
        }

        for(i=0;i<yl;i++)
        {
            if(a[i]>b[i])
                a[i]=a[i]-b[i];
            else
                a[i]=(a[i]+10-b[i])%10;
        }
        ten=1;

        for(i=0;i<xl;i++)
        {
            w=w+a[i]*ten;
            ten=ten*10;
        }

        return w;
    }
};

main()
{
    int t,a,b,type,i,j,n,ope,k;
    char op[20];
    cin>>t;
    Group *p;
    while(t--)
    {
        a=0;
        b=0;
        cin>>type;
        if(type==1)
        {
            cin>>op;
            for(i=0;i<strlen(op);i++)
            {
                if(op[i]<'0'||op[i]>'9')
                {
                    ope=i;
                }
            }
            for(i=0;i<ope;i++)
            {
                k=op[i]-'0';
                for(j=i;j<ope-1;j++)
                    k=k*10;
                a=a+k;
            }
            for(i=ope+1;i<strlen(op);i++)
            {
                k=op[i]-'0';
                for(j=i;j<strlen(op)-1;j++)
                    k=k*10;
                b=b+k;
            }
            p=new GroupA;
            if(op[ope]=='+')
                cout<<p->add(a,b)<<endl;
            else
                cout<<p->sub(a,b)<<endl;
        }
        else if(type==2)
        {
            cin>>op;
            for(i=0;i<strlen(op);i++)
            {
                if(op[i]<'0'||op[i]>'9')
                {
                    ope=i;
                }
            }
            for(i=0;i<ope;i++)
            {
                k=op[i]-'0';
                for(j=i;j<ope-1;j++)
                    k=k*10;
                a=a+k;
            }
            for(i=ope+1;i<strlen(op);i++)
            {
                k=op[i]-'0';
                for(j=i;j<strlen(op)-1;j++)
                    k=k*10;
                b=b+k;
            }
            p=new GroupB;
            if(op[ope]=='+')
                cout<<p->add(a,b)<<endl;
            else
                cout<<p->sub(a,b)<<endl;
        }
        else
        {
            cin>>op;
            for(i=0;i<strlen(op);i++)
            {
                if(op[i]<'0'||op[i]>'9')
                {
                    ope=i;
                }
            }
            for(i=0;i<ope;i++)
            {
                k=op[i]-'0';
                for(j=i;j<ope-1;j++)
                    k=k*10;
                a=a+k;
            }
            for(i=ope+1;i<strlen(op);i++)
            {
                k=op[i]-'0';
                for(j=i;j<strlen(op)-1;j++)
                    k=k*10;
                b=b+k;
            }
            p=new GroupC;
            if(op[ope]=='+')
                cout<<p->add(a,b)<<endl;
            else
                cout<<p->sub(a,b)<<endl;
        }
    }
}

