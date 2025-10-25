//This soultion a problem #7
#include <iostream>
#include<string>
using namespace std;
int Read_Number()
{
    float Number;
    cout << "Please Enter the Number: ";
    cin >> Number;
    return Number;
};
float Calculate_Half_Number(int Number)
{
    return (float)Number / 2;
};
void Print_Results(int Half_Number)
{
    string Resulte = "Half of " + to_string(Half_Number) + " is: " + to_string(Calculate_Half_Number(Half_Number));
    cout << Resulte << endl;
};
int main()
{
    Print_Results(Read_Number());
    cout << "End The Program";
    return 0;
}
