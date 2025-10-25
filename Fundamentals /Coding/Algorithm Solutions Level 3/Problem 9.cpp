//This solves problem number 9.
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

void PrintMiddleRow(int arr[3][3], short Rows, short Cols)
{
    short MiddleRow = Rows/2;

    for (int i = 0; i < Cols; i++)
    {
        printf("%0*d\t", 2, arr[MiddleRow][i]);
    }
};

void PrintMiddleCol(int arr[3][3], short Rows ,short Cols)
{
    short MiddleCol = Cols / 2;

    for (int j = 0; j < Cols; j++)
    {
        printf("%0*d\t", 2, arr[j][MiddleCol]);
    }
};

int main()
{
    srand((unsigned)time(NULL));
    int arr1[3][3];

    FillMatrixWithRandomNumber(arr1, 3, 3);
    cout << "\nmatrix 1:\n";
    PrintMatrix(arr1, 3, 3);

    cout << "\nMiddle Row of Matrix1 is: \n";
    PrintMiddleRow(arr1, 3, 3);

    cout << "\n\nMiddle Col of Matrix1 is: \n";
    PrintMiddleCol(arr1, 3, 3);
}

