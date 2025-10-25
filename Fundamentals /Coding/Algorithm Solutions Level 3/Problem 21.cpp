#include <iostream>
using namespace std;

void PrintFibonacciUsingLoop(short Number)
{
    int FibNumber = 0;
    int Prev2 = 0, Prev1 = 1;
    cout << "1 ";
    for (short i = 2; i <= Number; i++)
    {
        FibNumber = Prev1 + Prev2;
        cout << FibNumber << "  ";
        Prev2 = Prev1;
        Prev1 = FibNumber;
    }
};

int main() 
{
    PrintFibonacciUsingLoop(10);

    return 0;
}