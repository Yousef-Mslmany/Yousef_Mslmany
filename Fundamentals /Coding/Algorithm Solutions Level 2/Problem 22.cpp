//This is a soultion to the Problem #22.
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
void Read_Array(int Arr[100], int &Arr_Length)
{
    cout << "Enter Number of elements" << endl;
    cin >> Arr_Length;

    cout << "\nEnter arryay elements" << endl;
    for (int i = 0; i < Arr_Length; i++)
    {
        cout << "Elemant [" << i + 1 << "] : ";
        cin >> Arr[i];
    }

    cout << endl;
};
void Print_Array(int Arr[100], int Arr_Length)
{
    for (int i = 0; i < Arr_Length; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << "\n";
};
int Time_Repeated(int Number, int Arr[100], int Arr_Length)
{
    int Counter = 0;
    for (int i = 0; i < Arr_Length; i++)
    {
        if (Number == Arr[i])
            Counter++;
    }
    return Counter;
};
int main()
{
    int Arr[100], Arr_Length, Number_To_Check;
    Read_Array(Arr, Arr_Length);
    Number_To_Check = Read_Positive_Number("Enter the Number you want to check: ");
    cout << "\n Original array: ";

    Print_Array(Arr, Arr_Length);
    cout << "\nNumber " << Number_To_Check;
    cout << " is repeated ";
    cout << Time_Repeated(Number_To_Check, Arr, Arr_Length)<<" time(s)\n";
    return 0;
}