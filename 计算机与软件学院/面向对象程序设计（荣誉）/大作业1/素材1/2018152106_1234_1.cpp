2018152106:Problem1234:正确
#include<iostream>
#include<cmath>
using namespace std;

class Group
{
public:
	virtual int add(int x, int y)=0;//输出加法的运算结果
	virtual int sub(int x, int y)=0;//输出减法的运算结果
};

class GroupA
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

class GroupB
{
public:
	int add(int x,int y)
	{
		return x+y;
	}
	int sub(int x,int y)
	{
		int rx,ry,result=0,i=0;
		while(x!=0||y!=0)
		{
			rx=x%10;
			ry=y%10;
			if(rx<ry)
			{
				result+=(10+rx-ry)*pow(10,i);
			}
			else
			{
				result+=(rx-ry)*pow(10,i);
			}
			x/=10;
			y/=10;
			i++;
		}
		return result;
	}	
};

class GroupC
{
public:
	int add(int x,int y)
	{
		int rx,ry,result=0,i=0;
		while(x!=0||y!=0)
		{
			rx=x%10;
			ry=y%10;
			if(rx+ry<10)
			{
				result+=(rx+ry)*pow(10,i);
			}
			else
			{
				result+=(rx+ry-10)*pow(10,i);
			}
			x/=10;
			y/=10;
			i++;
		}
		return result;
	}
	int sub(int x,int y)
	{
		int rx,ry,result=0,i=0;
		while(x!=0||y!=0)
		{
			rx=x%10;
			ry=y%10;
			if(rx<ry)
			{
				result+=(10+rx-ry)*pow(10,i);
			}
			else
			{
				result+=(rx-ry)*pow(10,i);
			}
			x/=10;
			y/=10;
			i++;
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
		int type,a,b;
		char ch;
		cin>>type>>a>>ch>>b;
		if(type==1)
		{
			GroupA boy;
			if(ch=='+')
				cout<<boy.add(a,b)<<endl;
			else
				cout<<boy.sub(a,b)<<endl;
		}
		else if(type==2)
		{
			GroupB boy;
			if(ch=='+')
				cout<<boy.add(a,b)<<endl;
			else
				cout<<boy.sub(a,b)<<endl;
		}
		else if(type==3)
		{
			GroupC boy;
			if(ch=='+')
				cout<<boy.add(a,b)<<endl;
			else
				cout<<boy.sub(a,b)<<endl;
		}
	}
	return 0;
}
