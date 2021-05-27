2017081130:Problem1234:答案错误
#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;
class Group
{
public:
    Group(){};
    virtual int add(int x, int y)=0;//输出加法的运算结果
    virtual int sub(int x, int y)=0;//输出减法的运算结果

};
class GroupA:virtual public Group
{
public:
    GroupA(){};
    int add(int x,int y)
    {
        return x+y;
    }
    int sub(int x,int y)
    {
        return x-y;
    }

};
class GroupB:virtual public Group
{
public:
    GroupB(){};
    int add(int x,int y)
    {
        return x+y;
    }
    int sub(int x,int y)
    {
        int len,len1,i;
        char s[10],s1[10],s2[10];
        sprintf(s,"%d",x);
        sprintf(s1,"%d",y);
        len=strlen(s);
        len1=strlen(s1);
        if(len<len1)
            len=len1;
        for(i=0;i<len;i++)
        {
            if(s[i]>s1[i])
                s2[i]=((s[i]-'0')-(s1[i]-'0'))+'0';
            else
                s2[i]=((s[i]-'0')+10-(s1[i]-'0'))+'0';
        }
        s2[i]='\0';
        int sum=0;
        for(i=0;s2[i]!='\0';i++)
        {
            sum=sum*10+(s2[i]-'0');
        }
        return sum;
    }
};
class GroupC:virtual public Group
{
public:
    GroupC(){};
    int add(int x,int y)
    {
        int i;
        char s[10],s1[10],s2[10];
        sprintf(s,"%d",x);
        sprintf(s1,"%d",y);
        for(i=0;s1[i]!='\0'&&s[i]!='\0';i++)
        {
            s2[i]=((s1[i]-'0')+(s[i]-'0'))+'0';
        }
        s2[i]='\0';
        int sum=0;
        for(i=0;s2[i]!='\0';i++)
        {
            sum=sum*10+(s2[i]-'0');
        }
        return sum;
    }
    int sub(int x,int y)
    {
        int len,len1,i;
        char s[10],s1[10],s2[10];
        sprintf(s,"%d",x);
        sprintf(s1,"%d",y);
        len=strlen(s);
        len1=strlen(s1);
        if(len<len1)
            len=len1;
        for(i=0;i<len;i++)
        {
            if(s[i]>s1[i])
                s2[i]=((s[i]-'0')-(s1[i]-'0'))+'0';
            else
                s2[i]=((s[i]-'0')+10-(s1[i]-'0'))+'0';
        }
        s2[i]='\0';
        int sum=0;
        for(i=0;s2[i]!='\0';i++)
        {
            sum=sum*10+(s2[i]-'0');
        }
        return sum;
    }
};
int main()
{
    int t,x,y,level;
    char ch;
    cin>>t;
    while(t--)
    {
        Group *g;
        cin>>level;
        cin>>x>>ch>>y;
        if(level==1)
        {
            GroupA ga;
            g=&ga;
            if(ch=='+')
                cout<<g->add(x,y)<<endl;
            else
                cout<<g->sub(x,y)<<endl;
        }
        else if(level==2)
        {
            GroupB gb;
            g=&gb;
            if(ch=='+')
                cout<<g->add(x,y)<<endl;
            else
                cout<<g->sub(x,y)<<endl;
        }
        else if(level==3)
        {
            GroupC gc;
            g=&gc;
            if(ch=='+')
                cout<<g->add(x,y)<<endl;
            else
                cout<<g->sub(x,y)<<endl;
        }
    }
}

