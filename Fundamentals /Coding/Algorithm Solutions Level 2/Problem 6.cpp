//This is a soultion to the Problem #6.
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
int Sum_of_Digits(int Number)
{
    int Reminder = 0;
    int Sum = 0;
    while (Number > 0)
    {
        Reminder = Number % 10;
        Number = Number / 10;
        Sum = Sum + Reminder;
    }
    return Sum;
};
int main()
{
    cout << "Sum of Digits = " << Sum_of_Digits(Read_Positive_Number("Please enter a positive number:"));
    return 0;
}
