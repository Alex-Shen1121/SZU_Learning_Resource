2018152037:Problem1129:ÕıÈ·
#include<iostream>
using namespace std;

class NCard
{
protected:
	long ID;
	char CName;
	int Counter;
public:
	NCard(long I,char m,int y)
	{
		ID=I;
		CName=m;
		Counter=y; 
	}
	void initial(long I,char m,int y)
	{
		ID=I;
		CName=m;
		Counter=y; 
	}
	int save(int k)
	{
		if(k>0)
		{
			Counter=Counter+k;
			return 1;
		}
		else
		return -1;
	}
	int take(int k)
	{
		if(k<=0)
			return -1;
		if(Counter-k<0)
			return -1;
		else
		{
			Counter=Counter-k;
			return 1;
		}
	}
	virtual void info()
	{
		cout<<ID<<"-"<<CName<<"-"<<Counter<<endl;
	}
};

class jt:public NCard
{
	int Tcounter;
public:
	jt(long I,char m,int y,int t):NCard(I,m,y)
	{
		Tcounter=t;
	}
	int transfer(int k)
	{
		if(k<=0)
			return -1;
		if(Counter-k<0)
			return -1;
		else
		{
			Counter=Counter-k;
			Tcounter=Tcounter+k;
			return 1;
		}
	}
	void info()
	{
		cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Tcounter<<endl;
	}
};

class gbk:public NCard
{
	int Credit;
public:
	gbk(long I,char m,int y,int t):NCard(I,m,y)
	{
		Credit=t;
	}
	int over(int k)
	{
		if(k<=0)
			return -1;
		if(Counter+Credit<=k)
			return -1;
		else
		{
			Credit=Counter+Credit-k;
			Counter=0;
		}
	}
	void info()
	{
		cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Credit<<endl;
	}
};

void show(NCard &obj)
{
	obj.info();
}

int main()
{
	long I,I1,I2;
	char m,m1,m2;
	int y,y1,y2,t1,t2;
	cin>>I>>m>>y>>I1>>m1>>y1>>t1>>I2>>m2>>y2>>t2;
	NCard a1(I,m,y);
	jt a2(I1,m1,y1,t1);
	gbk a3(I2,m2,y2,t2);
	int n1,n2,n3,n4;
	cin>>n1>>n2>>n3>>n4;
	a1.save(n1);
	a1.save(n2);
	a1.take(n3);
	a1.take(n4);
	cin>>n1>>n2>>n3>>n4;
	//cout<<n1<<n2<<n3<<n4<<endl;
	a2.save(n1);
	a2.take(n2);
	a2.transfer(n3);
	a2.transfer(n4);
	cin>>n1>>n2>>n3>>n4;
	//cout<<n1<<n2<<n3<<n4<<endl;
	a3.save(n1);
	a3.take(n2);
	a3.over(n3);
	a3.over(n4);
	show(a1);
	show(a2);
	show(a3);
	return 0;
}
