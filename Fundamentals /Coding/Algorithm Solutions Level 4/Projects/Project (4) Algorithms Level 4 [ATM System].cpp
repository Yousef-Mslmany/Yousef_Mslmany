#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

enum enMainMenuOptions
{
    eQuickWithdraw = 1, eNormalWithdraw = 2, eDeposit = 3,
    eCheckBalance = 4, eLogout = 5
};

enum enQuickWithdrawOptions
{
    enOption1 = 1, enOption2 = 2, enOption3 = 3, enOption4 = 4,
    enOption5 = 5, enOption6 = 6, enOption7 = 7, enOption8 = 8,
    eExit = 9
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

sClient CurrentClient;

void ShowMainMenu();
void ShowQuickWithdrawScreen();
void ShowNormalWithdrawScreen();
void Login();
const string ClientsFileName = "Clients.txt";

vector<string> SplitString(string S1, string Delim)
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

sClient ConvertLineToRecord(string Line, string Seperator = "#//#")
{
    sClient Client;
    vector<string> vClientData = SplitString(Line, Seperator);
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

vector<sClient> LoadClientsDataFromFile(string FileName)
{
    vector<sClient> vClient;
    fstream MyFile(FileName, ios::in);
    if (MyFile.is_open())
    {
        string line;
        while (getline(MyFile, line))
            vClient.push_back(ConvertLineToRecord(line));
        MyFile.close();
    }
    return vClient;
}

void GoBackToMainMenu()
{
    cout << "\n\nPress any key to go back to ATM Main Menu...";
    system("pause>0");
    ShowMainMenu();
}

short ReadQuickWithdrawOption()
{
    short Choice = 0;
    while (Choice < 1 || Choice > 9)
    {
        cout << "\nChoose What to do from [1] to [9] ? ";
        cin >> Choice;
    }

    return Choice;
}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
    return Client.Account_Number + Seperator + Client.Pin_Code + Seperator +
        Client.Name + Seperator + Client.Phone + Seperator +
        to_string(Client.Account_Balance);
}

void SaveClientsDataToFile(string FileName, vector<sClient> vClients)
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

bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector<sClient>& vClients)
{

    char Answer = 'n';

    cout << "\n\nAre you sure you want perform this transaction? y/n ?";
    cin >> Answer;
    if (toupper(Answer) == 'Y')
    {
        for (sClient& C : vClients)
            if (C.Account_Number == AccountNumber)
            {
                C.Account_Balance += Amount;
                SaveClientsDataToFile(ClientsFileName, vClients);
                cout << "\nDone Successfully. New Balance is: " << C.Account_Balance << endl;

                return true;
            }
        return false;
    }

}

short GetQuickWithDrawAmount(short QuickWithdrawOption)
{
    switch (QuickWithdrawOption)
    {
    case 1:
        return 20;
    case 2:
        return 50;
    case 3:
        return 100;
    case 4:
        return 200;
    case 5:
        return 400;
    case 6:
        return 600;
    case 7:
        return 800;
    case 8:
        return 1000;
    default:
        return 0;
    }
}

void PerformQuickMenuOption(short QuickWithdrawOption)
{
    if (QuickWithdrawOption == 9)
        return;

    short WithDrawBalance = GetQuickWithDrawAmount(QuickWithdrawOption);

    if (WithDrawBalance > CurrentClient.Account_Balance)
    {
        cout << "\n\nThe amount exceeds your balance, Make another choice. ";
        cout << "\nPress any key to countinue...";
        system("pause>0");
        ShowQuickWithdrawScreen();
        return;
    }

    vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    DepositBalanceToClientByAccountNumber(CurrentClient.Account_Number, WithDrawBalance * -1, vClients);
    CurrentClient.Account_Balance -= WithDrawBalance;
}

void ShowQuickWithdrawScreen()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tQuick Withdraw\n";
    cout << "===========================================\n";
    cout << "\t[1] 20  \t [2] 50\n";
    cout << "\t[3] 100 \t [4] 200\n";
    cout << "\t[5] 400 \t [6] 600\n";
    cout << "\t[7] 800 \t [8] 1000\n";
    cout << "\t[9] Exit\n";
    cout << "===========================================\n";
    cout << "Your Balance is " << CurrentClient.Account_Balance;
    PerformQuickMenuOption(ReadQuickWithdrawOption());
}

int ReadWithDrawAmount()
{
    int Amount;
    cout << "\nEnter an amount multiple of 5's ? ";

    cin >> Amount;
    while (Amount % 5 != 0)
    {
        cout << "\nEnter an amount multiple of 5's ? ";
        cin >> Amount;
    }
    return Amount;
}

