2018192014:Problem1120:���д���
#include<bits/stdc++.h>
using namespace std;
class Animal{
protected:
	string name;
	int age;
public:
	Animal(string n,int a):
		name(n),age(a){
		}
	virtual void speak()=0;
};
class Tiger:virtual public Animal{
protected:
public:
	Tiger(string n,int a):Animal(n,a){
	}
	virtual void speak()
	{
		cout<<"Hello,I am "<<name<<",AOOO."<<endl;
	}
};
class Pig:virtual public Animal{
protected:
public:
	Pig(string n,int a):Animal(n,a){
	}
	virtual void speak()
	{
		cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
	}
};
class Duck:virtual public Animal{
protected:
public:
	Duck(string n,int a):Animal(n,a){
	}
	virtual void speak()
	{
		cout<<"Hello,I am "<<name<<",GAGA."<<endl;
	}
};
class Dog:virtual public Animal{
protected:
public:
	Dog(string n,int a):Animal(n,a){
	}
	virtual void speak()
	{
		cout<<"Hello,I am "<<name<<",WangWang."<<endl;
	}
};
int main ()
{
	Animal *an;
	int t;
	cin>>t;
	while(t--)
	{
		string n;
		int a;
		string command;
		cin>>command;
		if(command=="Tiger")
		{
			cin>>n>>a;
			an=new Tiger(n,a);
			an->speak();
			delete an;
		}
		else if(command=="Pig")
		{
			cin>>n>>a;
			an=new Pig(n,a);
			an->speak();
			delete an;
		}
		else if(command=="Duck")
		{
			cin>>n>>a;
			an=new Duck(n,a);
			an->speak();
			delete an;
		}
		else if(command=="Dog")
		{
			cin>>n>>a;
			an=new Dog(n,a);
			an->speak();
			delete an;
		}
		else
		{
			cin>>n>>a;
			cout<<"There is no "<<command<<" in our Zoo."<<endl;
		}
		
	}
	return 0;
}
