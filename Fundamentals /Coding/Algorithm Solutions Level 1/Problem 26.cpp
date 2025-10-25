//This is a soultion to the Problem #26.
#include <iostream>
using namespace std;
int Read_Number()
{
	int Number;
	cout << "Please enter the Number: ";
	cin >> Number;
	return Number;
};
void Print_Range_From_1_to_N(int Number)
{
	cout << "Rang Printed using For Statement:\n";
	for (int i = 1; i <= Number; i++)
	{
		cout << i << endl;
	}
};
int main()
{
	Print_Range_From_1_to_N(Read_Number());
	cout << "End the Program.";
}
