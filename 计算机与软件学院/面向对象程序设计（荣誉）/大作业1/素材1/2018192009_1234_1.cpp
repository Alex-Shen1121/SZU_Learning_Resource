2018192009:Problem1234:´ð°¸´íÎó
#include <iostream>
#include <cmath>
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
    virtual int add(int x, int y){return x+y;}
    virtual int sub(int x, int y){return x-y;}
};
class GroupB:public Group
{
public:
    virtual int add(int x, int y){return x+y;}
    virtual int sub(int x, int y)
    {
        int wei=1;
        int i,yy;
        int xx=x;
        while(xx/10>=10)
        {
            wei++;
            xx=xx/10;
        }
        int *x1=new int[wei];
        x1[wei-1]=x/pow(10,wei-1);
        int *y1=new int[wei];
        //y1[0]=y%10;
        int *answer=new int[wei];
        xx=x;
        yy=y;
        for(i=0;i<wei-1;i++)
        {
            x1[i]=xx%10;
            xx=xx/10;
        }
        for(i=0;i<wei-1;i++)
        {
            y1[i]=y%10;
            yy=yy/10;
        }
        for(i=0;i<wei;i++)
            answer[i]=(int)abs(x1[i]-y1[i]);
        int an=0;
        for(i=0;i<wei;i++)
            an+=answer[i]*pow(10,i);
        return an;
    }
};
int main()
{
    int t;
    cin>>t;
    int a,b,level;
    char m;
    Group *p;
    while(t--)
    {
        cin>>level>>a>>m>>b;
        if(level==1)
        {
            GroupA aa;
            p=&aa;
            if(m=='+')
                cout<<p->add(a,b)<<endl;
            else
                cout<<p->sub(a,b)<<endl;
        }
        else if(level==2)
        {
            GroupB bb;
            p=&bb;
            if(m=='+')
                cout<<p->add(a,b)<<endl;
            else
                cout<<p->sub(a,b)<<endl;
        }
    }
    return 0;
}

