//This is a soultion to the Problem #27.
#include <iostream>
using namespace std;
int Read_Number()
{
	int Number;
	cout << "Please enter the Number: ";
	cin >> Number;
	return Number;
};
void Print_Range_From_N_to_1(int Number)
{
	cout << "Rang Printed using For Statement:\n";
	for (int i = Number; i >= 1; i--)
	{
		cout << i << endl;
	}
};
int main()
{
	Print_Range_From_N_to_1(Read_Number());
	cout << "End the Program.";
}
