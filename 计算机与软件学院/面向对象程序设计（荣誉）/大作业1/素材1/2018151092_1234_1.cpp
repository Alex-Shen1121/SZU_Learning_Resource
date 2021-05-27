2018151092:Problem1234:正确
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

class Group
{
	public:
		Group()
		{
		}
		
		virtual int add(int x, int y)=0;//输出加法的运算结果
		virtual int sub(int x, int y)=0;//输出减法的运算结果
};


class GroupA:public Group
{
	public:
		GroupA()
		{
		}
		
		virtual int add(int x, int y)//输出加法的运算结果
		{
			return x+y;
		}
		
		virtual int sub(int x, int y)//输出减法的运算结果
		{
			return x-y;
		}
};

class GroupB:public Group
{
	public:
		GroupB()
		{
		}
		
		virtual int add(int x, int y)//输出加法的运算结果
		{
			return x+y;
		}
		
		virtual int sub(int x, int y)//输出减法的运算结果
		{
			int xSingle;
			int ySingle;
			int Ans=0;
			int Bit=1;
			
			while(1)
			{
				xSingle=x%10;
				ySingle=y%10;
				x=x/10;
				y=y/10;

				Ans+=(xSingle-ySingle+10)%10*Bit;
				Bit*=10;
				
				if(x==0&&y==0)
				{
					break;
				}
			}
			
			return Ans;
		}
};

class GroupC:public Group
{
	public:
		GroupC()
		{
		}
		
		virtual int add(int x, int y)//输出加法的运算结果
		{
			int xSingle;
			int ySingle;
			int Ans=0;
			int Bit=1;
			
			while(1)
			{
				xSingle=x%10;
				ySingle=y%10;
				x=x/10;
				y=y/10;

				Ans+=(xSingle+ySingle)%10*Bit;
				Bit*=10;
				if(x==0&&y==0)
				{
					break;
				}	
			}
			
			return Ans;			
		}
		
		virtual int sub(int x, int y)//输出减法的运算结果
		{
			int xSingle;
			int ySingle;
			int Ans=0;
			int Bit=1;
			
			while(1)
			{
				xSingle=x%10;
				ySingle=y%10;
				x=x/10;
				y=y/10;
				Ans+=(xSingle-ySingle+10)%10*Bit;
				Bit*=10;
				
				if(x==0&&y==0)
				{
					break;
				}				
			}
			
			return Ans;
		}
};

int main()
{
	int t;
	
	cin>>t;
	
	int type;
	char Op;
	int x;
	int y;
	
	Group *Ace[t];
		
	for(int i=0;i<t;i++)
	{
		cin>>type>>x>>Op>>y;
		
		if(type==1)
		{
			Ace[i]=new GroupA;
			
			if(Op=='+')
			{
				cout<<Ace[i]->add(x,y)<<endl;
			}
			
			else if(Op=='-')
			{
				cout<<Ace[i]->sub(x,y)<<endl;
			}
		}
		
		if(type==2)
		{
			Ace[i]=new GroupB;
			
			if(Op=='+')
			{
				cout<<Ace[i]->add(x,y)<<endl;
			}
			
			else if(Op=='-')
			{
				cout<<Ace[i]->sub(x,y)<<endl;
			}
		}
		
		if(type==3)
		{
			Ace[i]=new GroupC;
			
			if(Op=='+')
			{
				cout<<Ace[i]->add(x,y)<<endl;
			}
			
			else if(Op=='-')
			{
				cout<<Ace[i]->sub(x,y)<<endl;
			}
		}
	}
	return 0; 
}
