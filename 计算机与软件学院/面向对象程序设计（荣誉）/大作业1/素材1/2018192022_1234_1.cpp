2018192022:Problem1234:正确
#include <iostream>
#include <iomanip>
#include <cstring>
#define PI 3.14
using namespace std;
class Group
{
public:
    Group(){}
    virtual int add(int x, int y)=0;//输出加法的运算结果
    virtual int sub(int x, int y)=0;//输出减法的运算结果
};
class GroupA:public Group
{
public:
    int add(int x,int y)
    {
        return x+y;
    }
    int sub(int x,int y)
    {
        return x-y;
    }
};
class GroupB:public Group
{
public:
    int add(int x,int y)
    {
        return x+y;
    }
    int sub(int x,int y)
    {
        int i=0,j=0,k,a[10],b[10],sum=0,t=1;
        while(x!=0)
        {
            int n;
            n=x%10;
            a[i]=n;
            x/=10;
            i++;
        }
        while(y!=0)
        {
            int n;
            n=y%10;
            b[j]=n;
            y/=10;
            j++;
        }
        for(k=0;k<j;k++)
        {
            if(a[k]>=b[k])
                a[k]-=b[k];
            else
            {
                a[k]+=10;
                a[k]-=b[k];
            }
        }
        for(k=0;k<i;k++)
        {
            sum+=a[k]*t;
            t*=10;
        }
        return sum;
    }
};
class GroupC:public Group
{
public:
    int add(int x,int y)
    {
        int i=0,j=0,k,a[10],b[10],sum=0,t=1;
        while(x!=0)
        {
            int n;
            n=x%10;
            a[i]=n;
            x/=10;
            i++;
        }
        while(y!=0)
        {
            int n;
            n=y%10;
            b[j]=n;
            y/=10;
            j++;
        }
        if(i>=j)
        {
            for (k = 0; k < j; k++)
            {
                if(a[k]+b[k]<10)
                    a[k]+=b[k];
                else
                {
                    a[k]+=b[k];
                    a[k]-=10;
                }
            }
            for(k=0;k<i;k++)
            {
                sum+=a[k]*t;
                t*=10;
            }
            return sum;
        }
        else
        {
            for (k = 0; k < i; k++)
            {
                if(a[k]+b[k]<10)
                    b[k]+=a[k];
                else
                {
                    b[k]+=a[k];
                    b[k]-=10;
                }
            }
            for(k=0;k<j;k++)
            {
                sum+=b[k]*t;
                t*=10;
            }
            return sum;
        }
    }
    int sub(int x,int y)
    {
        int i=0,j=0,k,a[10],b[10],sum=0,t=1;
        while(x!=0)
        {
            int n;
            n=x%10;
            a[i]=n;
            x/=10;
            i++;
        }
        while(y!=0)
        {
            int n;
            n=y%10;
            b[j]=n;
            y/=10;
            j++;
        }
        for(k=0;k<j;k++)
        {
            if(a[k]>=b[k])
                a[k]-=b[k];
            else
            {
                a[k]+=10;
                a[k]-=b[k];
            }
        }
        for(k=0;k<i;k++)
        {
            sum+=a[k]*t;
            t*=10;
        }
        return sum;
    }
};
int main()
{
    int t;
    cin>>t;
    Group *p;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==1)
        {
            p=new GroupA;
            int x,y;
            char c;
            cin>>x>>c>>y;
            if(c=='+')
            {
                int sum;
                sum=p->add(x,y);
                cout<<sum<<endl;
            }
            else
            {
                int sum;
                sum=p->sub(x,y);
                cout<<sum<<endl;
            }
        }
        else if(n==2)
        {
            p=new GroupB;
            int x,y;
            char c;
            cin>>x>>c>>y;
            if(c=='+')
            {
                int sum;
                sum=p->add(x,y);
                cout<<sum<<endl;
            }
            else
            {
                int sum;
                sum=p->sub(x,y);
                cout<<sum<<endl;
            }
        }
        else if(n==3)
        {
            p=new GroupC;
            int x,y;
            char c;
            cin>>x>>c>>y;
            if(c=='+')
            {
                int sum;
                sum=p->add(x,y);
                cout<<sum<<endl;
            }
            else
            {
                int sum;
                sum=p->sub(x,y);
                cout<<sum<<endl;
            }
        }
    }
    return 0;
}
