2018192006:Problem1235:正确
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
class Geometry{
	public:
    	virtual double getArea()=0;
};
class Rect:public Geometry{
	public:
		double getArea(){return this->length*this->width;};
		void readInfo();
	protected:
		double length;
		double width;
};
class Circle:public Geometry{
	public:
		double getArea(){return 3.14*this->radius*this->radius;};
		void readInfo();
	protected:
		double radius;
};
class TotalArea{
	public:
   		static void computerTotalArea(Geometry** t,int n);
	private:

};
/*Add Functions Here*/
void 
Rect::readInfo(){
	cin >> this->length >> this->width;
}
void 
Circle::readInfo(){
	cin >> this->radius;
}
void
TotalArea::computerTotalArea(Geometry** t,int n){
	int i;
	double tmp,max=INT_MIN;
	for(i=0;i<n;++i){
		tmp=t[i]->getArea();
		if(tmp>max)
			max=tmp;
	}
	cout << std::fixed << std::setprecision(2) << "最大面积=" << max << endl;
}
/*Main Function starts here.*/
int main(){
#define IF_LOOP_NEEDED
#ifdef  IF_LOOP_NEEDED
    int round,rounds;
    cin >> rounds;
    /*Preprocessing Here*/
    TotalArea M;
    Geometry** ptr=new Geometry*[rounds];
    int max=INT_MIN;
    for(round=1;round<=rounds;++round){
    /*Solve Problems Here if number of test cases are known.*/
    	int n;
    	cin >> n;
    	if(n==1){
    		Rect A;
    		ptr[round-1]=&A;
    		A.readInfo();
    
		}else{
			Circle B;
			ptr[round-1]=&B;
			B.readInfo();
			
		}
    }
    M.computerTotalArea(ptr,rounds);
#endif
    /*Final process here.*/
  
/*Debugger after Solution,close output file.*/
#ifdef DEBUG
    input.close();
    output.close();
#endif
    return 0;
}      
