2016150076:Problem1235:�������
class Geometry{

public:

    virtual double getArea()=0; //����������������С�������λ

};

��GeometryΪ���࣬������Rect�����Σ����ݳ�ԱΪ���Ϳ���Circle��Բ�����ݳ�ԱΪ�뾶�������࣬��дgetArea()��������������������Ҫ���⡣

дһ��TotalArea�࣬����ṹ���£�

class TotalArea{

public:

   static void computerTotalArea(Geometry** t,int n)��//tΪ�������ָ�룬ָ��һ�����ද̬���飬�����ÿ��Ԫ��ָ��һ������ͼ�Σ�nΪ����Ĵ�С

};

int main()
{
	int n;
	cin>>n;
	
	Geometry **t=new Geometry *[n];
	for(int i=0;i<n;i++)
	{
		cin>>type;
		if(type==1)
		{
			cin>>a>>b;
			*t=new Rect(a,b);
		}
		
		else
		{
			cin>>r;
			*t=new Circle(r);
		}
	}
}
