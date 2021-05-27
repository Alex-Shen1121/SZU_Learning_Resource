2018151044:Problem1235:��ȷ
#include<string>
#include<iostream>
#include<iomanip> 
using namespace std;
class Ge{
public:
    virtual double getArea()=0; 
    virtual ~Ge() {}
};
class Rect: public Ge
{
	int a,b;
public:
	Rect(int a,int b):a(a),b(b){} //������ 
	double getArea()
	{
		return a*b;
	}
};
class Circle: public Ge
{
	int r;
public:
	Circle(int r):r(r) {}
	double getArea()
	{
		return 3.14*r*r;
	}
};
class TotalArea{
public:
   static void computerTotalArea(Ge **t,int n)//tΪ�������ָ�룬ָ��һ�����ද̬���飬�����ÿ��Ԫ��ָ��һ������ͼ�Σ�nΪ����Ĵ�С
   {
		double ans=0;
		for(int i=0;i<n;++i)
		{
			ans=ans > t[i]->getArea() ? ans : t[i]->getArea();
		}
		cout<<"������="<<setprecision(2)<<fixed<<ans<<endl; 
   }
};
int main()
{
	int t,a,b,c,n;
	cin>>t;
	n=t;
	Ge** p=new Ge*[t];
	while(t--)
	{
		cin>>a>>b;
		if(a==1)
		{
			cin>>c;
			p[t]=new Rect(b,c);
		}
		else p[t]=new Circle(b); 
	}
	TotalArea::computerTotalArea(p,n);
	for(int i=0;i<n;++i)delete p[i];
	delete p;
}
