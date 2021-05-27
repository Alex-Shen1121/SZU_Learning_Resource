2018152062:Problem1235:��ȷ
#include <iostream>
#include <iomanip>
using namespace std;
/*���д���򣬴�ͼ���������ҳ���������������������ʾ��
��GeometryΪ���࣬������Rect�����Σ����ݳ�ԱΪ���Ϳ���Circle��Բ�����ݳ�ԱΪ�뾶�������࣬
��дetArea()��������������������Ҫ���⡣
дһ��TotalArea�࣬����ṹ���£�
���������ĸ��ಢ��д�����������������λС����*/
class Geometry
{
public:
    virtual double getArea()=0; //����������������С�������λ
};
class Rect:public Geometry
{
protected:
    float length;
    float width;
public:
    Rect(float _length,float _width):length(_length),width(_width){}
    double getArea()
    {
        return length*width;
    }
};
class Circle:public Geometry
{
protected:
    float r;
public:
    Circle(float _r):r(_r){}
    double getArea()
    {
        return 3.14*r*r;
    }
};
class TotalArea
{
public:
    static void computerTotalArea(Geometry** t,int n)
    {
        float maxS=-999999;
        for(int i=0;i<n;i++)
        {
            if(t[i]->getArea()>maxS)
                maxS=t[i]->getArea();
        }
        cout<<"������="<<setiosflags(ios::fixed)<<setprecision(2)<<maxS<<endl;
    }
    //tΪ�������ָ�룬ָ��һ�����ද̬���飬�����ÿ��Ԫ��ָ��һ������ͼ�Σ�nΪ����Ĵ�С

};
int main()
{
    int n;
    cin>>n;
    Geometry **u=new Geometry*[n];
    for(int i=0; i<n; i++)
    {
        int cnt;
        float length,width,r;
        cin>>cnt;
        if(cnt==1)
        {
            cin>>length>>width;
            u[i]=new Rect(length,width);
        }
        else
        {
            cin>>r;
            u[i]=new Circle(r);
        }
    }
    TotalArea::computerTotalArea(u,n);
    for(int i=0;i<n;i++)
        delete u[i];
    delete []u;
}

