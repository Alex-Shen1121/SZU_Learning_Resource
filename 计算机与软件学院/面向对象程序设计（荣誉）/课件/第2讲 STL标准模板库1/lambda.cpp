#include <iostream>
using namespace std;

int main()
{
   int j=12;

   auto by_val_lambda = [=]{return j+1;};
   auto by_ref_lambda = [&]{return j+1;};

   cout<<"by_val_lambda:"<<by_val_lambda()<<endl;
   cout<<"by_ref_lambda:"<<by_ref_lambda()<<endl;
   j+=1;
   cout<<"by_val_lambda:"<<by_val_lambda()<<endl;
   cout<<"by_ref_lambda:"<<by_ref_lambda()<<endl;



   return 0;

}
