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
};

sDate ReadFullDate()
{
    sDate Date;

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

bool IsLastDayInMonth(sDate Date)
{
    return (Date.Day == NumberOfDayInMonth(Date.Year, Date.Month)) ? true : false;
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

sDate IncreaseDateByOneDay(sDate &Date)
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

sDate IncreaseDateByXDays(int Days, sDate& Date)
{
    for (int i = 0; i < Days; i++)
    {
        IncreaseDateByOneDay(Date);
    }
    return Date;
}

sDate IncreaseDateByOneWeek(sDate& Date)
{
    for (int i = 0; i < 7; i++)
    {
        IncreaseDateByOneDay(Date);
    }
    return Date;
}

sDate IncreaseDateByXWeeks(int Weeks, sDate& Date)
{
    for (int i = 0; i < Weeks; i++)
    {
        IncreaseDateByOneWeek(Date);
    }
    return Date;
}

sDate IncreaseDateByOneMonth(sDate& Date)
{
    if (Date.Month == 12)
    {
        Date.Month == 1;
        Date.Year++;
    }
    else
    {
        Date.Month++;
    }

    short NumberOfDaysInCurrentMonth = NumberOfDayInMonth(Date.Year, Date.Month);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}

sDate IncreaseDateByXMonths(int Months, sDate& Date)
{
    for (int i = 0; i < Months; i++)
    {
        IncreaseDateByOneMonth(Date);
    }
    return Date;
}

sDate IncreaseDateByOneYear(sDate& Date)
{
    Date.Year++;
    return Date;
}

sDate IncreaseDateByXYear(int Years, sDate& Date)
{
    for (int i = 0; i < Years; i++)
    {
        IncreaseDateByOneYear(Date);
    }
    return Date;
}

sDate IncreaseDateByXYearsFaster(int Years, sDate& Date)
{
    Date.Year += Years;
    return Date;
}

sDate IncreaseDateByOneDecade(sDate& Date)
{
    Date.Year += 10;
    return Date;
}

sDate IncreaseDateByXDecades(int Decades, sDate& Date)
{
    for (int i = 0; i < Decades * 10; i++)
    {
        IncreaseDateByOneYear(Date);
    }
    return Date;
}

sDate IncreaseDateByXDecadesFaster(int Decades, sDate& Date)
{
    Date.Year += Decades * 10;
    return Date;
}

sDate IncreaseDateByOneCentury(sDate& Date)
{
    Date.Year += 100;
    return Date;
}

sDate IncreaseDateByOneMillennium(sDate& Date)
{
    Date.Year += 1000;
    return Date;
}

int main()
{
    sDate Date;
    Date = ReadFullDate();

    cout << "\nDate After:\n";

    IncreaseDateByOneDay(Date);
    cout << "\n01-Adding one day is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    IncreaseDateByXDays(10 ,Date);
    cout << "\n02-Adding 10 days is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    IncreaseDateByOneWeek(Date);
    cout << "\n03-Adding one week is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    IncreaseDateByXWeeks(10, Date);
    cout << "\n04-Adding 10 week is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    IncreaseDateByOneMonth(Date);
    cout << "\n05-Adding one month is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    IncreaseDateByXMonths(5, Date);
    cout << "\n06-Adding 5 Months is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    IncreaseDateByOneYear(Date);
    cout << "\n07-Adding one year is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    IncreaseDateByXYear(10, Date);
    cout << "\n08-Adding 10 Years is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    IncreaseDateByXYearsFaster(10, Date);
    cout << "\n09-Adding 10 Years (faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    IncreaseDateByOneDecade(Date);
    cout << "\n10-Adding one Decade is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    IncreaseDateByXDecades(10, Date);
    cout << "\n11-Adding 10 Decades is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    IncreaseDateByXDecadesFaster(10, Date);
    cout << "\n12-Adding 10 Decades (faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    IncreaseDateByOneCentury(Date);
    cout << "\n13-Adding One Century is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    IncreaseDateByOneMillennium(Date);
    cout << "\n14-Adding One Millennium is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;


    system("pause>0");
    return 0;

}