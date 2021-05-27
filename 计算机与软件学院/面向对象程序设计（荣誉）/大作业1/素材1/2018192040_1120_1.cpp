2018192040:Problem1120:ÕýÈ·
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class Animal{ 
protected:
	string name;
	int age;
public:
	Animal(){
	};
	Animal(string n,int a):name(n),age(a){
	};
	virtual void speak()=0;

};

class Tiger:public Animal{
public:
	Tiger(string n,int a):Animal(n,a){
	};
	Tiger(){
	};
	void speak(){
		cout<<"Hello,I am "<<name<<",AOOO."<<endl;
	}
};

class Pig:public Animal{
public:
	Pig(string n,int a):Animal(n,a){
	};
	Pig(){
	};
	void speak(){
		cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
	}
};


class Duck:public Animal{
public:
	Duck(string n,int a):Animal(n,a){
	};
	Duck(){
	};
	void speak(){
		cout<<"Hello,I am "<<name<<",GAGA."<<endl;
	}
};

class Dog:public Animal{
public:
	Dog(string n,int a):Animal(n,a){
	};
	Dog(){
	};
	void speak(){
		cout<<"Hello,I am "<<name<<",WangWang."<<endl;
	}
};


int main(){
	int n;
	cin>>n;
	Animal *p0;
	while(n--){
		string type,name;
		int age;
		cin>>type>>name>>age;
		if(type == "Tiger"){
			Tiger tiger(name,age);
			Tiger *p1 = &tiger;
			p0 = p1;
			p0->speak();
		}
		else if(type == "Dog"){
			Dog dog(name,age);
			Dog *p1 = &dog;
			p0 = p1;
			p0->speak();
		}
		else if(type == "Duck"){
			Duck duck(name,age);
			Duck *p1 = &duck;
			p0 = p1;
			p0->speak();
		}
		else if(type == "Pig"){
			Pig pig(name,age);
			Pig *p1 = &pig;
			p0 = p1;
			p0->speak();
		}
		else{
			cout<<"There is no "<<type<<" in our Zoo."<<endl;
		}
	}
}
