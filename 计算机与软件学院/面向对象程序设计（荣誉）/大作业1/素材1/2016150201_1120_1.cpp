2016150201:Problem1120:ÕýÈ·
#include<iostream>
using namespace std;
class animal{
protected:
   string name;
   int age;
   int weight;
public:
   animal(string na,int a):name(na),age(a){
   }
   ~animal(){
   }
   virtual void speak()=0;
};
class tiger:public animal{
public:
   tiger(string na,int a):animal(na,a){
   }
   ~tiger(){
   }
   void virtual speak(){
      cout<<"Hello,I am "<<name<<",AOOO."<<endl;
   }
};
class dog:public animal{
public:
   dog(string na,int a):animal(na,a){
   }
   ~dog(){
   }
   virtual void speak(){
      cout<<"Hello,I am "<<name<<",WangWang."<<endl;
   }
};
class duck:public animal{
public:
   duck(string na,int a):animal(na,a){
   }
   ~duck(){
   }
   virtual void speak(){
      cout<<"Hello,I am "<<name<<",GAGA."<<endl;
   }
};
class pig:public animal{
public:
   pig(string na,int a):animal(na,a ){
   }
   ~pig(){
   }
   virtual void speak(){
      cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
   }
};
int main(){
   int t,a;
   animal *an;
   string ty,na;
   cin>>t;
   while(t--){
      cin>>ty>>na>>a;
      if(ty=="Tiger"){
         tiger t(na,a);
         an=&t;
         an->speak();
      }
      else if(ty=="Pig"){
         pig p(na,a);
         an=&p;
         an->speak();
      }
      else if(ty=="Duck"){
         duck d(na,a);
         an=&d;
         an->speak();
      }
      else if(ty=="Dog"){
         dog dg(na,a);
         an=&dg;
         an->speak();
      }
      else
         cout<<"There is no "<<ty<<" in our Zoo."<<endl;
   }
}
