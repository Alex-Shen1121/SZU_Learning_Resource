#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
   int min = 10, max = 20;
   int num;

   while(cin>>num)
   {
       [min,max](int &x){
            if(x>=min&&x<=max)
                x= 2*x;
        }(num);
        cout<<num<<endl;
   }
    return 0;


}
