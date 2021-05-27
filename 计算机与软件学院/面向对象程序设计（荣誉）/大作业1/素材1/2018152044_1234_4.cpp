2018152044:Problem1234:ÕýÈ·
#include<iostream>
#include<cmath>
using namespace std;
class Group
{
public:
    virtual int add(int x,int y)=0;
    virtual int sub(int x,int y)=0;
};
class GroupA:public Group
{
public:
    GroupA()
    {
    }
    int add(int x,int y)
    {
        int resadd=x+y;
        return resadd;
    }
    int sub(int x,int y)
    {
        int ressub=x-y;
        return ressub;
    }
};
class GroupB:public Group
{
public:
    GroupB()
    {
    }
    int add(int x,int y)
    {
        int resadd=x+y;
        return resadd;
    }
    int sub(int x,int y)
    {
        int ressub=0;
        int sub[50]={0};
        int savex[50]={0};
        int n=1;
        int tempx=x;
        while(tempx/10!=0)
        {
            n++;
            tempx/=10;
        }
        for(int i=n-1;i>=0;i--)
        {
            savex[i]=x%10;
            x/=10;
        }
        int savey[50]={0};
        int m=1;
        int tempy=y;
        while(tempy/10!=0)
        {
            m++;
            tempy/=10;
        }
        for(int i=n-1;i>=0;i--)
        {
            savey[i]=y%10;
            y/=10;
        }
        for(int i=n-1;i>=0;i--)
        {
            sub[i]=(savex[i]+10-savey[i])%10;
        }
        for(int i=n-1;i>=0;i--)
        {
            ressub+=sub[i]*pow(10,n-1-i);
        }
        return ressub;
    }
};
class GroupC:public Group
{
public:
    GroupC()
    {
    }
    int add(int x,int y)
    {
        int resadd=0;
        int add[50]={0};
        int savex[50]={0};
        int n=1;
        int tempx=x;
        while(tempx/10!=0)
        {
            n++;
            tempx/=10;
        }
        int savey[50]={0};
        int m=1;
        int tempy=y;
        while(tempy/10!=0)
        {
            m++;
            tempy/=10;
        }
        if(m>n)
            n=m;
        for(int i=n-1;i>=0;i--)
        {
            savex[i]=x%10;
            x/=10;
        }
        for(int i=n-1;i>=0;i--)
        {
            savey[i]=y%10;
            y/=10;
        }
        for(int i=n-1;i>=0;i--)
        {
            add[i]=(savex[i]+savey[i])%10;
        }
        for(int i=n-1;i>=0;i--)
        {
            resadd+=add[i]*pow(10,n-1-i);
        }
        return resadd;
    }
    int sub(int x,int y)
    {
        int ressub=0;
        int sub[50]={0};
        int savex[50]={0};
        int n=1;
        int tempx=x;
        while(tempx/10!=0)
        {
            n++;
            tempx/=10;
        }
        for(int i=n-1;i>=0;i--)
        {
            savex[i]=x%10;
            x/=10;
        }
        int savey[50]={0};
        int m=1;
        int tempy=y;
        while(tempy/10!=0)
        {
            m++;
            tempy/=10;
        }
        for(int i=n-1;i>=0;i--)
        {
            savey[i]=y%10;
            y/=10;
        }
        for(int i=n-1;i>=0;i--)
        {
            sub[i]=(savex[i]+10-savey[i])%10;
        }
        for(int i=n-1;i>=0;i--)
        {
            ressub+=sub[i]*pow(10,n-1-i);
        }
        return ressub;
    }
};

int main()
{
    int n;
    cin>>n;
    Group *s[1000];
    for(int i=0;i<n;i++)
    {
        int type;
        cin>>type;
        int x,y;
        char op;
        cin>>x>>op>>y;
        if(type==1)
        {
            s[i]=new GroupA();
            if(op=='+')
                cout<<s[i]->add(x,y)<<endl;
            else if(op=='-')
                cout<<s[i]->sub(x,y)<<endl;
        }
        else if(type==2)
        {
            s[i]=new GroupB();
            if(op=='+')
                cout<<s[i]->add(x,y)<<endl;
            else if(op=='-')
                cout<<s[i]->sub(x,y)<<endl;
        }
        else if(type==3)
        {
            s[i]=new GroupC();
            if(op=='+')
                cout<<s[i]->add(x,y)<<endl;
            else if(op=='-')
                cout<<s[i]->sub(x,y)<<endl;
        }
    }
    for(int i=0;i<n;i++)
        delete s[i];
    return 0;
}
