//This is a soultion to the Problem #20.
#include <iostream>
#include <string>
using namespace std;
enum enChar_Type { Samall_Letter = 1, Capital_Letter = 2, Special_Character = 3, Digit = 4 };
int Rendom_Number(int From, int To)
{

    int Rand_Number = rand() % (To - From + 1) + From;
    return Rand_Number;

};
char Get_Random_Character(enChar_Type Char_Type)
{
    switch (Char_Type)
    {
    case enChar_Type::Samall_Letter:
        return(Rendom_Number(97, 122));
        break;
    case enChar_Type::Capital_Letter:
        return(Rendom_Number(65, 90));
        break;
    case enChar_Type::Special_Character:
        return(Rendom_Number(33, 47));
        break;
    case enChar_Type::Digit:
        return(Rendom_Number(48, 57));
        break;
    default:
        break;
    }
};
int main()
{
    srand((unsigned)time(NULL));
    cout << Get_Random_Character(enChar_Type::Samall_Letter) << endl;
    cout << Get_Random_Character(enChar_Type::Capital_Letter) << endl;
    cout << Get_Random_Character(enChar_Type::Special_Character) << endl;
    cout << Get_Random_Character(enChar_Type::Digit) << endl;
    return 0;
}