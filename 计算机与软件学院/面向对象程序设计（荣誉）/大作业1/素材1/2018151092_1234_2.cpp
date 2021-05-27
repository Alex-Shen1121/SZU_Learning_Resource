2018151092:Problem1234:ÕýÈ·
#include<iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<cmath>
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
		GroupA()
		{
		}
		
		virtual int add(int x,int y)
		{
			return x+y;
		}
		
		virtual int sub(int x,int y)
		{
			return x-y;
		}
		
		~GroupA()
		{
		}
};

class GroupB:public Group
{
	public:
		GroupB()
		{
		}
		
		virtual int add(int x,int y)
		{
			return x+y;
		}
		
		virtual int sub(int x,int y)
		{
			int xSingle;
			int ySingle;
			int sum=0;
			int count=0;
			
			while(x!=0||y!=0)
			{
				xSingle=x%10;
				ySingle=y%10;
				sum+=((xSingle-ySingle+10)%10)*pow(10,count);
				count++;
				x/=10;
				y/=10;
			}
			return sum;			
		}
		
		~GroupB()
		{
		}
};

class GroupC:public Group
{
	public:
		GroupC()
		{
		}
		
		virtual int add(int x,int y)
		{
			int xSingle;
			int ySingle;
			int sum=0;
			int count=0;
			
			while(x!=0||y!=0)
			{
				xSingle=x%10;
				ySingle=y%10;
				sum+=((xSingle+ySingle)%10)*pow(10,count);
				count++;
				x/=10;
				y/=10;
			}
			return sum;
		}
		
		virtual int sub(int x,int y)
		{
			int xSingle;
			int ySingle;
			int sum=0;
			int count=0;
			
			while(x!=0||y!=0)
			{
				xSingle=x%10;
				ySingle=y%10;
				sum+=((xSingle-ySingle+10)%10)*pow(10,count);
				count++;
				x/=10;
				y/=10;
			}
			return sum;
		}
		
		~GroupC()
		{
		}
};

int main()
{
	int Ans;
	int t;
	int i;
	int Gtype;
	int x;
	char symbol;
	int y;
	
	cin>>t;
	
	Group *Ace[t];
	
	for(i=0;i<t;i++)
	{
		cin>>Gtype>>x>>symbol>>y;
		
		if(Gtype==1)
		{
			Ace[i]=new GroupA;
			
			if(symbol=='+')
			{
				Ans=Ace[i]->add(x,y);
			}
			
			if(symbol=='-')
			{
				Ans=Ace[i]->sub(x,y);
			}
			
			cout<<Ans<<endl;
		}

		if(Gtype==2)
		{
			Ace[i]=new GroupB;
			
			if(symbol=='+')
			{
				Ans=Ace[i]->add(x,y);
			}
			
			if(symbol=='-')
			{
				Ans=Ace[i]->sub(x,y);
			}
			
			cout<<Ans<<endl;
		}
		
		if(Gtype==3)
		{
			Ace[i]=new GroupC;
			
			if(symbol=='+')
			{
				Ans=Ace[i]->add(x,y);
			}
			
			if(symbol=='-')
			{
				Ans=Ace[i]->sub(x,y);
			}
			
			cout<<Ans<<endl;
		}
	}
	return 0;	
}
