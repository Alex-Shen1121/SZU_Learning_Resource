2018151051:Problem1234:ÕýÈ·
#include<iostream>
#include<cmath>
using namespace std;
class Group
{
public:
	virtual int add(int x,int y)=0;
	virtual int sub(int x,int y)=0;
};
class GroupA:public Group
{
public:
	virtual int add(int x,int y)
	{
		return x+y;
	}
	virtual int sub(int x,int y)
	{
		return x-y;
	}
};
class GroupB:public Group
{
public:
	virtual int add(int x,int y)
	{
		return x+y;
	}
	virtual int sub(int x,int y)
	{
		int flag=0,i;
		for(i=0;x!=0||y!=0;i++)
		{
			int m,n;
			m=x%10;
			n=y%10;
			if(m-n<0)
				m=10+m;
			flag=flag+(m-n)*pow(10,i);
			x=x/10;
			y=y/10;
		}
		return flag;
	}
};
class GroupC:public Group
{
public:
	virtual int add(int x,int y)
	{
		int flag=0,i;
		for(i=0;x!=0||y!=0;i++)
		{
			int m,n;
			m=x%10;
			n=y%10;
			if(m+n>=10)
				flag=flag+(m+n-10)*pow(10,i);
			else if(m+n<10)
				flag=flag+(m+n)*pow(10,i);
			x=x/10;
			y=y/10;
		}
		return flag;
	}
	virtual int sub(int x,int y)
	{
		int flag=0,i;
		for(i=0;x!=0||y!=0;i++)
		{
			int m,n;
			m=x%10;
			n=y%10;
			if(m-n<0)
				m=10+m;
			flag=flag+(m-n)*pow(10,i);
			x=x/10;
			y=y/10;
		}
		return flag;
	}
};
int main()
{
	int n,i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		int type;
		int x,y;
		char ask;
		cin>>type;
		cin>>x>>ask>>y;
		Group *p;
		if(type==1)
			p=new GroupA;
		else if(type==2)
			p=new GroupB;
		else if(type==3)
			p=new GroupC;
		if(ask=='+')
			cout<<p->add(x,y)<<endl;
		else if(ask=='-')
			cout<<p->sub(x,y)<<endl;
		delete p;
	}
}
