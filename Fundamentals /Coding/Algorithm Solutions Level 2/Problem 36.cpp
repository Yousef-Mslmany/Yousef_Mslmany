//This is a soultion to the Problem #36.
#include<iostream>
#include<string>
using namespace std;
int Read_Number()
{
	int Number;
	cout << "\nPlease enter a Number? ";
	cin >> Number;
	return Number;
};
void Add_Array_Element(int Number, int Array[100], int& Array_Length)
{
	Array_Length++;
	Array[Array_Length - 1] = Number;
};
void Input_User_Number_In_Array(int Array[100], int& Array_Length)
{
	bool Add_More = true;
	do
	{
		    Add_Array_Element(Read_Number(), Array, Array_Length);
			cout << "\n Do you want to add more number? [0]:No,[1]:Yes? ";
			cin >> Add_More;

	} while (Add_More);

};
void Print_Array(int Array[100], int Array_Length)
{
	for (int i = 0; i < Array_Length; i++)
	{
		cout << Array[i] << " ";
	}
	cout << "\n";
};
int main()
{
	int Array[100], Array_Length = 0;
	Input_User_Number_In_Array(Array, Array_Length);

	cout << "\nArray Length: " << Array_Length << endl;
	cout << "Array Element: ";
	Print_Array(Array, Array_Length);

	return 0;
}