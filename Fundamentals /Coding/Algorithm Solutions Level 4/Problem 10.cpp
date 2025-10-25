#include <iostream>
#include <iomanip>
using namespace std;

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


string MonthShortName(short Month)
{
    string NameOfMonth[12] =
    { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
      "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

    return NameOfMonth[Month - 1];
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
int main()
{
    short Day = ReadDay();
    short Month = ReadMonth();
    short Year = ReadYear();

    cout << "\nNumber of Days from the begining of the year is year is " << NumberOfDaysFromTheBeginingOfTheYear(Year, Month, Day);

    system("pause>0");
    return 0;
}