2018192026:Problem1120:ÕıÈ·
#include<stdio.h>
#include<string.h>
class Animal
{
protected:
	int age;
	char *name;
public:
	virtual void Speak()=0;
};
class Tiger:public Animal
{
public:
	Tiger(char *n,int a)
	{
		age=a;
		name=new char[10];
		strcpy(name,n);
	}
	void Speak()
	{
		printf("Hello,I am %s,AOOO.\n",name);
	}
};
class Dog:public Animal
{
public:
	Dog(char *n,int a)
	{
		age=a;
		name=new char[10];
		strcpy(name,n);
	}
	void Speak()
	{
		printf("Hello,I am %s,WangWang.\n",name);
	}
};
class Duck:public Animal
{
public:
	Duck(char *n,int a)
	{
		age=a;
		name=new char[10];
		strcpy(name,n);
	}
	void Speak()
	{
		printf("Hello,I am %s,GAGA.\n",name);
	}
};
class Pig:public Animal
{
public:
	Pig(char *n,int a)
	{
		age=a;
		name=new char[10];
		strcpy(name,n);
	}
	void Speak()
	{
		printf("Hello,I am %s,HENGHENG.\n",name);
	}
};
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		getchar();
		char *kind=new char[10];
		char *name=new char[10];
		Animal *A;
		int age;
		scanf("%s %s %d",kind,name,&age);
		if(strcmp(kind,"Tiger")==0)
		{
			Tiger A1(name,age);
			A=&A1;
			A->Speak();
		}
		else if(strcmp(kind,"Pig")==0)
		{
			Pig A2(name,age);
			A=&A2;
			A->Speak();
		}
		else if(strcmp(kind,"Duck")==0)
		{
			Duck A3(name,age);
			A=&A3;
			A->Speak();
		}
		else if(strcmp(kind,"Dog")==0)
		{
			Dog A4(name,age);
			A=&A4;
			A->Speak();
		}
		else
			printf("There is no %s in our Zoo.\n",kind);
	}
	return 0;
}

		

