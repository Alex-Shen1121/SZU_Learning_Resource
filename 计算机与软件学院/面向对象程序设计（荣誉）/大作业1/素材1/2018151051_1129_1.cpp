2018151051:Problem1129:ÕýÈ·
#include<iostream>
#include<cmath>
using namespace std;
class bank
{
protected:
	int ID;
	char CName;
	int Counter;
public:
	bank(){}
	void initial(int I,char CN,int Co)
	{
		ID=I;
		CName=CN;
		Counter=Co;	
	}
	int save(int money)
	{
		if(money<0)
			return -1;
		else
		{
			Counter=Counter+money;
			return 1;
		}
	}
	int take(int money)
	{
		if(money<0)
			return -1;
		else
		{
			if(Counter<money)
				return -1;
			else
			{
				Counter=Counter-money;
				return 1;
			}
		}
	}
	void info()
	{
		cout<<ID<<"-"<<CName<<"-"<<Counter<<endl;
	}
};
class bankjiaotong:public bank
{
	int Tcounter;
public:
	bankjiaotong(){}
	void initial(int I,char CN,int Co,int T)
	{
		ID=I;
		CName=CN;
		Counter=Co;	
		Tcounter=T;
	}
	int transfer(int money)
	{
		if(money<0)
			return -1;
		else
		{
			if(Counter<money)
				return -1;
			else
			{
				Counter=Counter-money;
				Tcounter=Tcounter+money;
				return 1;
			}
		}
	}
	void info()
	{
		cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Tcounter<<endl;
	}
};
class bankVIP:public bank
{
	int Credit;
public:
	bankVIP(){}
	void initial(int I,char CN,int Co,int Cr)
	{
		ID=I;
		CName=CN;
		Counter=Co;
		Credit=Cr;
	}
	int over(int money)
	{
		if(money<0)
			return -1;
		else
		{
			if(Counter+Credit<money)
				return -1;
			else
			{
				int s;
				s=money-Counter;
				Counter=0;
				Credit=Credit-s;
				return 1;
			}
		}
	}
	void info()
	{
		cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Credit<<endl;
	}
};
int main()
{
	int ID1,ID2,ID3;
	char CName1,CName2,CName3;
	int Counter1,Counter2,Counter3;
	int Tcounter;
	int Credit;
	bank p1;
	bankjiaotong p2;
	bankVIP p3;
	cin>>ID1>>CName1>>Counter1;
	cin>>ID2>>CName2>>Counter2>>Tcounter;
	cin>>ID3>>CName3>>Counter3>>Credit;
	p1.initial(ID1,CName1,Counter1);
	p2.initial(ID2,CName2,Counter2,Tcounter);
	p3.initial(ID3,CName3,Counter3,Credit);
	int money1,money2,money3,money4;
	int money11,money22,money33,money44;
	int money111,money222,money333,money444;
	cin>>money1>>money2>>money3>>money4;
	cin>>money11>>money22>>money33>>money44;
	cin>>money111>>money222>>money333>>money444;
	p1.save(money1);
	p1.save(money2);
	p1.take(money3);
	p1.take(money4);
	p2.save(money11);
	p2.take(money22);
	p2.transfer(money33);
	p2.transfer(money44);
	p3.save(money111);
	p3.take(money222);
	p3.over(money333);
	p3.over(money444);
	p1.info();
	p2.info();
	p3.info();
	return 0;
}
