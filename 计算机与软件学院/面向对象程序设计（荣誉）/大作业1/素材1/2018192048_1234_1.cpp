2018192048:Problem1234:�������
#include<iostream>
using namespace std;

class Group{

public:
	virtual int add(int x, int y)=0;//����ӷ���������
	virtual int sub(int x, int y)=0;//���������������
}

class GroupA:public Group{
protected:
	int x,y;
public:
	GroupA(){}
	GroupA(int x_,int y_):x(x_),y(y_){}
	int add(){
		return x+y;
	}
	int sub(){
		return x-y;
	}
	~GroupA(){}
};
class GroupB:public Group{
protected:
	int x,y;
public:
	GroupB(){}
	GroupB(int x_,int y_):x(x_),y(y_){}
	int add(){
		return x+y;
	}
	int sub(){
		return x-y+10;
	}
	~GroupB(){}
};

class GroupC:public Group{
protected:
	int x,y;
public:
	GroupC(){}
	GroupC(int x_,int y_):x(x_),y(y_){}
	int add(){
		return x+y;
	}
	int sub(){
		return x-y+10;
	}
	~GroupB(){}
};
