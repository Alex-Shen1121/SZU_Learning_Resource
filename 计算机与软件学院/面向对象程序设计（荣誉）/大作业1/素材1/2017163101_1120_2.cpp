2017163101:Problem1120:‘À––¥ÌŒÛ
#include<iostream>
#include<cstdio>
using namespace std;
class Animal{
	protected:
		string type;
		string name;
		int age;
	public:
		virtual void speak()=0;
		Animal(string t,string n,int a):type(t),name(n),age(a){
			
		}
};
class Tiger:public Animal{
	public:
		void speak(){
			cout<<"Hello,I am "<<name<<","<<"AOOO"<<endl;
		}
		Tiger(string t,string n,int a):Animal(t,n,a){
			
		}
};
class Dog:public Animal{
	public:
		void speak(){
			cout<<"Hello,I am "<<name<<","<<"WangWang"<<endl;
		}
		Dog(string t,string n,int a):Animal(t,n,a){
			
		}
};
class Pig:public Animal{
public:
		void speak(){
			cout<<"Hello,I am "<<name<<","<<"HENGHENG"<<endl;
		}
		Pig(string t,string n,int a):Animal(t,n,a){
			
		}
};
class Duck:public Animal{
	public:
		void speak(){
			cout<<"Hello,I am "<<name<<","<<"GAGA"<<endl;
		}
		Duck(string t,string n,int a):Animal(t,n,a){
		}
};
int main(){
	int t;
	cin>>t;
	while(t--){
		string type,name;
		int age;
		cin>>type>>name>>age;
		Animal *s;
		if(type=="Tiger"){
			s=new Tiger(type,name,age);
		}
		else if(type=="Pig"){
			s=new Pig(type,name,age);
		}
		else if(type=="Dog"){
			s=new Dog(type,name,age);
		}
		else if(type=="Duck"){
			s=new Duck(type,name,age);
		}
		else{
			cout<<"There is no "<<type<<" in our Zoo"<<endl;
		}
		s->speak();
		//delete s;
	}
	//delete s;
	return 0;
}
