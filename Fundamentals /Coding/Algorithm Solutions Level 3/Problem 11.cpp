//This solves problem number 11.
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

int SumOfMatrix(int arr[3][3], short Rows, short cols)
{
    short Sum = 0;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            Sum = Sum + arr[i][j];
        }
    }
    return Sum;
};

bool AreEqualMatrices(int arr1[3][3], int arr2[3][3],short Rows, short cols)
{
    return(SumOfMatrix(arr1, Rows, cols) == SumOfMatrix(arr2, Rows, cols));
};
int main()
{
    srand((unsigned)time(NULL));
    int arr1[3][3];
    int arr2[3][3];

    FillMatrixWithRandomNumber(arr1, 3, 3);
    cout << "Matrix 1:\n";
    PrintMatrix(arr1, 3, 3);

    FillMatrixWithRandomNumber(arr2, 3, 3);
    cout << "\nMatrix 2:\n";
    PrintMatrix(arr2, 3, 3);

    if (AreEqualMatrices(arr1,arr2,3,3))
        cout << "\nYes, both Matrices of equal.";
    else
        cout << "\nNo, matrices are NOT equal.";
}

