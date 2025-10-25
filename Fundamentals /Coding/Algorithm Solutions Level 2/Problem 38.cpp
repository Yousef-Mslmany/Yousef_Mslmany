//This is a soultion to the Problem #38.
#include <iostream>
#include <string>
using namespace std;
int Read_Number()
{
    int Number;
    cout << "\nPlease enter a number to element for Array?\n";
    cin >> Number;
    return Number;
};
int Random_Number(int From, int To)
{

    int Rand_Number = rand() % (To - From + 1) + From;
    return Rand_Number;

};
void Fill_Array_With_Random_Numbers(int Array[100], int& Array_Length)
{
    cout << "Enter number of element: ";
    cin >> Array_Length;

    for (int i = 0; i < Array_Length; i++)
        Array[i] = Random_Number(1, 100);
};
void Add_Array_Element(int Number, int Array[100], int& Array_Length)
{
        Array_Length++;
        Array[Array_Length - 1] = Number;
};
void Copy_Odd_Number(int Array_Source[100], int Array_Destination[100], int Array_Length, int& Array_Destination_Length)
{
    for (int i = 0; i < Array_Length; i++)
        if (Array_Source[i] % 2 != 0)
        {
            Add_Array_Element(Array_Source[i], Array_Destination, Array_Destination_Length);
        }

};
void Print_Array(int Array[100], int Array_Length)
{
    for (int i = 0; i < Array_Length; i++)
    {
        cout << Array[i] << " ";
    }
};

int main()
{
    srand((unsigned)time(NULL));

    int Array[100], Array2_Length = 0, Array_Length = 0;
    Fill_Array_With_Random_Numbers(Array, Array_Length);

    int Array2[100];
    Copy_Odd_Number(Array, Array2, Array_Length, Array2_Length);

    cout << "\n Array 1 element\n";
    Print_Array(Array, Array_Length);

    cout << "\n Array 2 element\n";
    Print_Array(Array2, Array2_Length);
    return 0;
}