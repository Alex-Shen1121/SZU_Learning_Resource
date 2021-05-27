2018192006:Problem1234:ÕýÈ·
/* Structure for OpenJudge
 * Version 1.2 
 * Created by Sparky. 2019.3.10
 */
#include <iostream>
using std::cin;using std::cout;
using std::cerr;using std::endl;
    
using std::istream;using std::ostream; 
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <queue>
using std::queue;
#include <algorithm>
using std::sort;
using std::swap;
    
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <cmath>
/*Add other "#include"s and namespace usings here if needed.*/
#include <iomanip>
  
  
/*Debugger before Solution*/
//#define DEBUG
//undefine DEBUG if stop debugging.
#ifdef DEBUG
    #include <fstream>
    using std::ifstream;using std::ofstream;
    ifstream input("C:\\Users\\StarSparky\\Desktop\\Codes\\OpenJudge Structure(Cpp)\\InputTest.txt",ifstream::in);
    ofstream output("C:\\Users\\StarSparky\\Desktop\\Codes\\OpenJudge Structure(Cpp)\\OutputTest.txt",ofstream::out);
    #define cin input
    #define cout output
#endif
  
/*Add Data Structures Here*/
class Group
{
	public:
		virtual int add(int x, int y)=0;
		virtual int sub(int x, int y)=0;
};
class GpA:public Group{
	public:
		int add(int x, int y){return x+y;};
		int sub(int x, int y){return x-y;};

	private:

};
class GpB:public Group{
	public:
		int add(int x, int y){return x+y;};
		int sub(int x, int y){
			int a=x,b=y,sum=0;
			int i;
			for(i=0;a!=0 || b!=0;++i){
				int tmp=(a%10-b%10);
				if(tmp<0)
					tmp+=10;
				sum+=tmp*pow(10,i);
				a/=10;
				b/=10;
			}
			return sum;
		};

	private:

};
class GpC:public Group{
	public:
		int add(int x, int y){
			int i;
			int a=x,b=y,sum=0;
			for(i=0;a!=0 || b!=0;++i){
				sum+=fabs((a%10+b%10)%10)*pow(10,i);
				a/=10;
				b/=10;
			}
			return sum;
		};
		int sub(int x, int y){
			int i;
			int a=x,b=y,sum=0;
			for(i=0;a!=0 || b!=0;++i){
				int tmp=(a%10-b%10);
				if(tmp<0)
					tmp+=10;
				sum+=tmp*pow(10,i);
				a/=10;
				b/=10;
			}
			return sum;
		};


};
/*Add Functions Here*/

/*Main Function starts here.*/
int main(){
#define IF_LOOP_NEEDED
#ifdef  IF_LOOP_NEEDED
    int round,rounds;
    cin >> rounds;
    /*Preprocessing Here*/
    Group *ptr;
    for(round=1;round<=rounds;++round){
    /*Solve Problems Here if number of test cases are known.*/
    	int n,a,b;
    	char c;
    	cin >> n;
    	cin >> a >> c >> b;
    	if(n==1){
    		GpA A;
    		ptr=&A;
    		if(c=='+'){
    			cout << ptr->add(a,b) << endl;
			}else{
				cout << ptr->sub(a,b) << endl;
			}
		}else if(n==2){
			GpB B;
			ptr=&B;
		    if(c=='+'){
    			cout << ptr->add(a,b) << endl;
			}else{
				cout << ptr->sub(a,b) << endl;
			}
		}else{
			GpC C;
			ptr=&C;
		    if(c=='+'){
    			cout << ptr->add(a,b) << endl;
			}else{
				cout << ptr->sub(a,b) << endl;
			}
		}
    }
    
#endif
    /*Final process here.*/
  
/*Debugger after Solution,close output file.*/
#ifdef DEBUG
    input.close();
    output.close();
#endif
    return 0;
}      
