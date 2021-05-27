2018192006:Problem1232:ÕýÈ·
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
class Veichle{
    public:
        virtual void display()=0;
        void setType(int i);
         
    protected:  
        int type;
        string name;
        int num;
        int weight;
 
};
class Car:public Veichle{
    public:
        void display();
        void readInfo();
    protected:
 
};
class Truck:public Veichle{
    public:
        void display();
        void readInfo();
    protected:
 
};
class Bus:public Veichle{
    public:
        void display();
        void readInfo();
    protected:
 
 
};
/*Add Functions Here*/
void
Car::display(){
    cout << this->name << " ";
    cout << this->num*8+this->weight*2 << endl;

}
void
Bus::display(){
    cout << this->name << " ";
    cout << this->num*3 << endl;
    
}
void
Truck::display(){
    cout << this->name << " ";

    cout << this->weight*5 << endl;

}
void
Car::readInfo(){
    cin >> this->name >> this->num >> this->weight;
}
void
Truck::readInfo(){
    cin >> this->name >> this->weight;
}
void
Bus::readInfo(){
    cin >> this->name >> this->num ;
}
void
Veichle::setType(int n){
    this->type=n;
}
/*Main Function starts here.*/
int main(){
#define IF_LOOP_NEEDED
#ifdef  IF_LOOP_NEEDED
    int round,rounds;
    cin >> rounds;
    /*Preprocessing Here*/
    Veichle *ptr;
    for(round=1;round<=rounds;++round){
    /*Solve Problems Here if number of test cases are known.*/
        int n;
        cin >> n;
        if(n==1){
            Car A;
            ptr=&A;
            ptr->setType(n);
            A.readInfo(); 
            ptr->display();
        }else if(n==2){
            Truck B;
            ptr=&B;
            ptr->setType(n);
            B.readInfo();
            ptr->display();
        }else{
            Bus C;
            ptr=&C;
            ptr->setType(n);
            C.readInfo();
            ptr->display();
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
