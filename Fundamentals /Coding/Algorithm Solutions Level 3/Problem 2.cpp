//This solves problem number 2.
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

int RowSum(int arr[3][3], short RowNumber, short cols)
{
    int Sum = 0;

    for (short j = 0; j < cols; j++)
    {
        Sum = Sum + arr[RowNumber][j];
    }
    return Sum;
};

void SumRowsMatrix(int arr[3][3], short Rows, short cols)
{
    int Sum = 0;

    for (short i = 0; i < Rows; i++)
    {
        cout << "Row " << i + 1 << " Sum = " << RowSum(arr, i, cols) << endl;
    }
};

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];

    FillMatrixWithRandomNumber(arr, 3, 3);
    cout << "\nThe following is a 3x3 random matrix:\n";

    PrintMatrix(arr, 3, 3);

    SumRowsMatrix(arr, 3, 3);

}

