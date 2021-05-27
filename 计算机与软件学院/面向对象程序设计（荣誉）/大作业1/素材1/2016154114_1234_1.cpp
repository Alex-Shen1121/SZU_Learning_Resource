2016154114:Problem1234:ÕıÈ·
#include<iostream>
#include<string>
using namespace std;

class Group
{
public:
	virtual int add(int x, int y)=0;
	virtual int sub(int x, int y)=0;
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
        return x-y;
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
        int result=0,temp=1;
        while(1)
        {
            int temp1=x%10;
			int temp2=y%10;
            if(x==y && x==0)
				break;
            if(temp1>=temp2)
				result+=(temp1-temp2)*temp;
            else
				result+=(temp1-temp2+10)*temp;
			x/=10;
			y/=10;
			temp*=10;
        }
        return result;
    }
};

class GroupC:public Group
{
public:
    virtual int add(int x, int y)
	{
        int result=0,temp=1;
        while(1)
        {
            int temp1=x%10;
            int temp2=y%10;
            if(x==y && x==0)
				break;
            int sum=temp1+temp2;
            if(sum>10)
				sum-=10;
            result+=sum*temp;
            x/=10;
			y/=10;
			temp*=10;
        }
        return result;
    }
    virtual int sub(int x, int y)
	{
        int result=0,temp=1;
        while(1)
        {
            int temp1=x%10;
			int temp2=y%10;
            if(x==y && x==0)
				break;
            if(temp1>=temp2)
				result+=(temp1-temp2)*temp;
            else
				result+=(temp1-temp2+10)*temp;
			x/=10;
			y/=10;
			temp*=10;
        }
        return result;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Group *g;
        int i,j,group;
        string str,str1,str2; 
        char type;
        cin>>group>>str;
        
		for(i=0;i<str.length();i++)
        {
            if(str[i]=='+' || str[i]=='-')
            {
				j=i;
                break;
            }
            str1+=str[i];
        }
		type=str[j];
        for(i=j+1;i<str.length();i++)
        {
            str2+=str[i];
        }
        
		int x=atof(str1.c_str());
        int y=atof(str2.c_str());
        if(group==1)
        {
            GroupA A;
            g=&A;
            if(type=='+')
				cout<<g->add(x, y)<<endl;
            else
				cout<<g->sub(x, y)<<endl;
        }
        else if(group==2)
        {
            GroupB B;
            g=&B;
            if(type=='+')
			    cout<<g->add(x, y)<<endl;
            else
		        cout<<g->sub(x, y)<<endl;
        }
        else if(group==3)
        {
            GroupC C;
            g=&C;
            if(type=='+')
				cout<<g->add(x, y)<<endl;
            else
	            cout<<g->sub(x, y)<<endl;
        }
    }
	return 0;
}
