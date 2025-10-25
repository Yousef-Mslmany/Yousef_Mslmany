//This is a soultion to the Problem #38.
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

    } while (Number<0);

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
void Print_Number_Type(int Number)
{
    switch (Check_Prime( Number))
    {
    case enPrime_Or_Not_Prime::Prime:
        cout << "The number is Prime \n";
        break;
    case enPrime_Or_Not_Prime::Not_Prime:
        cout << "The number is Not Prime \n";
        break;
    }

};
int main()
{
    Print_Number_Type(Read_Positive_Number("Plaese Enter a positive Number:"));
}
