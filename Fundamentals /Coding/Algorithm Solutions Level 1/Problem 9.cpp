//This is program to soultoin problem #9 
#include <iostream>
using namespace std;
struct strNumbers
{
    int Number1;
    int Number2;
    int Number3;
};
strNumbers Read_Number()
{
    strNumbers  Numbers;
    cout << "Please Enter the Number1: ";
    cin >> Numbers.Number1;
    cout << "Please Enter the Number2: ";
    cin >> Numbers.Number2;
    cout << "Please Enter the Number3: ";
    cin >> Numbers.Number3;
    return Numbers;
};
int Sum_Number(strNumbers Numbers)
{   
    return (Numbers.Number1 + Numbers.Number2 + Numbers.Number3);
};
void Print_Number(int Sum)
{
    cout << "the Sum of Numbers: " << Sum << endl;
};
int main()
{
    Print_Number(Sum_Number(Read_Number()));
    cout << "End the program.";
}
