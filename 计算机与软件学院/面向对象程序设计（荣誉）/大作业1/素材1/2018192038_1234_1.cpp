2018192038:Problem1234:正确
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
    int add(int x, int y)
    {
        return x+y;
    }
    int sub(int x, int y)
    {
        int t=1;
        int var;
        int t1,t2,sum=0;
        while(1)
        {
            t1=x%10;
            t2=y%10;
            if(t1<t2)
            {
                var=t1+10-t2;
            }
            else
            {
                var=t1-t2;
            }
            sum+=var*t;
            t*=10;
            x/=10;
            y/=10;
            if(x==0)
            {
                break;
            }
        }
        return sum;
    }
};

class GroupC:public Group
{
public:
    int add(int x, int y)
    {
        int t=1;
        int var;
        int t1,t2,sum=0;
        if(x<y)
        {
            int temp;
            temp=x;
            x=y;
            y=temp;
        }
        while(1)
        {
            t1=x%10;
            t2=y%10;
            var=(t1+t2)%10;
            sum+=var*t;
            t*=10;
            x/=10;
            y/=10;
            if(x==0)
            {
                break;
            }
        }
        return sum;
    }
    int sub(int x, int y)
    {
        int t=1;
        int var;
        int t1,t2,sum=0;
        while(1)
        {
            t1=x%10;
            t2=y%10;
            if(t1<t2)
            {
                var=t1+10-t2;
            }
            else
            {
                var=t1-t2;
            }
            sum+=var*t;
            t*=10;
            x/=10;
            y/=10;
            if(x==0)
            {
                break;
            }
        }
        return sum;
    }
};

int main()
{
    int t;
    int type;
    int x,y;
    char ch;
    cin>>t;
    Group *p=NULL;
    while(t--)
    {
        cin>>type;
        if(type==1)
        {
            GroupA one;
            p=&one;
            cin>>x>>ch>>y;
            if(ch=='+')
            {
                cout<<p->add(x,y)<<endl;
            }
            else if(ch=='-')
            {
                cout<<p->sub(x,y)<<endl;
            }
        }
        else if(type==2)
        {
            GroupB one;
            p=&one;
            cin>>x>>ch>>y;
            if(ch=='+')
            {
                cout<<p->add(x,y)<<endl;
            }
            else if(ch=='-')
            {
                cout<<p->sub(x,y)<<endl;
            }
        }
        else if(type==3)
        {
            GroupC one;
            p=&one;
            cin>>x>>ch>>y;
            if(ch=='+')
            {
                cout<<p->add(x,y)<<endl;
            }
            else if(ch=='-')
            {
                cout<<p->sub(x,y)<<endl;
            }
        }
    }
    return 0;
}

