2018192026:Problem1119:ÕýÈ·
#include<stdio.h>
#include<string.h>
class BaseAccount
{
protected:
	char *name;
	char *number;
	int balance;
public:
	BaseAccount(char *n,char *nu,int b):balance(b)
	{
		name=new char[10];
		number=new char[10];
		strcpy(name,n),strcpy(number,nu);
	}
	virtual void withdraw(int b)
	{
		if(b<=balance)
			balance-=b;
		else
			printf("insufficient\n");
	}
	void deposit(int b)
	{
		balance+=b;
	}
	virtual void display()
	{
		printf("%s %s Balance:%d\n",name,number,balance);
	}
};
class BasePlus:public BaseAccount
{
protected:
	int limit;
	int limit_sum;
public:
	BasePlus(char *n,char *nu,int b):BaseAccount(n,nu,b)
	{
		limit=5000;
		limit_sum=0;
	}
	void withdraw(int b)
	{
		if(balance==b)
			balance-=b;
		else if(balance+limit>=b)
			limit_sum+=b-balance,balance=0;
		else
			printf("insufficient\n");
	}
	void display()
	{
		printf("%s %s Balance:%d limit:%d\n",name,number,balance,limit-limit_sum);
	}
};
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		getchar();
		char *name=new char[10];
		char *number=new char[10];
		int balance,amount;
		BaseAccount *B;
		scanf("%s %s %d",name,number,&balance);
		if(number[0]=='B'&&number[1]=='A')
		{
			BaseAccount B1(name,number,balance);
			B=&B1;
			for(int i=0;i<4;i++)
			{
				scanf("%d",&amount);
				if(i%2)
					B->withdraw(amount);
				else
					B->deposit(amount);
			}
			B->display();
		}
		else if(number[0]=='B'&&number[1]=='P')
		{
			BasePlus B2(name,number,balance);
			B=&B2;
			for(int i=0;i<4;i++)
			{
				scanf("%d",&amount);
				if(i%2)
					B->withdraw(amount);
				else
					B->deposit(amount);
			}
			B->display();
		}
	}
	return 0;
}

