#include <iostream>
using namespace std;

void PrintFibonacciUsingRecursion(short Number, int Prev1, int Prev2)
{
    int FibNumber = 0;

    if (Number > 0)
    {
        FibNumber = Prev1 + Prev2;
        Prev2 = Prev1; 
        Prev1 = FibNumber;
        cout << FibNumber << " ";
        PrintFibonacciUsingRecursion(Number - 1, Prev1, Prev2);
    }
};

int main()
{
    PrintFibonacciUsingRecursion(10, 1, 0);

    return 0;
}