#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsDeletUserScreen: protected clsScreen 
{
private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

public:
    static void ShowDeletUserScreen()
    {

        _DrawScreenHeader("\t Delete User Screen");

        cout << "\nPlease Enter User Name: ";
        string UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser Is Not Found, Choose Another One: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);

        _PrintUser(User1);

        char Answer = 'n';
        cout << "\nAre you sure you want to delete this client? (y/n)? ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            if (User1.Delete())
            {
                cout << "\nUser Delete Successfully :-)\n";

                _PrintUser(User1);
            }
            else
            {
                cout << "\nError User Was not Delete\n";
            }

        }
    }
};