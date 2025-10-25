//This solves problem number 18.
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

void PrintIntersectedNumber(int arr1[3][3], int arr2[3][3], short Rows, short cols)
{
    int Number;

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            Number = arr1[i][j];
            if (IsNumberInMatrix(arr2, Rows, cols, Number))
            {
                cout << Number << "\t";
            }  
        }
    }
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
    cout << "Matrix 1:\n";
    PrintMatrix(arr2, 3, 3);

    cout << "\nIntersected Numbers are: \n";
    PrintIntersectedNumber(arr1, arr2, 3, 3);


    
}

