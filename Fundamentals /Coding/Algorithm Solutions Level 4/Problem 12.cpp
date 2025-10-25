#include <iostream>
#include <iomanip>
using namespace std;

struct sDate
{
    short Year;
    short Month;
    short Day;
};

short ReadYear()
{
    short Year;
    cout << "\nPlease Enter a year? ";
    cin >> Year;
    return Year;
}

short ReadMonth()
{
    short Month;
    cout << "\nPlease Enter a Month? ";
    cin >> Month;
    return Month;
}

short ReadDay()
{
    short Year;
    cout << "\nPlease Enter a Day? ";
    cin >> Year;
    return Year;
};

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

short NumberOfDaysFromTheBeginingOfTheYear(short Year, short Month, short Day)
{
    short TotalDays = 0;

    for (int i = 1; i <= Month - 1; i++)
    {
        TotalDays += NumberOfDayInMonth(Year, i);
    }
    TotalDays += Day;

    return TotalDays;
};

sDate DateAddDays(sDate Date, short Days)
{
    sDate Date;

    short RemainingDays = Days + NumberOfDaysFromTheBeginingOfTheYear(Date.Year, Date.Month, Date.Day);
    short MonthDays = 0;

    Date.Month = 1;

    while (true)
    {
        MonthDays = NumberOfDayInMonth(Date.Year, Date.Month);

        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;
            if (Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
            else
            {
                Date.Day++;
                Date.Month++;
            }
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;
}

sDate ReadFullDate()
{
    sDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

short ReadDaysToAdd()
{
    short Days;
    cout << "\nHow Many days to add? ";
    cin >> Days;
    return Days;
}

int main()
{
    sDate Date = ReadFullDate();
    short Days = ReadDaysToAdd();

    Date = DateAddDays(Date, Days);

    cout << "\nData after adding [" << Days << "] days is: " << Date.Day << "/"
        << Date.Month << "/" << Date.Year;

    system("pause>0");
    return 0;
}