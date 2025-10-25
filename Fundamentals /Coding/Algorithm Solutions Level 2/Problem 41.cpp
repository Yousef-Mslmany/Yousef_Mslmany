//This is a soultion to the Problem #41.
#include <iostream>
#include <string>
using namespace std;
void Fill_Array(int Array[100], int& Array_Length)
{
    Array_Length = 6;
    Array[0] = 10;
    Array[1] = 20;
    Array[2] = 30;
    Array[3] = 30;
    Array[4] = 20;
    Array[5] = 10;
};
bool Is_Palindrome_Array(int Array[100], int Array_Length)
{
    for (int i = 0; i < Array_Length; i++)
    {

        if (Array[i]!= Array[Array_Length-i-1])
        {
            return false;
        }
        return true;
    }
};
void Print_Array(int Array[100], int Array_Length)
{
    for (int i = 0; i < Array_Length; i++)
    {
        cout << Array[i] << " ";
    }
    cout << endl;
};

int main()
{
    int Array[100], Array_Length = 0;
    Fill_Array(Array, Array_Length);

    cout << "\nArray Element:\n";
    Print_Array(Array, Array_Length);

    if (Is_Palindrome_Array(Array, Array_Length))
        cout << "Yes Array is Palindrome\n";
    else
        cout << "No Array is NOT Palindrome\n";
    return 0;
}