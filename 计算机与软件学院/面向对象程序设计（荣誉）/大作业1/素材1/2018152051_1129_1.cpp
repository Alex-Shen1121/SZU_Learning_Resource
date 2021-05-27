2018152051:Problem1129:ÕıÈ·
#include <iostream>
using namespace std;
class CCommon
{
protected:
	 long ID;
	 char CName;
	 int Counter;
public:
	CCommon(){}
	virtual void initial(long id,char name,int counter)
	{
		ID = id;
		CName = name;
		Counter = counter;
	}
	void save(int num)
	{
		if(num>=0)
			Counter+=num;
		else
			Counter = Counter;
	}
	bool take(int num)
	{
		if(num>=0)
		{
			if(num>Counter)
			{
				return false;
			}
			else
			{
				Counter-=num;
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	virtual void info()
	{
		cout<<ID<<"-"<<CName<<"-"<<Counter<<endl;
	}
};
class CTransfer:public CCommon
{
	int Tcounter;
public:
	CTransfer(){}
	void initial(long id,char name,int counter,int tc)
	{
		ID = id;
		CName = name;
		Counter = counter;
		Tcounter = tc;
	}
	bool transfer(int num)
	{
		if(num>Counter)
		{
			Tcounter = Tcounter;
			Counter = Counter;
			return false;
		}
		else
		{
			Tcounter+=num;
			Counter-=num;
		}
	}
	void info()
	{
		cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Tcounter<<endl;
	}
};
class CVeryImpPer:public CCommon
{
	int credit;
public:
	CVeryImpPer(){}
	void initial(long id,char name,int counter,int cr)
	{
		ID = id;
		CName = name;
		Counter = counter;
		credit = cr;
	}
	bool over(int num)
	{
		if(num>Counter+credit)
		{
			credit = credit;
			Counter = Counter;
			return false;
		}
		else
		{
			credit-=(num-Counter);
			Counter = 0;
			return true;
		}
	}
	void info()
	{
		cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<credit<<endl;
	}
};
void show(CCommon& obj)
{
	obj.info();
}
int main()
{
	long id1,id2,id3;
	char name1,name2,name3;
	int counter1,counter2,counter3;
	int balance1,credit1;
	cin>>id1>>name1>>counter1;
	cin>>id2>>name2>>counter2>>balance1;
	cin>>id3>>name3>>counter3>>credit1;
	CCommon c1;
	CTransfer c2;
	CVeryImpPer c3;
	c1.initial(id1,name1,counter1);
	c2.initial(id2,name2,counter2,balance1);
	c3.initial(id3,name3,counter3,credit1);
	int num1,num2,num3,num4;
	cin>>num1;
	c1.save(num1);
	cin>>num2;
	c1.save(num2);
	cin>>num3;
	if(c1.take(num3)){}
	cin>>num4;
	if(c1.take(num4)){}
	show(c1);
	cin>>num1;
	c2.save(num1);
	cin>>num2;
	if(c2.take(num2)){}
	cin>>num3;
	if(c2.transfer(num3)){}
	cin>>num4;
	if(c2.transfer(num4)){}
	show(c2);
	cin>>num1;
	c3.save(num1);
	cin>>num2;
	if(c3.take(num2)){}
	cin>>num3;
	if(c3.over(num3)){}
	cin>>num4;
	if(c3.over(num4)){}
	show(c3);
}

