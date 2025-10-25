//This is a soultion to the Problem #31.
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
}

int Rendom_Number(int From, int To)
{

    int Rand_Number = rand() % (To - From + 1) + From;
    return Rand_Number;

}

void Read_Array(int Arr[100], int& Arr_Length)
{

    for (int i = 0; i < Arr_Length; i++)
    {
        Arr[i] = i + 1;
    }
}

void Swap(int& A, int& B)
{
    int Temp;
    Temp = A;
    A = B;
    B = Temp;
}

void Print_Array(int Arr[100],int Arr_Length)
{
    for (int i = 0; i < Arr_Length; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << "\n";
}

void Shuffle_Array(int Arr[100], int Arr_Length)
{
    for (int i = 0; i < Arr_Length; i++)
    {
        Swap(Arr[Rendom_Number(1, Arr_Length) - 1], Arr[Rendom_Number(1, Arr_Length) - 1]);
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int Arr[100];
    int Arr_Length = Read_Positive_Number("How many element : ");
    Read_Array(Arr, Arr_Length);

    cout << "Array elements before shuffle : \n";
    Print_Array(Arr, Arr_Length);


    Shuffle_Array(Arr, Arr_Length);
    cout << "Array elements after shuffle : \n";
    Print_Array(Arr, Arr_Length);
}
