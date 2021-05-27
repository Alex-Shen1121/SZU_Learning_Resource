2018192037:Problem1234:编译错误
#include<bits/stdc++.h>
using namespace std;

class Group{
public:
    virtual int add(int x, int y)=0;//输出加法的运算结果
    virtual int sub(int x, int y)=0;//输出减法的运算结果
};

class GroupA:public Group
{

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

class GroupB:public Group
{

public:
    GroupB(){}
    int add(int x, int y)
    {
        return x+y;
    }
    int sud(int x,int y)
    {
        int i=0,j=0,q=0;
        int x1[10],y1[10],ans[10];
        while(x/10>0)
        {
            x1[i]=x%10;
            x/=10;
            i++;
        }
        x1[i]=x;
        while(y/10>0)
        {
            y1[j]=y%10;
            y/=10;
            j++;
        }
        y1[j]=y;
        int m = max(i,j);
        for(int t=0;t<m;t++)
        {
            if(t>i)
                x1[t]=0;
            if(t>j)
                y1[t]=0;

            if(x1[t]-y1[t]<0)
            {
                ans[t]=y1[t]+x1[t]+10;
            }
            else ans[t] = ans[t]=y1[t]+x1[t];
        }
        for(int t=0;t<m;t++)
        {
            q+=ans[t]*pow(10,i);
        }
        return q;
    }
};

class GroupC:public Group
{
public:
    int sud(int x,int y)
    {
        int i=0,j=0,q=0;
        int x1[10],y1[10],ans[10];
        while(x/10>0)
        {
            x1[i]=x%10;
            x/=10;
            i++;
        }
        x1[i]=x;
        while(y/10>0)
        {
            y1[j]=y%10;
            y/=10;
            j++;
        }
        y1[j]=y;
        int m = max(i,j);
        for(int t=0;t<m;t++)
        {
            if(t>i)
                x1[t]=0;
            if(t>j)
                y1[t]=0;

            if(x1[t]-y1[t]<0)
            {
                ans[t]=y1[t]+x1[t]+10;
            }
            else ans[t] = ans[t]=y1[t]+x1[t];
        }
        for(int t=0;t<m;t++)
        {
            q+=ans[t]*pow(10,i);
        }
        return q;
    }
    int add(int x, int y)
    {
        int i=0,j=0,q=0;
        int x1[10],y1[10],ans[10];
        while(x/10>0)
        {
            x1[i]=x%10;
            x/=10;
            i++;
        }
        x1[i]=x;
        while(y/10>0)
        {
            y1[j]=y%10;
            y/=10;
            j++;
        }
        y1[j]=y;
        int m = max(i,j);
        for(int t=0;t<m;t++)
        {
            if(t>i)
                x1[t]=0;
            if(t>j)
                y1[t]=0;

            if(x1[t]+y1[t]>=10)
            {
                ans[t]=y1[t]+x1[t]-10;
            }
            else ans[t] = ans[t]=y1[t]+x1[t];
        }
        for(int t=0;t<m;t++)
        {
            q+=ans[t]*pow(10,i);
        }
        return q;
    }
};

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int q,w;
        Group *p;
        int type;
        cin>>type;
        int flag,m;
        string opra;
        cin>>opra;
        if(opra.find_first_of('+')>0)
        {
            m=opra.find_first_of('+');
            string str1=opra.substr(0,m);
            string str2=opra.substr(m+1,opra.length());

            q = atoi(str1.c_str());
            w = atoi(str2.c_str());
        }
        if(opra.find_first_of('-')>0)
        {
            m=opra.find_first_of('-');
            string str1=opra.substr(0,m);
            string str2=opra.substr(m+1,opra.length());

            q = atoi(str1.c_str());
            w = atoi(str2.c_str());
        }
        if(type==1)
        {
            GroupA a;
            p = &a;
        }
        else if(type==2)
        {
            GroupB q1;
            p = &q1;
        }
        else if(type == 3)
        {
            GroupC c;
            p = &c;
        }
        if(opra.find_first_of('+')>0)
            p->add(q,w);
        else p->sub(q,w);
    }

}

