2018151044:Problem1235:正确
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
	Rect(int a,int b):a(a),b(b){} //最大面积 
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
   static void computerTotalArea(Ge **t,int n)//t为基类二级指针，指向一个基类动态数组，数组的每个元素指向一个子类图形，n为数组的大小
   {
		double ans=0;
		for(int i=0;i<n;++i)
		{
			ans=ans > t[i]->getArea() ? ans : t[i]->getArea();
		}
		cout<<"最大面积="<<setprecision(2)<<fixed<<ans<<endl; 
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
