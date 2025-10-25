//This is a Program to soulation the problem #31
#include <iostream>
using namespace std;
float Read_Number()
{
	float Number;
	cout << "This is a program to power number 2, 3, 4." << endl;
	cout << "Please Enter the number: ";
	cin >> Number;
	return Number;
};
float Power_Of_2_3_4(float Number)
{
	cout << "Power_2 = " << pow(Number, 2) << endl;
	cout << "Power_3 = " << pow(Number, 3) << endl;
	cout << "Power_4 = " << pow(Number, 4) << endl;

};
int main()
{
	Power_Of_2_3_4(Read_Number());
	cout << "End the program.";
}
