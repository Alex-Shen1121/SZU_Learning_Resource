#include <iostream>
#include <regex>
using namespace std;

int main()
{
    int t;
    string str;
    regex r("(int|float|double)");
    regex r1("[a-zA-z_]([a-zA-z0-9_]*)");
    cin>>t;
    cin.ignore();
    while(t--)
    {

        getline(cin,str);

        if(!regex_match(str,r) && regex_match(str,r1))
            cout<<"valid"<<endl;
        else
            cout<<"unvalid"<<endl;
    }
}
