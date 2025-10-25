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

bool IsLeapYear(short Year)
{
	return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
};

short NumberOfDayInYear(short Year)
{
	return IsLeapYear(Year) ? 366 : 365;
};

int NumberOfHourInYear(short Year)
{
	return NumberOfDayInYear(Year) * 24;
};

int NumberOfMinutesInYear(short Year)
{
	return NumberOfHourInYear(Year) * 60;
};

int NumberOfSecondsInYear(short Year)
{
	return NumberOfMinutesInYear(Year) * 60;
};

int main()
{
	short Year = ReadYear();

	cout << "\nNumber of Days    in Year [" << Year << "] is " << NumberOfDayInYear(Year) << endl;
	cout << "Number of Hours   in Year [" << Year << "] is " << NumberOfHourInYear(Year) << endl;
	cout << "Number of Minutes in Year [" << Year << "] is " << NumberOfMinutesInYear(Year) << endl;
	cout << "Number of Seconds in Year [" << Year << "] is " << NumberOfSecondsInYear(Year) << endl;

	system("pause>0");
	return 0;
}
