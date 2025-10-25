//This is a soultion to the Problem #30.
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
        Arr[i] = Rendom_Number(1, 100);
    }
};
void Print_Array(int Arr[100], int Arr_Length)
{
    for (int i = 0; i < Arr_Length; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << "\n";
};
void Sum_Of_Tow_Array(int Arr[100], int Arr2[100], int Arr3[100], int Arr_Length)
{
    for (int i = 0; i < Arr_Length; i++)
    {
        Arr3[i] = Arr[i] + Arr2[i];
    }
};
int main()
{
    srand((unsigned)time(NULL));
    int Arr3[100], Arr2[100], Arr[100];
    int Arr_Length = Read_Positive_Number("How many element : ");

    Read_Array(Arr, Arr_Length);
    Read_Array(Arr2, Arr_Length);

    Sum_Of_Tow_Array(Arr, Arr2, Arr3, Arr_Length);

    cout << "Array 1 elements : \n";
    Print_Array(Arr, Arr_Length);

    cout << "Array 2 elements : \n";
    Print_Array(Arr2, Arr_Length);

    cout << "Sum of Array1 and Array2 elements : \n";
    Print_Array(Arr3, Arr_Length);
}
