2017152043:Problem1235:正确
#include<iostream>
#include<iomanip>
using namespace std;

class Geometry{
public:
    virtual double getArea()=0; //计算面积，结果保留小数点后两位
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
		cout << "最大面积=" << fixed << setprecision(2) << t[n - 1]->getArea() << endl;
	
   }//t为基类二级指针，指向一个基类动态数组，数组的每个元素指向一个子类图形，n为数组的大小
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

