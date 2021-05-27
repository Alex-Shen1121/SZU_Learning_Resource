2018152062:Problem1234:正确
#include <iostream>
using namespace std;
/*某小学二年级的数学老师在教学生整数加减法运算时发现：班上的同学可以分成三类，
第一类可以正确地完成加减法运算(GroupA)；第二类可以正确地完成加法运算，
但对于减法运算来说，总是忘记借位的处理(GroupB)；第三类总是忘记加法的进位，
也总是忘记减法的借位(GroupC)。（提示：小学二年级还没学负数。）
现在请模拟当老师在课堂提问某位同学时，同学会给出的回答。
实现时请基于下面的基类框架：*/

class Group
{
public:
    virtual int add(int x, int y)=0;//输出加法的运算结果
    virtual int sub(int x, int y)=0;//输出减法的运算结果
};
/*构建出GroupA, GroupB和GroupC三个派出类:
并编写主函数，要求主函数中有一个基类Group指针，通过该指针统一地进行add和sub运算*/
class GroupA:public Group
{
public:
    GroupA(){}
    int add(int x,int y)
    {
        return x+y;
    }
    int sub(int x,int y)
    {
        return x-y;
    }
};
class GroupB:public Group
{
public:
    GroupB(){}
    int add(int x,int y)
    {
        return x+y;
    }
    int sub(int x,int y)
    {
        int xx,yy;
        int sum=0;
        int cnt=1;
        while(1)
        {
            xx=x%10;
            yy=y%10;
            if(!x)
                break;
            if(xx<yy)
                xx=xx+10-yy;
            else
                xx-=yy;
            sum+=xx*cnt;
            cnt*=10;
            x=x/10;
            y=y/10;
        }
        return sum;
    }
};
class GroupC:public Group
{
public:
    GroupC(){}
    int add(int x,int y)
    {
        int xx,yy;
        int sum=0;
        int cnt=1;
        int tag;
        if(x<y)
        {
            tag=x;
            x=y;
            y=tag;
        }
        while(1)
        {
            xx=x%10;
            yy=y%10;
            if(!x)
                break;
            if(xx+yy>=10)
                xx=xx+yy-10;
            else
                xx+=yy;
            sum+=xx*cnt;
            cnt*=10;
            x=x/10;
            y=y/10;
        }
        return sum;
    }
    int sub(int x,int y)
    {
        int xx,yy;
        int sum=0;
        int cnt=1;
        while(1)
        {
            xx=x%10;
            yy=y%10;
            if(!x)
                break;
            if(xx<yy)
                xx=xx+10-yy;
            else
                xx-=yy;
            sum+=xx*cnt;
            cnt*=10;
            x=x/10;
            y=y/10;
        }
        return sum;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Group *p;
        int cnt;
        int x,y;
        char ch;
        cin>>cnt>>x>>ch>>y;
        if(cnt==1)
        {
            GroupA u;
            p=&u;
            if(ch=='+')
                cout<<p->add(x,y)<<endl;
            else
                cout<<p->sub(x,y)<<endl;
        }
        else if(cnt==2)
        {
            GroupB u;
            p=&u;
            if(ch=='+')
                cout<<p->add(x,y)<<endl;
            else
                cout<<p->sub(x,y)<<endl;
        }
        else
        {
            GroupC u;
            p=&u;
            if(ch=='+')
                cout<<p->add(x,y)<<endl;
            else
                cout<<p->sub(x,y)<<endl;
        }
    }
    return 0;
}

