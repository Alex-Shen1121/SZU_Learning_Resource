2018191214:Problem1120:´ğ°¸´íÎó
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
class Animal
{
public:
	virtual void speak()
	{
		cout<<"Hello,I am animal."<<endl;
	}
};
class Tiger:public Animal
{
protected:
	char name[20];
	int old;
public:
	Tiger(){}
	Tiger(char na[20],int ol):old(ol)
	{
		strcpy(name,na);
	}
    void speak()
	{
		cout<<"Hello,I am "<<name<<",AOOO."<<endl;
	}
};
class Pig:public Animal
{	
	char name[20];
	int old;
public:
	Pig(){}
	Pig(char na[20],int ol):old(ol)
	{
	    strcpy(name,na);
	}
    void speak()
	{
		cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
	}
};
class Duck:public Animal
{
	char name[20];
	int old;
public:
	Duck(){}
	Duck(char na[20],int ol):old(ol)
	{
		strcpy(name,na);
	}
    void speak()
	{
		cout<<"Hello,I am "<<name<<",GAGA."<<endl;
	}
};
int main()
{
	int t,old;
	char name[20],kind[20];
	Animal *p;
	cin>>t;
	while(t--)
	{
		cin>>kind>>name>>old;
		if(strcmp(kind,"Tiger")==0)
		{
			p=new Tiger(name,old);
			p->speak();
		}
		else if(strcmp(kind,"Pig")==0)
		{
			p=new Pig(name,old);
			p->speak();
		}
		else if(strcmp(kind,"Duck")==0)
		{
			p=new Duck(name,old);
			p->speak();
		}
		else 
			cout<<"There is no "<<kind<<" in our Zoo."<<endl;
	}
	return 0;
}

