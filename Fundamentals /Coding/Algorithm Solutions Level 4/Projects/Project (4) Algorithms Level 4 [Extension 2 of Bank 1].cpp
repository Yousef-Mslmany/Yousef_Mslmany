#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;


enum enMainMenuOptions
{
    eListClient = 1, eAddNewClient = 2, eDeleteClient = 3,
    eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenu = 6, eShowManageUsers = 7, eLogout = 8
};

enum enMainMenuPermissions
{
    eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
    pUpdateClients = 8, pFindClient = 16, pTransactions = 32, pManageUsers = 64
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

struct stUser
{
    string Name;
    string Password;
    short Permissions = 0;
    bool MarkForDelete = false;
};

stUser CurrentUser;

const string ClientsFileName = "Clients.txt";
const string UsersFileName = "Users.txt";

short ReadMainMenuOption();
void PerformMainMenuOption(enMainMenuOptions MainMenuOption);
void ShowMainMenu();

void ShowTransactionsMenu();

void Login();
vector<stUser> LoadUsersDateFromFile(string FileName);
void ShowMangeUsersMenue();
bool FindUserByUsername(string Username, const vector<stUser>& vUser, stUser& User);
void PrintUserCard(const stUser& User);
int ReadPermissionsToSet();
void SaveUserToFile(string FileName, vector<stUser> vUsers);
void ShowAccessDeniedMessage();
string ReadUserName();

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

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
    return Client.Account_Number + Seperator + Client.Pin_Code + Seperator +
        Client.Name + Seperator + Client.Phone + Seperator +
        to_string(Client.Account_Balance);
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

bool CheckAccessPermission(enMainMenuPermissions Permission)
{
    if (CurrentUser.Permissions == enMainMenuPermissions::eAll)
        return true;

    if ((Permission & CurrentUser.Permissions) == Permission)
        return true;
    else
        return false;
}

void ShowAllClientsScreen()
{

    if (!CheckAccessPermission(enMainMenuPermissions::pListClients))
    {
        ShowAccessDeniedMessage();
        return;
    }

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
    cout << "\n------------------------------------\n";
    cout << "           Add New Client\n";
    cout << "------------------------------------\n";
}

void AddNewClientScreen()
{
    if (!CheckAccessPermission(enMainMenuPermissions::pAddNewClient))
    {
        ShowAccessDeniedMessage();
        return;
    }

    char AddMore = 'y';
    ShowAddNewClientScreen();
    do
    {
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
    if (!CheckAccessPermission(enMainMenuPermissions::pFindClient))
    {
        ShowAccessDeniedMessage();
        return;
    }

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
            SaveClientsDataToFile(ClientsFileName, vClients);
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
    if (!CheckAccessPermission(enMainMenuPermissions::pDeleteClient))
    {
        ShowAccessDeniedMessage();
        return;
    }

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
            SaveClientsDataToFile(ClientsFileName, vClients);
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
    if (!CheckAccessPermission(enMainMenuPermissions::pUpdateClients))
    {
        ShowAccessDeniedMessage();
        return;
    }

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
                    SaveClientsDataToFile(ClientsFileName, vClients);
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

bool DepositBalanceToClientByAccountNumber(string AccountNumber,double Amount, vector<sClient>& vClients)
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

void ShowDepositScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "            Deposit Screen\n";
    cout << "-----------------------------------\n";

    sClient Client;
    vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();

    while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        AccountNumber = ReadClientAccountNumber();
    }

    PrintClientCard(Client);

    double Amount = 0;
    cout << "\nPlease enter deposit amount? ";
    cin >> Amount;

    DepositBalanceToClientByAccountNumber(AccountNumber, Amount, vClients);
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
    if (!CheckAccessPermission(enMainMenuPermissions::pTransactions))
    {
        ShowAccessDeniedMessage();
        return;
    }

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

void GoBackToManageUsersMenu()
{
    cout << "\n\nPress any key to go back to Mange Users Menu...";
    system("pause>0");
    system("cls");
    ShowMangeUsersMenue();
}

string ConvertUserRecordToLine(stUser User, string Seperator = "#//#")
{
    return User.Name + Seperator + User.Password + Seperator +
        to_string(User.Permissions);
}

void ShowFindUserScreen()
{
    cout << "\n------------------------------------\n";
    cout << "          Find User Screen\n";
    cout << "------------------------------------\n";
    vector<stUser> vUsers = LoadUsersDateFromFile(UsersFileName);
    stUser User;
    string UserName = ReadUserName();
    if (FindUserByUsername(UserName, vUsers, User))
        PrintUserCard(User);
    else
        cout << "\nClient with Account Number [" << UserName << "] not found!\n";
}

stUser ChangeUserRecord(string UserName)
{
    stUser User;
    User.Name = UserName;
    cout << "\nEnter New Password: ";
    getline(cin >> ws, User.Password);
    ReadPermissionsToSet();
    return User;
}

bool UpdateUserByUsername(string UserName, vector<stUser>& vUsers)
{
    stUser User;
    if (FindUserByUsername(UserName, vUsers, User))
    {
        PrintUserCard(User);
        char Answer;
        cout << "\nAre you sure you want to update this User? (y/n)? ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            for (auto& C : vUsers)
                if (C.Name == UserName)
                {
                    C = ChangeUserRecord(UserName);
                    break;
                }
            SaveUserToFile(UsersFileName, vUsers);
            cout << "\nUser Updated Successfully.\n";
        }
    }
    else
    {
        cout << "\nUser Not Found!\n";
    }
    return true;
}

string ReadUserName()
{
    string UserName;
    cout << "Please Enter Username? ";
    cin >> UserName;
    return UserName;
}

void ShowUpdateUserScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "         Update User Screen\n";
    cout << "-----------------------------------\n";
    vector<stUser> vUsers = LoadUsersDateFromFile(UsersFileName);
    string UserName = ReadUserName();
    UpdateUserByUsername(UserName, vUsers);
}

