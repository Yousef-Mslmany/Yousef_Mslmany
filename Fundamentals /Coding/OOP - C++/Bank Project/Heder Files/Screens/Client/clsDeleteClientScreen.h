#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"

class clsDeleteClientScreen: protected clsScreen
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

    static void ShowDeleteClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            return;
        }

        _DrawScreenHeader("\tDelete Client Screen");


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

        char Answer = 'n';
        cout << "\nAre you sure you want to delete this client? (y/n)? ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            if (Client1.Delete())
            {
                cout << "\nClient Delete Successfully :-)\n";

                _PrintClient(Client1);
            }
            else
            {
                cout << "\nError Client Was not Delete\n";
            }

        }
    }
};

