2018152087:Problem1129:ÕıÈ·
#include<iostream>
#include<string>
using namespace std;
class CommonCard
{
protected:
	int id;
	string cname;
	int counter;
public:
	void initial(int i,string cn,int c);
	int save(int num);
	int take(int num);
	virtual void info();
};
void CommonCard::initial(int i,string cn,int c)
{
	id=i;
	cname=cn;
	counter=c;
}
int CommonCard::save(int num)
{
	if(num>0)
	{
		counter+=num;
		return 1;
	}
	else 
		return -1;
}
int CommonCard::take(int num)
{
	if(counter<num||num<=0)
		return -1;
	else
		counter-=num;
	return 1;
}
void CommonCard::info()
{
	cout<<id<<"-"<<cname<<"-"<<counter<<endl;
}

class TCard:public CommonCard
{
	int Tcounter;
public:
	void initial(int i,string cn,int c,int t);
	int transfer(int num);
	virtual void info();
};
void TCard::initial(int i,string cn,int c,int t)
{
	id=i;
	cname=cn;
	counter=c;
	Tcounter=t;
}
int TCard::transfer(int num)
{
	if(num>counter)
		return -1;
	else
	{
		counter-=num;
		Tcounter+=num;
		return 1;
	}
}
void TCard::info()
{
	cout<<id<<"-"<<cname<<"-"<<counter<<"-"<<Tcounter<<endl;
}

class VIPcard:public CommonCard
{
	int credit;
public:
	void initial(int i,string cn,int c,int cr);
	int over(int num);
	virtual void info();
};
void VIPcard::initial(int i,string cn,int c,int cr)
{
	id=i;
	cname=cn;
	counter=c;
	credit=cr;
}
int VIPcard::over(int num)
{
	/*cout<<counter<<endl;
	cout<<credit<<endl;
	cout<<num<<endl;*/
	if(counter+credit<num)
		return -1;
	else
	{
		credit=credit+counter-num;
		counter=0;
	//	cout<<credit<<endl;
		return 1;
	}
}
void VIPcard::info()
{
	cout<<id<<"-"<<cname<<"-"<<counter<<"-"<<credit<<endl;
}

void show(CommonCard &obj)
{
	obj.info();
}
int main()
{
	CommonCard exc;
	TCard ext;
	VIPcard exv;
	int idc;
	string namec;
	int bc;
	cin>>idc>>namec>>bc;
	exc.initial(idc,namec,bc);
	int idt;
	string namet;
	int bt,tt;
	cin>>idt>>namet>>bt>>tt;
	ext.initial(idt,namet,bt,tt);
	int idv,bv,cv;
	string namev;
	cin>>idv>>namev>>bv>>cv;
	exv.initial(idv,namev,bv,cv);
	
	int num1,num2,num3,num4;
	cin>>num1>>num2>>num3>>num4;
	exc.save(num1);
	exc.save(num2);
	exc.take(num3);
	exc.take(num4);
	int num11,num22,num33,num44;
	cin>>num11>>num22>>num33>>num44;
	ext.save(num11);
	ext.take(num22);
	ext.transfer(num33);
	ext.transfer(num44);
	int num111,num222,num333,num444;
	cin>>num111>>num222>>num333>>num444;
	exv.save(num111);
	exv.take(num222);
	exv.over(num333);
	exv.over(num444);
	show(exc);
	show(ext);
	show(exv);
	return 0;
}
