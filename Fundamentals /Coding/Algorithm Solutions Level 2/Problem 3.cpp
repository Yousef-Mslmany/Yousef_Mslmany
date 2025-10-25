//This is a soultion to the Problem #3.
#include <iostream>
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
bool Is_Prefect_Number(int Number)
{
    int Sum = 0;
    for (int i = 1; i < Number; i++)
    {
        if (Number % i == 0)
        {
            Sum = Sum + i;
        }
    }
    return Number == Sum;
};
void Print_Number_Status(int Number)
{
    if (Is_Prefect_Number(Number))
        cout << Number << " is Prefect Number" << endl;
    else
        cout << Number << " is Not Prefect Number" << endl;
};
int main()
{
    Print_Number_Status(Read_Positive_Number("Please enter a Positive number : "));
}
