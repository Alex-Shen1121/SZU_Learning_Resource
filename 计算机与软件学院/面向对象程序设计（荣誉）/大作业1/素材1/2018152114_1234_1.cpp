2018152114:Problem1234:�������
#include<iostream>
#include<cstring>
using namespace std;
class Group
{

public:

virtual int add(int x, int y)=0;//����ӷ���������

virtual int sub(int x, int y)=0;//���������������

};
class GroupA:public Group
{
public:
   virtual int add(int x, int y)
   {
   	   return x+y;
   }
   virtual int sub(int x, int y)
   {
   		
   }
};
class GroupB:public Group
{
	public:
   virtual int add(int x, int y)
   {
   	   return x+y;
   }
   virtual int sub(int x, int y)
   {
   		
   		return sum
   }	
}
class GroupC:public Group
{
	
};
int main()
{
	int t;
	int type;
	int n1,n2;
	char key;
	cin>>t;
	Group* ps;
	while(t--)
	{
		cin>>type>>n1>>key>>n2;
		switch(type)
			{
				case 1:
					
					
			}
	}
	
	
}
