#include <iostream>
#include <iomanip>
using namespace std;

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
    cout << "\nPlease Enter a Month? ";
    cin >> Month;
    return Month;
}

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

short DayOfWeekOrder(short Year, short Month, short Day)
{
    int a = (14 - Month) / 12;
    int y = Year - a;
    int m = Month + 12 * a - 2;
    return (Day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
}

string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
    return arrDayNames[DayOfWeekOrder];
}

void PrintMonthCalinder(short Year, short Month)
{
    int NumberOfDays = NumberOfDayInMonth(Year, Month);
    int Current = DayOfWeekOrder(Year, Month, 1);

    cout << "\n  ________________ " << MonthShortName(Month) << " " << Year << " ________________\n\n";
    cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

    int i;
    for (i = 0; i < Current; i++)
        cout << "     ";

    for (int j = 1; j <= NumberOfDays; j++)
    {
        cout << setw(5) << j;

        if (++i == 7)
        {
            i = 0;
            cout << "\n";
        }
    }

    cout << "\n  ___________________________________________\n";
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();
    PrintMonthCalinder(Year, Month);

    system("pause>0");
    return 0;
}