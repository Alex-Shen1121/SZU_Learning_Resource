2018152037:Problem1234:ÕýÈ·
#include<iostream>
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
		int xx1[100]={0},yy1[100]={0};
		int xx=x,yy=y,weix=1,weiy=1,wei;
		while(xx/10!=0)
		{
			xx1[weix]=xx%10;
			weix++;
			xx=xx/10;
		}
		xx1[weix]=xx;
		while(yy/10!=0)
		{
			yy1[weiy]=yy%10;
			weiy++;
			yy=yy/10;
		}
		yy1[weiy]=yy;
		if(weix>weiy)
			wei=weix;
		else
			wei=weiy;
		int sum=0;
		for(int i=0;i<wei;i++)
		{
			if(xx1[wei-i]>=yy1[wei-i])
				sum=sum*10+xx1[wei-i]-yy1[wei-i];
			else
				sum=sum*10+xx1[wei-i]+10-yy1[wei-i];
		}
		return sum;
	}
};

class GroupC:public Group
{
public:
	int add(int x,int y)
	{
		int xx1[100]={0},yy1[100]={0};
		int xx=x,yy=y,weix=1,weiy=1,wei;
		while(xx/10!=0)
		{
			xx1[weix]=xx%10;
			weix++;
			xx=xx/10;
		}
		xx1[weix]=xx;
		while(yy/10!=0)
		{
			yy1[weiy]=yy%10;
			weiy++;
			yy=yy/10;
		}
		yy1[weiy]=yy;
		if(weix>weiy)
			wei=weix;
		else
			wei=weiy;
		int sum=0;
		for(int i=0;i<wei;i++)
		{
			if(xx1[wei-i]+yy1[wei-i]<10)
				sum=sum*10+xx1[wei-i]+yy1[wei-i];
			else
				sum=sum*10+xx1[wei-i]+yy1[wei-i]-10;
		}
		return sum;
	}
	int sub(int x,int y)
	{
		int xx1[100]={0},yy1[100]={0};
		int xx=x,yy=y,weix=1,weiy=1,wei;
		while(xx/10!=0)
		{
			xx1[weix]=xx%10;
			weix++;
			xx=xx/10;
		}
		xx1[weix]=xx;
		while(yy/10!=0)
		{
			yy1[weiy]=yy%10;
			weiy++;
			yy=yy/10;
		}
		yy1[weiy]=yy;
		if(weix>weiy)
			wei=weix;
		else
			wei=weiy;
		int sum=0;
		for(int i=0;i<wei;i++)
		{
			if(xx1[wei-i]>=yy1[wei-i])
				sum=sum*10+xx1[wei-i]-yy1[wei-i];
			else
				sum=sum*10+xx1[wei-i]+10-yy1[wei-i];
		}
		return sum;
	}
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		Group *aa;
		int zl,n1,n2;
		char ch;
		cin>>zl>>n1>>ch>>n2;
		if(zl==1)
		{
			aa=new GroupA;
			if(ch=='+')
				cout<<aa->add(n1,n2)<<endl;
			if(ch=='-')
				cout<<aa->sub(n1,n2)<<endl;
		}
		if(zl==2)
		{
			aa=new GroupB;
			if(ch=='+')
				cout<<aa->add(n1,n2)<<endl;
			if(ch=='-')
				cout<<aa->sub(n1,n2)<<endl;
		}
		if(zl==3)
		{
			aa=new GroupC;
			if(ch=='+')
				cout<<aa->add(n1,n2)<<endl;
			if(ch=='-')
				cout<<aa->sub(n1,n2)<<endl;
		}
		delete aa;
	}
	return 0;
}
