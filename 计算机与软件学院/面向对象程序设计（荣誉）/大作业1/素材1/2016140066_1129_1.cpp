2016140066:Problem1129:正确
#include <iostream>
using namespace std;
//----类定义----
class NCard //普通卡
{
protected:
	int ID, Counter;
	char CName;
public:
	NCard(){}
	NCard(int id,char n,int c):ID(id),CName(n),Counter(c){}
	void initial(int id, char n, int c);
	int save(int money);
	int take(int money);
	virtual void info();
};
class Trafficcard :public NCard //交通卡
{
protected:
	int Tcounter;
public:
	Trafficcard(){}
	Trafficcard(int id, char n, int c,int t):NCard(id,n,c),Tcounter(t){}
	void initial(int id, char n, int c,int t);
	int transfer(int money);
	virtual void info();
};
class VIPcard :public NCard //贵宾卡
{
protected:
	int Credit;
public:
	VIPcard(){}
	VIPcard(int id, char n, int c, int cr):NCard(id,n,c),Credit(cr){}
	void initial(int id, char n, int c, int cr);
	int over(int money);
	virtual void info();
};
//----类实现----
void NCard::initial(int id, char n, int c)
{
	ID = id;
	CName = n;
	Counter = c;
}
int NCard::save(int money)
{
	if (money < 0)
	{
		return -1;
	}
	else
	{
		Counter += money;
		return 1;
	}
}
int NCard::take(int money)
{
	if ((money < 0)||(money>Counter))
	{
		return -1;
	}
	else
	{
		Counter -= money;
		return 1;
	}
}
void NCard::info()
{
	cout << ID << "-" << CName << "-" << Counter << endl;
}
void Trafficcard::initial(int id, char n, int c,int t)
{
	ID=id;
	CName = n;
	Counter = c;
	Tcounter = t;
}
int Trafficcard::transfer(int money)
{
	if ((money < 0) || (money > Counter))
	{
		return -1;
	}
	else
	{
		Counter -= money;
		Tcounter += money;
		return 1;
	}
}
void Trafficcard::info()
{
	cout << ID << "-" << CName << "-" << Counter << "-"<<Tcounter<<endl;
}
void VIPcard::initial(int id, char n, int c, int cr)
{
	ID = id;
	CName = n;
	Counter = c;
	Credit = cr;
}
int VIPcard::over(int money)
{
	if (money > (Counter + Credit))
	{
		return -1;
	}
	else
	{
		Credit = Credit - (money - Counter);
		Counter = 0;
		return 1;
	}
}
void VIPcard::info()
{
	cout << ID << "-" << CName << "-" << Counter << "-" << Credit << endl;
}
//----虚函数----
void show(NCard &obj)
{
	obj.info();
}
//----主函数----
int main()
{
	int id1, id2, id3, b1, b2, b3, tb,cb,N1,N2,N3,N4,T1,T2,T3,T4,V1,V2,V3,V4;
	char n1, n2, n3;
	NCard s1;
	Trafficcard s2;
	VIPcard s3;
	cin >> id1 >> n1 >> b1
		>> id2 >> n2 >> b2 >> tb
		>> id3 >> n3 >> b3 >> cb;
	s1.initial(id1, n1, b1);
	s2.initial(id2, n2, b2, tb);
	s3.initial(id3, n3, b3, cb);
	cin >> N1 >> N2 >> N3 >> N4
		>> T1 >> T2 >> T3 >> T4
		>> V1 >> V2 >> V3 >> V4;
	s1.save(N1);
	s1.save(N2);
	s1.take(N3);
	s1.take(N4);
	s2.save(T1);
	s2.take(T2);
	s2.transfer(T3);
	s2.transfer(T4);
	s3.save(V1);
	s3.take(V2);
	s3.over(V3);
	s3.over(V4);
	show(s1);
	show(s2);
	show(s3);
	return 0;
}
