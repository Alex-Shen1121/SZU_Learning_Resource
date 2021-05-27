2018152087:Problem1234:正确
#include<iostream>
#include<math.h> 
using namespace std;
class Group
{
public:
	virtual int add(int x, int y)=0;//输出加法的运算结果
	virtual int sub(int x, int y)=0;//输出减法的运算结果
};
class GroupA:public Group
{
public:
	virtual int add(int x, int y)
	{
		return x+y;
	}
	virtual int sub(int x, int y)
	{
		return x-y;
	}
};
class GroupB:public Group
{
public:
	virtual int add(int x, int y)
	{
		return x+y;
	}
	virtual int sub(int x, int y)
	{
		int numx[100]={0};
		int numy[100]={0};
		int ans[100]={0};
		int sumx=0;
		int sumy=0;
		while(x)
		{
			numx[sumx]=x%10;
			x=x/10;
			sumx++;
		}
		while(y)
		{
			numy[sumy]=y%10;
			sumy++;
			y=y/10;
		}
		int maxsum=max(sumx,sumy);
		for(int i=0;i<maxsum;i++)
		{
			ans[i]=numx[i]-numy[i];
			if(ans[i]<0)
				ans[i]=10+numx[i]-numy[i];
		}
		int temp=0;
		for(int i=0;i<maxsum;i++)
			temp+=ans[i]*pow(10,i);
		return temp;
	}
};
class GroupC:public Group
{
public:
	virtual int add(int x, int y)
	{
		int numx[100]={0};
		int numy[100]={0};
		int ans[100]={0};
		int sumx=0;
		int sumy=0;
		while(x)
		{
			numx[sumx]=x%10;
			x=x/10;
			sumx++;
		}
		while(y)
		{
			numy[sumy]=y%10;
			sumy++;
			y=y/10;
		}
		int maxsum=max(sumx,sumy);
		for(int i=0;i<maxsum;i++)
		{
			ans[i]=numx[i]+numy[i];
			if(ans[i]>9)
				ans[i]=numx[i]+numy[i]-10;
		}
		int temp=0;
		for(int i=0;i<maxsum;i++)
			temp+=ans[i]*pow(10,i);
		return temp;
	}
	virtual int sub(int x, int y)
	{
		int numx[100]={0};
		int numy[100]={0};
		int ans[100]={0};
		int sumx=0;
		int sumy=0;
		while(x)
		{
			numx[sumx]=x%10;
			x=x/10;
			sumx++;
		}
		while(y)
		{
			numy[sumy]=y%10;
			sumy++;
			y=y/10;
		}
		int maxsum=max(sumx,sumy);
		for(int i=0;i<maxsum;i++)
		{
			ans[i]=numx[i]-numy[i];
			if(ans[i]<0)
				ans[i]=10+numx[i]-numy[i];
		}
		int temp=0;
		for(int i=0;i<maxsum;i++)
			temp+=ans[i]*pow(10,i);
		return temp;
	}
};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		Group *p;
		int flag;
		cin>>flag;
		int num1,num2;
		char s;
		int ans;
		if(flag==1)
		{
			GroupA ex;
			cin>>num1>>s>>num2;
			p=&ex;
			if(s=='+')
			{
				ans=p->add(num1,num2);
			}
			else 
			{
				ans=p->sub(num1,num2);
			}
		}
		else if(flag==2)
		{
			GroupB ex;
			cin>>num1>>s>>num2;
			p=&ex;
			if(s=='+')
			{
				ans=p->add(num1,num2);
			}
			else 
			{
				ans=p->sub(num1,num2);
			}
		}
		else if(flag==3)
		{
			GroupC ex;
			cin>>num1>>s>>num2;
			p=&ex;
			if(s=='+')
			{
				ans=p->add(num1,num2);
			}
			else 
			{
				ans=p->sub(num1,num2);
			}
		}
		cout<<ans<<endl;
	}
}
