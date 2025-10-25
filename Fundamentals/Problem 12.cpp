//This is a soultion to the Problem #12
#include <iostream>
using namespace std;
struct Numbers
{
    int Number1;
    int Number2;
};
Numbers Read_Numbers()
{
	Numbers Number;
	cout << "Please enter Number1: ";
	cin >> Number.Number1;
	cout << "Please enter Number2: ";
	cin >> Number.Number2;
	return Number;
};
int Max_Namber(Numbers Number)
{
	if (Number.Number1 > Number.Number2)
		return Number.Number1;
	else
		return Number.Number2;
};
void Print_Max(int Max_Namber)
{
	cout << "Max is: " << Max_Namber;

};
int main()
{
	Print_Max(Max_Namber(Read_Numbers()));
	cout << "End the Program.";
}
