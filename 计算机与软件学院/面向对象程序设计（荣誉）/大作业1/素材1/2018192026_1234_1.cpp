2018192026:Problem1234:´ğ°¸´íÎó
#include<stdio.h>
#include<math.h>
class Group
{
public:
	virtual int add(int x,int y)=0;
	virtual int sub(int x,int y)=0;
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
		int i,sum=0;
		for(i=0;x;i++,x/=10,y/=10)
		{
			if(x%10<y%10)
				sum+=(x%10+10-y%10)*pow(10,i);
			else
				sum+=(x%10-y%10)*pow(10,i);
		}
		return sum;
	}
};
class GroupC:public Group
{
public:
	int add(int x,int y)
	{
		int i,sum=0;
		for(i=0;x;i++,x/=10,y/=10)
		{
			if(x%10+y%10>10)
				sum+=(x%10-10+y%10)*pow(10,i);
			else
				sum+=(x%10+y%10)*pow(10,i);
		}
		return sum;
	}
	int sub(int x,int y)
	{
		int i,sum=0;
		for(i=0;x;i++,x/=10,y/=10)
		{
			if(x%10<y%10)
				sum+=(x%10+10-y%10)*pow(10,i);
			else
				sum+=(x%10-y%10)*pow(10,i);
		}
		return sum;
	}
};
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		Group *person;
		int kind,x,y;
		char ch;
		scanf("%d %d%c%d",&kind,&x,&ch,&y);
		if(kind==1)
		{
			GroupA A;
			person=&A;
		}
		else if(kind==2)
		{
			GroupB B;
			person=&B;
		}
		else if(kind==3)
		{
			GroupC C;
			person=&C;
		}
		if(ch=='+')
			printf("%d\n",person->add(x,y));
		else
			printf("%d\n",person->sub(x,y));
	}
	return 0;
}


