#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

class clsUpdateUserScreen : protected clsScreen
{
private:
    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter First Name: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter Last Name: ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Password: ";
        User.Password = clsInputValidate::ReadString();

        cout << "\nEnter Permissions: ";
        User.Permissions = _ReadPermissionsToSet();
    }

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

    static int _ReadPermissionsToSet()
    {
        int Permissions = 0;
        char Answer = 'y';

        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            return -1;

        cout << "\nDo you want to give access to : \n";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions += clsUser::enPermissions::pListClients;

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions += clsUser::enPermissions::pAddNewClient;

        cout << "\nDelet Client? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions += clsUser::enPermissions::pDeleteClient;

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions += clsUser::enPermissions::pUpdateClients;

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions += clsUser::enPermissions::pFindClient;

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions += clsUser::enPermissions::pTranactions;

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions += clsUser::enPermissions::pManageUsers;

        cout << "\nLogin Register? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions += clsUser::enPermissions::pShowLoginRegister;

        return Permissions;
    }

public:
    static void ShowUpdateClientScreen()
    {
        _DrawScreenHeader("\tUpdate User Screen");

        string UserName = "";

        cout << "\nPlease Enter User Name: ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser Name is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);
        _PrintUser(User1);

        char Answer = 'n';
        cout << "\nAre you sure you want to delete this client? (y/n)? ";
        cin >> Answer;

        if (toupper(Answer) == 'Y' )
        {
            cout << "\n\nUpdate User Info:";
            cout << "\n____________________\n";


            _ReadUserInfo(User1);

            clsUser::enSaveResults SaveResult;

            SaveResult = User1.Save();

            switch (SaveResult)
            {
            case  clsUser::enSaveResults::svSucceeded:
            {
                cout << "\nUser Updated Successfully :-)\n";
                _PrintUser(User1);
                break;
            }
            case clsUser::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError User was not saved because it's Empty";
                break;
            }

            }
        }
        
    }
};

