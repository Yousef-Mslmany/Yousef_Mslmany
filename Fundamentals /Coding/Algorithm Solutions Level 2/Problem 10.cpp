//This is a soultion to the Problem #10.
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
void Print_Digits(int Number)
{
    int Reminder = 0;
    while (Number > 0)
    {
        Reminder = Number % 10;
        Number = Number / 10;
        cout << Reminder << endl;
    }

};
int main()
{
    Print_Digits(Revers_Number(Read_Positive_Number("Please enter a positive number: ")));
    return 0;
}