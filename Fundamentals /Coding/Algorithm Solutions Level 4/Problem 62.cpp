
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

short ReadYear()
{
    short Year;
    cout << "Please Enter a year? ";
    cin >> Year;
    return Year;
}

short ReadMonth()
{
    short Month;
    cout << "Please Enter a Month? ";
    cin >> Month;
    return Month;
}

short ReadDay()
{
    short Day;
    cout << "\nPlease Enter a Day? ";
    cin >> Day;
    return Day;
}

stDate ReadFullDate()
{
    stDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

bool IsLeapYear(short Year)
{
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}

short NumberOfDayInMonth(short Year, short Month)
{
    if (Month < 1 || Month > 12)
        return 0;

    int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}

bool IsValideDate(stDate Date)
{
    if (Date.Day < 1 || Date.Day > 31)
        return false;

    if (Date.Month < 1 || Date.Month > 12)
        return false;

    if (Date.Month == 2)
    {
        if (IsLeapYear(Date.Year))
        {
            if (Date.Month > 29)
                return false;
            else
            {
                if (Date.Month > 28)
                    return false;
            }
        }
    }

    short DaysInMonth = NumberOfDayInMonth(Date.Year, Date.Month);

    if (Date.Day > DaysInMonth)
        return false;

    return true;
}

int main()
{
    stDate Date;
    Date = ReadFullDate();

    if (IsValideDate(Date))
        cout << "\nYes, Date is a Valide date\n";
    else
        cout << "\nNo, Date is NOT a Valide date\n";

    system("pause>0");
    return 0;
}
