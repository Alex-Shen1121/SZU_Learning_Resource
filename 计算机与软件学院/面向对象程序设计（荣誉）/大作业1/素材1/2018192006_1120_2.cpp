2018192006:Problem1120:ÕýÈ·
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
class Animal{
    public:
        virtual void speak()=0;
        void readInfo();
    protected:  
        string name;
        int age;
};
class Tiger:public Animal{
    public:
        void speak();
    protected:
 
};
class Dog:public Animal{
    public:
        void speak();
    protected:
 
};
class Duck:public Animal{
    public:
        void speak();
    protected:
 
};
class Pig:public Animal{
    public:
        void speak();
    protected:
 
};
/*Add Functions Here*/
void
Animal::readInfo(){
    cin >> this->name >> this->age;
}

void
Tiger::speak(){

    cout << "Hello,I am " << this->name;
    cout << ",AOOO." << endl;

}
void
Pig::speak(){
    cout << "Hello,I am " << this->name;
    cout << ",HENGHENG." << endl; 

}
void
Dog::speak(){
    cout << "Hello,I am " << this->name; 
    cout << ",WangWang." << endl; 

}
void
Duck::speak(){
    cout << "Hello,I am " << this->name; 
    cout << ",GAGA." << endl; 
}
/*Main Function starts here.*/
int main(){
#define IF_LOOP_NEEDED
#ifdef  IF_LOOP_NEEDED
    int round,rounds;
    cin >> rounds;
    /*Preprocessing Here*/
    Animal *ptr;
    for(round=1;round<=rounds;++round){
    /*Solve Problems Here if number of test cases are known.*/
    	string str;
    	cin >> str;
    	if(str=="Tiger"){
    		Tiger A;
    		ptr=&A;
	        ptr->readInfo();
	        ptr->speak();
		}else if(str=="Pig"){
			Pig A;
    		ptr=&A;
	        ptr->readInfo();
	        ptr->speak();
		}else if(str=="Dog"){
			Dog A;
    		ptr=&A;
	        ptr->readInfo();
	        ptr->speak();
		}else if(str=="Duck"){
			Duck A;
    		ptr=&A;
	        ptr->readInfo();
	        ptr->speak();
		}else{
			cout << "There is no "<< str <<" in our Zoo."<< endl;
			string buff1;
			int buff2;
			cin >> buff1 >> buff2;
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
