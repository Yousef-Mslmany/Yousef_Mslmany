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
    bool MarkForDelete = false;
    bool MarkForUpdate = false;
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

void SaveVectorToFile(string FileName, vector <sClient> vClients)
{

    fstream MyFile;
    MyFile.open(FileName, ios::out);
    string DataLine = "";

    if (MyFile.is_open())
    {
        for (sClient C : vClients)
        {
            if (C.MarkForDelete == false)
            {
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }

}

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

sClient ChangeClientRecord(string AccountNumber)
{
    sClient Client;

    Client.Account_Number = AccountNumber;

    cout << "\nEnter PinCode? ";
    getline(cin >> ws, Client.Pin_Code);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter Account Balance: ";
    cin >> Client.Account_Balance;

    Client.MarkForDelete = false;

    return Client;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
    for (sClient& C : vClients)
    {
        if (C.Account_Number == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }
    }
    return false;
};

bool FindClientByAccountNumber(string AccountNumber, vector <sClient> vClients, sClient& Client)
{

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

bool UpdateClientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
    sClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintNewClient(Client);

        cout << "\nAre you sure you want Update this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            for (sClient& C : vClients)
            {
                if (C.Account_Number == AccountNumber)
                {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }
            SaveVectorToFile(ClientsFileName, vClients);

            cout << "\nClient Update Successfully.";
            return true;
        }
    }
    else
    {
        cout << "\nClient With Account Number (" << AccountNumber << ") Not Found!";
        return false;
    }
};

string ReadClientAccountNumber()
{
    string AccountNumber = "";
    cout << "Please enter Account Number? ";
    cin >> AccountNumber;
    return AccountNumber;
};

int main()
{
    vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    string AccountNumber = ReadClientAccountNumber();

    UpdateClientByAccountNumber(AccountNumber, vClients);

    return 0;
}