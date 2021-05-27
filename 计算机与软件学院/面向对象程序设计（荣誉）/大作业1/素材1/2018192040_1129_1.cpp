2018192040:Problem1129:´ğ°¸´íÎó
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class card{
protected:
	int ID,counter;
	string name;
public:
	card(){
	};
	card(int id,int c,string n):ID(id),counter(c),name(n){
	};
	void initial(){
		cin>>ID>>name>>counter;
	}
	int save(double n){
		if(n/10!=0||n<0)
			return -1;
		counter += n;
		return 1;
	}
	int take(int n){
		if(n/10!=0 || n>counter||n<0)
			return -1;
		counter -= n;
		return 1;
	}
	virtual void show(){
		cout<<ID<<"-"<<name<<"-"<<counter<<endl;
	}
};

class tcard:public card{
	int tcounter;
public:
	tcard(){
	};
	tcard(int id,int c,string n,int t):card(id,c,n),tcounter(t){
	};
	int transfer(double n){
		if(n/10!=0 || counter < n||n<0)
			return -1;
		counter -= n;
		tcounter += n;
	}
	void show(){
		cout<<ID<<"-"<<name<<"-"<<counter<<"-"<<tcounter<<endl;
	}

};

class creCard:public card{
	int credit;
public:
	creCard(){
	};
	creCard(int id,int c,string n,int cr):card(id,c,n),credit(cr){
	};
	int over(double n){
		if(n/10!=0 || n>credit+counter || n<0)
			return -1;
		else if(n<counter){
			counter -= n;
		}
		else{
			counter = 0;
			credit -= (n-counter);
		}
	}
	void show(){
		cout<<ID<<"-"<<name<<"-"<<counter<<"-"<<credit<<endl;
	}
};

int main(){
	int id,counter,tcounter,credit;
	string name;
	cin>>id>>name>>counter;
	card c1(id,counter,name);
	cin>>id>>name>>counter>>tcounter;
	tcard c2(id,counter,name,tcounter);
	cin>>id>>name>>counter>>credit;
	creCard c3(id,counter,name,credit);
	int n1,n2,n3,n4;
	cin>>n1>>n2>>n3>>n4;
	c1.save(n1);
	c1.save(n2);
	c1.take(n3);
	c1.take(n4);
	c1.show();
	cin>>n1>>n2>>n3>>n4;
	c2.save(n1);
	c2.take(n2);
	c2.transfer(n3);
	c2.transfer(n4);
	c2.show();
	cin>>n1>>n2>>n3>>n4;
	c3.save(n1);
	c3.take(n2);
	c3.over(n3);
	c3.over(n3);
	c3.show();
}
