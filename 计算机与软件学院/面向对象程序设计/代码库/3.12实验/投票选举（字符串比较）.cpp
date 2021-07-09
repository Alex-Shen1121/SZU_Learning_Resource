#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int N,i,j;
	cin >> N;
	char name1[3][100]= { "Li","Zhang","Fu" } , name[100];
	int number[3] = { 0 };
	for (i = 0; i < N; i++)
	{
		cin >> name;
			for (j = 0; j < 3; j++)
			{
				if (strcmp(name,name1[j])==0)
					number[j]++;
			}
	}
	for(i=0;i<3;i++)
		cout<<name1[i]<<':'<<number[i]<<endl;
	
	return 0;
}
