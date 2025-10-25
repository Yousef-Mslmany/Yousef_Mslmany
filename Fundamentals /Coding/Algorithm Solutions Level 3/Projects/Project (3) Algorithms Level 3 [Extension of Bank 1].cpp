#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

enum enMainMenuOptions
{
    eListClient = 1, eAddNewClient = 2, eDeleteClient = 3,
    eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenu = 6, eExit = 7
};

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

short ReadMainMenuOption();
void PerformMainMenuOption(enMainMenuOptions MainMenuOption);
void ShowMainMenu();
void ShowTransactionsMenu();

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
            if (!C.MarkForDelete)
                MyFile << ConvertRecordToLine(C) << endl;
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
            vClients.push_back(ConvertLineToRecord(line));
        MyFile.close();
    }
    return vClients;
}

void GoBackToTransactionsMenu()
{
    cout << "\n\nPress any key to go back to Transactions Menu...";
    system("pause>0");
    system("cls");
    ShowTransactionsMenu();
}

void GoBackToMainMenu()
{
    cout << "\n\nPress any key to go back to Main Menu...";
    system("pause>0");
    ShowMainMenu();
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
    cout << "| " << setw(15) << left << Client.Account_Number
        << "| " << setw(10) << left << Client.Pin_Code
        << "| " << setw(40) << left << Client.Name
        << "| " << setw(12) << left << Client.Phone
        << "| " << setw(12) << left << Client.Account_Balance << endl;
}

void ShowAllClientsScreen()
{
    vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    cout << "\n\t\t\t\t\t\tClient List (" << vClients.size() << ") Client(s)\t\t\t\t\t\n";
    cout << "\n________________________________________________________________________________________________\n";

    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";

    cout << "\n________________________________________________________________________________________________\n";

    if (vClients.empty())
        cout << "\t\t\tNo Clients Available In the System!\n";
    else
        for (sClient Client : vClients)
            PrintClientRecord(Client);

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

void ShowAddNewClientScreen()
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

void PrintClientCard(const sClient& client)
{
    cout << "\nClient details:\n";
    cout << "Account Number  : " << client.Account_Number << endl;
    cout << "Pin Code        : " << client.Pin_Code << endl;
    cout << "Name            : " << client.Name << endl;
    cout << "Phone           : " << client.Phone << endl;
    cout << "Account Balance : " << client.Account_Balance << endl;
}

bool FindClientByAccountNumber(string AccountNumber, const vector<sClient>& vClients, sClient& Client)
{
    for (auto& C : vClients)
        if (C.Account_Number == AccountNumber)
        {
            Client = C;
            return true;
        }
    return false;
}

void ShowFindClientScreen()
{
    cout << "\n------------------------------------\n";
    cout << "       Find Client\n";
    cout << "------------------------------------\n";
    vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    sClient Client;
    string AccountNumber = ReadClientAccountNumber();
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
        PrintClientCard(Client);
    else
        cout << "\nClient with Account Number [" << AccountNumber << "] not found!\n";
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
    for (auto& C : vClients)
        if (C.Account_Number == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
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

void ShowDeleteClientScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "           Delete Client\n";
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
            for (auto& C : vClients)
                if (C.Account_Number == AccountNumber)
                {
                    C = ChangeClientRecord(AccountNumber);
                    break;
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

void ShowUpdateClientScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "           Update Client\n";
    cout << "-----------------------------------\n";
    vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vClients);
}

void TotalBalances(const vector<sClient>& vClients)
{
    double total = 0;
    for (auto& C : vClients)
        total += C.Account_Balance;
    cout << "\t\t\t\t\t\tTotal Balance = " << total << endl;
}

void PrintClientRecordBalanceLine(const sClient& Client)
{
    cout << "| " << setw(15) << left << Client.Account_Number
        << "| " << setw(40) << left << Client.Name
        << "| " << setw(12) << left << Client.Account_Balance << endl;
}

void ShowTotalBalancesScreen()
{
    vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    cout << "\n\t\t\t\tBalances List (" << vClients.size() << ") Client(s).\n";
    cout << "\n________________________________________________________________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n________________________________________________________________________________________________\n" << endl;

    double TotalBalances = 0;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else
        for (sClient Client : vClients)
        {
            PrintClientRecordBalanceLine(Client);
            TotalBalances += Client.Account_Balance;

            cout << endl;
        }
    cout << "\n________________________________________________________________________________________________\n" << endl;
    cout << "\t\t\t\t\t   Total Balances = " << TotalBalances;
}

bool WithdrawByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
    sClient Client;
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
        double WithdrawAmount = 0;
        cout << "\nEnter withdrawal amount: ";
        cin >> WithdrawAmount;

        for (auto& C : vClients)
            if (C.Account_Number == AccountNumber)
            {
                while (WithdrawAmount > C.Account_Balance)
                {
                    cout << "\nAmount exceeds balance (" << C.Account_Balance << "). Enter new amount: ";
                    cin >> WithdrawAmount;
                }
                break;
            }

        char Answer;
        cout << "\nConfirm transaction? (y/n): ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            for (auto& C : vClients)
                if (C.Account_Number == AccountNumber)
                {
                    C.Account_Balance -= WithdrawAmount;
                    SaveVectorToFile(ClientsFileName, vClients);
                    cout << "\nDone. New Balance = " << C.Account_Balance << endl;
                    break;
                }
        }
    }
    else
    {
        cout << "\nClient [" << AccountNumber << "] does not exist.\n";
    }
    return true;
}

void ShowWithdrawScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "           Withdraw Screen\n";
    cout << "-----------------------------------\n";
    vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    WithdrawByAccountNumber(AccountNumber, vClients);
}

bool DepositByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
    sClient Client;
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
        double DepositAmount = 0;
        cout << "\nEnter deposit amount: ";
        cin >> DepositAmount;

        char Answer;
        cout << "\nConfirm transaction? (y/n): ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            for (auto& C : vClients)
                if (C.Account_Number == AccountNumber)
                {
                    C.Account_Balance += DepositAmount;
                    SaveVectorToFile(ClientsFileName, vClients);
                    cout << "\nDone. New Balance = " << C.Account_Balance << endl;
                    break;
                }
        }
    }
    else
    {
        cout << "\nClient [" << AccountNumber << "] does not exist.\n";
    }
    return true;
}

void ShowDepositScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "            Deposit Screen\n";
    cout << "-----------------------------------\n";
    vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    DepositByAccountNumber(AccountNumber, vClients);
}

enum enTransactionsMenuOptions
{
    eDeposit = 1, eWithdraw = 2, eShowTotalBalances = 3, eShowMainMenu = 4
};

short ReadTransactionsMenuOption()
{
    cout << "\nChoose what to do? [1 to 4]: ";
    short Option;
    cin >> Option;
    return Option;
}

void PerformTransactionsMenuOption(enTransactionsMenuOptions TransactionMenuOption)
{
    switch (TransactionMenuOption)
    {
    case enTransactionsMenuOptions::eDeposit:
    {
        system("cls");
        ShowDepositScreen();
        GoBackToTransactionsMenu();
        break;
    }
    case enTransactionsMenuOptions::eWithdraw:
    {
        system("cls");
        ShowWithdrawScreen();
        GoBackToTransactionsMenu();
        break;
    }
    case enTransactionsMenuOptions::eShowTotalBalances:
    {
        system("cls");
        ShowTotalBalancesScreen();
        GoBackToTransactionsMenu();
        break;
    }
    case enTransactionsMenuOptions::eShowMainMenu:
    {
        ShowMainMenu();
    }
    }
}

void ShowTransactionsMenu()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tTransactions Menu\n";
    cout << "===========================================\n";
    cout << "\t[1] Deposit.\n";
    cout << "\t[2] Withdraw.\n";
    cout << "\t[3] Total Balances.\n";
    cout << "\t[4] Main Menu.\n";
    cout << "===========================================\n";
    PerformTransactionsMenuOption((enTransactionsMenuOptions)ReadTransactionsMenuOption());
}

void ShowEndScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "           Program Ends :-)\n";
    cout << "-----------------------------------\n";
}

short ReadMainMenuOption()
{
    cout << "\nChoose what to do? [1 to 7]: ";
    short Option;
    cin >> Option;
    return Option;
}

void PerformMainMenuOption(enMainMenuOptions MainMenuOption)
{
    switch (MainMenuOption)
    {
    case enMainMenuOptions::eListClient:
        system("cls");
        ShowAllClientsScreen();
        GoBackToMainMenu();
        break;
    case enMainMenuOptions::eAddNewClient:
        system("cls");
        ShowAddNewClientScreen();
        GoBackToMainMenu();
        break;
    case enMainMenuOptions::eDeleteClient:
        system("cls");
        ShowDeleteClientScreen();
        GoBackToMainMenu();
        break;
    case enMainMenuOptions::eUpdateClient:
        system("cls");
        ShowUpdateClientScreen();
        GoBackToMainMenu();
        break;
    case enMainMenuOptions::eFindClient:
        system("cls");
        ShowFindClientScreen();
        GoBackToMainMenu();
        break;
    case enMainMenuOptions::eShowTransactionsMenu:
        system("cls");
        ShowTransactionsMenu();
        break;
    case enMainMenuOptions::eExit:
        system("cls");
        ShowEndScreen();
        break;
    default:
        cout << "Invalid choice, select between 1 and 7.\n";
        GoBackToMainMenu();
        break;
    }
}

void ShowMainMenu()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t   Main Menu Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Show Client List.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client Info.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Transactions.\n";
    cout << "\t[7] Exit.\n";
    cout << "===========================================\n";
    
    PerformMainMenuOption((enMainMenuOptions)ReadMainMenuOption());
}

int main()
{

    ShowMainMenu();
    system("pause>0");
    return 0;
}
