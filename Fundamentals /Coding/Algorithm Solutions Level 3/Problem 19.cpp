//This solves problem number 19.
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
            printf("%0*d\t", 2, arr[i][j]);
        }
        cout << endl;
    }
};

bool IsNumberInMatrix(int arr1[3][3], short Rows, short cols, short Number)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (arr1[i][j] == Number)
                return true;
        }
    }
    return false;
};

int MinNumberInMatrix(int arr1[3][3], short Rows, short cols)
{
    int  Minimum = arr1[0][0];;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (Minimum < arr1[i][j])
            {
                Minimum = arr1[i][j];
            }
        }
    }
    return Minimum;
};

int MaxNumberInMatrix(int arr1[3][3], short Rows, short cols)
{
    int Maximum = arr1[0][0];
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (Maximum > arr1[i][j])
            {
                Maximum = arr1[i][j];
            }
        }
    }
    return Maximum;
};

int main()
{
    srand((unsigned)time(NULL));
    int arr1[3][3];

    FillMatrixWithRandomNumber(arr1, 3, 3);
    cout << "Matrix 1:\n";
    PrintMatrix(arr1, 3, 3);

    cout << "\nMinimum Number is: " << MinNumberInMatrix(arr1, 3, 3);
    cout << "\nMax Number is: " << MaxNumberInMatrix(arr1, 3, 3);

}

