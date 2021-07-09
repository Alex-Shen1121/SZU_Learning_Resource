#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int num[3][3],i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			cin>>num[i][j];
	}
	for(j=0;j<3;j++)
	{
		for(i=0;i<3;i++)
			cout<<num[i][j]<<' ';
		cout<<'\n';
	}
}

