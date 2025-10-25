#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Client
{
    string Account_Number;
    string Pin_Code;
    string Name, Phone;
    int Account_Balance;
};

vector<string> split(string S1, string Delim)
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

Client ConvertLineToRecord(string Line, string Seperator = "#//#") 
{
    Client client;
    vector<string> vClientData = split(Line, Seperator);
    client.Account_Number = vClientData[0];
    client.Pin_Code = vClientData[1];
    client.Name = vClientData[2];
    client.Phone = vClientData[3];
    client.Account_Balance = stoi(vClientData[4]);
    return client;
}

void PrintNewClient(Client client) 
{
    cout << "\n\nThe following is the extracted client record:\n\n";
    cout << "Account Number: " << client.Account_Number << endl;
    cout << "Pin Code: " << client.Pin_Code << endl;
    cout << "Name: " << client.Name << endl;
    cout << "Phone: " << client.Phone << endl;
    cout << "Account Balance: " << client.Account_Balance << endl;
}

int main() 
{
    string stLine = "A150#//#1234#//#Yousef Mslmany#//#0937053132#//#5270";
    cout << "Line Record is:\n" << stLine;
    Client client = ConvertLineToRecord(stLine);
    PrintNewClient(client);
    return 0;
}