#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsBankClient.h"
#include "clsPerson.h"
#include "clsString.h"
#include "clsShowDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
using namespace std;

class clsTransactionsMenuScreen: protected clsScreen
{
private:
    enum enTransactionsMenuOptions
    {
        eDeposit = 1, eWithdraw = 2, eShowTotalBalances = 3, eTransfer = 4, eTransferLog = 5, eShowMainMenu = 6
    };

    static short _ReadTransactionsMenuOption()
    {
        cout << "\n" << setw(37) << left << "" << "Choose what to do? [1 to 6]: ";
        short Option = clsInputValidate::ReadNumberBetween<short>(1, 6, "Enter Number between 1 to 6");
        return Option;
    }

    static void _GoBackToTransactionsMenu()
    {
        cout << "\n\nPress any key to go back to Transactions Menu...";
        system("pause>0");
        system("cls");
        ShowTransactionsMenu();
    }

    static void _ShowDepositScreen()
    {
        clsShowDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        clsTotalBalancesScreen::ShowTotalBalances();
    }

    static void _ShowTransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
    }

    static void _ShowTransferLogScreen()
    {
        clsTransferLogScreen::ShowLoginRegisterScreen();
    }

    static void _ShowMainMenu()
    {

    }

public:
    static void PerformTransactionsMenuOption(enTransactionsMenuOptions TransactionMenuOption)
    {
        switch (TransactionMenuOption)
        {
        case enTransactionsMenuOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenu();
            break;
        }
        case enTransactionsMenuOptions::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenu();
            break;
        }
        case enTransactionsMenuOptions::eShowTotalBalances:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenu();
            break;
        }
        case enTransactionsMenuOptions::eTransfer:
        {
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenu();
            break;
        }
        case enTransactionsMenuOptions::eTransferLog:
        {
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionsMenu();
            break;
        }
        case enTransactionsMenuOptions::eShowMainMenu:
        {
            _ShowMainMenu();
        }
        }
    }

    static void ShowTransactionsMenu()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;
        }

        system("cls");
        _DrawScreenHeader("\tTransactions Screen");

        system("cls");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tTransactions Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

         PerformTransactionsMenuOption((enTransactionsMenuOptions)_ReadTransactionsMenuOption());
    }   
};      
