2018192048:Problem1120:ÕýÈ·
#include<iostream>
#include<cstring>
using namespace std;

class Animal{
protected:
	string name;
public:
	Animal(){}
	Animal(string n):name(n){}
	virtual void speak()=0;
	~Animal(){}
};

class Tiger:public Animal{
protected:
	int age;
public:
	Tiger(){}
	Tiger(string n,int a):Animal(n),age(a){}
	void speak(){
		cout<<"Hello,I am "<<Animal::name<<",AOOO."<<endl;
	}
	~Tiger(){}
};

class Pig:public Animal{
protected:
	int age;
public:
	Pig(){}
	Pig(string n,int a):Animal(n),age(a){}
	void speak(){
		cout<<"Hello,I am "<<Animal::name<<",HENGHENG."<<endl;
	}
	~Pig(){}
};

class Dog:public Animal{
protected:
	int age;
public:
	Dog(){}
	Dog(string n,int a):Animal(n),age(a){}
	void speak(){
		cout<<"Hello,I am "<<Animal::name<<",WangWang."<<endl;
	}
	~Dog(){}
};

class Duck:public Animal{
protected:
	int age;
public:
	Duck(){}
	Duck(string n,int a):Animal(n),age(a){}
	void speak(){
		cout<<"Hello,I am "<<Animal::name<<",GAGA."<<endl;
	}
	~Duck(){}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		char type[10];
		cin>>type;
		string name;
		int age;
		cin>>name>>age;
		Animal *pv;
		if(strcmp(type,"Tiger")==0){
			Tiger a(name,age);
			pv=&a;
			pv->speak();
		}
		else if(strcmp(type,"Pig")==0){
			Pig a(name,age);
			pv=&a;
			pv->speak();
		}
		else if(strcmp(type,"Dog")==0){
			Dog a(name,age);
			pv=&a;
			pv->speak();
		}
		else if(strcmp(type,"Duck")==0){
			Duck a(name,age);
			pv=&a;
			pv->speak();
		}
		else
			cout<<"There is no "<<type<<" in our Zoo."<<endl;
		
			
	}
	return 0;
}
