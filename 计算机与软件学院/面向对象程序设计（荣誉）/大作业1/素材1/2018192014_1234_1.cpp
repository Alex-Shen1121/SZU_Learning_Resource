2018192014:Problem1234:��ȷ
#include<bits/stdc++.h>
using namespace std;
class Group

{

public:

virtual int add(int x, int y)=0;//����ӷ���������

virtual int sub(int x, int y)=0;//���������������

};
class GroupA:virtual public Group

{

public:

virtual int add(int x, int y)//����ӷ���������
{
	return x+y;
} 

virtual int sub(int x, int y)//���������������
{
	return x-y;
}
};
class GroupB:virtual public Group

{

public:

virtual int add(int x, int y)//����ӷ���������
{
	return x+y;
} 

virtual int sub(int x, int y)//���������������
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

virtual int add(int x, int y)//����ӷ���������
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

virtual int sub(int x, int y)//���������������
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
