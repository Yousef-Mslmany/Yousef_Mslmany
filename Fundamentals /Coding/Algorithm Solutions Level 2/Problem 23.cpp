//This is a soultion to the Problem #23.
#include <iostream>
#include <string>
using namespace std;
int Read_Positive_Number(string Message)
{
    int Number;
    do
    {

        cout << Message << endl;
        cin >> Number;

    } while (Number < 0);

    return Number;
};
int Rendom_Number(int From, int To)
{

    int Rand_Number = rand() % (To - From + 1) + From;
    return Rand_Number;

};
void Read_Array(int Arr[100], int& Arr_Length)
{

    for (int i = 0; i < Arr_Length; i++)
    {
        Arr[i]= Rendom_Number(1, 100);
    }
};
void Print_Array(int Arr[100], int Arr_Length)
{
    for (int i = 0; i < Arr_Length; i++)
    {
        cout <<  Arr[i] << " ";
    }
    cout << "\n";
};
int main()
{
    srand((unsigned)time(NULL));

    int Arr_Length = Read_Positive_Number("Please enter number of array elements :"), Arr[100];
    Read_Array(Arr, Arr_Length);
    cout << "Array elements :";
    Print_Array(Arr, Arr_Length);
}
