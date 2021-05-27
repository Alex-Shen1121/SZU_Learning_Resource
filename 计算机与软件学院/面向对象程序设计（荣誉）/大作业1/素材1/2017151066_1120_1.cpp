2017151066:Problem1120:´ð°¸´íÎó
#include<iostream>
using namespace std;
class Animal
{
protected:
	string name;
public:
	Animal(string n):name(n){}
    virtual void Speak()=0;
};

class Tiger:public Animal
{
public:
	    Tiger(string name):Animal(name){}
        virtual void Speak()
    	{
        	cout<<"Hello,I am "<<name<<",AOOO."<<endl;
		}
};
class Dog:public Animal
{
public:
	    Dog(string name):Animal(name){}
        virtual void Speak()
    	{
        	cout<<"Hello,I am "<<name<<",WangWang."<<endl;
		}
};
class Duck:public Animal
{
public:
	    Duck(string name):Animal(name){}
        virtual void Speak()
    	{
        	cout<<"Hello,I am "<<name<<",GAGA."<<endl;
		}
};
class Pig:public Animal
{
public:
	    Pig(string name):Animal(name){}
        virtual void Speak()
    	{
        	cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
		}
};
int main()
{
    Animal *p_animal;
	int t;
	cin>>t;
	while(t--)
	{
		string ming,name;
		int ego;
		cin>>ming>>name>>ego;
		if(ming=="Tiger")
		{
        	p_animal=new Tiger(name);
        	p_animal->Speak();
		}
		else if(ming=="Pig")
		{
        	p_animal=new Pig(name);
        	p_animal->Speak();
		}
		else if(ming=="Duck")
		{
			p_animal=new Duck(name);
        	p_animal->Speak();
		}
		else if(ming=="Dog")
		{
			p_animal=new Dog(name);
        	p_animal->Speak();
		}
		else
		{
			cout<<"There is no Rabbit in our Zoo."<<endl;
		}

	}
	return 0;
}
