2018152106:Problem1129:ÕýÈ·
#include<iostream>
using namespace std;

class NCard
{
protected:
	string ID;
	char CName;
	int Counter;
public:
	NCard(){}
	NCard(string id,char name,int ba):ID(id),CName(name),Counter(ba){}
	virtual void initial(string id,char name,int ba)
	{
		ID=id;
		CName=name;
		Counter=ba;
	}
	int save(int num)
	{
		if(num>0)
		{
			Counter+=num;
			return 1;
		}
		else
			return -1;
	}
	int take(int num)
	{
		if(num>0&&num<=Counter)
		{
			Counter-=num;
			return 1;
		}
		else 
			return -1;
	}
	virtual void info()
	{
		cout<<ID<<"-"<<CName<<"-"<<Counter<<endl;
	}
};

class TCard:public NCard
{
	int Tcounter;
public:
	TCard(){}
	TCard(string id,char name,int ba,int t):NCard(id,name,ba),Tcounter(t){}
	void initial(string id,char name,int ba,int t)
	{
		ID=id;
		CName=name;
		Counter=ba;
		Tcounter=t;
	}
	int transfer(int num)
	{
		if(num>0&&num<=Counter)
		{
			Counter-=num;
			Tcounter+=num;
			return 1;
		}
		else 
			return -1;
	}
	void info()
	{
		cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Tcounter<<endl;
	}
};

class VIPCard:public NCard
{
	int Credit;
public:
	VIPCard(){}
	VIPCard(string id,char name,int ba,int t):NCard(id,name,ba),Credit(t){}
	void initial(string id,char name,int ba,int t)
	{
		ID=id;
		CName=name;
		Counter=ba;
		Credit=t;
	}
	int over(int num)
	{
		if(num>0&&num<=Counter+Credit)
		{
			Credit-=(num-Counter);
			Counter=0;
			return 1;
		}
		else 
			return -1;
	}
	void info()
	{
		cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Credit<<endl;
	}
};

void show(NCard &obj)
{
	obj.info();
}

int main()
{
	string id;
	char n;
	int bal,t,x1,x2,y1,y2;
	NCard a;
	TCard b;
	VIPCard c;
	
	cin>>id>>n>>bal;
	a.initial(id,n,bal);
	
	cin>>id>>n>>bal>>t;
	b.initial(id,n,bal,t);
	
	cin>>id>>n>>bal>>t;
	c.initial(id,n,bal,t);
	
	cin>>x1>>x2>>y1>>y2;
	a.save(x1);
	a.save(x2);
	a.take(y1);
	a.take(y2);
	
	cin>>x1>>x2>>y1>>y2;
	b.save(x1);
	b.take(x2);
	b.transfer(y1);
	b.transfer(y2);
	
	cin>>x1>>x2>>y1>>y2;
	c.save(x1);
	c.take(x2);
	c.over(y1);
	c.over(y2);
	
	show(a);
	show(b);
	show(c);
	return 0;
}
