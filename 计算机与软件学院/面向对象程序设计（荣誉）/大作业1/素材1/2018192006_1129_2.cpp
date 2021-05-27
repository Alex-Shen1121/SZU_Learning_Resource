2018192006:Problem1129:ÕýÈ·
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
#include <algorithm>
using std::sort;
using std::swap;
   
#include <iomanip>
#include <cstdio>
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
class show{
	public:
		virtual void printCard()=0;
};
class BaseCard:virtual public show{
    public:
        void setCard();
        void depositCard();
        void withdrawCard();
        void printCard();
    protected:
        string cardID;
        string cardName;
        double value;
          
};
class TraCard : public BaseCard,virtual public show{
    public:
        void setTraCard();
        void depositTraCard();
        void withdrawTraCard();
        void printCard();
        void transfer();
    protected:
        double traVal;
};
class GoldCard : public BaseCard,virtual public show{
    public:
        void setGoldCard();
        void depositGoldCard();
        void withdrawGoldCard();
        void printCard();
    protected:
        double extraVal;
};
/*Add Functions Here*/
void
BaseCard::setCard(){
    cin >> this->cardID >> this->cardName >> this->value;
}
void
TraCard::setTraCard(){
    this->setCard();
    cin >> this->traVal;
}
void
GoldCard::setGoldCard(){
    this->setCard();
    cin >> this->extraVal;
}
  
void
BaseCard::depositCard(){
    double m;
    cin >> m;
    if(m<=0)
        return;
    this->value+=m;
}
void
TraCard::depositTraCard(){
    this->depositCard();
}
void
GoldCard::depositGoldCard(){
    this->depositCard();
}
  
void
BaseCard::withdrawCard(){
    double m;
    cin >> m; 
    if(m<=0)
        return;
    if(m>this->value)
        return;
    this->value-=m;
}
void
TraCard::withdrawTraCard(){
    this->withdrawCard();
}
void
GoldCard::withdrawGoldCard(){
    double m;
    cin >> m; 
    if(m<=0)
        return;
    else if(m>this->value+this->extraVal)
        return;
    else if(m<=this->value+this->extraVal && m>this->value){
        m-=this->value;
        this->value=0;
        this->extraVal-=m;
    }else{
        this->value-=m;
    }
}
void
BaseCard::printCard(){
    cout << this->cardID << "-" << this->cardName << "-" << this->value << endl;
}
void
TraCard::printCard(){
    cout << this->cardID << "-" << this->cardName << "-" << this->value << "-" << this->traVal << endl; 
}
void
GoldCard::printCard(){
    cout << this->cardID << "-" << this->cardName << "-" << this->value << "-" << this->extraVal << endl; 
}
void
TraCard::transfer(){
    double m;
    cin >> m;
    if(m<=0)
        return;
    if(m>this->value)
        return;
    this->value-=m;
    this->traVal+=m;
}
/*Main Function starts here.*/
int main(){
/*define IF_LOOP_NEEDED here if number of test cases are known.*/
//#define IF_LOOP_NEEDED
#ifdef  IF_LOOP_NEEDED
    int round,rounds;
    cin >> rounds;
    /*Preprocessing Here*/
      
    for(round=1;round<=rounds;++round){
  
    }
  
    /*Final process here.*/
      
#endif
    /*Solve Problems here if there are only one test case.*/
    show* ptr;
    BaseCard A;
    TraCard B;
    GoldCard C;
    A.setCard();
    B.setTraCard();
    C.setGoldCard();
    A.depositCard();
    A.depositCard();
    A.withdrawCard();
    A.withdrawCard();
    ptr=&A; 
    ptr->printCard();
    B.depositTraCard();
    B.withdrawTraCard();
    B.transfer();
    B.transfer();
    ptr=&B;
    ptr->printCard();
    C.depositGoldCard();
    C.withdrawGoldCard();
    C.withdrawGoldCard();
    C.withdrawGoldCard();
    ptr=&C;
    ptr->printCard();
/*Debugger after Solution,close output file.*/
#ifdef DEBUG
    input.close();
    output.close();
#endif
    return 0;
}     
   
