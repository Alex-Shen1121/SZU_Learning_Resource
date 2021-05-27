2018192014:Problem1129:ÕýÈ·
#include<bits/stdc++.h>
using namespace std;
class CommonCard{
protected:
	long ID;
	string CName;
	unsigned int Counter;
public:
	virtual void initial(long i,string n,unsigned int c)
	{
		ID=i;
		CName=n;
		Counter=c;
	}
	virtual int save(int c)
	{
		if(c<=0)
		return -1;
		Counter+=c;
		return 1;
	}
	virtual int take(int c)
	{
		if(c<=0||c>Counter)
		return -1;
		Counter-=c;
		return 1;
	}
	virtual void info()
	{
		cout<<ID<<'-'<<CName<<'-'<<Counter<<endl;
	}
};
class Transport:virtual public CommonCard{
protected:
	unsigned int Tcounter;
public:
	virtual void initial(long i,string n,unsigned int c,unsigned int t){
		ID=i;
		CName=n;
		Counter=c;
		Tcounter=t;
	}
	int transfer(int c)
	{
		if(c<=0||c>Counter)
		return -1;
		Counter-=c;
		Tcounter+=c;
	} 
	virtual void info()
	{
		cout<<ID<<'-'<<CName<<'-'<<Counter<<'-'<<Tcounter<<endl;
	}
};
class VIPcard:virtual public CommonCard
{
protected:
	int Credit;
public:
	virtual void initial(long i,string n,unsigned int c,int t){
		ID=i;
		CName=n;
		Counter=c;
		Credit=t;
	}
	int over(int c)
	{
		if(c<=0||c>(Credit+Counter))
		return -1;
		if(c<Counter)
		{
			Counter-=c;
			return 1;
		}
		else
		{
			c-=Counter;
			Counter=0;
			Credit-=c;
		}
	}
	virtual void info()
	{
		cout<<ID<<'-'<<CName<<'-'<<Counter<<'-'<<Credit<<endl;
	}
};
void show(CommonCard &obj)
{
	obj.info();
}
int main ()
{
	long id;
	string name;
	int c,t,credit;
	cin>>id>>name>>c;
	CommonCard a;
	a.initial(id,name,c);
	cin>>id>>name>>c>>t;
	Transport b;
	b.initial(id,name,c,t);
	cin>>id>>name>>c>>credit;
	VIPcard c1;
	c1.initial(id,name,c,credit);
	cin>>c;
	a.save(c);
	cin>>c;
	a.save(c);
	cin>>c;
	a.take(c);
	cin>>c;
	a.take(c);
	cin>>c;
	b.save(c);
	cin>>c;
	b.take(c);
	cin>>c;
	b.transfer(c);
	cin>>c;
	b.transfer(c);
	cin>>c;
	c1.save(c);
	cin>>c;
	c1.take(c);
	cin>>c;
	c1.over(c);
	cin>>c;
	c1.over(c);
	show(a);
	show(b);
	show(c1);
	return 0;
}
