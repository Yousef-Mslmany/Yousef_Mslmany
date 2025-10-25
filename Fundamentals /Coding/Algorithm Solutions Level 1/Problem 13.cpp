//This is a soultion to the Problem #12
#include <iostream>
using namespace std;
struct Numbers
{
	int Number1;
	int Number2;
	int Number3;
};
Numbers Read_Numbers()
{
	Numbers Number;
	cout << "Please enter Number1: ";
	cin >> Number.Number1;
	cout << "Please enter Number2: ";
	cin >> Number.Number2;
	cout << "Please enter Number2: ";
	cin >> Number.Number3;
	return Number;
};
int Max_Namber(Numbers Number)
{
	if (Number.Number1 > Number.Number2 && Number.Number1 > Number.Number3)
		return Number.Number1;
	else if (Number.Number2 > Number.Number1 && Number.Number2 > Number.Number3)
		return Number.Number2;
	else
		return Number.Number3;
};
void Print_Max(int Max_Namber)
{
	cout << "Max is: " << Max_Namber<<endl;

};
int main()
{
	Print_Max(Max_Namber(Read_Numbers()));
	cout << "End the Program.";
}
