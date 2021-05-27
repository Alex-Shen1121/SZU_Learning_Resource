2016102048:Problem1234:答案错误
#include <bits/stdc++.h>
using namespace std;

class Group
{ 

public:

	virtual int add(int x, int y)=0;//输出加法的运算结果
	virtual int sub(int x, int y)=0;//输出减法的运算结果
	Group(){
	}

	~Group(){
	}
};

class GroupA:public Group 
{
public:
	GroupA()
	{
	}
	virtual int add(int x, int y)
	{
		return x+y;
	}
	virtual int sub(int x, int y)
	{
		return x-y;
	}	
	~GroupA()
	{
	}
};

class GroupB:public Group
{

public:
	GroupB()
	{
	}
	virtual int add(int x, int y)
	{
		return x+y;
	}
	virtual int sub(int x, int y)
	{
		int i,j;
		int xv=x,yv=y;
		int a[20],b[20],c[20],n;
		memset(a,0,sizeof(int)*20);
		memset(b,0,sizeof(int)*20);
		memset(c,0,sizeof(int)*20);
		for(i=0;;i++)
		{
			a[i]=xv%10;
			//cout<<"xv"<<a[i]<<endl;
			if(xv<10)
				break;
			xv=xv/10;
			
		}
		n=i;
		for(i=0;;i++)
		{
			b[i]=yv%10;
			//cout<<"yv"<<b[i]<<endl;
			if(yv<10)
				break;
			yv=yv/10;
			
		}
		int final=0;
		for(i=0,j=1;i<=n;i++,j*=10)
		{
			if(a[i]<b[i])
				c[i]=a[i]+10-b[i];
			else
				c[i]=a[i]-b[i];
			final+=c[i]*j;
		}
		return final;
	}
	~GroupB(){
	}
};

class GroupC:public Group
{

public:
	GroupC()
	{
		
	}
	virtual int add(int x, int y)
	{
		int i,j;
		int xv=x,yv=y;
		int a[20],b[20],c[20],n;
		memset(a,0,sizeof(int)*20);
		memset(b,0,sizeof(int)*20);
		memset(c,0,sizeof(int)*20);
		for(i=0;;i++)
		{
			a[i]=xv%10;
			//cout<<"xv"<<a[i]<<endl;
			if(xv<10)
				break;
			xv=xv/10;
			
		}
		n=i;
		for(i=0;;i++)
		{
			b[i]=yv%10;
			//cout<<"yv"<<b[i]<<endl;
			if(yv<10)
				break;
			yv=yv/10;
			
		}
		int final=0;
		for(i=0,j=1;i<=n;i++,j*=10)
		{
			if(a[i]+b[i]>=10)
				c[i]=a[i]+b[i]-10;
			else
				c[i]=a[i]+b[i];
			final+=c[i]*j;
		}
		return final;
	}
	virtual int sub(int x, int y)
	{
		int i,j;
		int xv=x,yv=y;
		int a[20],b[20],c[20],n;
		memset(a,0,sizeof(int)*20);
		memset(b,0,sizeof(int)*20);
		memset(c,0,sizeof(int)*20);
		for(i=0;;i++)
		{
			a[i]=xv%10;
			//cout<<"xv"<<a[i]<<endl;
			if(xv<10)
				break;
			xv=xv/10;
			
		}
		n=i;
		for(i=0;;i++)
		{
			b[i]=yv%10;
			//cout<<"yv"<<b[i]<<endl;
			if(yv<10)
				break;
			yv=yv/10;
			
		}
		int final=0;
		for(i=0,j=1;i<=n;i++,j*=10)
		{
			if(a[i]<b[i])
				c[i]=a[i]+10-b[i];
			else
				c[i]=a[i]-b[i];
			final+=c[i]*j;
		}
		return final;
	}
	~GroupC()
	{
	}
};


int main()
{
	int t;
	cin>>t;
	int type;
	int a,b;
	char ch;
	
	while(t--)
	{
		Group *p;
		cin>>type>>a>>ch>>b;
		if(type==1)
		{
			GroupA a1;
			p=&a1;
			if(ch=='+')
				cout<<p->add(a,b)<<endl;
			else if(ch=='-')
				cout<<p->sub(a,b)<<endl;
		}
		else if(type==2)
		{
			GroupB a2;
			p=&a2;
			if(ch=='+')
				cout<<p->add(a,b)<<endl;
			else if(ch=='-')
				cout<<p->sub(a,b)<<endl;
		}
		else if(type==3)
		{
			GroupC a3;
			p=&a3;
			if(ch=='+')
				cout<<p->add(a,b)<<endl;
			else if(ch=='-')
				cout<<p->sub(a,b)<<endl;
		}
		
	}
	return 0;
}
