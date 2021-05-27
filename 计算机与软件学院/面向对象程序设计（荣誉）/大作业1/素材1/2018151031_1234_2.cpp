2018151031:Problem1234:正确
#include <bits/stdc++.h>
using namespace std;
class Group
{
public:
	virtual int add(int x, int y)=0;//输出加法的运算结果
	virtual int sub(int x, int y)=0;//输出减法的运算结果
};
class GroupA :public Group
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
class GroupB :public Group
{
public:
	int add(int x,int y)
	{
		return x+y;
	}
	int sub(int x,int y)
	{
		int i,maxnum=max(x,y),count=0,sum=0;
		for(i=0;maxnum;i++)
		{
			maxnum/=10;
		}
		count=i;
		for(i=0;i<count;i++)
		{
			int lastnum,a,b;
			a=x%10;
			b=y%10;
			if(a<b)
				a+=10;
			lastnum=(a-b)*(pow(10,i));
			sum+=lastnum;
			x/=10;
			y/=10;
		}
		return sum;
	}
};
class GroupC :public Group
{
public:
	int add(int x,int y)
	{
		int i,maxnum=max(x,y),count=0,sum=0;
		for(i=0;maxnum;i++)
		{
			maxnum/=10;
		}
		count=i;
		for(i=0;i<count;i++)
		{
			int lastnum,a,b;
			a=x%10;
			b=y%10;
			if(a+b>10)
				a-=10;
			lastnum=(a+b)*(pow(10,i));
			sum+=lastnum;
			x/=10;
			y/=10;
		}
		return sum;
	}
	int sub(int x,int y)
	{
		int i,maxnum=max(x,y),count=0,sum=0;
		for(i=0;maxnum;i++)
		{
			maxnum/=10;
		}
		count=i;
		for(i=0;i<count;i++)
		{
			int lastnum,a,b;
			a=x%10;
			b=y%10;
			if(a<b)
				a+=10;
			lastnum=(a-b)*(pow(10,i));
			sum+=lastnum;
			x/=10;
			y/=10;
		}
		return sum;
	}	
};
int main() 
{
	Group *g;
	int t;
	cin>>t;
	while(t--)
	{
		int type,num1,num2;
		char ch;
		cin>>type;
		if(type==1)
		{
			cin>>num1>>ch>>num2;
			GroupA a;
			g=&a;
			if(ch=='+')
				cout<<g->add(num1,num2)<<endl;
			else
				cout<<g->sub(num1,num2)<<endl;
		}
		else if(type==2)
		{
			cin>>num1>>ch>>num2;
			GroupB b;
			g=&b;
			if(ch=='+')
				cout<<g->add(num1,num2)<<endl;
			else
				cout<<g->sub(num1,num2)<<endl;		
				
		}
		else if(type==3)
		{
			cin>>num1>>ch>>num2;
			GroupC c;
			g=&c;
			if(ch=='+')
				cout<<g->add(num1,num2)<<endl;
			else
				cout<<g->sub(num1,num2)<<endl;	
		}
	}
	return 0;
}
