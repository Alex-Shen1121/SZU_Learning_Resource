2018152086:Problem1120:ÕýÈ·
#include<iostream>
#include<string.h>

using namespace std;

class Animal{
	protected:
		string name;
		int age;
	public:
		Animal(){
		}
		Animal(string a,int b){
			name=a;
			age=b;
		}
		void virtual speak(){
			cout<<"hello world."<<endl;
		}
};
class Tiger:public Animal{
	public:
		Tiger(string a,int b){
			name=a;
			age=b;
		}
		void speak(){
			cout<<"Hello,I am "<<name<<",AOOO."<<endl;
		}
};
class Dog:public Animal{
	public:
		Dog(string a,int b){
			name=a;
			age=b;
		}
		void speak(){
			cout<<"Hello,I am "<<name<<",WangWang."<<endl;
		}
};
class Duck:public Animal{
	public:
		Duck(string a,int b){
			name=a;
			age=b;
		}
		void speak(){
			cout<<"Hello,I am "<<name<<",GAGA."<<endl;
		}
};
class Pig:public Animal{
	public:
		Pig(string a,int b){
			name=a;
			age=b;
		}
		void speak(){
			cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
		}
};

int main(){
	int t;
	char type[10];
	string name;
	int age;
	Animal *P;
	cin>>t;
	while(t--){
		cin>>type>>name>>age;
		if(strcmp(type,"Tiger")==0){
			Tiger A(name,age);
			P=&A;
			P->speak();
		}
		else if(strcmp(type,"Dog")==0){
			Dog A(name,age);
			P=&A;
			P->speak();
		}
		else if(strcmp(type,"Duck")==0){
			Duck A(name,age);
			P=&A;
			P->speak();
		}
		else if(strcmp(type,"Pig")==0){
			Pig A(name,age);
			P=&A;
			P->speak();
		}
		else{
			cout<<"There is no "<<type<<" in our Zoo."<<endl;
		}
	}
	return 0;
}
