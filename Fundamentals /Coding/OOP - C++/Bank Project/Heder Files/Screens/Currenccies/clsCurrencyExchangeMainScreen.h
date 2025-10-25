#pragma once
#include <iostream>
#include <iomanip>
#include "clsCurrency.h"
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

class clsCurrencyExchangeMainScreen : protected clsScreen
{
private:
    enum enCurrencyMainMenuOptions
    {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateCurrencyRate = 3,
        eCurrencyCalculator = 4, eMainMenu = 5
    };

    static short _ReadCurrencyMainMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what to do? [1 to 5]: ";
        short Option = clsInputValidate::ReadNumberBetween<short>(1, 5, "Enter Number between 1 to 5");
        return Option;

    }

    static void _GoBackToCurrencyMainMenu()
    {
        cout << setw(37) << left << "" << "\n\nPress any key to go back to Main Menu...";
        system("pause>0");
        ShowCurrencyMainMenu();
    }

    static void _ShowListCurrenciesScreen()
    {
        //cout << "\nList Currencies List Screen Will Be Here\n";
        clsCurrenciesListScreen::ShowCurrenciesListScreen();
    }

    static void _ShowFindCurrencyScreen()
    {
        //cout << "\nFind Currency List Screen Will Be Here\n";
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateRateScreen()
    {
        //cout << "\nUpdate Rate Screen Will Be Here\n";
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        //cout << "\nCurrency Calculator Screen Will Be Here\n";
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

public:
    static void PerformCurrencyMainMenuOption(enCurrencyMainMenuOptions CurrencyMainMenuOption)
    {

        switch (CurrencyMainMenuOption)
        {
        case enCurrencyMainMenuOptions::eListCurrencies:
        {
            system("cls");
            _ShowListCurrenciesScreen();
            _GoBackToCurrencyMainMenu();
            break;
        }
        case enCurrencyMainMenuOptions::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyMainMenu();
            break;
        }
        case enCurrencyMainMenuOptions::eUpdateCurrencyRate:
        {
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToCurrencyMainMenu();
            break;
        }
        case enCurrencyMainMenuOptions::eCurrencyCalculator:
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrencyMainMenu();
            break;
        }
        case enCurrencyMainMenuOptions::eMainMenu:
        {

        }
        }
    }

	static void ShowCurrencyMainMenu()
	{
        system("cls");

        _DrawScreenHeader("    Currency Exchange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Exchange Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        PerformCurrencyMainMenuOption((enCurrencyMainMenuOptions)_ReadCurrencyMainMenuOption());
	}
};

