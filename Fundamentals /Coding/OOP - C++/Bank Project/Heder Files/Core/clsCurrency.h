#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsScreen.h"

class clsCurrency
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1 };

    enMode _Mode;
    string _Currency;
    string _CurrencyCode;
    string _CurrencyName;
    float _Rate;

    static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Separator = "#//#")
    {

        string stClientRecord = "";
        stClientRecord += Currency.Currency() + Separator;
        stClientRecord += Currency.CurrencyCode() + Separator;
        stClientRecord += Currency.CurrencyName() + Separator;
        stClientRecord += to_string(Currency.Rate());

        return stClientRecord;

    }

    static clsCurrency _ConvertLineToCurrencyObject(string Line, string Separator = "#//#")
    {
        vector<string> vCurrencyData;
        vCurrencyData = clsString::Split(Line, Separator);

        return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1],
            vCurrencyData[2], stof(vCurrencyData[3]));
    }

    static  vector <clsCurrency> _LoadCurrenciesDataFromFile()
    {

        vector <clsCurrency> _vCurrencies;

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

                _vCurrencies.push_back(Currency);
            }

            MyFile.close();

        }

        return _vCurrencies;

    }

    static void _SaveCurrenciesDataToFile(vector <clsCurrency> vCurrencies)
    {

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsCurrency C : vCurrencies)
            {
                    MyFile << _ConvertCurrencyObjectToLine(C) << endl;
            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsCurrency> _vCurrencies;
        _vCurrencies = _LoadCurrenciesDataFromFile();

        for (clsCurrency& C : _vCurrencies)
        {
            if (C.CurrencyCode() == CurrencyCode())
            {
                C = *this;
                break;
            }

        }

        _SaveCurrenciesDataToFile(_vCurrencies);

    }

    static clsCurrency _GetEmptyCurrencyObject()
    {
        return clsCurrency(enMode::EmptyMode, "", "", "",  0);
    }

public:

    clsCurrency(enMode Mode, string Currency, string CurrencyCode, string CurrencyName, float Rate)
    {
        _Mode = Mode;
        _Currency = Currency;
        _CurrencyCode = CurrencyCode;
        _CurrencyName = CurrencyName;
        _Rate = Rate;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    string Currency()
    {
        return _Currency;
    }

    string CurrencyCode()
    {
        return _CurrencyCode;
    }

    string CurrencyName()
    {
        return _CurrencyName;
    }

    void UpdateRate(float NewRate)
    {
        _Rate = NewRate;
        _Update();
    }

    float Rate()
    {
        return _Rate;
    }

    static clsCurrency FindByCode(string CurrencyCode)
    {

        CurrencyCode = clsString::UpperAllString(CurrencyCode);

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
                if (Currency.CurrencyCode() == CurrencyCode)
                {
                    MyFile.close();
                    return Currency;
                }

            }

            MyFile.close();

        }

        return _GetEmptyCurrencyObject();
    }

    static clsCurrency FindByCountry(string Country)
    {

        Country = clsString::UpperAllString(Country);

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
                if (clsString::UpperAllString(Currency.Currency()) == Country)
                {
                    MyFile.close();
                    return Currency;
                }

            }

            MyFile.close();

        }

        return _GetEmptyCurrencyObject();
    }

    static bool IsCurrencyExist(string CurrencyCode)
    {

        clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode);
        return (!Currency1.IsEmpty());
    }

    static vector <clsCurrency> GetCurrenciesList()
    {
        return _LoadCurrenciesDataFromFile();
    }

    static clsCurrency GetEmptyCurrencyObject()
    {
        return _GetEmptyCurrencyObject();
    }

    float ConvertInUSD(float Amount)
    {
        return (float)(Amount / Rate());
    }

    float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
    {
        float AmountInUSD = ConvertInUSD(Amount);

        if (Currency2.CurrencyCode() == "USD")
        {
            return AmountInUSD;
        }

        return (float)(AmountInUSD * Currency2.Rate());
    }
};

