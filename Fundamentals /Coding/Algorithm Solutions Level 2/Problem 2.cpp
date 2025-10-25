//This is a soultion to the Problem #2 
#include <iostream>
using namespace std;
enum enPrime_Or_Not_Prime { Prime = 1, Not_Prime = 2 };
int Read_Positive_Number(string Message)
{
    float Number;
    do
    {

        cout << Message << endl;
        cin >> Number;

    } while (Number < 0);

    return Number;
};
enPrime_Or_Not_Prime Check_Prime(int Number)
{
    int M = round(Number / 2);
    for (int i = 2; i <= M; i++)
    {
        if (Number % i == 0)
            return enPrime_Or_Not_Prime::Not_Prime;
    }
    return enPrime_Or_Not_Prime::Prime;
};
void Print_Prime_Numbers_From_1_To_N(int Number)
{
    cout << "\n Prime Numbers From " << 1 << " To " << Number<< endl;
    for (int i = 1; i <= Number; i++)
    {
        if (Check_Prime(i) == enPrime_Or_Not_Prime::Prime)
            cout << i << endl;
    }
};
int main()
{
    Print_Prime_Numbers_From_1_To_N(Read_Positive_Number("Please enter a positive number :"));
}