void SaveUserToFile(string FileName, vector<stUser> vUsers)
{
    fstream MyFile(FileName, ios::out);
    if (MyFile.is_open())
    {
        for (stUser C : vUsers)
            if (!C.MarkForDelete)
                MyFile << ConvertUserRecordToLine(C) << endl;
        MyFile.close();
    }
}

bool MarkUserForDeleteByUsername(string UserName, vector<stUser>& vUsers)
{
    for (auto& C : vUsers)
        if (C.Name == UserName)
        {
            C.MarkForDelete = true;
            return true;
        }
    return false;
}

void PrintUserCard(const stUser& User)
{
    cout << "\nThe following are the User details:\n";
    cout << "---------------------------------------\n";
    cout << "Username     : " << User.Name << endl;
    cout << "Password     : " << User.Password << endl;
    cout << "Permissions  : " << User.Permissions << endl;
    cout << "---------------------------------------\n";
}

bool FindUserByUsername(string Username, const vector<stUser>& vUser, stUser& User)
{
    for (auto& C : vUser)
        if (C.Name == Username)
        {
            User = C;
            return true;
        }
    return false;
}

bool DeleteUserByUsername(string UserName, vector<stUser>& vUsers)
{
    stUser User;

    if (UserName == "Admin")
    {
        cout << "\nYou cannot Delete This User.";
        GoBackToManageUsersMenu();
    }

    if (FindUserByUsername(UserName, vUsers, User))
    {
        PrintUserCard(User);
        char Answer;
        cout << "\nAre you sure you want to delete this User? (y/n)? ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            MarkUserForDeleteByUsername(UserName, vUsers);
            SaveUserToFile(UsersFileName, vUsers);
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

void ShowDeleteUserScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "        Delete User Screen\n";
    cout << "-----------------------------------\n";
    vector<stUser> Users = LoadUsersDateFromFile(UsersFileName);
    string Username = ReadUserName();
    DeleteUserByUsername(Username, Users);
}

stUser ConvertUserLinetoRecord(string Line, string Seperator = "#//#")
{
    stUser User;
    vector<string> vUserData = SplitString(Line, Seperator);

        User.Name = vUserData[0];
        User.Password = vUserData[1];
        User.Permissions = stoi(vUserData[2]);

    return User;
}

bool UserExistsByUsername(string Username, string FileName)
{
    fstream MyFile(FileName, ios::in);
    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            stUser User = ConvertUserLinetoRecord(Line);
            if (User.Name == Username)
            {
                MyFile.close();
                return true;
            }
        }
        MyFile.close();
    }
    return false;
}

