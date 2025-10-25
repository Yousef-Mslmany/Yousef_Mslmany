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
        if (sWord != "")
            vString.push_back(sWord);
        S1.erase(0, Pos + Delim.length());
    }

    if (S1 != "")
        vString.push_back(S1);

    return vString;
}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
    return Client.Account_Number + Seperator + Client.Pin_Code + Seperator +
        Client.Name + Seperator + Client.Phone + Seperator +
        to_string(Client.Account_Balance);
}

sClient ConvertLineToRecord(string Line, string Seperator = "#//#")
{
    sClient Client;
    vector<string> vClientData = Split(Line, Seperator);

    if (vClientData.size() >= 5)
    {
        Client.Account_Number = vClientData[0];
        Client.Pin_Code = vClientData[1];
        Client.Name = vClientData[2];
        Client.Phone = vClientData[3];
        Client.Account_Balance = stod(vClientData[4]);
    }
    return Client;
}

void SaveVectorToFile(string FileName, vector<sClient> vClients)
{
    fstream MyFile(FileName, ios::out);
    if (MyFile.is_open())
    {
        for (sClient C : vClients)
        {
            if (!C.MarkForDelete)
                MyFile << ConvertRecordToLine(C) << endl;
        }
        MyFile.close();
    }
}

vector<sClient> LoadClientsDataFromFile(string FileName)
{
    vector<sClient> vClients;
    fstream MyFile(FileName, ios::in);
    if (MyFile.is_open())
    {
        string line;
        while (getline(MyFile, line))
        {
            sClient Client = ConvertLineToRecord(line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}

bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
{
    fstream MyFile(FileName, ios::in);
    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            sClient Client = ConvertLineToRecord(Line);
            if (Client.Account_Number == AccountNumber)
            {
                MyFile.close();
                return true;
            }
        }
        MyFile.close();
    }
    return false;
}

void PrintClientRecord(sClient Client)
{
    cout << "| " << setw(15) << left << Client.Account_Number;
    cout << "| " << setw(10) << left << Client.Pin_Code;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.Account_Balance << endl;
}

void ShowAllClientsData()
{
    vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    cout << "\n\t\t\t\tClient List (" << vClients.size() << ") Client(s)\n";
    cout << "________________________________________________________________________________________________\n";
    cout << "| " << setw(15) << left << "Account Number"
        << "| " << setw(10) << left << "Pin Code"
        << "| " << setw(40) << left << "Client Name"
        << "| " << setw(12) << left << "Phone"
        << "| " << setw(12) << left << "Balance\n";
    cout << "________________________________________________________________________________________________\n";

    if (vClients.empty())
    {
        cout << "\t\t\tNo Clients Available In the System!\n";
    }
    else
    {
        for (sClient Client : vClients)
            PrintClientRecord(Client);
    }

    cout << "________________________________________________________________________________________________\n";
}

string ReadClientAccountNumber()
{
    string AccountNumber;
    cout << "Enter Account Number: ";
    cin >> AccountNumber;
    return AccountNumber;
}

sClient ReadNewClient()
{
    sClient Client;
    cout << "\nEnter Account Number: ";
    getline(cin >> ws, Client.Account_Number);

    while (ClientExistsByAccountNumber(Client.Account_Number, ClientsFileName))
    {
        cout << "\nClient with [" << Client.Account_Number << "] already exists, Enter another Account? ";
        getline(cin >> ws, Client.Account_Number);
    }

    cout << "Enter Pin Code: ";
    getline(cin, Client.Pin_Code);

    cout << "Enter Name: ";
    getline(cin, Client.Name);

    cout << "Enter Phone: ";
    getline(cin, Client.Phone);

    cout << "Enter Account Balance: ";
    cin >> Client.Account_Balance;

    return Client;
}

void AddDataLineToFile(string FileName, string DataLine)
{
    fstream MyFile(FileName, ios::out | ios::app);
    if (MyFile.is_open())
    {
        MyFile << DataLine << endl;
        MyFile.close();
    }
}

void ShowAddNewClient()
{
    char AddMore = 'y';
    do
    {
        cout << "\n------------------------------------\n";
        cout << "           Add New Client\n";
        cout << "------------------------------------\n";

        sClient Client = ReadNewClient();
        AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));

        cout << "\nClient Added Successfully. Add another? (y/n): ";
        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}

