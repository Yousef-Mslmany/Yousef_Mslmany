//This is a soultion to the Problem #30.
#include <iostream>
using namespace std;
int Read_Positive_Number(string Message)
{
    int Number;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number < 0);

    return Number;
};

int Factorial_Number(int Number)
{

    int Result = 1;
    for (int i = 1; i <= Number; i++)
    {
        Result = Result * i;
    }
    return Result;
};
int main()
{
    cout << Factorial_Number(Read_Positive_Number("Please Enter a Number Positive: ")) << endl;
    cout << "End the Program.";

}
