2017092048:Problem1235:正确
// May.27, 2019
// Author: Wenzhuo Dong
#include <iostream>
#include <string>
#include <iomanip>

#define PI 3.14

using namespace std;

class Geometry{
public:
    virtual double getArea()=0;
};

class Rect:public Geometry{
protected:
    double length, width;
public:
    Rect(int length, int width) : length(length), width(width) {}

    double getArea(){
        return length*width;
    }
};

class Circle:public Geometry{
protected:
    double radius;
public:
    Circle(double radius) : radius(radius) {}

    double getArea(){
        return PI*radius*radius;
    }
};

class TotalArea{
public:
    static void computerTotalArea(Geometry** t, int n) {
        double max = 0;
        for (int i = 0; i < n; ++i ) {
            if (t[i]->getArea() > max)
                max = t[i]->getArea();
        }
        cout <<fixed << setprecision(2)<< "最大面积=" << max << endl;
    }
};

int main() {
    int samples;
    cin >> samples;

    int opt, a, b;
    Geometry **t = new Geometry*[samples];

    for (int i=0; i < samples; ++i) {

        cin >> opt;
        switch(opt){
            case 1:
                cin >> a >> b;
                t[i] = new Rect(a, b);
                break;
            case 2:
                cin >> a;
                t[i] = new Circle(a);
                break;
        }
    }

    TotalArea::computerTotalArea(t, samples);
    return 0;
}



