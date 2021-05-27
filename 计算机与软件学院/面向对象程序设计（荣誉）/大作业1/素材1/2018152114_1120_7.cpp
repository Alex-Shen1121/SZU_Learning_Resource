2018152114:Problem1120:´ð°¸´íÎó
#include<iostream>
#include<cstring>
using namespace std;
class Animal
{
protected:
	string name;
	string no;
	int old;
public:
	Animal(string noo,int o):no(noo),old(o)
	{
	}
	virtual void speak()=0;
	virtual ~Animal()
	{
	}
};
class Tiger:public Animal
{
public:
		Tiger(string noo,int old4):Animal(noo,old4)
		{
		}
		virtual void speak()
		{
			cout<<"Hello,I am "<<no<<",AOOO."<<endl;
		}
};
class Pig:public Animal
{
public:
	Pig(string noo,int old3):Animal(noo,old3)
	{
	}
	virtual void speak()
		{
			cout<<"Hello,I am "<<no<<",HENGHENG."<<endl;
		}
};
class Dog:public Animal
{
public:
	Dog(string noo,int old2):Animal(noo,old2)
	{
	}
	virtual void speak()
		{
			cout<<"Hello,I am "<<no<<",WangWang."<<endl;
		}	
};
class Duck:public Animal
{
public:
	Duck(string noo,int old1):Animal(noo,old1)
	{
	}
	virtual void speak()
		{
			cout<<"Hello,I am "<<no<<",GAGA."<<endl;
		}	
};
int main()
{
	int t;
	string _name,_no;
	int _old;
	cin>>t;
    while(t--)
	{
		cin>>_name>>_no>>_old;
		Animal* a;
		if(_name=="Tiger")
		{
	
			Tiger tg(_no,_old);
			a=&tg;
			a->speak();
		}
		else if(_name=="Pig")
		{
	
			Pig pg(_no,_old);
			a=&pg;
			a->speak();
		}
		else if(_name=="Duck")
		{
	
			Duck dk(_no,_old);
			a=&dk;
			a->speak();
		}
		else if(_name=="Dog")
		{

			Dog dg(_no,_old);
			a=&dg;
			a->speak();
		}
		else
			cout<<"There is no "<<_no<<" in our Zoo."<<endl;
	}
	return 0;
}
