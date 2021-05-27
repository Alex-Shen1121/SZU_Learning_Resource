2018192006:Problem1119:ÕýÈ·
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
class BaseAccount{
	public:
		virtual void deposit();
		virtual void withdraw();
		virtual void display(); 
		BaseAccount(string name,string acco,int balance):name(name),acco(acco),balance(balance){};
	protected:	
		string name;
		string acco;
		int balance;
};
class BasePlus:public BaseAccount{
	public:
		BasePlus(string name,string acco,int balance):BaseAccount(name,acco,balance),limit(5000){};
		void deposit();
		void withdraw(); 
		void display();
	protected:
		int limit;
};
void
BaseAccount::display(){
	cout << this->name << " " << this->acco << " Balance:" << this->balance << endl;
}
void
BasePlus::display(){
	cout << this->name << " " << this->acco << " Balance:" << this->balance << " limit:" << this->limit << endl;
}
void
BaseAccount::deposit(){
	int a;
	cin >> a;
	this->balance+=a;
	
}
void
BaseAccount::withdraw(){
	int a;
	cin >> a;
	if(this->balance<a){
		cout << "insufficient" << endl;
	}else{
		this->balance-=a;
	}
}
void
BasePlus::deposit(){
	int a;
	cin >> a;
	this->balance+=a;
	
}
void
BasePlus::withdraw(){
	int a;
	cin >> a;
	if((this->balance+this->limit)<a){
		cout << "insufficient" << endl;
	}else if(this->balance<a && (this->balance+this->limit)>=a){
		this->limit-=(a-this->balance);
		this->balance=0;
	}else{
		this->balance-=a;
	}
}
/*Add Functions Here*/

/*Main Function starts here.*/
int main(){
#define IF_LOOP_NEEDED
#ifdef  IF_LOOP_NEEDED
    int round,rounds;
    cin >> rounds;
    /*Preprocessing Here*/
    BaseAccount *ptr;
    for(round=1;round<=rounds;++round){
    /*Solve Problems Here if number of test cases are known.*/
    	string s1,s2;
    	int m;
    	cin >> s1 >> s2 >> m;
    	if(s2.substr(0,2)=="BA"){
    		BaseAccount A(s1,s2,m);
    		ptr=&A;
    		ptr->deposit();
			ptr->withdraw();		
			ptr->deposit();
			ptr->withdraw();
			ptr->display();
		}else{
			BasePlus B(s1,s2,m);
			ptr=&B;
			ptr->deposit();
			ptr->withdraw();		
			ptr->deposit();
			ptr->withdraw();
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
