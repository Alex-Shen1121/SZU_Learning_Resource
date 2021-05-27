2018152029:Problem1129:ÕýÈ·
#include<bits/stdc++.h>
using namespace std;
class Card;
void show(Card &obj);
class Card
{
protected:
	string ID;
	char CName;
	int Counter;
public:
	Card() {}
	Card(string id, char n, int c) :ID(id), CName(n), Counter(c) {}
	int save(int m)
	{
		if (m > 0)
		{
			Counter += m;
			return 1;
		}
		return -1;
	}
	int take(int m)
	{
		if (m > 0 && Counter >= m)
		{
			Counter -= m;
			return 1;
		}
		return -1;
	}
	virtual void info()
	{
		cout << ID << "-" << CName << "-" << Counter << endl;
	}
};

class TrafficCard :public Card
{
	int Tcounter;
public:
	TrafficCard(string i, char n, int c, int t) :Card(i,n,c), Tcounter(t) {}
	int transfer(int m)
	{
		if (m < 0)
			return -1;
		if (m <= Counter)
		{
			Counter -= m, Tcounter += m;
			return 1;
		}
		return -1;
	}
	virtual void info()
	{
		cout << ID << '-' << CName << '-' << Counter << '-' << Tcounter << endl;
	}
};

class VIPcard :public Card
{
	int Credit;
public:
	VIPcard(string i, char n, int c, int cre) :Card(i, n, c),Credit(cre){}
	bool over(int m)
	{
		if (m < 0)
			return -1;
		if (Counter + Credit >= m)
		{
			if (Counter >= m)
				Counter -= m;
			else
			{
				Credit -= (m-Counter);
				Counter = 0;
			}
		}
		return -1;
	}
	void info()
	{
		cout << ID << '-' << CName << '-' << Counter << '-' << Credit << endl;
	}
};

void show(Card &obj)
{
	obj.info();
}

int main()
{
	string a;
	int c, d;
	char b;
	cin >> a >> b >> c;
	Card aa(a, b, c);
	cin >> a >> b >> c >> d;
	TrafficCard bb(a, b, c, d);
	cin >> a >> b >> c >> d;
	VIPcard cc(a, b, c, d);
	cin >> c>>d;
	aa.save(c);
	aa.save(d);
	cin >> c >> d;
	aa.take(c);
	aa.take(d);
	cin >> c >> d;
	bb.save(c);
	bb.take(d);
	cin >> c >> d;
	bb.transfer(c);
	bb.transfer(d);
	cin >> c >> d;
	cc.save(c);
	cc.take(d);
	cin >> c >> d;
	cc.over(c);
	cc.over(d);
	show(aa);
	show(bb);
	show(cc);
	//system("pause");
	return 0;
}
