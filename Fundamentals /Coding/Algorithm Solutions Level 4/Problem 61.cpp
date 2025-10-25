
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

enum enCompareDates { Before = -1, Equal = 0, After = 1 };

struct stDate
{
    short Year;
    short Month;
    short Day;
};

struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
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

stPeriod ReadPeriod()
{
    stPeriod Period;
    cout << "\nEnter Start Date: \n";
    Period.StartDate = ReadFullDate();
    cout << "\nEnter End Date: \n";
    Period.EndDate = ReadFullDate();
    return Period;
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
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

enCompareDates CompareDates(stDate Date1, stDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enCompareDates::Before;

    if (IsDate1EqualDate2(Date1, Date2))
        return enCompareDates::Equal;

    else
        return enCompareDates::After;
}

stDate Max(stDate Date1, stDate Date2)
{
    return (IsDate1AfterDate2(Date1, Date2)) ? Date1 : Date2;
}

stDate Min(stDate Date1, stDate Date2)
{
    return (IsDate1BeforeDate2(Date1, Date2)) ? Date1 : Date2;
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

int PeriodLengthInDays(stPeriod Period, bool IncludeEndDate = false)
{
    return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDate);
}

bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2)
{
    if (CompareDates(Period2.EndDate, Period1.StartDate) == enCompareDates::Before
        || CompareDates(Period2.StartDate, Period1.EndDate) == enCompareDates::After)
        return false;
    else
        return true;
}

bool IsDateInPeriod(stDate Date, stPeriod Period)
{
    return !(CompareDates(Date, Period.StartDate) == enCompareDates::Before
        ||
        CompareDates(Date, Period.EndDate) == enCompareDates::After);
}

int CountOverlapDays (stPeriod Period1, stPeriod Period2)
{
    int Period1Length = PeriodLengthInDays(Period1, true);
    int Period2Length = PeriodLengthInDays(Period2, true);
    int OverLapDays = 0;

    if (!IsOverlapPeriods(Period1, Period2))
        return 0;

    if (Period1Length < Period2Length)
    {
        while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
        {
            if (IsDateInPeriod(Period1.StartDate, Period2))
                OverLapDays++;

            Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
        }
    }

    else
    {
        while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
        {
            if (IsDateInPeriod(Period2.StartDate, Period1))
            OverLapDays++;

            Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
        }
    }

    return OverLapDays;
}

int main()
{
    stPeriod Period1, Period2;

    cout << "\nEnter Period 1 : ";
    Period1 = ReadPeriod();

    cout << "\nEnter Period 2 : ";
    Period2 = ReadPeriod();

    cout << "\nOverlap Days Count Is: " << CountOverlapDays(Period1, Period2) << endl;
    
    system("pause>0");
    return 0;
}
