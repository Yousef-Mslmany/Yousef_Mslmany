#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeletUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
using namespace std;
class clsManageUsersScreen: protected clsScreen
{
private:
    enum enManageUsersMenuOptions
    {
        eListUsers = 1, eAddNewUsers = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eMainMenu = 6
    };

    static short _ReadMangeUsersMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what to do? [1 to 6]: ";
        short Option = clsInputValidate::ReadNumberBetween<short>(1, 6, "Enter Number between 1 to 4");
        return Option;
    }

    static void GoBackToManageUsersMenu()
    {
        cout << "\n\nPress any key to go back to Mange Users Menu...";
        system("pause>0");
        system("cls");
        ShowManageUsersMenue();
    }

    static void _ShowListUsersScreen()
    {
        clsListUsersScreen::ShowUsersList();
    }

    static void _AddNewUserScreen()
    {
        clsAddNewUserScreen::ShowAddNewUserScreen();
    }

    static void _ShowDeleteUserScreen()
    {
        clsDeletUserScreen::ShowDeletUserScreen();
    }

    static void _ShowUpdateUserScreen()
    {
        clsUpdateUserScreen::ShowUpdateClientScreen();
    }

    static void _ShowFindUserScreen()
    {
        clsFindUserScreen::ShowFindUserScreen();
    }


public:
    static void PerformManageUsersMenuOption(enManageUsersMenuOptions ManageUsersMenuOptions)
    {
        switch (ManageUsersMenuOptions)
        {
        case enManageUsersMenuOptions::eListUsers:
        {
            system("cls");
            _ShowListUsersScreen();
            GoBackToManageUsersMenu();
            break;
        }
        case enManageUsersMenuOptions::eAddNewUsers:
        {
            system("cls");
            _AddNewUserScreen();
            GoBackToManageUsersMenu();
            break;
        }
        case enManageUsersMenuOptions::eDeleteUser:
        {
            system("cls");
            _ShowDeleteUserScreen();
            GoBackToManageUsersMenu();
            break;
        }
        case enManageUsersMenuOptions::eUpdateUser:
        {
            system("cls");
            _ShowUpdateUserScreen();
            GoBackToManageUsersMenu();
            break;
        }
        case enManageUsersMenuOptions::eFindUser:
        {
            system("cls");
            _ShowFindUserScreen();
            GoBackToManageUsersMenu();
            break;
        }
        case enManageUsersMenuOptions::eMainMenu:
        {

        }
        }
    }

    static void ShowManageUsersMenue()
    {
        system("cls");

        if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
        {
            return;
        }

        _DrawScreenHeader("\t  Manage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tMange Users Menue Screen\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        PerformManageUsersMenuOption((enManageUsersMenuOptions)_ReadMangeUsersMenuOption());
    }
};

