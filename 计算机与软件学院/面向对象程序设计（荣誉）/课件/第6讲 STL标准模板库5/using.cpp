#include <tuple>
#include <iostream>
using namespace std;

class base
{
public:
    void baseprint()
    {
        cout<<"base print"<<endl;
    }
};

class CA:private base
{
public:
    using base::baseprint;
    CAprint()
    {
        cout<<"CA print"<<endl;
    }

};
int main()
{

    CA  A;

    A.baseprint();


}
