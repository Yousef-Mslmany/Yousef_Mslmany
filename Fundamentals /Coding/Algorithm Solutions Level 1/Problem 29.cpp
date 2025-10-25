//This is a soultion to the Problem #29.
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
int Sum_Even_Number_From_1_From_N(int Number)
{
	int Sum = 0;
	cout << "Sum Odd Numbers Using For Statement: \n";
	for (int i = 1; i <= Number; i++)
	{
		if (Check_Odd_Or_Even(i) == en_Odd_or_Even::Even)
			Sum = Sum + i;
	}
	return Sum;
};
int Sum_Even_Number_From_1_From_N_Using_While(int Number)
{
	int Sum = 0;
	int Counter = 0;
	while (Counter <= Number)
	{
		Counter++;
		if (Check_Odd_Or_Even(Counter) == en_Odd_or_Even::Even)
		{
			Sum = Sum + Counter;
			Counter++;
		}
	}
	return Sum;
};
int main()
{
	cout << Sum_Even_Number_From_1_From_N_Using_While(Read_Number()) << endl;
	cout << "End the Program.";
}
