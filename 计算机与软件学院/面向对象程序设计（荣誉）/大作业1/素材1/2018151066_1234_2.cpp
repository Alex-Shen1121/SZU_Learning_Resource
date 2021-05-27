2018151066:Problem1234:正确
#include<iostream>
using namespace std;
class Group
{
public :
    virtual int add(int x, int y)=0;//输出加法的运算结果
    virtual int sub(int x, int y)=0;//输出减法的运算结果
};
class GroupA:public Group
{
public :
    int add(int x,int y)
    {
        return x+y;
    }
    int sub(int x,int y)
    {
        return x-y;
    }
};
void display(int *t,int n)
{
    for(int i=0; i<n; i++)
        cout<<t[i];
    cout<<endl;
}
class GroupB:public Group
{
public:
    int add(int x,int y)
    {
        return x+y;
    }
    int sub(int x,int y)
    {
        int  *x_=new int;
        int  *y_=new int;
        int len_x=0,len_y=0;
        while(x)
        {
            x_[len_x++]=x%10;
            x/=10;
        }

        while(y)
        {
            y_[len_y++]=y%10;
            y/=10;
        }

        for(int i=0; i<len_y; i++)
        {
            x_[i]-=y_[i];
            if(x_[i]<0)
                x_[i]+=10;
        }

        int ans=0;
        for(int i=0; i<len_x; i++)
        {

            ans=ans*10+x_[len_x-i-1];
        }

        return ans;
    }
};

class GroupC:public Group
{
public:
    int add(int x,int y)
    {
        int  *x_=new int;
        int  *y_=new int;
        int len_x=0,len_y=0;
        while(x)
        {
            x_[len_x++]=x%10;
            x/=10;
        }
        while(y)
        {
            y_[len_y++]=y%10;
            y/=10;
        }
        int len_m=(len_y>len_x?len_y:len_x);
        int *c=new int[len_m];
        for(int i=0; i<len_y+len_x-len_m; i++)
        {
            c[i]=x_[i]+y_[i];
            if(c[i]>9)
                c[i]-=10;
        }
        if(len_y>len_x)
        {
            for(int i=len_y+len_x-len_m; i<len_m; i++)
                c[i]=y_[i];
        }
        else
        {
            for(int i=len_y+len_x-len_m; i<len_m; i++)
                c[i]=x_[i];
        }
        int ans=0;
        for(int i=0; i<len_m; i++)
        {

            ans=ans*10+c[len_m-i-1];
        }
        return ans;
    }
    int sub(int x,int y)
    {
        int  *x_=new int;
        int  *y_=new int;
        int len_x=0,len_y=0;
        while(x)
        {
            x_[len_x++]=x%10;
            x/=10;
        }
        while(y)
        {
            y_[len_y++]=y%10;
            y/=10;
        }
        for(int i=0; i<len_y; i++)
        {
            x_[i]-=y_[i];
            if(x_[i]<0)
                x_[i]+=10;
        }
        int ans=0;
        for(int i=0; i<len_x; i++)
        {

            ans=ans*10+x_[len_x-i-1];
        }
        return ans;
    }
};
int main()
{
    int t;
    cin>>t;
    Group *group;
    while(t--)
    {
        int type;
        cin>>type;
        int x,y;
        char cmd;
        cin>>x>>cmd>>y;
        if(type==1)
        {
            group=new GroupA;

        }
        else if(type==2)
        {
            group=new GroupB;
        }
        else if(type==3)
        {
            group=new GroupC;
        }
        if(cmd=='+')
            cout<<group->add(x,y)<<endl;
        else
            cout<<group->sub(x,y)<<endl;
    }
}

