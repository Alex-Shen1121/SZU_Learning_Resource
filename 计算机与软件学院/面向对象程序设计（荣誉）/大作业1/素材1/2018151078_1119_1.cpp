2018151078:Problem1119:ÕýÈ·
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
     virtual void cun(int n)
     {
        yu_e=yu_e+n;
     }
     virtual void qu(int n)
     {
        if(n>yu_e)
        cout<<"insufficient"<<endl;
        else{
            yu_e=yu_e-n;
         }
     }
     virtual void display()
     {
        cout<<name<<" "<<zhanghu<<" Balance:"<<yu_e<<endl;
     }
};
class BP:public BA
{
protected:
    int touzhi;
    int touzhi_t;
public:
    BP(string name,string z,int y):BA(name,z,y)
    {
         touzhi=5000;
         touzhi_t=0;
    }
    virtual void cun(int n)
    {
        yu_e=yu_e+n;
    }
    virtual void qu(int n)
    {
        if(n>yu_e+touzhi)
        {
            cout<<"insufficient"<<endl;
        }
        else
        {
            yu_e=yu_e-n;
            if(yu_e<0)
            {
                touzhi_t=touzhi_t-yu_e;
                yu_e=0;
            }
        }
    }
    virtual void display()
    {
        cout<<name<<" "<<zhanghu<<" Balance:"<<yu_e<<" limit:"<<touzhi-touzhi_t<<endl;
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
            p=new BA(n,z,y);
            cin>>c1>>q1>>c2>>q2;
            p->cun(c1);
            p->qu(q1);
            p->cun(c2);
            p->qu(q2);
            p->display();
        }
        else{
            p=new BP(n,z,y);
            cin>>c1>>q1>>c2>>q2;
            p->cun(c1);
            p->qu(q1);
            p->cun(c2);
            p->qu(q2);
            p->display();
        }
    }
    return 0;
}
