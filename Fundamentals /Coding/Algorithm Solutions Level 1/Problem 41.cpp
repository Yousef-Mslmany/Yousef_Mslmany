//This is a soultion to the Problem #41.
#include <iostream>
using namespace std;
float Read_Hours(string Message)
{
	int Number;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number<0);
	return Number;
};
float Calculate_Day(float Number)
{
	return (float) Number / 24;
};
float Calculate_Weeks(float Day)
{
	return (float)Day / 7;
};
int main()
{
	float Total_Hour = Read_Hours("Please enter a positive Total Hours: ");
	float Total_Days = Calculate_Day(Total_Hour);
	float Total_Weeks = Calculate_Weeks(Total_Days);
	cout << "The Hour :" << Total_Hour << " Hours" << endl;
	cout << "The Days :" << Total_Days << " Days" << endl;
	cout << "The Weeks :" << Total_Weeks << " Weeks" << endl;
	cout << "The End Program.";
}
