
#include <string>
#include <iostream>
#include<vector>
#include<fstream>
using namespace std;

const string ClientsFileName = "Clients.txt";

struct sClient
{
	string Account_Number;
	string Pin_Code;
	string Name, Phone;
	double Account_Balance;
};

sClient ReadNewClient()
{
	sClient Client;

	cout << "\n\nEnter Account Number? ";
	getline(cin >> ws, Client.Account_Number);

	cout << "Enter PinCode? ";
	getline(cin, Client.Pin_Code);

	cout << "Enter Name? ";
	getline(cin, Client.Name);

	cout << "Enter Phone? ";
	getline(cin, Client.Phone);

	cout << "Enter Account Balance: ";
	cin >> Client.Account_Balance;

	return Client;
};

string  ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
	string stClintRecord = "";

	stClintRecord += Client.Account_Number + Seperator;
	stClintRecord += Client.Pin_Code + Seperator;
	stClintRecord += Client.Name + Seperator;
	stClintRecord += Client.Phone + Seperator;
	stClintRecord += to_string(Client.Account_Balance);

	return stClintRecord;
};

void AddDataLineToFile(string FileName, string stDataLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{
		MyFile << stDataLine << endl;
		MyFile.close();
	}
};

void AddNewClient()
{
	sClient Client;
	Client = ReadNewClient();
	AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
};

void AddClients()
{

	char AddMore = 'y';
	do
	{
		system("cls");
		cout << "Adding New Client:";

		AddNewClient();
		cout << "\nClient Added Successfully, do you want to add more clients? ";
		cin >> AddMore;

	} while (toupper(AddMore) == 'Y');
};

int main()
{
	AddClients();

	return 0;
}