#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsBankClient.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;

class clsWithdrawScreen : protected clsScreen
{
private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

public:

    static void ShowWithdrawScreen()
    {
        _DrawScreenHeader("\t   Withdraw Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        _PrintClient(Client1);

        double Amount = 0;
        cout << "\nPlease enter Withdraw amount? ";
        Amount = clsInputValidate::ReadNumber<double>();

        char Answer = 'n';
        cout << "\n\nAre you sure you want perform this transaction? y/n ?";
        cin >> Answer;



        if (Answer == 'y' || Answer == 'Y')
        {
            if (Client1.Withdraw(Amount))
            {
            Client1.Withdraw(Amount);
            cout << "\nAmount Withdraw Successfully.\n";
            cout << "\nNew Balance Is: " << Client1.AccountBalance;
            }
            else
            {
                cout << "\nCannot withdraw, Insuffecient Balance!\n";
                cout << "\nAmount to withdraw is: " << Amount;
                cout << "\nYour Balance is: " << Client1.AccountBalance;
            }
        }
        else
        {
            cout << "\nOeration was cancelled.\n";
        }
    }
};

