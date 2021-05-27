2017152043:Problem1234:正确
#include<iostream>
using namespace std;

class Group
{
public:
	virtual int add(int x, int y)=0;//输出加法的运算结果
	virtual int sub(int x, int y)=0;//输出减法的运算结果
};

class GroupA:public Group{
public:
	int add(int x, int y)
	{
		return (x + y);
	}
	int sub(int x,int y)
	{
		return (x - y);
	}
};

class GroupB:public Group{
public:
	int add(int x, int y)
	{
		return (x + y);
	}
	int sub(int x,int y)
	{
		int a,b;
		int temp = 0;
		int sum = 0;
		int i = 0;
		int j;
		while(x || y){
			a = x % 10;
			b = y % 10;
			if(a < b){
				sum = a + 10 - b;
			}
			else{
				sum = a - b;
			}
			j = i;
			while(j--){
				sum *= 10;
			}
			temp += sum;
			i++;
			x /= 10;
			y /= 10;
		}
		return temp;
	}
};

class GroupC:public Group{
public:
	int add(int x, int y)
	{
		int a,b;
		int temp = 0;
		int sum = 0;
		int i = 0;
		int j;
		while(x || y){
			a = x % 10;
			b = y % 10;
			if(a + b >= 10){
				sum = a +b - 10;
			}
			else{
				sum = a + b;
			}
			j = i;
			while(j--){
				sum *= 10;
			}
			temp += sum;
			i++;
			x /= 10;
			y /= 10;
		}
		return temp;
	}
	int sub(int x,int y)
	{
		int a,b;
		int temp = 0;
		int sum = 0;
		int i = 0;
		int j;
		while(x || y){
			a = x % 10;
			b = y % 10;
			if(a < b){
				sum = a + 10 - b;
			}
			else{
				sum = a - b;
			}
			j = i;
			while(j--){
				sum *= 10;
			}
			temp += sum;
			i++;
			x /= 10;
			y /= 10;
		}
		return temp;
	}
};



int main(){
	int t;
	int type;
	int a,b;
	char cal;
	Group *pg;
	GroupA GA;
	GroupB GB;
	GroupC GC;
	
	cin >> t;
	while(t--){
		cin >> type >> a >> cal >> b;
		if(type == 1){
			pg = &GA;
			if(cal == '+')
				cout << pg->add(a,b) << endl;
			else
				cout << pg->sub(a,b) << endl;
		}
		else if(type == 2){
			pg = &GB;
			if(cal == '+')
				cout << pg->add(a,b) << endl;
			else
				cout << pg->sub(a,b) << endl;
		}
		else if(type == 3){
			pg = &GC;
			if(cal == '+')
				cout << pg->add(a,b) << endl;
			else
				cout << pg->sub(a,b) << endl;
		}
	}
	return 0;
}

