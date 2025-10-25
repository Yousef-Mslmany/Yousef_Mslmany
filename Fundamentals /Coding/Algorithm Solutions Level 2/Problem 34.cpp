//This is a soultion to the Problem #34.
#include <iostream>
#include <string>
using namespace std;
int Read_Number()
{
    int Number;
    cout << "\nPlease enter a number to search for?\n";
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
    cout << "\nEnter number of elements:\n";
    cin >> Array_Length;

    for (int i = 0; i < Array_Length; i++)
    {
        Array[i] = Random_Number(1, 100);
    }
};
void Print_Array(int Array[100], int Array_Length)
{
    for (int i = 0; i < Array_Length; i++)
    {
        cout << Array[i] << " ";
    }
};
short Find_Number_Position_In_Array(int Number,int Array[100], int Array_Length)
{
    for (int i = 0; i < Array_Length; i++)
    {
        if (Array[i] == Number)
            return i;
    }
    return -1;
};
int main()
{
    srand((unsigned)time(NULL));
    int Array[100], Array_Length;
    Fill_Array_With_Random_Numbers(Array, Array_Length);

    cout << "\nArray 1 element:\n";
    Print_Array(Array, Array_Length);

    int Number= Read_Number();
    cout << "\nNumber you are looking for is = " << Number << endl;

    short Number_Position = Find_Number_Position_In_Array(Number, Array, Array_Length);
    
    if (Number_Position == -1)
        cout << "The Number found at posistion = -(\n" << endl;
    else
    {
        cout << "The Number is not found: " << Number_Position << endl;
        cout << "The Number found its order: " << Number_Position + 1 << endl;
    }
    return 0;
}