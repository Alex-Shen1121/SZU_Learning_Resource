2018151044:Problem1234:��ȷ
#include<iostream>
#include<string>
using namespace std;
class G
{
public:
	virtual ~G() {}
	virtual int add(int x, int y)=0;//����ӷ���������
	virtual int sub(int x, int y)=0;//���������������
};
class G1:public G
{
public:
	virtual int add(int x, int y)//����ӷ���������
	{
		return x+y;
	}
	virtual int sub(int x, int y)//���������������
	{
		return x-y;
	}
};
class G2:public G
{
public:
	virtual int add(int x, int y)//����ӷ���������
	{
		return x+y;
	}
	virtual int sub(int x, int y)//���������������
	{
		int ans[10],cnt=0;
		while(x||y)
		{
			ans[cnt++]=(10+x%10-y%10)%10;
			x/=10;
			y/=10; 
		}
		int res=0;
		for(int i=cnt-1;i>=0;--i)
		{
			res=res*10+ans[i];
		}
		return res;
	}
};
class G3:public G
{
public:
	virtual int add(int x, int y)//����ӷ���������
	{
		int ans[10],cnt=0;
		while(x||y)
		{
			ans[cnt++]=(x%10+y%10)%10;
			x/=10;
			y/=10; 
		}
		int res=0;
		for(int i=cnt-1;i>=0;--i)
		{
			res=res*10+ans[i];
		}
		return res;
	}
	virtual int sub(int x, int y)//���������������
	{
		int ans[10],cnt=0;
		while(x||y)
		{
			ans[cnt++]=(10+x%10-y%10)%10;
			x/=10;
			y/=10; 
		}
		int res=0;
		for(int i=cnt-1;i>=0;--i)
		{
			res=res*10+ans[i];
		}
		return res;
	}
};
int main()
{
	int t;
	cin>>t;
	G *p; 
	while(t--)
	{
		int no,a,c;
		char b;
		cin>>no>>a>>b>>c;
		if(no==1)p=new G1;
		else if(no==2)p=new G2;
		else p=new G3;
		if(b=='+')cout<<p->add(a,c)<<endl;
		else cout<<p->sub(a,c)<<endl;
		delete p;
	} 
}
