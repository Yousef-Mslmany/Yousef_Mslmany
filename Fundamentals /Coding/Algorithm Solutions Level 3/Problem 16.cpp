//This solves problem number 16.
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


int CountNumberInMatrix(int arr1[3][3], short Rows, short cols, short Number)
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

bool IsSparseMatrix(int arr1[3][3], short Rows, short cols)
{
    short MatrixSize = Rows * cols;
    return(CountNumberInMatrix(arr1, 3, 3, 0) >= MatrixSize);
};
int main()
{
    srand((unsigned)time(NULL));
    int arr1[3][3];
    FillMatrixWithRandomNumber(arr1, 3, 3);
    cout << "Matrix 1:\n";
    PrintMatrix(arr1, 3, 3);

    if (IsSparseMatrix(arr1, 3, 3))
        cout << "\nYes: It is Sparse " << endl;
    else
        cout << "\nNo: It's NOT Sparse " << endl;
}

