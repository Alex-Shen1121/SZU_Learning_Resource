2018152100:Problem1234:正确
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int pow(int a)
{
    if (a==0)
        return 1;
    else return 10*pow(a-1);
}

class Group
{
protected:
public:
    Group(){}
    virtual int add(int x, int y)=0;//输出加法的运算结果
    virtual int sub(int x, int y)=0;//输出减法的运算结果
};

class GroupA:public Group
{
public:
    GroupA(){}
    virtual int add(int x, int y)
    {
        return x+y;
    }
    virtual int sub(int x, int y)
    {
        return x-y;
    }
};

class GroupB:public Group
{
public:
    GroupB(){}
    virtual int add(int x, int y)
    {
        return x+y;
    }
    virtual int sub(int x, int y)
    {
        int ans=0,i=0;
        while (x!=0)
        {
            int m;
            if (y!=0)
            {
                if (x%10<y%10)
                {
                    m=x%10-y%10+10;
                }
                else m=x%10-y%10;
                y/=10;

            }
            else m=x%10;
            ans+=m*pow(i);
            i++;
            x/=10;
        }
        return ans;
    }
};

class GroupC:public Group
{
public:
    GroupC(){}
    virtual int add(int x, int y)
    {
        int ans=0,i=0;
        while (x!=0)
        {
            int m;
            m=(x%10+y%10)%10;
            ans+=m*pow(i++);
            x/=10;y/=10;
        }
        return ans;
    }
    virtual int sub(int x, int y)
    {
        int ans=0,i=0;
        while (x!=0)
        {
            int m;
            if (y!=0)
            {
                if (x%10<y%10)
                {
                    m=x%10-y%10+10;
                }
                else m=x%10-y%10;
                y/=10;

            }
            else m=x%10;
            ans+=m*pow(i);
            i++;
            x/=10;
        }
        return ans;
    }
};

int main()
{
    int t,m;
    cin >> t;
    Group *p;
    int x,y;
    char ch;
    while (t--)
    {
        cin >> m;
        cin >> x >> ch >> y;
        if (x<y)swap(x,y);
        if (m==1){GroupA aa;p=&aa;}
        else if (m==2) {GroupB bb;p=&bb;}
        else {GroupC cc;p=&cc;}
        if (ch=='+')
            cout << p->add(x,y) << endl;
        else cout << p->sub(x,y) << endl;

    }
    return 0;
}

