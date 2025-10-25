//This is a soultion to the Problem #11.
#include <iostream>
#include <string>
using namespace std;
int Read_Positive_Number(string Message)
{
    float Number;
    do
    {

        cout << Message << endl;
        cin >> Number;

    } while (Number < 0);

    return Number;
};
int Revers_Number(int Number)
{
    int Reminder = 0, Number2 = 0;
    while (Number > 0)
    {
        Reminder = Number % 10;
        Number = Number / 10;
        Number2 = Number2 * 10 + Reminder;
    }
    return Number2;
};
bool Print_Digits(int Number)
{
    return Revers_Number(Number) == Number;
};
int main()
{
    if (Print_Digits(Read_Positive_Number("Please enter a Positive number")))
        cout << "Yes,it is a Palindrome number." << endl;
    else
        cout << "Yes,it is NOT a Palindrome number." << endl;
    return 0;
}