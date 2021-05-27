2018152021:Problem1234:正确
#include<iostream>
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
    int add(int x,int y)
	{
        return x+y;
    }
    int sub(int x,int y)
	{
        int sum=x-y;
        if(x%10<y%10)
            sum+=10;
        if(x%100<y%100)
            sum+=100;   
        return sum;
    }
};
class GroupC:public Group
{
public:
    int add(int x,int y)
	{
        int sum=x+y;
        if(x%10+y%10>10)
            sum-=10;
        if(x%100+y%100>100)
            sum-=100;
            return sum;
	}
    int sub(int x,int y)
	{
        int sum=x-y;
        if(x%10<y%10)
            sum+=10;
        if(x%100<y%100)
            sum+=100;   
        return sum;
	}
};
int main()
{
    int t;
	cin >> t;
    int a,b,c;
    char d;
    Group *p;
    while(t--)
    {
        cin >> a >> b >> d >> c;
        if(a==1)
            p=new GroupA();
        else if(a==2)
            p=new GroupB();
        else if(a==3)
            p=new GroupC();
        if(d=='+')
            cout << p->add(b,c) << endl;
        else
            cout << p->sub(b,c) << endl;
    }
    return 0;
}
