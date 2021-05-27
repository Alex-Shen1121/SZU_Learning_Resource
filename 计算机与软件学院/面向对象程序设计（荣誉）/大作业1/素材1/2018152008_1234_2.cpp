2018152008:Problem1234:ÕıÈ·
#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdlib>
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
		int add(int x,int y);
		int sub(int x,int y);
};
int GroupA::add(int x,int y)
{
	return x+y;
}
int GroupA::sub(int x,int y)
{
	return x-y;
}
class GroupB:public GroupA
{
	public:
		int sub(int x,int y);
};
int GroupB::sub(int x,int y)
{
	int z=1;
	int sum=0;
	while(x||y)
	{
		int a=x%10;
		int b=y%10;
		sum+=(a-b)*z;
		if(a<b)
			sum+=z*10;
		x/=10;
		y/=10;
		z*=10;
	}
	return sum;
}
class GroupC:public GroupB
{
	public:
		int add(int x,int y);
};
int GroupC::add(int x,int y)
{
	int z=1;
	int sum=0;
	while(x||y)
	{
		int a=x%10;
		int b=y%10;
		sum+=(a+b)*z;
		if(a+b>9)
			sum-=z*10;
		x/=10;
		y/=10;
		z*=10;
	}
	return sum;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		Group *pll;
		int kind;
		cin>>kind;
		char suanshi[100];
		char num1[100];
		char yunsuanfu;
		char num2[100];
		cin>>suanshi;
		int k=strlen(suanshi);
		int i;
		int flag=0;
		int j=0;
		for(i=0;i<k;i++)
		{
			if(flag==0&&suanshi[i]<='9'&&suanshi[i]>='0')
			{
				num1[j]=suanshi[i];
				j++;
			}
			else if(suanshi[i]>'9'||suanshi[i]<'0')
			{
				flag=1;
				num1[j]='\0';
				yunsuanfu=suanshi[i];
				j=0;
			}
			else if(flag==1&&suanshi[i]<='9'&&suanshi[i]>='0')
			{
				num2[j]=suanshi[i];
				j++;
			}
		}
		num2[j]='\0';
		int nu1=atoi(num1);
		int nu2=atoi(num2);
		if(kind==1)
		{
			pll=new GroupA;
			if(yunsuanfu=='+')
				cout<<pll->add(nu1,nu2)<<endl;
			else
				cout<<pll->sub(nu1,nu2)<<endl;
		}
		else if(kind==2)
		{
			pll=new GroupB;
			if(yunsuanfu=='+')
				cout<<pll->add(nu1,nu2)<<endl;
			else
				cout<<pll->sub(nu1,nu2)<<endl;
		}
		else if(kind==3)
		{
			pll=new GroupC;
			if(yunsuanfu=='+')
				cout<<pll->add(nu1,nu2)<<endl;
			else
				cout<<pll->sub(nu1,nu2)<<endl;
		}
		delete pll;
	}
	return 0;
}