void PerformNormalWithdrawOption()
{
    int WithDrawBalance = ReadWithDrawAmount();

    if (WithDrawBalance > CurrentClient.Account_Balance)
    {
        cout << "\n\nThe amount exceeds your balance, Make another choice. ";
        cout << "\nPress any key to countinue...";
        system("pause>0");
        ShowNormalWithdrawScreen();
        return;
    }

    vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    DepositBalanceToClientByAccountNumber(CurrentClient.Account_Number, WithDrawBalance * -1, vClients);
    CurrentClient.Account_Balance -= WithDrawBalance;
}

void ShowNormalWithdrawScreen()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\tNormal Withdraw Screen\n";
    cout << "===========================================\n";
    PerformNormalWithdrawOption();
}

double ReadDepositAmount()
{
    double Amount;
    cout << "\nEnter a Positive Deposit Amount? ";

    cin >> Amount;
    while (Amount<=0)
    {
        cout << "\nEnter a Positive Deposit Amount? ";
        cin >> Amount;
    }
    return Amount;
}

void PerformDepositOption()
{
    double DepositAmount = ReadDepositAmount();
    
    vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    DepositBalanceToClientByAccountNumber(CurrentClient.Account_Number, DepositAmount, vClients);
    CurrentClient.Account_Balance += DepositAmount;
}

void ShowDepositScreen()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tDeposit Screen\n";
    cout << "===========================================\n";
    PerformDepositOption();
}

void ShowCheckBalanceScreen()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\tCheck Balance Screen\n";
    cout << "===========================================\n";
    cout << "Your Balance is " << CurrentClient.Account_Balance;
}

void PerformMainMenuOption(enMainMenuOptions MainMenuOption)
{

    switch (MainMenuOption)
    {
    case enMainMenuOptions::eQuickWithdraw:

        system("cls");
        ShowQuickWithdrawScreen();
        GoBackToMainMenu();
        break;
    case enMainMenuOptions::eNormalWithdraw:
        system("cls");
        ShowNormalWithdrawScreen();
        GoBackToMainMenu();
        break;
    case enMainMenuOptions::eDeposit:
        system("cls");
        ShowDepositScreen();
        GoBackToMainMenu();
        break;
    case enMainMenuOptions::eCheckBalance:
        system("cls");
        ShowCheckBalanceScreen();
        GoBackToMainMenu();
        break;
    case enMainMenuOptions::eLogout:
        system("cls");
        Login();
        break;
    default:
        cout << "Invalid choice, select between 1 and 5.\n";
        GoBackToMainMenu();
        break;
    }
}

short ReadATM_MainMenuOption()
{
    cout << "\nChoose what to do? [1 to 5]: ";
    short Option;
    cin >> Option;
    return Option;
}

void ShowMainMenu()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t ATM Main Menu Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Quick Withdraw.\n";
    cout << "\t[2] Normal Withdraw.\n";
    cout << "\t[3] Deposit.\n";
    cout << "\t[4] Check Balance.\n";
    cout << "\t[5] Logout.\n";
    cout << "===========================================\n";

    PerformMainMenuOption((enMainMenuOptions)ReadATM_MainMenuOption());
}

bool FindUserByAccountAndPinCode(string AccountNumber, string PinCode, sClient& Client)
{
    vector <sClient> vUsers = LoadClientsDataFromFile(ClientsFileName);

    for (sClient C : vUsers)
    {
        if (C.Account_Number == AccountNumber && C.Pin_Code == PinCode)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

bool LoadClientInfo(string AccountNumber, string PinCode)
{
    if (FindUserByAccountAndPinCode(AccountNumber, PinCode, CurrentClient))
        return true;
    else
        return false;

}

void LoginScreen()
{
    system("cls");
    cout << "\n-----------------------------------\n";
    cout << "           Login Screen\n";
    cout << "-----------------------------------\n";
}

void Login()
{
    bool LoginFaild = false;
    string AccountNumber, PinCode;

    do
    {
        LoginScreen();

        if (LoginFaild)
        {
            cout << "Invlaid AccountNumber/PinCode!\n";
        }

        cout << "Enter AccountNumber? ";
        cin >> AccountNumber;

        cout << "Enter PinCode? ";
        cin >> PinCode;

        LoginFaild = !LoadClientInfo(AccountNumber, PinCode);

    } while (LoginFaild);

    ShowMainMenu();
}

int main()
{
    Login();

    system("pause>0");
    return 0;
}
