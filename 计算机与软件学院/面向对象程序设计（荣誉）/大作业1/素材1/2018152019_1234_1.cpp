2018152019:Problem1234:ÕıÈ·
#include <iostream>

#include<iomanip>

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
    virtual int add(int x,int y)
    {
        return x+y;
    }
    virtual int sub(int x,int y)
    {
        return x-y;
    }
};

class GroupB:public Group
{
public:
    virtual int add(int x,int y)
    {
        return x+y;
    }
    virtual int sub(int x,int y)
    {
        int ten=0,hundred=0,thousand=0;
        if((x%10)<(y%10))
        {
            ten+=10;
        }
        if((x%100)/10<(y%100)/10)
        {
            hundred+=100;
        }
        if((x%1000)/100<(y%1000)/100)
        {
            thousand+=1000;
        }
        return (x-y+ten+hundred+thousand);
    }
};

class GroupC:public Group
{
public:
    virtual int add(int x,int y)
    {
        int ten=0,hundred=0,thousand=0;
        if((x%10)+(y%10)>10)
        {
            ten-=10;
        }
        if((x%100)/10+(y%100)/10>10)
        {
            hundred-=100;
        }
        if((x%1000)/100+(y%1000)/100>10)
        {
            thousand-=1000;
        }
        return (x+y+ten+hundred+thousand);
    }
    virtual int sub(int x,int y)
    {
        int ten=0,hundred=0,thousand=0;
        if((x%10)<(y%10))
        {
            ten+=10;
        }
        if((x%100)/10<(y%100)/10)
        {
            hundred+=100;
        }
        if((x%1000)/100<(y%1000)/100)
        {
            thousand+=1000;
        }
        return (x-y+ten+hundred+thousand);
    }
};

int main()
{
    int times,type,x,y;
    char op;
    Group *p;
    GroupA a;
    GroupB b;
    GroupC c;
    cin>>times;
    while(times--)
    {
        cin>>type;
        if(type==1)
        {
            p=&a;
            cin>>x>>op>>y;
            if(op=='+')
                cout<<p->add(x,y)<<endl;
            else
                cout<<p->sub(x,y)<<endl;
        }
        else if(type==2)
        {
            p=&b;
            cin>>x>>op>>y;
            if(op=='+')
                cout<<p->add(x,y)<<endl;
            else
                cout<<p->sub(x,y)<<endl;
        }
        else
        {
            p=&c;
            cin>>x>>op>>y;
            if(op=='+')
                cout<<p->add(x,y)<<endl;
            else
                cout<<p->sub(x,y)<<endl;
        }
    }
    return 0;
}
