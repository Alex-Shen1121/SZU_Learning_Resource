2018151044:Problem1119:ÕýÈ·
#include<iostream>
#include<string>
using namespace std;
class BA
{
protected:
	string name,no;
	int ba;
public:
	BA(string a,string b,int c):name(a),no(b),ba(c) {}
	virtual void deposit(int v)
	{
		ba+=v;
	}
	virtual void withdraw(int v)
	{
		if(ba<v)
		{
			cout<<"insufficient"<<endl;
			return ;
		}
		ba-=v;
	}
	virtual void display()
	{
		cout<<name<<" "<<no<<" Balance:"<<ba<<endl;
	}
};
class BP:public BA
{
	int limit;
public:
	BP(string a,string b,int c):BA(a,b,c),limit(5000) {}
	virtual void deposit(int v)
	{
		if(limit!=5000)
		{
			limit+=v;
			if(limit>5000)v=limit-5000,limit=5000;
			else v=0;
		}
		ba+=v;
	}
	virtual void withdraw(int v)
	{
		if(ba+limit<v)
		{
			cout<<"insufficient"<<endl;
			return;
		}
		if(ba>=v)
		{
			ba-=v;
		}
		else 
		{
			v-=ba;
			ba=0;
			limit-=v;
		}
	}
	virtual void display()
	{
		cout<<name<<" "<<no<<" Balance:"<<ba<<" limit:"<<limit<<endl;
	}
};
int main()
{
	int t;
	cin>>t;
	BA *p;
	while(t--)
	{
		string name,no;
		int ba;
		cin>>name>>no>>ba;
		if(no[1]=='P') p=new BP(name,no,ba);
		else p=new BA(name,no,ba);
		int v;
		for(int i=0;i<2;++i)
		{
			cin>>v;
			p->deposit(v);
			cin>>v;
			p->withdraw(v);
		}
		p->display();
		delete p;
	}
}
