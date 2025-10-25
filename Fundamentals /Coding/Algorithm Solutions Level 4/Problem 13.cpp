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
    short Year;
    cout << "\nPlease Enter a Day? ";
    cin >> Year;
    return Year;
};

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

sDate ReadFullDate()
{
    sDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

int main()
{
    sDate Date1, Date2;

    Date1 = ReadFullDate();
    Date2 = ReadFullDate();

    if (IsDate1BeforeDate2(Date1, Date2))
        cout << "\nYes, Date1 is LESS than Date2";
    else
        cout << "\nNo, Date1 is NOT LESS than Date2";

    system("pause>0");
    return 0;
}