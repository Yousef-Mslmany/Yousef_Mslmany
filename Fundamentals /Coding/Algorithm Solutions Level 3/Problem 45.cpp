
#include <string>
#include <iostream>
#include<vector>
using namespace std;

struct sClint
{
	string Account_Number;
	string Pin_Code;
	string Name, Phone;
	double Account_Balance;
};

sClint ReadNewClient()
{
	sClint Clint;

		cout << "\n\nEnter Account Number? ";
		getline(cin, Clint.Account_Number);

		cout << "Enter PinCode? ";
		getline(cin, Clint.Pin_Code);

		cout << "Enter Name? ";
		getline(cin, Clint.Name);

		cout << "Enter Phone? ";
		getline(cin, Clint.Phone);

		cout << "Enter Account Balance: ";
		cin>> Clint.Account_Balance;

		return Clint;
}

string  ConvertRecordToLine(sClint Clint, string Seperator = "#//#")
{
	string stClintRecord = "";

	stClintRecord += Clint.Account_Number + Seperator;
	stClintRecord += Clint.Pin_Code + Seperator;
	stClintRecord += Clint.Name + Seperator;
	stClintRecord += Clint.Phone + Seperator;
	stClintRecord += to_string(Clint.Account_Balance);

	return stClintRecord;
};


int main()
{
	cout << "Please Enter Client Data:";

	sClint Clint;
	Clint = ReadNewClient();

	cout << "\n\nClient Record for Saving is: \n";
	cout << ConvertRecordToLine(Clint);

	return 0;
}