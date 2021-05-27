2017182103:Problem1234:答案错误
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
    virtual int add(int x, int y)
    {
        return x+y;
    }

    virtual int sub(int x, int y)
    {
        return x-y;
    }
};

class GroupB:public Group
{
public:
    virtual int add(int x, int y)
    {
        return x+y;
    }

    virtual int sub(int x, int y)
    {
        int sum[10];
        int s = 0,xx,yy;
        double m,n,o;
        for(int i=1; i<100; i++)
        {
            m = pow(10,i);
            n = pow(10,i-1);
            o = pow(10,i+1);
            int m1 = m,n1 =n,o1=o;
            if(int(x/m)==0&&int(y/m)==0)
            {
                xx = (x%m1 - x%n1)/n1;
                yy = (y%m1 - y%n1)/n1;

                if(xx-yy<0)
                    sum[i-1]=xx-yy+10;
                else
                    sum[i-1]=xx-yy;

                s = s + sum[i-1]*n;

                break;
            }
            else if(int(x/m)!=0&&int(y/m)==0)
            {

                xx = (x%m1 - x%n1)/n1;
                yy = (y%m1 - y%n1)/n1;

                if(xx-yy<0)
                    sum[i-1]=xx-yy+10;
                else
                    sum[i-1]=xx-yy;

                s = s + sum[i-1]*n;

                xx = (x%o1-x%m1)/m1;
                yy = 0;
                sum[i-1]=xx-yy;
                s = s + sum[i-1]*m1;

                break;
            }
            else if(int(x/m)==0&&int(y/m)!=0)
            {

                xx = (x%m1 - x%n1)/n1;
                yy = (y%m1 - y%n1)/n1;

                if(xx-yy<0)
                    sum[i-1]=xx-yy+10;
                else
                    sum[i-1]=xx-yy;

                s = s + sum[i-1]*n;

                xx = 10;
                yy = (y%o1-y%m1)/m1;
                sum[i-1]=xx-yy;
                s = s + sum[i-1]*m1;

                break;
            }
            else
            {
                if(i!=1)
                {
                    xx = (x%m1 - x%n1)/n1;
                    yy = (y%m1 - y%n1)/n1;
                }
                else
                {
                    xx = x%m1;
                    yy = y%m1;
                }

                if(xx-yy<0)
                    sum[i-1]=xx-yy+10;
                else
                    sum[i-1]=xx-yy;

                s = s + sum[i-1]*n;
            }
        }
        return s;
    }
};

class GroupC:public Group
{
public:
    virtual int add(int x, int y)
    {
        int sum[10];
        int s = 0,xx,yy;
        double m,n,o;
        for(int i=1; i<100; i++)
        {
            m = pow(10,i);
            n = pow(10,i-1);
            o = pow(10,i+1);
            int m1 = m,n1 =n,o1=o;
            if(int(x/m)==0&&int(y/m)==0)
            {
                xx = (x%m1 - x%n1)/n1;
                yy = (y%m1 - y%n1)/n1;

                if(xx+yy>=10)
                    sum[i-1]=xx+yy-10;
                else
                    sum[i-1]=xx+yy;

                s = s + sum[i-1]*n;

                break;
            }
            else if(int(x/m)==0&&int(y/m)!=0)
            {
                xx = (x%m1 - x%n1)/n1;
                yy = (y%m1 - y%n1)/n1;

                if(xx+yy>=10)
                    sum[i-1]=xx+yy-10;
                else
                    sum[i-1]=xx+yy;

                s = s + sum[i-1]*n;

                xx = 0;
                yy = (y%o1-y%m1)/m1;
                sum[i-1]=xx+yy;
                s = s + sum[i-1]*n;

                break;
            }
            else if(int(x/m)!=0&&int(y/m)==0)
            {

                xx = (x%m1 - x%n1)/n1;
                yy = (y%m1 - y%n1)/n1;

                if(xx+yy>=10)
                    sum[i-1]=xx+yy-10;
                else
                    sum[i-1]=xx+yy;

                s = s + sum[i-1]*n;

                xx = (x%o1-x%m1)/m1;
                yy = 0;
                sum[i-1]=xx+yy;
                s = s + sum[i-1]*m;

                break;
            }
            else
            {
                if(i!=1)
                {
                    xx = (x%m1 - x%n1)/n1;
                    yy = (y%m1 - y%n1)/n1;
                }
                else
                {
                    xx = x%m1;
                    yy = y%m1;
                }

                if(xx+yy>=10)
                    sum[i-1]=xx+yy-10;
                else
                    sum[i-1]=xx+yy;

                s = s + sum[i-1]*n;
            }
        }
        return s;
    }

    virtual int sub(int x, int y)
    {
        return x-y;
    }
};

int main()
{
    int t;
    cin>>t;
    Group *g;
    while(t--)
    {
        int n,n1,n2;
        char type;
        cin>>n>>n1>>type>>n2;

        if(n==1)
        {
            GroupA a;
            g = &a;

            if(type=='+')
                cout<<g->add(n1,n2)<<endl;
            else
                cout<<g->sub(n1,n2)<<endl;
        }

        else if(n==2)
        {
            GroupB b;
            g = &b;

            if(type=='+')
                cout<<g->add(n1,n2)<<endl;
            else
                cout<<g->sub(n1,n2)<<endl;
        }
        else if(n==3)
        {
            GroupC c;
            g = &c;

            if(type=='+')
                cout<<g->add(n1,n2)<<endl;
            else
                cout<<g->sub(n1,n2)<<endl;
        }
    }
    return 0;
}

