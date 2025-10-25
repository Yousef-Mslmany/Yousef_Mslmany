//This solves problem number 13.
#include <iostream>
#include <string>
using namespace std;

int Random(int From, int To)
{
    int Rand_Number = rand() % (To - From + 1) + From;
    return Rand_Number;
};

void FillMatrixWithRandomNumber(int arr[3][3], short Rows, short cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = Random(1, 10);
        }
    }
};

void PrintMatrix(int arr[3][3], short Rows, short cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%0*d\t", 2, arr[i][j]);
        }
        cout << endl;
    }
};


int CountNumberInMateix(int arr1[3][3], short Rows, short cols, short Number)
{
    int Count = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (arr1[i][j] == Number)
            Count++;
        }
    }
    return Count;
};
int main()
{
    srand((unsigned)time(NULL));
    int arr1[3][3];
    short Number;
    FillMatrixWithRandomNumber(arr1, 3, 3);
    cout << "Matrix 1:\n";
    PrintMatrix(arr1, 3, 3);

    cout << "\nEnter the number to count in matrix? ";
    cin >> Number;

    cout << "\nNumber " << Number << " count in matrix is " << CountNumberInMateix(arr1, 3, 3, Number);
}

