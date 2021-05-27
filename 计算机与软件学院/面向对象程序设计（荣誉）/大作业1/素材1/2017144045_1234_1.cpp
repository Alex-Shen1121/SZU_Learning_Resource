2017144045:Problem1234:答案错误
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;
class Group
{
protected:
	int x,y;
public:
	Group(int ix,int iy)
	{
		x=ix;
		y=iy;
	} 
    virtual int add(int ix, int iy)=0;//输出加法的运算结果
    virtual int sub(int ix, int iy)=0;//输出减法的运算结果
};

class GroupA:public Group
{
public:
	GroupA(int ix,int iy):Group(ix,iy)
	{
	}
    virtual int add(int ix, int iy)
    {
    	return x+y;
	}
    virtual int sub(int ix, int iy)
    {
    	return x-y;
	}
};

class GroupB:public Group
{
public:
	GroupB(int ix,int iy):Group(ix,iy)
	{
	}
    virtual int add(int ix, int iy)
    {
    	return x+y;
	}
    virtual int sub(int ix, int iy)
    {
    	int n=0;
    	int i=0;
    	int s;
    	while((x!=0)||(y!=0))
    	{
    		s=x%10-y%10;
    		if(s<0)
    		{
    			s=10+s;
			}
			if(i==0)
    		    n=n+s;
    		else
    		    n=n+s*pow(10,i);
    		x=x/10;
    		y=y/10;
    		i++;
    		//cout<<x<<" "<<y<<endl;
		}
    	return n;
	}
};

class GroupC:public Group
{
public:
	GroupC(int ix,int iy):Group(ix,iy)
	{
	}
    virtual int add(int ix, int iy)
    {
    	int n=0;
    	int i=0;
    	int s;
    	while((x!=0)||(y!=0))
    	{
    		s=x%10+y%10;
    		if(s>10)
    		{
    			s=s%10;
			}
			if(i==0)
    		    n=n+s;
    		else
    		{
    			n=n+s*pow(10,i);
			}
    		x=x/10;
    		y=y/10;
    		i++;
    		//cout<<s<<" "<<n<<endl;
		}
    	return n;
	}
    virtual int sub(int ix, int iy)
    {
    	int n=0;
    	int i;
    	int s;
    	while((x/10==0)&&(y/10==0))
    	{
    		s=x%10-y%10;
    		if(s<0)
    		{
    			s=10+s;
			}
			if(i==0)
    		    n=n+s;
    		else
    		    n=n+s*10*i;
    		x=x/10;
    		y=y/10;
    		i++;
		}
    	return n;
	}
};

int main()
{
	int t;
	int a,x,y;
	char ch;
	cin>>t;
	Group *p; 
	while(t--)
	{
		cin>>a>>x>>ch>>y;
		if(a==1)
		{
			p=new GroupA(x,y);
		}
		else if(a==2)
		{
			p=new GroupB(x,y);
		}
		else if(a==3)
		{
			p=new GroupC(x,y);
		}
		if(ch=='+')
		{
			cout<<p->add(x,y)<<endl;
		}
		else if(ch=='-')
		{
			cout<<p->sub(x,y)<<endl;
		}
	 } 
}
