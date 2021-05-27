2018192014:Problem1235:�𰸴���
#include<bits/stdc++.h>
using namespace std;
class Geometry{

public:

    virtual double getArea()=0; //����������������С�������λ

};
class Rect:virtual public Geometry{
protected:
	double a,b;
public:
	Rect(double a1,double b1):
		a(a1),b(b1){	
		}
	virtual double getArea(){
		return a*b;
	}
};
class Circle:virtual public Geometry{
protected:
	double r;
public:
	Circle(double r1):
		r(r1){
		}
	virtual double getArea(){
		return r*r*3.14;
	}
};
class TotalArea{

public:

   static void computerTotalArea(Geometry** t,int n)//tΪ�������ָ�룬ָ��һ�����ද̬���飬�����ÿ��Ԫ��ָ��һ������ͼ�Σ�nΪ����Ĵ�С
	{
		double res;
		for(int i=0;i<n;i++)
		{
			if(res<t[i]->getArea())
			{
				res=t[i]->getArea();
			}
		}
		cout<<"������="<<res<<endl;
	}
};
int main ()
{
	Geometry **t;
	int n;
	cin>>n;
	t=new Geometry*[n];
	for(int i=0;i<n;i++)
	{
		int command;
		double a,b,r;
		cin>>command;
		if(command==1)
		{
			cin>>a>>b;
			t[i]=new Rect(a,b);
		}
		else
		{
			cin>>r;
			t[i]=new Circle(r);
		}
	}
	TotalArea a;
	a.computerTotalArea(t,n);
	return 0;
}