char ReadAnswer(string Message)
{
    char Answer;
    cout << Message;
    cin >> Answer;
    return Answer;
}

int ReadPermissionsToSet()
{
    int Permissions = 0;
    char Answer = 'y';

    Answer = ReadAnswer("\nDo you want to give full access? y/n? ");
    if (toupper(Answer) == 'Y')
        return -1;
   
    cout << "\nDo you want to give access to : \n";

    Answer = ReadAnswer("\nShow Client List? y/n? ");
    if (toupper(Answer) == 'Y')
        Permissions += enMainMenuPermissions::pListClients;

    Answer = ReadAnswer("\nAdd New Client? y/n? ");
    if (toupper(Answer) == 'Y')
        Permissions += enMainMenuPermissions::pAddNewClient;

    Answer = ReadAnswer("\nDelet Client? y/n? ");
    if (toupper(Answer) == 'Y')
        Permissions += enMainMenuPermissions::pDeleteClient;

    Answer = ReadAnswer("\nUpdate Client? y/n? ");
    if (toupper(Answer) == 'Y')
        Permissions += enMainMenuPermissions::pUpdateClients;

    Answer = ReadAnswer("\nFind Client? y/n? ");
    if (toupper(Answer) == 'Y')
        Permissions += enMainMenuPermissions::pFindClient;

    Answer = ReadAnswer("\nTransactions? y/n? ");
    if (toupper(Answer) == 'Y')
        Permissions += enMainMenuPermissions::pTransactions;

    Answer = ReadAnswer("\nManage Users? y/n? ");
    if (toupper(Answer) == 'Y')
        Permissions += enMainMenuPermissions::pManageUsers;

    return Permissions;
}

stUser ReadNewUser()
{
    stUser User;
    cout << "\nEnter Username? ";
    getline(cin >> ws, User.Name);
    while (UserExistsByUsername(User.Name, UsersFileName))
    {
        cout << "\nUser with [" << User.Name << "] already exists, Enter another Username? ";
        getline(cin >> ws, User.Name);
    }
    cout << "Enter Password: ";
    getline(cin, User.Password);

    User.Permissions = ReadPermissionsToSet();

    return User;
}

void ShowAddNewUserScreen()
{
    cout << "\n------------------------------------\n";
    cout << "           Add New User\n";
    cout << "------------------------------------\n";
}

