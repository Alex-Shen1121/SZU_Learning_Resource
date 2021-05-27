2018192026:Problem1129:正确
#include<stdio.h>
#include<string.h>
//类定义
class NCard
{
protected:
	int ID;
	char name;
	int balance;
public:
	NCard(){}
	void initial(int id,char n,int b);
	int save(int b);
	int withdraw(int b);
	virtual void info();
};
//类实现
void NCard::initial(int id,char n,int b)
{
	ID=id,balance=b;
	name=n;
}
int NCard::save(int b)
{
	if(b<=0)
		return -1;
	else
	{
		balance+=b;
		return 1;
	}
}
int NCard::withdraw(int b)
{
	if(b<=0||balance<b)
		return -1;
	else
	{
		balance-=b;
		return 1;
	}
}
void NCard::info()
{
	printf("%d-%c-%d\n",ID,name,balance);
}
//类定义
class TCard:public NCard
{
protected:
	int Tcounter;
public:
	TCard(){}
	void initial(int id,char n,int b,int t);
	int transfer(int t);
	void info();
};
//类实现
void TCard::initial(int id,char n,int b,int t)
{
	ID=id,balance=b,Tcounter=t;
	name=n;
}
int TCard::transfer(int t)
{
	if(t<=0||balance<t)
		return -1;
	else
	{
		balance-=t;
		Tcounter+=t;
		return 1;
	}
}
void TCard::info()
{
	printf("%d-%c-%d-%d\n",ID,name,balance,Tcounter);
}
//类定义
class VIPCard:public TCard
{
protected:
	int credit;
public:
	VIPCard(){}
	void initial(int id,char n,int b,int c);
	int over(int c);
	void info();
};
//类实现
void VIPCard::initial(int id,char n,int b,int c)
{
	ID=id,name=n;
	balance=b,credit=c;
}
int VIPCard::over(int c)
{
	if(c>credit)
		return -1;
	else
	{
		credit-=(c-balance);
		balance=0;
		return 1;
	}
}
void VIPCard::info()
{
	printf("%d-%c-%d-%d\n",ID,name,balance,credit);
}
//多态函数
void show(NCard &obj)
{
	obj.info();
}
//主函数
int main()
{
	int i,m;					
	int id1,id2,id3;		//3个账户的ID
	char n1,n2,n3;			//3个账户的name
	int b1,b2,b3;			//3个账户的余额
	int Tcounter,credit;	//交通卡的交通余额和VIP卡的信用额度
	int o;					//操作
	NCard C1;
	TCard C2;
	VIPCard C3;
	scanf("%d %c %d",&id1,&n1,&b1);
	scanf("%d %c %d %d",&id2,&n2,&b2,&Tcounter);
	scanf("%d %c %d %d",&id3,&n3,&b3,&credit);
	C1.initial(id1,n1,b1);							//三个对象初始化
	C2.initial(id2,n2,b2,Tcounter);
	C3.initial(id3,n3,b3,credit);
	for(i=0;i<4;i++)								//对普通卡进行操作
	{
		scanf("%d",&o);
		if(i<2)
			m=C1.save(o);
		else
			m=C1.withdraw(o);
	}
	for(i=0;i<4;i++)								//对交通卡进行操作
	{
		scanf("%d",&o);
		if(i==0)
			m=C2.save(o);
		else if(i==1)
			m=C2.withdraw(o);
		else
			m=C2.transfer(o);
	}
	for(i=0;i<4;i++)								//对VIP卡进行操作
	{
		scanf("%d",&o);
		if(i==0)
			m=C3.save(o);
		else if(i==1)
			m=C3.withdraw(o);
		else
			m=C3.over(o);
	}
	show(C1);
	show(C2);
	show(C3);
	return 0;
}


	





