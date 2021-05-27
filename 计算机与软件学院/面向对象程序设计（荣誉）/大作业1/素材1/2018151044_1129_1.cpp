2018151044:Problem1129:ÕýÈ·
#include<iostream>
#include<string>
using namespace std;
class C
{
protected:
	int id;
	char name;
	int ba;
public:
	C(int a,char b,int c):id(a),name(b),ba(c) {}
	int save(int v)
	{
		if(v<0)return -1;
		ba+=v;
		return 1;
	}
	int take(int v)
	{
		if(v<0)return -1;
		if(ba>=v){
			ba-=v;
			return 1;
		}
		return -1;
	}
	virtual void info()
	{
		cout<<id<<'-'<<name<<'-'<<ba<<endl;
	}
};
class C1:public C
{
	int tba;
public:
	C1(int a,char b,int c,int d):C(a,b,c),tba(d) {}
	int transfer(int v)
	{
		if(v<0)return -1;
		if(ba>=v)
		{
			ba-=v;
			tba+=v;
			return 1;
		}
		return -1;
	}
	virtual void info()
	{
		cout<<id<<'-'<<name<<'-'<<ba<<'-'<<tba<<endl;
	}	
};
class C2:public C
{
	int credit;
public:
	C2(int a,char b,int c,int d):C(a,b,c),credit(d) {}
	int over(int v)
	{
		if(v<0)return -1;
		if(credit+ba>=v)
		{
			if(ba>=v)
			{
				ba-=v;
			}
			else
			{
				v-=ba;
				credit-=v;
				ba=0;
			}
			return 1;
		}
		return -1;
	}
	virtual void info()
	{
		cout<<id<<'-'<<name<<'-'<<ba<<'-'<<credit<<endl;
	}	
};
void show(C& x)
{
	x.info();
} 
int main()
{
	int a,c,d;
	char b;
	cin>>a>>b>>c;
	C x(a,b,c);
	cin>>a>>b>>c>>d;
	C1 y(a,b,c,d);
	cin>>a>>b>>c>>d;
	C2 z(a,b,c,d);
	cin>>a>>c;
	x.save(a);
	x.save(c);
	cin>>a>>c;
	x.take(a);
	x.take(c);
	cin>>a>>c;
	y.save(a);
	y.take(c);
	cin>>a>>c;
	y.transfer(a);
	y.transfer(c);
	cin>>a>>c;
	z.save(a);
	z.take(c);
	cin>>a>>c;
	z.over(a);
	z.over(c);
	show(x),show(y),show(z);
} 
