2018152008:Problem1129:ÕýÈ·
#include<iostream>
#include<string>
using namespace std;
class card
{
	protected:
		string num;
		string id;
		float balance;
	public:
		card(string n,string i,float bal);
		int save(float money);
		int take(float money);
		void virtual info();
};
card::card(string n,string i,float bal)
{
	num=n;
	id=i;
	balance=bal;
}
int card::save(float money)
{
	if(money!=(int)money||money<=0)
		return -1;
	else
		balance+=money;
	return 1;
}
int card::take(float money)
{
	if(money!=(int)money||money<=0||money>balance)
		return -1;
	else
		balance-=money;
	return 1;
}
void card::info()
{
	cout<<num<<"-"<<id<<"-"<<balance<<endl;
}
class trcard:public card
{
	protected:
		float Tcounter;
	public:
		trcard(string n,string i,float bal,float tc);
		int zhuan(float money);
		void info();
};
int trcard::zhuan(float money)
{
	if(money!=(int)money||money<=0||money>balance)
		return -1;
	else
	{
		balance-=money;
		Tcounter+=money;
	}
	return 1;
}
trcard::trcard(string n,string i,float bal,float tc):card(n,i,bal)
{
	Tcounter=tc;
}
void trcard::info()
{
	cout<<num<<"-"<<id<<"-"<<balance<<"-"<<Tcounter<<endl;
}
class vipcard:public card
{
	protected:
		float credit;
	public:
		vipcard(string n,string i,float bal,float cr);
		int over(float money);
		void info();
};
void vipcard::info()
{
	cout<<num<<"-"<<id<<"-"<<balance<<"-"<<credit<<endl;
}
vipcard::vipcard(string n,string i,float bal,float cr):card(n,i,bal)
{
	credit=cr;
}
int vipcard::over(float money)
{
	if(money!=(int)money||money<=0||money>balance+credit)
		return -1;
	else
	{
		money-=balance;
		balance=0;
		credit-=money;
	}
	return 1;
}
int main()
{
	card * pol;
	string n1,n2,n3,i1,i2,i3;
	float bal1,bal2,bal3,tc,cr;
	cin>>n1>>i1>>bal1;
	cin>>n2>>i2>>bal2>>tc;
	cin>>n3>>i3>>bal3>>cr;
	card po1(n1,i1,bal1);
	trcard po2(n2,i2,bal2,tc);
	vipcard po3(n3,i3,bal3,cr);
	float m1,m2,m3,m4;
	cin>>m1>>m2>>m3>>m4;
	po1.save(m1);
	po1.save(m2);
	po1.take(m3);
	po1.take(m4);
	pol=&(po1);
	pol->info();
	cin>>m1>>m2>>m3>>m4;
	po2.save(m1);
	po2.take(m2);
	po2.zhuan(m3);
	po2.zhuan(m4);
	pol=&(po2);
	pol->info();
	cin>>m1>>m2>>m3>>m4;
	po3.save(m1);
	po3.take(m2);
	po3.over(m3);
	po3.over(m4);
	pol=&(po3);
	pol->info();
	return 0; 
}
