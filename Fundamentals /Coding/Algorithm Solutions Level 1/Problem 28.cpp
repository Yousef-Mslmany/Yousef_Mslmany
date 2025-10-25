//This is a soultion to the Problem #28.
#include <iostream>
using namespace std;
enum en_Odd_or_Even { Odd = 1, Even = 2 };

int Read_Number()
{
	int Number;
	cout << "Please enter the Number: ";
	cin >> Number;
	return Number;
};
en_Odd_or_Even Check_Odd_Or_Even(int Number)
{
	if (Number % 2 == 0)
		return en_Odd_or_Even::Even;
	else
		return en_Odd_or_Even::Odd;

};
int Sum_Odd_Number_From_1_From_N(int Number)
{
	int Sum=0;
	cout << "Sum Odd Numbers Using For Statement: \n";
	for (int i = 1; i <= Number; i++)
	{
		if (Check_Odd_Or_Even(i) == en_Odd_or_Even::Odd)
			Sum = Sum + i;
	}
	return Sum;
};
int main()
{
	cout << Sum_Odd_Number_From_1_From_N(Read_Number()) << endl;
	cout << "End the Program.";
}
