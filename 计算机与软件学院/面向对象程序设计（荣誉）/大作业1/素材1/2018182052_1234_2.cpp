2018182052:Problem1234:ÕýÈ·
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <iomanip>
#define ADDRESS "C:\\Users\\241\\Desktop\\in.txt","r",stdin
using namespace std;
class Group
{
public:
    virtual int add(int x,int y)=0;
    virtual int sub(int x,int y)=0;
    virtual ~Group(){}
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
    virtual ~GroupA(){};
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
        int temp=x-y;
        int wei=1;
        while(y>0&&x>0)
        {
            if(x%10<y%10)
                temp+=pow(10,wei);
            x/=10;
            y/=10;
            ++wei;
        }
        return temp;
    }
    virtual ~GroupB(){}
};
class GroupC:public Group
{
public:
    virtual int add(int x,int y)
    {
        int temp=x+y;
        int wei=1;
        while(x>0&&y>0)
        {
            if(x%10+y%10>=10)
                temp-=pow(10,wei);
            x/=10;
            y/=10;
            ++wei;
        }
        return temp;
    }
    virtual int sub(int x,int y)
    {
        int temp=x-y;
        int wei=1;
        while(y>0&&x>0)
        {
            if(x%10<y%10)
                temp+=pow(10,wei);

            x/=10;
            y/=10;
            ++wei;
        }
        return temp;
    }
    virtual ~GroupC(){}
};
void get_num(char str[],int &x,int &y,int &type)
{
    int cur=0;
    int n=strlen(str);
    while(str[cur]>='0'&&str[cur]<='9')
    {
        x=x*10+str[cur]-'0';
        ++cur;
    }
    if(str[cur]=='+')
        type=1;
    else if(str[cur]=='-')
        type=2;
    ++cur;
    while(cur<n)
    {
        y=y*10+str[cur]-'0';
        ++cur;
    }
}
int main()
{
 //   freopen(ADDRESS);
    int T(0);
    cin>>T;
    Group *pp;
    char str[20];
    while(T--)
    {
        int cmd(0);
        int x(0),y(0),type(0);
        cin>>cmd;
        if(cmd==1)
            pp=new GroupA;
        else if(cmd==2)
            pp=new GroupB;
        else if(cmd==3)
            pp=new GroupC;
        cin>>str;
        get_num(str,x,y,type);
        if(type==1)
            cout<<pp->add(x,y)<<endl;
        else if(type==2)
            cout<<pp->sub(x,y)<<endl;
        delete pp;
    }
    return 0;
}
