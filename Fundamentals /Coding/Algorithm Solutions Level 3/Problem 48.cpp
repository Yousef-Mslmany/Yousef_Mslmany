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

void PrintClientRecord(sClient Client)
{
    cout << "| " << setw(15)<< left << Client.Account_Number;
    cout << "| " << setw(10)<< left << Client.Pin_Code;
    cout << "| " << setw(40)<< left << Client.Name;
    cout << "| " << setw(12)<< left << Client.Phone;
    cout << "| " << setw(12)<< left << Client.Account_Balance;
}

void PrintAllClientsData(vector <sClient> vClients)
{
    cout << "\n\t\t\t\t\t\tClient List ("<< vClients.size() <<") Client(s)\t\t\t\t\t\n";
    cout << "\n________________________________________________________________________________________________________________________\n";
    
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";

    cout << "\n________________________________________________________________________________________________________________________\n";

    for (sClient Client : vClients)
    {
        PrintClientRecord(Client);
        cout << endl;

    }

    cout << "\n________________________________________________________________________________________________________________________\n";

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

int main()
{
    vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    PrintAllClientsData(vClients);

    return 0;
}