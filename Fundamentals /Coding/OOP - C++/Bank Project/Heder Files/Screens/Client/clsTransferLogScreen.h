#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsUser.h"


class clsTransferLogScreen :protected clsScreen
{

private:

    static void PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLofRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLofRecord.DateTime;
        cout << "| " << setw(8) << left << TransferLofRecord.SoursAccountNumber;
        cout << "| " << setw(8) << left << TransferLofRecord.DestinationAccountNumber;
        cout << "| " << setw(8) << left << TransferLofRecord.Amount;
        cout << "| " << setw(10) << left << TransferLofRecord.srcBalanceAfter;
        cout << "| " << setw(10) << left << TransferLofRecord.desBalanceAfter;
        cout << "| " << setw(10) << left << TransferLofRecord.UserName;
    }

public:

    static void ShowLoginRegisterScreen()
    {

        vector <clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::GetTransferLogList();

        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t(" + to_string(vTransferLogRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(10) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsBankClient::stTransferLogRecord Record : vTransferLogRecord)
            {

                PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};

