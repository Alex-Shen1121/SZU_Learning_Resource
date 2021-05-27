#include <iostream>
using namespace std;


int main()
{
   int boys = 4, girls = 3;

   auto totalChild = [=]()->int{return girls+boys;};

   cout<<typeid(boys).name()<<endl;
   cout<<typeid(girls).name()<<endl;
   cout<<typeid(totalChild()).name()<<endl;


   cout<<totalChild()<<endl;




   return 0;

}
