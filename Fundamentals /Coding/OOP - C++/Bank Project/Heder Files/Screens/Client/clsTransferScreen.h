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

class clsTransferScreen: protected clsScreen
{
private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber(string Destination)
    {
        string AccountNumber = "";

        cout << "\nPlease Enter Account Number to Transfer " << Destination << " : ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        return AccountNumber;
    }

    static float ReadAmount(clsBankClient SourceClient)
    {
        float Amount = 0;
        cout << "\nEnter Transfer Amount? ";
        Amount = clsInputValidate::ReadNumber<double>();

        while (Amount > SourceClient.AccountBalance)
        {
            cout << "\nAmount Exceeds the available Balance, Enter another Amount ?";
            Amount = clsInputValidate::ReadNumber<double>();
        }

        return Amount;
    }

public:
	static void ShowTransferScreen()
	{

		_DrawScreenHeader("\t   Transfer Screen");

        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("From"));

        _PrintClient(SourceClient);

        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("To"));

        _PrintClient(DestinationClient);

        float Amount = ReadAmount(SourceClient);

        char Answer = 'n';
        cout << "\nAre you sure you want to perform this operation? y/n? ";
        cin >> Answer;
        
        if (Answer == 'y' || Answer == 'Y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.UserName))
            {
                cout << "\nTransfer done successfully\n";
                _PrintClient(SourceClient);
                _PrintClient(DestinationClient);
            }
            else
            {
                cout << "\nTransfer Failed \n";
            }
        } 
	}


};

