#include <stack>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    stack<char>  sign;
    string str;
    int i;

    getline(cin,str);
    for(i=0; i<(int)str.size(); i++)
    {
        if(str[i]=='('||str[i]=='{'||str[i]=='[')
            sign.push(str[i]);
        else if((str[i]==')'&&sign.top()=='(')||
                (str[i]==']'&&sign.top()=='[')||
                (str[i]=='}'&&sign.top()=='{'))
        {
            sign.pop();
        }
        else
            break;
    }
    if(i==(int)str.size()&&sign.empty())
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;

}
