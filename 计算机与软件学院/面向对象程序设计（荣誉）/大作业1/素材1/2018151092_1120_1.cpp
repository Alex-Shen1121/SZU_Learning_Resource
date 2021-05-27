2018151092:Problem1120:ÕýÈ·
#include<iostream>
#include<cstring>
using namespace std;

class Animal
{
	protected:
		string name;
		int age;
		int weight;
	public:
		Animal()
		{
		}
		
		Animal(string n,int a)
		{
			name=n;
			age=a;
		}
		
		virtual void Speak()=0;
		
		~Animal()
		{
		}
};

class Tiger:public Animal
{
	public:
		Tiger()
		{
		}
		
		Tiger(string n,int a):Animal(n,a)
		{
		}
		
		virtual void Speak()
		{
			cout<<"Hello,I am "<<name<<",AOOO."<<endl;
		}
		
		~Tiger()
		{
		}
};

class Dog:public Animal
{
	public:
		Dog()
		{
		}
		
		Dog(string n,int a):Animal(n,a)
		{
		}
		
		virtual void Speak()
		{
			cout<<"Hello,I am "<<name<<",WangWang."<<endl;
		}
		
		~Dog()
		{
		}
};

class Pig:public Animal
{
	public:
		Pig()
		{
		}
		
		Pig(string n,int a):Animal(n,a)
		{
		}
		
		virtual void Speak()
		{
			cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
		}
		
		~Pig()
		{
		}
};

class Duck:public Animal
{
	public:
		Duck()
		{
		}
		
		Duck(string n,int a):Animal(n,a)
		{
		}
		
		virtual void Speak()
		{
			cout<<"Hello,I am "<<name<<",GAGA."<<endl;
		}
		
		~Duck()
		{
		}
};

int main()
{
	string type;
	string name;
	int age;
	int t;
	int i;
	
	cin>>t;
	
	Animal *Ace[t];
	
	for(i=0;i<t;i++)
	{
		int flag=0;
		cin>>type>>name>>age;
		
		if(type=="Dog")
		{
			Ace[i]=new Dog(name,age);
			Ace[i]->Speak();
			flag=1;
		}
		
		if(type=="Duck")
		{
			Ace[i]=new Duck(name,age);
			Ace[i]->Speak();
			flag=1;
		}
		
		if(type=="Pig")
		{
			Ace[i]=new Pig(name,age);
			Ace[i]->Speak();
			flag=1;
		}
		
		if(type=="Tiger")
		{
			Ace[i]=new Tiger(name,age);
			Ace[i]->Speak();
			flag=1;
		}
		
		if(flag==0)
		{
			cout<<"There is no "<<type<<" in our Zoo."<<endl;
		}
	}
	return 0;
}
