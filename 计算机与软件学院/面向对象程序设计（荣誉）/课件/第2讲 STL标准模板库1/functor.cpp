#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;



int main()
{
    int  data[10]{1,2,3,4,5};

    sort(data,data+10,greater<int>());    //��������
    //sort(data,data+10,[](int lhs,int rhs){return lhs>=rhs;});

    int sum = accumulate(data,data+10,0,minus<int>());   //minus�º�����accumulate���㷨�����
    int sum1 = accumulate(data,data+10,10);      //���
    cout<<sum<<" "<<sum1<<endl;

    for(auto x:data)
        cout<<x<<" ";
    cout<<endl;


}
