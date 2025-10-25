//This is a soultion to the Problem #9.
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
int count_Digit_Frequency(short Digit_To_check,int Number)
{
    int Reminder = 0, Counter = 0;
        while (Number > 0)
        {
            Reminder = Number % 10;
            Number = Number / 10;
            if (Reminder == Digit_To_check)
            {
                Counter++;
            }
        }
        return Counter;
};
void Print_Digit_All_Frequency(int Number)
{
    for (int i = 0; i < 10; i++)
    {
        short Digit_Frequency = 0;
        Digit_Frequency = count_Digit_Frequency(i, Number);
            if (Digit_Frequency > 0)
            {
                cout << "Digit " << i << " Frequency is " << Digit_Frequency << " Time(s)." << endl;
            }
    }

};
int main()
{
    Print_Digit_All_Frequency(Read_Positive_Number("Please enter a number: "));
    return 0;
}