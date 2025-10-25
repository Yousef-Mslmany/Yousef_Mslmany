//This is a soultion to the Problem #45.
#include <iostream>
using namespace std;
enum en_Month_Of_Year { Jan = 1, Feb = 2, Mar = 3, Apr = 4, May = 5, Jun = 6, Jul = 7, Aug = 8, Sep = 9, Oct = 10, Nov = 11, Dec = 12 };
int Read_Number_In_Range(string Message, int From, int To)
{
	int Number;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number < From || Number > To);
	return Number;
};
en_Month_Of_Year Read_Month_Of_Year()
{
	return (en_Month_Of_Year)Read_Number_In_Range("Please Enter a mounth[1 to 12] ", 1, 12);
}
string Print_Month(int Month)
{
	switch (Month)
	{
	case  en_Month_Of_Year::Jan:
	  return "Its January\n";
	case  en_Month_Of_Year::Feb:
	  return "Its February\n";
	case  en_Month_Of_Year::Mar:
		return "Its March\n";
	case  en_Month_Of_Year::Apr:
		return "Its April\n";
	case  en_Month_Of_Year::May:
		return "Its May\n";
	case  en_Month_Of_Year::Jun:
		return "Its June\n";
	case  en_Month_Of_Year::Jul:
		return "Its July\n";
	case  en_Month_Of_Year::Aug:
		return "Its August\n";
	case  en_Month_Of_Year::Sep:
		return "Its September\n";
	case  en_Month_Of_Year::Oct:
		return "Its October\n";
	case  en_Month_Of_Year::Nov:
		return "Its November\n";
	case  en_Month_Of_Year::Dec:
		return "Its December\n";
	default:
		return "Wrong Day\n";
	}
};
int main()
{
	cout << Print_Month(Read_Month_Of_Year());
	cout << "End the Program.";
}
