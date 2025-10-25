//This is a soultion to the Problem #44.
#include <iostream>
using namespace std;
enum en_Days_Of_Week { Sun = 1, Mon = 2, Tue = 3, Wen = 4, Thu = 5, Fri = 6, Sat = 7 };
int Read_Number_In_Range(string Message,int From,int To)
{
    int Number;
    do
    {
        cout << Message << endl;
        cin >> Number;
	} while (Number < From || Number > To);
    return Number;
};
en_Days_Of_Week Read_Day_Of_Week()
{
	return (en_Days_Of_Week)Read_Number_In_Range("Please Enter Today's number: ", 1, 7);
}
string Print_Today(en_Days_Of_Week Day)
{
	switch (Day)
	{
	case  en_Days_Of_Week::Sun:
		return "Its Sunday\n";
	case  en_Days_Of_Week::Mon:
		return "Its Monday\n";
	case  en_Days_Of_Week::Tue:
		return "Its Tuesday\n";
	case  en_Days_Of_Week::Wen:
		return "Its Wedneday\n";
	case  en_Days_Of_Week::Thu:
		return "Its Thursday\n";
	case  en_Days_Of_Week::Fri:
		return "Its Friday\n";
	case  en_Days_Of_Week::Sat:
		return "Its Saturday\n";
	default:
		cout << "Wrong Day\n";
	}
};
int main()
{
	cout << Print_Today(Read_Day_Of_Week());
	cout << "End the Program.";
}
