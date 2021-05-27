2018151027:Problem1234:ÕýÈ·
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
        int xv,yv,ha,result=0;
        int ten=1;
        while(x||y)
        {
            xv=x%10;
            yv=y%10;
            x=x/10;
            y=y/10;
            if(xv>=yv)
                ha=xv-yv;
            else
                ha=xv+10-yv;
            result+=ha*ten;
            ten=ten*10;
        }
        return result;

    }
};
class GroupC: public Group
{
protected:

public:
    int add(int x, int y)
    {
        int xv,yv,ha,result=0;
        int ten=1;
        while(x||y)
        {
            xv=x%10;
            yv=y%10;
            x=x/10;
            y=y/10;
            ha=(xv+yv)%10;
            result+=ha*ten;
            ten=ten*10;
        }
        return result;
    }
    int sub(int x, int y)
    {
        int xv,yv,ha,result=0;
        int ten=1;
        while(x||y)
        {
            xv=x%10;
            yv=y%10;
            x=x/10;
            y=y/10;
            if(xv>=yv)
                ha=xv-yv;
            else
                ha=xv+10-yv;
            result+=ha*ten;
            ten=ten*10;
        }
        return result;
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

