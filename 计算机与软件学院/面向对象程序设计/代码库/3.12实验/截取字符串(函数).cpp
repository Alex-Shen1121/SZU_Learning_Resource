#include<iostream>
#include<string.h>
using namespace std;
int substr(char str1[],char str2[],int index);
int main()
{
	char str1[100]="",str2[100]="";
	int index;
	int I,N,i;
	cin>>N;
	I=N;
	cin.ignore();
	while(I--)
	{
		if(I!=N-1)
			cin.ignore();
		for(i=0;i<100;i++)
		{
			str1[i]='\0';
			str2[i]='\0';
		}			
		cin.get(str1,100);
		cin>>index;
		substr(str1,str2,index)	;
	}
	return 0;
}
int substr(char str1[],char str2[],int index)
{
	int l,i,j;
	l=strlen(str1);
	if(index>l||index<0)
	{
		cout<<"IndexError"<<endl;
		return 0;
	}
	else 
	{
		for(i=index,j=0;i<l;j++,i++)
			str2[j]=str1[i];
		cout<<str2<<endl;
		return 1;
	}
}
