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
    cout << "\n  ________________ " << MonthShortName(Month) << " ________________\n\n";
    cout << "\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

    int NumberOfDays = NumberOfDayInMonth(Year, Month);
    int Current = DayOfWeekOrder(Year, Month, 1);

    int j;
    for (j = 0; j < Current; j++)
        cout << "     ";

    for (int k = 1; k <= NumberOfDays; k++)
    {
        cout << setw(5) << k;

        if (++j == 7)
        {
            j = 0;
            cout << "\n";
        }
    }

    cout << "\n  _____________________________________\n";
};

void PrintYearCalinder(short Year)
{

    cout << "\n  _____________________________________\n\n";
    cout << "             Calender - " << Year << endl;
    cout << "  _____________________________________\n";

    for (int i = 1; i <= 12; i++)
    {
        PrintMonthCalinder(Year, i);
    }
}

int main()
{
    PrintYearCalinder(ReadYear());

    system("pause>0");
    return 0;
}