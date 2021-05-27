2018191214:Problem1129:正确
#include<iostream>
#include<cstring>
#include<cmath>
#include<iomanip>
using namespace std;
class NormalCard
{
protected:
	int ID,Counter;
	char CName;
public:
	NormalCard(){}
	NormalCard(int id,int count,char na)
	{
		ID=id;
		Counter=count;
		CName=na;
	}
	virtual void initial(int id,int co,char na)
	{
		ID=id;
		Counter=co;
		CName=na;
	}
	virtual int save(float money)
	{
		if(money>0 && money-(int)money==0)
		Counter=Counter+money;
		else
			return -1;
		return 1;
	}
	virtual int take(float money)
	{
		if(money<=Counter &&money-(int)money==0 &&money>0)
			Counter=Counter-money;
		else
			return -1;
		return 1;
	}
	virtual void info()
	{
		cout<<ID<<"-"<<CName<<"-"<<Counter<<endl;
	}
};
class transFer:public NormalCard
{
protected:
	int Tcounter;
public:
	transFer(){}
	transFer(int id,int count,char na,int tc):Tcounter(tc),NormalCard(id,count,na){}
	int transfer(int money)
	{
		if(money>0 && money<=Counter)
		{
			Tcounter=Tcounter+money;
            Counter=Counter-money;
		}
		else
			return -1;
		return 1;
	}
    void initial(int id,int co,char na,int Tc)
	{
		ID=id;
		Counter=co;
		CName=na;
		Tcounter=Tc;
	}
	void info()
	{
		cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Tcounter<<endl;
	}
};
class VIP:public NormalCard
{
protected:
	int Credit;
public:
	VIP(){}
	VIP(int ID,int counter,char name,int cr):Credit(cr),NormalCard(ID,counter,name){}
	int over(int money)
	{
		if(money>0 &&money<Credit+Counter&&money>Counter)
		{
			money=money-Counter;
			Counter=0;
			Credit=Credit-money;
		}
		else
			return -1;
		return 1;
	}
    void initial(int id,int co,char na,int cr)
	{
		ID=id;
		Counter=co;
		CName=na;
		Credit=cr;
	}
	void info()
	{
		cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Credit<<endl;
	}
};
void show(NormalCard &obj)//多态函数
{
	obj.info();
}
int main()
{
	int ID,Counter,Tcounter,Credit,money1;//定义各个变量
	float money;
	char CName;
	NormalCard nc;
	transFer tf;
	VIP vip;//定义三个卡对象
	cin>>ID>>CName>>Counter;
	nc.initial(ID,Counter,CName);
	cin>>ID>>CName>>Counter>>Tcounter;
	tf.initial(ID,Counter,CName,Tcounter);
	cin>>ID>>CName>>Counter>>Credit;
	vip.initial(ID,Counter,CName,Credit);//初始化
	cin>>money;
	nc.save(money);
	cin>>money;
	nc.save(money);
	cin>>money;
	nc.take(money);
	cin>>money;
	nc.take(money);//普通卡两次存款，两次取款；
	cin>>money;
	tf.save(money);
	cin>>money;
	tf.take(money);
	cin>>money1;
	tf.transfer(money1);
	cin>>money1;
	tf.transfer(money1);//交通卡一次存款，一次取款，两次转账；
	cin>>money;
	vip.save(money);
	cin>>money;
	vip.take(money);
	cin>>money1;
	vip.over(money1);
	cin>>money1;
	vip.over(money1);//贵宾卡一次存款，一次取款，两次透支；
	show(nc);
	show(tf);
	show(vip);
	return 0;
}

