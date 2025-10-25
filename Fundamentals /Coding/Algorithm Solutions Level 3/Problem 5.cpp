//This solves problem number 5.
#include <iostream>
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
            arr[i][j] = Random(1, 100);
        }
    }
};

void PrintMatrix(int arr[3][3], short Rows, short cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
};

int ColSum(int arr[3][3], short Rows, short colsNumber)
{
    int Sum = 0;

    for (short i = 0; i < Rows; i++)
    {
        Sum = Sum + arr[i][colsNumber];
    }
    return Sum;
};

void StoreTheSumInAnArray(int arr[3][3], int arrSum[3], short Rows, short Cols)
{
    for (int i = 0; i < 3; i++)
    {
        arrSum[i] = ColSum(arr, Rows, i);
    }
};

void PrintColSumArray(int arrSum[3], short Length)
{
    for (short i = 0; i < Length; i++)
    {
        cout << "Cols " << i + 1 << " Sum = " << arrSum[i] << endl;
    }
};

int main()
{
    srand((unsigned)time(NULL));
    int arrSum[3];
    int arr[3][3];

    FillMatrixWithRandomNumber(arr, 3, 3);
    cout << "\nThe following is a 3x3 random matrix:\n";

    PrintMatrix(arr, 3, 3);

    StoreTheSumInAnArray(arr, arrSum, 3, 3);

    PrintColSumArray(arrSum, 3);

}

