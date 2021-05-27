2018041051:Problem1234:ÕıÈ·
#include<iostream>
#include<string>
#include<cstring>
 
using namespace std;
 
class Group
{
 
public:
 
    virtual int add(int x, int y)=0;
 
    virtual int sub(int x, int y)=0;

	virtual ~Group(){}
};
 
class GroupA:public Group{
public:
    int add(int x, int y)
    {
        return x+y;
    }
    int sub(int x, int y)
    {
        return x-y;
    }
    ~GroupA(){}
};
 
class GroupB:public Group{
public:
    int add(int x, int y)
    {
        return x+y;
    }
    int sub(int x, int y)
    {
        int result=0,flag1=0,flag2=0;
        result=x-y;
        if(x%10<y%10)
        {
            flag1=1;
        }
        if(x%100<y%100)
        {
            flag2=1;
        }
        result=result+flag1*10+flag2*100;
    }
    ~GroupB(){}
};
 
class GroupC:public Group{
public:
    int add(int x, int y)
    {
        int result=0,flag1=0,flag2=0;
        result=x+y;
        if((x%10+y%10)>=10)
        {
            flag1=1;
        }
        if((x%100+y%100)>=100)
        {
            flag2=1;
        }
        result=result-flag1*10-flag2*100;
    }
    int sub(int x, int y)
    {
        int result=0,flag1=0,flag2=0;
        result=x-y;
        if(x%10<y%10)
        {
            flag1=1;
        }
        if(x%100<y%100)
        {
            flag2=1;
        }
        result=result+flag1*10+flag2*100;
    }
    ~GroupC(){}
};
 
int main()
{
    Group *G;
    int t;
    cin>>t;
 
    while(t--)
    {
        int n,num1,num2;
        char c;
        cin>>n>>num1>>c>>num2;
        if(n==1)
            G=new GroupA; 
        else if(n==2)
            G=new GroupB;
        else
            G=new GroupC;
        if(c=='+')
            cout<<G->add(num1,num2)<<endl;
        else
            cout<<G->sub(num1,num2)<<endl;
        delete G;
    }
    
     
    return 0;
}
