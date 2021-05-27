2017144045:Problem1129:ÕýÈ·
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;
class origin
{
protected:
	int ID;
	char CName;
	int Counter;
	
public:
	origin()
	{
		
	 } 
	virtual void initial(int id,char n,int c)
	{
		ID=id;
		CName=n;
		Counter=c;
	}
    int save(double money)
    {
		if(abs(round(money)-money)<0.00000000001&&money>=0)
		{
			Counter=Counter+money;
			return 1;
		}
		else
		    return -1;
	}
	int take(double money)
	{
		if(abs(round(money)-money)<0.00000000001&&money<=Counter&&money>=0)
		{
			Counter=Counter-money;
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

class Traffic:public origin
{
	int Tcounter;
public:
	Traffic()
	{
	}
	virtual void initial(int id,char n,int c,int t)
	{
		ID=id;
		CName=n;
		Counter=c;
		Tcounter=t;
	}
	int transfer(double money)
	{
		if(abs(round(money)-money)<0.00000000001&&money<=Counter&&money>=0)
		{
			Counter=Counter-money;
			Tcounter=Tcounter+money;
			return 1;
		}
		else
		    return -1;
	}
	virtual void info()
	{
		cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Tcounter<<endl;
	}
};

class Vip:public origin
{
	int Credit;
public:
	Vip()
	{
	}
	virtual void initial(int id,char n,int c,int cr)
	{
		ID=id;
		CName=n;
		Counter=c;
		Credit=cr;
	}
	int over(double money)
	{
		if(abs(round(money)-money)>0.00000000001||money>(Counter+Credit)||money<0)
		{
			return -1;
		}
		else
		{
			Credit=Counter+Credit-money;
			Counter=0;
			return 1;
		}
	}
	virtual void info()
	{
		cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Credit<<endl;
	}
};

void show(origin & obj)
{
	obj.info();
}
int main()
{
	int id;
	char n;
	int c;
	int t;
	int cr;
	double m,x,y,z;
	origin o;
	Traffic tr;
	Vip v;
	
	cin>>id>>n>>c;
	o.initial(id,n,c);
	cin>>id>>n>>c>>t;
	tr.initial(id,n,c,t);
	cin>>id>>n>>c>>cr;
	v.initial(id,n,c,cr);
	
	cin>>m>>x>>y>>z;
	o.save(m);
	o.save(x);
	o.take(y);
	o.take(z);
	
	cin>>m>>x>>y>>z;
	tr.save(m);
	tr.take(x);
	tr.transfer(y);
	tr.transfer(z);
	
	cin>>m>>x>>y>>z;
	v.save(m);
	v.take(x);
	v.over(y);
	v.over(z);
	
	show(o);
	show(tr);
	show(v);
	
}
