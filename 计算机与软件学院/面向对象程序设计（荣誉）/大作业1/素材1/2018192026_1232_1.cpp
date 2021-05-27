2018192026:Problem1232:ÕıÈ·
#include<stdio.h>
#include<string.h>
class Vehicle
{
protected:
	char *no;
public:
	virtual void display()=0;
};
class Car:public Vehicle
{
protected:
	int number;
	int weight;
public:
	Car(char *n,int nu,int w):number(nu),weight(w)
	{
		no=new char[10];
		strcpy(no,n);
	}
	void display()
	{
		printf("%s %d\n",no,number*8+weight*2);
	}
};
class Truck:public Vehicle
{
protected:
	int weight;
public:
	Truck(char *n,int w):weight(w)
	{
		no=new char[10];
		strcpy(no,n);
	}
	void display()
	{
		printf("%s %d\n",no,weight*5);
	}
};
class Bus:public Vehicle
{
protected:
	int number;
public:
	Bus(char *n,int nu):number(nu)
	{
		no=new char[10];
		strcpy(no,n);
	}
	void display()
	{
		printf("%s %d\n",no,number*3);
	}
};
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		getchar();
		int n,weight,number;
		char *no=new char[10];
		Vehicle *V;
		scanf("%d",&n);
		if(n==1)
		{
			scanf("%s %d %d",no,&number,&weight);
			Car V1(no,number,weight);
			V=&V1;
			V->display();
		}
		else if(n==2)
		{
			scanf("%s %d",no,&weight);
			Truck V2(no,weight);
			V=&V2;
			V->display();
		}
		else if(n==3)
		{
			scanf("%s %d",no,&number);
			Bus V3(no,number);
			V=&V3;
			V->display();
		}
	}
	return 0;
}


