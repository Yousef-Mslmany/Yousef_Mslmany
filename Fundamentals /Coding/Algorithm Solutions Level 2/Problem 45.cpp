//This is a soultion to the Problem #45.
#include <iostream>
#include <string>
using namespace std;
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
        Array[i] = Random_Number(-100, 100);
    }
};
void Print_Array(int Array[100], int Array_Length)
{
    for (int i = 0; i < Array_Length; i++)
    {
        cout << Array[i] << " ";
    }
};
short Negative_Number(int Array[100], int Array_Length)
{
    int count = 0;
    for (int i = 0; i < Array_Length; i++)
    {
        if (Array[i] < 0)
            count++;
    }
    return count;
};
int main()
{
    srand((unsigned)time(NULL));
    int Array[100], Array_Length;
    Fill_Array_With_Random_Numbers(Array, Array_Length);

    cout << "\nArray Elements: ";
    Print_Array(Array, Array_Length);

    cout << "\nPositive Number count is : " << Negative_Number(Array, Array_Length);
    return 0;
}