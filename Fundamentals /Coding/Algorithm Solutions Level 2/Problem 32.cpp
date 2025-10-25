//This is a soultion to the Problem #32.
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
void Swap(int& A, int& B)
{
    int Temp;
    Temp = A;
    A = B;
    B = Temp;
};
void Coping_array_In_Reversed_Order(int Arr[100], int& Arr_Length)
{
    for (int i = 0; i < Arr_Length / 2; i++)
    {
        Swap(Arr[i], Arr[Arr_Length - i - 1]);
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

int main()
{
    srand((unsigned)time(NULL));

    int Arr[100];
    int Arr_Length = Read_Positive_Number("How many element : ");
    Read_Array(Arr, Arr_Length);

    cout << "Array 1 elements: \n";
    Print_Array(Arr, Arr_Length);

    Coping_array_In_Reversed_Order(Arr, Arr_Length);

    cout << "Array 2 elements after coping array 1 in reversed order: \n";
    Print_Array(Arr, Arr_Length);
}
