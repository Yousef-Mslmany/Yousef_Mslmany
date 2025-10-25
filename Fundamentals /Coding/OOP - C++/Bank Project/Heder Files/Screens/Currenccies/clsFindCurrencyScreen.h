#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsString.h"
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsFindCurrencyScreen : protected clsScreen
{
private:
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:";
        cout << "\n___________________";
        cout << "\nCountry    : " << Currency.Currency();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$)   : " << Currency.Rate();
        cout << "\n___________________\n";
    }

    static void _ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency Was not Found :-(\n";
        }
    }

public:
    static void ShowFindCurrencyScreen()
    {
        _DrawScreenHeader("\tFind Currency Screen");

        short Choice = 0;
        cout << "\nFind By: [1] Code or [2] Country? ";
        Choice = clsInputValidate::ReadNumberBetween<short>(1, 2, "Please Enter Number [1] OR [2] ");

        clsCurrency Currency = clsCurrency::GetEmptyCurrencyObject();

        if (Choice == 1)
        {
            cout << "\nPlease Enter CurrencyCode: ";
            string Code = clsInputValidate::ReadString();
            Currency = clsCurrency::FindByCode(Code);
        }
        else
        {
            cout << "\nPlease Enter Country Name: ";
            string Country = clsInputValidate::ReadString();
            Currency = clsCurrency::FindByCountry(Country);
        }
        
        _ShowResults(Currency);
    }
};

