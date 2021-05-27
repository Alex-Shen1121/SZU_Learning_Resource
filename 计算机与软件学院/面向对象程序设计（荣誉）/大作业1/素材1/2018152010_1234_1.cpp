2018152010:Problem1234:´ð°¸´íÎó
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

class Group
{
public:
    virtual int add(int x, int y)=0;
    virtual int sub(int x, int y)=0;
};

class Group1:public Group
{
public:
    int add(int x, int y){return x+y;}
    int sub(int x, int y){return x-y;}
};

class Group2:public Group
{
    int add(int x, int y){return x+y;}
    int sub(int x, int y)
    {
        int a,b,c;
        a=(x%10+10-y%10)%10;
        b=(((x/10)%10+10)-(y/10)%10)%10*10;
        c=(x/100)-(y/100)*100;
        return a+b+c;
    }
};

class Group3:public Group
{
    int add(int x, int y)
    {
        int a,b,c;
        a=(x%10+y%10)%10;
        b=(((x/10)%10+(y/10)%10)%10)*10;
        c=(((x/100)+(y/100))%10)*100;
        return a+b+c;
    }
    int sub(int x, int y)
    {
        int a,b,c;
        a=(x%10*10-y%10)%10;
        b=(((x/10)%10+10)-(y/10)%10)%10*10;
        c=(x/100)-(y/100);
        return a+b+c;
    }
};
int main()
{
    Group *p;
    Group1 p1;
    Group2 p2;
    Group3 p3;
    int n,a,b,m;
    char f;
    cin>>n;
    while(n--)
    {
        cin>>m>>a>>f>>b;
        if(m==1)
            p=&p1;
        else if(m==2)
            p=&p2;
        else
            p=&p3;
        if(f=='+')
            cout<<p->add(a,b)<<endl;
        else
            cout<<p->sub(a,b)<<endl;
    }
}

