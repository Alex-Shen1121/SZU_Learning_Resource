2018151051:Problem1234:´ğ°¸´íÎó
#include<iostream>
#include<cstring>
#include<iomanip>
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
		int i,_y=y;
		for(i=0;_y<x;i++)
		{
			_y=_y+10;
		}
		int flag;
		flag=x-y;
		flag=flag+10*i;
		return flag;
	}
};
class GroupC:public Group
{
public:
	virtual int add(int x,int y)
	{
		int i,_y=y;
		for(i=0;_y<x;i++)
		{
			_y=_y+10;
		}
		int flag;
		flag=x+y;
		flag=flag-10*(i-1);
		return flag;
	}
	virtual int sub(int x,int y)
	{
		int i,_y=y;
		for(i=0;_y<x;i++)
		{
			_y=_y+10;
		}
		int flag;
		flag=x-y;
		flag=flag+10*i;
		return flag;
	}
};
int main()
{
    int n,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
    	int x,y,type;
    	char ask;
    	cin>>type;
    	cin>>x>>ask>>y;
    	Group *p;
    	if(type==1)
    	{
    		p=new GroupA;
    		if(ask=='+')
    			cout<<p->add(x,y)<<endl;
    		else if(ask=='-')
    			cout<<p->sub(x,y)<<endl;
		}
		else if(type==2)
		{
			p=new GroupB;
			if(ask=='+')
    			cout<<p->add(x,y)<<endl;
    		else if(ask=='-')
    			cout<<p->sub(x,y)<<endl;
		}
		else if(type==3)
		{
			p=new GroupC;
			if(ask=='+')
    			cout<<p->add(x,y)<<endl;
    		else if(ask=='-')
    			cout<<p->sub(x,y)<<endl;
		}
		delete p;
	}
    return 0;
}
