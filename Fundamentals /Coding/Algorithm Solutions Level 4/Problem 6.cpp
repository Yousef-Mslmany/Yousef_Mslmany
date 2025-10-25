#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

short ReadYear()
{
	short Year;
	cout << "Please Enter a year? ";
	cin >> Year;
	return Year;
};

short ReadMonth()
{
	short Year;
	cout << "\nPlease Enter a Month? ";
	cin >> Year;
	return Year;
};

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
};

short NumberOfDayInMonth(short Year, short Month)
{
	if (Month < 1 || Month > 12)
		return 0;

	int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (IsLeapYear(Year)	? 29 : 28) : NumberOfDays[Month-1];

};

short IndexForDay(short Year, short Month, short Day)
{
	int a = (14 - Month) / 12;
	int y = Year - a;
	int m = Month + (12 * a) - 2;
	int d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return d;
};



int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();
	short Day = ReadDay();
	short Index = IndexForDay(Year, Month, Day);

	string DayOfWeek[7] = { "Sun","Mon","Tus","Wed","Thur","Fri","Sat" };

	cout << "\nDate\t  :" << Day << "/" << Month << "/" << Year;
	cout << "\nDay Order : "<< Index;
	cout << "\nDay Name  : "<< DayOfWeek[Index];

	system("pause>0");
	return 0;
}
