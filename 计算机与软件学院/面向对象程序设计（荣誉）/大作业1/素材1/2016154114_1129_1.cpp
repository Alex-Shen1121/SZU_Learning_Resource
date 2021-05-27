2016154114:Problem1129:ÕıÈ·
#include<iostream>
#include<string>
using namespace std;

class Card
{
protected:
	string id;
	string cname;
	int counter;
public:
	virtual void initial(string i,string n,int c)
	{
		id=i;
		cname=n;
		counter=c;
	}
	virtual int save(int m)
	{
		if(m<0)
			return -1;
		else
		{
			counter+=m;
			return 1;
		}
	}
	virtual int take(int m)
	{
		if(m<0 || m>counter)
			return -1;
		else
		{
			counter-=m;
			return 1;
		}
	}
	virtual void info()
	{
		cout<<id<<"-"<<cname<<"-"<<counter<<endl;
	}
};

class TCard:public Card
{
protected:
	int Tcounter;
public:
    virtual void initial(string i,string n,int c,int t)
	{
		id=i;
		cname=n;
		counter=c;
		Tcounter=t;
	}
	virtual int save(int m)
	{
		if(m<0)
			return -1;
		else
		{
			counter+=m;
			return 1;
		}
	}
	virtual int take(int m)
	{
		if(m<0 || m>counter)
			return -1;
		else
		{
			counter-=m;
			return 1;
		}
	}
	virtual void info()
	{
		cout<<id<<"-"<<cname<<"-"<<counter<<"-"<<Tcounter<<endl;
	}
	int transfer(int m)
	{
		if(m>counter)
			return -1;
		else
		{
			counter-=m;
			Tcounter+=m;
			return 1;
		}
	}
};

class VCard:public Card
{
protected:
	int credit;
public:
    virtual void initial(string i,string n,int c,int cr)
	{
		id=i;
		cname=n;
		counter=c;
		credit=cr;
	}
	virtual int save(int m)
	{
		if(m<0)
			return -1;
		else
		{
			counter+=m;
			return 1;
		}
	}
	virtual int take(int m)
	{
		if(m<0 || m>counter)
			return -1;
		else
		{
			counter-=m;
			return 1;
		}
	}
	virtual void info()
	{
		cout<<id<<"-"<<cname<<"-"<<counter<<"-"<<credit<<endl;
	}
	int over(int m)
	{
		if(m>counter && m<counter+credit)
		{
			m-=counter;
			counter=0;
			credit-=m;
			return 1;
		}
		else
			return -1;
	}
};

void show(Card &card)
{
	card.info();
}

int main()
{
	Card card;
	TCard tcard;
	VCard vcard;
	string id,name; 
	int counter,Tcounter,credit;
	cin>>id>>name>>counter;
	card.initial(id,name,counter);
	cin>>id>>name>>counter>>Tcounter;
	tcard.initial(id,name,counter,Tcounter);
	cin>>id>>name>>counter>>credit;
	vcard.initial(id,name,counter,credit);
	int m1,m2,m3,m4;
	cin>>m1>>m2>>m3>>m4;
	card.save(m1);
	card.save(m2);
	card.take(m3);
	card.take(m4);
	cin>>m1>>m2>>m3>>m4;
	tcard.save(m1);
	tcard.take(m2);
	tcard.transfer(m3);
	tcard.transfer(m4);
	cin>>m1>>m2>>m3>>m4;
	vcard.save(m1);
	vcard.take(m2);
	vcard.over(m3);
	vcard.over(m4);
	show(card);
	show(tcard);
	show(vcard);
	return 0;
}
