2018152051:Problem1234:答案错误
#include<iostream>
#include<cmath>
using namespace std;
class Group
{
protected:
	int x,y;
public:
	Group(int x1 = 0,int y1 = 0)
	{
		x = x1;
		y = y1;
	}
	virtual int add(int x, int y) = 0;//输出加法的运算结果
	virtual int sub(int x, int y) = 0;//输出减法的运算结果
};
class GroupA:public Group
{
public:
	GroupA(int x1 = 0,int y1 = 0)
	{
		x = x1;
		y = y1;
	}
	int add(int x, int y)
	{
		return (x+y);
	}
	int sub(int x, int y)
	{
		return (x-y);
	}
};
class GroupB:public Group
{
public:
	GroupB(int x1 = 0,int y1 = 0)
	{
		x = x1;
		y = y1;
	}
	int add(int x, int y)
	{
		return (x+y);
	}
	int sub(int x, int y)
	{
		return (x-y+10);
	}
};
class GroupC:public Group
{
public:
	GroupC(int x1 = 0,int y1 = 0)
	{
		x = x1;
		y = y1;
	}
	int add(int x, int y)
	{
		int a,b,A,sum=0,i;
		for(i=0;;i++)
		{
			if(x==0 && y==0)
			{
				break;
			}
			else
			{
				a = x%10;
				b = y%10;
				x = (x-a)/10;
				y = (y-b)/10;
				A = (a+b)%10;
				sum+=A*pow(10,i);
			}	
		}
		return sum;
	}
	int sub(int x, int y)
	{
		return (x-y+10);
	}
};
int main()
{
	int T;
	cin>>T;
	int number;
	while(T--)
	{
		cin>>number;
		Group *g1;
		if(number==1)
		{
			int a,b;
			char ch;
			cin>>a>>ch>>b;
			GroupA gA(a,b);
			g1 = &gA ;
			if(ch=='+')
			{
				cout<<g1->add(a,b)<<endl;
			}
			else if(ch=='-')
			{
				cout<<g1->sub(a,b)<<endl;
			}
		}
		if(number==2)
		{
			int a,b;
			char ch;
			cin>>a>>ch>>b;
			GroupB gB(a,b);
			g1=&gB;
			if(ch=='+')
			{
				cout<<g1->add(a,b)<<endl;
			}
			else if(ch=='-')
			{
				cout<<g1->sub(a,b)<<endl;
			}
		}
		if(number==3)
		{
			int a,b;
			char ch;
			cin>>a>>ch>>b;
			GroupC gC(a,b);
			g1=&gC;
			if(ch=='+')
			{
				cout<<g1->add(a,b)<<endl;
			}
			else if(ch=='-')
			{
				cout<<g1->sub(a,b)<<endl;
			}
		}
	}
}
