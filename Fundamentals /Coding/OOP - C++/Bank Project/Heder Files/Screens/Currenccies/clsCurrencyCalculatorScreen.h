#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsString.h"
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:
    static void _PrintCurrencyCode(clsCurrency Currency, string Direction)
    {
        cout << "\nConvert " << Direction << ": ";
        cout << "\n___________________";
        cout << "\nCountry    : " << Currency.Currency();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$)   : " << Currency.Rate();
        cout << "\n___________________\n";
    }

    static clsCurrency _GetCurrency(string Message)
    {
        string CurrencyCode = "";
        cout << Message;

        CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency Code is not found, choose another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        return Currency;
    }

    static float _ReadAmount()
    { 
        float Amount = 0;
        cout << "\nEnter Amount to Exchange: ";
        Amount = clsInputValidate::ReadNumber<float>();
        return Amount;
    }

    static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
    {
        _PrintCurrencyCode(Currency1, "From:");

        float AmountInUSD = Currency1.ConvertInUSD(Amount);

        cout << "\n" << Amount << " " << Currency1.CurrencyCode()
            << " = " << AmountInUSD << " " << "USD\n";

        if (Currency2.CurrencyCode() == "USD")
        {
            return;
        }

        cout << "\nConverting from USD to:\n";

        _PrintCurrencyCode(Currency2, "To:");

        float AmountInCurrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

        cout << "\n" << Amount << " " << Currency1.CurrencyCode()
            << " = " << AmountInCurrency2 << " " << Currency2.CurrencyCode();
    }

public:
    static void ShowCurrencyCalculatorScreen()
    {
        char Answer = 'y';
        while (toupper(Answer) == 'Y')
        { 
            system("cls");

            _DrawScreenHeader("\tCurrency Calculator Screen");
            
            clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 Code: ");
            clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency2 Code: ");      
            float Amount = _ReadAmount();
       
            _PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);

            cout << "\n\nDo you want to perform another calculation y/n ? ";
            cin >> Answer;         
        } 

    }
};

