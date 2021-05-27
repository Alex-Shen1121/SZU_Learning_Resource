2018041051:Problem1129:ÕýÈ·
#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>
 
using namespace std;
 
class Card{
protected:
	long ID;
	char name;
	int balance;
public:
    Card(){}
    Card(long ID1,char name1,int balance1):ID(ID1),name(name1),balance(balance1){}
    int save(int num)
    {
    	if(num<=0)
    		return -1;
    	else
    		balance+=num;
    	return 1;
	}
	int take(int num)
	{
		if(num<=0)
    		return -1;
    	else if(num>balance)
    		return -1;
    	else
    	{
    		balance-=num;
    		return 1;
		}
	}
	virtual void info()
	{
		cout<<ID<<"-"<<name<<"-"<<balance<<endl;
	}
	virtual void initial(long ID1,char name1,int balance1)
	{
		ID=ID1;
		name=name1;
		balance=balance1;
	}
};
 
class tCard:public Card{
protected:
	int counter;
public:
	tCard(){}
	tCard(long ID1,char name1,int balance1,int counter1):Card(ID1,name1,balance1),counter(counter1){}
	int transfer(int num)
	{
		if(num<=0)
    		return -1;
		if(num>balance)
			return -1;
		else
		{
			balance-=num;
			counter+=num;
		}
		return 1;
	}
	void info()
	{
		cout<<ID<<"-"<<name<<"-"<<balance<<"-"<<counter<<endl;
	}
	void initial(long ID1,char name1,int balance1,int counter1)
	{
		ID=ID1;
		name=name1;
		balance=balance1;
		counter=counter1;
	}
};

class vCard:public Card{
protected:
	int credit;
public:
	vCard(){}
	vCard(long ID1,char name1,int balance1,int credit1):Card(ID1,name1,balance1),credit(credit1){}
	int over(int num)
	{
		if(num<=0)
    		return -1;
    	if(num>balance+credit)
    		return -1;
    	else
    	{
    		credit=credit-(num-balance);
    		balance=0;
		}
		return 1;
	}
	void info()
	{
		cout<<ID<<"-"<<name<<"-"<<balance<<"-"<<credit<<endl;
	}
	void initial(long ID1,char name1,int balance1,int credit1)
	{
		ID=ID1;
		name=name1;
		balance=balance1;
		credit=credit1;
	}
};

void show(Card & obj)
{
	obj.info();
}

int main()
{
	//freopen("r.txt","r",stdin);
	long ID;
	char name;
	int balance,counter,credit,num;
    Card card;
    tCard tcard;
    vCard vcard;
    cin>>ID>>name>>balance;
    card.initial(ID,name,balance);
    cin>>ID>>name>>balance>>counter;
    tcard.initial(ID,name,balance,counter);
    cin>>ID>>name>>balance>>credit;
    vcard.initial(ID,name,balance,credit);
 	
 	for(int i=0;i<4;i++)
 	{
 		cin>>num;
 		if(i<2)
 		{
 			card.save(num);
		}
		else
		{
			card.take(num);
		}
	}
	for(int i=0;i<4;i++)
 	{
 		cin>>num;
 		if(i==0)
 		{
 			tcard.save(num);
		}
		else if(i==1)
		{
			tcard.take(num);
		}
		else
		{
			tcard.transfer(num);
		}
	}
	for(int i=0;i<4;i++)
 	{
 		cin>>num;
 		if(i==0)
 		{
 			vcard.save(num);
		}
		else if(i==1)
		{
			vcard.take(num);
		}
		else
		{
			vcard.over(num);
		}
	}
	
	show(card);
	show(tcard);
	show(vcard);
 	
    return 0;
}
