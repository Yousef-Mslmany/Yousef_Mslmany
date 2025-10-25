//This is a soultion to the Problem #8.
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
int Revers_Number(int Number, short Digit)
{
    int Reminder = 0, Counter = 0;
    while (Number > 0)
    {
        Reminder = Number % 10;
        Number = Number / 10;
        if (Reminder== Digit)
        {
            Counter++;
        }
    }
    return Counter;
};
int main()
{
    int Number = Read_Positive_Number("Please enter a number: ");short Digit_To_Check = Read_Positive_Number("Please enter one digit to check: ");
    cout << "Digit " << Digit_To_Check << " Frequecy is " <<  Revers_Number(Number, Digit_To_Check) << " Time(s)" << endl;
    return 0;
}