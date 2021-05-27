2017152043:Problem1234:答案错误
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
		a = x;
		b = y;
		int temp;
		int sum = 0;
		while(a / 10){
			sum++;
			a /= 10;
		}
		for(int i = 1;i <= sum;i++){
			if(x % 10 > y % 10)
				temp += (10 + x % 10 - y % 10) * i;
			else
				temp += (x % 10 - y % 10) * i;
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
		int a;
		a = x;
		int temp;
		int num;
		int sum = 0;
		while(a / 10){
			sum++;
			a /= 10;
		}
		for(int i = 1;i <= sum;i++){
			num = (x % 10 + y % 10) % 10;
			for(int j = 1;j < i;j++)
				num = ((x % 10 + y % 10) % 10) * 10;
			temp += num;
			x /= 10;
			y /= 10;
		}
		return temp;
	}
	int sub(int x,int y)
	{
		int a;
		a = x;
		int temp;
		int num;
		int sum = 0;
		while(a / 10){
			sum++;
			a /= 10;
		}
		for(int i = 1;i <= sum;i++){
			if(x % 10 > y % 10){
				num = (10 + x % 10 - y % 10);
				for(int j = 1;j < i;j++){
					num = (10 + x % 10 - y % 10) * 10;
				}
			}
			else{
				num = (x % 10 - y % 10);
				for(int j = 1;j < i;j++){
					num = (x % 10 - y % 10) * 10;
				}
			}
			temp += num;
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

