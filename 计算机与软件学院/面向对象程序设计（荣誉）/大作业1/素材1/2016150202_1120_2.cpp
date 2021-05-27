2016150202:Problem1120:ÕýÈ·
#include<iostream>
#include<cstring>
using namespace std;
class Animal{
	protected:
		string name;
		int age;
		public: 
		virtual void display()=0;
	    Animal (string n,int a):name(n),age(a){}
		~Animal(){}
	
}; 

class Tiger: public Animal
{	
		public:
			Tiger(string n,int a):Animal(n,a){}
			~Tiger(){}
		   void display()
			{
			cout<<"Hello,I am "<<name<<",AOOO."<<endl;
			} 
			
};

class Dog :public Animal
{
	protected:
		
		public:
			Dog(string n,int a):Animal(n,a){}
			~Dog(){}
			void display()
			{
				cout<<"Hello,I am "<<name<<",WangWang."<<endl;
               
			}	
};
class Duck : public Animal 
{
	protected:

		public:
			
		Duck(string n,int a):Animal(n,a){}
			~Duck(){}
			void display()
			{
				cout<<"Hello,I am "<<name<<",GAGA."<<endl;
			}
};

class Pig : public Animal 
{
	protected:

		public:
			
		Pig(string n,int a):Animal(n,a){}
			~Pig(){}
			void display()
			{
				cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
			}
};


int main()
{
	int t;
	cin>>t;
	Animal *pv;
	
	while(t--)
	{
		string key;
		string name;
		int age;
		
		cin>>key;
	
		if(key=="Tiger")
		{
			
		 cin>>name>>age;
		 Tiger tt(name,age);
		 pv=&tt;
		 pv->display();
		}
		else if(key=="Pig")
		{
		cin>>name>>age;
		Pig pp(name,age);
		pv=&pp;
		pv->display();
		}
		else if(key=="Dog")
		{
			cin>>name>>age;
			Dog dd(name,age);
			pv=&dd;
			pv->display();	
		}
		
		else if(key=="Duck")
		{
			cin>>name>>age;
			Duck k(name,age);
			pv=&k;
			pv->display();	
		}
		else
		{
			
			cin>>name>>age;
			cout<<"There is no "<<key<<" in our Zoo."<<endl; 
		}
		
   }
	return 0;
}



