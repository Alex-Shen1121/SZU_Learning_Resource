2017047011:Problem1120:ÕýÈ·
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip> 
using namespace std;

class Animal
{ 
protected:
	string kind;
	string name;
	int age;
public:
	Animal(){}
	virtual void speak()=0;
};
//------------------------
class tiger:public Animal
{
public:
	tiger(string n,int a);
	void speak();	
};

tiger::tiger(string n,int a){
	name=n;age=a;
}

void tiger::speak(){
	cout<<"Hello,I am "<<name<<",AOOO."<<endl; 
}
//------------------------
class dog:public Animal
{
public:
	dog(string n,int a);
	void speak();	
};

dog::dog(string n,int a){
	name=n;age=a;
}

void dog::speak(){
	cout<<"Hello,I am "<<name<<",WangWang."<<endl; 
}
//------------------------
class duck:public Animal
{
public:
	duck(string n,int a);
	void speak();	
};

duck::duck(string n,int a){
	name=n;age=a;
}

void duck::speak(){
	cout<<"Hello,I am "<<name<<",GAGA."<<endl; 
}
//------------------------
class pig:public Animal
{
public:
	pig(string n,int a);
	void speak();	
};

pig::pig(string n,int a){
	name=n;age=a;
}

void pig::speak(){
	cout<<"Hello,I am "<<name<<",HENGHENG."<<endl; 
}
//------------------------

int main()
{
	int t;
	string kind,name;
	int age;
	Animal *p;
	
	cin>>t;
	while(t--)
	{
		cin>>kind>>name>>age;
		
		if(kind=="Tiger"){
			tiger tiger1(name,age);
			p=&tiger1;
			p->speak();
		}
		
		else if(kind=="Duck"){
			duck duck1(name,age);
			p=&duck1;
			p->speak();
		}
		
		else if(kind=="Dog"){
			dog dog1(name,age);
			p=&dog1;
			p->speak();
		}
		
		else if(kind=="Pig"){
			pig pig1(name,age);
			p=&pig1;
			p->speak();
		}
		
		else 
			cout<<"There is no "<<kind<<" in our Zoo."<<endl;
	}
	
}
