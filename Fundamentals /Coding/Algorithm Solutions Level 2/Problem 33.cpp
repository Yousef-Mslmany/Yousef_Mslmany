//This is a soultion to the Problem #33.
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
};
int Random_Number(int From, int To)
{

    int Rand_Number = rand() % (To - From + 1) + From;
    return char(Rand_Number);

};
char Get_Random_Character(enChar_Type Char_Type)
{
    switch (Char_Type)
    {
    case enChar_Type::Samall_Letter:
        return(Random_Number(97, 122));
        break;
    case enChar_Type::Capital_Letter:
        return(Random_Number(65, 90));
        break;
    case enChar_Type::Special_Character:
        return(Random_Number(33, 47));
        break;
    case enChar_Type::Digit:
        return(Random_Number(48, 57));
        break;
    default:
        break;
    }
};
string Generate_Word(enChar_Type Char_Type, short Length)
{
    string Word;
    for (int i = 0; i < Length; i++)
    {
        Word = Word + Get_Random_Character(Char_Type);
    }
    return Word;
};
string Generate_Key()
{
    string Key = "";
    Key = Generate_Word(enChar_Type::Capital_Letter, 4) + "-";
    Key = Key + Generate_Word(enChar_Type::Capital_Letter, 4) + "-";
    Key = Key + Generate_Word(enChar_Type::Capital_Letter, 4) + "-";
    Key = Key + Generate_Word(enChar_Type::Capital_Letter, 4);
    return Key;
};
void Genetate_keys(string Array[100] , int Array_Length)
{
    for (int i = 0; i < Array_Length; i++)
        Array[i] = Generate_Key();
};
void Print_Array(string Array[100], int  Array_Length)
{
    cout << "\nArray Element:\n";
    for (int i = 0; i < Array_Length; i++)
    {
        cout << "Array[" << i << "] : ";
        cout << Array[i] << endl;
    }
    cout << "\n";
};
int main()
{
    srand((unsigned)time(NULL));

    string Array[100];
    int  Array_Length;
    Genetate_keys(Array,Array_Length=Read_Positive_Number("Please enter a number How many keys to generate in Array : "));
    Print_Array(Array, Array_Length);
    return 0;
}