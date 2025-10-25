//This is a soultion to the Problem #21.
#include <iostream>
#include <string>
using namespace std;
enum enChar_Type { Samall_Letter = 1, Capital_Letter = 2, Special_Character = 3, Digit = 4 };
int Read_Positive_Number(string Message)
{
    float Number;
    do
    {

        cout << Message << endl;
        cin >> Number;

    } while (Number < 0);

    return Number;
}
int Rendom_Number(int From, int To)
{

    int Rand_Number = rand() % (To - From + 1) + From;
    return char(Rand_Number);

}
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
}
string Generate_Word(enChar_Type Char_Type,short Length)
{
    string Word;
    for (int i = 0; i < Length; i++)
    {
        Word = Word + Get_Random_Character(Char_Type);
    }
    return Word;
}
string Generate_Key()
{
    string Key = "";
    Key = Generate_Word(enChar_Type::Capital_Letter, 4) + "-";
    Key = Key + Generate_Word(enChar_Type::Capital_Letter, 4) + "-";
    Key = Key + Generate_Word(enChar_Type::Capital_Letter, 4) + "-";
    Key = Key + Generate_Word(enChar_Type::Capital_Letter, 4);
    return Key;
}
void Genetate_keys(short Number_of_Key)
{
    for (int i = 1; i <= Number_of_Key; i++)
    {
        cout << "Key [" << i << "] : ";
        cout << Generate_Key() << endl;
    }
}
int main()
{
    srand((unsigned)time(NULL));

    Genetate_keys(Read_Positive_Number("Please enter a number How many keys to generate : "));
    return 0;
}