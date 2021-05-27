2018152108:Problem1234:ÕýÈ·
#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
#include<cstdio>
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
	int add(int x, int y)
	{
		return x+y;
	}
	int sub(int x, int y)
	{
		int result=0,time=1,per,a,b;
		while(x!=0||y!=0)
		{
			a=x%10;
			b=y%10;
			if(a>b)
				per=(a-b);
			else
				per=(a+10-b);
			result=result+time*per;
			time*=10;
			x/=10;
			y/=10;
		}
		return result;
	}
};

class GroupC:public Group
{
public:
	int add(int x, int y)
	{
		int result=0,time=1,per,a,b;
		while(x!=0||y!=0)
		{
			a=x%10;
			b=y%10;
			per=(a+b)%10;
			result=result+time*per;
			time*=10;
			x/=10;
			y/=10;
		}
		return result;
	}
	int sub(int x, int y)
	{
		int result=0,time=1,per,a,b;
		while(x!=0||y!=0)
		{
			a=x%10;
			b=y%10;
			if(a>b)
				per=(a-b);
			else
				per=(a+10-b);
			result=result+time*per;
			time*=10;
			x/=10;
			y/=10;
		}
		return result;
	}
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int type,x,y,i,j;
		string ss,xx,yy,cz;
		Group *p;
		cin>>type>>ss;
		for(i=0;i<ss.size();i++)
		{
			if(ss[i]=='+'||ss[i]=='-')
			{
				cz=ss[i];
				for(j=i+1;j<ss.size();j++)
				{
					yy+=ss[j];
				}
				break;
			}
			else
			{
				xx+=ss[i];
			}
		}
		x=atoi(xx.c_str());
		y=atoi(yy.c_str()); 
		if(type==1)
		{
			p = new GroupA;
			if(cz=="+")
			{
				cout<<p->add(x,y)<<endl;
			}
			if(cz=="-")
			{
				cout<<p->sub(x,y)<<endl;
			}
		}
		if(type==2)
		{
			p = new GroupB;
			if(cz=="+")
			{
				cout<<p->add(x,y)<<endl;
			}
			if(cz=="-")
			{
				cout<<p->sub(x,y)<<endl;
			}
		}
		if(type==3)
		{
			p = new GroupC;
			if(cz=="+")
			{
				cout<<p->add(x,y)<<endl;
			}
			if(cz=="-")
			{
				cout<<p->sub(x,y)<<endl;
			}
		}
	}
	return 0;
}
