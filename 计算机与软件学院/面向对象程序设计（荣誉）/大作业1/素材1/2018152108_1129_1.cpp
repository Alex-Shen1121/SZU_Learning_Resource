2018152108:Problem1129:ÕıÈ·
#include<iostream>
using namespace std;

class card
{
protected:
	string id,name;
	int counter;
public:
	card(){}
	card(string a,string b,int c):id(a),name(b),counter(c){}
	virtual void initial(string a,string b,int c)
	{
		id = a;
		name = b;
		counter = c;
	}
	int save(int m)
	{
		if(m<0)
			return -1;
		else 
		{
			counter+=m;
			return 1;
		}
	}
	int take(int m)
	{
		if(m<0||m>counter)
			return -1;
		else
		{
			counter-=m;
			return 1;
		}
	}
	virtual void info()
	{
		cout<<id<<"-"<<name<<"-"<<counter<<endl;
	}
};

class Tcard:public card
{
	int Tcounter;
public:
	Tcard(){}
	Tcard(string a,string b,int c,int d):card(a,b,c),Tcounter(d){}
	void initial(string a,string b,int c,int d)
	{
		id = a;
		name = b;
		counter = c;
		Tcounter = d;
	}
	int transfer(int m)
	{
		if(m<0||m>counter)
			return -1;
		else
		{
			counter-=m;
			Tcounter+=m;
			return 1;
		}
	}
	void info()
	{
		cout<<id<<"-"<<name<<"-"<<counter<<"-"<<Tcounter<<endl;
	}
};

class VIPcard:public card
{
	int credit;
public:
	VIPcard(){}
	VIPcard(string a,string b,int c,int d):card(a,b,c),credit(d){}
	void initial(string a,string b,int c,int d)
	{
		id = a;
		name = b;
		counter = c;
		credit = d;
	}
	int over(int m)
	{
		if(m<0||m>counter+credit)
			return -1;
		else
		{
			credit-=(m-counter);
			counter=0;
			return 1;
		}
	}
	void info()
	{
		cout<<id<<"-"<<name<<"-"<<counter<<"-"<<credit<<endl;
	}
};

void show(card &obj)
{
	obj.info();
}

int main()
{
	string idnum,xm;
	int balance,tbalance,limit;
	card c1;
	Tcard c2;
	VIPcard c3;
	
	cin>>idnum>>xm>>balance;
	c1.initial(idnum,xm,balance);
	
	cin>>idnum>>xm>>balance>>tbalance;
	c2.initial(idnum,xm,balance,tbalance);
	
	cin>>idnum>>xm>>balance>>limit;
	c3.initial(idnum,xm,balance,limit);
	
	int n1,n2,n3,n4;
	cin>>n1>>n2>>n3>>n4;
	c1.save(n1);
	c1.save(n2);
	c1.take(n3);
	c1.take(n4);
	show(c1);
	
	cin>>n1>>n2>>n3>>n4;
	c2.save(n1);
	c2.take(n2);
	c2.transfer(n3);
	c2.transfer(n4);
	show(c2);
	
	cin>>n1>>n2>>n3>>n4;
	c3.save(n1);
	c3.take(n2);
	c3.over(n3);
	c3.over(n4);
	show(c3);
	return 0;
}

