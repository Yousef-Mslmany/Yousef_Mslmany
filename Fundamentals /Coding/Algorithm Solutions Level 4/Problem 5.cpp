#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

short ReadYear()
{
	short Year;
	cout << "Please Enter a year to check? ";
	cin >> Year;
	return Year;
};

short ReadMonth()
{
	short Year;
	cout << "\nPlease Enter a Month to check? ";
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

	if (Month == 2)
		return IsLeapYear(Year)? 29 : 28;

	short arr31Days[7] = { 1,3,5,7,8,10,12 };

	for (int i = 1; i < 7; i++)
	{
		if (arr31Days[i - 1] == Month)
			return 31;
	}

		return 30;
};

int NumberOfHourInMonth(short Year, short Month)
{
	return NumberOfDayInMonth(Year, Month) * 24;
};

int NumberOfMinutesInMonth(short Year, short Month)
{
	return NumberOfHourInMonth(Year, Month) * 60;
};

int NumberOfSecondsInMonth(short Year, short Month)
{
	return NumberOfMinutesInMonth(Year, Month) * 60;
};

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();

	cout << "\nNumber of Days    in Month [" << Month << "] is " << NumberOfDayInMonth(Year, Month) << endl;
	cout << "Number of Hours   in Month [" << Month << "] is " << NumberOfHourInMonth(Year, Month) << endl;
	cout << "Number of Minutes in Month [" << Month << "] is " << NumberOfMinutesInMonth(Year, Month) << endl;
	cout << "Number of Seconds in Month [" << Month << "] is " << NumberOfSecondsInMonth(Year, Month) << endl;

	system("pause>0");
	return 0;
}
