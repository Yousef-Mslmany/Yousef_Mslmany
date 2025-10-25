#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
struct sClient
{
    string Account_Number;
    string Pin_Code;
    string Name;
    string Phone;
    double Account_Balance;
};

const string ClientsFileName = "Clients.txt";

vector<string> Split(string S1, string Delim)
{
    vector<string> vString;
    short Pos = 0;
    string sWord;

    while ((Pos = S1.find(Delim)) != string::npos)
    {
        sWord = S1.substr(0, Pos);
        if (sWord != "") {
            vString.push_back(sWord);
        }
        S1.erase(0, Pos + Delim.length());
    }
    if (S1 != "")
    {
        vString.push_back(S1);
    }
    return vString;
}

sClient ConvertLineToRecord(string Line, string Seperator = "#//#")
{
    sClient Client;
    vector<string> vClientData;

    vClientData = Split(Line, Seperator);
    Client.Account_Number = vClientData[0];
    Client.Pin_Code = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.Account_Balance = stod(vClientData[4]);

    return Client;
};

vector <sClient> LoadClientsDataFromFile(string FileName)
{
    vector<sClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string line;
        sClient Client;

        while (getline(MyFile, line))
        {
            Client = ConvertLineToRecord(line);

            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}

void PrintNewClient(sClient client)
{
    cout << "\nThe following are the client details:\n\n";
    cout << "Account Number: " << client.Account_Number << endl;
    cout << "Pin Code: " << client.Pin_Code << endl;
    cout << "Name: " << client.Name << endl;
    cout << "Phone: " << client.Phone << endl;
    cout << "Account Balance: " << client.Account_Balance << endl;
}

bool FindClientByAccountNumber(string AccountNumber, sClient& Client)
{
    vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    for (sClient& C : vClients)
    {
        if (AccountNumber == C.Account_Number)
        {
            Client = C;
            return true;
        }
        
    }
    return false;

};

string ReadClientAccountNumber()
{
    string AccountNumber = "";
    cout << "\nPlease enter Account Number?\n";
    cin >> AccountNumber;
    return AccountNumber;
};

int main()
{
    sClient Client;
    string AccountNumber = ReadClientAccountNumber();
    if (FindClientByAccountNumber(AccountNumber, Client))
    {
        PrintNewClient(Client);
    }
    else
    {
        cout << "\nClient With Account Number (" << AccountNumber << ") Not Found!";
    }
    return 0;
}