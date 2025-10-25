//This solves problem number 8.
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

void MultiplyingTwoMatrices(int arr1[3][3], int arr2[3][3], int MultiplyingArray[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            MultiplyingArray[i][j] = arr1[i][j] * arr2[i][j];
        }
    }
};

int main()
{
    srand((unsigned)time(NULL));
    int MultiplyingArray[3][3];
    int arr2[3][3];
    int arr1[3][3];

    FillMatrixWithRandomNumber(arr1, 3, 3);
    cout << "\nmatrix 1:\n";
    PrintMatrix(arr1, 3, 3);

    FillMatrixWithRandomNumber(arr2, 3, 3);
    cout << "\nmatrix 2:\n";
    PrintMatrix(arr2, 3, 3);

    MultiplyingTwoMatrices(arr1, arr2, MultiplyingArray, 3, 3);

    cout << "\nResult :\n";
    PrintMatrix(MultiplyingArray, 3, 3);
}

