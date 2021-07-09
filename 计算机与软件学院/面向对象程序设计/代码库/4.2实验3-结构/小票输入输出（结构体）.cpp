#include<iostream>
#include<iomanip>
using namespace std;
struct Inform
{
	char name[100];
	char term[6];
	char oper[3];
	char card[4];
	char vali[6];
	char numb[17];
	char date[10];
	float cost;
};
Inform getInform()
{
	Inform temp;
	cin >> temp.name >> temp.term >> temp.oper >> temp.card >> temp.vali >> temp.numb >> temp.date >> temp.cost;
	return temp;
}
void output(Inform& temp)
{
	cout << "Name: " << temp.name << '\n';
	cout << "Terminal: " << temp.term << " operator: " << temp.oper << '\n';
	cout << "Card Issuers: " << temp.card << " Validity: " << temp.vali << '\n';
	cout << "CardNumber: " << temp.numb[0] << temp.numb[1] << temp.numb[2] << temp.numb[3] << "********" << temp.numb[12] << temp.numb[13] << temp.numb[14] << temp.numb[15] << '\n';
	cout << "Traded: " << temp.date << '\n';
	cout << "Costs: $" << fixed << setprecision(2) << temp.cost << '\n' << endl;
}
int main()
{
	int i,t;
	cin >> t;
	Inform temp;
	Inform* Result = new Inform[t];
	for (i = 0; i < t; i++)
		Result[i] = getInform();
	for (i = 0; i < t; i++)
		output(Result[i]);
	return 0;
}

