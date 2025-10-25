//This solves problem number 7.
#include <iostream>
using namespace std;

void FillMatrixWithOrderedNumber(int arr[3][3], short Rows, short cols)
{
    short Counter = 0;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            Counter++;
            arr[i][j] = Counter;
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

void TransposeMatrix(int arr[3][3], int arrTranspose[3][3], short Rows, short cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arrTranspose[i][j] = arr[j][i];
        }
    }
};

int main()
{
    srand((unsigned)time(NULL));
    int arr[3][3];
    int arrTransposed[3][3];

    FillMatrixWithOrderedNumber(arr, 3, 3);
    cout << "\nThe following is a 3x3 ordered matrix:\n";

    PrintMatrix(arr, 3, 3);

    TransposeMatrix(arr, arrTransposed, 3, 3);

    cout << "\n\n\nThe following is the transposed matrix:\n";
    PrintMatrix(arrTransposed, 3, 3);
}
