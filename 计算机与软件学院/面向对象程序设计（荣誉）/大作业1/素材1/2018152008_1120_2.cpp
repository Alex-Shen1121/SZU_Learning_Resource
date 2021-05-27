2018152008:Problem1120:ÔËÐÐ´íÎó
#include<iostream>
#include<string>
using namespace std;
class Animal
{
	protected:
		string kind;
		string name;
		int age;
	public:
		virtual void speak();	
		void display();
};
void Animal::speak()
{
	;
}
void Animal::display()
{
	cout<<"Hello,I am "<<name<<",";
	speak();
}
class tiger:public Animal
{
	public:
		tiger(string n,int a);
		void speak();
};
tiger::tiger(string n,int a)
{
	kind="tiger";
	name=n;
	age=a;
}
void tiger::speak()
{
	cout<<"AOOO."<<endl;
}
class dog:public Animal
{
	public:
		dog(string n,int a);
		void speak();
};
dog::dog(string n,int a)
{
	kind="dog";
	name=n;
	age=a;
}
void dog::speak()
{
	cout<<"WangWang."<<endl;
}
class duck:public Animal
{
	public:
		duck(string n,int a);
		void speak();	
};
duck::duck(string n,int a)
{
	kind="duck";
	name=n;
	age=a;
}
void duck::speak()
{
	cout<<"GAGA."<<endl;
}
class pig:public Animal
{
	public:
		pig(string n,int a);
		void speak();
};
pig::pig(string n,int a)
{
	kind="pig";
	name=n;
	age=a;
}
void pig::speak()
{
	cout<<"HENGHENG."<<endl;
}
int main()
{
	int t;
	cin>>t;	
	while(t--)
	{
		Animal *p;
		string kind;
		string n;
		int a;
		cin>>kind>>n>>a;
		if(kind=="Tiger")
		{
			p=new tiger(n,a);
			p->display();
		}
		else if(kind=="Pig")
		{
			p=new pig(n,a);
			p->display();
		}
		else if(kind=="Duck")
		{
			p=new duck(n,a);
			p->display();
		}
		else if(kind=="Dog")
		{
			p=new dog(n,a);
			p->display();
		}
		else
		{
			cout<<"There is no "<<kind<<" in our Zoo."<<endl;
		}
		delete p;
	}
	return 0;
}
