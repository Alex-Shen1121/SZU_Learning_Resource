2018151092:Problem1129:��ȷ
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

class Card
{
	protected:
		int ID;
		char CName;
		double Counter;
	public:
		Card()
		{
		}
		
		virtual void initial(int id,char n,double c)
		{
			ID=id;
			CName=n;
			Counter=c;
		}
		
		virtual int save(double s)
		{
			if(s>0)
			{
				Counter+=s;
				return 1; 
			}
			
			return -1;
		}
		
		virtual int take(double t)
		{
			if(t>0)
			{
				if(t<Counter)
				{
					Counter-=t;
					return 1;
				}
				
				return -1;
			}
			
			return -1;
		}
		
		virtual void info()
		{
			cout<<ID<<"-"<<CName<<"-"<<Counter<<endl;
		}
		
		~Card()
		{
		} 
};

class TCard:public Card
{
	protected:
		double TCounter;
	public:
		TCard()
		{
		}
		
		virtual void initial(int id,char n,double c,double t)
		{
			ID=id;
			CName=n;
			Counter=c;
			TCounter=t;
		}
		
		virtual int save(double s)
		{
			if(s>0)
			{
				Counter+=s;
				return 1; 
			}
			
			return -1;
		}
		
		virtual int take(double t)
		{
			if(t>0)
			{
				if(t<Counter)
				{
					Counter-=t;
					return 1;
				}
				
				return -1;
			}
			
			return -1;
		}
		
		int transfer(double t)
		{
			if(t>0)
			{
				if(t<Counter)
				{
					TCounter+=t;
					Counter-=t;
					
					return 1;
				}
				
				return -1;
			}
			
			return -1;
		}
		
		virtual void info()
		{
			cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<TCounter<<endl;
		}
		
		~TCard()
		{
		} 
};

class VIPCard:public Card
{
	protected:
		double Credit;
	public:
		VIPCard()
		{
		}
		
		virtual void initial(int id,char n,double c,double t)
		{
			ID=id;
			CName=n;
			Counter=c;
			Credit=t;
		}
		
		int over(double o)
		{
			if(o<Counter+Credit)
			{
				o-=Counter;
				Counter=0;
				Credit-=o;
				return 1;
			}
			
			return -1;
		}
		
		virtual int save(double s)
		{
			if(s>0)
			{
				Counter+=s;
				return 1; 
			}
			
			return -1;
		}
		
		virtual int take(double t)
		{
			if(t>0)
			{
				if(t<Counter)
				{
					Counter-=t;
					return 1;
				}
				
				return -1;
			}
			
			return -1;
		}
		
		virtual void info()
		{
			cout<<ID<<"-"<<CName<<"-"<<Counter<<"-"<<Credit<<endl;
		}
		
		~VIPCard()
		{
		} 
};

void show(Card &obj)
{
	obj.info();
}

int main()
{
	int ID;
	char name;
	double counter;
	double tcounter;
	double credit;//����һϵ�б��������������
	
	Card Ace;
	TCard Beta;
	VIPCard Cita;//�������������� 
	

	cin>>ID>>name>>counter;
	Ace.initial(ID,name,counter);
		
	cin>>ID>>name>>counter>>tcounter;
	Beta.initial(ID,name,counter,tcounter);
		
	cin>>ID>>name>>counter>>credit;
	Cita.initial(ID,name,counter,credit);//�������ݲ�����������ĳ�ʼ�����������������initial����
	
	double op1,op2,op3,op4;
	int	Ace_d1,Ace_d2,Ace_w1,Ace_w2;
	int Beta_d,Beta_w,Beta_t1,Beta_t2;
	int Cita_d,Cita_w,Cita_c1,Cita_c2;//�������ݲ���˳��ִ�в��� 
	
	cin>>op1>>op2>>op3>>op4;
	Ace_d1=Ace.save(op1);
	Ace_d2=Ace.save(op2);
	Ace_w1=Ace.take(op3);
	Ace_w2=Ace.take(op4);//��ͨ��2�δ��2��ȡ�����save��take���� 
	
	cin>>op1>>op2>>op3>>op4;
	Beta_d=Beta.save(op1);
	Beta_w=Beta.take(op2);
	Beta_t1=Beta.transfer(op3);
	Beta_t2=Beta.transfer(op4);//��1�δ��1��ȡ��2��ת�ˣ�����save\take\transfer���� 
	
	cin>>op1>>op2>>op3>>op4;
	Cita_d=Cita.save(op1);
	Cita_w=Cita.take(op2);
	Cita_c1=Cita.over(op3);
	Cita_c2=Cita.over(op4);//�����1�δ��1��ȡ��2��͸֧������save\take\over���� 
	
	show(Ace);
	show(Beta);
	show(Cita); 
	
	return 0;
}
