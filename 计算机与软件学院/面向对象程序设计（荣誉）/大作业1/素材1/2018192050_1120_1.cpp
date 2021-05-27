2018192050:Problem1120:ÕýÈ·
#include<bits/stdc++.h>
using namespace std;
class Animal{
    protected:
        string name;
    public:
        Animal(){
        }
        Animal(string m){
        	name=m;
        }
        ~Animal(){
        }
        virtual void speak()=0;
};
class Tiger:public Animal
{
    protected:
        string id;
        int year;
    public:
        Tiger(){
        }
        Tiger(string a,string b,int c){
            name=a;
            id=b;
            year=c;
        }
        ~Tiger(){
        }
        void speak(){
        	cout<<"Hello,I am "<<id<<",AOOO."<<endl;
		}  
};
class Dog:public Animal
{
    protected:
        string id;
        int year;
    public:
        Dog(){
        }
        Dog(string a,string b,int c){
            name=a;
            id=b;
            year=c;
        }
        ~Dog(){
        }
        void speak(){
        	cout<<"Hello,I am "<<id<<",WangWang."<<endl;
		}  
};
class Duck:public Animal
{
    protected:
        string id;
        int year;
    public:
        Duck(){
        }
        Duck(string a,string b,int c){
            name=a;
            id=b;
            year=c;
        }
        ~Duck(){
        }
        void speak(){
        	cout<<"Hello,I am "<<id<<",GAGA."<<endl;
		}  
};
class Pig:public Animal
{
    protected:
        string id;
        int year;
    public:
        Pig(){
        }
        Pig(string a,string b,int c){
            name=a;
            id=b;
            year=c;
        }
        ~Pig(){
        }
        void speak(){
        	cout<<"Hello,I am "<<id<<",HENGHENG."<<endl;
		}  
};
int main(){
	int t,n;
	string name,id;
	cin>>t;
	Animal *pv;
	while(t--)
	{
		cin>>name>>id>>n;;
		if(name=="Tiger")
		{
			Tiger a(name,id,n);
			pv=&a;
			pv->speak();
		}
		else if(name=="Duck")
		{
			Duck a(name,id,n);
			pv=&a;
			pv->speak();
		}
		else if(name=="Pig")
		{
			Pig a(name,id,n);
			pv=&a;
			pv->speak();
		}
		else if(name=="Dog")
		{
			Dog a(name,id,n);
			pv=&a;
			pv->speak();
		}
		else
			cout<<"There is no "<<name<<" in our Zoo."<<endl;
	}
}
