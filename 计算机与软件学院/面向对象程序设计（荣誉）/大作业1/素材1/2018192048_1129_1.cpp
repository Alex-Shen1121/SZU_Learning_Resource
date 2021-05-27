2018192048:Problem1129:ÕıÈ·
#include<iostream>
using namespace std;

class ComCard{
protected:
	string ID;
	char CName;
	double Counter;
public:
	ComCard(){}
	ComCard(string id,char n,double c):ID(id),CName(n),Counter(c){}
	virtual void initial(string id,char n,double c){
		ID=id;
		CName=n;
		Counter=c;
	}
	int judgeSave(double m){
		int temp=(int)m;
		if(m<0)
			return -1;
		else if((m-temp)!=0)
			return -1;
		return 1;
	}
	virtual void save(double m){
		if(judgeSave(m)==1)
			Counter+=m;
	}
	int judgeTake(double m){
		int temp=(int)m;
		if(m<0)
			return -1;
		else if((m-temp)!=0)
			return -1;
		else if(m>Counter)
			return -1;
		return 1;
	}
	virtual void take(double m){
		if(judgeTake(m)==1)
			Counter-=m;
	}
	virtual void info(){
		cout<<ID<<"-"<<CName<<"-"<<Counter<<endl;
	}
	~ComCard(){}
};

class TracCard:public ComCard{
protected:
	double Tcounter;
public:
	TracCard(){}
	TracCard(string id,char n,double c,double t):ComCard(id,n,c){
		Tcounter=t;
	}
	void initial(string id,char n,double c,double t){
		ID=id;
		CName=n;
		Counter=c;
		Tcounter=t;
	}
	int judgeSave(double m){
		int temp=(int)m;
		if(m<0)
			return -1;
		else if((m-temp)!=0)
			return -1;
		return 1;
	}
	void save(double m){
		if(judgeSave(m)==1)
			Counter+=m;
	}
	int judgeTake(double m){
		int temp=(int)m;
		if(m<0)
			return -1;
		else if((m-temp)!=0)
			return -1;
		else if(m>Counter)
			return -1;
		return 1;
	}
	void take(double m){
		if(judgeTake(m)==1)
			Counter-=m;
	}
	int judgeTransfer(double m){
		if(m>Counter)
			return -1;
		return 1;
	}
	void transfer(double m){
		if(judgeTransfer(m)==1){
			Tcounter+=m;
			Counter-=m;
		}
	}
	void info(){
		cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Tcounter<<endl;
	}
	~TracCard(){}
};

class VIPCard:public ComCard{
protected:
	double Credit;
public:
	VIPCard(){}
	VIPCard(string id,char n,double c,double C):ComCard(id,n,c){
		Credit=C;
	}
	void initial(string id,char n,double c,double C){
		ID=id;
		CName=n;
		Counter=c;
		Credit=C;
	}
	int judgeSave(double m){
		int temp=(int)m;
		if(m<0)
			return -1;
		else if((m-temp)!=0)
			return -1;
		return 1;
	}
	void save(double m){
		if(judgeSave(m)==1)
			Counter+=m;
	}
	int judgeTake(double m){
		int temp=(int)m;
		if(m<0)
			return -1;
		else if((m-temp)!=0)
			return -1;
		else if(m>Counter)
			return -1;
		return 1;
	}
	void take(double m){
		if(judgeTake(m)==1)
			Counter-=m;
	}
	int judgeOver(double m){
		if(m<=Counter+Credit)
			return 1;
		return -1;
	}
	void over(double m){
		if(judgeOver(m)==1){
			if(m>Counter){
				Credit-=(m-Counter);
				Counter=0;
			}
			else
				Counter-=m;	
		}
	}
	void info(){
		cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Credit<<endl;
	}
	~VIPCard(){}
};
void show(ComCard &obj){
	obj.info();
}
int main(){
	string id1,id2,id3;
	char n1,n2,n3;
	double c1,c2,d2,c3,d3;
	cin>>id1>>n1>>c1;
	ComCard o(id1,n1,c1);
	cin>>id2>>n2>>c2>>d2;
	TracCard p(id2,n2,c2,d2);
	cin>>id3>>n3>>c3>>d3;
	VIPCard q(id3,n3,c3,d3);
	double num1,num2,num3,num4;
	cin>>num1>>num2>>num3>>num4;
	o.save(num1);
	o.save(num2);
	o.take(num3);
	o.take(num4);
	show(o);
	cin>>num1>>num2>>num3>>num4;
	p.save(num1);
	p.take(num2);
	p.transfer(num3);
	p.transfer(num4);
	show(p);
	cin>>num1>>num2>>num3>>num4;
	q.save(num1);
	q.take(num2);
	q.over(num3);
	q.over(num4);
	show(q);
	return 0;
}
