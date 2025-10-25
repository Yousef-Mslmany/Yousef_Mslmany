//This solves problem number 12.
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


bool AreTypicalMatrices(int arr1[3][3], int arr2[3][3], short Rows, short cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (arr1[i][j] != arr2[i][j])
            {
                return false;
            }
        }
    }
    return true;
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

    if (AreTypicalMatrices(arr1, arr2, 3, 3))
        cout << "\nYes, both Matrices of equal.";
    else
        cout << "\nNo, matrices are NOT equal.";
}

