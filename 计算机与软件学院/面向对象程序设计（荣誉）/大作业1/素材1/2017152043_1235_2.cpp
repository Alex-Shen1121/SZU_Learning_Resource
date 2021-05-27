2017152043:Problem1235:��ȷ
#include<iostream>
#include<iomanip>
using namespace std;

class Geometry{
public:
    virtual double getArea()=0; //����������������С�������λ
	virtual ~Geometry(){}
};

class Rect:public Geometry{
	double length;
	double width;
public:
	Rect(double l,double w):length(l),width(w){}
	double getArea()
	{
		return length * width;
	}
	~Rect(){}
};

class Circle:public Geometry{
	double radius;
public:
	Circle(double r):radius(r){}
	double getArea()
	{
		return 3.14 * radius * radius;
	}
	~Circle(){}
};

class TotalArea{
public:
	TotalArea(){}
   static void computerTotalArea(Geometry** t,int n)
   {
   		double max = t[0]->getArea();
   		for(int i = 1;i < n;i++){
			if(t[i]->getArea() > max)
				max = t[i]->getArea();
	    }
		cout << "������=" << fixed << setprecision(2) << t[n - 1]->getArea() << endl;
	
   }//tΪ�������ָ�룬ָ��һ�����ද̬���飬�����ÿ��Ԫ��ָ��һ������ͼ�Σ�nΪ����Ĵ�С
};




int main(){
	int t;
	Geometry** pg;
	int type;
	double l,w,r;
	cin >> t;
	pg = new Geometry *[t];
	for(int i = 0;i < t;i++){
		cin >> type;
		if(type == 1){
			cin >> l >> w;
			pg[i] = new Rect(l,w);
		}
		else if(type == 2){
			cin >> r;
			pg[i] = new Circle(r);
		}
	}
	TotalArea total;
	total.computerTotalArea(pg,t);
	for(int i = 0;i < t;i++)
		delete pg[i];
	delete []pg;
	
	return 0;
}