void PrintClientCard(sClient client)
{
    cout << "\nThe following are the client details:\n\n";
    cout << "Account Number  : " << client.Account_Number << endl;
    cout << "Pin Code        : " << client.Pin_Code << endl;
    cout << "Name            : " << client.Name << endl;
    cout << "Phone           : " << client.Phone << endl;
    cout << "Account Balance : " << client.Account_Balance << endl;
}

bool FindClientByAccountNumber(string AccountNumber, vector<sClient> vClients, sClient& Client)
{
    for (sClient C : vClients)
    {
        if (C.Account_Number == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

void ShowFindClientScreen()
{
    cout << "------------------------------------\n";
    cout << "       Find Client Screen\n";
    cout << "------------------------------------\n";

    vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    sClient Client;
    string AccountNumber = ReadClientAccountNumber();

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
        PrintClientCard(Client);
    else
        cout << "\nClient with Account Number[" << AccountNumber << "] is not found!\n";
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClient>& vClients)
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
}

bool DeleteClientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
    sClient Client;
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
        char Answer;
        cout << "\nAre you sure you want to delete this client? (y/n)? ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            SaveVectorToFile(ClientsFileName, vClients);
            cout << "\nClient Deleted Successfully.\n";
            return true;
        }
    }
    else
    {
        cout << "\nClient Not Found!\n";
    }
    return false;
}

void ShowDeleteClientByAccountNumber()
{
    cout << "\n-----------------------------------\n";
    cout << "             Delete Client\n";
    cout << "-----------------------------------\n";

    vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    DeleteClientByAccountNumber(AccountNumber, vClients);
}

sClient ChangeClientRecord(string AccountNumber)
{
    sClient Client;
    Client.Account_Number = AccountNumber;

    cout << "\nEnter New Pin Code: ";
    getline(cin >> ws, Client.Pin_Code);

    cout << "Enter New Name: ";
    getline(cin, Client.Name);

    cout << "Enter New Phone: ";
    getline(cin, Client.Phone);

    cout << "Enter New Balance: ";
    cin >> Client.Account_Balance;

    Client.MarkForDelete = false;
    return Client;
}

bool UpdateClientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
    sClient Client;
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
        char Answer;
        cout << "\nAre you sure you want to update this client? (y/n)? ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
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
            cout << "\nClient Updated Successfully.\n";
        }
    }
    else
    {
        cout << "\nClient Not Found!\n";
    }

    return true;
}

void ShowUpdateClientByAccountNumber()
{
    cout << "\n-----------------------------------\n";
    cout << "             Update Client\n";
    cout << "-----------------------------------\n";

    vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vClients);
}

void ShowEndScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "           Program Ends :-)\n";
    cout << "-----------------------------------\n";
}

enum enMainMenuOption
{
    eListClient = 1, eAddNewClient, eDeleteClient, eUpdateClient, eFindClient, eExit
};

short ReadMainMenuOption()
{
    cout << "\nChoose what do you want to do? [1 to 6]? ";
    short Option;
    cin >> Option;
    return Option;
}

void PerformMainMenuOption(enMainMenuOption MainMenuOption)
{
    switch (MainMenuOption)
    {
    case eListClient:
        system("cls");
        ShowAllClientsData();
        break;
    case eAddNewClient:
        system("cls");
        ShowAddNewClient();
        break;
    case eDeleteClient:
        system("cls");
        ShowDeleteClientByAccountNumber();
        break;
    case eUpdateClient:
        system("cls");
        ShowUpdateClientByAccountNumber();
        break;
    case eFindClient:
        system("cls");
        ShowFindClientScreen();
        break;
    case eExit:
        system("cls");
        ShowEndScreen();
        exit(0);
    default:
        cout << "Invalid choice, please select between 1 and 6.\n";
    }

    cout << "\nPress any key to return to Main Menu...";
    system("pause>0");
}

void ShowMainMenu()
{
    cout << "===========================================\n";
    cout << "              Main Menu Screen\n";
    cout << "===========================================\n";
    cout << "     [1] Show Client List.\n";
    cout << "     [2] Add New Client.\n";
    cout << "     [3] Delete Client.\n";
    cout << "     [4] Update Client Info.\n";
    cout << "     [5] Find Client.\n";
    cout << "     [6] Exit.\n";
    cout << "===========================================\n";
}

int main()
{
    while (true)
    {
        system("cls");
        ShowMainMenu();
        PerformMainMenuOption((enMainMenuOption)ReadMainMenuOption());
    }
    return 0;
}