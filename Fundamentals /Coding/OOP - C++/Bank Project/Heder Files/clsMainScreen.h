#pragma once
#include <iostream>
#include <iomanip>
#include "clsUtil.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeMainScreen.h"
#include "Global.h"
using namespace std;

 
class clsMainScreen: protected clsScreen
{
private:
    enum enMainMenuOptions
    {
        eListClient = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenu = 6, 
        eShowManageUsers = 7, eShowLoginRegister, eCurrencyExchange = 9 ,eLogout = 10
    };

    static short _ReadMainMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what to do? [1 to 10]: ";
        short Option = clsInputValidate::ReadNumberBetween<short>(1, 10, "Enter Number between 1 to 10");
        return Option;

    }

    static void _GoBackToCurrencyMainMenu()
    {
        cout << setw(37) << left << "" << "\n\nPress any key to go back to Main Menu...";
        system("pause>0");
        ShowMainMenu();
    }

    static void _ShowAllClientsScreen()
    {
        clsClientListScreen::ShowClientsList();
    }

    static void _AddNewClientScreen()
    {
        clsAddNewClientScreen::ShowAddNewClientScreen();
    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenu()
    {
        clsTransactionsMenuScreen::ShowTransactionsMenu();
    }

    static void _ShowManageUsersMenue()
    {
        clsManageUsersScreen::ShowManageUsersMenue();
    }

    static void _ShowLoginRegister()
    {
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }

    static void _ShowCurrencyExchangeScreen()
    {
        clsCurrencyExchangeMainScreen::ShowCurrencyMainMenu();
    }

    static void _Logout()
    {
		CurrentUser = clsUser::Find("", "");
    }

public:
    static void PerformMainMenuOption(enMainMenuOptions MainMenuOption)
    {

        switch (MainMenuOption)
        {
        case enMainMenuOptions::eListClient:

            system("cls");
            _ShowAllClientsScreen();
            _GoBackToCurrencyMainMenu();
            break;
        case enMainMenuOptions::eAddNewClient:
            system("cls");
            _AddNewClientScreen();
            _GoBackToCurrencyMainMenu();
            break;
        case enMainMenuOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToCurrencyMainMenu();
            break;
        case enMainMenuOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToCurrencyMainMenu();
            break;
        case enMainMenuOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToCurrencyMainMenu();
            break;
        case enMainMenuOptions::eShowTransactionsMenu:
            system("cls");
            _ShowTransactionsMenu();
            _GoBackToCurrencyMainMenu();
            break;
        case enMainMenuOptions::eShowManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToCurrencyMainMenu();
            break;
        case enMainMenuOptions::eShowLoginRegister:
            system("cls");
            _ShowLoginRegister();
            _GoBackToCurrencyMainMenu();
            break;
        case enMainMenuOptions::eCurrencyExchange:
            system("cls");
            _ShowCurrencyExchangeScreen();
            _GoBackToCurrencyMainMenu();
            break;
        case enMainMenuOptions::eLogout:
            system("cls");
            _Logout();
            break;
        default:
            cout << "Invalid choice, select between 1 and 9.\n";
            _GoBackToCurrencyMainMenu();
            break;
        }
    }

    static void ShowMainMenu()
    {
        system("cls");

        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Main Menu Screen\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        PerformMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());
    }
};

