//This is a Soultion to the Problem #3
#include <iostream>
using namespace std;
enum en_Number_Type { Odd = 1, Even = 2 };
int ReadNumber()
{
    int Number;
    cout << "Please Enter a Number: ";
    cin >> Number;
    return Number;
};

en_Number_Type Check_Number_Type(int Number)
{
    int Result = Number % 2;
    if (Result==0)
    {
        return en_Number_Type::Even;
    }
    else
    {
        return en_Number_Type::Odd;
    }

};

void Print_Number_Type(en_Number_Type Number)
{
    if (Number== en_Number_Type::Even)
    {
        cout << "Number is Even \n";
    }
    else
    {
        cout << "Number is Odd \n";
    }
};

int main()
{
    Print_Number_Type(Check_Number_Type(ReadNumber()));
}
