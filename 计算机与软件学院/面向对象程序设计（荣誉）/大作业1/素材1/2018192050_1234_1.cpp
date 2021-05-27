2018192050:Problem1234:答案错误
#include<bits/stdc++.h>
using namespace std;
class Group
{

public:

virtual int add(int x, int y)=0;//输出加法的运算结果

virtual int sub(int x, int y)=0;//输出减法的运算结果
};
class GroupA:public Group
{
    public:
        int add(int a,int b)
        {
        	return a+b;
		}
		int sub(int a,int b)
		{
			return a-b;
		}
};
class GroupB:public Group{
    public:
        int add(int a,int b)
        {
        	return a+b;
		}
		int sub(int a,int b){
			int w;
			w=a-b;
			if(a%10-b%10<0)
			{
				w=w+10;
			}
			return w;
		}
};
class GroupC:public Group{
    public:
		int add(int a,int b)
		{
			int w;
			w=a+b;
			if(a%10+b%10>10)
			{
				w=w-10;
			}
			if(a%100+b%100>10)
			{
				w=w-100;
			}
			return w;
		}
		int sub(int a,int b){
			int w;
			w=a-b;
			if(a%10-b%10<0)
			{
				w=w+10;
			}
		}
};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,n1,n2;
		char ch;
		cin>>n;
		cin>>n1>>ch>>n2;
		if(n==1)
		{
			GroupA a;
			if(ch=='+')
				cout<<a.add(n1,n2)<<endl;
			else
				cout<<a.sub(n1,n2)<<endl;
		}
		if(n==2)
		{
			GroupB b;
			if(ch=='+')
				cout<<b.add(n1,n2)<<endl;
			else
				cout<<b.sub(n1,n2)<<endl;
		}
		if(n==3)
		{
			GroupC c;
			if(ch=='+')
				cout<<c.add(n1,n2)<<endl;
			else
				cout<<c.sub(n1,n2)<<endl;
		}
	}
}
