2018192014:Problem1234:正确
#include<bits/stdc++.h>
using namespace std;
class Group

{

public:

virtual int add(int x, int y)=0;//输出加法的运算结果

virtual int sub(int x, int y)=0;//输出减法的运算结果

};
class GroupA:virtual public Group

{

public:

virtual int add(int x, int y)//输出加法的运算结果
{
	return x+y;
} 

virtual int sub(int x, int y)//输出减法的运算结果
{
	return x-y;
}
};
class GroupB:virtual public Group

{

public:

virtual int add(int x, int y)//输出加法的运算结果
{
	return x+y;
} 

virtual int sub(int x, int y)//输出减法的运算结果
{
	int n,m,times=1,x1=x,y1=y;
	while(x1)
	{
		n=x1%10;
		m=y1%10;
		x1=x1/10;
		y1=y1/10;
		if(n<m)
		{
			x=x+pow(10,times);
		}
		times++;
	}
	return x-y;
}
};
class GroupC:virtual public Group

{

public:

virtual int add(int x, int y)//输出加法的运算结果
{
	int n,m,times=1,x1=x,y1=y;
	while(x1)
	{
		n=x1%10;
		m=y1%10;
		x1=x1/10;
		y1=y1/10;
		if(n+m>=10)
		{
			x-=pow(10,times);
		}
		times++;
	}
	return x+y;
} 

virtual int sub(int x, int y)//输出减法的运算结果
{
	int n,m,times=1,x1=x,y1=y;
	while(x1)
	{
		n=x1%10;
		m=y1%10;
		x1=x1/10;
		y1=y1/10;
		if(n<m)
		{
			x+=pow(10,times);
		}
		times++;
	}
	return x-y;
}
};
int main ()
{
	Group *group;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int command;
		int a,b;
		char ch;
		cin>>command;
		if(command==1)
		{
			cin>>a>>ch>>b;
			group=new GroupA;
			if(ch=='+')
			cout<<group->add(a,b)<<endl;
			else
			cout<<group->sub(a,b)<<endl;
		}
		else if(command==2)
		{
			cin>>a>>ch>>b;
			group=new GroupB;
			if(ch=='+')
			cout<<group->add(a,b)<<endl;
			else
			cout<<group->sub(a,b)<<endl;
		}
		else if(command==3)
		{
			cin>>a>>ch>>b;
			group=new GroupC;
			if(ch=='+')
			cout<<group->add(a,b)<<endl;
			else
			cout<<group->sub(a,b)<<endl;
		}
	}
	return 0;
}
