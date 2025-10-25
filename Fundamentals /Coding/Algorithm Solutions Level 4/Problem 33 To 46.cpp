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

sDate DecreaseDateByOneDay(sDate& Date)
{
    if (Date.Day == 1)
    {
        if (Date.Month == 1)
        {
            Date.Month = 12;
            Date.Day = 31;
            Date.Year--;
        }
        else
        {
            Date.Month--;
            Date.Day = NumberOfDayInMonth(Date.Year, Date.Month);
        }
    }
    else
    {
        Date.Day--;
    }
    return Date;
}

sDate DecreaseDateByXDays(int Days, sDate& Date)
{
    for (int i = 0; i < Days; i++)
    {
        DecreaseDateByOneDay(Date);
    }
    return Date;
}

sDate DecreaseDateByOneWeek(sDate& Date)
{
    for (int i = 0; i < 7; i++)
    {
        DecreaseDateByOneDay(Date);
    }
    return Date;
}

sDate DecreaseDateByXWeeks(int Weeks, sDate& Date)
{
    for (int i = 0; i < Weeks; i++)
    {
        DecreaseDateByOneWeek(Date);
    }
    return Date;
}

sDate DecreaseDateByOneMonth(sDate& Date)
{
    if (Date.Month == 1)
    {
        Date.Month == 12;
        Date.Year--;
    }
    else
    {
        Date.Month--;
    }

    short NumberOfDaysInCurrentMonth = NumberOfDayInMonth(Date.Year, Date.Month);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}

sDate DecreaseDateByXMonths(int Months, sDate& Date)
{
    for (int i = 0; i < Months; i++)
    {
        DecreaseDateByOneMonth(Date);
    }
    return Date;
}

sDate DecreaseDateByOneYear(sDate& Date)
{
    Date.Year--;
    return Date;
}

sDate DecreaseDateByXYear(int Years, sDate& Date)
{
    for (int i = 0; i < Years; i++)
    {
        DecreaseDateByOneYear(Date);
    }
    return Date;
}

sDate DecreaseDateByXYearsFaster(int Years, sDate& Date)
{
    Date.Year -= Years;
    return Date;
}

sDate DecreaseDateByOneDecade(sDate& Date)
{
    Date.Year -= 10;
    return Date;
}

sDate DecreaseDateByXDecades(int Decades, sDate& Date)
{
    for (int i = 0; i < Decades * 10; i++)
    {
        DecreaseDateByOneYear(Date);
    }
    return Date;
}

sDate DecreaseDateByXDecadesFaster(int Decades, sDate& Date)
{
    Date.Year -= Decades * 10;
    return Date;
}

sDate DecreaseDateByOneCentury(sDate& Date)
{
    Date.Year -= 100;
    return Date;
}

sDate DecreaseDateByOneMillennium(sDate& Date)
{
    Date.Year -= 1000;
    return Date;
}

int main()
{
    sDate Date;
    Date = ReadFullDate();

    cout << "\nDate After:\n";

    DecreaseDateByOneDay(Date);
    cout << "\n01-Subtracting one day is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    DecreaseDateByXDays(10, Date);
    cout << "\n02-Subtracting 10 days is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    DecreaseDateByOneWeek(Date);
    cout << "\n03-Subtracting one week is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    DecreaseDateByXWeeks(10, Date);
    cout << "\n04-Subtracting 10 weeks is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    DecreaseDateByOneMonth(Date);
    cout << "\n05-Subtracting one month is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    DecreaseDateByXMonths(5, Date);
    cout << "\n06-Subtracting 5 months is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    DecreaseDateByOneYear(Date);
    cout << "\n07-Subtracting one year is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    DecreaseDateByXYear(10, Date);
    cout << "\n08-Subtracting 10 Years is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    DecreaseDateByXYearsFaster(10, Date);
    cout << "\n09-Subtracting 10 Years (faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    DecreaseDateByOneDecade(Date);
    cout << "\n10-Subtracting One Decade is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    DecreaseDateByXDecades(10, Date);
    cout << "\n11-Subtracting 10 Decades is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    DecreaseDateByXDecadesFaster(10, Date);
    cout << "\n12-Subtracting 10 Decades (faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    DecreaseDateByOneCentury(Date);
    cout << "\n13-Subtracting One Century is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    DecreaseDateByOneMillennium(Date);
    cout << "\n14-Subtracting One Millennium is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    system("pause>0");
    return 0;

}