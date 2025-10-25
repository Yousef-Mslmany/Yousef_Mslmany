//This is a soultion to the Problem #29.
#include <iostream>
#include <string>
using namespace std;
enum enPrime_Or_Not_Prime { Prime = 1, Not_Prime = 2 };
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
enPrime_Or_Not_Prime Check_Prime(int Number)
{
    int M = round(Number / 2);
    for (int i = 2; i <= M; i++)
    {
        if (Number % i == 0)
            return enPrime_Or_Not_Prime::Not_Prime;
    }
    return enPrime_Or_Not_Prime::Prime;
};
void Copy_Prime_Array(int Arr_Source[100], int Arr_Destination[100], int Arr_Length, int& Arr_Length2)
{
    int Counter = 0;
    for (int i = 0; i < Arr_Length; i++)
    {
        if (Check_Prime(Arr_Source[i]) == enPrime_Or_Not_Prime::Prime)
        {
            Arr_Destination[Counter] = Arr_Source[i];
            Counter++;
        }
    }
    Arr_Length2 = --Counter;
};
int main()
{
    srand((unsigned)time(NULL));

    int Arr2[100], Arr_Length2 = 0;
    int Arr_Length = Read_Positive_Number("Please enter number of array elements :"), Arr[100];
    Read_Array(Arr, Arr_Length);
    cout << "Array 1 elements : \n";
    Print_Array(Arr, Arr_Length);
    cout << "Prime number in Array2 : \n";
    Copy_Prime_Array(Arr, Arr2, Arr_Length, Arr_Length2);
    Print_Array(Arr2, Arr_Length2);
}
