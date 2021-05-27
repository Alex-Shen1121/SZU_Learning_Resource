2018192050:Problem1129:ÕıÈ·
#include<bits/stdc++.h>
using namespace std;
class Card{
    protected:
        string id;
        string name;
        int counter;
    public:
        Card(){
        }
        Card(string a,string b,int c){
            id=a;
            name=b;
            counter=c;
        }
        ~Card(){
        }
    	void initial()
    	{
    		id="0";
    		name="0";
    		counter=0;
		}
		int save(int a)
		{
			if(a<0)
				return -1;
			else
				counter+=a;
			return 1;
		}
		int take(int a)
		{
			if(a<0||a>counter)
				return -1;
			else
				counter-=a;
			return 1;
		}
		virtual void info()
		{
			cout<<id<<"-"<<name<<"-"<<counter<<endl;
		}
};
class JTCard:public Card{
    protected:
        int jtcounter;
    public:
        JTCard(){
        }
        JTCard(string a,string b,int c,int d){
        	id=a;
            name=b;
            counter=c;
            jtcounter=d;
        }
        ~JTCard(){
        } 
           	void initial()
    	{
    		id="0";
    		name="0";
    		counter=0;
		}
		int save(int a)
		{
			if(a<0)
				return -1;
			else
				counter+=a;
			return 1;
		}
		int take(int a)
		{
			if(a<0||a>counter)
				return -1;
			else
				counter-=a;
			return 1;
		}
		int transfer(int a)
		{
			if(a<0||a>counter)
				return -1;
			else
			{
				counter-=a;
				jtcounter+=a;
			}
			return 1;
		}
		void info(){
			cout<<id<<"-"<<name<<"-"<<counter<<"-"<<jtcounter<<endl;
		}
};
class GBCard:public Card{
    protected:
        int credit;
    public:
        GBCard(){
        }
        GBCard(string a,string b,int c,int d){
        	id=a;
            name=b;
            counter=c;
            credit=d;
        }
        ~GBCard(){
        }  
       	void initial()
    	{
    		id="0";
    		name="0";
    		counter=0;
		}
		int save(int a)
		{
			if(a<0)
				return -1;
			else
				counter+=a;
			return 1;
		}
		int take(int a)
		{
			if(a<0||a>counter)
				return -1;
			else
				counter-=a;
			return 1;
		}
		int over(int a){
			if(a<0||counter+credit<a)
				return -1;
			else
			{
				credit-=a-counter;
				counter=0;
				
			}
			return 1;
		}
		void info(){
			cout<<id<<"-"<<name<<"-"<<counter<<"-"<<credit<<endl;
		}
};
void show(Card &obj)
{
	obj.info();
}
int main(){
	string num1,num2,num3,n1,n2,n3;
	int sum1,sum2,sum3;
	int jt,credit;
	int x;
	cin>>num1>>n1>>sum1;
	cin>>num2>>n2>>sum2>>jt;
	cin>>num3>>n3>>sum3>>credit;
	Card a(num1,n1,sum1);
	JTCard b(num2,n2,sum2,jt);
	GBCard c(num3,n3,sum3,credit);
	cin>>x;
	a.save(x);
	cin>>x;
	a.save(x);
	cin>>x;
	a.take(x);
	cin>>x;
	a.take(x);
	show(a);
	cin>>x;
	b.save(x);
	cin>>x;
	b.take(x);
	cin>>x;
	b.transfer(x);
	cin>>x;
	b.transfer(x);
	show(b);
	cin>>x;
	c.save(x);
	cin>>x;
	c.take(x);
	cin>>x;
	c.over(x);
	cin>>x;
	c.over(x);
	show(c);
}

