2018151005:Problem1235:�𰸴���
#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>
using namespace std;
/*��Ŀ����

���д���򣬴�ͼ���������ҳ���������������������ʾ��

class Geometry{

public:

    virtual double getArea()=0; //����������������С�������λ

};*/
class Geometry
{
public:
    virtual double getArea()=0; //����������������С�������λ
};
/*��GeometryΪ���࣬������Rect�����Σ����ݳ�ԱΪ���Ϳ���Circle��Բ�����ݳ�ԱΪ�뾶�������࣬��дgetArea()������
��������������Ҫ���⡣*/
class Rect:public Geometry
{
private:
    double length,width;
public:
    Rect(){}
    Rect(double length0,double width0):length(length0),width(width0){}
    double getArea()
    {
        return length*width;
    }
};
class Circle:public Geometry
{
private:
    double radius;
public:
    Circle(){}
    Circle(double radius0):radius(radius0){}
    double getArea()
    {
        return 3.14*radius*radius;
    }
};
/*дһ��TotalArea�࣬����ṹ���£�

class TotalArea{

public:

   static void computerTotalArea(Geometry** t,int n)��//tΪ�������ָ�룬ָ��һ�����ද̬���飬�����ÿ��Ԫ��ָ��
   һ������ͼ�Σ�nΪ����Ĵ�С

};*/
class TotalArea
{
public:
    static void computerTotalArea(Geometry** t,int n)
    {
        double max_area=0;
        for(int i=1;i<=n;i++)
        {
            if(t[i-1]->getArea()>max_area)
                max_area=t[i-1]->getArea();
        }
        cout<<"������="<<double(int(max_area*100+0.5))/100<<endl;
    }
};
/*
���������ĸ��ಢ��д�����������������λС����

����

��һ�б�ʾ���Դ������ӵڶ��п�ʼ��ÿ����������ռһ�У�ÿ�������������£�ͼ�����ͣ�1ΪRect(����)��2ΪCircle(Բ)����
������Ϣ��Rect�ǳ��Ϳ�Circle�ǰ뾶����

���

���ͼ�ε����
��������

3
1 3 4
2 5
2 6
�������

������=113.04
��ʾ*/
int main()
{
    int t;
    cin>>t;
    Geometry** p;
    p=new Geometry*[t];
    for(int i=1;i<=t;i++)
    {
        int type;
        cin>>type;
        switch(type)
        {
        case 1:
            {
                double length,width;
                cin>>length>>width;
                Rect a(length,width);
                p[i-1]=&a;
                break;
            }
        case 2:
            {
                double radius;
                cin>>radius;
                Circle a(radius);
                p[i-1]=&a;
                break;
            }
        }
    }
    TotalArea b;
    b.computerTotalArea(p,t);
}

