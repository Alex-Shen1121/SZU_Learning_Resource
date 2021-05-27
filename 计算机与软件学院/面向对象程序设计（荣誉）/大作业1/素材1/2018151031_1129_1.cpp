2018151031:Problem1129:ÕýÈ·
#include <bits/stdc++.h>
using namespace std;
class travel;
class vip;
class card
{
	long id;
	string CName;
	float Counter;
public:
	friend travel;
	friend vip;
	virtual void initial(long id_in,string n,float c)
	{
		id=id_in;
		CName=n;
		Counter=c;		
	}	
	int save(float m)
	{
		if(m<0)
			return -1;
		if(m!=(int)m)
			return -1;
		if(m<0)
			return -1;
		else
			Counter+=m;
		return 1;
	}
	int take(float m)
	{
		if(m<0)
			return -1;
		if(m!=(int)m)
			return -1;
		if(m>Counter)
			return -1;
		else
			Counter-=m;
		return 1;
	}
	virtual void info()
	{
		cout<<id<<'-'<<CName<<'-'<<Counter<<endl;
	}
	
};
class travel:public card
{
	int Tcounter;
public:
	void initial(long id_in,string n,float c,int t)
	{
		id=id_in;
		CName=n;
		Counter=c;		
		Tcounter=t;
	}	
	int transfer(float m)
	{
		if(m<0)
			return -1;
		if(m>Counter)
			return -1;
		else
		{
			Counter-=m;
			Tcounter+=m;	
		}	
	}	
	void info()
	{
		cout<<id<<'-'<<CName<<'-'<<Counter<<'-'<<Tcounter<<endl;
	}
};
class vip:public card
{
	int Credit;
public:
	void initial(long id_in,string n,float c,int credit)
	{
		id=id_in;
		CName=n;
		Counter=c;		
		Credit=credit;
	}	
	int over(int m)
	{
		if(m<0)
			return -1;
		if(m>Counter+Credit)
			return -1;
		else
		{
			Credit-=m-Counter;
			Counter=0;
			return 1;
		}
	}
	void info()
	{
		cout<<id<<'-'<<CName<<'-'<<Counter<<'-'<<Credit<<endl;
	}
};
void show(card &obj)
{
	obj.info();
}
int main()
{
	long id;
	string n;
	float balance;
	cin>>id>>n>>balance;
	card c1;
	c1.initial(id,n,balance);
	int tcount_in;
	cin>>id>>n>>balance>>tcount_in;
	travel t;
	t.initial(id,n,balance,tcount_in);
	int o;
	cin>>id>>n>>balance>>o;
	vip v;
	v.initial(id,n,balance,o);
	float A,B,C,D;
	cin>>A>>B>>C>>D;
	c1.save(A);
	c1.save(B);
	c1.take(C);
	c1.take(D);
	cin>>A>>B>>C>>D;
	t.save(A);
	t.take(B);
	t.transfer(C);
	t.transfer(D);
	cin>>A>>B>>C>>D;
	v.save(A);
	v.take(B);
	v.over(C);
	v.over(D);
	card *c;
	c=&c1;
	show(*c);
	c=&t;
	show(*c);
	c=&v;
	show(*c);
}
