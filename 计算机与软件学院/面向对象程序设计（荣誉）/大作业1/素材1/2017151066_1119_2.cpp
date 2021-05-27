2017151066:Problem1119:´ð°¸´íÎó
#include<iostream>
using namespace std;
class BA
{
protected:
    string name,zhanghu;
    int yu_e;
public:
    BA(string n,string z,int y):name(n),zhanghu(z),yu_e(y){}
    //virtual void display()=0;
    virtual void display(int c1,int q1,int c2,int q2)
    {
        int sum=0;
        sum=yu_e+c1;
        if(sum<q1)
        cout<<"insufficient"<<endl;
        else
        {
            sum=yu_e+c1-q1+c2;
            if(sum<q2)
            cout<<"insufficient"<<endl;
            else
            cout<<name<<" "<<zhanghu<<" Balance:"<<sum-q2<<endl;
        }
    }
};
class BP:public BA
{
protected:
    int touzhi;
public:
    BP(string name,string z,int y):BA(name,z,y)
    {
         touzhi=5000;
    }
    virtual void display(int c1,int q1,int c2,int q2)
    {
        int sum=0,sum1=0;
        sum=yu_e+c1-q1+c2-q2;
        sum1=touzhi+sum;
        if(sum1<0)
        {
        	 cout<<"insufficient"<<endl;
		} 
		else{
           if(sum<0)
           {
           	   cout<<name<<" "<<zhanghu<<" Balance:"<<0<<" limit:"<<touzhi+sum<<endl;
		   }
		   else{
		   	cout<<name<<" "<<zhanghu<<" Balance:"<<sum<<" limit:"<<touzhi<<endl;
		   }
		   
        }              
    }
};
int main()
{
    int t;
    cin>>t;
    BA *p;
    string n,z;
    int y,c1,q1,c2,q2;
    while(t--)
    {
        cin>>n>>z>>y;
        if(z[1]=='A')
        {
            cin>>c1>>q1>>c2>>q2;
            p=new BA(n,z,y);
            p->display(c1,q1,c2,q2);
        }
        else{
            cin>>c1>>q1>>c2>>q2;
            p=new BP(n,z,y);
            p->display(c1,q1,c2,q2);
        }
    }
}
