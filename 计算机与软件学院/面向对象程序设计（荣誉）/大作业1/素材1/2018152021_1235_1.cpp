2018152021:Problem1235:正确
#include<iostream>
#include<iomanip>
using namespace std;
 
class Geometry{
    public:
        virtual double getArea()=0;
};
class Rect:public Geometry{
        int B,C;
    public:
        Rect(int b,int c){
            B=b;
            C=c;
        }
        double getArea(){
            return B*C;
        }
};
class Circle:public Geometry{
        int D;
    public:
        Circle(int d){
            D=d;
        }
        double getArea(){
            return D*D*3.14;
        }
};
 
class TotalArea{
    public:
        static void computerTotalArea(Geometry** t,int n){
            for(int i=0;i<n;i++)
            {
                int j;
                double b,c,d;
                cin >> j;
                if(j==1)
                {
                    cin >> b >> c;
                    t[i] = new Rect(b,c);
                }
                else if(j==2)
                {
                    cin >> d;
                    t[i] = new Circle(d);
                }
                 
            }
            double max1=t[0]->getArea();
            for(int i=1;i<n;i++)
            {
                if(max1<t[i]->getArea())
                    max1=t[i]->getArea();
            }
            cout << fixed << setprecision(2) << "最大面积=" << max1 << endl;
        }
};
 
int main()
{
    int t,i;
    cin >> t;
    int a,b,c,d;
    Geometry **ps = new Geometry*[t+1];
    int sum;
    TotalArea::computerTotalArea(ps,t);
    return 0;
}

