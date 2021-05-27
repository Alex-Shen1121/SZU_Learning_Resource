2017182013:Problem1234:编译错误
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
    int add(int x, int y)//输出加法的运算结果
    {
        return x+y;
    }
    int sub(int x, int y)//输出减法的运算结果
    {
        return x-y;
    }
};
class GroupB:public Group
{
public:
    int add(int x, int y)//输出加法的运算结果
    {
        return x+y;
    }
    int sub(int x, int y)//输出减法的运算结果
    {
        int xv,yv;
        xv = x/10;
        x %= 10;
        yv = y/10;
        y %= 10;
        if(x-y<0)
        {
            x+=10;
        }
        return (xv-yx)*10+x-y;
    }
};
class GroupC:public Group
{
public:
    int add(int x, int y)//输出加法的运算结果
    {
        int xv,yv;
        xv = x/10;
        x %= 10;
        yv = y/10;
        y %= 10;
        if(x+y>10)
        {
            x-=10;
        }
        if(xv+yv>10)
        {
            xv-=10;
        }
        return (xv+yx)*10+x+y;
    }
    int sub(int x, int y)//输出减法的运算结果
    {
        int xv,yv;
        xv = x/10;
        x %= 10;
        yv = y/10;
        y %= 10;
        if(x-y<0)
        {
            x+=10;
        }
        return (xv-yx)*10+x-y;
    }
};
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        Group *g;
        int type;
        cin>>type;
        if(type==1)
        {
            GroupA a;
            g = &a;
            string str;
            cin>>str;
            int x=0,y=0,i;
            for(i=0;str[i]!='-'||str[i]!='+'; i++)
            {
                x=str[i]-'0'+x*10;
            }
            for(i=i+1;i<str.length(); i++)
            {
                y=str[i]-'0'+y*10;
            }
        }
    }
    return 0;
}

