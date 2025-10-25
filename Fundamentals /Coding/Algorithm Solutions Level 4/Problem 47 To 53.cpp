#pragma warning(disable : 4996)

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

stDate GetSystemDate()
{
    stDate Date;

    time_t t = time(0);
    tm* now = localtime(&t);

    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;
    Date.Day = now->tm_mday;

    return Date;
}

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

bool IsLeapYear(short Year)
{
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}

short DayOfYear(short Year)
{
    return (IsLeapYear(Year)) ? 366 : 365;
}

short NumberOfDayInMonth(short Year, short Month)
{
    if (Month < 1 || Month > 12)
        return 0;

    int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsLastDayInMonth(stDate Date)
{
    return (Date.Day == NumberOfDayInMonth(Date.Year, Date.Month)) ? true : false;
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

stDate IncreaseDateByOneDay(stDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Day = 1;
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }
    return Date;
}

void SwapDates(stDate& Date1, stDate& Date2)
{
    stDate Temp;
    Temp = Date1;
    Date1 = Date2;
    Date2 = Temp;
}

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;
    int SwapFlagValue = 1;

    if (!IsDate1BeforeDate2(Date1, Date2))
    {
        SwapDates(Date1, Date2);
        SwapFlagValue = -1;
    }

    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
}

short DayOfWeekOrder(short Year, short Month, short Day)
{
    int a = (14 - Month) / 12;
    int y = Year - a;
    int m = Month + (12 * a) - 2;
    int d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    return d;
}

short DayOfWeekOrder(stDate Date)
{
    return DayOfWeekOrder(Date.Year, Date.Month, Date.Day);
}

string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[] = { "Sun","Mon","Tus","Wed","Thur","Fri","Sat" };

    return arrDayNames[DayOfWeekOrder];
}

bool IsEndOfWeek(stDate Date)
{
    return DayOfWeekOrder(Date) == 6;
}

bool IsWeekEnd(stDate Date)
{
    short IndexOfDay = DayOfWeekOrder(Date);
    return (IndexOfDay == 5 || IndexOfDay == 6);
}

bool IsBusinessDay(stDate Date)
{
    return (!IsWeekEnd(Date));
}

short DayUntilTheEndOfWeek(stDate Date)
{
    return 6 - DayOfWeekOrder(Date);
}

short DaysUntilTheEndOfMonth(stDate Date)
{
    stDate EndOfMonthDate;
    EndOfMonthDate.Day = NumberOfDayInMonth(Date.Year, Date.Month);
    EndOfMonthDate.Month = Date.Month;
    EndOfMonthDate.Year = Date.Year;
    return GetDifferenceInDays(Date, EndOfMonthDate, true);
}

short DaysUntilTheEndOfYear(stDate Date)
{
    stDate EndOfYearDate;
    EndOfYearDate.Day = 31;
    EndOfYearDate.Month = 12;
    EndOfYearDate.Year = Date.Year;
    return GetDifferenceInDays(Date, EndOfYearDate, true);
}

int main()
{
    stDate Date = GetSystemDate();

    short IndexOfDay = DayOfWeekOrder(Date);

    cout << "\nToday is " << DayShortName(IndexOfDay) << " , " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    
    cout << "\n\nIs it End of Week?";
    if (IsEndOfWeek(Date))
        cout << "\nYes, end of week.";
    else
        cout << "\nNo, NOT end of week.";

    cout << "\n\nIs it Weekend?";
    if (IsWeekEnd(Date))
        cout << "\nYes, it is a week end.";
    else
        cout << "\nNo Today is " << DayShortName(IndexOfDay) <<", NOT a week end.";

    cout << "\n\nIs it Business Day?";
    if (IsBusinessDay(Date))
        cout << "\nYes, it is a business day.";
    else
        cout << "\nNo, it is NOT a business day.";

    cout << "\n\nDays until end of week : " << DayUntilTheEndOfWeek(Date) << " Day(s).";
    
    cout << "\nDays until end of Month : " << DaysUntilTheEndOfMonth(Date) << " Day(s).";
    
    cout << "\nDays until end of Year : " << DaysUntilTheEndOfYear(Date) << " Day(s).";

    system("pause>0");
    return 0;
}
