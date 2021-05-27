2018192040:Problem1234:答案错误
#include<iostream>
#include<string>
#include<cstdio>
#include<iomanip>
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
	int sub(int x,int y){
		string X = to_string(x);
		string Y = to_string(y);
		string result;
		int l = max(X.size(),Y.size());
		while(X.size() < l)
			X = "0" + X;
		while(Y.size() < l)
			Y = "0" + Y;
		for(int i=0;i<l;i++){
			result[i] = '0';
		}
		for(int i=0;i<l;i++){
			int temp = X[i]-Y[i];
			if(temp < 0)
				result[i] = 10 + temp + '0';
			else
			    result[i] = temp + '0';
		}
		char *ch = new char[l];
		for(int i=0;i<l;i++)
			ch[i] = result[i];
		int res;
		sscanf(ch,"%d",&res);
		return res;
	}
	int add(int x,int y){
		return x+y;
	};
};

class GroupC:public Group{
public:
	int sub(int x,int y){
		string X = to_string(x);
		string Y = to_string(y);
		string result;
		int l = max(X.size(),Y.size());
		while(X.size() < l)
			X = "0" + X;
		while(Y.size() < l)
			Y = "0" + Y;
		for(int i=0;i<l;i++){
			result[i] = '0';
		}
		for(int i=0;i<l;i++){
			int temp = X[i]-Y[i];
			if(temp < 0)
				result[i] = 10 + temp + '0';
			else
			    result[i] = temp + '0';
		}
		char *ch = new char[l];
		for(int i=0;i<l;i++)
			ch[i] = result[i];
		int res;
		sscanf(ch,"%d",&res);
		return res;
	};
	int add(int x,int y){
		string X = to_string(x);
		string Y = to_string(y);
		string result;
		int l = max(X.size(),Y.size());
		while(X.size() < l)
			X = "0" + X;
		while(Y.size() < l)
			Y = "0" + Y;
		for(int i=0;i<l;i++){
			result[i] = '0';
		}
		for(int i=0;i<l;i++){
			result[i] = abs((X[i]-'0'+Y[i]-'0')%10)+'0';
		}
		char *ch = new char[l];
		for(int i=0;i<l;i++)
			ch[i] = result[i];
		int res;
		sscanf(ch,"%d",&res);
		return res;
	}
};
int main(){
    int n;
	cin>>n;
	Group *p;
	while(n--){
		int type;
		cin>>type;
		if(type == 1){
			char op;
			int x,y;
			cin>>x>>op>>y;
			GroupA ga;
			p = &ga;
			if(op == '+')
				cout<<p->add(x,y)<<endl;
			if(op == '-')
				cout<<p->sub(x,y)<<endl;
		}
		if(type == 2){
			char op;
			int x,y;
			cin>>x>>op>>y;
			GroupB gb;
			p = &gb;
			cout<<p->sub(x,y)<<endl;
		}
		if(type == 3){
			char op;
			int x,y;
			cin>>x>>op>>y;
			GroupC gc;
			p = &gc;
			cout<<p->add(x,y)<<endl;
		}
	} 
}
