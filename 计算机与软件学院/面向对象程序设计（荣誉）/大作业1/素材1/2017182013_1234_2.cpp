2017182013:Problem1234:正确
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
        int _x,_y,xv,yv;
        _x = x/100;
        x %= 100;
        _y = y/100;
        y %= 100;
        xv = x/10;
        x %= 10;
        yv = y/10;
        y %= 10;
        if(x-y<0)
        {
            x+=10;
        }
        if(xv-yv<0)
        {
            xv+=10;
        }
        return (_x-_y)*100+(xv-yv)*10+x-y;
    }
};
class GroupC:public Group
{
public:
    int add(int x, int y)//输出加法的运算结果
    {
        int _x,_y,xv,yv;
        _x = x/100;
        x %= 100;
        _y = y/100;
        y %= 100;
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
        if(_x+_y>10)
        {
            _x-=10;
        }
        return (_x+_y)*100+(xv+yv)*10+x+y;
    }
    int sub(int x, int y)//输出减法的运算结果
    {
        int _x,_y,xv,yv;
        _x = x/100;
        x %= 100;
        _y = y/100;
        y %= 100;
        xv = x/10;
        x %= 10;
        yv = y/10;
        y %= 10;
        if(x-y<0)
        {
            x+=10;
        }
        if(xv-yv<0)
        {
            xv+=10;
        }
        return (_x-_y)*100+(xv-yv)*10+x-y;
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
        string str;
        cin>>str;
        int x=0,y=0,i;
        for(i=0; str[i]>='0'&& str[i]<='9'; i++)
        {
            x=str[i]-'0'+x*10;
            //cout<<x<<endl;
        }
        int way =i;
        for(i=i+1; i<str.length(); i++)
        {
            y=str[i]-'0'+y*10;
            //cout<<y<<endl;
        }
        if(type==1)
        {
            GroupA a;
            g = &a;
            if(str[way] == '+')
                cout<<g->add(x,y)<<endl;
            else
                cout<<g->sub(x,y)<<endl;
        }
        else if(type == 2)
        {
            GroupB b;
            g = &b;
            if(str[way]== '+')
                cout<<g->add(x,y)<<endl;
            else
                cout<<g->sub(x,y)<<endl;
        }
        else if(type == 3)
        {
            GroupC c;
            g = &c;
            if(str[way]== '+')
                cout<<g->add(x,y)<<endl;
            else
                cout<<g->sub(x,y)<<endl;
        }
    }
    return 0;
}

