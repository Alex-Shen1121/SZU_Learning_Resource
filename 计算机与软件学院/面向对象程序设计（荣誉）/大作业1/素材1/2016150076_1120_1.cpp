2016150076:Problem1120:´ð°¸´íÎó
#include <iostream>
using namespace std;

class Animal
{
protected:
    string name;
    int age;
public:
    Animal(string n,int a):name(n),age(a){}
    virtual void speak()
    {

    }
    ~Animal(){} 
};
class Tiger:public Animal
{
public:
    Tiger(string n,int a):Animal(n,a){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",AOOO."<<endl;
    }
    ~Tiger(){}
};
class Dog:public Animal
{
public:
    Dog(string n,int a):Animal(n,a){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",WangWang."<<endl;
    }
    ~Dog(){}
};

class Duck:public Animal
{
public:
    Duck(string n,int a):Animal(n,a){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",GAGA."<<endl;
    }
    ~Duck(){}
};

class Pig:public Animal
{
public:
    Pig(string n,int a):Animal(n,a){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",HengHeng."<<endl;
    }
    ~Pig(){}
};


int main()
{
	int n,age;
	string name;
	string type;
    Animal *p_animal;
    cin>>n;
   while(n--)
   {
   		cin>>type;
   		int flag=0;
	   		if(type=="Tiger")
	   			{	
		   			cin>>name>>age;
		   			Tiger a(name,age);
		   			p_animal=&a;
		   			p_animal->speak();
		   			flag=1;
				}
				
			if(type=="Dog")
	   			{	
		   			cin>>name>>age;
		   			Dog b(name,age);
		   			p_animal=&b;
		   			p_animal->speak();
		   			flag=1;
				}
				
			if(type=="Duck")
	   			{	
		   			cin>>name>>age;
		   			Duck c(name,age);
		   			p_animal=&c;
		   			p_animal->speak();
		   			flag=1;
				}		
	   	
	 		if(type=="Pig")
	   			{	
		   			cin>>name>>age;
		   			Pig d(name,age);
		   			p_animal=&d;
		   			p_animal->speak();
		   			flag=1;
				} 
				
			if(flag==0)
			{
				cout<<"There is no "<<type<<" in our Zoo."<<endl;
			 }	 	
   }

  
    
    return 0;
}
