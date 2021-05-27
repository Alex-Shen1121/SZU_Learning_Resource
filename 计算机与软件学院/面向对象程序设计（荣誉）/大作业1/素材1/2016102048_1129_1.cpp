2016102048:Problem1129:ÕýÈ·
#include <bits/stdc++.h>
using namespace std;

class CardA

{ 
protected:
	string ID;
	string CName;
	int Counter;

public:
	CardA(){
	}

	virtual void initial(string id,string name,int counter)
	{
		ID=id;
		CName=name;
		Counter=counter;
	}
	virtual int save(int m)
	{
		if(m<=0)
			return -1;
		Counter+=m;
		return 1;
	}
	virtual int take(int m)
	{
		if(m<=0||m>Counter)
			return -1;
		Counter-=m;
		return 1;
	}
	virtual void info()
	{
		cout<<ID<<"-"<<CName<<"-"<<Counter<<endl;
	}
	
	~CardA(){
	}
};

class CardB:public CardA 
{
	int Tcounter;
public:
	CardB()
	{
	}
	int transfer(int m)
	{
		if(m>Counter)
			return -1;
		Counter-=m;
		Tcounter+=m;
		return 1;
	}
	virtual void initial(string id,string name,int counter,int t)
	{
		ID=id;
		CName=name;
		Counter=counter;
		Tcounter=t;
	}

	virtual void info()
	{
		cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Tcounter<<endl;
	}	
	~CardB()
	{
	}
};

class CardC:public CardA
{
	int Credit;
public:
	CardC()
	{
	}
	int over(int m)
	{
		if(Counter+Credit<m)
			return -1;
		Credit-=m-Counter;
		Counter=0;
		return 1;
	}
	virtual void initial(string id,string name,int counter,int c)
	{
		ID=id;
		CName=name;
		Counter=counter;
		Credit=c;
	}

	virtual void info()
	{
		cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Credit<<endl;
	}	
	~CardC(){
	}
};

void show(CardA &obj)
{
	obj.info();
}
int main()
{
	string ID;
	string CName;
	int Counter;
	int Tcounter;
	int Credit;
	int m1,m2,m3,m4;
	CardA a;
	CardB b;
	CardC c;
	cin>>ID>>CName>>Counter;
	a.initial(ID,CName,Counter);
	cin>>ID>>CName>>Counter>>Tcounter;
	b.initial(ID,CName,Counter,Tcounter);
	cin>>ID>>CName>>Counter>>Credit;
	c.initial(ID,CName,Counter,Credit);
	cin>>m1>>m2>>m3>>m4;
	a.save(m1);
	a.save(m2);
	a.take(m3);
	a.take(m4);
	cin>>m1>>m2>>m3>>m4;
	b.save(m1);
	b.take(m2);
	b.transfer(m3);
	b.transfer(m4);
	cin>>m1>>m2>>m3>>m4;
	c.save(m1);
	c.take(m2);
	c.over(m3);
	c.over(m4);
	show(a);
	show(b);
	show(c);
	
	return 0;
}
