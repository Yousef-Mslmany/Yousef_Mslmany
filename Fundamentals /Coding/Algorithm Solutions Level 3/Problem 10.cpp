//This solves problem number 10.
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

int SumAllNumbersInMatrix(int arr[3][3], short Rows, short cols)
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

int main()
{
    srand((unsigned)time(NULL));
    int arr1[3][3];

    FillMatrixWithRandomNumber(arr1, 3, 3);
    cout << "\nMatrix 1:\n";
    PrintMatrix(arr1, 3, 3);

    cout << "\nSum of Matrix1 is: ";
    cout << SumAllNumbersInMatrix(arr1, 3, 3);

}

