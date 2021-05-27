2017081130:Problem1234:´ð°¸´íÎó
#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;
class Group
{
public:
    Group(){};
    virtual int add(int x, int y)
    {
        return 1;
    }
    virtual int sub(int x, int y)
    {
        return 1;
    }

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
        int i,len,len1,l,j;
        char s[10],s1[10],s2[10],s3[10],s4[10];
        sprintf(s,"%d",x);
        sprintf(s1,"%d",y);
        len=strlen(s);
        len1=strlen(s1);
        if(len<len1)
        {
            l=len1;
            for(i=l-1,j=len-1;j>0;i--,j--)
            {
                s3[i]=s[j];
            }
            for(i=0;i<=(l-len);i++)
                s[i]='0';
            strcpy(s4,s1);
        }
        else
        {
            l=len;
            for(i=l-1,j=len1-1;j>=0;i--,j--)
            {
                s3[i]=s1[j];
            }
            for(i=0;i<=(l-len1)-1;i++)
                s3[i]='0';
            s3[l]='\0';
            strcpy(s4,s);
        }
        for(i=0;i<l;i++)
        {
            if(s4[i]>s3[i])
                s2[i]=((s4[i]-'0')-(s3[i]-'0'))+'0';
            else
                s2[i]=((s4[i]-'0')+10-(s3[i]-'0'))+'0';
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
        int i,len,len1,l,j;
        char s[10],s1[10],s2[10],s3[10],s4[10];
        sprintf(s,"%d",x);
        sprintf(s1,"%d",y);
        len=strlen(s);
        len1=strlen(s1);
        if(len<len1)
        {
            l=len1;
            for(i=l-1,j=len-1;j>0;i--,j--)
            {
                s3[i]=s[j];
            }
            for(i=0;i<=(l-len);i++)
                s[i]='0';
            strcpy(s4,s1);
        }
        else
        {
            l=len;
            for(i=l-1,j=len1-1;j>=0;i--,j--)
            {
                s3[i]=s1[j];
            }
            for(i=0;i<=(l-len1)-1;i++)
                s3[i]='0';
            s3[l]='\0';
            strcpy(s4,s);
        }
        for(i=0;i<l;i++)
        {
            s2[i]=((s4[i]-'0')+(s3[i]-'0'))%10+'0';
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
        int i,len,len1,l,j;
        char s[10],s1[10],s2[10],s3[10],s4[10];
        sprintf(s,"%d",x);
        sprintf(s1,"%d",y);
        len=strlen(s);
        len1=strlen(s1);
        if(len<len1)
        {
            l=len1;
            for(i=l-1,j=len-1;j>0;i--,j--)
            {
                s3[i]=s[j];
            }
            for(i=0;i<=(l-len);i++)
                s[i]='0';
            strcpy(s4,s1);
        }
        else
        {
            l=len;
            for(i=l-1,j=len1-1;j>=0;i--,j--)
            {
                s3[i]=s1[j];
            }
            for(i=0;i<=(l-len1)-1;i++)
                s3[i]='0';
            s3[l]='\0';
            strcpy(s4,s);
        }
        for(i=0;i<l;i++)
        {
            if(s4[i]>s3[i])
                s2[i]=((s4[i]-'0')-(s3[i]-'0'))+'0';
            else
                s2[i]=((s4[i]-'0')+10-(s3[i]-'0'))+'0';
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

