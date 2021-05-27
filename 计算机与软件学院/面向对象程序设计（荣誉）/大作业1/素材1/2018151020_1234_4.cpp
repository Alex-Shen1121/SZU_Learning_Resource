2018151020:Problem1234:正确
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;
class Group
{

public:
    virtual int add(int x, int y)=0;//输出加法的运算结果
    virtual int sub(int x, int y)=0;//输出减法的运算结果
};
class GroupA:public Group
{
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
    int add(int x, int y)
    {
        return x+y;
    }
    int sub(int x, int y)
    {
        int time=0,sum=0,x_s,y_s;
        while(x||y)
        {
            x_s = x%10;
            y_s = y%10;
            int num=(x_s+10-y_s)%10;
            double ch=pow(10,time);
            sum += (int)ch*num;
            x = x/10;
            y = y/10;
            time++;
        }
        return sum;
    }
};
class GroupC:public Group
{
    int add(int x, int y)
    {
        int time=0,sum=0,x_s,y_s;
        while(x||y)
        {
            x_s = x%10;
            y_s = y%10;
            int num=(x_s+y_s)%10;
            double ch=pow(10,time);
            sum += (int)ch*num;
            //cout<<pow(10,time)<<endl;
            //cout<<"x_s = "<<x_s<<"  y_s =  "<<y_s<<"  sum=  "<<sum<<endl;
            x = x/10;
            y = y/10;
            time++;
        }
        return sum;
    }
    int sub(int x, int y)
    {
        int time=0,sum=0,x_s,y_s;
        while(x||y)
        {
            x_s = x%10;
            y_s = y%10;
            int num=(x_s+10-y_s)%10;
            double ch=pow(10,time);
            sum += (int)ch*num;
            x = x/10;
            y = y/10;
            time++;
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
        Group *P;
        int k,x,y;
        char order;
        cin>>k>>x>>order>>y;
        if(k==1)
        {
            GroupA *A = new GroupA;
            P = A;
        }
        else if(k==2)
        {
            GroupB *B = new GroupB;
            P = B;
        }
        else if(k==3)
        {
            GroupC *C = new GroupC;
            P = C;
        }
        if(order=='+')
            cout<<P->add(x,y)<<endl;
        else if(order=='-')
            cout<<P->sub(x,y)<<endl;
    }
    return 0;
}

