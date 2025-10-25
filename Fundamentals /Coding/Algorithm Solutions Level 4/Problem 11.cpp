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

sDate GetDateFormDAyOrderInYear(short Year, short DateOrderInYear)
{
    sDate Date;

    short RemainingDays = DateOrderInYear;
    short MonthDays = 0;

    Date.Year = Year;
    Date.Month = 1;
    int i;
    while (true)
    {
        MonthDays = NumberOfDayInMonth(Year, Date.Month);
        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;
}

int main()
{
    short Day = ReadDay();
    short Month = ReadMonth();
    short Year = ReadYear();
    short DateOrderInYear = NumberOfDaysFromTheBeginingOfTheYear(Year, Month, Day);

    cout << "\nNumber of Days from the begining of the year is year is "
        << DateOrderInYear << "\n\n";

    sDate Date;
    Date = GetDateFormDAyOrderInYear(Year, DateOrderInYear);
    cout << "Date for [" << DateOrderInYear << "] is: " 
        << Date.Day << "/" << Date.Month << "/" << Date.Year;

    system("pause>0");
    return 0;
}