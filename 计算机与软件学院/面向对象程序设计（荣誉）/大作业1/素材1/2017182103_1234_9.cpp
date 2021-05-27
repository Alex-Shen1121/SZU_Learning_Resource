2017182103:Problem1234:´ğ°¸´íÎó
#include <bits/stdc++.h>
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
        int sum = 0;
        int time = 0;

        while(x/10!=0||x%10!=0||y/10!=0||y%10!=0)
        {
            double m = pow(10,time);
            if(x%10-y%10<0)
                sum += (x%10-y%10+10)*m;
            else
                sum += (x%10-y%10)*m;

            time++;

            x /= 10;
            y /= 10;
        }
        return sum;
    }
};

class GroupC:public Group
{
public:
    virtual int add(int x, int y)
    {
        int sum = 0;
        int time = 0;
        while(x/10!=0||x%10!=0||y/10!=0||y%10!=0)
        {
            double m = pow(10,time);

            int mm = x/10;
            int m0 = mm%10;
            int n = y/10;
            int n0 = n%10;

            if(mm!=0||m0!=0||n!=0||n0!=0)
            {
                if(x%10+y%10>=10)
                    sum += (x%10+y%10-10)*m;
                else
                    sum += (x%10+y%10)*m;
            }
            else
                sum += (x%10+y%10)*m;

            time++;

            x /= 10;
            y /= 10;
        }
        return sum;
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

