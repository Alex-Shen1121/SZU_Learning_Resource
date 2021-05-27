2016150202:Problem1232:ÕýÈ·
#include<iostream>
#include<cstring>
using namespace std;
class Vehicle{
	protected:
		string no;
		public: 
		virtual void display()=0;
		Vehicle (string num):no(num){}
		~Vehicle(){}
		
		 
}; 

class Car: public Vehicle
{
	protected:
		int w,c;
		public:
			Car(string num,int whight,int customer):Vehicle(num),w(whight),c(customer){}
			~Car(){}
			virtual void display()
			{
				cout<<no<<" "<<w*8+c*2<<endl;
			} 
			
};

class Truck :public Vehicle
{
	protected:
		int w;
		public:
			Truck(string num,int whight):Vehicle(num),w(whight){}
			~Truck(){}
			void display(){

                int f;
				f=w*5;
				cout<<no<<" "<<f<<endl;
			}
	
};

class Bus : public Vehicle 
{
	
	protected:
		int c;
		public:
			
			Bus(string num,int customer):Vehicle(num),c(customer){}
			~Bus(){}
			void display()
			{
				int f;
				f=c*3;
				cout<<no<<" "<<f<<endl;
			}
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int key;
		string no;
		int c,w;
		cin>>key;
	
		if(key==1)
		{
			
		 cin>>no>>w>>c;
		 Car cc(no,w,c);
		 Vehicle *pv=&cc;
		 cc.display();
		}
		if(key==2)
		{
		cin>>no>>w;
		Truck tt(no,w);
		Vehicle *pv=&tt;
	
		tt.display();
		}
		if(key==3)
		{
			cin>>no>>c;
			Bus bb(no,c);
			Vehicle *pv=&bb;
		
			bb.display();	
		}
   }
	
	
	return 0;
}



