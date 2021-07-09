#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int i,n,num[1000],sum=0,L,R;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>num[i];
	cin>>L>>R;
	for(i=L-1;i<R;i++)
		sum+=num[i]; 
	cout<<sum;
	return 0;
}

