2016071031:Problem1235:内存超限
#include <iostream>
#include <bits/stdc++.h>
// 考察向下转换
using namespace std;

class Geometry{
public:
    Geometry() {}
    virtual double getArea()=0; //计算面积，结果保留小数点后两位

};

class Rect: public Geometry {
    int width;
    int height;
public:
    Rect(){}
    Rect(int width_, int height_):Geometry(){
        width = width_;
        height = height_;
    }
    double getArea() { return width * height * 1.0; }
};

class Circle: public Geometry {
    int radius;
public:
    Circle() {}
    Circle(int radius_): Geometry() {
        radius = radius_;
    }
    double getArea() { return 3.14 * pow(radius, 2);}
};

class TotalArea {
public:
    static void computerTotalArea(Geometry** t,int n);
};

void computerTotalArea(Geometry** g,int n) {
    double max = 0;
    for (int i = 0; i < n; i++) {
        double tmp = g[i]->getArea();
        if ( tmp > max)
            max = tmp;
    }
    cout<< "最大面积=" << fixed << setprecision(2) << max <<endl;
}

int main() {
	freopen("ojdata.txt", "r", stdin);
    int t, type, width, height, radius;

    cin>>t;
    Geometry **g = new Geometry*[t];
    for (int i = 0; i < t; i++) {
        cin>>type;
        if (type == 1) {
            cin>>width>>height;
            g[i] = new Rect(width, height);
        } else {
            cin>>radius;
            g[i] = new Circle(radius);
        }
    }

    computerTotalArea(g, t);

    return 0;
}


