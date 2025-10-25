//This is a soultion to the Problem #47.
#include <iostream>
#include <string>
#include<Math.h>
using namespace std;
float Read_Number()
{
    float Number;
    cout << "\nPlease enter a float number?\n";
    cin >> Number;
    return Number;
};
float Get_Fraction_Part(float Number)
{
    return Number - (int)Number;
};
int My_Round(float Number)
{
    int Int_Part;
    Int_Part = (int)Number;
    
    float Fraction_Part = Get_Fraction_Part(Number);
    if (abs(Fraction_Part) >= 0.5)
    {
        if (Number > 0)
            Int_Part++;
        else
            Int_Part--;
    }
    else
    {
        return Int_Part;
    }
};
int main()
{
    float Number = Read_Number();
    cout << "My Round Result : " << My_Round(Number) << endl;
    cout << "C++ Round Result : " << round(Number) << endl;

    return 0;
}