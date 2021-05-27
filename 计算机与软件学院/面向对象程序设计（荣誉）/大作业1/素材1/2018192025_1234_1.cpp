2018192025:Problem1234:ÕýÈ·
#include<iostream>
#include<cstring>
#include<cmath>
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
        int flag=0,i=0;
        while(x || y)
        {

            flag+=((10+x%10-y%10)%10)*pow(10,i);
            x/=10;
            y/=10;
            i+=1;
        }
        return flag;
    }
};

class GroupC:public Group
{
public:
    virtual int add(int x, int y)
    {
        int flag=0,i=0;
        while(x || y)
        {
            flag+=((x%10+y%10)%10)*pow(10,i);
            x/=10;
            y/=10;
            i+=1;
        }
        return flag;
    }
    virtual int sub(int x, int y)
    {
        int flag=0,i=0;
        while(x || y)
        {

            flag+=((10+x%10-y%10)%10)*pow(10,i);
            x/=10;
            y/=10;
            i+=1;
        }
        return flag;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,sum,x,y;
        Group *pv;
        char ch;
        cin>>m;
        if(m==1)
        {
            GroupA ss;
            pv=&ss;
            cin>>x>>ch>>y;
            if(ch=='+')
                sum=pv->add(x,y);
            else
                sum=pv->sub(x,y);
        }
        else if(m==2)
        {
            GroupB ss;
            pv=&ss;
            cin>>x>>ch>>y;
            if(ch=='+')
                sum=pv->add(x,y);
            else
                sum=pv->sub(x,y);
        }
        else if(m==3)
        {
            GroupC ss;
            pv=&ss;
            cin>>x>>ch>>y;
            if(ch=='+')
                sum=pv->add(x,y);
            else
                sum=pv->sub(x,y);
        }
        cout<<sum<<endl;
    }

}

