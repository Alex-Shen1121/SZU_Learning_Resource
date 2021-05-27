2018192048:Problem1234:正确
#include<iostream>
using namespace std;
 
class Group{
public:
    virtual int add(int x, int y)=0;//输出加法的运算结果
    virtual int sub(int x, int y)=0;//输出减法的运算结果
};
 
class GroupA:public Group{
public:
    int add(int x,int y){
        return x+y;
    }
    int sub(int x,int y){
        return x-y;
    }
};
class GroupB:public Group{
public:
    int add(int x,int y){
        return x+y;
    }
    int sub(int x,int y){
        int count1=0,count2=0,a[10]={0},b[10]={0},c[10]={0};//count算位数,数组a、b存每个位置上的数字 
		for(int i=0;x!=0;i++){
			a[i]=x%10;
			x/=10;
			count1++;
		}
		for(int i=0;y!=0;i++){
			b[i]=y%10;
			y/=10;
			count2++;
		}
		if(count1<count2)
			count1=count2;
		for(int i=0;i<count1;i++){
			if(a[i]>=b[i])
				c[i]=a[i]-b[i];
			else
				c[i]=a[i]+10-b[i];
		}
		int sum=0;
		for(int i=count1-1;i>=0;i--){
			sum*=10;
			sum+=c[i];
		}
		return sum;		
    }
};
 
class GroupC:public Group{
public:
    int add(int x,int y){
        int count1=0,count2=0,a[10]={0},b[10]={0},c[10]={0};//count算位数,数组a、b存每个位置上的数字 
		for(int i=0;x!=0;i++){
			a[i]=x%10;
			x/=10;
			count1++;
		}
		for(int i=0;y!=0;i++){
			b[i]=y%10;
			y/=10;
			count2++;
		}
		if(count1<count2)
			count1=count2;
		for(int i=0;i<count1;i++){
			if(a[i]+b[i]>=10)
				c[i]=a[i]+b[i]-10;
			else
				c[i]=a[i]+b[i];
		}
		int sum=0;
		for(int i=count1-1;i>=0;i--){
			sum*=10;
			sum+=c[i];
		}
		return sum;
    }
    int sub(int x,int y){
        int count1=0,count2=0,a[10]={0},b[10]={0},c[10]={0};//count算位数,数组a、b存每个位置上的数字 
		for(int i=0;x!=0;i++){
			a[i]=x%10;
			x/=10;
			count1++;
		}
		for(int i=0;y!=0;i++){
			b[i]=y%10;
			y/=10;
			count2++;
		}
		if(count1<count2)
			count1=count2;
		for(int i=0;i<count1;i++){
			if(a[i]>=b[i])
				c[i]=a[i]-b[i];
			else
				c[i]=a[i]+10-b[i];
		}
		int sum=0;
		for(int i=count1-1;i>=0;i--){
			sum*=10;
			sum+=c[i];
		}
		return sum;
    }
};

int main(){
	int t;
	cin>>t;
	Group *p;
	while(t--){
		int type;
		cin>>type;
		int x,y;
		char ch;
		cin>>x>>ch>>y;
		if(type==1){
			p=new GroupA;
			if(ch=='+')
				cout<<p->add(x,y)<<endl;
			else if(ch=='-')
				cout<<p->sub(x,y)<<endl;
		}
		else if(type==2){
			p=new GroupB;
			if(ch=='+')
				cout<<p->add(x,y)<<endl;
			else if(ch=='-')
				cout<<p->sub(x,y)<<endl;
		}
		else if(type==3){
			p=new GroupC;
			if(ch=='+')
				cout<<p->add(x,y)<<endl;
			else if(ch=='-')
				cout<<p->sub(x,y)<<endl;
		}
	}
	return 0;
}
