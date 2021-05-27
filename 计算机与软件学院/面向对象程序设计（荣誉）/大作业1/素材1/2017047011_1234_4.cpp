2017047011:Problem1234:´ð°¸´íÎó
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip> 
using namespace std;

class Group
{

public:
	virtual int add(int x, int y)=0;
	virtual int sub(int x, int y)=0;
};
//------------------------
class groupA:public Group{
	
public:
	groupA(){}
	int add(int x, int y){
		return x+y;
	}
	int sub(int x, int y){
		return x-y;
	}	
};
//------------------------
class groupB:public Group{
	
public:
	groupB(){}
	int add(int x, int y){
		return x+y;
	}
	int sub(int x, int y){
		int leng1,leng2,res,i,j;
		int a[100]={0},b[100]={0},c[100]={0};
		leng1=leng2=res=0;
		
		while(pow(10,leng1)<=x)
			leng1++;
		
		for(i=0;i<leng1;i++){
			a[i]=x%10;
			x/=10;
		}
		
		while(pow(10,leng2)<=y)
			leng2++;
		for(i=0;i<leng2;i++){
			b[i]=y%10;
			y/=10;
		}
		
		int length=leng1>leng2?leng1:leng2;
		for(i=0;i<length;i++){
			if(a[i]>=b[i])
				c[i]=a[i]-b[i];
			else 
				c[i]=a[i]+10-b[i];
		}
		for(i=0;i<length;i++)
			res+=c[i]*pow(10,i);
		return res;
	}
};
//------------------------
class groupC:public Group{
	
public:
	groupC(){}
	int add(int x, int y){
		int leng1,leng2,res,i,j;
		int a[100]={0},b[100]={0},c[100]={0};
		leng1=leng2=res=0;
		
		while(pow(10,leng1)<=x)
			leng1++;
		
		for(i=0;i<leng1;i++){
			a[i]=x%10;
			x/=10;
		}
		
		while(pow(10,leng2)<=y)
			leng2++;
		for(i=0;i<leng2;i++){
			b[i]=y%10;
			y/=10;
		}
		
		int length=leng1>leng2?leng1:leng2;
		
		for(i=0;i<length;i++){
			if(a[i]+b[i]>=10)
				c[i]=(a[i]+b[i])%10;
			else 
				c[i]=a[i]+b[i];
		}
		
		for(i=0;i<leng1;i++)
			cout<<a[i]<<" ";
		cout<<"!"<<endl;
		
		
		for(i=0;i<length;i++)
			res+=c[i]*pow(10,i);
		
		return res;
	}
	
	int sub(int x, int y){
		int leng1,leng2,res,i,j;
		int a[100]={0},b[100]={0},c[100]={0};
		leng1=leng2=res=0;
		
		while(pow(10,leng1)<=x)
			leng1++;
		
		for(i=0;i<leng1;i++){
			a[i]=x%10;
			x/=10;
		}
		
		while(pow(10,leng2)<=y)
			leng2++;
		for(i=0;i<leng2;i++){
			b[i]=y%10;
			y/=10;
		}
		
		int length=leng1>leng2?leng1:leng2;
		for(i=0;i<length;i++){
			if(a[i]>=b[i])
				c[i]=a[i]-b[i];
			else 
				c[i]=a[i]+10-b[i];
		}
		for(i=0;i<length;i++)
			res+=c[i]*pow(10,i);
		return res;
	}
};
//------------------------
int main()
{
	int t,i,j,k;
	int num1,num2,kind;
	string ask;
	char fuhao;
	Group *p;
	
	cin>>t;
	while(t--)
	{
		cin>>kind>>ask;
		for(i=0;i<ask.length();i++)
			if(ask[i]=='+'||ask[i]=='-'){
				j=i;
				break;
			}
			
		fuhao=ask[j];
		num1=num2=0;
		k=j;
		
		for(i=0;i<j;i++){
			num1+=(ask[i]-'0')*pow(10,k-1);
			k--;
		}
		
		k=ask.length()-j-1;
		for(i=j+1;i<ask.length();i++){
			num2+=(ask[i]-'0')*pow(10,k-1);
			k--;
		}		
		
		if(kind==1){
			groupA g1;
			p=&g1;
			if(fuhao=='+')
				cout<<p->add(num1,num2);
			if(fuhao=='-')
				cout<<p->sub(num1,num2);
		}
		
		else if(kind==2){
			groupB g2;
			p=&g2;
			if(fuhao=='+')
				cout<<p->add(num1,num2);
			if(fuhao=='-')
				cout<<p->sub(num1,num2);
		}
		
		else if(kind==3){
			groupC g3;
			p=&g3;
			if(fuhao=='+')
				cout<<p->add(num1,num2);
			if(fuhao=='-')
				cout<<p->sub(num1,num2);
		}
		cout<<endl;	
	}
}
