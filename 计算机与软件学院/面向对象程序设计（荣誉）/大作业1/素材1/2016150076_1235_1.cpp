2016150076:Problem1235:编译错误
class Geometry{

public:

    virtual double getArea()=0; //计算面积，结果保留小数点后两位

};

以Geometry为基类，构建出Rect（矩形，数据成员为长和宽）和Circle（圆，数据成员为半径）两个类，重写getArea()方法，其他方法根据需要自拟。

写一个TotalArea类，该类结构如下：

class TotalArea{

public:

   static void computerTotalArea(Geometry** t,int n)；//t为基类二级指针，指向一个基类动态数组，数组的每个元素指向一个子类图形，n为数组的大小

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