void AddNewUserScreen()
{
    char AddMore = 'y';
    ShowAddNewUserScreen();
    do
    {
        stUser User = ReadNewUser();
        AddDataLineToFile(UsersFileName, ConvertUserRecordToLine(User));
        cout << "\nUser Added Successfully. Add another? (y/n): ";
        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}

void PrintUserRecord(stUser User)
{
    cout << "| " << setw(15) << left << User.Name
        << "| " << setw(10) << left << User.Password
        << "| " << setw(8) << left << User.Permissions << endl;
}

void ShowListUsersScreen()
{
    vector <stUser> vUsers = LoadUsersDateFromFile(UsersFileName);
    cout << "\n\t\t\t\t\tUser List (" << vUsers.size() << ") User(s)\t\t\t\t\t\n";
    cout << "\n________________________________________________________________________________________________\n";

    cout << "| " << left << setw(15) << "User Name";
    cout << "| " << left << setw(10) << "Password";
    cout << "| " << left << setw(5) << "Permissions";

    cout << "\n________________________________________________________________________________________________\n";

    if (vUsers.empty())
        cout << "\t\t\tNo Users Available In the System!\n";
    else
        for (stUser User : vUsers)
            PrintUserRecord(User);

    cout << "\n________________________________________________________________________________________________\n";
}

enum enManageUsersMenuOptions
{
    eListUsers = 1, eAddNewUsers = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eMainMenu = 6
};

short ReadMangeUsersMenuOption()
{
    cout << "\nChoose what to do? [1 to 6]: ";
    short Option;
    cin >> Option;
    return Option;
}

void PerformManageUsersMenuOption(enManageUsersMenuOptions ManageUsersMenuOptions)
{
    switch (ManageUsersMenuOptions)
    {
    case enManageUsersMenuOptions::eListUsers:
    {
        system("cls");
        ShowListUsersScreen();
        GoBackToManageUsersMenu();
        break;
    }
    case enManageUsersMenuOptions::eAddNewUsers:
    {
        system("cls");
        AddNewUserScreen();
        GoBackToManageUsersMenu();
        break;
    }
    case enManageUsersMenuOptions::eDeleteUser:
    {
        system("cls");
        ShowDeleteUserScreen();
        GoBackToManageUsersMenu();
        break;
    }
    case enManageUsersMenuOptions::eUpdateUser:
    {
        system("cls");
        ShowUpdateUserScreen();
        GoBackToManageUsersMenu();
        break;
    }
    case enManageUsersMenuOptions::eFindUser:
    {
        system("cls");
        ShowFindUserScreen();
        GoBackToManageUsersMenu();
        break;
    }
    case enManageUsersMenuOptions::eMainMenu:
    {
        ShowMainMenu();
    }
    }
}

void ShowMangeUsersMenue()
{
    if (!CheckAccessPermission(enMainMenuPermissions::pManageUsers))
    {
        ShowAccessDeniedMessage();
        return;
    }

    system("cls");
    cout << "===========================================\n";
    cout << "\tMange Users Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] List Users.\n";
    cout << "\t[2] Add New User.\n";
    cout << "\t[3] Delete User.\n";
    cout << "\t[4] Update User.\n";
    cout << "\t[5] Find User.\n";
    cout << "\t[6] Main Menu.\n";
    cout << "===========================================\n";
    PerformManageUsersMenuOption((enManageUsersMenuOptions)ReadMangeUsersMenuOption());
}

short ReadMainMenuOption()
{
    cout << "\nChoose what to do? [1 to 8]: ";
    short Option;
    cin >> Option;
    return Option;
}

void ShowAccessDeniedMessage()
{
    system("cls");
    cout << "\n------------------------------------\n";
    cout << "Access Denied,\n";
    cout << "You dont Have Permission To Do this,\n";
    cout << "Please Conact Your Admin.\n";
    cout << "------------------------------------\n";

    GoBackToMainMenu();

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
            AddNewClientScreen();
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
    case enMainMenuOptions::eShowManageUsers:
            system("cls");
            ShowMangeUsersMenue();
            GoBackToManageUsersMenu();
            break;
    case enMainMenuOptions::eLogout:
        system("cls");
        Login();
        break;
    default:
        cout << "Invalid choice, select between 1 and 8.\n";
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
    cout << "\t[7] Manage Users.\n";
    cout << "\t[8] Logout.\n";
    cout << "===========================================\n";

    PerformMainMenuOption((enMainMenuOptions)ReadMainMenuOption());
}

vector<stUser> LoadUsersDateFromFile(string FileName)
{
    vector<stUser> vUser;
    fstream MyFile(FileName, ios::in);
    if (MyFile.is_open())
    {
        string line;
        while (getline(MyFile, line))
            vUser.push_back(ConvertUserLinetoRecord(line));
        MyFile.close();
    }
    return vUser;
}

bool FindUserByUsernameAndPassword(string Username, string Password, stUser& User)
{
    vector <stUser> vUsers = LoadUsersDateFromFile(UsersFileName);

    for (stUser U : vUsers)
    {
        if (U.Name == Username && U.Password == Password)
        {
            User = U;
            return true;
        }
    }
    return false;
}

bool LoadUserInfo(string Username, string Password)
{
    if (FindUserByUsernameAndPassword(Username, Password, CurrentUser))
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
    string Username, Password;

    do
    {
        LoginScreen();

        if (LoginFaild)
        {
            cout << "Invlaid Username/Password!\n";
        }

        cout << "Enter Username? ";
        cin >> Username;

        cout << "Enter Password? ";
        cin >> Password;

        LoginFaild = !LoadUserInfo(Username, Password);

    } while (LoginFaild);

    ShowMainMenu();
}

int main()
{
    Login();

    system("pause>0");
    return 0;
}
