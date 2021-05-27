#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a[100]= {4,10,11,30,69,70,96,100};
    int b=binary_search(a,a+9,4);//success, 1
    cout<<"find 4:"<<b<<endl;
    int c=binary_search(a,a+9,40);//failure, 0
    cout<<"find 40: "<<c<<endl;

    auto rit = equal_range(a,a+9,10);  //[rit.first,rit.second),
    cout<<">=10 :" <<a[rit.first-a]<<endl;
    cout<<">10 :" <<a[rit.second-a]<<endl;


    int e=lower_bound(a,a+9,101)-a;
    cout<<">=101£º"<<a[e]<<endl;
    int f=upper_bound(a,a+9,10)-a;
    cout<<">10 :"<<a[f]<<endl;

    auto fun = [](int x,int y)->bool{return x>y;};
    cout<<"´æÔÚ7: " <<binary_search(a,a+9,7,fun)<<endl;

}
