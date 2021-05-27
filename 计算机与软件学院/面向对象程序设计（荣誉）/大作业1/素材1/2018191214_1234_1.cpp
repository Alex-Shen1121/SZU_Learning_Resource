2018191214:Problem1234:正确
#include<iostream>
#include<cstring>
#include<cmath>
#include<iomanip>
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
	int add(int x,int y)
	{
		return x+y;
	}
	int sub(int x,int y)
	{
		return x-y;
	}
};
class GroupB:public Group
{
public:
	int add(int x,int y)
	{
		return x+y;
	}
	int sub(int x,int y)
	{
		int x1,y1,s1,x2,y2,x3,y3,s2,s3;
		x1=x%10;
		y1=y%10;
		if(x1<y1)
			s1=fabs(x1+10-y1);
		else
		s1=x1-y1;
		x2=(x/10)%10;
		y2=(y/10)%10;
	    if(x2<y2)
		s2=fabs(x2+10-y2);
		else
			s2=x2-y2;
		x3=x/100;
		y3=y/100;
		s3=x3-y3;
		return s3*100+s2*10+s1;
	}
};
class GroupC:public Group
{
public:
   int sub(int x,int y)
	{
		int x1,y1,s1,x2,y2,x3,y3,s2,s3;
		x1=x%10;
		y1=y%10;
		if(x1<y1)	
			s1=fabs(x1+10-y1);
		else
		s1=x1-y1;
		x2=(x/10)%10;
		y2=(y/10)%10;
	    if(x2<y2)
		s2=fabs(x2+10-y2);
		else
			s2=x2-y2;
		x3=x/100;
		y3=y/100;
		s3=x3-y3;
		return s3*100+s2*10+s1;
	}
   int add(int x,int y)
   {
	   int s1,s2,s3,x1,x2,x3,y1,y2,y3;
	   x1=x%10;
	   y1=y%10;
	   if(x1+y1>=10)
		   s1=x1+y1-10;
	   else
		   s1=x1+y1;
       x2=(x/10)%10;
	   y2=(y/10)%10;
	   if(x2+y2>=10)
		   s2=(x2+y2-10)*10;
	   else
		   s2=(x2+y2)*10;
       x3=x/100;
	   y3=y/100;
	   if(x3+y3>=10)
		   s3=(x3+y3-10)*100;
	   else
		   s3=(x3+y3)*100;
	   return s1+s2+s3;
   }
};
int main()
{
	int t,kind,num1,num2;
	char f;
	Group *g;
	cin>>t;
	while(t--)
	{
		cin>>kind;
		if(kind==1)
		{
			g=new GroupA;
			cin>>num1>>f>>num2;
			if(f=='+')
				cout<<g->add(num1,num2)<<endl;
			else if(f=='-')
				cout<<g->sub(num1,num2)<<endl;
		}
		else if(kind==2)
		{
			g=new GroupB;
			cin>>num1>>f>>num2;
			if(f=='+')
				cout<<g->add(num1,num2)<<endl;
			else if(f=='-')
				cout<<g->sub(num1,num2)<<endl;
		}
		else if(kind==3)
		{
			g=new GroupC;
			cin>>num1>>f>>num2;
			if(f=='+')
				cout<<g->add(num1,num2)<<endl;
			else if(f=='-')
				cout<<g->sub(num1,num2)<<endl;
		}
	}
	return 0;
}

